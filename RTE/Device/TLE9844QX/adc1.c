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
** TL           Ted Lee                                                       **
** AV           Axel Viebig                                                   **
** MK           Martin Kilian                                                 **
** KC           Kay Claussen                                                  **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
 /* 
 * V0.1.0: 2015-10-23, AV:   Initial version
 * V0.1.1: 2015-11-03, AV:   Several changes for DU mode
 * V0.1.2: 2015-11-11, AV:   Range corrections in INLINE functions (adc1.h)
 *                           DU mode changes due to reorganized configwizard XML
 *                           Introduced waiting for acknowledge on mode change 
 * V0.1.3: 2015-11-18, AV:   Improved init routine to allow for clean startup
 *                             without having a bunch of irrelevant interrupts 
 * V0.1.4: 2017-04-20, MK:   Added define macros for registers access
 * V0.1.5: 2017-11-10, KC:   Six inline fuctions converted to non-inline
 *                           Calculation in mV functions corrected
 * V0.1.6: 2017-11-13, KC:   Calculation result for Ch6 pending on device
 *                           Added 2 macros for clearing ADC interrupts
 * V0.1.7: 2017-12-20, KC:   mV calcualtion corrected
 */

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "tle_device.h"     /* used for conditinal compiling */
#include "adc1.h"
#include "adc1_defines.h"
#include "wdt1.h"
#include "int.h"

/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
/** \brief Initializes the ADC1.
 *
 * \param None
 * \return None
 *
 * \ingroup adc1_api
 */
void ADC1_Init(void)
{
  uint16_t i;
/* Clock Configuration ********************************************************/
  ADC1->CTRL3.reg = (uint32) ADC1_CTRL3;    //1. clock+mode
                                            //2. sequencer config
                                            //3. configure channels, thresholds, filters, calibration, interrupts
                                            //4. configure esm
                                            //5. configure eim
                                            //6. configure interrupts
                                            //7. enable adc1
                                            

  ADC1->CTRL2.reg = (uint32) ADC1_CTRL2;
  ADC1->CTRL5.reg = (uint32) ADC1_CTRL5;  


/* Sequencer0-1 configuration */
  ADC1->SQ0_1.reg = (uint32) ADC1_SQ0_1; 
/* Sequencer2-3 configuration */
  ADC1->SQ2_3.reg = (uint32) ADC1_SQ2_3;  
/* Sequencer4-5 configuration */
  ADC1->SQ4_5.reg = (uint32) ADC1_SQ4_5;  
/* Sequencer6-7 configuration */
  ADC1->SQ6_7.reg = (uint32) ADC1_SQ6_7;
/* Sequencer8-9 configuration */
  ADC1->SQ8_9.reg = (uint32) ADC1_SQ8_9;
/* Sequencer10-11 configuration */
  ADC1->SQ10_11.reg = (uint32) ADC1_SQ10_11;
  
#if (ADC1_DUIN_SEL > 0)
  SCU->MODPISEL4.reg = (uint32) SCU_MODPISEL4;
  ADC1->DCHTH1_4_LOWER.reg = ADC1_DCHTH1_4_LOWER;
  ADC1->DCHTH1_4_UPPER.reg = ADC1_DCHTH1_4_UPPER;
#endif  
  
  ADC1->TH0_3_LOWER.reg = (uint32_t)ADC1_TH0_3_LOWER; 
  ADC1->TH0_3_UPPER.reg = ADC1_TH0_3_UPPER; 
  ADC1->TH4_7_LOWER.reg = ADC1_TH4_7_LOWER; 
  ADC1->TH4_7_UPPER.reg = ADC1_TH4_7_UPPER; 
  ADC1->TH8_11_LOWER.reg = ADC1_TH8_11_LOWER;
  ADC1->TH8_11_UPPER.reg = ADC1_TH8_11_UPPER;
  
  ADC1->CHx_ESM.reg = (uint32) ADC1_CHX_ESM;   
  ADC1->CHx_EIM.reg = (uint32) ADC1_CHX_EIM;  
  
  ADC1->DIFFCH_OUT1.reg = (uint32) ADC1_DIFFCH_OUT1;  
  ADC1->DIFFCH_OUT2.reg = (uint32) ADC1_DIFFCH_OUT2;  
  ADC1->DIFFCH_OUT3.reg = (uint32) ADC1_DIFFCH_OUT3;  
  ADC1->DIFFCH_OUT4.reg = (uint32) ADC1_DIFFCH_OUT4;  
  
  ADC1->DUIN_SEL.reg = (uint32) ADC1_DUIN_SEL;  
  
  ADC1->FILTCOEFF0_11.reg = (uint32) ADC1_FILTCOEFF0_11;  
  
  ADC1->FILT_OUT0.reg = ADC1_FILT_OUT0;
  ADC1->FILT_OUT1.reg = ADC1_FILT_OUT1;
  ADC1->FILT_OUT2.reg = ADC1_FILT_OUT2;
  ADC1->FILT_OUT3.reg = ADC1_FILT_OUT3;
  ADC1->FILT_OUT4.reg = ADC1_FILT_OUT4;
  ADC1->FILT_OUT5.reg = ADC1_FILT_OUT5;
  ADC1->FILT_OUT6.reg = ADC1_FILT_OUT6;
  ADC1->FILT_OUT7.reg = ADC1_FILT_OUT7;
  ADC1->FILT_OUT8.reg = ADC1_FILT_OUT8;
  ADC1->FILT_OUT9.reg = ADC1_FILT_OUT9;
  ADC1->FILT_OUT10.reg = ADC1_FILT_OUT10;
  ADC1->FILT_OUT11.reg = ADC1_FILT_OUT11;
  
  ADC1->FILT_LO_CTRL.reg = ADC1_FILT_LO_CTRL;
  ADC1->FILT_UP_CTRL.reg = ADC1_FILT_UP_CTRL;
  ADC1->IRQEN_1.reg = ADC1_IRQEN_1;
  ADC1->IRQEN_2.reg = ADC1_IRQEN_2;

/* Enable ADC1 ****************************************************************/ 

  INT_Disable_Global_Int();

  /* Enable ADC1 in Peripheral Management Register */
  SCU->PMCON.bit.ADC1_DIS = 0;
  /* Enable Measurement Core Module*/
  ADC1->CTRL3.bit.MCM_PD_N = 1;
  /* Switch ADC1 on */
  ADC1->CTRL_STS.bit.PD_N = 1;

  /* apply 10ms delay to give ADC1 time to turn on */
  for (i = 0; i < 20; i++)
  {
    Delay_us(500);
    (void)WDT1_Service();
  }
  
  ADC1->IRQCLR_1.reg=0xFFFFFFFF;     // clear all collected interrupts during ADC1 startup period 
  ADC1->IRQCLR_2.reg=0xFFFFFFFF;     // clear all collected interrupts during ADC1 startup period 

  INT_Enable_Global_Int();  
}

