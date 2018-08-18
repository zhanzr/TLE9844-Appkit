/*sha256=103BD9E21A2A5BE9A49BEA84CCF153380FAED5E48EEB93525BA07CAF7BCF760F*/
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

#ifndef _INT_DEFINES_H
#define _INT_DEFINES_H

#ifndef IFXConfigWizard_Version
  #define IFXConfigWizard_Version 1.8.7
#endif

/* XML Version 1.2.2 */
#ifndef INT_XML_VERSION
  #define INT_XML_VERSION 10202
#endif

#ifndef CPU_HARDFAULT_EN
  #define CPU_HARDFAULT_EN 0
#endif

/*CPU_NVIC_IPR0: (0<<6)|(0<<14)|(0<<22)|(0<<30)*/
#ifndef CPU_NVIC_IPR0
  #define CPU_NVIC_IPR0 (0x0u)
#endif

/*CPU_NVIC_IPR1: (0<<6)|(0<<14)|(0<<22)|(0<<30)*/
#ifndef CPU_NVIC_IPR1
  #define CPU_NVIC_IPR1 (0x0u)
#endif

/*CPU_NVIC_IPR2: (0<<6)|(0<<14)|(0<<22)|(0<<30)*/
#ifndef CPU_NVIC_IPR2
  #define CPU_NVIC_IPR2 (0x0u)
#endif

/*CPU_NVIC_IPR3: (0<<6)|(0<<14)|(0<<22)*/
#ifndef CPU_NVIC_IPR3
  #define CPU_NVIC_IPR3 (0x0u)
#endif

/*CPU_NVIC_IPR4: (0<<14)|(0<<22)|(0<<30)*/
#ifndef CPU_NVIC_IPR4
  #define CPU_NVIC_IPR4 (0x0u)
#endif

/*CPU_NVIC_IPR5: (0<<6)|(0<<14)|(0<<22)|(0<<30)*/
#ifndef CPU_NVIC_IPR5
  #define CPU_NVIC_IPR5 (0x0u)
#endif

/*CPU_NVIC_ISER: 0|(0<<1)|(0<<2)|(0<<3)|(0<<4)|(0<<5)|(0<<6)|(0<<7)|(0<<8)|(0<<\
9)|(0<<10)|(0<<11)|(0<<12)|(0<<13)|(0<<14)|(0<<17)|(0<<18)|(0<<19)|(0<<20)|(0<<\
21)|(0<<22)|(0<<23)*/
#ifndef CPU_NVIC_ISER
  #define CPU_NVIC_ISER (0x0u)
#endif

#ifndef CPU_SYSTICK_EN
  #define CPU_SYSTICK_EN 1
#endif

/*SCUPM_SYS_IRQ_CTRL: (0<<11)|(0<<10)|(0<<9)|(0<<8)*/
#ifndef SCUPM_SYS_IRQ_CTRL
  #define SCUPM_SYS_IRQ_CTRL (0x0u)
#endif

/*SCUPM_SYS_SUPPLY_IRQ_CTRL: (0<<6)|(0<<1)|(0<<9)|(0<<4)|(0<<7)|(0<<2)|(0<<8)|(\
0<<3)|(0<<5)|0*/
#ifndef SCUPM_SYS_SUPPLY_IRQ_CTRL
  #define SCUPM_SYS_SUPPLY_IRQ_CTRL (0x0u)
#endif

/*SCU_EDCCON: 0|(0<<2)*/
#ifndef SCU_EDCCON
  #define SCU_EDCCON (0x0u)
#endif

/*SCU_EXICON0: 0|(0<<1)|(0<<2)|(0<<3)|(1<<4)|(1<<5)*/
#ifndef SCU_EXICON0
  #define SCU_EXICON0 (0x30u)
#endif

/*SCU_EXICON1: 0|(0<<1)|(0<<2)|(0<<3)|(1<<4)|(1<<5)|(0<<6)|(0<<7)|(0<<8)|(0<<9)\
*/
#ifndef SCU_EXICON1
  #define SCU_EXICON1 (0x30u)
#endif

/*SCU_GPT12IEN: 0|(0<<1)|(0<<2)|(0<<3)|(0<<5)|(0<<4)*/
#ifndef SCU_GPT12IEN
  #define SCU_GPT12IEN (0x0u)
#endif

/*SCU_MODIEN1: (0<<2)|(0<<1)|0|(0<<10)|(0<<9)|(0<<8)*/
#ifndef SCU_MODIEN1
  #define SCU_MODIEN1 (0x0u)
#endif

/*SCU_MODIEN2: (0<<5)|0|(0<<1)|(0<<6)|(0<<7)*/
#ifndef SCU_MODIEN2
  #define SCU_MODIEN2 (0x0u)
#endif

/*SCU_MODIEN3: 0*/
#ifndef SCU_MODIEN3
  #define SCU_MODIEN3 (0x0u)
#endif

/*SCU_MODIEN4: 0*/
#ifndef SCU_MODIEN4
  #define SCU_MODIEN4 (0x0u)
#endif

/*SCU_NMICON: (0<<1)|(0<<2)|(0<<3)|(0<<4)|(0<<5)|(0<<6)|(0<<7)*/
#ifndef SCU_NMICON
  #define SCU_NMICON (0x0u)
#endif

/*SCU_WAKECON: 0*/
#ifndef SCU_WAKECON
  #define SCU_WAKECON (0x0u)
#endif


#endif
