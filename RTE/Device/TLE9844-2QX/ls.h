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
**                      Revision Control History                              **
*******************************************************************************/
/* See ls.c */

#ifndef LS_H
#define LS_H

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/*******************************************************************************
**                      Global Type Definitions                               **
*******************************************************************************/
typedef enum _LS_Sw_Int
{
  Int_Ls1_Ints    = 17U,  /**< \brief LS1 interrupts global enable            */
  Int_Ls1_Oc      = 7U,   /**< \brief LS1 Over-Current interrupt enable       */
  Int_Ls1_Ol      = 6U,   /**< \brief LS1 Over-Load interrupt enable          */
  Int_Ls1_Ot      = 5U,   /**< \brief LS1 Over-Temperature interrupt en.      */
  Int_Ls1_Ot_Prew = 4U,   /**< \brief LS1 Over-Temperature Prewarn int.en.    */

  Int_Ls2_Ints    = 18U,  /**< \brief LS2 interrupts global enable            */
  Int_Ls2_Oc      = 23U,  /**< \brief LS2 Over-Current interrupt enable       */
  Int_Ls2_Ol      = 22U,  /**< \brief LS2 Over-Load interrupt enable          */ 
  Int_Ls2_Ot      = 21U,  /**< \brief LS2 Over-Temperature interrupt en.      */
  Int_Ls2_Ot_Prew = 20U,  /**< \brief LS2 Over-Temperature Prewarn int.en.    */  
} LS_Sw_Int;

#define LS_IRQ_BITS 0x00F000F0


/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/
/* Lowside Switch Macro */

/* Register LS_CTRL: Low-Side Driver Control */
#define LS1_En()          (LS->CTRL.reg |= (uint32)  (1u << 0u))
#define LS1_Dis()         (LS->CTRL.reg &= (uint32) ~(1u << 0u))
#define LS1_PWM_En()      (LS->CTRL.reg |= (uint32)  (1u << 1u))
#define LS1_PWM_Dis()     (LS->CTRL.reg &= (uint32) ~(1u << 1u)) 
#define LS1_On()          (LS->CTRL.reg |= (uint32)  (1u << 2u))
#define LS1_Off()         (LS->CTRL.reg &= (uint32) ~(1u << 2u))
#define LS1_OL_En()       (LS->CTRL.reg |= (uint32)  (1u << 3u)) 
#define LS1_OL_Dis()      (LS->CTRL.reg &= (uint32) ~(1u << 3u)) 
#define LS1_SR_Fast_Set() (LS->CTRL.reg |= (uint32)  (1u << 8u)) 
#define LS1_SR_Slow_Set() (LS->CTRL.reg &= (uint32) ~(1u << 8u)) 
#define LS2_En()          (LS->CTRL.reg |= (uint32)  (1u << 16u))
#define LS2_Dis()         (LS->CTRL.reg &= (uint32) ~(1u << 16u))
#define LS2_PWM_En()      (LS->CTRL.reg |= (uint32)  (1u << 17u))
#define LS2_PWM_Dis()     (LS->CTRL.reg &= (uint32) ~(1u << 17u))
#define LS2_On()          (LS->CTRL.reg |= (uint32)  (1u << 18u))
#define LS2_Off()         (LS->CTRL.reg &= (uint32) ~(1u << 18u))
#define LS2_OL_En()       (LS->CTRL.reg |= (uint32)  (1u << 19u)) 
#define LS2_OL_Dis()      (LS->CTRL.reg &= (uint32) ~(1u << 19u))  
#define LS2_SR_Fast_Set() (LS->CTRL.reg |= (uint32)  (1u << 24u)) 
#define LS2_SR_Slow_Set() (LS->CTRL.reg &= (uint32) ~(1u << 24u)) 

/* Register LS_IRQS: Low-Side Driver Interrupt Status Macros */
#define LS2_OpenLoad_Sts()             ((LS->IRQS.reg >> 30u) & 1u)
#define LS2_OverTemp_Sts()             ((LS->IRQS.reg >> 29u) & 1u)
#define LS2_OverTemp_Prewarn_Sts()     ((LS->IRQS.reg >> 28u) & 1u)
#define LS2_OverCur_Int_Sts()          ((LS->IRQS.reg >> 23u) & 1u)
#define LS2_OpenLoad_Int_Sts()         ((LS->IRQS.reg >> 22u) & 1u)
#define LS2_OverTemp_Int_Sts()         ((LS->IRQS.reg >> 21u) & 1u)
#define LS2_OverTemp_Prewarn_Int_Sts() ((LS->IRQS.reg >> 20u) & 1u)
#define LS1_OpenLoad_Sts()             ((LS->IRQS.reg >> 14u) & 1u)
#define LS1_OverTemp_Sts()             ((LS->IRQS.reg >> 13u) & 1u)
#define LS1_OverTemp_Prewarn_Sts()     ((LS->IRQS.reg >> 12u) & 1u)
#define LS1_OverCur_Int_Sts()          ((LS->IRQS.reg >>  7u) & 1u)
#define LS1_OpenLoad_Int_Sts()         ((LS->IRQS.reg >>  6u) & 1u)
#define LS1_OverTemp_Int_Sts()         ((LS->IRQS.reg >>  5u) & 1u)
#define LS1_OverTemp_Prewarn_Int_Sts() ((LS->IRQS.reg >>  4u) & 1u)