/** \brief Get ADC1 Channel Correction Factor multiplied by 1024.
 *
 * \param[in] channel-channel number
 * \return true = correction factor multiflied by 1024
 *
 * \ingroup adc1_api
 */
static uint32 ADC1_GetChCorrFactMul1024(uint8 adc1_ch)
{
  if (adc1_ch < 2)
  {
    /* fs = Vref_in_mV / correction_factor / full_scale_bits * 1024 */
    /* fs = 1211 / 0,047 / 2^10 * 1024 */
    return (uint32)25766;      /* ch0-1 */
  }
#if (UC_FEAT_MON == 5)
  else if (adc1_ch < 7)
#else
  else if (adc1_ch < 6)
#endif
  {
    /* fs = 1211 / 0,039 */
    return (uint32) 31051;    /* ch2-6 for devices with MON5, else ch2-5 */
  }
  else 
  {
    /* fs = 1211 / 0,219 */
    return (uint32) 5530;     /* ch7-12 for devices with MON5, else ch6-12 */
  }
}


/** \brief Get ADC1 Channel result value.
 *
 * \param[in] pVar-application variable, channel-channel number
 * \param[out] *pVar = ADC value (10bit right aligned in 16 bit return value)
 * \return true = *pVar valid
 *
 * \ingroup adc1_api
 */
