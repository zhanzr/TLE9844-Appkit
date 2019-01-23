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
/* See adc1.c */

#ifndef ADC1_H
#define ADC1_H

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "TLE984x.h"
#include "types.h"

/*******************************************************************************
**                      Global Constant Declarations                          **
*******************************************************************************/
/* Mode Selection */
#define SOFT_MODE (1u)
#define SEQ_MODE  (0u)

/* Sequencer Configuration */
#define SKIP      (0u)
#define MEAS    (1u)

/* Data Width Selection */
#define BIT10     (0u)
#define BIT8      (1u)

/* Interrupt Enable/Disable */
#define INTDIS    (0u)
#define INTEN     (1u)

/* Result Register WFR mode */
#define OVERWRITE (0u)
#define WFR       (1u)

/* Result Register Channel */
#define ADC1_CH0  (0u)
#define ADC1_CH1  (1u)
#define ADC1_CH2  (2u)
#define ADC1_CH3  (3u)
#define ADC1_CH4  (4u)
#define ADC1_CH5  (5u)
#define ADC1_CH6  (6u)
#define ADC1_CH7  (7u)
#define ADC1_CH8  (8u)
#define ADC1_CH9  (9u)
#define ADC1_CH10 (10u)
#define ADC1_CH11 (11u)
#define ADC1_CH12 (12u)

/* ADC1 Channel Connections */
#define ADC1_VBAT_SENSE (ADC1_CH0)
#define ADC1_VS         (ADC1_CH1)
#define ADC1_MON1       (ADC1_CH2)
#define ADC1_MON2       (ADC1_CH3)
#define ADC1_MON3       (ADC1_CH4)
#define ADC1_MON4       (ADC1_CH5)
#define ADC1_MON5       (ADC1_CH6)
#define ADC1_P21        (ADC1_CH7)
#define ADC1_P22        (ADC1_CH8)
#define ADC1_P23        (ADC1_CH9)
#define ADC1_P26        (ADC1_CH10)
#define ADC1_P27        (ADC1_CH11)
#define ADC1_P20        (ADC1_CH12)

/* Sequencer/ESM Channel Enable Bitposition */
/* ADC1_MASK_CHx Bit */
#define ADC1_MASK_CH0  (1u << 0u)
#define ADC1_MASK_CH1  (1u << 1u)
#define ADC1_MASK_CH2  (1u << 2u)
#define ADC1_MASK_CH3  (1u << 3u)
#define ADC1_MASK_CH4  (1u << 4u)
#define ADC1_MASK_CH5  (1u << 5u)
#define ADC1_MASK_CH6  (1u << 6u)
#define ADC1_MASK_CH7  (1u << 7u)
#define ADC1_MASK_CH8  (1u << 8u)
#define ADC1_MASK_CH9  (1u << 9u)
#define ADC1_MASK_CH10 (1u << 10u)
#define ADC1_MASK_CH11 (1u << 11u)

#define ADC1_MASK_VBAT_SENSE (ADC1_MASK_CH0)
#define ADC1_MASK_VS         (ADC1_MASK_CH1)
#define ADC1_MASK_MON1       (ADC1_MASK_CH2)
#define ADC1_MASK_MON2       (ADC1_MASK_CH3)
#define ADC1_MASK_MON3       (ADC1_MASK_CH4)
#define ADC1_MASK_MON4       (ADC1_MASK_CH5)
#define ADC1_MASK_MON5       (ADC1_MASK_CH6)
#define ADC1_MASK_P21        (ADC1_MASK_CH7)
#define ADC1_MASK_P22        (ADC1_MASK_CH8)
#define ADC1_MASK_P23        (ADC1_MASK_CH9)
#define ADC1_MASK_P26        (ADC1_MASK_CH10)
#define ADC1_MASK_P27        (ADC1_MASK_CH11)

/* ADC1 global configuration flags */
#define ADC1_Power_On()    (ADC1->CTRL_STS.reg |= (uint32) (1u << 0u))
#define ADC1_Power_Off()   (ADC1->CTRL_STS.reg &= (uint32)~(1u << 0u))
#define ADC1_SOOC_Set()    (ADC1->CTRL_STS.reg |= (uint32) (1u << 1u))
#define ADC1_SOS_Set()     (ADC1->CTRL_STS.reg |= (uint32) (1u << 2u))
#define ADC1_DPP1_En()     (ADC1->CTRL_STS.reg |= (uint32) (1u << 18u))
#define ADC1_DPP1_Dis()    (ADC1->CTRL_STS.reg &= (uint32)~(1u << 18u))
#define ADC1_SW_Ch_Sel(adc1_ch)  (ADC1->CTRL_STS.bit.SW_CH_SEL = (uint32)(adc1_ch & 0xFu))

/* ADC1 Status Flags */
#define ADC1_EOC_Sts()       ((ADC1->CTRL_STS.reg >> 7u) & 1u)
#define ADC1_HV_Ready_Sts()  ((ADC1->CTRL_STS.reg >> 5u) & 1u)

/* ADC1 Sequencer Feedback Current ADC1 Channel */
#define ADC1_Current_Ch_Sts()  (ADC1->SQ_FB.reg >> 16u) & 0xFu)
#define ADC1_Current_SQ_Sts()  (ADC1->SQ_FB.reg >> 11u) & 0xFu)
#define ADC1_ESM_Active_Sts()  (ADC1->SQ_FB.reg >> 10u) & 1u)
#define ADC1_EIM_Active_Sts()  (ADC1->SQ_FB.reg >>  9u) & 1u)
#define ADC1_SQ_Stop_Sts()     (ADC1->SQ_FB.reg >>  8u) & 1u)
#define ADC1_SQ_Feedback_Sts() (ADC1->SQ_FB.reg >>  0u) & 0x1Fu)

/* ADC1_CTRL2 */
#define ADC1_Calibration_En(mask_ch) (ADC1->CTRL2.reg = (uint32) (mask_ch & 0xFFFu))

/* ADC1_CTRL3 Sample Time Definitions*/
#define ADC1_MICLK4  (0u)
#define ADC1_MICLK6  (1u)
#define ADC1_MICLK8  (2u)
#define ADC1_MICLK10 (3u)
#define ADC1_MICLK12 (4u)
#define ADC1_MICLK14 (5u)
#define ADC1_MICLK16 (6u)
#define ADC1_MICLK18 (7u)
#define ADC1_MICLK20 (8u)
#define ADC1_MICLK22 (9u)

/* ADC1_CTRL3 */
#define ADC1_Ch_Sample_Time_LV_Set(miclk) \
             (ADC1->CTRL3.bit.SAMPLE_TIME_LVCH = (uint32) (miclk & 0xFu))
#define ADC1_Ch_Sample_Time_HV_Set(miclk) \
             (ADC1->CTRL3.bit.SAMPLE_TIME_HVCH = (uint32) (miclk & 0xFu))

#define ADC1_MCM_Ready_Sts()     ((ADC1->CTRL3.reg >> 7u) & 1u) 
#define ADC1_EOC_Fail_Sts()      ((ADC1->CTRL3.reg >> 6u) & 1u) 
#define ADC1_EOC_Fail_Clr()       (ADC1->CTRL3.reg |= (uint32) (1u << 4u))
#define ADC1_Software_Mode_Sel()  (ADC1->CTRL3.reg |= (uint32) (1u << 1u))
#define ADC1_Sequencer_Mode_Sel() (ADC1->CTRL3.reg &= (uint32)~(1u << 1u))
#define ADC1_MCM_Power_On()       (ADC1->CTRL3.reg |= (uint32) (1u << 1u))
#define ADC1_MCM_Power_Off()      (ADC1->CTRL3.reg &= (uint32)~(1u << 1u))

/* ADC1_CTRL4 */
#define ADC1_Calibration_Time_Set(time) (ADC1->CTRL4.reg = (uint32) (time & 0xFu))

/* ADC1_CTRL5*/
#define ADC1_Ch_Filter_Set(mask_ch) (ADC1->CTRL5.reg = (uint16)(mask_ch & 0xFFFu))

/* ADC1 EIM Channel Setting */
#define ADC1_EIM_Chx_En(adc1_ch) (ADC1->CHx_EIM.bit.EIM_CHx = (uint32)(adc1_ch & 0xFu))
#define ADC1_EIM_Rep_Set(meas)   (ADC1->CHx_EIM.bit.EIM_REP = (uint32)(meas & 0x7u))
#define ADC1_EIM_En()            (ADC1->CHx_EIM.reg |= (uint32) (1u << 11u))
#define ADC1_EIM_Dis()           (ADC1->CHx_EIM.reg &= (uint32)~(1u << 11u))
#define ADC1_EIM_Trig_Set(eim_trig) \
             (ADC1->CHx_EIM.bit.ADC1_EIM_TRIG_SEL = (uint32)(eim_trig & 7u))

/* ADC1 ESM Channel Settings */
#define ADC1_ESM_Sequence_Set(mask_ch) \
                              (ADC1->CHx_ESM.bit.ESM_0 = (mask_ch & 0xFFFu))
#define ADC1_ESM_Trig_Set(esm_trig) \
             (ADC1->CHx_ESM.bit.ADC1_ESM_TRIG_SEL = (uint32)(esm_trig & 7u))

#define ADC1_ESM_En()   (ADC1->CHx_ESM.reg |= (uint32) (1u << 30u))
#define ADC1_ESM_Dis()  (ADC1->CHx_ESM.reg &= (uint32)~(1u << 30u))
#define ADC1_ESM_Sts() ((ADC1->CHx_ESM.reg >> 31u) & 1u)

