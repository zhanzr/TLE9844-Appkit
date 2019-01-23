/**
 * @cond
 ***********************************************************************************************************************
 *
 * Copyright (c) 2017, Infineon Technologies AG
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,are permitted provided that the
 * following conditions are met:
 *
 *   Redistributions of source code must retain the above copyright notice, this list of conditions and the  following
 *   disclaimer.
 *
 *   Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the
 *   following disclaimer in the documentation and/or other materials provided with the distribution.
 *
 *   Neither the name of the copyright holders nor the names of its contributors may be used to endorse or promote
 *   products derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
 * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE  FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY,OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT  OF THE
 * USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 **********************************************************************************************************************/
/*******************************************************************************
**                      Author(s) Identity
********************************************************************************
**
** Initials     Name
** ---------------------------------------------------------------------------
** DM           Daniel Mysliwitz
** TA           Thomas Albersinger
** AV           Axel Viebig
** KC           Kay Claussen
**
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History
*******************************************************************************/
/* 
 * V0.1.0: 2015-10-23, AV:   Initial version
 * V0.1.1: 2015-11-03, AV:   Changes for DU Measurements
 * V0.1.2: 2015-11-08, AV:   Corrected IRQS->IRQCLR in LS and HS section
 * V0.1.3: 2015-11-20, AV:   LSx OT prewarn Interrupts removed (not on LSx Nodes)
 *                           Corrected naming in HS1 and HS2 section
 *                           Rewritten whole NMI and ADC2 section
 *                           Solved a problem that otherwise might block
 *                           Supply NMI under certain conditions
 * V0.1.4: 2015-11-27, AV:   Extended for MON5  
 *                           Added HardFault ISR
 *                           EXINTx processing made compatible with XML implementation
 *                          -corrected wrong documented (also in debugger)
 *                           EXINTn Trigger select assignment (EXINT Interrupts):
 *                           0 (and not 3) is "Bypass Edge detection..."
 *                           3 (and not 2) is "...both edges"
 *                           2 (and not 0) is "...fallig edge"
 *                          -Added LIN_SMERR_CALLBACK
 * V0.1.5: 2017-02-22, KC:   All ISRs: Interrupt enable checked at runtime
 * V0.1.6: 2017-10-25, KC:   Names of Interrupt Clear Macros adapted
 *                           XML Version Check enabled; Ext. Callbacks added
 * V0.1.7: 2017-11-24, KC:   Interrupt clear for VBAT prewarning corrected
 * V0.1.8: 2017-11-27, KC:   ADC1: ESM_STS bit needs to be cleared in interrupt 
 ******************************************************************************/ 

/*******************************************************************************
**                      MISRA                                                 **
*******************************************************************************/
/*lint -e9032 Supressing MISRA 2012 Rule 10.7 */
/*lint -e9053 Supressing MISRA 2012 Rule 12.2 */

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "tle_device.h"
#include "int_defines.h"
#include "isr_defines.h"

/*******************************************************************************
**                      External CallBacks                                    **
*******************************************************************************/
/* GPT1 Call Backs */
#if (GPT12E_T2_INT_EN == 1u)
  extern void GPT1_T2_CALLBACK(void);
#endif /*(GPT12E_T2_INT_EN == 1u)*/
#if (GPT12E_T3_INT_EN == 1u)
  extern void GPT1_T3_CALLBACK(void);
#endif /*(GPT12E_T3_INT_EN == 1u)*/
#if (GPT12E_T4_INT_EN == 1u)
  extern void GPT1_T4_CALLBACK(void);
#endif /*(GPT12E_T4_INT_EN == 1u)*/

/* GPT2 Call Backs */
#if (GPT12E_T5_INT_EN == 1u)  
  extern void GPT2_T5_CALLBACK(void);
#endif /*(GPT12E_T5_INT_EN == 1u)*/
#if (GPT12E_T6_INT_EN == 1u)
  extern void GPT2_T6_CALLBACK(void);
#endif /*(GPT12E_T6_INT_EN == 1u)*/
#if (GPT12E_CAPREL_INT_EN == 1u)
  extern void GPT2_CAPREL_CALLBACK(void);
#endif /*(GPT12E_CAPREL_INT_EN == 1u)*/

/* ADC1 Call Backs */
#if (ADC1_CH0_INT_EN == 1u)
  extern void ADC1_CH0_CALLBACK(void);
#endif /*(ADC1_CH0_INT_EN == 1u)*/
#if (ADC1_CH1_INT_EN == 1u)
  extern void ADC1_CH1_CALLBACK(void);
#endif /*(ADC1_CH1_INT_EN == 1u)*/
#if (ADC1_CH2_INT_EN == 1u)
  extern void ADC1_CH2_CALLBACK(void);
#endif /*(ADC1_CH2_INT_EN == 1u)*/
#if (ADC1_CH3_INT_EN == 1u)
  extern void ADC1_CH3_CALLBACK(void);
#endif /*(ADC1_CH3_INT_EN == 1u)*/
#if (ADC1_CH4_INT_EN == 1u)
  extern void ADC1_CH4_CALLBACK(void);
#endif /*(ADC1_CH4_INT_EN == 1u)*/
#if (ADC1_CH5_INT_EN == 1u)
  extern void ADC1_CH5_CALLBACK(void);
#endif /*(ADC1_CH5_INT_EN == 1u)*/
#if (ADC1_CH6_INT_EN == 1u)
  extern void ADC1_CH6_CALLBACK(void);
#endif /*(ADC1_CH6_INT_EN == 1u)*/
#if (ADC1_CH7_INT_EN == 1u)
  extern void ADC1_CH7_CALLBACK(void);
#endif /*(ADC1_CH7_INT_EN == 1u)*/
#if (ADC1_CH8_INT_EN == 1u)
  extern void ADC1_CH8_CALLBACK(void);
#endif /*(ADC1_CH8_INT_EN == 1u)*/
#if (ADC1_CH9_INT_EN == 1u)
  extern void ADC1_CH9_CALLBACK(void);
#endif /*(ADC1_CH9_INT_EN == 1u)*/
#if (ADC1_CH10_INT_EN == 1u)
  extern void ADC1_CH10_CALLBACK(void);
#endif /*(ADC1_CH10_INT_EN == 1u)*/
#if (ADC1_CH11_INT_EN == 1u)
  extern void ADC1_CH11_CALLBACK(void);
#endif /*(ADC1_CH11_INT_EN == 1u)*/
#if (ADC1_CH12_INT_EN == 1u)
  extern void ADC1_CH12_CALLBACK(void);
#endif /*(ADC1_CH12_INT_EN == 1u)*/
#if (ADC1_EIM_INT_EN == 1u)
  extern void ADC1_EIM_CALLBACK(void);
#endif /*(ADC1_EIM_INT_EN == 1u)*/
#if (ADC1_ESM_INT_EN == 1u)
  extern void ADC1_ESM_CALLBACK(void);
#endif /*(ADC1_ESM_INT_EN == 1u)*/

#if (ADC1_CH1_LO_INT_EN == 1u)
  extern void ADC1_CH1_LO_CALLBACK(void);
#endif /*(ADC1_CH1_LO_INT_EN == 1u)*/
#if (ADC1_CH1_UP_INT_EN == 1u)
  extern void ADC1_CH1_UP_CALLBACK(void);
#endif /*(ADC1_CH1_UP_INT_EN == 1u)*/
#if (ADC1_CH2_LO_INT_EN == 1u)
  extern void ADC1_CH2_LO_CALLBACK(void);
#endif /*(ADC1_CH2_LO_INT_EN == 1u)*/
#if (ADC1_CH2_UP_INT_EN == 1u)
  extern void ADC1_CH2_UP_CALLBACK(void);
#endif /*(ADC1_CH2_UP_INT_EN == 1u)*/
#if (ADC1_CH3_LO_INT_EN == 1u)
  extern void ADC1_CH3_LO_CALLBACK(void);
#endif /*(ADC1_CH3_LO_INT_EN == 1u)*/
#if (ADC1_CH3_UP_INT_EN == 1u)
  extern void ADC1_CH3_UP_CALLBACK(void);
#endif /*(ADC1_CH3_UP_INT_EN == 1u)*/
#if (ADC1_CH4_LO_INT_EN == 1u)
  extern void ADC1_CH4_LO_CALLBACK(void);
#endif /*(ADC1_CH4_LO_INT_EN == 1u)*/
#if (ADC1_CH4_UP_INT_EN == 1u)
  extern void ADC1_CH4_UP_CALLBACK(void);
#endif /*(ADC1_CH4_UP_INT_EN == 1u)*/
#if (ADC1_CH5_LO_INT_EN == 1u)
  extern void ADC1_CH5_LO_CALLBACK(void);
#endif /*(ADC1_CH5_LO_INT_EN == 1u)*/
#if (ADC1_CH5_UP_INT_EN == 1u)
  extern void ADC1_CH5_UP_CALLBACK(void);
#endif /*(ADC1_CH5_UP_INT_EN == 1u)*/
#if (ADC1_CH6_LO_INT_EN == 1u)
  extern void ADC1_CH6_LO_CALLBACK(void);
#endif /*(ADC1_CH6_LO_INT_EN == 1u)*/
#if (ADC1_CH6_UP_INT_EN == 1u)
  extern void ADC1_CH6_UP_CALLBACK(void);
#endif /*(ADC1_CH6_UP_INT_EN == 1u)*/
#if (ADC1_CH7_LO_INT_EN == 1u)
  extern void ADC1_CH7_LO_CALLBACK(void);
#endif /*(ADC1_CH7_LO_INT_EN == 1u)*/
#if (ADC1_CH7_UP_INT_EN == 1u)
  extern void ADC1_CH7_UP_CALLBACK(void);
#endif /*(ADC1_CH7_UP_INT_EN == 1u)*/
#if (ADC1_CH8_LO_INT_EN == 1u)
  extern void ADC1_CH8_LO_CALLBACK(void);
#endif /*(ADC1_CH8_LO_INT_EN == 1u)*/
#if (ADC1_CH8_UP_INT_EN == 1u)
  extern void ADC1_CH8_UP_CALLBACK(void);
#endif /*(ADC1_CH8_UP_INT_EN == 1u)*/
#if (ADC1_CH9_LO_INT_EN == 1u)
  extern void ADC1_CH9_LO_CALLBACK(void);
#endif /*(ADC1_CH9_LO_INT_EN == 1u)*/
#if (ADC1_CH9_UP_INT_EN == 1u)
  extern void ADC1_CH9_UP_CALLBACK(void);
#endif /*(ADC1_CH9_UP_INT_EN == 1u)*/
#if (ADC1_CH10_LO_INT_EN == 1u)
  extern void ADC1_CH10_LO_CALLBACK(void);
#endif /*(ADC1_CH10_LO_INT_EN == 1u)*/
#if (ADC1_CH10_UP_INT_EN == 1u)
  extern void ADC1_CH10_UP_CALLBACK(void);
#endif /*(ADC1_CH10_UP_INT_EN == 1u)*/
#if (ADC1_CH11_LO_INT_EN == 1u)
  extern void ADC1_CH11_LO_CALLBACK(void);
#endif /*(ADC1_CH11_LO_INT_EN == 1u)*/
#if (ADC1_CH11_UP_INT_EN == 1u)
  extern void ADC1_CH11_UP_CALLBACK(void);
#endif /*(ADC1_CH11_UP_INT_EN == 1u)*/

#if (ADC1_DCH1_LO_INT_EN == 1u)
  extern void ADC1_DCH1_LO_CALLBACK(void);
#endif /*(ADC1_DCH1_LO_INT_EN == 1u)*/
#if (ADC1_DCH1_UP_INT_EN == 1u)
  extern void ADC1_DCH1_UP_CALLBACK(void);
#endif /*(ADC1_DCH1_UP_INT_EN == 1u)*/
#if (ADC1_DCH2_LO_INT_EN == 1u)
  extern void ADC1_DCH2_LO_CALLBACK(void);
#endif /*(ADC1_DCH2_LO_INT_EN == 1u)*/
#if (ADC1_DCH2_UP_INT_EN == 1u)
  extern void ADC1_DCH2_UP_CALLBACK(void);
#endif /*(ADC1_DCH2_UP_INT_EN == 1u)*/
#if (ADC1_DCH3_LO_INT_EN == 1u)
  extern void ADC1_DCH3_LO_CALLBACK(void);
#endif /*(ADC1_DCH3_LO_INT_EN == 1u)*/
#if (ADC1_DCH3_UP_INT_EN == 1u)
  extern void ADC1_DCH3_UP_CALLBACK(void);
#endif /*(ADC1_DCH3_UP_INT_EN == 1u)*/
#if (ADC1_DCH4_LO_INT_EN == 1u)
  extern void ADC1_DCH4_LO_CALLBACK(void);
#endif /*(ADC1_DCH4_LO_INT_EN == 1u)*/
#if (ADC1_DCH4_UP_INT_EN == 1u)
  extern void ADC1_DCH4_UP_CALLBACK(void);
#endif /*(ADC1_DCH4_UP_INT_EN == 1u)*/

/* ADC2 */
#if (ADC2_VBG_UP_INT_EN == 1u)
  extern void ADC2_VBG_UP_CALLBACK(void);
#endif
#if (ADC2_VBG_LO_INT_EN == 1u)
  extern void ADC2_VBG_LO_CALLBACK(void);
#endif

/* CCU6 Call Backs*/
#if (CCU6_CH0_CM_R_INT_EN == 1u)
  extern void CCU6_CH0_CM_R_CALLBACK(void);
#endif
#if (CCU6_CH0_CM_F_INT_EN == 1u)
  extern void CCU6_CH0_CM_F_CALLBACK(void);
#endif
#if (CCU6_CH1_CM_R_INT_EN == 1u)
  extern void CCU6_CH1_CM_R_CALLBACK(void);
#endif
#if (CCU6_CH1_CM_F_INT_EN == 1u)
  extern void CCU6_CH1_CM_F_CALLBACK(void);
#endif
#if (CCU6_CH2_CM_R_INT_EN == 1u)
  extern void CCU6_CH2_CM_R_CALLBACK(void);
#endif
#if (CCU6_CH2_CM_F_INT_EN == 1u)
  extern void CCU6_CH2_CM_F_CALLBACK(void);
#endif
#if (CCU6_T12_OM_INT_EN == 1u)
  extern void CCU6_T12_OM_CALLBACK(void);
#endif
#if (CCU6_T12_PM_INT_EN == 1u)
  extern void CCU6_T12_PM_CALLBACK(void);
#endif
#if (CCU6_T13_CM_INT_EN == 1u)
  extern void CCU6_T13_CM_CALLBACK(void);
#endif
#if (CCU6_T13_PM_INT_EN == 1u)
  extern void CCU6_T13_PM_CALLBACK(void);
#endif
#if (CCU6_TRAP_INT_EN == 1u)
  extern void CCU6_TRAP_CALLBACK(void);
#endif
#if (CCU6_CHE_INT_EN == 1u)
  extern void CCU6_CORRECT_HALL_CALLBACK(void);
#endif
#if (CCU6_WHE_INT_EN == 1u)
  extern void CCU6_WRONG_HALL_CALLBACK(void);
#endif
#if (CCU6_MCM_STR_INT_EN == 1u)
  extern void CCU6_MCM_STR_CALLBACK(void);
#endif

/* SSC1 Call Backs*/
#if (SSC1_RX_INT_EN == 1u)
  extern void SSC1_RX_CALLBACK(void);
#endif
#if (SSC1_TX_INT_EN == 1u)
  extern void SSC1_TX_CALLBACK(void);
#endif
#if (SSC1_ERR_INT_EN == 1u)
  extern void SSC1_ERR_CALLBACK(void);
#endif

/* SSC2 Call Backs*/
#if (SSC2_RX_INT_EN == 1u)
  extern void SSC2_RX_CALLBACK(void);
#endif
#if (SSC2_TX_INT_EN == 1u)
  extern void SSC2_TX_CALLBACK(void);
#endif
#if (SSC2_ERR_INT_EN == 1u)
  extern void SSC2_ERR_CALLBACK(void);
#endif

/* UART1/TIMER2/LIN Call Backs*/
#if (UART1_RX_INT_EN == 1u)
  extern void UART1_RX_CALLBACK(void);
#endif
#if (UART1_TX_INT_EN == 1u)
  extern void UART1_TX_CALLBACK(void);
#endif
#if (TIMER2_TF2_INT_EN == 1u)
  extern void TIMER2_TF2_CALLBACK(void);
#endif
#if (TIMER2_EXF2_INT_EN == 1u)
  extern void TIMER2_EXF2_CALLBACK(void);
#endif
#if (LIN_SMERR_INT_EN == 1u)
  extern void LIN_SMERR_CALLBACK(void);
#endif
#if (LIN_OC_INT_EN == 1u)
  extern void LIN_OC_CALLBACK(void);
#endif
#if (LIN_OT_INT_EN == 1u)
  extern void LIN_OT_CALLBACK(void);
#endif
#if (LIN_TMOUT_INT_EN == 1u)
  extern void LIN_TMOUT_CALLBACK(void);
#endif
#if (LIN_EOF_INT_EN == 1u)
  extern void LIN_EOF_CALLBACK(void);
#endif
#if (LIN_ERR_INT_EN == 1u)
  extern void LIN_ERR_CALLBACK(void);
