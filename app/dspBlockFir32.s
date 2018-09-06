;Description: FIR Filter Implementation

	ALIAS r0,py	;pointer to the output samples
	ALIAS r1,px	;pointer to the input samples
	ALIAS r2,pcoeff	;pointer to the coefficients
	ALIAS r3,nSamples
	ALIAS r4,nTaps
	ALIAS r5,c_1
	ALIAS r6,Acc0
	ALIAS r7,Acc1
	ALIAS r8,Acc2
	ALIAS r9,Acc3
	ALIAS r10,x0
	ALIAS r11,x1
	ALIAS r12,x2
	ALIAS r14,x3

;Overloaded
	ALIAS r3,c_0	;can do this because we do not need the sample count in the inner loop
	ALIAS r2,pS_Coeff

	AREA    |.text|, CODE, READONLY

	EXPORT vF_dspl_blockfir32

vF_dspl_blockfir32
#if(__CORTEX_M == 0)
	push {r4-r7}
	mov r4, r8
	mov r5, r9
	mov r6, r10
	mov r7, r11
	push {r4-r7}
	mov r4, r12
	push {r4}	
	push {lr}	
#else
	push {r4-r12,lr}
#endif
	
	ldr nTaps,[pS_Coeff,#4]	;get pointer to the coeffs from the structure
	ldr pcoeff,[pS_Coeff]	;get pointer to the coeffs from the structure

LoopSample
	ldr Acc0,=0
	mov Acc1,Acc0
	mov Acc2,Acc0
	mov Acc3,Acc0
	
#if(__CORTEX_M == 0)
	push {pcoeff, nSamples, nTaps, c_1}
	ldmia px!,{pcoeff, nSamples, nTaps, c_1}
	mov x0, pcoeff
	mov x1, nSamples
	mov x2, nTaps
	mov x3, c_1
	pop {pcoeff, nSamples, nTaps, c_1}
#else
	ldmia px!,{x0,x1,x2,x3}
#endif

	push {nSamples, nTaps}	

LoopTaps
	ldmia pcoeff!,{c_0,c_1}
	
#if(__CORTEX_M == 0)
	push {py, px}
	
	mov py, Acc3
	mov px, x3
	muls px, c_0, px
	adds py, px, py
	mov Acc3, py
;	mla Acc3,x3,c_0,Acc3
	
	push {py, px}
	mov py, Acc2
	mov px, x2
	muls px, c_0, px
	adds py, px, py
	mov Acc2, py
;	mla Acc2,x2,c_0,Acc2

	mov px, x1
	muls px, c_0, px
	adds Acc1, px, Acc1
;	mla Acc1,x1,c_0,Acc1

	mov px, x0
	muls px, c_0, px
	adds Acc0, px, Acc0
	pop {py, px}	
;	mla Acc0,x0,c_0,Acc0	
#else
	mla Acc3,x3,c_0,Acc3
	mla Acc2,x2,c_0,Acc2
	mla Acc1,x1,c_0,Acc1
	mla Acc0,x0,c_0,Acc0
#endif
	
#if(__CORTEX_M == 0)
	push {py}	
	
	ldr py,[px]
	ADDS px, #4
	mov x0, py
	
	ldr py,[pcoeff]
	ADDS pcoeff, #4
	mov c_0, py
	
	pop {py}
#else
	ldr x0,[px],#4	
	ldr c_0,[pcoeff],#4
#endif	
	
#if(__CORTEX_M == 0)
	push {py, px}
	
	mov py, Acc3
	mov px, x0
	muls px, c_1, px
	adds py, px, py
	mov Acc3, py
;	mla Acc3,x0,c_1,Acc3

	push {py, px}
	mov py, Acc2
	mov px, x3
	muls px, c_1, px
	adds py, px, py
	mov Acc2, py
;	mla Acc2,x3,c_1,Acc2

	mov px, x2
	muls px, c_1, px
	adds Acc1, px, Acc1
;	mla Acc1,x2,c_1,Acc1

	mov px, x1
	muls px, c_1, px
	adds Acc0, px, Acc0
	pop {py, px}	
;	mla Acc0,x1,c_1,Acc0
#else
	mla Acc3,x0,c_1,Acc3
	mla Acc2,x3,c_1,Acc2
	mla Acc1,x2,c_1,Acc1
	mla Acc0,x1,c_1,Acc0
#endif
	
#if(__CORTEX_M == 0)
	push {py}	
	
	ldr py,[px]
	ADDS px, #4
	mov x1, py
	
	ldr py,[pcoeff]
	ADDS pcoeff, #4
	mov c_1, py
	
	pop {py}
#else
	ldr x1,[px],#4
	ldr c_1,[pcoeff],#4
#endif		
	
#if(__CORTEX_M == 0)
	push {py, px}
	
	mov py, Acc3
	mov px, x1
	muls px, c_0, px
	adds py, px, py
	mov Acc3, py
;	mla Acc3,x1,c_0,Acc3

	push {py, px}
	mov py, Acc2
	mov px, x0
	muls px, c_0, px
	adds py, px, py
	mov Acc2, py
;	mla Acc2,x0,c_0,Acc2

	mov px, x3
	muls px, c_0, px
	adds Acc1, px, Acc1
;	mla Acc1,x3,c_0,Acc1

	mov px, x2
	muls px, c_0, px
	adds Acc0, px, Acc0
;	mla Acc0,x2,c_0,Acc0

	pop {py, px}	
#else
	mla Acc3,x1,c_0,Acc3
	mla Acc2,x0,c_0,Acc2
	mla Acc1,x3,c_0,Acc1
	mla Acc0,x2,c_0,Acc0
#endif	
	
#if(__CORTEX_M == 0)
	push {py}	
	
	ldr py,[px]
	ADDS px, #4
	mov x2, py
	
	pop {py}
#else
	ldr x2,[px],#4
#endif	

	subs nTaps,nTaps,#4		;hoisted up to avoid pipe delay before branch

#if(__CORTEX_M == 0)
	push {py, px}
	
	mov py, Acc3
	mov px, x2
	muls px, c_1, px
	adds py, px, py
	mov Acc3, py
;	mla Acc3,x2,c_1,Acc3

	push {py, px}
	mov py, Acc2
	mov px, x1
	muls px, c_1, px
	adds py, px, py
	mov Acc2, py
;	mla Acc2,x1,c_1,Acc2

	mov px, x0
	muls px, c_1, px
	adds Acc1, px, Acc1
;	mla Acc1,x0,c_1,Acc1

	mov px, x3
	muls px, c_1, px
	adds Acc0, px, Acc0
	pop {py, px}	
;	mla Acc0,x3,c_1,Acc0
#else
	mla Acc3,x2,c_1,Acc3
	mla Acc2,x1,c_1,Acc2
	mla Acc1,x0,c_1,Acc1
	mla Acc0,x3,c_1,Acc0
#endif

#if(__CORTEX_M == 0)
	push {py}	
	
	ldr py,[px]
	ADDS px, #4
	mov x3, py
	
	pop {py}
#else
	ldr x3,[px],#4
#endif	
	
	bne LoopTaps
	
	pop {nSamples, nTaps}
	
	;Store the outputs
#if(__CORTEX_M == 0)
	push {pcoeff, nSamples, nTaps, c_1}
	mov pcoeff, Acc0
	mov nSamples, Acc1
	mov nTaps, Acc2
	mov c_1, Acc3
	stmia py!,{pcoeff, nSamples, nTaps, c_1}
	pop {pcoeff, nSamples, nTaps, c_1}
#else
	stmia py!,{Acc0,Acc1,Acc2,Acc3}
#endif
	
	subs nSamples,nSamples,#4	;hoisted up to avoid pipe delay before branch
	
	;Reset Coeffs to start
#if(__CORTEX_M == 0)
	push {nTaps}
	LSLS nTaps, #2
	subs pcoeff,pcoeff,nTaps
	pop {nTaps}
#else
	sub pcoeff,pcoeff,nTaps,LSL#2
#endif
	
	;Walk along the input data by 4 samples each LoopSample iteration
#if(__CORTEX_M == 0)
	push {nTaps}
	LSLS nTaps, #2
	subs px,px,nTaps
	pop {nTaps}
#else
	sub px,px,nTaps,LSL#2
#endif
	
	beq exit_LoopSample
	b LoopSample
	
exit_LoopSample
#if(__CORTEX_M == 0)
	pop {r4}
	mov lr, r4	
	pop {r4}
	mov r12, r4
	pop {r4-r7}
	mov r11, r7
	mov r10, r6
	mov r9, r5
	mov r8, r4	
	pop {r4-r7}
#else
	pop {r4-r12,lr}
#endif
	
	bx lr

	END