/* ADC1 Maximum Time in Software Mode */
#define ADC1_SW_Max_Time_Set(time) (ADC1->MAX_TIME.reg = (time & 0xFFu))


/* Result Mode */
#define ADC1_Ch0_WaitForReady_Set()  (ADC1->FILT_OUT0.reg  |= (uint32) (1u << 16u))
#define ADC1_Ch0_Overwrite_Set()     (ADC1->FILT_OUT0.reg  &= (uint32)~(1u << 16u))
#define ADC1_Ch1_WaitForReady_Set()  (ADC1->FILT_OUT1.reg  |= (uint32) (1u << 16u))
#define ADC1_Ch1_Overwrite_Set()     (ADC1->FILT_OUT1.reg  &= (uint32)~(1u << 16u))
#define ADC1_Ch2_WaitForReady_Set()  (ADC1->FILT_OUT2.reg  |= (uint32) (1u << 16u))
#define ADC1_Ch2_Overwrite_Set()     (ADC1->FILT_OUT2.reg  &= (uint32)~(1u << 16u))
#define ADC1_Ch3_WaitForReady_Set()  (ADC1->FILT_OUT3.reg  |= (uint32) (1u << 16u))
#define ADC1_Ch3_Overwrite_Set()     (ADC1->FILT_OUT3.reg  &= (uint32)~(1u << 16u))
#define ADC1_Ch4_WaitForReady_Set()  (ADC1->FILT_OUT4.reg  |= (uint32) (1u << 16u))
#define ADC1_Ch4_Overwrite_Set()     (ADC1->FILT_OUT4.reg  &= (uint32)~(1u << 16u))
#define ADC1_Ch5_WaitForReady_Set()  (ADC1->FILT_OUT5.reg  |= (uint32) (1u << 16u))
#define ADC1_Ch5_Overwrite_Set()     (ADC1->FILT_OUT5.reg  &= (uint32)~(1u << 16u))
#define ADC1_Ch6_WaitForReady_Set()  (ADC1->FILT_OUT6.reg  |= (uint32) (1u << 16u))
#define ADC1_Ch6_Overwrite_Set()     (ADC1->FILT_OUT6.reg  &= (uint32)~(1u << 16u))
#define ADC1_Ch7_WaitForReady_Set()  (ADC1->FILT_OUT7.reg  |= (uint32) (1u << 16u))
#define ADC1_Ch7_Overwrite_Set()     (ADC1->FILT_OUT7.reg  &= (uint32)~(1u << 16u))
#define ADC1_Ch8_WaitForReady_Set()  (ADC1->FILT_OUT8.reg  |= (uint32) (1u << 16u))
#define ADC1_Ch8_Overwrite_Set()     (ADC1->FILT_OUT8.reg  &= (uint32)~(1u << 16u))
#define ADC1_Ch9_WaitForReady_Set()  (ADC1->FILT_OUT9.reg  |= (uint32) (1u << 16u))
#define ADC1_Ch9_Overwrite_Set()     (ADC1->FILT_OUT9.reg  &= (uint32)~(1u << 16u))
#define ADC1_Ch10_WaitForReady_Set() (ADC1->FILT_OUT10.reg |= (uint32) (1u << 16u))
#define ADC1_Ch10_Overwrite_Set()    (ADC1->FILT_OUT10.reg &= (uint32)~(1u << 16u))
#define ADC1_Ch11_WaitForReady_Set() (ADC1->FILT_OUT11.reg |= (uint32) (1u << 16u))
#define ADC1_Ch11_Overwrite_Set()    (ADC1->FILT_OUT11.reg &= (uint32)~(1u << 16u))
#define ADC1_Ch12_WaitForReady_Set() (ADC1->FILT_OUT12.reg |= (uint32) (1u << 16u))
#define ADC1_Ch12_Overwrite_Set()    (ADC1->FILT_OUT12.reg &= (uint32)~(1u << 16u))
#if defined(TLE9845QX)
#define ADC1_DU1_WaitForReady_Set() (ADC1->DIFFCH_OUT1.reg |= (uint32) (1u << 16u))
#define ADC1_DU1_Overwrite_Set()    (ADC1->DIFFCH_OUT1.reg &= (uint32)~(1u << 16u))
#define ADC1_DU2_WaitForReady_Set() (ADC1->DIFFCH_OUT2.reg |= (uint32) (1u << 16u))
#define ADC1_DU2_Overwrite_Set()    (ADC1->DIFFCH_OUT2.reg &= (uint32)~(1u << 16u))
#define ADC1_DU3_WaitForReady_Set() (ADC1->DIFFCH_OUT3.reg |= (uint32) (1u << 16u))
#define ADC1_DU3_Overwrite_Set()    (ADC1->DIFFCH_OUT3.reg &= (uint32)~(1u << 16u))
#define ADC1_DU4_WaitForReady_Set() (ADC1->DIFFCH_OUT4.reg |= (uint32) (1u << 16u))
#define ADC1_DU4_Overwrite_Set()    (ADC1->DIFFCH_OUT4.reg &= (uint32)~(1u << 16u))
#endif

/* Get ADC1 Result Value */
#define ADC1_Ch0_Result_Get()  ((uint16)((ADC1->FILT_OUT0.reg  & 0xFFFu)>>2u))
#define ADC1_Ch1_Result_Get()  ((uint16)((ADC1->FILT_OUT1.reg  & 0xFFFu)>>2u))
#define ADC1_Ch2_Result_Get()  ((uint16)((ADC1->FILT_OUT2.reg  & 0xFFFu)>>2u))
#define ADC1_Ch3_Result_Get()  ((uint16)((ADC1->FILT_OUT3.reg  & 0xFFFu)>>2u))
#define ADC1_Ch4_Result_Get()  ((uint16)((ADC1->FILT_OUT4.reg  & 0xFFFu)>>2u))
#define ADC1_Ch5_Result_Get()  ((uint16)((ADC1->FILT_OUT5.reg  & 0xFFFu)>>2u))
#define ADC1_Ch6_Result_Get()  ((uint16)((ADC1->FILT_OUT6.reg  & 0xFFFu)>>2u))
#define ADC1_Ch7_Result_Get()  ((uint16)((ADC1->FILT_OUT7.reg  & 0xFFFu)>>2u))
#define ADC1_Ch8_Result_Get()  ((uint16)((ADC1->FILT_OUT8.reg  & 0xFFFu)>>2u))
#define ADC1_Ch9_Result_Get()  ((uint16)((ADC1->FILT_OUT9.reg  & 0xFFFu)>>2u))
#define ADC1_Ch10_Result_Get() ((uint16)((ADC1->FILT_OUT10.reg & 0xFFFu)>>2u))
#define ADC1_Ch11_Result_Get() ((uint16)((ADC1->FILT_OUT11.reg & 0xFFFu)>>2u))
#define ADC1_Ch12_Result_Get() ((uint16)((ADC1->FILT_OUT12.reg & 0xFFFu)>>2u))
#if defined(TLE9845QX)
#define ADC1_DU1_Result_Get() ((uint16)((ADC1->DIFFCH_OUT1.reg & 0xFFFu)>>2u))
#define ADC1_DU2_Result_Get() ((uint16)((ADC1->DIFFCH_OUT2.reg & 0xFFFu)>>2u))
#define ADC1_DU3_Result_Get() ((uint16)((ADC1->DIFFCH_OUT3.reg & 0xFFFu)>>2u))
#define ADC1_DU4_Result_Get() ((uint16)((ADC1->DIFFCH_OUT4.reg & 0xFFFu)>>2u))
#endif

#define ADC1_VBAT_SENSE_Result_Get()  ADC1_Ch0_Result_Get() 
#define ADC1_VS_Result_Get()          ADC1_Ch1_Result_Get() 
#define ADC1_MON1_Result_Get()        ADC1_Ch2_Result_Get() 
#define ADC1_MON2_Result_Get()        ADC1_Ch3_Result_Get() 
#define ADC1_MON3_Result_Get()        ADC1_Ch4_Result_Get() 
#define ADC1_MON4_Result_Get()        ADC1_Ch5_Result_Get() 
#define ADC1_MON5_Result_Get()        ADC1_Ch6_Result_Get() 
#define ADC1_P21_Result_Get()         ADC1_Ch7_Result_Get() 
#define ADC1_P22_Result_Get()         ADC1_Ch8_Result_Get() 
#define ADC1_P23_Result_Get()         ADC1_Ch9_Result_Get() 
#define ADC1_P26_Result_Get()         ADC1_Ch10_Result_Get()
#define ADC1_P27_Result_Get()         ADC1_Ch11_Result_Get()
#define ADC1_P20_Result_Get()         ADC1_Ch12_Result_Get()

