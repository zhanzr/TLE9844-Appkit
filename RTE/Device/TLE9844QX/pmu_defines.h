/*sha256=8116EAEAD95A6326B0354599959B3ED3F044E9EBD448ED892CA5C55D0FEDA608*/
/**
 * @cond
 ***********************************************************************************************************************
 *
 * Copyright (c) 2015, Infineon Technologies AG
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

/*------------------------------------------------------------------------------
IFXConfigWizard output file
created on:Sat Aug 11 16:06:45 2018
------------------------------------------------------------------------------*/

#ifndef _PMU_DEFINES_H
#define _PMU_DEFINES_H

#ifndef IFXConfigWizard_Version
  #define IFXConfigWizard_Version 1.8.7
#endif

/* XML Version 1.2.2 */
#ifndef PMU_XML_VERSION
  #define PMU_XML_VERSION 10202
#endif

/*PMU_CNF_RST_TFB: 3*/
#ifndef PMU_CNF_RST_TFB
  #define PMU_CNF_RST_TFB (0x3u)
#endif

/*PMU_CNF_WAKE_FILTER: 0|(0<<1)|(2<<2)*/
#ifndef PMU_CNF_WAKE_FILTER
  #define PMU_CNF_WAKE_FILTER (0x8u)
#endif

#ifndef PMU_CYC_SENSE_ACT_TIME
  #define PMU_CYC_SENSE_ACT_TIME 10
#endif

#ifndef PMU_CYC_SENSE_EFF_SLP_TIME
  #define PMU_CYC_SENSE_EFF_SLP_TIME 2
#endif

#ifndef PMU_CYC_SENSE_SLP_TIME
  #define PMU_CYC_SENSE_SLP_TIME 2
#endif

#ifndef PMU_CYC_WAKE_EFF_TIME
  #define PMU_CYC_WAKE_EFF_TIME 2
#endif

#ifndef PMU_CYC_WAKE_TIME
  #define PMU_CYC_WAKE_TIME 2
#endif

/*PMU_LIN_WAKE_EN: (0<<7)*/
#ifndef PMU_LIN_WAKE_EN
  #define PMU_LIN_WAKE_EN (0x0u)
#endif

#ifndef PMU_MON1_CYCLE_SENSE
  #define PMU_MON1_CYCLE_SENSE 0
#endif

#ifndef PMU_MON1_WAKE
  #define PMU_MON1_WAKE 1
#endif

#ifndef PMU_MON1_WAKE_FALL
  #define PMU_MON1_WAKE_FALL 1
#endif

#ifndef PMU_MON1_WAKE_RISE
  #define PMU_MON1_WAKE_RISE 1
#endif

#ifndef PMU_MON2_CYCLE_SENSE
  #define PMU_MON2_CYCLE_SENSE 0
#endif

#ifndef PMU_MON2_WAKE
  #define PMU_MON2_WAKE 1
#endif

#ifndef PMU_MON2_WAKE_FALL
  #define PMU_MON2_WAKE_FALL 1
#endif

#ifndef PMU_MON2_WAKE_RISE
  #define PMU_MON2_WAKE_RISE 1
#endif

#ifndef PMU_MON3_CYCLE_SENSE
  #define PMU_MON3_CYCLE_SENSE 0
#endif

#ifndef PMU_MON3_WAKE
  #define PMU_MON3_WAKE 1
#endif

#ifndef PMU_MON3_WAKE_FALL
  #define PMU_MON3_WAKE_FALL 1
#endif

#ifndef PMU_MON3_WAKE_RISE
  #define PMU_MON3_WAKE_RISE 1
#endif

#ifndef PMU_MON4_CYCLE_SENSE
  #define PMU_MON4_CYCLE_SENSE 0
#endif

#ifndef PMU_MON4_WAKE
  #define PMU_MON4_WAKE 1
#endif

#ifndef PMU_MON4_WAKE_FALL
  #define PMU_MON4_WAKE_FALL 1
#endif

#ifndef PMU_MON4_WAKE_RISE
  #define PMU_MON4_WAKE_RISE 1
#endif

#ifndef PMU_MON5_CYCLE_SENSE
  #define PMU_MON5_CYCLE_SENSE 0
#endif

#ifndef PMU_MON5_WAKE
  #define PMU_MON5_WAKE 0
#endif

#ifndef PMU_MON5_WAKE_FALL
  #define PMU_MON5_WAKE_FALL 1
#endif

#ifndef PMU_MON5_WAKE_RISE
  #define PMU_MON5_WAKE_RISE 1
#endif

#ifndef PMU_PORT0_WAKE
  #define PMU_PORT0_WAKE 0
#endif

#ifndef PMU_PORT1_WAKE
  #define PMU_PORT1_WAKE 0
#endif

#ifndef PMU_SENSE_EFF_SLP_TIME
  #define PMU_SENSE_EFF_SLP_TIME 10
#endif

/*PMU_SLEEP: (0<<2)|(0<<20)|(0<<16)|(0<<3)|(0<<12)|(0<<8)|(0<<24)|(1<<1)|0*/
#ifndef PMU_SLEEP
  #define PMU_SLEEP (0x2u)
#endif

#ifndef PMU_SLEEP_MODE
  #define PMU_SLEEP_MODE 0
#endif

#ifndef PMU_STOP_MODE
  #define PMU_STOP_MODE 0
#endif

/*PMU_SUPPLY_STS: (0<<2)|(0<<6)*/
#ifndef PMU_SUPPLY_STS
  #define PMU_SUPPLY_STS (0x0u)
#endif

#ifndef PMU_VDDC_OL_EN
  #define PMU_VDDC_OL_EN 0
#endif

#ifndef PMU_VDDC_OV_EN
  #define PMU_VDDC_OV_EN 0
#endif

/*PMU_VDDEXT_CTRL: 0|(0<<1)|(0<<2)*/
#ifndef PMU_VDDEXT_CTRL
  #define PMU_VDDEXT_CTRL (0x0u)
#endif

#ifndef PMU_VDDEXT_OT_EN
  #define PMU_VDDEXT_OT_EN 0
#endif

#ifndef PMU_VDDEXT_UV_EN
  #define PMU_VDDEXT_UV_EN 0
#endif

#ifndef PMU_VDDP_OL_EN
  #define PMU_VDDP_OL_EN 0
#endif

#ifndef PMU_VDDP_OV_EN
  #define PMU_VDDP_OV_EN 0
#endif

/*PMU_WAKE_CNF_GPIO0: 0|(0<<8)|(0<<16)|(0<<1)|(0<<9)|(0<<17)|(0<<2)|(0<<10)|(0<\
<18)|(0<<3)|(0<<11)|(0<<19)|(0<<4)|(0<<12)|(0<<20)*/
#ifndef PMU_WAKE_CNF_GPIO0
  #define PMU_WAKE_CNF_GPIO0 (0x0u)
#endif

/*PMU_WAKE_CNF_GPIO1: 0|(0<<8)|(0<<16)|(0<<1)|(0<<9)|(0<<17)|(0<<2)|(0<<10)|(0<\
<18)|(0<<3)|(0<<11)|(0<<19)|(0<<4)|(0<<12)|(0<<20)*/
#ifndef PMU_WAKE_CNF_GPIO1
  #define PMU_WAKE_CNF_GPIO1 (0x0u)
#endif


#endif
