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
** AV           Axel Viebig                                                   **
** DM           Daniel Mysliwitz                                              **
** MK           Martin Kilian                                                 **
** KC           Kay Claussen                                                  **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/* 
 * V0.1.0: 2015-10-23, AV:   Initial version
 * V0.1.1: 2015-11-11, AV:   Added methods for LS module 
 * V0.1.2: 2016-06-28, DM:   LSx_Set_Switch corrected
 * V0.1.3: 2017-04-05, MK:   Added Define Macros for LS Registers in LS.h
 * V0.1.4: 2017-10-20, KC:   Macros with _ISts_ renamed to _Int_
                             Macros corrected to right IRQCLR register
 */

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "ls.h"
#include "TLE984x.h"
#include "ls_defines.h"

/*******************************************************************************
**                      External CallBacks                                    **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/

/** \brief Initializes the LS1 module.
 *
 * \param None
 * \return None
 *
 * \ingroup drv_api
 */
void LS1_Init(void)
{
#if ((LS_CTRL & (1u << 0u)) != 0u)
  LS->LS1_TRIM.reg = LS_LS1_TRIM;
  LS->IRQEN.reg = ((LS->IRQEN.reg & 0xFFFF0000)|(LS_IRQEN & 0x0000FFFF));
  LS->PWMSRCSEL.reg = ((LS->PWMSRCSEL.reg & 0x0000FFC7)|(LS_PWMSRCSEL & 0x00000038));
  LS->CTRL.reg = ((LS->CTRL.reg & 0xFFFF0000)|(LS_CTRL & 0x0000FFFF));
#endif
}

/** \brief Initializes the LS2 module.
 *
 * \param None
 * \return None
 *
 * \ingroup drv_api
 */
void LS2_Init(void)
{
#if ((LS_CTRL & (1u << 16u)) != 0u)
  LS->LS2_TRIM.reg = LS_LS2_TRIM;
  LS->IRQEN.reg = ((LS->IRQEN.reg & 0x0000FFFF)|(LS_IRQEN & 0xFFFF0000));
  LS->PWMSRCSEL.reg = ((LS->PWMSRCSEL.reg & 0x0000FFF8)|(LS_PWMSRCSEL & 0x00000007));
  LS->CTRL.reg = ((LS->CTRL.reg & 0x0000FFFF)|(LS_CTRL & 0xFFFF0000));
#endif
}