/* ADC1 Sequencer configuration Macros*/
#define ADC1_Sequence0_Set(mask_ch)  (ADC1->SQ0_1.bit.SQ0 = (uint32)(mask_ch & 0xFFFu))
#define ADC1_Sequence1_Set(mask_ch)  (ADC1->SQ0_1.bit.SQ1 = (uint32)(mask_ch & 0xFFFu))
#define ADC1_Sequence2_Set(mask_ch)  (ADC1->SQ2_3.bit.SQ2 = (uint32)(mask_ch & 0xFFFu))
#define ADC1_Sequence3_Set(mask_ch)  (ADC1->SQ2_3.bit.SQ3 = (uint32)(mask_ch & 0xFFFu))
#define ADC1_Sequence4_Set(mask_ch)  (ADC1->SQ4_5.bit.SQ4 = (uint32)(mask_ch & 0xFFFu))
#define ADC1_Sequence5_Set(mask_ch)  (ADC1->SQ4_5.bit.SQ5 = (uint32)(mask_ch & 0xFFFu))
#define ADC1_Sequence6_Set(mask_ch)  (ADC1->SQ6_7.bit.SQ6 = (uint32)(mask_ch & 0xFFFu))
#define ADC1_Sequence7_Set(mask_ch)  (ADC1->SQ6_7.bit.SQ7 = (uint32)(mask_ch & 0xFFFu))
#define ADC1_Sequence8_Set(mask_ch)  (ADC1->SQ8_9.bit.SQ8 = (uint32)(mask_ch & 0xFFFu))
#define ADC1_Sequence9_Set(mask_ch)  (ADC1->SQ8_9.bit.SQ9 = (uint32)(mask_ch & 0xFFFu))
#define ADC1_Sequence10_Set(mask_ch) (ADC1->SQ10_11.bit.SQ10 = (uint32)(mask_ch & 0xFFFu))
#define ADC1_Sequence11_Set(mask_ch) (ADC1->SQ10_11.bit.SQ11 = (uint32)(mask_ch & 0xFFFu))


/* ADC1 Postprocessing Control Register */
#define ADC1_Ch0_Filt_Up_En()  (ADC1->FILT_UP_CTRL.reg |= (uint32) (1u << 0u))
#define ADC1_Ch1_Filt_Up_En()  (ADC1->FILT_UP_CTRL.reg |= (uint32) (1u << 1u))
#define ADC1_Ch2_Filt_Up_En()  (ADC1->FILT_UP_CTRL.reg |= (uint32) (1u << 2u))
#define ADC1_Ch3_Filt_Up_En()  (ADC1->FILT_UP_CTRL.reg |= (uint32) (1u << 3u))
#define ADC1_Ch4_Filt_Up_En()  (ADC1->FILT_UP_CTRL.reg |= (uint32) (1u << 4u))
#define ADC1_Ch5_Filt_Up_En()  (ADC1->FILT_UP_CTRL.reg |= (uint32) (1u << 5u))
#define ADC1_Ch6_Filt_Up_En()  (ADC1->FILT_UP_CTRL.reg |= (uint32) (1u << 6u))
#define ADC1_Ch7_Filt_Up_En()  (ADC1->FILT_UP_CTRL.reg |= (uint32) (1u << 7u))
#define ADC1_Ch8_Filt_Up_En()  (ADC1->FILT_UP_CTRL.reg |= (uint32) (1u << 8u))
#define ADC1_Ch9_Filt_Up_En()  (ADC1->FILT_UP_CTRL.reg |= (uint32) (1u << 9u))
#define ADC1_Ch10_Filt_Up_En() (ADC1->FILT_UP_CTRL.reg |= (uint32) (1u << 10u))
#define ADC1_Ch11_Filt_Up_En() (ADC1->FILT_UP_CTRL.reg |= (uint32) (1u << 11u))

#define ADC1_Ch0_Filt_Up_Dis()  (ADC1->FILT_UP_CTRL.reg &= (uint32)~(1u << 0u))
#define ADC1_Ch1_Filt_Up_Dis()  (ADC1->FILT_UP_CTRL.reg &= (uint32)~(1u << 1u))
#define ADC1_Ch2_Filt_Up_Dis()  (ADC1->FILT_UP_CTRL.reg &= (uint32)~(1u << 2u))
#define ADC1_Ch3_Filt_Up_Dis()  (ADC1->FILT_UP_CTRL.reg &= (uint32)~(1u << 3u))
#define ADC1_Ch4_Filt_Up_Dis()  (ADC1->FILT_UP_CTRL.reg &= (uint32)~(1u << 4u))
#define ADC1_Ch5_Filt_Up_Dis()  (ADC1->FILT_UP_CTRL.reg &= (uint32)~(1u << 5u))
#define ADC1_Ch6_Filt_Up_Dis()  (ADC1->FILT_UP_CTRL.reg &= (uint32)~(1u << 6u))
#define ADC1_Ch7_Filt_Up_Dis()  (ADC1->FILT_UP_CTRL.reg &= (uint32)~(1u << 7u))
#define ADC1_Ch8_Filt_Up_Dis()  (ADC1->FILT_UP_CTRL.reg &= (uint32)~(1u << 8u))
#define ADC1_Ch9_Filt_Up_Dis()  (ADC1->FILT_UP_CTRL.reg &= (uint32)~(1u << 9u))
#define ADC1_Ch10_Filt_Up_Dis() (ADC1->FILT_UP_CTRL.reg &= (uint32)~(1u << 10u))
#define ADC1_Ch11_Filt_Up_Dis() (ADC1->FILT_UP_CTRL.reg &= (uint32)~(1u << 11u))

#define ADC1_Ch0_Filt_Lo_En()  (ADC1->FILT_LO_CTRL.reg |= (uint32) (1u << 0u))
#define ADC1_Ch1_Filt_Lo_En()  (ADC1->FILT_LO_CTRL.reg |= (uint32) (1u << 1u))
#define ADC1_Ch2_Filt_Lo_En()  (ADC1->FILT_LO_CTRL.reg |= (uint32) (1u << 2u))
#define ADC1_Ch3_Filt_Lo_En()  (ADC1->FILT_LO_CTRL.reg |= (uint32) (1u << 3u))
#define ADC1_Ch4_Filt_Lo_En()  (ADC1->FILT_LO_CTRL.reg |= (uint32) (1u << 4u))
#define ADC1_Ch5_Filt_Lo_En()  (ADC1->FILT_LO_CTRL.reg |= (uint32) (1u << 5u))
#define ADC1_Ch6_Filt_Lo_En()  (ADC1->FILT_LO_CTRL.reg |= (uint32) (1u << 6u))
#define ADC1_Ch7_Filt_Lo_En()  (ADC1->FILT_LO_CTRL.reg |= (uint32) (1u << 7u))
#define ADC1_Ch8_Filt_Lo_En()  (ADC1->FILT_LO_CTRL.reg |= (uint32) (1u << 8u))
#define ADC1_Ch9_Filt_Lo_En()  (ADC1->FILT_LO_CTRL.reg |= (uint32) (1u << 9u))
#define ADC1_Ch10_Filt_Lo_En() (ADC1->FILT_LO_CTRL.reg |= (uint32) (1u << 10u))
#define ADC1_Ch11_Filt_Lo_En() (ADC1->FILT_LO_CTRL.reg |= (uint32) (1u << 11u))

#define ADC1_Ch0_Filt_Lo_Dis()  (ADC1->FILT_LO_CTRL.reg &= (uint32)~(1u << 0u))
#define ADC1_Ch1_Filt_Lo_Dis()  (ADC1->FILT_LO_CTRL.reg &= (uint32)~(1u << 1u))
#define ADC1_Ch2_Filt_Lo_Dis()  (ADC1->FILT_LO_CTRL.reg &= (uint32)~(1u << 2u))
#define ADC1_Ch3_Filt_Lo_Dis()  (ADC1->FILT_LO_CTRL.reg &= (uint32)~(1u << 3u))
#define ADC1_Ch4_Filt_Lo_Dis()  (ADC1->FILT_LO_CTRL.reg &= (uint32)~(1u << 4u))
#define ADC1_Ch5_Filt_Lo_Dis()  (ADC1->FILT_LO_CTRL.reg &= (uint32)~(1u << 5u))
#define ADC1_Ch6_Filt_Lo_Dis()  (ADC1->FILT_LO_CTRL.reg &= (uint32)~(1u << 6u))
#define ADC1_Ch7_Filt_Lo_Dis()  (ADC1->FILT_LO_CTRL.reg &= (uint32)~(1u << 7u))
#define ADC1_Ch8_Filt_Lo_Dis()  (ADC1->FILT_LO_CTRL.reg &= (uint32)~(1u << 8u))
#define ADC1_Ch9_Filt_Lo_Dis()  (ADC1->FILT_LO_CTRL.reg &= (uint32)~(1u << 9u))
#define ADC1_Ch10_Filt_Lo_Dis() (ADC1->FILT_LO_CTRL.reg &= (uint32)~(1u << 10u))
#define ADC1_Ch11_Filt_Lo_Dis() (ADC1->FILT_LO_CTRL.reg &= (uint32)~(1u << 11u))

/* ADC1 Differential Unit Status Clear Macros*/
#if defined(TLE9845QX)
#define ADC1_DU1_Lo_Sts_Clr() (ADC1->STSCLR_1.reg = (uint32)(1u << 24u))
#define ADC1_DU1_Up_Sts_Clr() (ADC1->STSCLR_1.reg = (uint32)(1u << 25u))
#define ADC1_DU2_Lo_Sts_Clr() (ADC1->STSCLR_1.reg = (uint32)(1u << 26u))
#define ADC1_DU2_Up_Sts_Clr() (ADC1->STSCLR_1.reg = (uint32)(1u << 27u))
#define ADC1_DU3_Lo_Sts_Clr() (ADC1->STSCLR_1.reg = (uint32)(1u << 28u))
#define ADC1_DU3_Up_Sts_Clr() (ADC1->STSCLR_1.reg = (uint32)(1u << 29u))
#define ADC1_DU4_Lo_Sts_Clr() (ADC1->STSCLR_1.reg = (uint32)(1u << 30u))
#define ADC1_DU4_Up_Sts_Clr() (ADC1->STSCLR_1.reg = (uint32)(1u << 31u))
#endif

