/******************************************************************************
 * @file:    system_TLE984x.h
 * @purpose: CMSIS Cortex-M0 Device Peripheral Access Layer Header File
 *           for the Infineon TLE984x Device Series 
 * @version: V0.2
 * @date:    21. Oct. 2014
 *----------------------------------------------------------------------------
 *
 * Copyright (C) 2009 ARM Limited. All rights reserved.
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
 * V0.2: 21. Oct 2014:   changed to 20MHz system frequency
 */

#ifndef __SYSTEM_TLE984x_H
#define __SYSTEM_TLE984x_H

#ifdef __cplusplus
 extern "C" {
#endif 

extern unsigned int SystemFrequency;    /*!< System Clock Frequency (Core Clock)  */

/**
 * Initialize the system
 *
 * @param  none
 * @return none
 *
 * @brief  Setup the microcontroller system.
 *         Initialize the System and update the SystemFrequency variable.
 */
extern void SystemInit (void);

#ifdef __cplusplus
}
#endif

#endif /* __SYSTEM_TLE984x_H */
