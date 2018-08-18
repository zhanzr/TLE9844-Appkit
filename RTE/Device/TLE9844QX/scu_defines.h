/*sha256=9774B2AFBE6F5B0C909E7881C224FB96450EFA98657F5E32718C75BCF43EBA29*/
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
created on:Sat Aug 11 17:33:58 2018
------------------------------------------------------------------------------*/

#ifndef _SCU_DEFINES_H
#define _SCU_DEFINES_H

#ifndef IFXConfigWizard_Version
  #define IFXConfigWizard_Version 1.8.7
#endif

/* XML Version 1.2.2 */
#ifndef SCU_XML_VERSION
  #define SCU_XML_VERSION 10202
#endif

#ifndef SCUPM_WDT1_PERIOD
  #define SCUPM_WDT1_PERIOD 1008
#endif

#ifndef SCUPM_WDT1_PERIOD_EDIT
  #define SCUPM_WDT1_PERIOD_EDIT 1008
#endif

/*SCUPM_WDT1_TRIG: 63*/
#ifndef SCUPM_WDT1_TRIG
  #define SCUPM_WDT1_TRIG (0x3Fu)
#endif

#ifndef SCUPM_WDT1_TRIGGER
  #define SCUPM_WDT1_TRIGGER 699
#endif

/*SCU_APCLK: 1|(19<<8)*/
#ifndef SCU_APCLK
  #define SCU_APCLK (0x1301u)
#endif

#ifndef SCU_APCLK_FILT_CLK
  #define SCU_APCLK_FILT_CLK 2
#endif

#ifndef SCU_APCLK_MI_CLK
  #define SCU_APCLK_MI_CLK 20
#endif

/*SCU_AUTO_FSYS: 40000000*/
#ifndef SCU_AUTO_FSYS
  #define SCU_AUTO_FSYS (0x2625A00u)
#endif

#ifndef SCU_AUTO_FSYS_SEL
  #define SCU_AUTO_FSYS_SEL 0
#endif

/*SCU_BCON1: (0<<1)|0*/
#ifndef SCU_BCON1
  #define SCU_BCON1 (0x0u)
#endif

/*SCU_BCON2: (0<<1)|1*/
#ifndef SCU_BCON2
  #define SCU_BCON2 (0x1u)
#endif

#ifndef SCU_CKOUT_FREQ
  #define SCU_CKOUT_FREQ 0.5
#endif

/*SCU_CMCON1: (0<<4)|(1<<8)*/
#ifndef SCU_CMCON1
  #define SCU_CMCON1 (0x100u)
#endif

/*SCU_COCON: (0<<7)|15|(1<<5)|(1<<6)|(1<<4)*/
#ifndef SCU_COCON
  #define SCU_COCON (0x7Fu)
#endif

#ifndef SCU_FSYS
  #define SCU_FSYS 4e+07
#endif

/*SCU_GPT12PISEL: 0*/
#ifndef SCU_GPT12PISEL
  #define SCU_GPT12PISEL (0x0u)
#endif

/*SCU_IEN0: (0<<31)*/
#ifndef SCU_IEN0
  #define SCU_IEN0 (0x0u)
#endif

/*SCU_MODPISEL: (0<<16)|2|(0<<2)|(0<<4)|(0<<7)|(0<<6)*/
#ifndef SCU_MODPISEL
  #define SCU_MODPISEL (0x2u)
#endif

/*SCU_MODPISEL1: (0<<6)|(1<<7)*/
#ifndef SCU_MODPISEL1
  #define SCU_MODPISEL1 (0x80u)
#endif

/*SCU_MODPISEL2: 1|(0<<4)|(0<<2)|(0<<6)*/
#ifndef SCU_MODPISEL2
  #define SCU_MODPISEL2 (0x1u)
#endif

#ifndef SCU_NVM_BOOT_PROT
  #define SCU_NVM_BOOT_PROT 0
#endif

#ifndef SCU_NVM_CODE_PROT
  #define SCU_NVM_CODE_PROT 0
#endif

#ifndef SCU_NVM_DATA_PROT
  #define SCU_NVM_DATA_PROT 0
#endif

/*SCU_NVM_PROT_PW: 0*/
#ifndef SCU_NVM_PROT_PW
  #define SCU_NVM_PROT_PW (0x0u)
#endif

/*SCU_OSC_CON: 16*/
#ifndef SCU_OSC_CON
  #define SCU_OSC_CON (0x10u)
#endif

#ifndef SCU_PINSEL
  #define SCU_PINSEL 0
#endif

/*SCU_PLL_CON: (10<<4)*/
#ifndef SCU_PLL_CON
  #define SCU_PLL_CON (0xA0u)
#endif

#ifndef SCU_PLL_fPLL
  #define SCU_PLL_fPLL 40
#endif

#ifndef SCU_XTAL_EN
  #define SCU_XTAL_EN 0
#endif

#ifndef SCU_XTAL_FREQ
  #define SCU_XTAL_FREQ 5
#endif


#endif
