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
/* See interrupt.c */

#ifndef ADC2_H
#define ADC2_H

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "TLE984x.h"
#include "types.h"

/*******************************************************************************
**                      Global Constant Declarations                          **
*******************************************************************************/
#define ADC2_RESULT_VS          ((uint16)0)        /* Channel 0 - VS */
#define ADC2_RESULT_VDDEXT      ((uint16)1)        /* Channel 1 - VDDEXT */
#define ADC2_RESULT_VDDP        ((uint16)2)        /* Channel 2 - VDDP */
#define ADC2_RESULT_VBG         ((uint16)3)        /* Channel 3 - VBG */
#define ADC2_RESULT_VDDC        ((uint16)4)        /* Channel 4 - VDDC */
#define ADC2_RESULT_TEMP1       ((uint16)5)        /* Channel 5 - TEMP1 */
#define ADC2_RESULT_TEMP2       ((uint16)6)        /* Channel 6 - TEMP2 */

/* ADC2 Interrupt Clear Macros */
#define ADC2_VS_OV_Int_Clr()         (SCUPM->SYS_SUPPLY_IRQ_CLR.reg = (uint32)1u << 6u)
#define ADC2_VS_UV_Int_Clr()         (SCUPM->SYS_SUPPLY_IRQ_CLR.reg = (uint32)1u << 1u)
#define ADC2_VDDEXT_OV_Int_Clr()     (SCUPM->SYS_SUPPLY_IRQ_CLR.reg = (uint32)1u << 9u)
#define ADC2_VDDEXT_UV_Int_Clr()     (SCUPM->SYS_SUPPLY_IRQ_CLR.reg = (uint32)1u << 4u)
#define ADC2_VDDP_OV_Int_Clr()       (SCUPM->SYS_SUPPLY_IRQ_CLR.reg = (uint32)1u << 7u)
#define ADC2_VDDP_UV_Int_Clr()       (SCUPM->SYS_SUPPLY_IRQ_CLR.reg = (uint32)1u << 2u)
#define ADC2_VBG_OV_Int_Clr()        (SCUPM->SYS_ISCLR.reg = (uint32)1u << 11u)
#define ADC2_VBG_UV_Int_Clr()        (SCUPM->SYS_ISCLR.reg = (uint32)1u << 10u)
#define ADC2_VDDC_OV_Int_Clr()       (SCUPM->SYS_SUPPLY_IRQ_CLR.reg = (uint32)1u << 8u)
#define ADC2_VDDC_UV_Int_Clr()       (SCUPM->SYS_SUPPLY_IRQ_CLR.reg = (uint32)1u << 3u)
#define ADC2_TEMP1_OT_Int_Clr()       (SCUPM->SYS_ISCLR.reg = (uint32)1u << 9u)
#define ADC2_TEMP1_WARN_Int_Clr()     (SCUPM->SYS_ISCLR.reg = (uint32)1u << 8u)

/*******************************************************************************
**                      Global Function Declarations                          **
*******************************************************************************/
void ADC2_Init(void);
uint16 ADC2_GetChResult(uint8 channel);
sint16 ADC2_GetChResult_mVC(uint8 channel);

/*******************************************************************************
**                      Global Inline Function Definitions                    **
*******************************************************************************/

#endif







