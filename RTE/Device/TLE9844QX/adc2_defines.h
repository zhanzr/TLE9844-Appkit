/*sha256=F8156CCEA991E11DB47ED708C5D8B2F2DD87B8D8F3EA2890A5F0A5C5EE8058E9*/
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

#ifndef _ADC2_DEFINES_H
#define _ADC2_DEFINES_H

#ifndef IFXConfigWizard_Version
  #define IFXConfigWizard_Version 1.8.7
#endif

/* XML Version 1.2.2 */
#ifndef ADC2_XML_VERSION
  #define ADC2_XML_VERSION 10202
#endif

#ifndef ADC2_CH0_LOTH_VOLT
  #define ADC2_CH0_LOTH_VOLT 4.6
#endif

#ifndef ADC2_CH0_UPTH_VOLT
  #define ADC2_CH0_UPTH_VOLT 28.2
#endif

#ifndef ADC2_CH1_LOTH_VOLT
  #define ADC2_CH1_LOTH_VOLT 4.51
#endif

#ifndef ADC2_CH1_UPTH_VOLT
  #define ADC2_CH1_UPTH_VOLT 5.5
#endif

#ifndef ADC2_CH2_LOTH_VOLT
  #define ADC2_CH2_LOTH_VOLT 2.64
#endif

#ifndef ADC2_CH2_UPTH_VOLT
  #define ADC2_CH2_UPTH_VOLT 5.5
#endif

#ifndef ADC2_CH3_LOTH_VOLT
  #define ADC2_CH3_LOTH_VOLT 1.001
#endif

#ifndef ADC2_CH3_UPTH_VOLT
  #define ADC2_CH3_UPTH_VOLT 1.5
#endif

#ifndef ADC2_CH4_LOTH_VOLT
  #define ADC2_CH4_LOTH_VOLT 1.355
#endif

#ifndef ADC2_CH4_UPTH_VOLT
  #define ADC2_CH4_UPTH_VOLT 1.6
#endif

#ifndef ADC2_CH5_LOTH_DEG
  #define ADC2_CH5_LOTH_DEG 152
#endif

#ifndef ADC2_CH5_UPTH_DEG
  #define ADC2_CH5_UPTH_DEG 182
#endif

#ifndef ADC2_CH6_LOTH_DEG
  #define ADC2_CH6_LOTH_DEG 128
#endif

#ifndef ADC2_CH6_UPTH_DEG
  #define ADC2_CH6_UPTH_DEG 182
#endif

#ifndef ADC2_CLK
  #define ADC2_CLK 20
#endif

/*ADC2_CTRL2: 1|(4<<8)*/
#ifndef ADC2_CTRL2
  #define ADC2_CTRL2 (0x401u)
#endif

/*ADC2_CTRL4: 1|(1<<1)|(1<<2)|(1<<3)|(1<<4)|(1<<5)|(1<<6)*/
#ifndef ADC2_CTRL4
  #define ADC2_CTRL4 (0x7Fu)
#endif

/*ADC2_FILT_LO_CTRL: 1|(1<<1)|(1<<2)|(1<<3)|(1<<4)|(1<<5)|(1<<6)*/
#ifndef ADC2_FILT_LO_CTRL
  #define ADC2_FILT_LO_CTRL (0x7Fu)
#endif

/*ADC2_FILT_UP_CTRL: 1|(1<<1)|(1<<2)|(1<<3)|(1<<4)|(1<<5)|(1<<6)*/
#ifndef ADC2_FILT_UP_CTRL
  #define ADC2_FILT_UP_CTRL (0x7Fu)
#endif

/*ADC2_TH0_3_LOWER: 37|(191<<8)|(111<<16)|(157<<24)*/
#ifndef ADC2_TH0_3_LOWER
  #define ADC2_TH0_3_LOWER (0x9D6FBF25u)
#endif

/*ADC2_TH0_3_UPPER: 228|(233<<8)|(233<<16)|(235<<24)*/
#ifndef ADC2_TH0_3_UPPER
  #define ADC2_TH0_3_UPPER (0xEBE9E9E4u)
#endif

/*ADC2_TH4_7_LOWER: 212|(212<<8)|(200<<16)*/
#ifndef ADC2_TH4_7_LOWER
  #define ADC2_TH4_7_LOWER (0xC8D4D4u)
#endif

/*ADC2_TH4_7_UPPER: 251|(226<<8)|(226<<16)*/
#ifndef ADC2_TH4_7_UPPER
  #define ADC2_TH4_7_UPPER (0xE2E2FBu)
#endif


#endif
