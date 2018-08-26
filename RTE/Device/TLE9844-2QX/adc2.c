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
 * V0.1.0: 2015-10-23  AV: initial version
 * V0.1.1: 2015-11-18  AV: Removed unnecessary registers from init routine 
 * V0.1.4: 2017-10-20  KC: Macros for interrupt register access added 
 * V0.1.5: 2017-11-10  KC: Calcualtions of ADC2_GetChResult_mVC() corrected
 *                         Return type of ADC2_GetChResult_mVC() changed to sint16
 *                         ADC2_GetChResult() converted to non-inline function 
 * V0.1.6: 2017-12-21  KC: Calcualtions of ADC2_GetChResult_mVC() improved
 */
  
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "adc2.h"
#include "adc2_defines.h"

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
void ADC2_Init(void)
{
#if ((ADC2_CTRL2 & 1u) != 0u)
  ADC2->CTRL2.reg = (uint32) ADC2_CTRL2;
  ADC2->CTRL4.reg = (uint32) ADC2_CTRL4;
  ADC2->TH0_3_LOWER.reg = (uint32) ADC2_TH0_3_LOWER;
  ADC2->TH0_3_UPPER.reg = (uint32) ADC2_TH0_3_UPPER;
  ADC2->TH4_7_LOWER.reg = (uint32) ADC2_TH4_7_LOWER;
#endif
}


/** \brief Get ADC2 Channel result value.
 *
 * \param[in] channel-channel number(defined in adc2.h)
 * \param[out] n/a
 * \return native ADC2 result value
 *
 * \ingroup adc2_api
 */
uint16 ADC2_GetChResult(uint8 channel)
{
  volatile uint32 *pBaseAddr;
  volatile uint16 var;
  
  pBaseAddr = (uint32*)(&(ADC2->FILT_OUT0.reg) + (uint32) (channel));
  var = ((*pBaseAddr) & 0x000003FF);
  return (var);
} /* End of ADC2_GetChResult */


/** \brief Get ADC2 Channels 0-4 result in mV and channels 5-6 in °C
 *
 * \param[in] uint8 channel number
 * \return sint16 ADC result values in mV or °C
 *
 * \ingroup adc2_api
 */
sint16 ADC2_GetChResult_mVC(uint8 channel)
{
  uint16 var;
  uint32 fs;
  
  var = ADC2_GetChResult(channel);
  if (channel==0)
  {
    /* 1.211 * 1000 / 0.039 / 1024 * 1024 */
    fs=31051;                  /* ch0 in mV */
  }
  else if (channel<3) 
  {
    /* 1.211 * 1000 / 0.203 */
    fs=5966;                   /* ch1+2 in mV */
  }
  else if (channel<5) 
  {
    /* 1.211 * 1000 / 0.75 */
    fs=1615;                   /* ch3+4 in mV */
  }
  else if (channel<7)
  {
    /* Calculate temperature in °C = (var*131-69662) / 256 */
    return ((sint16)(((sint32)(131) * var - 69662)>>8)); /* ch5+6 in °C */
  }
  else
  {
    return 0;                  /* invalid channel */
  }
  /* Calculate mV = var * fs / 1024 */
  if (var > 0)
    return ((sint16)(((var * fs) - (fs>>1))>>10u)) /* calculate voltage in mV */; 
  else
    return (0) /* calculate voltage in mV */; 

}