bool ADC1_GetChResult(uint16 * pVar, uint8 channel)
{
  volatile uint32 *pBaseAddr;
  uint8 vf;

  pBaseAddr = &(ADC1->FILT_OUT0.reg) + (uint32) (channel);
  vf = ((*pBaseAddr) >> 17 & 0x1);

  /* update the value only if there is valid data in result register */
  if (vf)
  {
    *pVar = (((*pBaseAddr) & 0x00000FFF)>>2);
  }
  return ((bool)vf);
}                               /* End of ADC1_GetChResult */


/** \brief Get ADC1 Channel result in Milli Volt (mV).
 *
 * \param[in] pVar_mV-application variable, channel-channel number
 * \param[out] *pVar_mV = ADC value in mV
 * \return true = *pVar_mV valid
 *
 * \ingroup adc1_api
 */
bool ADC1_GetChResult_mV(uint16 * pVar_mV, uint8 channel)
{
  uint16 var;
  uint32 fs; 
  bool result_valid;
  
  result_valid = ADC1_GetChResult(&var, channel);
  if (result_valid)
  {
    if(var > 0)
    {
      fs = ADC1_GetChCorrFactMul1024(channel);
      *pVar_mV = (uint16) (((var * fs)-(fs >> 1u)) >> 10u);
    }
    else *pVar_mV = 0;
  }
  return (result_valid);
}


/** \brief Get ADC1 EIM result value.
 *
 * \param[out] *pVar = ADC value (10bit right aligned in 16 bit return value)
 * \return true = *pVar valid
 *
 * \ingroup adc1_api
 */
bool ADC1_GetEIMResult(uint16 * pVar)
{
  volatile uint32 *pBaseAddr;
  uint8 vf;

  pBaseAddr = (uint32 *)&(ADC1->FILT_OUTEIM.reg);
  vf = ((*pBaseAddr) >> 17 & 0x1);
  if (vf)
  {
    *pVar = (((*pBaseAddr) & 0x00000FFF) >> 2);
}
  return ((bool)vf);
}                               /* End of ADC1_GetEIMResult */


/** \brief Get ADC1 EIM result value.
 *
 * \param[in] pVar-application variable
 * \param[out] *pVar_mV = ADC value in mV
 * \return true = *pVar valid
 *
 * \ingroup adc1_api
 */
bool ADC1_GetEIMResult_mV(uint16 * pVar_mV)
{
  uint16 var;
  uint32 fs;
  bool result_valid;
  
  result_valid = ADC1_GetEIMResult(&var);
  if (result_valid)
  {
    if(var > 0)
    {
      fs = ADC1_GetChCorrFactMul1024(ADC1->CHx_EIM.bit.EIM_CHx);
      *pVar_mV = (uint16) (((var * fs)-(fs >> 1u)) >> 10u);
    }
    else *pVar_mV = 0;
  }
  return (result_valid);
}                               /* End of ADC1_GetEIMResult */


/** \brief Get ADC1 SW_MODE result
 *
 * \param[in] pVar - application variable to store the ADC result
 * \return true = *pVar valid
 *
 * \ingroup adc1_api
 */
bool ADC1_GetSwModeResult(uint16 * pVar)
{
  volatile uint32 *pBaseAddr;
  uint8 vf;

  /* Calculate the base address */
  pBaseAddr = &(ADC1->FILT_OUT0.reg) + (uint32) (ADC1->CTRL_STS.bit.SW_CH_SEL);
  vf = ((*pBaseAddr) >> 17 & 0x1);

  if (vf)
  {
    *pVar = (((*pBaseAddr) & 0x00000FFF) >> 2);
  }
  return ((bool) vf);
}                               /* End of ADC1_GetSwModeResult */


/** \brief Get ADC1 SW_MODE result
 *
 * \param[out] *pVar_mV = ADC value in mV
 * \return true = *pVar_mV valid
 *
 * \ingroup adc1_api
 */
bool ADC1_GetSwModeResult_mV(uint16 * pVar_mV)
{
  uint16 var;
  uint32 fs;
  bool result_valid;
  
  result_valid = ADC1_GetSwModeResult(&var);
  if (result_valid)
  {
    if(var > 0)
    {    
      fs = ADC1_GetChCorrFactMul1024(ADC1->CTRL_STS.bit.SW_CH_SEL);
      *pVar_mV = (uint16) (((var * fs)-(fs >> 1u)) >> 10u);
    }
    else *pVar_mV = 0;
  }
  return (result_valid);
}                               /* End of ADC1_GetSwModeResult */