#endif

/* UART2/TIMER21/EXINT2 Call Backs*/
#if (UART2_RX_INT_EN == 1u)
  extern void UART2_RX_CALLBACK(void);
#endif
#if (UART2_TX_INT_EN == 1u)
  extern void UART2_TX_CALLBACK(void);
#endif
#if (TIMER21_TF2_INT_EN == 1u)
  extern void TIMER21_TF2_CALLBACK(void);
#endif
#if (TIMER21_EXF2_INT_EN == 1u)
  extern void TIMER21_EXF2_CALLBACK(void);
#endif
#if (SCU_EXINT2_RISING_INT_EN == 1u)
  extern void EXINT2_RISING_CALLBACK(void);
#endif
#if (SCU_EXINT2_FALLING_INT_EN == 1u)
  extern void EXINT2_FALLING_CALLBACK(void);
#endif

/* EXINT0 Call Backs*/
#if (SCU_EXINT0_RISING_INT_EN == 1u)
  extern void EXINT0_RISING_CALLBACK(void);
#endif
#if (SCU_EXINT0_FALLING_INT_EN == 1u)
  extern void EXINT0_FALLING_CALLBACK(void);
#endif

/* EXINT1 Call Backs*/
#if (SCU_EXINT1_RISING_INT_EN == 1u)
  extern void EXINT1_RISING_CALLBACK(void);
#endif
#if (SCU_EXINT1_FALLING_INT_EN == 1u)
  extern void EXINT1_FALLING_CALLBACK(void);
#endif

/* WAKEUP Call Backs*/
#if (PMU_GPIO_WAKEUP_INT_EN == 1u)
  extern void PMU_WAKEUP_CALLBACK(void);
#endif

/* LS1 Call Backs*/
#if (LS1_OC_INT_EN == 1u)
  extern void LS1_OC_CALLBACK(void);
#endif
#if (LS1_OL_INT_EN == 1u)
  extern void LS1_OL_CALLBACK(void);
#endif
#if (LS1_OT_INT_EN == 1u)
  extern void LS1_OT_CALLBACK(void);
#endif

/* LS2 Call Backs*/
#if (LS2_OC_INT_EN == 1u)
  extern void LS2_OC_CALLBACK(void);
#endif
#if (LS2_OL_INT_EN == 1u)
  extern void LS2_OL_CALLBACK(void);
#endif
#if (LS2_OT_INT_EN == 1u)
  extern void LS2_OT_CALLBACK(void);
#endif

/* HS1 Call Backs*/
#if (HS1_OC_INT_EN == 1u)
  extern void HS1_OC_CALLBACK(void);
#endif
#if (HS1_OL_INT_EN == 1u)
  extern void HS1_OL_CALLBACK(void);
#endif
#if (HS1_OT_INT_EN == 1u)
  extern void HS1_OT_CALLBACK(void);
#endif

/* HS2 Call Backs*/
#if (HS2_OC_INT_EN == 1u)
  extern void HS2_OC_CALLBACK(void);
#endif
#if (HS2_OL_INT_EN == 1u)
  extern void HS2_OL_CALLBACK(void);
#endif
#if (HS2_OT_INT_EN == 1u)
  extern void HS2_OT_CALLBACK(void);
#endif

/* MON1-4 Call Backs*/
#if (MON1_FALLING_INT_EN == 1u)
  extern void MON1_FALLING_CALLBACK(void); 
#endif
#if (MON1_RISING_INT_EN == 1u)
  extern void MON1_RISING_CALLBACK(void);
#endif   
//  extern void MON1_CYCLIC_CALLBACK(void); 
#if (MON2_FALLING_INT_EN == 1u)
  extern void MON2_FALLING_CALLBACK(void);
#endif     
#if (MON2_RISING_INT_EN == 1u)
  extern void MON2_RISING_CALLBACK(void);
#endif   
//  extern void MON2_CYCLIC_CALLBACK(void); 
#if (MON3_FALLING_INT_EN == 1u)
  extern void MON3_FALLING_CALLBACK(void);
#endif     
#if (MON3_RISING_INT_EN == 1u)
  extern void MON3_RISING_CALLBACK(void);
#endif   
//  extern void MON3_CYCLIC_CALLBACK(void); 
#if (MON4_FALLING_INT_EN == 1u)
  extern void MON4_FALLING_CALLBACK(void);
#endif
#if (MON4_RISING_INT_EN == 1u)
  extern void MON4_RISING_CALLBACK(void);
#endif      
//  extern void MON4_CYCLIC_CALLBACK(void); 
#if (MON5_FALLING_INT_EN == 1u)
  extern void MON5_FALLING_CALLBACK(void);
#endif
#if (MON5_RISING_INT_EN == 1u)
  extern void MON5_RISING_CALLBACK(void);
#endif      
//

/* NMI Call Backs */
#if (SCU_NMI_PLL_INT_EN == 1u)
  extern void SCU_NMI_PLL_CALLBACK(void);
#endif
#if (SCU_NMI_NVM_INT_EN == 1u)
  extern void SCU_NMI_NVM_CALLBACK(void);
#endif
#if (SCU_NMI_OWD_INT_EN == 1u)
  extern void SCU_NMI_OWD_CALLBACK(void);
#endif
#if (SCU_NMI_MAP_INT_EN == 1u)
  extern void SCU_NMI_MAP_CALLBACK(void);
#endif
#if ( ADC2_SYS_TEMP_UP_INT_EN == 1u)
  extern void ADC2_SYS_TEMP_UP_CALLBACK(void);
#endif
#if ( ADC2_SYS_TEMP_LO_INT_EN == 1u)
  extern void ADC2_SYS_TEMP_LO_CALLBACK(void);
#endif
#if (SCU_ECC_RAM_DB_INT_EN == 1u)
  extern void SCU_ECC_RAM_DB_CALLBACK(void);
#endif
#if (SCU_ECC_NVM_DB_INT_EN == 1u)
  extern void SCU_ECC_NVM_DB_CALLBACK(void);
#endif
/* NMI Supply Error Call Backs*/
#if (ADC1_CH0_UP_INT_EN == 1u)  
  extern void ADC1_CH0_UP_CALLBACK(void);
#endif
#if (ADC1_CH0_LO_INT_EN == 1u)
  extern void ADC1_CH0_LO_CALLBACK(void);
#endif
#if (ADC2_VS_UP_INT_EN == 1u)
  extern void ADC2_VS_UP_CALLBACK(void);
#endif  
#if (ADC2_VS_LO_INT_EN == 1u)
  extern void ADC2_VS_LO_CALLBACK(void);
#endif
#if (ADC2_VDDP_UP_INT_EN == 1u)
  extern void ADC2_VDDP_UP_CALLBACK(void);
#endif
#if (ADC2_VDDP_LO_INT_EN == 1u)
  extern void ADC2_VDDP_LO_CALLBACK(void);
#endif
#if (ADC2_VDDC_UP_INT_EN == 1u)
  extern void ADC2_VDDC_UP_CALLBACK(void);
#endif
#if (ADC2_VDDC_LO_INT_EN == 1u)
  extern void ADC2_VDDC_LO_CALLBACK(void);
#endif
#if (ADC2_VDDEXT_UP_INT_EN == 1u)
  extern void ADC2_VDDEXT_UP_CALLBACK(void);
#endif
#if (ADC2_VDDEXT_LO_INT_EN == 1u)
  extern void ADC2_VDDEXT_LO_CALLBACK(void);
#endif
#if (PMU_VDDP_OV_INT_EN == 1u)
  extern void PMU_VDDP_OV_CALLBACK(void);
#endif /*(PMU_VDDP_OV_INT_EN == 1u)*/
#if (PMU_VDDP_OL_INT_EN == 1u)
  extern void PMU_VDDP_OL_CALLBACK(void);
#endif /*(PMU_VDDP_OL_INT_EN == 1u)*/
#if (PMU_VDDC_OV_INT_EN == 1u)
  extern void PMU_VDDC_OV_CALLBACK(void);
#endif 
#if (PMU_VDDC_OL_INT_EN == 1u)
  extern void PMU_VDDC_OL_CALLBACK(void);
#endif 
#if (PMU_VDDEXT_UV_INT_EN == 1u)
  extern void PMU_VDDEXT_UV_CALLBACK(void);
#endif
#if (PMU_VDDEXT_OT_INT_EN == 1u)
  extern void PMU_VDDEXT_OT_CALLBACK(void);
#endif

/* Core Exceptions */
#if (CPU_HARDFAULT_EN == 1u)
  extern void CPU_HARDFAULT_CALLBACK(void);
#endif
#if (CPU_SYSTICK_EN == 1u)
  extern void CPU_SYSTICK_CALLBACK(void);
#endif

#define CCU6_SR0 0u
#define CCU6_SR1 1u
#define CCU6_SR2 2u
#define CCU6_SR3 3u

void GPT1_IRQHandler(void);
void GPT2_IRQHandler(void);
void ADC2_IRQHandler(void);
void ADC1_IRQHandler(void);
void CCU6SR0_IRQHandler(void);
void CCU6SR1_IRQHandler(void);
void CCU6SR2_IRQHandler(void);
void CCU6SR3_IRQHandler(void);
void SSC1_IRQHandler(void);
void SSC2_IRQHandler(void);
void UART1_IRQHandler(void);
void UART2_IRQHandler(void);
void EXINT0_IRQHandler(void);
void EXINT1_IRQHandler(void);
void WAKEUP_IRQHandler(void);
void LS1_IRQHandler(void);
void LS2_IRQHandler(void);
void HS1_IRQHandler(void);
void HS2_IRQHandler(void);
void DU_IRQHandler(void);
void MON_IRQHandler(void);
void PORT_IRQHandler(void);
void NMI_Handler(void);
void HardFault_Handler(void);
void SysTick_Handler(void);

#if (INT_XML_VERSION < 10106)
 #error "use IFXConfigWizard XML Version V1.1.6 or greater"
#else
/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
/** \brief Peripheral Modules ISRs.
 *
 * \param None
 * \return None
 *
 * \ingroup drv_api
 */
/*******************************************************************************
**                      GPT1 ISR                                              **
*******************************************************************************/
#if ((GPT12E_T2_INT_EN == 1u) || \
     (GPT12E_T3_INT_EN == 1u) || \
     (GPT12E_T4_INT_EN == 1u))
void GPT1_IRQHandler(void)
{
#if (GPT12E_T2_INT_EN == 1u)
  /* GPT1u - T2 Interrupt */
  if ((uint8)SCU->GPT12IEN.bit.T2IE == (uint8)1u)
  {
    if ((uint8)SCU->GPT12IRC.bit.GPT1T2 == (uint8)1u)
    {
      GPT1_T2_CALLBACK();
      GPT12E_T2_Int_Clr();
    }
  }
#endif /*(GPT12E_T2_INT_EN == 1u)*/

#if (GPT12E_T3_INT_EN == 1u)
  /* GPT1u - T3 Interrupt */
  if ((uint8)SCU->GPT12IEN.bit.T3IE == (uint8)1u)
  {
    if ((uint8)SCU->GPT12IRC.bit.GPT1T3 == (uint8)1u)
    {
      GPT1_T3_CALLBACK();
      GPT12E_T3_Int_Clr();
    }
  }
#endif /*(GPT12E_T3_INT_EN == 1u)*/

#if (GPT12E_T4_INT_EN == 1u)
  /* GPT1u - T4 Interrupt */
  if ((uint8)SCU->GPT12IEN.bit.T4IE == (uint8)1u)
  {
    if ((uint8)SCU->GPT12IRC.bit.GPT1T4 == (uint8)1u)
    {
      GPT1_T4_CALLBACK();
      GPT12E_T4_Int_Clr();
    }
  }
#endif /*(GPT12E_T4_INT_EN == 1u)*/
}
#endif

/*******************************************************************************
**                      GPT2 ISR
*******************************************************************************/
#if ((GPT12E_T5_INT_EN == 1u) || \
     (GPT12E_T6_INT_EN == 1u) || \
     (GPT12E_CAPREL_INT_EN == 1u))
void GPT2_IRQHandler(void)
{
#if (GPT12E_T5_INT_EN == 1u)
  /* GPT2 - T5 Interrupt */
  if ((uint8)SCU->GPT12IEN.bit.T5IE == (uint8)1u)
  {
    if ((uint8)SCU->GPT12IRC.bit.GPT2T5 == (uint8)1u)
    {
      GPT2_T5_CALLBACK();
      GPT12E_T5_Int_Clr();
    }
  }
#endif /*(GPT12E_T5_INT_EN == 1u)*/

#if (GPT12E_T6_INT_EN == 1u)
  /* GPT2 - T6 Interrupt */
  if ((uint8)SCU->GPT12IEN.bit.T6IE == (uint8)1u)
  {
    if ((uint8)SCU->GPT12IRC.bit.GPT2T6 == (uint8)1u)
    {
      GPT2_T6_CALLBACK();
      GPT12E_T6_Int_Clr();
    }
  }
#endif /*(GPT12E_T6_INT_EN == 1u)*/

#if (GPT12E_CAPREL_INT_EN == 1u)
  /* GPT2 - CAPREL Interrupt */
  if ((uint8)SCU->GPT12IEN.bit.CRIE == (uint8)1u)
  {
    if ((uint8)SCU->GPT12IRC.bit.GPT12CR == (uint8)1u)
    {
      GPT2_CAPREL_CALLBACK();
      GPT12E_CapRel_Int_Clr();
    }
  }
#endif /*(GPT12E_CAPREL_INT_EN == 1u)*/
}
#endif

/*******************************************************************************
**                      ADC2 ISR
*******************************************************************************/
#if ((ADC2_VBG_UP_INT_EN == 1u) || \
     (ADC2_VBG_LO_INT_EN == 1u))
void ADC2_IRQHandler(void)
{
#if (ADC2_VBG_UP_INT_EN == 1u)
  if (SCUPM->SYS_IRQ_CTRL.bit.REFBG_UPTHWARN_IE == 1u)
  {
    /* ?MF->REF1_STS.bit.REFBG_UPTHWARN_STS AND SCUPM->SYS_IS.bit.REFBG_UPTHWARN_IS ? */
    if (MF->REF1_STS.bit.REFBG_UPTHWARN_STS == 1u)
    {
      SCUPM->SYS_IRQ_CTRL.bit.REFBG_UPTHWARN_IE  = 0u; //prevent permanent triggering if condition is still active 
      ADC2_VBG_UP_CALLBACK();
      ADC2_VBG_OV_Int_Clr();//SCUPM->SYS_ISCLR.bit.REFBG_UPTHWARN_ISC = 1u;
    }
  }
#endif /*(ADC2_VBG_UP_INT_EN == 1u)*/

#if (ADC2_VBG_LO_INT_EN == 1u)
  if (SCUPM->SYS_IRQ_CTRL.bit.REFBG_LOTHWARN_IE == 1u)
  {
    /* ?MF->REF1_STS.bit.REFBG_LOTHWARN_STS AND SCUPM->SYS_IS.bit.REFBG_LOTHWARN_IS ? */
    if (MF->REF1_STS.bit.REFBG_LOTHWARN_STS == 1u)
    {
      SCUPM->SYS_IRQ_CTRL.bit.REFBG_LOTHWARN_IE  = 0u; //prevent permanent triggering if condition is still active 
      ADC2_VBG_LO_CALLBACK();
      ADC2_VBG_UV_Int_Clr();//SCUPM->SYS_ISCLR.bit.REFBG_LOTHWARN_ISC = 1u;
    }
  }
#endif /*(ADC2_VBG_LO_INT_EN == 1u)*/
}
#endif

/*******************************************************************************
**                      ADC1 ISR                                              **
*******************************************************************************/
#if ((ADC1_CH0_INT_EN == 1u) || \
     (ADC1_CH1_INT_EN == 1U) || \
     (ADC1_CH2_INT_EN == 1U) || \
     (ADC1_CH3_INT_EN == 1U) || \
     (ADC1_CH4_INT_EN == 1U) || \
     (ADC1_CH5_INT_EN == 1U) || \
     (ADC1_CH6_INT_EN == 1U) || \
     (ADC1_CH7_INT_EN == 1U) || \
     (ADC1_CH8_INT_EN == 1U) || \
     (ADC1_CH9_INT_EN == 1U) || \
     (ADC1_CH10_INT_EN == 1U) || \
     (ADC1_CH11_INT_EN == 1U) || \
     (ADC1_CH12_INT_EN == 1U) || \
     (ADC1_EIM_INT_EN == 1U) || \
     (ADC1_ESM_INT_EN == 1U) || \
     (ADC1_CH1_UP_INT_EN == 1U) || \
     (ADC1_CH1_LO_INT_EN == 1U))
