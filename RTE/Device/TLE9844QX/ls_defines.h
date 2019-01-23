/*sha256=A433574A0423BB2361DC213CC152B862E48D5E436D9C0453486C8E93536B4FF4*/
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

#ifndef _LS_DEFINES_H
#define _LS_DEFINES_H

#ifndef IFXConfigWizard_Version
  #define IFXConfigWizard_Version 1.8.7
#endif

/* XML Version 1.2.2 */
#ifndef LS_XML_VERSION
  #define LS_XML_VERSION 10202
#endif

/*LS_CTRL: 1|(0<<8)|(0<<3)|(0<<2)|(0<<1)|(1<<16)|(0<<24)|(0<<19)|(0<<18)|(0<<17\
)*/
#ifndef LS_CTRL
  #define LS_CTRL (0x10001u)
#endif

/*LS_IRQEN: (0<<7)|(0<<6)|(0<<5)|(0<<23)|(0<<22)|(0<<21)*/
#ifndef LS_IRQEN
  #define LS_IRQEN (0x0u)
#endif

/*LS_LS1_TRIM: (3<<8)|3*/
#ifndef LS_LS1_TRIM
  #define LS_LS1_TRIM (0x303u)
#endif

/*LS_LS2_TRIM: (3<<8)|3*/
#ifndef LS_LS2_TRIM
  #define LS_LS2_TRIM (0x303u)
#endif

/*LS_PWMSRCSEL: (0<<3)|0*/
#ifndef LS_PWMSRCSEL
  #define LS_PWMSRCSEL (0x0u)
#endif


#endif