/* ADC1 Differential Measurement Unit */
#if defined(TLE9845QX)
#define ADC1_DU1_En()  (ADC1->DUIN_SEL.reg |= (uint32)  (1u << 0u))
#define ADC1_DU2_En()  (ADC1->DUIN_SEL.reg |= (uint32)  (1u << 8u))
#define ADC1_DU3_En()  (ADC1->DUIN_SEL.reg |= (uint32)  (1u << 16u))
#define ADC1_DU4_En()  (ADC1->DUIN_SEL.reg |= (uint32)  (1u << 24u))
#define ADC1_DU1_Dis() (ADC1->DUIN_SEL.reg &= (uint32) ~(1u << 0u))
#define ADC1_DU2_Dis() (ADC1->DUIN_SEL.reg &= (uint32) ~(1u << 8u))
#define ADC1_DU3_Dis() (ADC1->DUIN_SEL.reg &= (uint32) ~(1u << 16u))
#define ADC1_DU4_Dis() (ADC1->DUIN_SEL.reg &= (uint32) ~(1u << 24u))

#define ADC1_DU1_Result_Neg_Sts() (uint32)((ADC1->DUIN_SEL.reg >> 4u) & 1u)
#define ADC1_DU2_Result_Neg_Sts() (uint32)((ADC1->DUIN_SEL.reg >> 12u) & 1u)
#define ADC1_DU3_Result_Neg_Sts() (uint32)((ADC1->DUIN_SEL.reg >> 20u) & 1u)
#define ADC1_DU4_Result_Neg_Sts() (uint32)((ADC1->DUIN_SEL.reg >> 28u) & 1u)
#endif


/* ADC1 Overvoltage Measurement Mode */

#define ADC1_MMODE_0  0u
#define ADC1_MMODE_UV 1u
#define ADC1_MMODE_OV 2u

#define ADC1_Ch0_Mode_Meas_Sel(mmode)  (ADC1->MMODE0_11.bit.MMODE_0  = (uint32)(mmode & 3u))
#define ADC1_Ch1_Mode_Meas_Sel(mmode)  (ADC1->MMODE0_11.bit.MMODE_1  = (uint32)(mmode & 3u))
#define ADC1_Ch2_Mode_Meas_Sel(mmode)  (ADC1->MMODE0_11.bit.MMODE_2  = (uint32)(mmode & 3u))
#define ADC1_Ch3_Mode_Meas_Sel(mmode)  (ADC1->MMODE0_11.bit.MMODE_3  = (uint32)(mmode & 3u))
#define ADC1_Ch4_Mode_Meas_Sel(mmode)  (ADC1->MMODE0_11.bit.MMODE_4  = (uint32)(mmode & 3u))
#define ADC1_Ch5_Mode_Meas_Sel(mmode)  (ADC1->MMODE0_11.bit.MMODE_5  = (uint32)(mmode & 3u))
#define ADC1_Ch6_Mode_Meas_Sel(mmode)  (ADC1->MMODE0_11.bit.MMODE_6  = (uint32)(mmode & 3u))
#define ADC1_Ch7_Mode_Meas_Sel(mmode)  (ADC1->MMODE0_11.bit.MMODE_7  = (uint32)(mmode & 3u))
#define ADC1_Ch8_Mode_Meas_Sel(mmode)  (ADC1->MMODE0_11.bit.MMODE_8  = (uint32)(mmode & 3u))
#define ADC1_Ch9_Mode_Meas_Sel(mmode)  (ADC1->MMODE0_11.bit.MMODE_9  = (uint32)(mmode & 3u))
#define ADC1_Ch10_Mode_Meas_Sel(mmode) (ADC1->MMODE0_11.bit.MMODE_10 = (uint32)(mmode & 3u))
#define ADC1_Ch11_Mode_Meas_Sel(mmode) (ADC1->MMODE0_11.bit.MMODE_11 = (uint32)(mmode & 3u))
#if defined(TLE9845QX)
#define ADC1_DU1_Mode_Meas_Sel(mmode)  (ADC1->MMODE0_11.bit.MMODE_D1 = (uint32)(mmode & 3u))
#define ADC1_DU2_Mode_Meas_Sel(mmode)  (ADC1->MMODE0_11.bit.MMODE_D2 = (uint32)(mmode & 3u))
#define ADC1_DU3_Mode_Meas_Sel(mmode)  (ADC1->MMODE0_11.bit.MMODE_D3 = (uint32)(mmode & 3u))
#define ADC1_DU4_Mode_Meas_Sel(mmode)  (ADC1->MMODE0_11.bit.MMODE_D4 = (uint32)(mmode & 3u))
#endif

/* ADC1 Postprocessing Lower Comparator Trigger Level */
#define ADC1_Ch0_Lo_Th_Set(trig_val)  (ADC1->TH0_3_LOWER.bit.CH0_LOW = (uint32)(trig_val & 0xFFu))
#define ADC1_Ch1_Lo_Th_Set(trig_val)  (ADC1->TH0_3_LOWER.bit.CH1_LOW = (uint32)(trig_val & 0xFFu))
#define ADC1_Ch2_Lo_Th_Set(trig_val)  (ADC1->TH0_3_LOWER.bit.CH2_LOW = (uint32)(trig_val & 0xFFu))
#define ADC1_Ch3_Lo_Th_Set(trig_val)  (ADC1->TH0_3_LOWER.bit.CH3_LOW = (uint32)(trig_val & 0xFFu))
#define ADC1_Ch4_Lo_Th_Set(trig_val)  (ADC1->TH4_7_LOWER.bit.CH4_LOW = (uint32)(trig_val & 0xFFu))
#define ADC1_Ch5_Lo_Th_Set(trig_val)  (ADC1->TH4_7_LOWER.bit.CH5_LOW = (uint32)(trig_val & 0xFFu))
#define ADC1_Ch6_Lo_Th_Set(trig_val)  (ADC1->TH4_7_LOWER.bit.CH6_LOW = (uint32)(trig_val & 0xFFu))
#define ADC1_Ch7_Lo_Th_Set(trig_val)  (ADC1->TH4_7_LOWER.bit.CH7_LOW = (uint32)(trig_val & 0xFFu))
#define ADC1_Ch8_Lo_Th_Set(trig_val)  (ADC1->TH8_11_LOWER.bit.CH8_LOW = (uint32)(trig_val & 0xFFu))
#define ADC1_Ch9_Lo_Th_Set(trig_val)  (ADC1->TH8_11_LOWER.bit.CH9_LOW = (uint32)(trig_val & 0xFFu))
#define ADC1_Ch10_Lo_Th_Set(trig_val) (ADC1->TH8_11_LOWER.bit.CH10_LOW = (uint32)(trig_val & 0xFFu))
#define ADC1_Ch11_Lo_Th_Set(trig_val) (ADC1->TH8_11_LOWER.bit.CH11_LOW = (uint32)(trig_val & 0xFFu))
#if defined(TLE9845QX)
#define ADC1_DU1_Lo_Th_Set(trig_val)  (ADC1->DCHTH1_4_LOWER.bit.DCH1_LOW = (uint32)(trig_val & 0xFFu))
#define ADC1_DU2_Lo_Th_Set(trig_val)  (ADC1->DCHTH1_4_LOWER.bit.DCH2_LOW = (uint32)(trig_val & 0xFFu))
#define ADC1_DU3_Lo_Th_Set(trig_val)  (ADC1->DCHTH1_4_LOWER.bit.DCH3_LOW = (uint32)(trig_val & 0xFFu))
#define ADC1_DU4_Lo_Th_Set(trig_val)  (ADC1->DCHTH1_4_LOWER.bit.DCH4_LOW = (uint32)(trig_val & 0xFFu))
#endif

/* ADC1 Postprocessing Upper Comparator Trigger Level */
#define ADC1_Ch0_Up_Th_Set(trig_val)  (ADC1->TH0_3_UPPER.bit.CH0_UP = (uint32)(trig_val & 0xFFu))
#define ADC1_Ch1_Up_Th_Set(trig_val)  (ADC1->TH0_3_UPPER.bit.CH1_UP = (uint32)(trig_val & 0xFFu))
#define ADC1_Ch2_Up_Th_Set(trig_val)  (ADC1->TH0_3_UPPER.bit.CH2_UP = (uint32)(trig_val & 0xFFu))
#define ADC1_Ch3_Up_Th_Set(trig_val)  (ADC1->TH0_3_UPPER.bit.CH3_UP = (uint32)(trig_val & 0xFFu))
#define ADC1_Ch4_Up_Th_Set(trig_val)  (ADC1->TH4_7_UPPER.bit.CH4_UP = (uint32)(trig_val & 0xFFu))
#define ADC1_Ch5_Up_Th_Set(trig_val)  (ADC1->TH4_7_UPPER.bit.CH5_UP = (uint32)(trig_val & 0xFFu))
#define ADC1_Ch6_Up_Th_Set(trig_val)  (ADC1->TH4_7_UPPER.bit.CH6_UP = (uint32)(trig_val & 0xFFu))
#define ADC1_Ch7_Up_Th_Set(trig_val)  (ADC1->TH4_7_UPPER.bit.CH7_UP = (uint32)(trig_val & 0xFFu))
#define ADC1_Ch8_Up_Th_Set(trig_val)  (ADC1->TH8_11_UPPER.bit.CH8_UP = (uint32)(trig_val & 0xFFu))
#define ADC1_Ch9_Up_Th_Set(trig_val)  (ADC1->TH8_11_UPPER.bit.CH9_UP = (uint32)(trig_val & 0xFFu))
#define ADC1_Ch10_Up_Th_Set(trig_val) (ADC1->TH8_11_UPPER.bit.CH10_UP = (uint32)(trig_val & 0xFFu))
#define ADC1_Ch11_Up_Th_Set(trig_val) (ADC1->TH8_11_UPPER.bit.CH11_UP = (uint32)(trig_val & 0xFFu))
#if defined(TLE9845QX)
#define ADC1_DU1_Up_Th_Set(trig_val)  (ADC1->DCHTH1_4_UPPER.bit.DCH1_UP = (uint32)(trig_val & 0xFFu))
#define ADC1_DU2_Up_Th_Set(trig_val)  (ADC1->DCHTH1_4_UPPER.bit.DCH2_UP = (uint32)(trig_val & 0xFFu))
#define ADC1_DU3_Up_Th_Set(trig_val)  (ADC1->DCHTH1_4_UPPER.bit.DCH3_UP = (uint32)(trig_val & 0xFFu))
#define ADC1_DU4_Up_Th_Set(trig_val)  (ADC1->DCHTH1_4_UPPER.bit.DCH4_UP = (uint32)(trig_val & 0xFFu))
#endif

