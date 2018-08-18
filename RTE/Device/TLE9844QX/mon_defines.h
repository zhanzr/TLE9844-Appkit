/*sha256=B39C6E12A9F1289862EA5D3700BCC319FCB7D56C8EEC9725CF093BC1EE11DFAF*/
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

#ifndef _MON_DEFINES_H
#define _MON_DEFINES_H

#ifndef IFXConfigWizard_Version
  #define IFXConfigWizard_Version 1.8.7
#endif

/* XML Version 1.2.1 */
#ifndef MON_XML_VERSION
  #define MON_XML_VERSION 10201
#endif

/*MON_CNF14: 1|(1<<2)|(1<<1)|(0<<5)|(0<<4)|(0<<3)|(1<<8)|(1<<10)|(1<<9)|(0<<13)\
|(0<<12)|(0<<11)|(1<<16)|(1<<18)|(1<<17)|(0<<21)|(0<<20)|(0<<19)|(1<<24)|(1<<26\
)|(1<<25)|(0<<29)|(0<<28)|(0<<27)*/
#ifndef MON_CNF14
  #define MON_CNF14 (0x7070707u)
#endif

/*MON_CNF5: 0|(1<<2)|(1<<1)|(0<<5)|(0<<4)|(0<<3)*/
#ifndef MON_CNF5
  #define MON_CNF5 (0x6u)
#endif


#endif
