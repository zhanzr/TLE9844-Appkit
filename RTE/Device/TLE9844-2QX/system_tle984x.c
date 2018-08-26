/******************************************************************************
 * @file:    system_TLE984x.c
 * @purpose: CMSIS Cortex-M0 Device Peripheral Access Layer Source File
 *           for the Infineon TLE984x Device Series 
 * @version: V0.6
 * @date:    28. Jun 2016
 *----------------------------------------------------------------------------
 *
 * Copyright (C) 2008 ARM Limited. All rights reserved.
 *
 * ARM Limited (ARM) is supplying this software for use with Cortex-M0 
 * processor based microcontrollers.  This file can be freely distributed 
 * within development tools that are supporting such ARM based processors. 
 *
 * THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 * OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 * ARM SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, OR
 * CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 *
 ******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/* 
 * V0.1:  8. Oct 2014:   Initial version
 * V0.2: 21. Oct 2014:   editorial changes
 *                       changed syntax for writing to memory
 *                       disabled NAC writing
 * V0.3: 11. Nov 2015:   extended SystemInit(), included epower_defines.h
 * V0.4: 27. Nov 2015:   added SCU_Init() to SystemInit() routine
 * V0.5: 03. May 2016:   definition of BSL parameters adapted
 * V0.6: 28. Jun 2016:   SCU_Init removed from SystemInit()
 * V1.1: 19. Oct 2017:   variable SystemFrequency removed
 *                       version of this file must be greater than V1.0 (pdsc)
 *                       
*/
#include "tle_device.h"
#include "scu.h"
#include "wdt1.h"
#include "bsl_defines.h"

/*----------------------------------------------------------------------------
  Define BSL parameter
 *----------------------------------------------------------------------------*/
#if (NAC_NAD_EN == 1)
/*lint -e950 Suppressing MISRA 2012 Directive 2.1 */ \
const uint32 p_NACNAD  __attribute__((at(NACStart),used)) = (uint32)NAD_NAC;
/*lint +e950 */
#endif

void SystemInit(void)
{
  SCU_ClkInit();
  WDT1_Init();
}