/* Differential Unit Trigger Selection */
typedef enum _du_triggen_sel{
  DU_TRIGGEN_CC60   = (uint32)0u,\
  DU_TRIGGEN_CC61   = (uint32)1u,\
  DU_TRIGGEN_CC62   = (uint32)2u,\
  DU_TRIGGEN_COUT60 = (uint32)3u,\
  DU_TRIGGEN_COUT61 = (uint32)4u,\
  DU_TRIGGEN_COUT62 = (uint32)5u,\
  DU_TRIGGEN_T3OUT  = (uint32)6u,\
  DU_TRIGGEN_COUT63 = (uint32)7u,\
  DU_TRIGGEN_Ch0t   = (uint32)0u,\
  DU_TRIGGEN_Ch1t   = (uint32)1u,\
  DU_TRIGGEN_Ch2t   = (uint32)2u,\
  DU_TRIGGEN_Ch0c   = (uint32)3u,\
  DU_TRIGGEN_Ch1c   = (uint32)4u,\
  DU_TRIGGEN_Ch2c   = (uint32)5u,\
  DU_TRIGGEN_T3_Out = (uint32)6u,\
  DU_TRIGGEN_Ch3c   = (uint32)7u,\
}du_triggen_sel;

#if defined(TLE9845QX)
#define ADC1_DU1_Trigger_Sel(trig_Ch) (SCU->MODPISEL4.bit.DU1TRIGGEN = (uint32)(trig_Ch & 3u))
#define ADC1_DU2_Trigger_Sel(trig_Ch) (SCU->MODPISEL4.bit.DU2TRIGGEN = (uint32)(trig_Ch & 3u))
#define ADC1_DU3_Trigger_Sel(trig_Ch) (SCU->MODPISEL4.bit.DU3TRIGGEN = (uint32)(trig_Ch & 3u))
#define ADC1_DU4_Trigger_Sel(trig_Ch) (SCU->MODPISEL4.bit.DU4TRIGGEN = (uint32)(trig_Ch & 3u))
#endif

/* ADC1 Lower Hysteresis Trigger Level  */
#define ADC1_HYST_OFF (0u)
#define ADC1_HYST_4   (1u)
#define ADC1_HYST_8   (2u)
#define ADC1_HYST_16  (3u)

#define ADC1_Ch0_Lo_hys_Set(hyst)  (ADC1->CNT0_3_LOWER.bit.HYST_LO_CH0 = (uint32)(hyst & 3u))
#define ADC1_Ch1_Lo_hys_Set(hyst)  (ADC1->CNT0_3_LOWER.bit.HYST_LO_CH1 = (uint32)(hyst & 3u))
#define ADC1_Ch2_Lo_hys_Set(hyst)  (ADC1->CNT0_3_LOWER.bit.HYST_LO_CH2 = (uint32)(hyst & 3u))
#define ADC1_Ch3_Lo_hys_Set(hyst)  (ADC1->CNT0_3_LOWER.bit.HYST_LO_CH3 = (uint32)(hyst & 3u))
#define ADC1_Ch4_Lo_hys_Set(hyst)  (ADC1->CNT4_7_LOWER.bit.HYST_LO_CH4 = (uint32)(hyst & 3u))
#define ADC1_Ch5_Lo_hys_Set(hyst)  (ADC1->CNT4_7_LOWER.bit.HYST_LO_CH5 = (uint32)(hyst & 3u))
#define ADC1_Ch6_Lo_hys_Set(hyst)  (ADC1->CNT4_7_LOWER.bit.HYST_LO_CH6 = (uint32)(hyst & 3u))
#define ADC1_Ch7_Lo_hys_Set(hyst)  (ADC1->CNT4_7_LOWER.bit.HYST_LO_CH7 = (uint32)(hyst & 3u))
#define ADC1_Ch8_Lo_hys_Set(hyst)  (ADC1->CNT8_11_LOWER.bit.HYST_LO_CH8  = (uint32)(hyst & 3u))
#define ADC1_Ch9_Lo_hys_Set(hyst)  (ADC1->CNT8_11_LOWER.bit.HYST_LO_CH9  = (uint32)(hyst & 3u))
#define ADC1_Ch10_Lo_hys_Set(hyst) (ADC1->CNT8_11_LOWER.bit.HYST_LO_CH10 = (uint32)(hyst & 3u))
#define ADC1_Ch11_Lo_hys_Set(hyst) (ADC1->CNT8_11_LOWER.bit.HYST_LO_CH11 = (uint32)(hyst & 3u))
#if defined(TLE9845QX)
#define ADC1_DU1_Lo_hys_Set(hyst)  (ADC1->DCHCNT1_4_LOWER.bit.HYST_LO_DCH1 = (uint32)(hyst & 3u))
#define ADC1_DU2_Lo_hys_Set(hyst)  (ADC1->DCHCNT1_4_LOWER.bit.HYST_LO_DCH2 = (uint32)(hyst & 3u))
#define ADC1_DU3_Lo_hys_Set(hyst)  (ADC1->DCHCNT1_4_LOWER.bit.HYST_LO_DCH3 = (uint32)(hyst & 3u))
#define ADC1_DU4_Lo_hys_Set(hyst)  (ADC1->DCHCNT1_4_LOWER.bit.HYST_LO_DCH4 = (uint32)(hyst & 3u))
#endif

/* ADC1 Upper Hysteresis Trigger Level  */
#define ADC1_Ch0_Up_hys_Set(hyst)  (ADC1->CNT0_3_UPPER.bit.HYST_UP_CH0 = (uint32)(hyst & 3u))
#define ADC1_Ch1_Up_hys_Set(hyst)  (ADC1->CNT0_3_UPPER.bit.HYST_UP_CH1 = (uint32)(hyst & 3u))
#define ADC1_Ch2_Up_hys_Set(hyst)  (ADC1->CNT0_3_UPPER.bit.HYST_UP_CH2 = (uint32)(hyst & 3u))
#define ADC1_Ch3_Up_hys_Set(hyst)  (ADC1->CNT0_3_UPPER.bit.HYST_UP_CH3 = (uint32)(hyst & 3u))
#define ADC1_Ch4_Up_hys_Set(hyst)  (ADC1->CNT4_7_UPPER.bit.HYST_UP_CH4 = (uint32)(hyst & 3u))
#define ADC1_Ch5_Up_hys_Set(hyst)  (ADC1->CNT4_7_UPPER.bit.HYST_UP_CH5 = (uint32)(hyst & 3u))
#define ADC1_Ch6_Up_hys_Set(hyst)  (ADC1->CNT4_7_UPPER.bit.HYST_UP_CH6 = (uint32)(hyst & 3u))
#define ADC1_Ch7_Up_hys_Set(hyst)  (ADC1->CNT4_7_UPPER.bit.HYST_UP_CH7 = (uint32)(hyst & 3u))
#define ADC1_Ch8_Up_hys_Set(hyst)  (ADC1->CNT8_11_UPPER.bit.HYST_UP_CH8  = (uint32)(hyst & 3u))
#define ADC1_Ch9_Up_hys_Set(hyst)  (ADC1->CNT8_11_UPPER.bit.HYST_UP_CH9  = (uint32)(hyst & 3u))
#define ADC1_Ch10_Up_hys_Set(hyst) (ADC1->CNT8_11_UPPER.bit.HYST_UP_CH10 = (uint32)(hyst & 3u))
#define ADC1_Ch11_Up_hys_Set(hyst) (ADC1->CNT8_11_UPPER.bit.HYST_UP_CH11 = (uint32)(hyst & 3u))
#if defined(TLE9845QX)
#define ADC1_DU1_Up_hys_Set(hyst)  (ADC1->DCHCNT1_4_UPPER.bit.HYST_UP_DCH1 = (uint32)(hyst & 3u))
#define ADC1_DU2_Up_hys_Set(hyst)  (ADC1->DCHCNT1_4_UPPER.bit.HYST_UP_DCH2 = (uint32)(hyst & 3u))
#define ADC1_DU3_Up_hys_Set(hyst)  (ADC1->DCHCNT1_4_UPPER.bit.HYST_UP_DCH3 = (uint32)(hyst & 3u))
#define ADC1_DU4_Up_hys_Set(hyst)  (ADC1->DCHCNT1_4_UPPER.bit.HYST_UP_DCH4 = (uint32)(hyst & 3u))
#endif


