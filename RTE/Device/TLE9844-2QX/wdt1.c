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
 * V0.1.0: 2015-09-30, AV:   Initial version, ported from Proteus SDK
 * V0.1.1: 2015-11-18, AV:   Added function Delay_ms
 * V0.1.2: 2016-05-03, DM:   function Delay_ms removed
 * V0.1.3: 2017-06-19, KC:   macros One_us and SysTickRL are moved to wdt.h
 *                           Delay_us() function updated
 * V0.2.5: 2017-10-20, KV:   Version number changed to be consistent with pdsc
 */

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "wdt1.h"
#include "scu_defines.h"

/*******************************************************************************
**                      Private Constant Declarations                         **
*******************************************************************************/

/*******************************************************************************
**                      Private Variable Declarations                         **
*******************************************************************************/
uint32 WD_Counter;
static bool bSOWactive;

/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
/** \brief Initializes the WDT1.
 *
 * \param None
 * \return None
 *
 * \ingroup wdt1_api
 */
void WDT1_Init(void)
{
  uint32 ui;
  /* calc SysTick reload based on SystemFrequency */
  ui = (uint32)SCU_FSYS / SysTickFreq;
  /* program SysTick Timer */
  CPU->SYSTICK_RVR.reg = ui;
  /* reset SysTick timer, write is necessary to start */
  CPU->SYSTICK_CVR.reg = 0u;
  /* CLKSRC=CPU clk */ 
  CPU->SYSTICK_CSR.bit.CLKSOURCE = 1;
  /* TICK Interrupt = enabled */
  CPU->SYSTICK_CSR.bit.TICKINT = 1u;
  /* ENABLE SysTick Timer */
  CPU->SYSTICK_CSR.bit.ENABLE = 1u;
  /* trigger inital WDT1 service */
  SCUPM->WDT1_TRIG.reg = SCUPM_WDT1_TRIG;
  /* reset window counter */
  WD_Counter = 0u;
  /* reset SOW active signal */
  bSOWactive = false;
}

/** \brief Stops the WDT1 (SysTick Counter).
 *
 * \param None
 * \return None
 *
 * \ingroup wdt1_api
 */
void WDT1_Stop(void)
{
  /* DISABLE SysTick Timer */
  CPU->SYSTICK_CSR.bit.ENABLE = 0u;
}

/** \brief Triggers the WDT1 in the open window.
 *
 * \param None
 * \return 0 = WDT1 not serviced, 1 = WDT1 serviced
 *
 * \ingroup wdt1_api
 */
int WDT1_Service(void)
{
  int result;
  result = 0;
  /* check if Window Counter is beyond 70% of WDT1 period  *
   * or if a SOW service has been done before              */

/*lint -e9050 Supressing MISRA 2012 Rule 12.1 */
  if ((WD_Counter > SCUPM_WDT1_TRIGGER) || (bSOWactive == true))
/*lint +e9050 */
  {
    /* service WDT1 */
    SCUPM->WDT1_TRIG.reg = (uint8) SCUPM_WDT1_TRIG;
    /* reset window counter */
    WD_Counter = 0u;
    /* reset "short open window" active flag */
    bSOWactive = false;

    result = 1;
  }
  return (result);
}

/** \brief triggers a short-window.
 *
 * \param NoOfSOW, number of SOWs
 * \return None
 *
 * \ingroup wdt1_api
 */
void WDT1_SOW_Service(uint32 NoOfSOW)
{
  SCUPM->WDT1_TRIG.reg = (NoOfSOW & 3u) << 6u;
  bSOWactive = true;
}

/** \brief Delays the regular program execution by a given number of Microseconds
 * \brief the function returns if the given time has elapsed
 * \brief smaller Microsecond delay times are getting falsen by the execution time
 * \brief of the function itself
 * \param Delay time in Microseconds (max. < 1000us)
 * \return None
 *
 * \ingroup wdt1_api
 */
void Delay_us(uint32 delay_time_us)
{
  uint16 delay_val;
  uint16 delay_count = delay_time_us * One_us;

  /* get current systick value */
  uint16 systick_val = SysTick->VAL;

  if( systick_val >= delay_count)
    {
    delay_val = systick_val - delay_count;
    /* wait underflow with 1 countdown detection */
    while((SysTick->VAL > delay_val) && (SysTick->VAL < systick_val));
    }
  else
  {
    delay_val = SysTick->LOAD - ( delay_count - systick_val ) ;
    /* wait for underflow */
    while(SysTick->VAL < systick_val);
    /* wait target underflowed */
    while( SysTick->VAL > delay_val );
  }
}
