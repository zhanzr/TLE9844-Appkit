; Description: Biquad (IIR) Filter Implementation
; Using 2.14 x 2.14 ->4.28 arithmetic with no saturation

	ALIAS r0,pi_Output
	ALIAS r1,pi_Input
	ALIAS r2,pS_StateCoeff
	ALIAS r3,i_NSamples
	ALIAS r4,a_1
	ALIAS r5,a_2
	ALIAS r6,b0
	ALIAS r7,b1
	ALIAS r8,b2
	ALIAS r9,yn_1
	ALIAS r10,yn_2
	ALIAS r11,Acc1
	ALIAS r12,xn
	ALIAS r14,Acc2

	AREA    |.text|, CODE, READONLY

	EXPORT vF_dspl_biquad32

vF_dspl_biquad32
	push {r4-r7}
	mov r4, r8
	mov r5, r9
	mov r6, r10
	mov r7, r11
	push {r4-r7}
	mov r4, r14
	push {r4}	

	;push {r4-r11,r14}
	
#if(__CORTEX_M == 0)
	ldr b1, =0
	ldrsh a_1,[pS_StateCoeff, b1]		;get the coefficients and state	
	ldr b1, =2
	ldrsh a_2,[pS_StateCoeff, b1]
	ldr b1, =4
	ldrsh b0,[pS_StateCoeff,b1]	
	ldr b1, =6
	ldrsh b1,[pS_StateCoeff,b1]
	push {b0, b1}
	ldr b1, =8
	ldrsh b0,[pS_StateCoeff, b1]
	mov b2, b0
	ldr b1, =10
	ldrsh b0,[pS_StateCoeff, b1]
	mov yn_1, b0
	ldr b1, =12
	ldrsh b0,[pS_StateCoeff, b1]	
	mov yn_2, b0
	pop {b0, b1}
#else
	ldrsh a_1,[pS_StateCoeff]		;get the coefficients and state
	ldrsh a_2,[pS_StateCoeff,#2]
	ldrsh b0,[pS_StateCoeff,#4]
	ldrsh b1,[pS_StateCoeff,#6]
	ldrsh b2,[pS_StateCoeff,#8]
	ldrsh yn_1,[pS_StateCoeff,#10]
	ldrsh yn_2,[pS_StateCoeff,#12]
#endif
	
InnerLoop
#if(__CORTEX_M == 0)
	push {b0}	
	ldr b0,[pi_Input]
	ADDS pi_Input, #4
	mov xn, b0
	pop {b0}
#else
	ldr xn,[pi_Input],#4
#endif
	
	;compute recusrive part
#if(__CORTEX_M == 0)
	push {b0, b1}
	mov b0, a_1
	mov b1, yn_1
	MULS b0, b1, b0
	mov b1, xn
	ADDS b0, b0, b1
	push {a_1}
	mov a_1, b0
	
	mov b0, yn_2
	MULS b0, a_2, b0
	ADDS b0, a_1, b0
	mov Acc1, b0
	pop {a_1}
	pop {b0, b1}
#else
	mla Acc1,a_1,yn_1,xn
	mla Acc1,a_2,yn_2,Acc1
#endif
	
	;compute non-recursive part
#if(__CORTEX_M == 0)
	push {b0}
	mov b0, Acc1
	ASRS b0, #14
	mov Acc1, b0
	pop {b0}
#else
	mov Acc1,Acc1,ASR#14			;normalize back to 2.14
#endif
	
#if(__CORTEX_M == 0)
	push {a_1, a_2}	
	mov a_1, Acc1
	mov a_2, Acc2	
	muls a_1, b0, a_1
	mov Acc2, a_1
	mov a_2, Acc1
	
	push {b0}
	mov b0, yn_1
	MULS b0, b1, b0
	ADDS b0, b0, a_1
	
	mov a_1, b2
	mov a_2, yn_2
	MULS a_1, a_2, a_1
	ADDS b0, a_1, b0
	mov Acc2, b0
	pop {b0}
	pop {a_1, a_2}	
#else
	mul Acc2,b0,Acc1
	
	mla Acc2,b1,yn_1,Acc2
	mla Acc2,b2,yn_2,Acc2
#endif
	
	;update the state
	mov yn_2,yn_1
	mov yn_1,Acc1
	
	;store result
#if(__CORTEX_M == 0)
	push {b0}
	mov b0, Acc2
	str b0,[pi_Output]
	ADDS pi_Output, #4
	pop {b0}
#else
	str Acc2,[pi_Output],#4
#endif
	
	subs.n i_NSamples,i_NSamples,#1
	bne.n InnerLoop

	;store updated state to memory	
#if(__CORTEX_M == 0)
	push {b0, b1}
	mov b0, yn_1
	ldr b1, =2*5
	strh b0, [pS_StateCoeff, b1]
	mov b0, yn_2
	ldr b1, =2*6
	strh b0, [pS_StateCoeff, b1]
	pop {b0, b1}
#else
	strh yn_1, [pS_StateCoeff,#(2*5)]
	strh yn_2, [pS_StateCoeff,#(2*6)]
#endif
	
	pop {r4}
	mov r14, r4
	pop {r4-r7}
	mov r11, r7
	mov r10, r6
	mov r9, r5
	mov r8, r4	
	pop {r4-r7}

;	pop {r4-r11,r14}
	
	bx lr

	END