void ADC1_IRQHandler(void)
{
#if (ADC1_CH0_INT_EN == 1u)
  /* ADC1 - Ch0 Interrupt */
  if (ADC1->IRQEN_1.bit.VBATSEN_IEN == 1u)
  {
    if (ADC1->IRQS_1.bit.VBATSEN_IS == 1u)
    {
      ADC1_CH0_CALLBACK();
      ADC1_VbatSense_Int_Clr();
    }
  }
#endif
#if (ADC1_CH1_INT_EN == 1u)
  /* ADC1 - Ch1 Interrupt */
  if (ADC1->IRQEN_1.bit.VS_IEN == 1u)
  {
    if (ADC1->IRQS_1.bit.VS_IS == 1u)
    {
      ADC1_CH1_CALLBACK();
      ADC1_VS_Int_Clr();
    }
  }
#endif
#if (ADC1_CH2_INT_EN == 1u)
  /* ADC1 - Ch2 Interrupt */
  if (ADC1->IRQEN_1.bit.MON1_IEN == 1u)
  {
    if (ADC1->IRQS_1.bit.MON1_IS == 1u)
    {
      ADC1_CH2_CALLBACK();
      ADC1_MON1_Int_Clr();
    }
  }
#endif
#if (ADC1_CH3_INT_EN == 1u)
  /* ADC1 - Ch3 Interrupt */
  if (ADC1->IRQEN_1.bit.MON2_IEN == 1u)
  {
    if (ADC1->IRQS_1.bit.MON2_IS == 1u)
    {
      ADC1_CH3_CALLBACK();
      ADC1_MON2_Int_Clr();
    }
  }
#endif  
#if (ADC1_CH4_INT_EN == 1u)
  /* ADC1 - Ch4 Interrupt */
  if (ADC1->IRQEN_1.bit.MON3_IEN == 1u)
  {
    if (ADC1->IRQS_1.bit.MON3_IS == 1u)
    {
      ADC1_CH4_CALLBACK();
      ADC1_MON3_Int_Clr();
    }
  } 
#endif
#if (ADC1_CH5_INT_EN == 1u)
  /* ADC1 - Ch5 Interrupt */
  if (ADC1->IRQEN_1.bit.MON4_IEN == 1u)
  {
    if (ADC1->IRQS_1.bit.MON4_IS == 1u)
    {
      ADC1_CH5_CALLBACK();
      ADC1_MON4_Int_Clr();
    }
  } 
#endif
#if (ADC1_CH6_INT_EN == 1u)
  /* ADC1 - Ch6 Interrupt */
  if (ADC1->IRQEN_1.bit.MON5_IEN == 1u)
  {
    if (ADC1->IRQS_1.bit.MON5_IS == 1u)
    {
      ADC1_CH6_CALLBACK();
      ADC1_MON5_Int_Clr();
    }
  } 
#endif
#if (ADC1_CH7_INT_EN == 1u)
  /* ADC1 - Ch7 Interrupt */
  if (ADC1->IRQEN_1.bit.P2_1_IEN == 1u)
  {
    if (ADC1->IRQS_1.bit.P2_1_IS == 1u)
    {
      ADC1_CH7_CALLBACK();
      ADC1_P21_Int_Clr();
    }
  } 
#endif
#if (ADC1_CH8_INT_EN == 1u)
  /* ADC1 - Ch8 Interrupt */
  if (ADC1->IRQEN_1.bit.P2_2_IEN == 1u)
  {
    if (ADC1->IRQS_1.bit.P2_2_IS == 1u)
    {
      ADC1_CH8_CALLBACK();
      ADC1_P22_Int_Clr();
    }
  } 
#endif
#if (ADC1_CH9_INT_EN == 1u)
  /* ADC1 - CH9 Interrupt */
  if (ADC1->IRQEN_1.bit.P2_3_IEN == 1u)
  {
    if (ADC1->IRQS_1.bit.P2_3_IS == 1u)
    {
      ADC1_CH9_CALLBACK();
      ADC1_P23_Int_Clr();
    }
  } 
#endif
#if (ADC1_CH10_INT_EN == 1u)
  /* ADC1 - CH10 Interrupt */
  if (ADC1->IRQEN_1.bit.P2_6_IEN == 1u)
  {
    if (ADC1->IRQS_1.bit.P2_6_IS == 1u)
    {
      ADC1_CH10_CALLBACK();
      ADC1_P26_Int_Clr();
    }
  } 
#endif
#if (ADC1_CH11_INT_EN == 1u)
  /* ADC1 - CH11 Interrupt */
  if (ADC1->IRQEN_1.bit.P2_7_IEN == 1u)
  {
    if (ADC1->IRQS_1.bit.P2_7_IS == 1u)
    {
      ADC1_CH11_CALLBACK();
      ADC1_P27_Int_Clr();
    }
  } 
#endif
#if (ADC1_CH12_INT_EN == 1u)
  /* ADC1 - CH12 Interrupt */
  if (ADC1->IRQEN_1.bit.P2_0_IEN == 1u)
  {
    if (ADC1->IRQS_1.bit.P2_0_IS == 1u)
    {
      ADC1_CH12_CALLBACK();
      ADC1_P20_Int_Clr();
    }
  } 
#endif
#if (ADC1_EIM_INT_EN == 1u)
  /* ADC1 - EIM Interrupt */
  if (ADC1->IRQEN_1.bit.EIM_IEN == 1u)
  {
    if (ADC1->IRQS_1.bit.EIM_IS == 1u)
    {
      ADC1_EIM_CALLBACK();
      ADC1_EIM_Int_Clr();
    }
  } 
#endif
#if (ADC1_ESM_INT_EN == 1u)
  /* ADC1 - ESM Interrupt */
  if (ADC1->IRQEN_1.bit.ESM_IEN == 1u)
  {
    if (ADC1->IRQS_1.bit.ESM_IS == 1u)
    {
      ADC1_ESM_CALLBACK();
      ADC1_ESM_Int_Clr();
      ADC1->CHx_ESM.reg &= ~ADC1_CHx_ESM_ESM_STS_Msk;
    }
  } 
#endif
#if (ADC1_CH1_LO_INT_EN == 1u)
  /* ADC1 - CH1 LO Interrupt */
  if (ADC1->IRQEN_2.bit.VS_LO_IEN == 1u)
  {
    if (ADC1->IRQS_2.bit.VS_LO_IS == 1u)
    {
      ADC1_CH1_LO_CALLBACK();
      ADC1_VS_Lo_Int_Clr();
    }
  } 
#endif
#if (ADC1_CH1_UP_INT_EN == 1u)
  /* ADC1 - CH1 UP Interrupt */
  if (ADC1->IRQEN_2.bit.VS_UP_IEN == 1u)
  {
    if (ADC1->IRQS_2.bit.VS_UP_IS == 1u)
    {
      ADC1_CH1_UP_CALLBACK();
      ADC1_VS_Up_Int_Clr();
    }
  } 
#endif
}
#endif

/*******************************************************************************
**                      CCU6 SR0 ISR                                          **
*******************************************************************************/
/*lint -e572 Supressing MISRA 2012 Excessive shift value */
#if ((CPU_NVIC_ISER & (1u << 4u)) != 0u)
void CCU6SR0_IRQHandler(void)
{
#if (((CCU6_INP >> 0u) & 3u) == CCU6_SR0)

#if (CCU6_CH0_CM_R_INT_EN == 1u)
  if (CCU6->IEN.bit.ENCC60R == 1u)
  {
    if ((uint16)CCU6->IS.bit.ICC60R == (uint16)1u)
    {
      CCU6_CH0_CM_R_CALLBACK();
      CCU6_CH0_CM_R_Int_Clr();
    }
  }
#endif /*(CCU6_CH0_CM_R_INT_EN == 1u) */

#if (CCU6_CH0_CM_F_INT_EN == 1u)
  if (CCU6->IEN.bit.ENCC60F == 1u)
  {
    if ((uint16)CCU6->IS.bit.ICC60F == (uint16)1u)
    {
      CCU6_CH0_CM_F_CALLBACK();
      CCU6_CH0_CM_F_Int_Clr();
    }
  }
#endif /*(CCU6_CH0_CM_F_INT_EN == 1u) */
#endif /*((CCU6_INP >> 0u) & 3u) == CCU6_SR0) */

#if (((CCU6_INP >> 2u) & 3u) == CCU6_SR0)
#if (CCU6_CH1_CM_R_INT_EN == 1u)
  if (CCU6->IEN.bit.ENCC61R == 1u)
  {
    if ((uint16)CCU6->IS.bit.ICC61R == (uint16)1u)
    {
      CCU6_CH1_CM_R_CALLBACK();
      CCU6_CH1_CM_R_Int_Clr();
    }
  }
#endif /*(CCU6_CH1_CM_R_INT_EN == 1u) */

#if (CCU6_CH1_CM_F_INT_EN == 1u)
  if (CCU6->IEN.bit.ENCC61F == 1u)
  {
    if ((uint16)CCU6->IS.bit.ICC61F == (uint16)1u)
    {
      CCU6_CH1_CM_F_CALLBACK();
      CCU6_CH1_CM_F_Int_Clr();
    }
  }
#endif /*(CCU6_CH1_CM_F_INT_EN == 1u) */
#endif /*((CCU6_INP >> 2u) & 3u) == CCU6_SR0) */

#if (((CCU6_INP >> 4u) & 3u) == CCU6_SR0)
#if (CCU6_CH2_CM_R_INT_EN == 1u)
  if (CCU6->IEN.bit.ENCC62R == 1u)
  {
    if ((uint16)CCU6->IS.bit.ICC62R == (uint16)1u)
    {
      CCU6_CH2_CM_R_CALLBACK();
      CCU6_CH2_CM_R_Int_Clr();
    }
  }
#endif /*(CCU6_CH2_CM_R_INT_EN == 1u) */

#if (CCU6_CH2_CM_F_INT_EN == 1u)
  if (CCU6->IEN.bit.ENCC62F == 1u)
  {
    if ((uint16)CCU6->IS.bit.ICC62F == (uint16)1u)
    {
      CCU6_CH2_CM_F_CALLBACK();
      CCU6_CH2_CM_F_Int_Clr();
    }
  }
#endif /*(CCU6_CH2_CM_F_INT_EN == 1u) */
#endif /*((CCU6_INP >> 4u) & 3u) == CCU6_SR0) */

#if (((CCU6_INP >> 10u) & 3u) == CCU6_SR0)
#if (CCU6_T12_OM_INT_EN == 1u)
  if ((uint16)CCU6->IEN.bit.ENT12OM == (uint16)1u)
  {
    if ((uint16)CCU6->IS.bit.T12OM == (uint16)1u)
    {
      CCU6_T12_OM_CALLBACK();
      CCU6_T12_OM_Int_Clr();
    }
  }
#endif /*(CCU6_T12_OM_INT_EN == 1u) */

#if (CCU6_T12_PM_INT_EN == 1u)
  if ((uint16)CCU6->IEN.bit.ENT12PM == (uint16)1u)
  {
    if ((uint16)CCU6->IS.bit.T12PM == (uint16)1u)
    {
      CCU6_T12_PM_CALLBACK();
      CCU6_T12_PM_Int_Clr();
    }
  }
#endif /*(CCU6_T12_PM_INT_EN == 1u) */
#endif /*((CCU6_INP >> 10u) & 3u) == CCU6_SR0) */

#if (((CCU6_INP >> 12u) & 3u) == CCU6_SR0)
#if (CCU6_T13_CM_INT_EN == 1u)
  if ((uint16)CCU6->IEN.bit.ENT13CM == (uint16)1u)
  {
    if ((uint16)CCU6->IS.bit.T13CM == (uint16)1u)
    {
      CCU6_T13_CM_CALLBACK();
      CCU6_T13_CM_Int_Clr();
    }
  }
#endif /*(CCU6_T13_CM_INT_EN == 1u) */

#if (CCU6_T13_PM_INT_EN == 1u)
  if ((uint16)CCU6->IEN.bit.ENT13PM == (uint16)1u)
  {
    if ((uint16)CCU6->IS.bit.T13PM == (uint16)1u)
    {
      CCU6_T13_PM_CALLBACK();
      CCU6_T13_PM_Int_Clr();
    }
  }
#endif /*(CCU6_T13_PM_INT_EN == 1u) */
#endif /*((CCU6_INP >> 12u) & 3u) == CCU6_SR0) */

#if (((CCU6_INP >> 8u) & 3u) == CCU6_SR0)
#if (CCU6_TRAP_INT_EN == 1u)
  if ((uint16)CCU6->IEN.bit.ENTRPF == (uint16)1u)
  {
    if ((uint16)CCU6->IS.bit.TRPF == (uint16)1u)
    {
      CCU6_TRAP_CALLBACK();
      CCU6_TRAP_Int_Clr();
    }
  }
#endif /*(CCU6_TRAP_INT_EN == 1u) */

#if (CCU6_WHE_INT_EN == 1u)
  if ((uint16)CCU6->IEN.bit.ENWHE == (uint16)1u)
  {
    if ((uint16)CCU6->IS.bit.WHE == (uint16)1u)
    {
      CCU6_WRONG_HALL_CALLBACK();
      CCU6_WHE_Int_Clr();
    }
  }
#endif /*(CCU6_WHE_INT_EN == 1u) */
#endif /*((CCU6_INP >> 8u) & 3u) == CCU6_SR0) */

#if (((CCU6_INP >> 6u) & 3u) == CCU6_SR0)
#if (CCU6_CHE_INT_EN == 1u)
  if ((uint16)CCU6->IEN.bit.ENCHE == (uint16)1u)
  {
    if ((uint16)CCU6->IS.bit.CHE == (uint16)1u)
    {
      CCU6_CORRECT_HALL_CALLBACK();
      CCU6_CHE_Int_Clr();
    }
  }
#endif /*(CCU6_CHE_INT_EN == 1u) */

#if (CCU6_MCM_STR_INT_EN == 1u)
  if ((uint16)CCU6->IEN.bit.ENSTR == (uint16)1u)
  {
    if ((uint16)CCU6->IS.bit.STR == (uint16)1u)
    {
      CCU6_MCM_STR_CALLBACK();
      CCU6_STR_Int_Clr();
    }
  }
#endif /*(CCU6_MCM_STR_INT_EN == 1u) */
#endif /*((CCU6_INP >> 6u) & 3u) == CCU6_SR0) */

  SCU->IRCON4CLR.bit.CCU6SR0C = 1;
}
#endif

