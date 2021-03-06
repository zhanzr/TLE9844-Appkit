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
** KC           Kay Claussen                                                  **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/*
 * V0.1.0: 2017-10-19, KC:   initial version
 */

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "tle_device.h"

/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
/** \brief Initializes the TLE modules.
 *
 * \param None
 * \return None
 *
 * \ingroup tle_api
 */
void TLE_Init(void)
{
#ifdef RTE_DEVICE_SDK_SCU
  SCU_Init();
#endif
#ifdef RTE_DEVICE_SDK_PMU
  PMU_Init();
#endif
#ifdef RTE_DEVICE_SDK_ADC1
  ADC1_Init();
#endif
#ifdef RTE_DEVICE_SDK_ADC2
  ADC2_Init();
#endif
#ifdef RTE_DEVICE_SDK_CCU6
  CCU6_Init();
#endif
#ifdef RTE_DEVICE_SDK_GPT12E
  GPT12E_Init();
#endif
#ifdef RTE_DEVICE_SDK_LIN
  LIN_Init();
#endif
#ifdef RTE_DEVICE_SDK_HS
  HS1_Init();
#if (UC_FEAT_HS > 1u)
  HS2_Init();
#endif
#endif
#ifdef RTE_DEVICE_SDK_LS
  LS1_Init();
  LS2_Init();
#endif
#ifdef RTE_DEVICE_SDK_MON
  MONx_Init();
#endif
#ifdef RTE_DEVICE_SDK_PORT
  PORT_Init();
#endif
#ifdef RTE_DEVICE_SDK_SSC
  SSC1_Init();
  SSC2_Init();
#endif
#ifdef RTE_DEVICE_SDK_TIMER2X
  TIMER2_Init();
  TIMER21_Init();
#endif
#ifdef RTE_DEVICE_SDK_UART
  UART1_Init();
  UART2_Init();
#endif
#ifdef RTE_DEVICE_SDK_INT
  INT_Init();
#endif
}
