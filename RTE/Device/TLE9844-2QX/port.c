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
** SS           Steffen Storandt                                              **
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
 * V0.1.0: 2015-09-30, AV:   Initial version, ported from V0.5.1 (Proteus SDK)
 * V0.1.1: 2015-11-09, AV:   Method names: Port->PORT
 * V0.1.2: 2015-11-25, AV:   Corrected memory addressing in 3 inline functions
 * V0.6.0: 2017-06-19, KC:   Port prefix changed to capital letters
 *                           API extended: Macros added
 */
 
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "port.h"
#include "port_defines.h"

/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
/** \brief Initializes the ports.
 *
 * \param None
 * \return None
 *
 * \ingroup PORT_api
 */
void PORT_Init(void)
{
  /* Initialize all ports */
  uint8 Value;

  /* Port 0 */
  PORT->P0_DIR.reg = (uint8) PORT_P0_DIR;
  PORT->P0_OD.reg = (uint8) PORT_P0_OD;

  Value  = (uint8) ((PORT_P0_0_PUD & 0x02u) >> 1u);
  Value |= (uint8) ((PORT_P0_1_PUD & 0x02u));
  Value |= (uint8) ((PORT_P0_2_PUD & 0x02u) << 1u);
  Value |= (uint8) ((PORT_P0_3_PUD & 0x02u) << 2u);
  Value |= (uint8) ((PORT_P0_4_PUD & 0x02u) << 3u);
  Value |= (uint8) ((PORT_P0_5_PUD & 0x02u) << 4u);
  PORT->P0_PUDEN.reg = Value;

  Value  = (uint8) ((PORT_P0_0_PUD & 0x01u));
  Value |= (uint8) ((PORT_P0_1_PUD & 0x01u) << 1u);
  Value |= (uint8) ((PORT_P0_2_PUD & 0x01u) << 2u);
  Value |= (uint8) ((PORT_P0_3_PUD & 0x01u) << 3u);
  Value |= (uint8) ((PORT_P0_4_PUD & 0x01u) << 4u);
  Value |= (uint8) ((PORT_P0_5_PUD & 0x01u) << 5u);
  PORT->P0_PUDSEL.reg = Value;

  Value  = (uint8) ((PORT_P0_0_ALT & 0x01u));
  Value |= (uint8) ((PORT_P0_1_ALT & 0x01u) << 1u);
  Value |= (uint8) ((PORT_P0_2_ALT & 0x01u) << 2u);
  Value |= (uint8) ((PORT_P0_3_ALT & 0x01u) << 3u);
  Value |= (uint8) ((PORT_P0_4_ALT & 0x01u) << 4u);
  Value |= (uint8) ((PORT_P0_5_ALT & 0x01u) << 5u);
  PORT->P0_ALTSEL0.reg = Value;

  Value  = (uint8) ((PORT_P0_0_ALT & 0x02u) >> 1u);
  Value |= (uint8) ((PORT_P0_1_ALT & 0x02u));
  Value |= (uint8) ((PORT_P0_2_ALT & 0x02u) << 1u);
  Value |= (uint8) ((PORT_P0_3_ALT & 0x02u) << 2u);
  Value |= (uint8) ((PORT_P0_4_ALT & 0x02u) << 3u);
  Value |= (uint8) ((PORT_P0_5_ALT & 0x02u) << 4u);
  PORT->P0_ALTSEL1.reg = Value;
  PORT->P0_DATA.reg = (uint8) PORT_P0_DATA;

  /* Port 1 */
  PORT->P1_DIR.reg = (uint8) PORT_P1_DIR;
  PORT->P1_OD.reg = (uint8) PORT_P1_OD;

  Value  = (uint8) ((PORT_P1_0_PUD & 0x02u) >> 1u);
  Value |= (uint8) ((PORT_P1_1_PUD & 0x02u));
  Value |= (uint8) ((PORT_P1_2_PUD & 0x02u) << 1u);
  Value |= (uint8) ((PORT_P1_4_PUD & 0x02u) << 3u);
  PORT->P1_PUDEN.reg = Value;

  Value  = (uint8) ((PORT_P1_0_PUD & 0x01u));
  Value |= (uint8) ((PORT_P1_1_PUD & 0x01u) << 1u);
  Value |= (uint8) ((PORT_P1_2_PUD & 0x01u) << 2u);
  Value |= (uint8) ((PORT_P1_4_PUD & 0x01u) << 4u);
  PORT->P1_PUDSEL.reg = Value;

  Value  = (uint8) ((PORT_P1_0_ALT & 0x01u));
  Value |= (uint8) ((PORT_P1_1_ALT & 0x01u) << 1u);
  Value |= (uint8) ((PORT_P1_2_ALT & 0x01u) << 2u);
  Value |= (uint8) ((PORT_P1_4_ALT & 0x01u) << 4u);
  PORT->P1_ALTSEL0.reg = Value;

  Value  = (uint8) ((PORT_P1_0_ALT & 0x02u) >> 1u);
  Value |= (uint8) ((PORT_P1_1_ALT & 0x02u));
  Value |= (uint8) ((PORT_P1_2_ALT & 0x02u) << 1u);
  Value |= (uint8) ((PORT_P1_4_ALT & 0x02u) << 3u);
  PORT->P1_ALTSEL1.reg = Value;
  PORT->P1_DATA.reg = (uint8) PORT_P1_DATA;

  /* Port 2 */
  PORT->P2_DIR.reg = (uint8) PORT_P2_DIR;

  Value  = (uint8) ((PORT_P2_0_PUD & 0x02u) >> 1u);
  Value |= (uint8) ((PORT_P2_1_PUD & 0x02u));
  Value |= (uint8) ((PORT_P2_2_PUD & 0x02u) << 1u);
  Value |= (uint8) ((PORT_P2_3_PUD & 0x02u) << 2u);
  Value |= (uint8) ((PORT_P2_4_PUD & 0x02u) << 3u);
  Value |= (uint8) ((PORT_P2_5_PUD & 0x02u) << 4u);
  Value |= (uint8) ((PORT_P2_6_PUD & 0x02u) << 5u);
  Value |= (uint8) ((PORT_P2_7_PUD & 0x02u) << 6u);
  PORT->P2_PUDEN.reg = Value;

  Value  = (uint8) ((PORT_P2_0_PUD & 0x01u));
  Value |= (uint8) ((PORT_P2_1_PUD & 0x01u) << 1u);
  Value |= (uint8) ((PORT_P2_2_PUD & 0x01u) << 2u);
  Value |= (uint8) ((PORT_P2_3_PUD & 0x01u) << 3u);
  Value |= (uint8) ((PORT_P2_4_PUD & 0x01u) << 4u);
  Value |= (uint8) ((PORT_P2_5_PUD & 0x01u) << 5u);
  Value |= (uint8) ((PORT_P2_5_PUD & 0x01u) << 6u);
  Value |= (uint8) ((PORT_P2_7_PUD & 0x01u) << 7u);
  PORT->P2_PUDSEL.reg = Value;
}