/*******************************************************************************
**                      CCU6 SR1 ISR                                          **
*******************************************************************************/
#if ((CPU_NVIC_ISER & (1u << 5u)) != 0u)
void CCU6SR1_IRQHandler(void)
{
#if (((CCU6_INP >> 0u) & 3u) == CCU6_SR1)
#if (CCU6_CH0_CM_R_INT_EN == 1u)
  if (CCU6->IEN.bit.ENCC60R == 1u)
  {
    if ((uint16)CCU6->IS.bit.ICC60R == (uint16)1u)
    {
      CCU6_CH0_CM_R_CALLBACK();
      CCU6_CH0_CM_R_Int_Clr();
    }
  }
#endif /*(CCU6_CH0_CM_R_INT_EN == 1u) */

#if (CCU6_CH0_CM_F_INT_EN == 1u)
  if (CCU6->IEN.bit.ENCC60F == 1u)
  {
    if ((uint16)CCU6->IS.bit.ICC60F == (uint16)1u)
    {
      CCU6_CH0_CM_F_CALLBACK();
      CCU6_CH0_CM_F_Int_Clr();
    }
  }
#endif /*(CCU6_CH0_CM_F_INT_EN == 1u) */
#endif /*((CCU6_INP >> 0u) & 3u) == CCU6_SR1) */

#if (((CCU6_INP >> 2u) & 3u) == CCU6_SR1)
#if (CCU6_CH1_CM_R_INT_EN == 1u)
  if (CCU6->IEN.bit.ENCC61R == 1u)
  {
    if ((uint16)CCU6->IS.bit.ICC61R == (uint16)1u)
    {
      CCU6_CH1_CM_R_CALLBACK();
      CCU6_CH1_CM_R_Int_Clr();
    }
  }
#endif /*(CCU6_CH1_CM_R_INT_EN == 1u) */

#if (CCU6_CH1_CM_F_INT_EN == 1u)
  if (CCU6->IEN.bit.ENCC61F == 1u)
  {
    if ((uint16)CCU6->IS.bit.ICC61F == (uint16)1u)
    {
      CCU6_CH1_CM_F_CALLBACK();
      CCU6_CH1_CM_F_Int_Clr();
    }
  }
#endif /*(CCU6_CH1_CM_F_INT_EN == 1u) */
#endif /*((CCU6_INP >> 2u) & 3u) == CCU6_SR1) */

#if (((CCU6_INP >> 4u) & 3u) == CCU6_SR1)
#if (CCU6_CH2_CM_R_INT_EN == 1u)
  if (CCU6->IEN.bit.ENCC62R == 1u)
  {
    if ((uint16)CCU6->IS.bit.ICC62R == (uint16)1u)
    {
      CCU6_CH2_CM_R_CALLBACK();
      CCU6_CH2_CM_R_Int_Clr();
    }
  }
#endif /*(CCU6_CH2_CM_R_INT_EN == 1u) */

#if (CCU6_CH2_CM_F_INT_EN == 1u)
  if (CCU6->IEN.bit.ENCC62F == 1u)
  {
    if ((uint16)CCU6->IS.bit.ICC62F == (uint16)1u)
    {
      CCU6_CH2_CM_F_CALLBACK();
      CCU6_CH2_CM_F_Int_Clr();
    }
  }
#endif /*(CCU6_CH2_CM_F_INT_EN == 1u) */
#endif /*((CCU6_INP >> 4u) & 3u) == CCU6_SR1) */

#if (((CCU6_INP >> 10u) & 3u) == CCU6_SR1)
#if (CCU6_T12_OM_INT_EN == 1u)
  if ((uint16)CCU6->IEN.bit.ENT12OM == (uint16)1u)
  {
    if ((uint16)CCU6->IS.bit.T12OM == (uint16)1u)
    {
      CCU6_T12_OM_CALLBACK();
      CCU6_T12_OM_Int_Clr();
    }
  }
#endif /*(CCU6_T12_OM_INT_EN == 1u) */

#if (CCU6_T12_PM_INT_EN == 1u)
  if ((uint16)CCU6->IEN.bit.ENT12PM == (uint16)1u)
  {
    if ((uint16)CCU6->IS.bit.T12PM == (uint16)1u)
    {
      CCU6_T12_PM_CALLBACK();
      CCU6_T12_PM_Int_Clr();
    }
  }
#endif /*(CCU6_T12_PM_INT_EN == 1u) */
#endif /*((CCU6_INP >> 10u) & 3u) == CCU6_SR1) */

#if (((CCU6_INP >> 12u) & 3u) == CCU6_SR1)
#if (CCU6_T13_CM_INT_EN == 1u)
  if ((uint16)CCU6->IEN.bit.ENT13CM == (uint16)1u)
  {
    if ((uint16)CCU6->IS.bit.T13CM == (uint16)1u)
    {
      CCU6_T13_CM_CALLBACK();
      CCU6_T13_CM_Int_Clr();
    }
  }
#endif /*(CCU6_T13_CM_INT_EN == 1u) */

#if (CCU6_T13_PM_INT_EN == 1u)
  if ((uint16)CCU6->IEN.bit.ENT13PM == (uint16)1u)
  {
    if ((uint16)CCU6->IS.bit.T13PM == (uint16)1u)
    {
      CCU6_T13_PM_CALLBACK();
      CCU6_T13_PM_Int_Clr();
    }
  }
#endif /*(CCU6_T13_PM_INT_EN == 1u) */
#endif /*((CCU6_INP >> 12u) & 3u) == CCU6_SR1) */

#if (((CCU6_INP >> 8u) & 3u) == CCU6_SR1)
#if (CCU6_TRAP_INT_EN == 1u)
  if ((uint16)CCU6->IEN.bit.ENTRPF == (uint16)1u)
  {
    if ((uint16)CCU6->IS.bit.TRPF == (uint16)1u)
    {
      CCU6_TRAP_CALLBACK();
      CCU6_TRAP_Int_Clr();
    }
  }
#endif /*(CCU6_TRAP_INT_EN == 1u) */

#if (CCU6_WHE_INT_EN == 1u)
  if ((uint16)CCU6->IEN.bit.ENWHE == (uint16)1u)
  {
    if ((uint16)CCU6->IS.bit.WHE == (uint16)1u)
    {
      CCU6_WRONG_HALL_CALLBACK();
      CCU6_WHE_Int_Clr();
    }
  }
#endif /*(CCU6_WHE_INT_EN == 1u) */
#endif /*((CCU6_INP >> 8u) & 3u) == CCU6_SR1) */

#if (((CCU6_INP >> 6u) & 3u) == CCU6_SR1)
#if (CCU6_CHE_INT_EN == 1u)
  if ((uint16)CCU6->IEN.bit.ENCHE == (uint16)1u)
  {
    if ((uint16)CCU6->IS.bit.CHE == (uint16)1u)
    {
      CCU6_CORRECT_HALL_CALLBACK();
      CCU6_CHE_Int_Clr();
    }
  }
#endif /*(CCU6_CHE_INT_EN == 1u) */

#if (CCU6_MCM_STR_INT_EN == 1u)
  if ((uint16)CCU6->IEN.bit.ENSTR == (uint16)1u)
  {
    if ((uint16)CCU6->IS.bit.STR == (uint16)1u)
    {
      CCU6_MCM_STR_CALLBACK();
      CCU6_STR_Int_Clr();
    }
  }
#endif /*(CCU6_MCM_STR_INT_EN == 1u) */
#endif /*((CCU6_INP >> 6u) & 3u) == CCU6_SR1) */

  SCU->IRCON4CLR.bit.CCU6SR1C = 1;
}
#endif

/*******************************************************************************
**                      CCU6 SR2 ISR                                          **
*******************************************************************************/
#if ((CPU_NVIC_ISER & (1u << 6u)) != 0u)
void CCU6SR2_IRQHandler(void)
{
#if (((CCU6_INP >> 0u) & 3u) == CCU6_SR2)

#if (CCU6_CH0_CM_R_INT_EN == 1u)
  if (CCU6->IEN.bit.ENCC60R == 1u)
  {
    if ((uint16)CCU6->IS.bit.ICC60R == (uint16)1u)
    {
      CCU6_CH0_CM_R_CALLBACK();
      CCU6_CH0_CM_R_Int_Clr();
    }
  }
#endif /*(CCU6_CH0_CM_R_INT_EN == 1u) */

#if (CCU6_CH0_CM_F_INT_EN == 1u)
  if (CCU6->IEN.bit.ENCC60F == 1u)
  {
    if ((uint16)CCU6->IS.bit.ICC60F == (uint16)1u)
    {
      CCU6_CH0_CM_F_CALLBACK();
      CCU6_CH0_CM_F_Int_Clr();
    }
  }
#endif /*(CCU6_CH0_CM_F_INT_EN == 1u) */
#endif /*((CCU6_INP >> 0u) & 3u) == CCU6_SR2) */

#if (((CCU6_INP >> 2u) & 3u) == CCU6_SR2)
#if (CCU6_CH1_CM_R_INT_EN == 1u)
  if (CCU6->IEN.bit.ENCC61R == 1u)
  {
    if ((uint16)CCU6->IS.bit.ICC61R == (uint16)1u)
    {
      CCU6_CH1_CM_R_CALLBACK();
      CCU6_CH1_CM_R_Int_Clr();
    }
  }
#endif /*(CCU6_CH1_CM_R_INT_EN == 1u) */

#if (CCU6_CH1_CM_F_INT_EN == 1u)
  if (CCU6->IEN.bit.ENCC61F == 1u)
  {
    if ((uint16)CCU6->IS.bit.ICC61F == (uint16)1u)
    {
      CCU6_CH1_CM_F_CALLBACK();
      CCU6_CH1_CM_F_Int_Clr();
    }
  }
#endif /*(CCU6_CH1_CM_F_INT_EN == 1u) */
#endif /*((CCU6_INP >> 2u) & 3u) == CCU6_SR2) */

#if (((CCU6_INP >> 4u) & 3u) == CCU6_SR2)
#if (CCU6_CH2_CM_R_INT_EN == 1u)
  if (CCU6->IEN.bit.ENCC62R == 1u)
  {
    if ((uint16)CCU6->IS.bit.ICC62R == (uint16)1u)
    {
      CCU6_CH2_CM_R_CALLBACK();
      CCU6_CH2_CM_R_Int_Clr();
    }
  }
#endif /*(CCU6_CH2_CM_R_INT_EN == 1u) */

#if (CCU6_CH2_CM_F_INT_EN == 1u)
  if (CCU6->IEN.bit.ENCC62F == 1u)
  {
    if ((uint16)CCU6->IS.bit.ICC62F == (uint16)1u)
    {
      CCU6_CH2_CM_F_CALLBACK();
      CCU6_CH2_CM_F_Int_Clr();
    }
  }
#endif /*(CCU6_CH2_CM_F_INT_EN == 1u) */
#endif /*((CCU6_INP >> 4u) & 3u) == CCU6_SR2) */

#if (((CCU6_INP >> 10u) & 3u) == CCU6_SR2)
#if (CCU6_T12_OM_INT_EN == 1u)
  if ((uint16)CCU6->IEN.bit.ENT12OM == (uint16)1u)
  {
    if ((uint16)CCU6->IS.bit.T12OM == (uint16)1u)
    {
      CCU6_T12_OM_CALLBACK();
      CCU6_T12_OM_Int_Clr();
    }
  }
#endif /*(CCU6_T12_OM_INT_EN == 1u) */

#if (CCU6_T12_PM_INT_EN == 1u)
  if ((uint16)CCU6->IEN.bit.ENT12PM == (uint16)1u)
  {
    if ((uint16)CCU6->IS.bit.T12PM == (uint16)1u)
    {
      CCU6_T12_PM_CALLBACK();
      CCU6_T12_PM_Int_Clr();
    }
  }
#endif /*(CCU6_T12_PM_INT_EN == 1u) */
#endif /*((CCU6_INP >> 10u) & 3u) == CCU6_SR2) */

#if (((CCU6_INP >> 12u) & 3u) == CCU6_SR2)
#if (CCU6_T13_CM_INT_EN == 1u)
  if ((uint16)CCU6->IEN.bit.ENT13CM == (uint16)1u)
  {
    if ((uint16)CCU6->IS.bit.T13CM == (uint16)1u)
    {
      CCU6_T13_CM_CALLBACK();
      CCU6_T13_CM_Int_Clr();
    }
  }
#endif /*(CCU6_T13_CM_INT_EN == 1u) */

#if (CCU6_T13_PM_INT_EN == 1u)
  if ((uint16)CCU6->IEN.bit.ENT13PM == (uint16)1u)
  {
    if ((uint16)CCU6->IS.bit.T13PM == (uint16)1u)
    {
      CCU6_T13_PM_CALLBACK();
      CCU6_T13_PM_Int_Clr();
    }
  }
#endif /*(CCU6_T13_PM_INT_EN == 1u) */
#endif /*((CCU6_INP >> 12u) & 3u) == CCU6_SR2) */

#if (((CCU6_INP >> 8u) & 3u) == CCU6_SR2)
#if (CCU6_TRAP_INT_EN == 1u)
  if ((uint16)CCU6->IEN.bit.ENTRPF == (uint16)1u)
  {
    if ((uint16)CCU6->IS.bit.TRPF == (uint16)1u)
    {
      CCU6_TRAP_CALLBACK();
      CCU6_TRAP_Int_Clr();
    }
  }
#endif /*(CCU6_TRAP_INT_EN == 1u) */

#if (CCU6_WHE_INT_EN == 1u)
  if ((uint16)CCU6->IEN.bit.ENWHE == (uint16)1u)
  {
    if ((uint16)CCU6->IS.bit.WHE == (uint16)1u)
    {
      CCU6_WRONG_HALL_CALLBACK();
      CCU6_WHE_Int_Clr();
    }
  }
#endif /*(CCU6_WHE_INT_EN == 1u) */
#endif /*((CCU6_INP >> 8u) & 3u) == CCU6_SR2) */

#if (((CCU6_INP >> 6u) & 3u) == CCU6_SR2)
#if (CCU6_CHE_INT_EN == 1u)
  if ((uint16)CCU6->IEN.bit.ENCHE == (uint16)1u)
  {
    if ((uint16)CCU6->IS.bit.CHE == (uint16)1u)
    {
      CCU6_CORRECT_HALL_CALLBACK();
      CCU6_CHE_Int_Clr();
    }
  }
#endif /*(CCU6_CHE_INT_EN == 1u) */

#if (CCU6_MCM_STR_INT_EN == 1u)
  if ((uint16)CCU6->IEN.bit.ENSTR == (uint16)1u)
  {
    if ((uint16)CCU6->IS.bit.STR == (uint16)1u)
    {
      CCU6_MCM_STR_CALLBACK();
      CCU6_STR_Int_Clr();
    }
  }
#endif /*(CCU6_MCM_STR_INT_EN == 1u) */
#endif /*((CCU6_INP >> 6u) & 3u) == CCU6_SR2) */

  SCU->IRCON4CLR.bit.CCU6SR2C = 1;
}
#endif

/*******************************************************************************
**                      CCU6 SR3 ISR                                          **
*******************************************************************************/
#if ((CPU_NVIC_ISER & (1u << 7u)) != 0u)
void CCU6SR3_IRQHandler(void)
{
#if (((CCU6_INP >> 0u) & 3u) == CCU6_SR3)

#if (CCU6_CH0_CM_R_INT_EN == 1u)
  if (CCU6->IEN.bit.ENCC60R == 1u)
  {
    if ((uint16)CCU6->IS.bit.ICC60R == (uint16)1u)
    {
      CCU6_CH0_CM_R_CALLBACK();
      CCU6_CH0_CM_R_Int_Clr();
    }
  }
#endif /*(CCU6_CH0_CM_R_INT_EN == 1u) */

#if (CCU6_CH0_CM_F_INT_EN == 1u)
  if (CCU6->IEN.bit.ENCC60F == 1u)
  {
    if ((uint16)CCU6->IS.bit.ICC60F == (uint16)1u)
    {
      CCU6_CH0_CM_F_CALLBACK();
      CCU6_CH0_CM_F_Int_Clr();
    }
  }
#endif /*(CCU6_CH0_CM_F_INT_EN == 1u) */
#endif /*((CCU6_INP >> 0u) & 3u) == CCU6_SR3) */

#if (((CCU6_INP >> 2u) & 3u) == CCU6_SR3)
#if (CCU6_CH1_CM_R_INT_EN == 1u)
  if (CCU6->IEN.bit.ENCC61R == 1u)
  {
    if ((uint16)CCU6->IS.bit.ICC61R == (uint16)1u)
    {
      CCU6_CH1_CM_R_CALLBACK();
      CCU6_CH1_CM_R_Int_Clr();
    }
  }
#endif /*(CCU6_CH1_CM_R_INT_EN == 1u) */

#if (CCU6_CH1_CM_F_INT_EN == 1u)
  if (CCU6->IEN.bit.ENCC61F == 1u)
  {
    if ((uint16)CCU6->IS.bit.ICC61F == (uint16)1u)
    {
      CCU6_CH1_CM_F_CALLBACK();
      CCU6_CH1_CM_F_Int_Clr();
    }
  }
#endif /*(CCU6_CH1_CM_F_INT_EN == 1u) */
#endif /*((CCU6_INP >> 2u) & 3u) == CCU6_SR3) */

#if (((CCU6_INP >> 4u) & 3u) == CCU6_SR3)
#if (CCU6_CH2_CM_R_INT_EN == 1u)
  if (CCU6->IEN.bit.ENCC62R == 1u)
  {
    if ((uint16)CCU6->IS.bit.ICC62R == (uint16)1u)
    {
      CCU6_CH2_CM_R_CALLBACK();
      CCU6_CH2_CM_R_Int_Clr();
    }
  }
#endif /*(CCU6_CH2_CM_R_INT_EN == 1u) */

#if (CCU6_CH2_CM_F_INT_EN == 1u)
  if (CCU6->IEN.bit.ENCC62F == 1u)
  {
    if ((uint16)CCU6->IS.bit.ICC62F == (uint16)1u)
    {
      CCU6_CH2_CM_F_CALLBACK();
      CCU6_CH2_CM_F_Int_Clr();
    }
  }
#endif /*(CCU6_CH2_CM_F_INT_EN == 1u) */
#endif /*((CCU6_INP >> 4u) & 3u) == CCU6_SR3) */

#if (((CCU6_INP >> 10u) & 3u) == CCU6_SR3)
#if (CCU6_T12_OM_INT_EN == 1u)
  if ((uint16)CCU6->IEN.bit.ENT12OM == (uint16)1u)
  {
    if ((uint16)CCU6->IS.bit.T12OM == (uint16)1u)
    {
      CCU6_T12_OM_CALLBACK();
      CCU6_T12_OM_Int_Clr();
    }
  }
#endif /*(CCU6_T12_OM_INT_EN == 1u) */

#if (CCU6_T12_PM_INT_EN == 1u)
  if ((uint16)CCU6->IEN.bit.ENT12PM == (uint16)1u)
  {
    if ((uint16)CCU6->IS.bit.T12PM == (uint16)1u)
    {
      CCU6_T12_PM_CALLBACK();
      CCU6_T12_PM_Int_Clr();
    }
  }
#endif /*(CCU6_T12_PM_INT_EN == 1u) */
#endif /*((CCU6_INP >> 10u) & 3u) == CCU6_SR3) */

#if (((CCU6_INP >> 12u) & 3u) == CCU6_SR3)
#if (CCU6_T13_CM_INT_EN == 1u)
  if ((uint16)CCU6->IEN.bit.ENT13CM == (uint16)1u)
  {
    if ((uint16)CCU6->IS.bit.T13CM == (uint16)1u)
    {
      CCU6_T13_CM_CALLBACK();
      CCU6_T13_CM_Int_Clr();
    }
  }
#endif /*(CCU6_T13_CM_INT_EN == 1u) */

#if (CCU6_T13_PM_INT_EN == 1u)
  if ((uint16)CCU6->IEN.bit.ENT13PM == (uint16)1u)
  {
    if ((uint16)CCU6->IS.bit.T13PM == (uint16)1u)
    {
      CCU6_T13_PM_CALLBACK();
      CCU6_T13_PM_Int_Clr();
    }
  }
#endif /*(CCU6_T13_PM_INT_EN == 1u) */
#endif /*((CCU6_INP >> 12u) & 3u) == CCU6_SR3) */

#if (((CCU6_INP >> 8u) & 3u) == CCU6_SR3)
#if (CCU6_TRAP_INT_EN == 1u)
  if ((uint16)CCU6->IEN.bit.ENTRPF == (uint16)1u)
  {
    if ((uint16)CCU6->IS.bit.TRPF == (uint16)1u)
    {
      CCU6_TRAP_CALLBACK();
      CCU6_TRAP_Int_Clr();
    }
  }
#endif /*(CCU6_TRAP_INT_EN == 1u) */

#if (CCU6_WHE_INT_EN == 1u)
  if ((uint16)CCU6->IEN.bit.ENWHE == (uint16)1u)
  {
    if ((uint16)CCU6->IS.bit.WHE == (uint16)1u)
    {
      CCU6_WRONG_HALL_CALLBACK();
      CCU6_WHE_Int_Clr();
    }
  }
#endif /*(CCU6_WHE_INT_EN == 1u) */
#endif /*((CCU6_INP >> 8u) & 3u) == CCU6_SR3) */

#if (((CCU6_INP >> 6u) & 3u) == CCU6_SR3)
#if (CCU6_CHE_INT_EN == 1u)
  if ((uint16)CCU6->IEN.bit.ENCHE == (uint16)1u)
  {
    if ((uint16)CCU6->IS.bit.CHE == (uint16)1u)
    {
      CCU6_CORRECT_HALL_CALLBACK();
      CCU6_CHE_Int_Clr();
    }
  }
#endif /*(CCU6_CHE_INT_EN == 1u) */

#if (CCU6_MCM_STR_INT_EN == 1u)
  if ((uint16)CCU6->IEN.bit.ENSTR == (uint16)1u)
  {
    if ((uint16)CCU6->IS.bit.STR == (uint16)1u)
    {
      CCU6_MCM_STR_CALLBACK();
      CCU6_STR_Int_Clr();
    }
  }
#endif /*(CCU6_MCM_STR_INT_EN == 1u) */
#endif /*((CCU6_INP >> 6u) & 3u) == CCU6_SR3) */

  SCU->IRCON4CLR.bit.CCU6SR3C = 1;
}
#endif
/*lint +e572 */