/* ADC1 Lower Counter Trigger Level  */
#define ADC1_CNT_1  (0u)
#define ADC1_CNT_2  (1u)
#define ADC1_CNT_4  (2u)
#define ADC1_CNT_8  (3u)
#define ADC1_CNT_16 (4u)
#define ADC1_CNT_32 (5u)
#define ADC1_CNT_63 (6u)

#define ADC1_Ch0_Lo_Cnt_Set(cnt)  (ADC1->CNT0_3_LOWER.bit.CNT_LO_CH0   = (uint32)(cnt & 7u))
#define ADC1_Ch1_Lo_Cnt_Set(cnt)  (ADC1->CNT0_3_LOWER.bit.CNT_LO_CH1   = (uint32)(cnt & 7u))
#define ADC1_Ch2_Lo_Cnt_Set(cnt)  (ADC1->CNT0_3_LOWER.bit.CNT_LO_CH2   = (uint32)(cnt & 7u))
#define ADC1_Ch3_Lo_Cnt_Set(cnt)  (ADC1->CNT0_3_LOWER.bit.CNT_LO_CH3   = (uint32)(cnt & 7u))
#define ADC1_Ch4_Lo_Cnt_Set(cnt)  (ADC1->CNT4_7_LOWER.bit.CNT_LO_CH4   = (uint32)(cnt & 7u))
#define ADC1_Ch5_Lo_Cnt_Set(cnt)  (ADC1->CNT4_7_LOWER.bit.CNT_LO_CH5   = (uint32)(cnt & 7u))
#define ADC1_Ch6_Lo_Cnt_Set(cnt)  (ADC1->CNT4_7_LOWER.bit.CNT_LO_CH6   = (uint32)(cnt & 7u))
#define ADC1_Ch7_Lo_Cnt_Set(cnt)  (ADC1->CNT4_7_LOWER.bit.CNT_LO_CH7   = (uint32)(cnt & 7u))
#define ADC1_Ch8_Lo_Cnt_Set(cnt)  (ADC1->CNT8_11_LOWER.bit.CNT_LO_CH8  = (uint32)(cnt & 7u))
#define ADC1_Ch9_Lo_Cnt_Set(cnt)  (ADC1->CNT8_11_LOWER.bit.CNT_LO_CH9  = (uint32)(cnt & 7u))
#define ADC1_Ch10_Lo_Cnt_Set(cnt) (ADC1->CNT8_11_LOWER.bit.CNT_LO_CH10 = (uint32)(cnt & 7u))
#define ADC1_Ch11_Lo_Cnt_Set(cnt) (ADC1->CNT8_11_LOWER.bit.CNT_LO_CH11 = (uint32)(cnt & 7u))
#if defined(TLE9845QX)
#define ADC1_DU1_Lo_Cnt_Set(cnt)  (ADC1->DCHCNT1_4_LOWER.bit.CNT_LO_DCH1 = (uint32)(cnt & 7u))
#define ADC1_DU2_Lo_Cnt_Set(cnt)  (ADC1->DCHCNT1_4_LOWER.bit.CNT_LO_DCH2 = (uint32)(cnt & 7u))
#define ADC1_DU3_Lo_Cnt_Set(cnt)  (ADC1->DCHCNT1_4_LOWER.bit.CNT_LO_DCH3 = (uint32)(cnt & 7u))
#define ADC1_DU4_Lo_Cnt_Set(cnt)  (ADC1->DCHCNT1_4_LOWER.bit.CNT_LO_DCH4 = (uint32)(cnt & 7u))
#endif

/* ADC1 Upper Counter Trigger Level  */
#define ADC1_Ch0_Up_Cnt_Set(cnt)  (ADC1->CNT0_3_UPPER.bit.CNT_UP_CH0   = (uint32)(cnt & 7u))
#define ADC1_Ch1_Up_Cnt_Set(cnt)  (ADC1->CNT0_3_UPPER.bit.CNT_UP_CH1   = (uint32)(cnt & 7u))
#define ADC1_Ch2_Up_Cnt_Set(cnt)  (ADC1->CNT0_3_UPPER.bit.CNT_UP_CH2   = (uint32)(cnt & 7u))
#define ADC1_Ch3_Up_Cnt_Set(cnt)  (ADC1->CNT0_3_UPPER.bit.CNT_UP_CH3   = (uint32)(cnt & 7u))
#define ADC1_Ch4_Up_Cnt_Set(cnt)  (ADC1->CNT4_7_UPPER.bit.CNT_UP_CH4   = (uint32)(cnt & 7u))
#define ADC1_Ch5_Up_Cnt_Set(cnt)  (ADC1->CNT4_7_UPPER.bit.CNT_UP_CH5   = (uint32)(cnt & 7u))
#define ADC1_Ch6_Up_Cnt_Set(cnt)  (ADC1->CNT4_7_UPPER.bit.CNT_UP_CH6   = (uint32)(cnt & 7u))
#define ADC1_Ch7_Up_Cnt_Set(cnt)  (ADC1->CNT4_7_UPPER.bit.CNT_UP_CH7   = (uint32)(cnt & 7u))
#define ADC1_Ch8_Up_Cnt_Set(cnt)  (ADC1->CNT8_11_UPPER.bit.CNT_UP_CH8  = (uint32)(cnt & 7u))
#define ADC1_Ch9_Up_Cnt_Set(cnt)  (ADC1->CNT8_11_UPPER.bit.CNT_UP_CH9  = (uint32)(cnt & 7u))
#define ADC1_Ch10_Up_Cnt_Set(cnt) (ADC1->CNT8_11_UPPER.bit.CNT_UP_CH10 = (uint32)(cnt & 7u))
#define ADC1_Ch11_Up_Cnt_Set(cnt) (ADC1->CNT8_11_UPPER.bit.CNT_UP_CH11 = (uint32)(cnt & 7u))
#if defined(TLE9845QX)
#define ADC1_DU1_Up_Cnt_Set(cnt)  (ADC1->DCHCNT1_4_UPPER.bit.CNT_UP_DCH1 = (uint32)(cnt & 7u))
#define ADC1_DU2_Up_Cnt_Set(cnt)  (ADC1->DCHCNT1_4_UPPER.bit.CNT_UP_DCH2 = (uint32)(cnt & 7u))
#define ADC1_DU3_Up_Cnt_Set(cnt)  (ADC1->DCHCNT1_4_UPPER.bit.CNT_UP_DCH3 = (uint32)(cnt & 7u))
#define ADC1_DU4_Up_Cnt_Set(cnt)  (ADC1->DCHCNT1_4_UPPER.bit.CNT_UP_DCH4 = (uint32)(cnt & 7u))
#endif


/* ADC1 Interrupt Status Clear Macros */
#define ADC1_VBAT_OV_Int_Clr()   (SCUPM->SYS_SUPPLY_IRQ_CLR.reg = (uint32)1u << 5u)
#define ADC1_VBAT_UV_Int_Clr()   (SCUPM->SYS_SUPPLY_IRQ_CLR.reg = (uint32)1u << 0u)
#define ADC1_VbatSense_Int_Clr() (ADC1->IRQCLR_1.reg = (uint32)(1u << 0u))
#define ADC1_VS_Int_Clr()        (ADC1->IRQCLR_1.reg = (uint32)(1u << 1u))
#define ADC1_MON1_Int_Clr()      (ADC1->IRQCLR_1.reg = (uint32)(1u << 2u))
#define ADC1_MON2_Int_Clr()      (ADC1->IRQCLR_1.reg = (uint32)(1u << 3u))
#define ADC1_MON3_Int_Clr()      (ADC1->IRQCLR_1.reg = (uint32)(1u << 4u))
#define ADC1_MON4_Int_Clr()      (ADC1->IRQCLR_1.reg = (uint32)(1u << 5u))
#define ADC1_MON5_Int_Clr()      (ADC1->IRQCLR_1.reg = (uint32)(1u << 6u))
#define ADC1_P21_Int_Clr()       (ADC1->IRQCLR_1.reg = (uint32)(1u << 7u))
#define ADC1_P22_Int_Clr()       (ADC1->IRQCLR_1.reg = (uint32)(1u << 8u))
#define ADC1_P23_Int_Clr()       (ADC1->IRQCLR_1.reg = (uint32)(1u << 9u))
#define ADC1_P26_Int_Clr()       (ADC1->IRQCLR_1.reg = (uint32)(1u << 10u))
#define ADC1_P27_Int_Clr()       (ADC1->IRQCLR_1.reg = (uint32)(1u << 11u))
#define ADC1_P20_Int_Clr()       (ADC1->IRQCLR_1.reg = (uint32)(1u << 12u))
#define ADC1_EIM_Int_Clr()       (ADC1->IRQCLR_1.reg = (uint32)(1u << 16u))
#define ADC1_ESM_Int_Clr()       (ADC1->IRQCLR_1.reg = (uint32)(1u << 17u))

#define ADC1_VS_Lo_Int_Clr()     (ADC1->IRQCLR_2.reg = (uint32)(1u << 1u))
#define ADC1_MON1_Lo_Int_Clr()   (ADC1->IRQCLR_2.reg = (uint32)(1u << 2u))
#define ADC1_MON2_Lo_Int_Clr()   (ADC1->IRQCLR_2.reg = (uint32)(1u << 3u))
#define ADC1_MON3_Lo_Int_Clr()   (ADC1->IRQCLR_2.reg = (uint32)(1u << 4u))
#define ADC1_MON4_Lo_Int_Clr()   (ADC1->IRQCLR_2.reg = (uint32)(1u << 5u))
#define ADC1_MON5_Lo_Int_Clr()   (ADC1->IRQCLR_2.reg = (uint32)(1u << 6u))
#define ADC1_P21_Lo_Int_Clr()    (ADC1->IRQCLR_2.reg = (uint32)(1u << 7u))
#define ADC1_P22_Lo_Int_Clr()    (ADC1->IRQCLR_2.reg = (uint32)(1u << 8u))
#define ADC1_P23_Lo_Int_Clr()    (ADC1->IRQCLR_2.reg = (uint32)(1u << 9u))
#define ADC1_P26_Lo_Int_Clr()    (ADC1->IRQCLR_2.reg = (uint32)(1u << 10u))
#define ADC1_P27_Lo_Int_Clr()    (ADC1->IRQCLR_2.reg = (uint32)(1u << 11u))