/* Register LS_IRQCLR: Low-Side Interrupt Status Clear Macros */
#define LS2_OpenLoad_Sts_Clr()         ((LS->IRQCLR.reg >> 30u) & 1u)
#define LS2_OverTemp_Sts_Clr()         ((LS->IRQCLR.reg >> 29u) & 1u)
#define LS2_OverTemp_Prewarn_Sts_Clr() ((LS->IRQCLR.reg >> 28u) & 1u)
#define LS2_OverCur_Int_Clr()          ((LS->IRQCLR.reg >> 23u) & 1u)
#define LS2_OpenLoad_Int_Clr()         ((LS->IRQCLR.reg >> 22u) & 1u)
#define LS2_OverTemp_Int_Clr()         ((LS->IRQCLR.reg >> 21u) & 1u)
#define LS2_OverTemp_Prewarn_Int_Clr() ((LS->IRQCLR.reg >> 20u) & 1u)
#define LS1_OpenLoad_Sts_Clr()         ((LS->IRQCLR.reg >> 14u) & 1u)
#define LS1_OverTemp_Sts_Clr()         ((LS->IRQCLR.reg >> 13u) & 1u)
#define LS1_OverTemp_Prewarn_Sts_Clr() ((LS->IRQCLR.reg >> 12u) & 1u)
#define LS1_OverCur_Int_Clr()          ((LS->IRQCLR.reg >>  7u) & 1u)
#define LS1_OpenLoad_Int_Clr()         ((LS->IRQCLR.reg >>  6u) & 1u)
#define LS1_OverTemp_Int_Clr()         ((LS->IRQCLR.reg >>  5u) & 1u)
#define LS1_OverTemp_Prewarn_Int_Clr() ((LS->IRQCLR.reg >>  4u) & 1u)

/* Register LS_IRQEN: Low-Side Interrupt Enable Macros */
#define LS2_OverCur_Int_En()           (LS->IRQEN.reg |= (1<<23u))
#define LS2_OpenLoad_Int_En()          (LS->IRQEN.reg |= (1<<22u))
#define LS2_OverTemp_Int_En()          (LS->IRQEN.reg |= (1<<21u))
#define LS2_OverTemp_Prewarn_Int_En()  (LS->IRQEN.reg |= (1<<20u))
#define LS1_OverCur_Int_En()           (LS->IRQEN.reg |= (1<<7u))
#define LS1_OpenLoad_Int_En()          (LS->IRQEN.reg |= (1<<6u))
#define LS1_OverTemp_Int_En()          (LS->IRQEN.reg |= (1<<5u))
#define LS1_OverTemp_Prewarn_Int_En()  (LS->IRQEN.reg |= (1<<4u))

/* Register LS_PWMSRCSEL: Low-Side PWM Selection Macros */
#define LS_PWM_CC60   0u
#define LS_PWM_CC61   1u
#define LS_PWM_CC62   2u
#define LS_PWM_COUT60 3u
#define LS_PWM_COUT61 4u
#define LS_PWM_COUT62 5u
#define LS_PWM_T3OUT  6u

#define LS1_PWM_Src_Sel(ls_pwm) (LS->PWMSRCSEL.bit.LS1_SRC_SEL = (ls_pwm & 7u))
#define LS2_PWM_Src_Sel(ls_pwm) (LS->PWMSRCSEL.bit.LS2_SRC_SEL = (ls_pwm & 7u))

/* Register LS_LS1_TRIM Low Side Trimming Register */
#define LS_Filt_4us  0u
#define LS_Filt_8us  1u
#define LS_Filt_16us 2u
#define LS_Filt_32us 3u

#define LS1_OverCur_Filt_time(ls_filt)     (LS->LS1_TRIM.bit.LS1_OC_BTFILT_SEL = (ls_filt & 3u))
#define LS1_OpenLoad_Filt_time(ls_filt)    (LS->LS1_TRIM.bit.LS1_OL_BTFILT_SEL = (ls_filt & 3u))
#define LS2_OverCur_Filt_time(ls_filt)     (LS->LS2_TRIM.bit.LS2_OC_BTFILT_SEL = (ls_filt & 3u))
#define LS2_OpenLoad_Filt_time(ls_filt)    (LS->LS2_TRIM.bit.LS2_OL_BTFILT_SEL = (ls_filt & 3u))


/*******************************************************************************
**                      Global Function Declarations                          **
*******************************************************************************/
void LS1_Init(void);
void LS2_Init(void);

/*******************************************************************************
**                      Global Inline Function Definitions                    **
*******************************************************************************/



#endif