/*******************************************************************************
**                      SSC1 ISR                                              **
*******************************************************************************/
#if ((SSC1_RX_INT_EN == 1u) || \
     (SSC1_TX_INT_EN == 1u) || \
     (SSC1_ERR_INT_EN == 1u))
void SSC1_IRQHandler(void)
{
#if (SSC1_RX_INT_EN == 1u)
  /* check for receive interrupt */
  if (SCU->MODIEN1.bit.RIREN1 == 1u)
  {
    if ((uint8)SCU->IRCON2.bit.RIR1 == (uint8)1u)
    {
      SSC1_RX_CALLBACK();
      SSC1_RX_Int_Clr();
    }
  }
#endif /*(SSC1_RX_INT_EN == 1u) */

#if (SSC1_TX_INT_EN == 1u)
  /* check for transmit interrupt */
  if (SCU->MODIEN1.bit.TIREN1 == 1u)
  {
    if ((uint8)SCU->IRCON2.bit.TIR1 == (uint8)1u)
    {
      SSC1_TX_CALLBACK();
      SSC1_TX_Int_Clr();
    }
  }
#endif /*(SSC1_TX_INT_EN == 1u) */

#if (SSC1_ERR_INT_EN == 1u)
  /* check for error interrupt */
  if (SCU->MODIEN1.bit.EIREN1 == 1u)
  {
    if ((uint8)SCU->IRCON2.bit.EIR1 == (uint8)1u)
    {
      SSC1_ERR_CALLBACK();
      SSC1_ERR_Int_Clr();
    }
  }
#endif /*(SSC1_ERR_INT_EN == 1u) */
}
#endif

/*******************************************************************************
**                      SSC2 ISR                                              **
*******************************************************************************/
#if ((SSC2_RX_INT_EN == 1u) || \
     (SSC2_TX_INT_EN == 1u) || \
     (SSC2_ERR_INT_EN == 1u))
void SSC2_IRQHandler(void)
{
#if (SSC2_RX_INT_EN == 1u)
  /* check for receive interrupt */
  if (SCU->MODIEN1.bit.RIREN2 == 1u)
  {
    if ((uint8)SCU->IRCON3.bit.RIR2 == (uint8)1u)
    {
      SSC2_RX_CALLBACK();
      SSC2_RX_Int_Clr();
    }
  }
#endif /*(SSC2_RX_INT_EN == 1u) */

#if (SSC2_TX_INT_EN == 1u)
  /* check for transmit interrupt */
  if (SCU->MODIEN1.bit.TIREN2 == 1u)
  {
    if ((uint8)SCU->IRCON3.bit.TIR2 == (uint8)1u)
    {
      SSC2_TX_CALLBACK();
      SSC2_TX_Int_Clr();
    }
  }
#endif /*(SSC2_TX_INT_EN == 1u) */

#if (SSC2_ERR_INT_EN == 1u)
  /* check for error interrupt */
  if (SCU->MODIEN1.bit.EIREN2 == 1u)
  {
    if ((uint8)SCU->IRCON3.bit.EIR2 == (uint8)1u)
    {
      SSC2_ERR_CALLBACK();
      SSC2_ERR_Int_Clr();
    }
  }
#endif /*(SSC2_ERR_INT_EN == 1u) */
}
#endif

/*******************************************************************************
**                      UART1 ISR                                             **
*******************************************************************************/
#if ((UART1_RX_INT_EN == 1u) || \
     (UART1_TX_INT_EN == 1u) || \
     (TIMER2_EXF2_INT_EN == 1u) || \
     (TIMER2_TF2_INT_EN == 1u) || \
     (LIN_EOF_INT_EN == 1u) || \
     (LIN_ERR_INT_EN == 1u) || \
     (LIN_OC_INT_EN == 1u) || \
     (LIN_OT_INT_EN == 1u) || \
     (LIN_TMOUT_INT_EN == 1u) || \
     (LIN_SMERR_INT_EN == 1u))

void UART1_IRQHandler(void)
{
#if (UART1_RX_INT_EN == 1u)
  if (SCU->MODIEN2.bit.RIEN1 == 1u)
  {
    /* check for receive interrupt */
    if ((uint8)UART1->SCON.bit.RI == (uint8)1u)
    {
      UART1_RX_CALLBACK();
      UART1_RX_Int_Clr();
    }
  }
#endif /*(UART1_RX_INT_EN == 1u) */

#if (UART1_TX_INT_EN == 1u)
  if (SCU->MODIEN2.bit.TIEN1 == 1u)
  {
    /* check for transmit interrupt */
    if ((uint8)UART1->SCON.bit.TI == (uint8)1u)
    {
      UART1_TX_CALLBACK();
      UART1_TX_Int_Clr();
    }
  }
#endif /*(UART1_TX_INT_EN == 1u) */

#if (TIMER2_TF2_INT_EN == 1u)
  if (TIMER2->CON1.bit.TF2EN == 1u)
  {
    if ((uint8)TIMER2->CON.bit.TF2 == (uint8)1u)
    {
      TIMER2_TF2_CALLBACK();
      TIMER2_Overflow_Int_Clr();
    }
  }
#endif /*(TIMER2_TF2_INT_EN == 1u) */

#if (TIMER2_EXF2_INT_EN == 1u)
  if (TIMER2->CON1.bit.EXF2EN == 1u)
  {
    if ((uint8)TIMER2->CON.bit.EXF2 == (uint8)1u)
    {
      TIMER2_EXF2_CALLBACK();
      TIMER2_External_Int_Clr();
    }
  }
#endif /*(TIMER2_EXF2_INT_EN == 1u) */

#if (LIN_OC_INT_EN == 1u)
  if (LIN->IRQEN.bit.OC_IEN == 1u)
  {
    /* LIN Over Current Interrupt */
    if ((uint8)LIN->IRQS.bit.OC_IS == (uint8)1u)
    {
      LIN_OC_CALLBACK();
      LIN_Over_Curr_Int_Clr();
    }
  }
#endif /* (LIN_OC_INT_EN == 1u) */

#if (LIN_OT_INT_EN == 1u)
  if (LIN->IRQEN.bit.OT_IEN == 1u)
  {
    /* LIN Over Temperature Interrupt */
    if ((uint8)LIN->IRQS.bit.OT_IS == (uint8)1u)
    {
      LIN_OT_CALLBACK();
      LIN_Over_Temp_Int_Clr();
    }
  }
#endif /* (LIN_OT_INT_EN == 1u) */
  
#if (LIN_TMOUT_INT_EN == 1u)
  if (LIN->IRQEN.bit.TXD_TMOUT_IEN == 1u)
  {
    /* LIN TxD Timerout Interrupt */
    if ((uint8)LIN->IRQS.bit.TXD_TMOUT_IS == (uint8)1u)
    {
      LIN_TMOUT_CALLBACK();
      LIN_Time_Out_Int_Clr();
    }
  }
#endif /* (LIN_TMOUT_INT_EN == 1u) */
  
#if ((LIN_EOF_INT_EN == 1u) || \
     (LIN_ERR_INT_EN == 1u) )
  if (SCU->LINST.bit.SYNEN == 1u)
  {
#if (LIN_EOF_INT_EN == 1u)
    if ((uint8)SCU->LINST.bit.EOFSYN == (uint8)1u)
    {
      LIN_EOF_CALLBACK();
      LIN_End_Of_Sync_Int_Clr();
    }
#endif /* ((LIN_EOF_INT_EN == 1u) */
#if (LIN_ERR_INT_EN == 1u)
    if ((uint8)SCU->LINST.bit.ERRSYN == (uint8)1u)
    {
      LIN_ERR_CALLBACK();
      LIN_Err_In_Sync_Int_Clr();
    }
#endif /* ((LIN_ERR_INT_EN == 1u) */
  }
#endif /*(LIN_EOF_INT_EN == 1u) || ... */

#if (LIN_SMERR_INT_EN == 1u)
  if (LIN->IRQEN.bit.M_SM_ERR_IEN == 1u)
  {
    /* LIN SM Error Interrupt */
    if ((uint8)LIN->IRQS.bit.M_SM_ERR_IS == (uint8)1u)
    {
      LIN_SMERR_CALLBACK();
      LIN_Slope_Error_Int_Clr();
    }
  }
#endif /* (LIN_SMERR_INT_EN == 1u) */
}
#endif

/*******************************************************************************
**                      UART2 ISR                                             **
*******************************************************************************/
#if ((UART2_RX_INT_EN == 1u) || \
     (UART2_TX_INT_EN == 1u) || \
     (TIMER21_EXF2_INT_EN == 1u) || \
     (TIMER21_TF2_INT_EN == 1u) || \
     (SCU_EXINT2_RISING_INT_EN == 1u) || \
     (SCU_EXINT2_FALLING_INT_EN == 1u) )
void UART2_IRQHandler(void)
{
#if (UART2_RX_INT_EN == 1u)
  if (SCU->MODIEN2.bit.RIEN2 == 1u)
  {
    /* check for receive interrupt */
    if ((uint8)UART2->SCON.bit.RI == (uint8)1u)
    {
      UART2_RX_CALLBACK();
      UART2_RX_Int_Clr();
    }
  }
#endif /*(UART2_RX_INT_EN == 1u) */

#if (UART2_TX_INT_EN == 1u)
  if (SCU->MODIEN2.bit.TIEN2 == 1u)
  {
    /* check for transmit interrupt */
    if ((uint8)UART2->SCON.bit.TI == (uint8)1u)
    {
      UART2_TX_CALLBACK();
      UART2_TX_Int_Clr();
    }
  }
#endif /*(UART2_TX_INT_EN == 1u) */

#if (TIMER21_TF2_INT_EN == 1u)
  if (TIMER21->CON1.bit.TF2EN == 1u)
  {
    if ((uint8)TIMER21->CON.bit.TF2 == (uint8)1u)
    {
      TIMER21_TF2_CALLBACK();
      TIMER21_Overflow_Int_Clr();
    }
  }
#endif /*(TIMER21_TF2_INT_EN == 1u) */

#if (TIMER21_EXF2_INT_EN == 1u)
  if (TIMER21->CON1.bit.EXF2EN == 1u)
  {
    if ((uint8)TIMER21->CON.bit.EXF2 == (uint8)1u)
    {
      TIMER21_EXF2_CALLBACK();
      TIMER21_External_Int_Clr();
    }
  }
#endif /*(TIMER21_TF2_INT_EN == 1u) */

#if ((SCU_MODIEN2 & (1u << 5u)) != 0u)
#if (SCU_EXINT2_FALLING_INT_EN == 1u)
  if ((SCU->EXICON0.reg & (1u << 5u)) != 0u)
  {
    /* External Interrupt 2 - Falling Edge */
    if ((uint8)SCU->IRCON0.bit.EXINT2F == (uint8)1u)
    {
      EXINT2_FALLING_CALLBACK();
      EXINT2_Falling_Edge_Int_Clr();
    }
  }
#endif /* (SCU_EXINT2_FALLING_INT_EN == 1u) */
  
#if (SCU_EXINT2_RISING_INT_EN == 1u)
  if ((SCU->EXICON0.reg & (1u << 4u)) != 0u)
  {
    /* External Interrupt 2 - Rising Edge */
    if ((uint8)SCU->IRCON0.bit.EXINT2R == (uint8)1u)
    {
      EXINT2_RISING_CALLBACK();
      EXINT2_Rising_Edge_Int_Clr();
    }
  }
#endif /* (SCU_EXINT2_RISING_INT_EN == 1u) */
#endif /*((SCU_MODIEN2 & (1u << 5u)) != 0u) */
}
#endif

/*******************************************************************************
**                      EXINT0 ISR                                            **
*******************************************************************************/
#if ((SCU_EXINT0_RISING_INT_EN == 1u) || \
     (SCU_EXINT0_FALLING_INT_EN == 1u))
void EXINT0_IRQHandler(void)
{
#if ((SCU_MODIEN3 & (1u << 0u)) != 0u)
#if (SCU_EXINT0_FALLING_INT_EN == 1u)
  if ((SCU->EXICON0.reg & (1u << 1u)) != 0u)
  {
    /* External Interrupt 0 - Falling Edge */
    if ((uint8)SCU->IRCON0.bit.EXINT0F == (uint8)1u)
    {
      EXINT0_FALLING_CALLBACK();
      EXINT0_Falling_Edge_Int_Clr();
    }
  }
#endif /* (SCU_EXINT0_FALLING_INT_EN == 1u) */

#if (SCU_EXINT0_RISING_INT_EN == 1u)
  if ((SCU->EXICON0.reg & (1u << 0u)) != 0u)
  {
    /* External Interrupt 0 - Rising Edge */
    if ((uint8)SCU->IRCON0.bit.EXINT0R == (uint8)1u)
    {
      EXINT0_RISING_CALLBACK();
      EXINT0_Rising_Edge_Int_Clr();
    }
  }
#endif /* (SCU_EXINT0_RISING_INT_EN == 1u) */
#endif /* ((SCU_MODIEN3 & (1u << 0u)) != 0u) */
}
#endif

/*******************************************************************************
**                      EXINT1 ISR                                           **
*******************************************************************************/
#if ((SCU_EXINT1_RISING_INT_EN == 1u) || \
     (SCU_EXINT1_FALLING_INT_EN == 1u))
void EXINT1_IRQHandler(void)
{
#if ((SCU_MODIEN4 & (1u << 0u)) != 0u)
#if (SCU_EXINT1_FALLING_INT_EN == 1u)
  if ((SCU->EXICON0.reg & (1u << 3u)) != 0u)
  {
    /* External Interrupt 1 - Falling Edge */
    if ((uint8)SCU->IRCON0.bit.EXINT1F == (uint8)1u)
    {
      EXINT1_FALLING_CALLBACK();
      EXINT1_Falling_Edge_Int_Clr();
    }
  }
#endif /* (SCU_EXINT1_FALLING_INT_EN == 1u) */
#if (SCU_EXINT1_RISING_INT_EN == 1u)
  if ((SCU->EXICON0.reg & (1u << 2u)) != 0u)
  {
    /* External Interrupt 1 - Rising Edge */
    if ((uint8)SCU->IRCON0.bit.EXINT1R == (uint8)1u)
    {
      EXINT1_RISING_CALLBACK();
      EXINT1_Rising_Edge_Int_Clr();
    }
  }
#endif /* (SCU_EXINT1_RISING_INT_EN == 1u) */
#endif /*((SCU_MODIEN4 & (1u << 0u)) != 0u) */
}
#endif

