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
**                      Author(s) Identity                                    **
********************************************************************************
**                                                                            **
** Initials     Name                                                          **
** ---------------------------------------------------------------------------**
** DM           Daniel Mysliwitz                                              **
** TA           Thomas Albersinger                                            **
** AV           Axel Viebig                                                   **
** KC           Kay Claussen                                                  **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
 /* 
 * V0.1.0: 2015-09-30, AV:   Initial version
 * V0.1.1: 2015-11-21, AV:   Added SCUPM_SYS_IS to initialization
 * V0.1.4: 2017-10-20, KC:   Macros for interrupt register access added
 */

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "int.h"
#include "int_defines.h"
#include "scu_defines.h"

/*******************************************************************************
**                      External CallBacks                                    **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
/** \brief Initializes the Interrupt module.
 *
 * \param None
 * \return None
 *
 * \ingroup drv_api
 */
void INT_Init(void)
{
  /***************************************************************************
   ** Interrupt Control                                                     **
   **************************************************************************/
  SCU->NMISRCLR.reg = (uint32) SCU_NMICON;
  SCU->NMICON.reg = (uint32) SCU_NMICON;
  SCU->EXICON0.reg = (uint32) SCU_EXICON0;
  SCU->EXICON1.reg = (uint32) SCU_EXICON1;
  SCU->MODIEN1.reg = (uint32) SCU_MODIEN1;
  SCU->MODIEN2.reg = (uint32) SCU_MODIEN2;
  SCU->MODIEN3.reg = (uint32) SCU_MODIEN3;
  SCU->MODIEN4.reg = (uint32) SCU_MODIEN4;
  SCU->GPT12IEN.reg = (uint32) SCU_GPT12IEN;
  SCUPM->SYS_ISCLR.reg = (uint32) 0x03000F00;
  SCUPM->SYS_IRQ_CTRL.reg = SCUPM_SYS_IRQ_CTRL;
  SCUPM->SYS_SUPPLY_IRQ_CLR.reg = (uint32) 0x03FF03FF;
  SCUPM->SYS_SUPPLY_IRQ_CTRL.reg = (uint32) SCUPM_SYS_SUPPLY_IRQ_CTRL;
  SCU->EDCCON.reg = (uint32) SCU_EDCCON;
  CPU->NVIC_IPR0.reg = (uint32) CPU_NVIC_IPR0;
  CPU->NVIC_IPR1.reg = (uint32) CPU_NVIC_IPR1;
  CPU->NVIC_IPR2.reg = (uint32) CPU_NVIC_IPR2;
  CPU->NVIC_IPR3.reg = (uint32) CPU_NVIC_IPR3;
  CPU->NVIC_IPR4.reg = (uint32) CPU_NVIC_IPR4;
  CPU->NVIC_IPR5.reg = (uint32) CPU_NVIC_IPR5; 
  CPU->NVIC_ISER.reg = (uint32) CPU_NVIC_ISER;
  SCU->IEN0.reg = (uint32) SCU_IEN0;
}