#define ADC1_VS_Up_Int_Clr()     (ADC1->IRQCLR_2.reg = (uint32)(1u << 17u))
#define ADC1_MON1_Up_Int_Clr()   (ADC1->IRQCLR_2.reg = (uint32)(1u << 18u))
#define ADC1_MON2_Up_Int_Clr()   (ADC1->IRQCLR_2.reg = (uint32)(1u << 19u))
#define ADC1_MON3_Up_Int_Clr()   (ADC1->IRQCLR_2.reg = (uint32)(1u << 20u))
#define ADC1_MON4_Up_Int_Clr()   (ADC1->IRQCLR_2.reg = (uint32)(1u << 21u))
#define ADC1_MON5_Up_Int_Clr()   (ADC1->IRQCLR_2.reg = (uint32)(1u << 22u))
#define ADC1_P21_Up_Int_Clr()    (ADC1->IRQCLR_2.reg = (uint32)(1u << 23u))
#define ADC1_P22_Up_Int_Clr()    (ADC1->IRQCLR_2.reg = (uint32)(1u << 24u))
#define ADC1_P23_Up_Int_Clr()    (ADC1->IRQCLR_2.reg = (uint32)(1u << 25u))
#define ADC1_P26_Up_Int_Clr()    (ADC1->IRQCLR_2.reg = (uint32)(1u << 26u))
#define ADC1_P27_Up_Int_Clr()    (ADC1->IRQCLR_2.reg = (uint32)(1u << 27u))

#if defined(TLE9845QX)
#define ADC1_DU1_Lo_Int_Clr()   (ADC1->IRQCLR_1.reg = (uint32)(1u << 24u))
#define ADC1_DU1_Up_Int_Clr()   (ADC1->IRQCLR_1.reg = (uint32)(1u << 25u))
#define ADC1_DU2_Lo_Int_Clr()   (ADC1->IRQCLR_1.reg = (uint32)(1u << 26u))
#define ADC1_DU2_Up_Int_Clr()   (ADC1->IRQCLR_1.reg = (uint32)(1u << 27u))
#define ADC1_DU3_Lo_Int_Clr()   (ADC1->IRQCLR_1.reg = (uint32)(1u << 28u))
#define ADC1_DU3_Up_Int_Clr()   (ADC1->IRQCLR_1.reg = (uint32)(1u << 29u))
#define ADC1_DU4_Lo_Int_Clr()   (ADC1->IRQCLR_1.reg = (uint32)(1u << 30u))
#define ADC1_DU4_Up_Int_Clr()   (ADC1->IRQCLR_1.reg = (uint32)(1u << 31u))
#endif

/* ADC1 Interrupt Enable Macros (ADC1_IRQEN_1) */
#define ADC1_VBatSense_Int_En()(ADC1->IRQEN_1.bit.VBATSEN_IEN = 1u)
#define ADC1_VS_Int_En()       (ADC1->IRQEN_1.bit.VS_IEN   = 1u)
#define ADC1_MON1_Int_En()     (ADC1->IRQEN_1.bit.MON1_IEN = 1u)
#define ADC1_MON2_Int_En()     (ADC1->IRQEN_1.bit.MON2_IEN = 1u)
#define ADC1_MON3_Int_En()     (ADC1->IRQEN_1.bit.MON3_IEN = 1u)
#define ADC1_MON4_Int_En()     (ADC1->IRQEN_1.bit.MON4_IEN = 1u)
#define ADC1_MON5_Int_En()     (ADC1->IRQEN_1.bit.MON5_IEN = 1u)
#define ADC1_P21_Int_En()      (ADC1->IRQEN_1.bit.P2_1_IEN = 1u)
#define ADC1_P22_Int_En()      (ADC1->IRQEN_1.bit.P2_2_IEN = 1u)
#define ADC1_P23_Int_En()      (ADC1->IRQEN_1.bit.P2_3_IEN = 1u)
#define ADC1_P26_Int_En()      (ADC1->IRQEN_1.bit.P2_6_IEN = 1u)
#define ADC1_P27_Int_En()      (ADC1->IRQEN_1.bit.P2_7_IEN = 1u)
#define ADC1_P20_Int_En()      (ADC1->IRQEN_1.bit.P2_0_IEN = 1u)
#define ADC1_EIM_Int_En()      (ADC1->IRQEN_1.bit.EIM_IEN  = 1u)
#define ADC1_ESM_Int_En()      (ADC1->IRQEN_1.bit.ESM_IEN  = 1u)
#if defined(TLE9845QX)
#define ADC1_DU1_Lo_Int_En()   (ADC1->IRQEN_1.bit.DU1LO_IEN = 1u)
#define ADC1_DU1_Up_Int_En()   (ADC1->IRQEN_1.bit.DU1UP_IEN = 1u)
#define ADC1_DU2_Lo_Int_En()   (ADC1->IRQEN_1.bit.DU2LO_IEN = 1u)
#define ADC1_DU2_Up_Int_En()   (ADC1->IRQEN_1.bit.DU2UP_IEN = 1u)
#define ADC1_DU3_Lo_Int_En()   (ADC1->IRQEN_1.bit.DU3LO_IEN = 1u)
#define ADC1_DU3_Up_Int_En()   (ADC1->IRQEN_1.bit.DU3UP_IEN = 1u)
#define ADC1_DU4_Lo_Int_En()   (ADC1->IRQEN_1.bit.DU4LO_IEN = 1u)
#define ADC1_DU4_Up_Int_En()   (ADC1->IRQEN_1.bit.DU4UP_IEN = 1u)
#endif

/* ADC1 Interrupt Disable Macros (ADC1_IRQEN_1) */
#define ADC1_VbatSense_Int_Dis()(ADC1->IRQEN_1.bit.VBATSEN_IEN = 0u)
#define ADC1_VS_Int_Dis()      (ADC1->IRQEN_1.bit.VS_IEN   = 0u)
#define ADC1_MON1_Int_Dis()    (ADC1->IRQEN_1.bit.MON1_IEN = 0u)
#define ADC1_MON2_Int_Dis()    (ADC1->IRQEN_1.bit.MON2_IEN = 0u)
#define ADC1_MON3_Int_Dis()    (ADC1->IRQEN_1.bit.MON3_IEN = 0u)
#define ADC1_MON4_Int_Dis()    (ADC1->IRQEN_1.bit.MON4_IEN = 0u)
#define ADC1_MON5_Int_Dis()    (ADC1->IRQEN_1.bit.MON5_IEN = 0u)
#define ADC1_P21_Int_Dis()     (ADC1->IRQEN_1.bit.P2_1_IEN = 0u)
#define ADC1_P22_Int_Dis()     (ADC1->IRQEN_1.bit.P2_2_IEN = 0u)
#define ADC1_P23_Int_Dis()     (ADC1->IRQEN_1.bit.P2_3_IEN = 0u)
#define ADC1_P26_Int_Dis()     (ADC1->IRQEN_1.bit.P2_6_IEN = 0u)
#define ADC1_P27_Int_Dis()     (ADC1->IRQEN_1.bit.P2_7_IEN = 0u)
#define ADC1_P20_Int_Dis()     (ADC1->IRQEN_1.bit.P2_0_IEN = 0u)
#define ADC1_EIM_Int_Dis()     (ADC1->IRQEN_1.bit.EIM_IEN  = 0u)
#define ADC1_ESM_Int_Dis()     (ADC1->IRQEN_1.bit.ESM_IEN  = 0u)
#if defined(TLE9845QX)         
#define ADC1_DU1_Lo_Int_Dis()  (ADC1->IRQEN_1.bit.DU1LO_IEN = 0u)
#define ADC1_DU1_Up_Int_Dis()  (ADC1->IRQEN_1.bit.DU1UP_IEN = 0u)
#define ADC1_DU2_Lo_Int_Dis()  (ADC1->IRQEN_1.bit.DU2LO_IEN = 0u)
#define ADC1_DU2_Up_Int_Dis()  (ADC1->IRQEN_1.bit.DU2UP_IEN = 0u)
#define ADC1_DU3_Lo_Int_Dis()  (ADC1->IRQEN_1.bit.DU3LO_IEN = 0u)
#define ADC1_DU3_Up_Int_Dis()  (ADC1->IRQEN_1.bit.DU3UP_IEN = 0u)
#define ADC1_DU4_Lo_Int_Dis()  (ADC1->IRQEN_1.bit.DU4LO_IEN = 0u)
#define ADC1_DU4_Up_Int_Dis()  (ADC1->IRQEN_1.bit.DU4UP_IEN = 0u)
#endif