/*******************************************************************************
**                      WAKEUP ISR                                            **
*******************************************************************************/
#if (PMU_GPIO_WAKEUP_INT_EN == 1u)
void WAKEUP_IRQHandler(void)
{
#if ((SCU_WAKECON & (1u << 0u)) != 0u)
  static volatile uint32_t wakestatus = 0u;
  static volatile uint32_t gpio_wakestatus = 0u;

  if ((wakestatus & (1u << 0u)) != 0u) 
  {
    PMU_WAKEUP_CALLBACK();
    wakestatus = PMU->WAKE_STATUS.reg;              // ensure that int-status bits are reset by reading this register
    gpio_wakestatus = PMU->GPIO_WAKE_STATUS.reg;    // should work like above, but such behaviour is not documented for this register (to be clarified)
  }
// the following skeleton can be used for later config wizard extensions or be deleted
#if ((PMU_SLEEP & (1u << 2u)) != 0u)
  /* CYCLIC WAKE Interrupt */
#endif /*((PMU_SLEEP & (1u << 2u)) != 0u)*/
#if ((PMU_SLEEP & (1u << 3u)) != 0u)
  /* CYCLIC SENSE Interrupt */
#endif /*((PMU_SLEEP & (1u << 3u)) != 0u)*/
#if ((PMU_LIN_WAKE_EN & (1u << 7u)) != 0u)
  /* LIN WAKE UP Interrupt */
#endif /*((PMU_LIN_WAKE_EN & (1u << 7u)) != 0u)*/
#if ((MON_CNF14 & (1u << 0u)) != 0u)
  /* MON1 WAKE UP Interrupt */
#endif /*((MON_CNF14 & (1u << 0u)) != 0u)*/
#if ((MON_CNF14 & (1u << 8u)) != 0u)
  /* MON2 WAKE UP Interrupt */
#endif /*((MON_CNF14 & (1u << 8u)) != 0u)*/
#if ((MON_CNF14 & (1u << 16u)) != 0u)
  /* MON3 WAKE UP Interrupt */
#endif /*((MON_CNF14 & (1u << 16u)) != 0u)*/
#if ((MON_CNF14 & (1u << 24u)) != 0u)
  /* MON4 WAKE UP Interrupt */
#endif /*((MON_CNF14 & (1u << 24u)) != 0u)*/
#if ((PMU_WAKE_CNF_GPIO0 & (1u << 0u)) != 0u)
  /* PORT0.Pin0 RISING EDGE WAKE UP Interrupt */
#endif /*((PMU_WAKE_CNF_GPIO0 & (1u << 0u)) != 0u)*/
#if ((PMU_WAKE_CNF_GPIO0 & (1u << 8u)) != 0u)
  /* PORT0.Pin0 FALLING EDGE WAKE UP Interrupt */
#endif /*((PMU_WAKE_CNF_GPIO0 & (1u << 8u)) != 0u)*/
#if ((PMU_WAKE_CNF_GPIO0 & (1u << 16u)) != 0u)
  /* PORT0.Pin0 CYCLIC SENSE WAKE UP Interrupt */
#endif /*((PMU_WAKE_CNF_GPIO0 & (1u << 16u)) != 0u)*/
#if ((PMU_WAKE_CNF_GPIO0 & (1u << 1u)) != 0u)
  /* PORT0.Pin1 RISING EDGE WAKE UP Interrupt */
#endif /*((PMU_WAKE_CNF_GPIO0 & (1u << 1u)) != 0u)*/
#if ((PMU_WAKE_CNF_GPIO0 & (1u << 9u)) != 0u)
  /* PORT0.Pin1 FALLING EDGE WAKE UP Interrupt */
#endif /*((PMU_WAKE_CNF_GPIO0 & (1u << 9u)) != 0u)*/
#if ((PMU_WAKE_CNF_GPIO0 & (1u << 17u)) != 0u)
  /* PORT0.Pin1 CYCLIC SENSE WAKE UP Interrupt */
#endif /*((PMU_WAKE_CNF_GPIO0 & (1u << 17u)) != 0u)*/
#if ((PMU_WAKE_CNF_GPIO0 & (1u << 2u)) != 0u)
  /* PORT0.Pin2 RISING EDGE WAKE UP Interrupt */
#endif /*((PMU_WAKE_CNF_GPIO0 & (1u << 2u)) != 0u)*/
#if ((PMU_WAKE_CNF_GPIO0 & (1u << 10u)) != 0u)
  /* PORT0.Pin2 FALLING EDGE WAKE UP Interrupt */
#endif /*((PMU_WAKE_CNF_GPIO0 & (1u << 10u)) != 0u)*/
#if ((PMU_WAKE_CNF_GPIO0 & (1u << 18u)) != 0u)
  /* PORT0.Pin2 CYCLIC SENSE WAKE UP Interrupt */
#endif /*((PMU_WAKE_CNF_GPIO0 & (1u << 18u)) != 0u)*/
#if ((PMU_WAKE_CNF_GPIO0 & (1u << 3u)) != 0u)
  /* PORT0.Pin3 RISING EDGE WAKE UP Interrupt */
#endif /*((PMU_WAKE_CNF_GPIO0 & (1u << 3u)) != 0u)*/
#if ((PMU_WAKE_CNF_GPIO0 & (1u << 11u)) != 0u)
  /* PORT0.Pin3 FALLING EDGE WAKE UP Interrupt */
#endif /*((PMU_WAKE_CNF_GPIO0 & (1u << 11u)) != 0u)*/
#if ((PMU_WAKE_CNF_GPIO0 & (1u << 19u)) != 0u)
  /* PORT0.Pin3 CYCLIC SENSE WAKE UP Interrupt */
#endif /*((PMU_WAKE_CNF_GPIO0 & (1u << 19u)) != 0u)*/
#if ((PMU_WAKE_CNF_GPIO0 & (1u << 4u)) != 0u)
  /* PORT0.Pin4 RISING EDGE WAKE UP Interrupt */
#endif /*((PMU_WAKE_CNF_GPIO0 & (1u << 4u)) != 0u)*/
#if ((PMU_WAKE_CNF_GPIO0 & (1u << 12u)) != 0u)
  /* PORT0.Pin4 FALLING EDGE WAKE UP Interrupt */
#endif /*((PMU_WAKE_CNF_GPIO0 & (1u << 12u)) != 0u)*/
#if ((PMU_WAKE_CNF_GPIO0 & (1u << 20u)) != 0u)
  /* PORT0.Pin4 CYCLIC SENSE WAKE UP Interrupt */
#endif /*((PMU_WAKE_CNF_GPIO0 & (1u << 20u)) != 0u)*/
#if ((PMU_WAKE_CNF_GPIO1 & (1u << 1u)) != 0u)
  /* PORT1.Pin1 RISING EDGE WAKE UP Interrupt */
#endif /*((PMU_WAKE_CNF_GPIO1 & (1u << 1u)) != 0u)*/
#if ((PMU_WAKE_CNF_GPIO1 & (1u << 9u)) != 0u)
  /* PORT1.Pin1 FALLING EDGE WAKE UP Interrupt */
#endif /*((PMU_WAKE_CNF_GPIO1 & (1u << 9u)) != 0u)*/
#if ((PMU_WAKE_CNF_GPIO1 & (1u << 17u)) != 0u)
  /* PORT1.Pin1 CYCLIC SENSE WAKE UP Interrupt */
#endif /*((PMU_WAKE_CNF_GPIO1 & (1u << 17u)) != 0u)*/
#if ((PMU_WAKE_CNF_GPIO1 & (1u << 2u)) != 0u)
  /* PORT1.Pin2 RISING EDGE WAKE UP Interrupt */
#endif /*((PMU_WAKE_CNF_GPIO1 & (1u << 2u)) != 0u)*/
#if ((PMU_WAKE_CNF_GPIO1 & (1u << 10u)) != 0u)
  /* PORT1.Pin2 FALLING EDGE WAKE UP Interrupt */
#endif /*((PMU_WAKE_CNF_GPIO1 & (1u << 10u)) != 0u)*/
#if ((PMU_WAKE_CNF_GPIO1 & (1u << 18u)) != 0u)
  /* PORT1.Pin2 CYCLIC SENSE WAKE UP Interrupt */
#endif /*((PMU_WAKE_CNF_GPIO1 & (1u << 18u)) != 0u)*/
#if ((PMU_WAKE_CNF_GPIO1 & (1u << 3u)) != 0u)
  /* PORT1.Pin3 RISING EDGE WAKE UP Interrupt */
#endif /*((PMU_WAKE_CNF_GPIO1 & (1u << 3u)) != 0u)*/
#if ((PMU_WAKE_CNF_GPIO1 & (1u << 11u)) != 0u)
  /* PORT1.Pin3 FALLING EDGE WAKE UP Interrupt */
#endif /*((PMU_WAKE_CNF_GPIO1 & (1u << 11u)) != 0u)*/
#if ((PMU_WAKE_CNF_GPIO1 & (1u << 19u)) != 0u)
  /* PORT1.Pin3 CYCLIC SENSE WAKE UP Interrupt */
#endif /*((PMU_WAKE_CNF_GPIO1 & (1u << 19u)) != 0u)*/
#if ((PMU_WAKE_CNF_GPIO1 & (1u << 4u)) != 0u)
  /* PORT1.Pin4 RISING EDGE WAKE UP Interrupt */
#endif /*((PMU_WAKE_CNF_GPIO1 & (1u << 4u)) != 0u)*/
#if ((PMU_WAKE_CNF_GPIO1 & (1u << 12u)) != 0u)
  /* PORT1.Pin4 FALLING EDGE WAKE UP Interrupt */
#endif /*((PMU_WAKE_CNF_GPIO1 & (1u << 12u)) != 0u)*/
#if ((PMU_WAKE_CNF_GPIO1 & (1u << 20u)) != 0u)
  /* PORT1.Pin4 CYCLIC SENSE WAKE UP Interrupt */
#endif /*((PMU_WAKE_CNF_GPIO1 & (1u << 20u)) != 0u)*/
// end skeleton
#endif /*((SCU_WAKECON & (1u << 0u)) != 0u)*/
}
#endif /*(PMU_GPIO_WAKEUP_INT_EN) */

/*******************************************************************************
**                      LS1 ISR                                               **
*******************************************************************************/
#if ((LS1_OC_INT_EN == 1u) || \
     (LS1_OL_INT_EN == 1u) || \
     (LS1_OT_INT_EN == 1u))
void LS1_IRQHandler(void)
{
#if (LS1_OC_INT_EN == 1u)
  if (LS->IRQEN.bit.LS1_OC_IEN == 1u)
  {
    /* LS1 Over Current Interrupt */
    if (LS->IRQS.bit.LS1_OC_IS == 1u)
    {
      LS1_OC_CALLBACK();
      LS1_OverCur_Int_Clr();
    }
  }
#endif /*(LS1_OC_INT_EN == 1u) */

#if (LS1_OL_INT_EN == 1u)
  if (LS->IRQEN.bit.LS1_OL_IEN == 1u)
  {
    /* LS1 Open Load Interrupt */
    if (LS->IRQS.bit.LS1_OL_IS == 1u)
    {
      LS1_OL_CALLBACK();
      LS1_OpenLoad_Int_Clr();
    }
  }
#endif /*(LS1_OL_INT_EN == 1u) */

#if (LS1_OT_INT_EN == 1u)
  if (LS->IRQEN.bit.LS1_OT_IEN == 1u)
  {
    /* LS1 Over Temperature Interrupt */
    if (LS->IRQS.bit.LS1_OT_IS == 1u)
    {
      LS1_OT_CALLBACK();
      LS1_OverTemp_Int_Clr();
    }
  }
#endif /*(LS1_OT_INT_EN == 1u) */
}
#endif

/*******************************************************************************
**                      LS2 ISR                                               **
*******************************************************************************/
#if ((LS2_OC_INT_EN == 1u) || \
     (LS2_OL_INT_EN == 1u) || \
     (LS2_OT_INT_EN == 1u))
void LS2_IRQHandler(void)
{
#if (LS2_OC_INT_EN == 1u)
  if (LS->IRQEN.bit.LS2_OC_IEN == 1u)
  {
    /* LS2 Over Current Interrupt */
    if (LS->IRQS.bit.LS2_OC_IS == 1u)
    {
      LS2_OC_CALLBACK();
      LS2_OverCur_Int_Clr();
    }
  }
#endif /*(LS2_OC_INT_EN == 1u) */

#if (LS2_OL_INT_EN == 1u)
  if (LS->IRQEN.bit.LS2_OL_IEN == 1u)
  {
    /* LS2 Open Load Interrupt */
    if (LS->IRQS.bit.LS2_OL_IS == 1u)
    {
      LS2_OL_CALLBACK();
      LS2_OpenLoad_Int_Clr();
    }
  }
#endif /*(LS2_OL_INT_EN == 1u) */

#if (LS2_OT_INT_EN == 1u)
  if (LS->IRQEN.bit.LS2_OT_IEN == 1u)
  {
    /* LS2 Over Temperature Interrupt */
    if (LS->IRQS.bit.LS2_OT_IS == 1u)
    {
      LS2_OT_CALLBACK();
      LS2_OverTemp_Int_Clr();
    }
  }
#endif /*(LS2_OT_INT_EN == 1u) */
}
#endif

/*******************************************************************************
**                      HS1 ISR                                               **
*******************************************************************************/
#if ((HS1_OC_INT_EN == 1u) || \
     (HS1_OL_INT_EN == 1u) || \
     (HS1_OT_INT_EN == 1u))
void HS1_IRQHandler(void)
{
#if (HS1_OC_INT_EN == 1u)
  if (HS->IRQEN.bit.HS1_OC_IEN == 1u)
  {
    /* HS1 Over Current Interrupt */
    if (HS->IRQS.bit.HS1_OC_IS == 1u)
    {
      HS1_OC_CALLBACK();
      HS1_OverCur_Int_Clr();
    }
  }
#endif /*(HS1_OC_INT_EN == 1u) */

#if (HS1_OL_INT_EN == 1u)
  if (HS->IRQEN.bit.HS1_OL_IEN == 1u)
  {
    /* HS1 Over Load Interrupt */
    if (HS->IRQS.bit.HS1_OL_IS == 1u)
    {
      HS1_OL_CALLBACK();
      HS1_OpenLoad_Int_Clr();
    }
  }
#endif /*(HS1_OL_INT_EN == 1u) */

#if (HS1_OT_INT_EN == 1u)
  if (HS->IRQEN.bit.HS1_OT_IEN == 1u)
  {
    /* HS1 Over Temperature Interrupt */
    if (HS->IRQS.bit.HS1_OT_IS == 1u)
    {
      HS1_OT_CALLBACK();
      HS1_OverTemp_Int_Clr();
    }
  }
#endif /*(HS1_OT_INT_EN == 1u) */
}
#endif

/*******************************************************************************
**                      HS2 ISR                                               **
*******************************************************************************/
#if ((HS2_OC_INT_EN == 1u) || \
     (HS2_OL_INT_EN == 1u) || \
     (HS2_OT_INT_EN == 1u))
void HS2_IRQHandler(void)
{
#if (HS2_OC_INT_EN == 1u)
  if (HS->IRQEN.bit.HS2_OC_IEN == 1u)
  {
    /* HS2 Over Current Interrupt */
    if (HS->IRQS.bit.HS2_OC_IS == 1u)
    {
      HS2_OC_CALLBACK();
      HS2_OverCur_Int_Clr();
    }
  }
#endif /*(HS2_OC_INT_EN == 1u) */

#if (HS2_OL_INT_EN == 1u)
  if (HS->IRQEN.bit.HS2_OL_IEN == 1u)
  {
    /* HS2 Over Load Interrupt */
    if (HS->IRQS.bit.HS2_OL_IS == 1u)
    {
      HS2_OL_CALLBACK();
      HS2_OpenLoad_Int_Clr();
    }
  }
#endif /*(HS2_OL_INT_EN == 1u) */

#if (HS2_OT_INT_EN == 1u)
  if (HS->IRQEN.bit.HS2_OT_IEN == 1u)
  {
    /* HS2 Over Temperature Interrupt */
    if (HS->IRQS.bit.HS2_OT_IS == 1u)
    {
      HS2_OT_CALLBACK();
      HS2_OverTemp_Int_Clr();
    }
  }
#endif /*(HS2_OT_INT_EN == 1u) */
}
#endif

/*******************************************************************************
**                      DU ISR (Node 21)                                      **
*******************************************************************************/
#if ((CPU_NVIC_ISER & (1u << 21u)) != 0u)
void DU_IRQHandler(void)
{
#if (ADC1_DCH1_UP_INT_EN == 1u)
  if (ADC1->IRQEN_1.bit.DU1UP_IEN == 1u)
  {
    /* DU1 Interrupt - Upper Threshold */
    if (ADC1->IRQS_1.bit.DU1UP_IS == 1u)
    {
      ADC1_DCH1_UP_CALLBACK();
      ADC1_DU1_Up_Int_Clr();
    }
  }
#endif
#if (ADC1_DCH1_LO_INT_EN == 1u)
  if (ADC1->IRQEN_1.bit.DU1LO_IEN == 1u)
  {
    /* DU1 Interrupt - Lower Threshold */
    if (ADC1->IRQS_1.bit.DU1LO_IS == 1u)
    {
      ADC1_DCH1_LO_CALLBACK();
      ADC1_DU1_Lo_Int_Clr();
    }
  }
#endif
#if (ADC1_DCH2_UP_INT_EN == 1u)
  if (ADC1->IRQEN_1.bit.DU2UP_IEN == 1u)
  {
    /* DU2 Interrupt - Upper Threshold */
    if (ADC1->IRQS_1.bit.DU2UP_IS == 1u)
    {
      ADC1_DCH2_UP_CALLBACK();
      ADC1_DU2_Up_Int_Clr();
    }
  }
#endif
#if (ADC1_DCH2_LO_INT_EN == 1u)
  if (ADC1->IRQEN_1.bit.DU2LO_IEN == 1u)
  {
    /* DU2 Interrupt - Lower Threshold */
    if (ADC1->IRQS_1.bit.DU2LO_IS == 1u)
    {
      ADC1_DCH2_LO_CALLBACK();
      ADC1_DU2_Lo_Int_Clr();
    }
  }
#endif
#if (ADC1_DCH3_UP_INT_EN == 1u)
  if (ADC1->IRQEN_1.bit.DU3UP_IEN == 1u)
  {
    /* DU3 Interrupt - Upper Threshold */
    if (ADC1->IRQS_1.bit.DU3UP_IS == 1u)
    {
      ADC1_DCH3_UP_CALLBACK();
      ADC1_DU3_Up_Int_Clr();
    }
  }
#endif
#if (ADC1_DCH3_LO_INT_EN == 1u)
  if (ADC1->IRQEN_1.bit.DU3LO_IEN == 1u)
  {
    /* DU3 Interrupt - Lower Threshold */
    if (ADC1->IRQS_1.bit.DU3LO_IS == 1u)
    {
      ADC1_DCH3_LO_CALLBACK();
      ADC1_DU3_Lo_Int_Clr();
    }
  }
#endif
#if (ADC1_DCH4_UP_INT_EN == 1u)
  if (ADC1->IRQEN_1.bit.DU4UP_IEN == 1u)
  {
    /* DU4 Interrupt - Upper Threshold */
    if (ADC1->IRQS_1.bit.DU4UP_IS == 1u)
    {
      ADC1_DCH4_UP_CALLBACK();
      ADC1_DU4_Up_Int_Clr();
    }
  }
#endif
#if (ADC1_DCH4_LO_INT_EN == 1u)
  if (ADC1->IRQEN_1.bit.DU4LO_IEN == 1u)
  {
    /* DU4 Interrupt - Lower Threshold */
    if (ADC1->IRQS_1.bit.DU4LO_IS == 1u)
    {
      ADC1_DCH4_LO_CALLBACK();
      ADC1_DU4_Lo_Int_Clr();
    }
  }
#endif
}
#endif

