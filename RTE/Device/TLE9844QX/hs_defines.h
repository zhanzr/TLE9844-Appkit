/*sha256=BA574FC3C17175A687F1D9C45C09D0EBCEBC4C74E6ECDB840D2FB3A4584C4C96*/
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
created on:Mi Jan 10 11:11:11 2018
------------------------------------------------------------------------------*/

#ifndef _HS_DEFINES_H
#define _HS_DEFINES_H

#ifndef IFXConfigWizard_Version
  #define IFXConfigWizard_Version 1.8.7
#endif

/* XML Version 1.2.1 */
#ifndef HS_XML_VERSION
  #define HS_XML_VERSION 10201
#endif

/*HS_CTRL: 0|(0<<12)|(0<<8)|(0<<7)|(0<<3)|(0<<2)|(0<<1)|(0<<16)|(0<<28)|(0<<24)\
|(0<<23)|(0<<19)|(0<<18)|(0<<17)*/
#ifndef HS_CTRL
  #define HS_CTRL (0x0u)
#endif

/*HS_HS1_TRIM: (3<<8)|3*/
#ifndef HS_HS1_TRIM
  #define HS_HS1_TRIM (0x303u)
#endif

/*HS_HS2_TRIM: (3<<8)|3*/
#ifndef HS_HS2_TRIM
  #define HS_HS2_TRIM (0x303u)
#endif

/*HS_IRQEN: (0<<7)|(0<<6)|(0<<5)|(0<<23)|(0<<22)|(0<<21)*/
#ifndef HS_IRQEN
  #define HS_IRQEN (0x0u)
#endif

/*HS_PWMSRCSEL: (0<<3)|0*/
#ifndef HS_PWMSRCSEL
  #define HS_PWMSRCSEL (0x0u)
#endif


#endif