/* ADC1 Threshold Interrupt Enable Macros (ADC1_IRQEN_2) */
#define ADC1_VS_Lo_Int_En()    (ADC1->IRQEN_2.bit.VS_LO_IEN    = 1u)
#define ADC1_MON1_Lo_Int_En()  (ADC1->IRQEN_2.bit.MON1_LO_IEN  = 1u)
#define ADC1_MON2_Lo_Int_En()  (ADC1->IRQEN_2.bit.MON2_LO_IEN  = 1u)
#define ADC1_MON3_Lo_Int_En()  (ADC1->IRQEN_2.bit.MON3_LO_IEN  = 1u)
#define ADC1_MON4_Lo_Int_En()  (ADC1->IRQEN_2.bit.MON4_LO_IEN  = 1u)
#define ADC1_MON5_Lo_Int_En()  (ADC1->IRQEN_2.bit.MON5_LO_IEN  = 1u)
#define ADC1_P21_Lo_Int_En()   (ADC1->IRQEN_2.bit.P2_1_LO_IEN  = 1u)
#define ADC1_P22_Lo_Int_En()   (ADC1->IRQEN_2.bit.P2_2_LO_IEN  = 1u)
#define ADC1_P23_Lo_Int_En()   (ADC1->IRQEN_2.bit.P2_3_LO_IEN  = 1u)
#define ADC1_P26_Lo_Int_En()   (ADC1->IRQEN_2.bit.P2_6_LO_IEN  = 1u)
#define ADC1_P27_Lo_Int_En()   (ADC1->IRQEN_2.bit.P2_7_LO_IEN  = 1u)
#define ADC1_VS_Up_Int_En()    (ADC1->IRQEN_2.bit.VS_UP_IEN    = 1u)
#define ADC1_MON1_Up_Int_En()  (ADC1->IRQEN_2.bit.MON1_UP_IEN  = 1u)
#define ADC1_MON2_Up_Int_En()  (ADC1->IRQEN_2.bit.MON2_UP_IEN  = 1u)
#define ADC1_MON3_Up_Int_En()  (ADC1->IRQEN_2.bit.MON3_UP_IEN  = 1u)
#define ADC1_MON4_Up_Int_En()  (ADC1->IRQEN_2.bit.MON4_UP_IEN  = 1u)
#define ADC1_MON5_Up_Int_En()  (ADC1->IRQEN_2.bit.MON5_UP_IEN  = 1u)
#define ADC1_P21_Up_Int_En()   (ADC1->IRQEN_2.bit.P2_1_UP_IEN  = 1u)
#define ADC1_P22_Up_Int_En()   (ADC1->IRQEN_2.bit.P2_2_UP_IEN  = 1u)
#define ADC1_P23_Up_Int_En()   (ADC1->IRQEN_2.bit.P2_3_UP_IEN  = 1u)
#define ADC1_P26_Up_Int_En()   (ADC1->IRQEN_2.bit.P2_6_UP_IEN  = 1u)
#define ADC1_P27_Up_Int_En()   (ADC1->IRQEN_2.bit.P2_7_UP_IEN  = 1u)

/* ADC1 Threshold Interrupt Disable Macros (ADC1_IRQEN_2) */
#define ADC1_VS_Lo_Int_Dis()   (ADC1->IRQEN_2.bit.VS_LO_IEN    = 0u)
#define ADC1_MON1_Lo_Int_Dis() (ADC1->IRQEN_2.bit.MON1_LO_IEN  = 0u)
#define ADC1_MON2_Lo_Int_Dis() (ADC1->IRQEN_2.bit.MON2_LO_IEN  = 0u)
#define ADC1_MON3_Lo_Int_Dis() (ADC1->IRQEN_2.bit.MON3_LO_IEN  = 0u)
#define ADC1_MON4_Lo_Int_Dis() (ADC1->IRQEN_2.bit.MON4_LO_IEN  = 0u)
#define ADC1_MON5_Lo_Int_Dis() (ADC1->IRQEN_2.bit.MON5_LO_IEN  = 0u)
#define ADC1_P21_Lo_Int_Dis()  (ADC1->IRQEN_2.bit.P2_1_LO_IEN  = 0u)
#define ADC1_P22_Lo_Int_Dis()  (ADC1->IRQEN_2.bit.P2_2_LO_IEN  = 0u)
#define ADC1_P23_Lo_Int_Dis()  (ADC1->IRQEN_2.bit.P2_3_LO_IEN  = 0u)
#define ADC1_P26_Lo_Int_Dis()  (ADC1->IRQEN_2.bit.P2_6_LO_IEN  = 0u)
#define ADC1_P27_Lo_Int_Dis()  (ADC1->IRQEN_2.bit.P2_7_LO_IEN  = 0u)
#define ADC1_VS_Up_Int_Dis()   (ADC1->IRQEN_2.bit.VS_UP_IEN    = 0u)
#define ADC1_MON1_Up_Int_Dis() (ADC1->IRQEN_2.bit.MON1_UP_IEN  = 0u)
#define ADC1_MON2_Up_Int_Dis() (ADC1->IRQEN_2.bit.MON2_UP_IEN  = 0u)
#define ADC1_MON3_Up_Int_Dis() (ADC1->IRQEN_2.bit.MON3_UP_IEN  = 0u)
#define ADC1_MON4_Up_Int_Dis() (ADC1->IRQEN_2.bit.MON4_UP_IEN  = 0u)
#define ADC1_MON5_Up_Int_Dis() (ADC1->IRQEN_2.bit.MON5_UP_IEN  = 0u)
#define ADC1_P21_Up_Int_Dis()  (ADC1->IRQEN_2.bit.P2_1_UP_IEN  = 0u)
#define ADC1_P22_Up_Int_Dis()  (ADC1->IRQEN_2.bit.P2_2_UP_IEN  = 0u)
#define ADC1_P23_Up_Int_Dis()  (ADC1->IRQEN_2.bit.P2_3_UP_IEN  = 0u)
#define ADC1_P26_Up_Int_Dis()  (ADC1->IRQEN_2.bit.P2_6_UP_IEN  = 0u)
#define ADC1_P27_Up_Int_Dis()  (ADC1->IRQEN_2.bit.P2_7_UP_IEN  = 0u)


/*******************************************************************************
**                      Global Function Declarations                          **
*******************************************************************************/
void ADC1_Init(void);
bool ADC1_GetChResult(uint16 * pVar, uint8 channel);
bool ADC1_GetChResult_mV(uint16 * pVar_mV, uint8 channel);
bool ADC1_GetEIMResult(uint16 * pVar);
bool ADC1_GetEIMResult_mV(uint16 * pVar_mV);
bool ADC1_GetSwModeResult(uint16 * pVar);
bool ADC1_GetSwModeResult_mV(uint16 * pVar_mV);
/* Inline functions ***********************************************************/
__STATIC_INLINE void ADC1_SetEIMChannel(uint8 channel);
__STATIC_INLINE void ADC1_SetSwMode_Channel(uint8 channel);
__STATIC_INLINE void ADC1_SetSeqMode(void);
__STATIC_INLINE void ADC1_SetSwMode(void);
__STATIC_INLINE void ADC1_SetSocSwMode(uint8 channel);
__STATIC_INLINE bool ADC1_GetEocSwMode(void);

/*******************************************************************************
**                      Global Inline Function Definitions                    **
*******************************************************************************/
/** \brief Set(Change) ADC1 EIM channel
 *
 * \param[in] ADC1 EIM mode channel
 * \return void
 *
 * \ingroup adc1_api
 */
__STATIC_INLINE void ADC1_SetEIMChannel(uint8 channel)
{
  ADC1->CHx_EIM.bit.EIM_CHx = channel;
}                               /* End of ADC1_SetEIMChannel */


/** \brief Set(Change) ADC1 SW_MODE channel
 *
 * \param[in] ADC1 SW mode channel
 * \return void
 *
 * \ingroup adc1_api
 */
__STATIC_INLINE void ADC1_SetSwMode_Channel(uint8 channel)
{
  ADC1->CTRL_STS.bit.SW_CH_SEL = channel;
}                               /* End of ADC1_SetSwMode_Channel */


/** \brief ADC1 Set Sequencer Mode
 *
 * \param[in] void
 * \return void
 *
 * \ingroup adc1_api
 */
__STATIC_INLINE void ADC1_SetSeqMode(void)
{
  ADC1->CTRL3.bit.SW_MODE = 0;
  while (ADC1->SQ_FB.bit.SQ_STOP)
  {
  }
}                               /* End of ADC1_SetSeqMode */ 


/** \brief ADC1 Set Software Mode
 *
 * \param[in] void
 * \return void
 *
 * \ingroup adc1_api
 */
__STATIC_INLINE void ADC1_SetSwMode(void)
{
  ADC1->CTRL3.bit.SW_MODE = 1;
  while (!ADC1->SQ_FB.bit.SQ_STOP)
  {
  }
}                              /* End of ADC1_SetSwMode */ 






/** \brief Start ADC1 SW_MODE conversion
 *
 * \param[in] channel
 * \return void
 *
 * \ingroup adc1_api
 */
__STATIC_INLINE void ADC1_SetSocSwMode(uint8 channel)
{
  ADC1->CTRL_STS.bit.SW_CH_SEL = channel;
  ADC1->CTRL_STS.bit.SOS = 1;
}                               /* End of ADC1_SetSocSwMode */


/** \brief Get ADC1 SW_MODE EOC(end of conversion)
 *
 * \param[in] void
 * \return true=conversion ended
 *
 * \ingroup adc1_api
 */
__STATIC_INLINE bool ADC1_GetEocSwMode(void)
{
  return ((bool) (ADC1->CTRL_STS.bit.EOC == 1));
}                               /* End of ADC1_GetEocSwMode */

#endif /* ADC1_H */