/*******************************************************************************
**                      MON ISR (Node 22)                                     **
*******************************************************************************/
#if ((CPU_NVIC_ISER & (1u << 22u)) != 0u)
void MON_IRQHandler(void)
{
#if ((SCU_MONIEN & (1u << 0u)) != 0u)
#if (MON1_FALLING_INT_EN == 1u)
  if ((SCU->EXICON1.reg & (1u << 1u)) != 0u)
  {
    /* MON1 Pin Interrupt - Falling Edge */
    if (SCU->IRCON1.bit.MON1F == 1u)
    {
      MON1_FALLING_CALLBACK();
      MON1_Falling_Edge_Int_Clr();
    }
  }
#endif /* (MON1_FALLING_INT_EN == 1u) */
#if (MON1_RISING_INT_EN == 1u)
  if ((SCU->EXICON1.reg & (1u << 0u)) != 0u)
  {
    /* MON1 Pin Interrupt - Rising Edge */
    if (SCU->IRCON1.bit.MON1R == 1u)
    {
      MON1_RISING_CALLBACK();
      MON1_Rising_Edge_Int_Clr();
    }
  }
#endif /* (MON1_RISING_INT_EN == 1u) */
#endif /* ((SCU_MONIEN & (1u << 0u)) != 0u) */

#if ((SCU_MONIEN & (1u << 1u)) != 0u)
#if (MON2_FALLING_INT_EN == 1u)
  if ((SCU->EXICON1.reg & (1u << 3u)) != 0u)
  {
    /* MON2 Pin Interrupt - Falling Edge */
    if (SCU->IRCON1.bit.MON2F == 1u)
    {
      MON2_FALLING_CALLBACK();
      MON2_Falling_Edge_Int_Clr();
    }
  }
#endif /* (MON2_FALLING_INT_EN == 1u) */
#if (MON2_RISING_INT_EN == 1u)
  if ((SCU->EXICON1.reg & (1u << 2u)) != 0u)
  {
    /* MON2 Pin Interrupt - Rising Edge */
    if (SCU->IRCON1.bit.MON2R == 1u)
    {
      MON2_RISING_CALLBACK();
      MON2_Rising_Edge_Int_Clr();
    }
  }
#endif /* (MON2_RISING_INT_EN == 1u) */
#endif /* ((SCU_MONIEN & (1u << 1u)) != 0u) */

#if ((SCU_MONIEN & (1u << 2u)) != 0u)
#if (MON3_FALLING_INT_EN == 1u)
  if ((SCU->EXICON1.reg & (1u << 5u)) != 0u)
  {
    /* MON3 Pin Interrupt - Falling Edge */
    if (SCU->IRCON1.bit.MON3F == 1u)
    {
      MON3_FALLING_CALLBACK();
      MON3_Falling_Edge_Int_Clr();
    }
  }
#endif /* (MON3_FALLING_INT_EN == 1u) */
#if (MON3_RISING_INT_EN == 1u)
  if ((SCU->EXICON1.reg & (1u << 4u)) != 0u)
  {
    /* MON3 Pin Interrupt - Rising Edge */
    if (SCU->IRCON1.bit.MON3R == 1u)
    {
      MON3_RISING_CALLBACK();
      MON3_Rising_Edge_Int_Clr();
    }
  }
#endif /* (MON3_RISING_INT_EN == 1u) */
#endif /* ((SCU_MONIEN & (1u << 2u)) != 0u) */

#if ((SCU_MONIEN & (1u << 3u)) != 0u)
#if (MON4_FALLING_INT_EN == 1u)
  if ((SCU->EXICON1.reg & (1u << 7u)) != 0u)
  {
    /* MON4 Pin Interrupt - Falling Edge */
    if (SCU->IRCON1.bit.MON4F == 1u)
    {
      MON4_FALLING_CALLBACK();
      MON4_Falling_Edge_Int_Clr();
    }
  }
#endif /* (MON4_FALLING_INT_EN == 1u) */
#if (MON4_RISING_INT_EN == 1u)
  if ((SCU->EXICON1.reg & (1u << 6u)) != 0u)
  {
    /* MON4 Pin Interrupt - Rising Edge */
    if (SCU->IRCON1.bit.MON4R == 1u)
    {
      MON4_RISING_CALLBACK();
      MON4_Rising_Edge_Int_Clr();
    }
  }
#endif /* (MON4_RISING_INT_EN == 1u) */
#endif /* ((SCU_MONIEN & (1u << 3u)) != 0u) */

#if ((SCU_MONIEN & (1u << 4u)) != 0u)
#if (MON5_FALLING_INT_EN == 1u)
  if ((SCU->EXICON1.reg & (1u << 9u)) != 0u)
  {
    /* MON5 Pin Interrupt - Falling Edge */
    if (SCU->IRCON1.bit.MON5F == 1u)
    {
      MON5_FALLING_CALLBACK();
      MON5_Falling_Edge_Int_Clr();
    }
  }
#endif /* (MON5_FALLING_INT_EN == 1u) */
#if (MON5_RISING_INT_EN == 1u)
  if ((SCU->EXICON1.reg & (1u << 8u)) != 0u)
  {
    /* MON5 Pin Interrupt - Rising Edge */
    if (SCU->IRCON1.bit.MON5R == 1u)
    {
      MON5_RISING_CALLBACK();
      MON5_Rising_Edge_Int_Clr();
    }
  }
#endif /* (MON5_RISING_INT_EN == 1u) */
#endif /* ((SCU_MONIEN & (1u << 4u)) != 0u) */

#if (ADC1_CH2_UP_INT_EN == 1u)
  if (ADC1->IRQEN_2.bit.MON1_UP_IEN == 1u)
  {
    /* CH2/MON1 Interrupt - Upper Threshold */
    if (ADC1->IRQS_2.bit.MON1_UP_IS == 1u)
    {
      ADC1_CH2_UP_CALLBACK();
      ADC1_MON1_Up_Int_Clr(); //ADC1->IRQCLR_2.bit.MON1_UP_ISC = 1u;
    }
  }
#endif
#if (ADC1_CH2_LO_INT_EN == 1u)
  if (ADC1->IRQEN_2.bit.MON1_LO_IEN == 1u)
  {
  /* CH2/MON1 Interrupt - Lower Threshold */
  if (ADC1->IRQS_2.bit.MON1_LO_IS == 1u)
    {
      ADC1_CH2_LO_CALLBACK();
      ADC1_MON1_Lo_Int_Clr(); //ADC1->IRQCLR_2.bit.MON1_LO_ISC = 1u;
    }
  } 
#endif
#if (ADC1_CH3_UP_INT_EN == 1u)
  if (ADC1->IRQEN_2.bit.MON2_UP_IEN == 1u)
  {
    /* CH3/MON2 Interrupt - Upper Threshold */
    if (ADC1->IRQS_2.bit.MON2_UP_IS == 1u)
    {
      ADC1_CH3_UP_CALLBACK();
      ADC1_MON2_Up_Int_Clr(); //ADC1->IRQCLR_2.bit.MON2_UP_ISC = 1u;
    }
  }
#endif
#if (ADC1_CH3_LO_INT_EN == 1u)
  if (ADC1->IRQEN_2.bit.MON2_LO_IEN == 1u)
  {
  /* CH3/MON2 Interrupt - Lower Threshold */
  if (ADC1->IRQS_2.bit.MON2_LO_IS == 1u)
    {
      ADC1_CH3_LO_CALLBACK();
      ADC1_MON2_Lo_Int_Clr(); //ADC1->IRQCLR_2.bit.MON2_LO_ISC = 1u;
    }
  } 
#endif
#if (ADC1_CH4_UP_INT_EN == 1u)
  if (ADC1->IRQEN_2.bit.MON3_UP_IEN == 1u)
  {
    /* CH4/MON3 Interrupt - Upper Threshold */
    if (ADC1->IRQS_2.bit.MON3_UP_IS == 1u)
    {
      ADC1_CH4_UP_CALLBACK();
      ADC1_MON3_Up_Int_Clr(); //ADC1->IRQCLR_2.bit.MON3_UP_ISC = 1u;
    }
  }
#endif
#if (ADC1_CH4_LO_INT_EN == 1u)
  if (ADC1->IRQEN_2.bit.MON3_LO_IEN == 1u)
  {
  /* CH4/MON3 Interrupt - Lower Threshold */
  if (ADC1->IRQS_2.bit.MON3_LO_IS == 1u)
    {
      ADC1_CH4_LO_CALLBACK();
      ADC1_MON3_Lo_Int_Clr(); //ADC1->IRQCLR_2.bit.MON3_LO_ISC = 1u;
    }
  } 
#endif
#if (ADC1_CH5_UP_INT_EN == 1u)
  if (ADC1->IRQEN_2.bit.MON4_UP_IEN == 1u)
  {
    /* CH5/MON4 Interrupt - Upper Threshold */
    if (ADC1->IRQS_2.bit.MON4_UP_IS == 1u)
    {
      ADC1_CH5_UP_CALLBACK();
      ADC1_MON4_Up_Int_Clr(); //ADC1->IRQCLR_2.bit.MON4_UP_ISC = 1u;
    }
  }
#endif
#if (ADC1_CH5_LO_INT_EN == 1u)
  if (ADC1->IRQEN_2.bit.MON4_LO_IEN == 1u)
  {
  /* CH5/MON4 Interrupt - Lower Threshold */
  if (ADC1->IRQS_2.bit.MON4_LO_IS == 1u)
    {
      ADC1_CH5_LO_CALLBACK();
      ADC1_MON4_Lo_Int_Clr(); //ADC1->IRQCLR_2.bit.MON4_LO_ISC = 1u;
    }
  } 
#endif
#if (ADC1_CH6_UP_INT_EN == 1u)
  if (ADC1->IRQEN_2.bit.MON5_UP_IEN == 1u)
  {
    /* CH6/MON5 Interrupt - Upper Threshold */
    if (ADC1->IRQS_2.bit.MON5_UP_IS == 1u)
    {
      ADC1_CH6_UP_CALLBACK();
      ADC1_MON5_Up_Int_Clr();
    }
  }
#endif
#if (ADC1_CH6_LO_INT_EN == 1u)
  if (ADC1->IRQEN_2.bit.MON5_LO_IEN == 1u)
  {
  /* CH6/MON5 Interrupt - Lower Threshold */
  if (ADC1->IRQS_2.bit.MON5_LO_IS == 1u)
    {
      ADC1_CH6_LO_CALLBACK();
      ADC1_MON5_Lo_Int_Clr();
    }
  } 
#endif
}
#endif

/*******************************************************************************
**                      PORT ISR (Node 23)                                    **
*******************************************************************************/
#if ((CPU_NVIC_ISER & (1u << 23u)) != 0u)
void PORT_IRQHandler(void)
{
#if (ADC1_CH7_UP_INT_EN == 1u)
  if (ADC1->IRQEN_2.bit.P2_1_UP_IEN == 1u)
  {
    /* CH7/P2.1 Interrupt - Upper Threshold */
    if (ADC1->IRQS_2.bit.P2_1_UP_IS == 1u)
    {
      ADC1_CH7_UP_CALLBACK();
      ADC1_P21_Up_Int_Clr(); //ADC1->IRQCLR_2.bit.P2_1_UP_ISC = 1u;
    }
  }
#endif
#if (ADC1_CH7_LO_INT_EN == 1u)
  if (ADC1->IRQEN_2.bit.P2_1_LO_IEN == 1u)
  {
  /* CH7/P2.1 Interrupt - Lower Threshold */
  if (ADC1->IRQS_2.bit.P2_1_LO_IS == 1u)
    {
      ADC1_CH7_LO_CALLBACK();
      ADC1_P21_Lo_Int_Clr(); //ADC1->IRQCLR_2.bit.P2_1_LO_ISC = 1u;
    }
  } 
#endif

#if (ADC1_CH8_UP_INT_EN == 1u)
  if (ADC1->IRQEN_2.bit.P2_2_UP_IEN == 1u)
  {
    /* CH8/P2.2 Interrupt - Upper Threshold */
    if (ADC1->IRQS_2.bit.P2_2_UP_IS == 1u)
    {
      ADC1_CH8_UP_CALLBACK();
      ADC1_P22_Up_Int_Clr(); //ADC1->IRQCLR_2.bit.P2_2_UP_ISC = 1u;
    }
  }
#endif
#if (ADC1_CH8_LO_INT_EN == 1u)
  if (ADC1->IRQEN_2.bit.P2_2_LO_IEN == 1u)
  {
  /* CH8/P2.2 Interrupt - Lower Threshold */
  if (ADC1->IRQS_2.bit.P2_2_LO_IS == 1u)
    {
      ADC1_CH8_LO_CALLBACK();
      ADC1_P22_Lo_Int_Clr(); //ADC1->IRQCLR_2.bit.P2_2_LO_ISC = 1u;
    }
  } 
#endif

#if (ADC1_CH9_UP_INT_EN == 1u)
  if (ADC1->IRQEN_2.bit.P2_3_UP_IEN == 1u)
  {
    /* CH9/P2.3 Interrupt - Upper Threshold */
    if (ADC1->IRQS_2.bit.P2_3_UP_IS == 1u)
    {
      ADC1_CH9_UP_CALLBACK();
      ADC1_P23_Up_Int_Clr(); //ADC1->IRQCLR_2.bit.P2_3_UP_ISC = 1u;
    }
  }
#endif
#if (ADC1_CH9_LO_INT_EN == 1u)
  if (ADC1->IRQEN_2.bit.P2_3_LO_IEN == 1u)
  {
  /* CH9/P2.3 Interrupt - Lower Threshold */
  if (ADC1->IRQS_2.bit.P2_3_LO_IS == 1u)
    {
      ADC1_CH9_LO_CALLBACK();
      ADC1_P23_Lo_Int_Clr(); //ADC1->IRQCLR_2.bit.P2_3_LO_ISC = 1u;
    }
  } 
#endif

#if (ADC1_CH10_UP_INT_EN == 1u)
  if (ADC1->IRQEN_2.bit.P2_6_UP_IEN == 1u)
  {
    /* CH10/P2.6 Interrupt - Upper Threshold */
    if (ADC1->IRQS_2.bit.P2_6_UP_IS == 1u)
    {
      ADC1_CH10_UP_CALLBACK();
      ADC1_P26_Up_Int_Clr(); //ADC1->IRQCLR_2.bit.P2_6_UP_ISC = 1u;
    }
  }
#endif
#if (ADC1_CH10_LO_INT_EN == 1u)
  if (ADC1->IRQEN_2.bit.P2_6_LO_IEN == 1u)
  {
  /* CH10/P2.6 Interrupt - Lower Threshold */
  if (ADC1->IRQS_2.bit.P2_6_LO_IS == 1u)
    {
      ADC1_CH10_LO_CALLBACK();
      ADC1_P26_Lo_Int_Clr(); //ADC1->IRQCLR_2.bit.P2_6_LO_ISC = 1u;
    }
  } 
#endif

#if (ADC1_CH11_UP_INT_EN == 1u)
  if (ADC1->IRQEN_2.bit.P2_7_UP_IEN == 1u)
  {
    /* CH11/P2.7 Interrupt - Upper Threshold */
    if (ADC1->IRQS_2.bit.P2_7_UP_IS == 1u)
    {
      ADC1_CH11_UP_CALLBACK();
      ADC1_P27_Up_Int_Clr(); //ADC1->IRQCLR_2.bit.P2_7_UP_ISC = 1u;
    }
  }
#endif
#if (ADC1_CH11_LO_INT_EN == 1u)
  if (ADC1->IRQEN_2.bit.P2_7_LO_IEN == 1u)
  {
  /* CH11/P2.7 Interrupt - Lower Threshold */
  if (ADC1->IRQS_2.bit.P2_7_LO_IS == 1u)
    {
      ADC1_CH11_LO_CALLBACK();
      ADC1_P27_Lo_Int_Clr(); //ADC1->IRQCLR_2.bit.P2_7_LO_ISC = 1u;
    }
  } 
#endif
}
#endif

/*******************************************************************************
**                      NMI ISR                                               **
*******************************************************************************/
#if ((SCU_NMI_PLL_INT_EN == 1u) || \
     (SCU_NMI_NVM_INT_EN == 1u) || \
     (SCU_NMI_OWD_INT_EN == 1u) || \
     (SCU_NMI_MAP_INT_EN == 1u) || \
     (ADC2_SYS_TEMP_UP_INT_EN == 1u) || \
     (ADC2_SYS_TEMP_LO_INT_EN == 1u) || \
     (SCU_ECC_RAM_DB_INT_EN == 1u) || \
     (SCU_ECC_NVM_DB_INT_EN == 1u) || \
     (ADC1_CH0_UP_INT_EN == 1u) || \
     (ADC1_CH0_LO_INT_EN == 1u) || \
     (ADC2_VS_UP_INT_EN == 1u) || \
     (ADC2_VS_LO_INT_EN == 1u) || \
     (ADC2_VDDP_UP_INT_EN == 1u) || \
     (ADC2_VDDP_LO_INT_EN == 1u) || \
     (ADC2_VDDC_UP_INT_EN == 1u) || \
     (ADC2_VDDC_LO_INT_EN == 1u) || \
     (ADC2_VDDEXT_UP_INT_EN == 1u) || \
     (ADC2_VDDEXT_LO_INT_EN == 1u) || \
     (PMU_VDDP_OV_INT_EN == 1u) || \
     (PMU_VDDP_OL_INT_EN == 1u) || \
     (PMU_VDDC_OV_INT_EN == 1u) || \
     (PMU_VDDC_OL_INT_EN == 1u) || \
     (PMU_VDDEXT_UV_INT_EN == 1u) || \
     (PMU_VDDEXT_OT_INT_EN == 1u))
void NMI_Handler(void)
{
/* WDT not implemented in TLE984x
#if (SCU_NMI_WDT_INT_EN == 1u)
  if (SCU->NMICON.bit.NMIWDT == 1u)
  {
    if ((uint8)SCU->NMISR.bit.FNMIWDT == (uint8)1u)
    {
      SCU_NMI_WDT_CALLBACK();
      NMI_WDT_Int_Clr();
    }
  }
#endif
*/
#if (SCU_NMI_PLL_INT_EN == 1u)
  if (SCU->NMICON.bit.NMIPLL == 1u)
  {
    if ((uint8)SCU->NMISR.bit.FNMIPLL == (uint8)1u)
    {
      SCU_NMI_PLL_CALLBACK();
      NMI_PLL_Int_Clr();
    }
  }
#endif /*(SCU_NMI_PLL_INT_EN == 1u)*/

#if (SCU_NMI_NVM_INT_EN == 1u)
  if (SCU->NMICON.bit.NMINVM == 1u)
  {
    if ((uint8)SCU->NMISR.bit.FNMINVM == (uint8)1u)
    {
      SCU_NMI_NVM_CALLBACK();
      NMI_NVM_Int_Clr();
    }
  }
#endif /*(SCU_NMI_NVM_INT_EN == 1u)*/

#if ((ADC2_SYS_TEMP_UP_INT_EN == 1u) || \
     (ADC2_SYS_TEMP_LO_INT_EN == 1u) )
  if ((uint8)SCU->NMICON.bit.NMIOT == (uint8)1u)
  {
    if ((uint8)SCU->NMISR.bit.FNMIOT == (uint8)1u)
    {
      NMI_OT_Int_Clr();

#if (ADC2_SYS_TEMP_LO_INT_EN == 1u)
      if (SCUPM->SYS_IRQ_CTRL.bit.SYS_OTWARN_IE == 1u)
      {
        if (SCUPM->SYS_IS.bit.SYS_OTWARN_IS == 1u)
        {
          ADC2_SYS_TEMP_LO_CALLBACK();
          ADC2_TEMP1_WARN_Int_Clr();
        }
      }
#endif /*(ADC2_SYS_TEMP_LO_INT_EN == 1u) */

#if (ADC2_SYS_TEMP_UP_INT_EN == 1u)
      if (SCUPM->SYS_IRQ_CTRL.bit.SYS_OT_IE == 1u)
      {
        if (SCUPM->SYS_IS.bit.SYS_OT_IS == 1u)
        {
          ADC2_SYS_TEMP_UP_CALLBACK();
          ADC2_TEMP1_OT_Int_Clr();
        }
      }
#endif /*(ADC2_SYS_TEMP_UP_INT_EN == 1u)*/
    }
  }
#endif /*(ADC2_SYS_TEMP_UP_INT_EN == 1u) || ...*/

#if (SCU_NMI_OWD_INT_EN == 1u)
  if (SCU->NMICON.bit.NMIOWD == 1u)
  {
    if ((uint8)SCU->NMISR.bit.FNMIOWD == (uint8)1u)
    {
      SCU_NMI_OWD_CALLBACK();
      NMI_OWD_Int_Clr();
    }
  }
#endif /*(SCU_NMI_OWD_INT_EN == 1u)*/

#if (SCU_NMI_MAP_INT_EN == 1u)
  if (SCU->NMICON.bit.NMIMAP == 1u)
  {
    if ((uint8)SCU->NMISR.bit.FNMIMAP == (uint8)1u)
    {
      SCU_NMI_MAP_CALLBACK();
      NMI_MAP_Int_Clr();
    }
  }
#endif /*(SCU_NMI_MAP_INT_EN == 1u)*/

#if ((SCU_ECC_RAM_DB_INT_EN == 1u) || \
     (SCU_ECC_NVM_DB_INT_EN == 1u))
  if ((uint8)SCU->NMICON.bit.NMIECC == (uint8)1u)
  {
    if ((uint8)SCU->NMISR.bit.FNMIECC == (uint8)1u)
    {
      NMI_ECC_Int_Clr();

#if (SCU_ECC_RAM_DB_INT_EN == 1u)
      if (SCU->EDCCON.bit.RIE == 1u)
      {
        if ((uint8)SCU->EDCSTAT.bit.RDBE == (uint8)1u)
        {
          SCU_ECC_RAM_DB_CALLBACK();
          ECC_RAM_DoubleBit_Int_Clr();
        }
      }
#endif /*((SCU_EDCCON & (1u << 0u)) != 0u) */

#if (SCU_ECC_NVM_DB_INT_EN == 1u)
      if (SCU->EDCCON.bit.NVMIE == 1u)
      {
        if ((uint8)SCU->EDCSTAT.bit.NVMDBE == (uint8)1u)
        {
          SCU_ECC_NVM_DB_CALLBACK();
          ECC_NVM_DoubleBit_Int_Clr();
        }
      }
#endif /*(SCU_ECC_NVM_DB_INT_EN == 1u)*/
    }
  }
#endif /*(SCU_ECC_RAM_DB_INT_EN == 1u) || ... */

#if ((ADC1_CH0_UP_INT_EN == 1u) || \
     (ADC1_CH0_LO_INT_EN == 1u) || \
     (ADC2_VS_UP_INT_EN == 1u) || \
     (ADC2_VS_LO_INT_EN == 1u) || \
     (ADC2_VDDP_UP_INT_EN == 1u) || \
     (ADC2_VDDP_LO_INT_EN == 1u) || \
     (ADC2_VDDC_UP_INT_EN == 1u) || \
     (ADC2_VDDC_LO_INT_EN == 1u) || \
     (ADC2_VDDEXT_UP_INT_EN == 1u) || \
     (ADC2_VDDEXT_LO_INT_EN == 1u) || \
     (PMU_VDDP_OV_INT_EN == 1u) || \
     (PMU_VDDP_OL_INT_EN == 1u) || \
     (PMU_VDDC_OV_INT_EN == 1u) || \
     (PMU_VDDC_OL_INT_EN == 1u) || \
     (PMU_VDDEXT_UV_INT_EN == 1u) || \
     (PMU_VDDEXT_OT_INT_EN == 1u))
  if ((uint8)SCU->NMICON.bit.NMISUP == (uint8)1u)
  {
    if ((uint8)SCU->NMISR.bit.FNMISUP == (uint8)1u)
    {
      NMI_SUP_Int_Clr();
#if (ADC1_CH0_UP_INT_EN == 1u)
      if (SCUPM->SYS_SUPPLY_IRQ_CTRL.bit.VBAT_OV_IE == 1u)
      {
        if (SCUPM->SYS_SUPPLY_IRQ_STS.bit.VBAT_OV_IS == 1u)
        {
          ADC1_CH0_UP_CALLBACK();
          ADC1_VBAT_OV_Int_Clr();
        }
      }
#endif

#if (ADC1_CH0_LO_INT_EN == 1u)
      if (SCUPM->SYS_SUPPLY_IRQ_CTRL.bit.VBAT_UV_IE == 1u)
      {
        if (SCUPM->SYS_SUPPLY_IRQ_STS.bit.VBAT_UV_IS == 1u)
        {
          ADC1_CH0_LO_CALLBACK();
          ADC1_VBAT_UV_Int_Clr();
        }
      }
#endif

#if (ADC2_VS_UP_INT_EN == 1u)
      if (SCUPM->SYS_SUPPLY_IRQ_CTRL.bit.VS_OV_IE == 1u)
      {
        if (SCUPM->SYS_SUPPLY_IRQ_STS.bit.VS_OV_IS == 1u)
        {
          ADC2_VS_UP_CALLBACK();
          ADC2_VS_OV_Int_Clr();
        }
      }
#endif

#if (ADC2_VS_LO_INT_EN == 1u)
      if (SCUPM->SYS_SUPPLY_IRQ_CTRL.bit.VS_UV_IE == 1u)
      {
        if (SCUPM->SYS_SUPPLY_IRQ_STS.bit.VS_UV_IS == 1u)
        {
          ADC2_VS_LO_CALLBACK();
          ADC2_VS_UV_Int_Clr();
        }
      }
#endif /*((SCU_SYS_SUPPLY_IRQ_CTRL & (1u << 1u)) != 0u) */
      
#if (ADC2_VDDP_UP_INT_EN == 1u)
      if (SCUPM->SYS_SUPPLY_IRQ_CTRL.bit.VDD5V_OV_IE == 1u)
      {
        if (SCUPM->SYS_SUPPLY_IRQ_STS.bit.VDD5V_OV_IS == 1u)
        {
          ADC2_VDDP_UP_CALLBACK();
          ADC2_VDDP_OV_Int_Clr();
        }
      }
#endif /*((SCU_SYS_SUPPLY_IRQ_CTRL & (1u << 6u)) != 0u) */

#if (ADC2_VDDP_LO_INT_EN == 1u)
      if (SCUPM->SYS_SUPPLY_IRQ_CTRL.bit.VDD5V_UV_IE == 1u)
      {
        if (SCUPM->SYS_SUPPLY_IRQ_STS.bit.VDD5V_UV_IS == 1u)
        {
          ADC2_VDDP_LO_CALLBACK();
          ADC2_VDDP_UV_Int_Clr();
        }
      }
#endif /*((SCU_SYS_SUPPLY_IRQ_CTRL & (1u << 2u)) != 0u) */

#if (ADC2_VDDC_UP_INT_EN == 1u)
      if (SCUPM->SYS_SUPPLY_IRQ_CTRL.bit.VDD1V5_OV_IE == 1u)
      {
        if (SCUPM->SYS_SUPPLY_IRQ_STS.bit.VDD1V5_OV_IS == 1u)
        {
          ADC2_VDDC_UP_CALLBACK();
          ADC2_VDDC_OV_Int_Clr();
        }
      }
#endif /*((SCU_SYS_SUPPLY_IRQ_CTRL & (1u << 7u)) != 0u) */

#if (ADC2_VDDC_LO_INT_EN == 1u)
      if (SCUPM->SYS_SUPPLY_IRQ_CTRL.bit.VDD1V5_UV_IE == 1u)
      {
        if (SCUPM->SYS_SUPPLY_IRQ_STS.bit.VDD1V5_UV_IS == 1u)
        {
          ADC2_VDDC_LO_CALLBACK();
          ADC2_VDDC_UV_Int_Clr();
        }
      }
#endif /*((SCU_SYS_SUPPLY_IRQ_CTRL & (1u << 3u)) != 0u) */

#if (ADC2_VDDEXT_UP_INT_EN == 1u)
      if (SCUPM->SYS_SUPPLY_IRQ_CTRL.bit.VDDEXT_OV_IE == 1u)
      {
        if (SCUPM->SYS_SUPPLY_IRQ_STS.bit.VDDEXT_OV_IS == 1u)
        {
          ADC2_VDDEXT_UP_CALLBACK();
          ADC2_VDDEXT_OV_Int_Clr();
        }
      }
#endif

#if (ADC2_VDDEXT_LO_INT_EN == 1u)
      if (SCUPM->SYS_SUPPLY_IRQ_CTRL.bit.VDDEXT_UV_IE == 1u)
      {
        if (SCUPM->SYS_SUPPLY_IRQ_STS.bit.VDDEXT_UV_IS == 1u)
        {
          ADC2_VDDEXT_LO_CALLBACK();
          ADC2_VDDEXT_UV_Int_Clr();
        }
      }
#endif

#if ((PMU_VDDC_OV_INT_EN == 1u) || \
     (PMU_VDDC_OL_INT_EN == 1u))
      if (PMU->SUPPLY_STS.bit.PMU_1V5_FAIL_EN == 1u)
      {
      #if (PMU_VDDC_OV_INT_EN == 1u)
        if ((uint8)PMU->SUPPLY_STS.bit.PMU_1V5_OVERVOLT == (uint8)1u)
        {
          PMU_VDDC_OV_CALLBACK();
        }
      #endif
      #if (PMU_VDDC_OL_INT_EN == 1u)
        if ((uint8)PMU->SUPPLY_STS.bit.PMU_1V5_OVERLOAD == (uint8)1u)
        {
          PMU_VDDC_OL_CALLBACK();
        }
      #endif
      }
#endif /*((PMU_PMU_SUPPLY_STS & (1u << 0u)) != 0u) */

#if ((PMU_VDDP_OV_INT_EN == 1u) || \
     (PMU_VDDP_OL_INT_EN == 1u))
      if (PMU->SUPPLY_STS.bit.PMU_5V_FAIL_EN == 1u)
      {
      #if (PMU_VDDP_OV_INT_EN == 1u)
        if ((uint8)PMU->SUPPLY_STS.bit.PMU_5V_OVERVOLT == (uint8)1u)
        {
          PMU_VDDP_OV_CALLBACK();
        }
      #endif
      #if (PMU_VDDP_OL_INT_EN == 1u)
        if ((uint8)PMU->SUPPLY_STS.bit.PMU_5V_OVERLOAD == (uint8)1u)
        {
          PMU_VDDP_OL_CALLBACK();
        }
      #endif
      }
#endif /*((PMU_PMU_SUPPLY_STS & (1u << 6u)) != 0u) */

#if ((PMU_VDDEXT_UV_INT_EN == 1u) || \
     (PMU_VDDEXT_OT_INT_EN == 1u) )
      if (PMU->VDDEXT_CTRL.bit.VDDEXT_FAIL_EN == 1u)
      {
        #if (PMU_VDDEXT_UV_INT_EN == 1u)
          /* Supply VDDEXT Undervoltage NMI Enable */
          if (PMU->VDDEXT_CTRL.bit.VDDEXT_UV_IS == 1u)
          {
            PMU_VDDEXT_UV_CALLBACK();
            PMU_VDDEXT_UV_Int_Clr(); // PMU->VDDEXT_CTRL.bit.VDDEXT_UV_ISC = (uint8)1u;
          }
        #endif
        #if (PMU_VDDEXT_OT_INT_EN == 1u)
          /* Supply VDDEXT Over-Temperature NMI Enable */ 
          if (PMU->VDDEXT_CTRL.bit.VDDEXT_OT_IS == 1u)
          {
            PMU_VDDEXT_OT_CALLBACK();
            PMU_VDDEXT_OT_Int_Clr(); // PMU->VDDEXT_CTRL.bit.VDDEXT_OT_ISC = (uint8)1u;
          }
        #endif
      }
#endif /*(PMU_VDDEXT_UV_INT_EN == 1u) ||...*/
    }
  }
#endif
}
#endif

/*******************************************************************************
**                      HardFault ISR                                         **
*******************************************************************************/
void HardFault_Handler(void)
{
#if (CPU_HARDFAULT_EN == 1)
  CPU_HARDFAULT_CALLBACK();
#endif /*(CPU_HARDFAULT_EN == u)*/
}

/*******************************************************************************
**                      SysTick ISR                                           **
*******************************************************************************/
void SysTick_Handler(void)
{
#if (CPU_SYSTICK_EN == 1)
  CPU_SYSTICK_CALLBACK();
#endif /*(CPU_SYSTICK_EN == 1)*/

  WDT1_Window_Count();
}
#endif /* INT_XML_VERSION < 10106) */

