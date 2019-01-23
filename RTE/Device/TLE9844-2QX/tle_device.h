/****************************************************************************
 *
 * @file     tle_device.h
 *           Infineon TLE Device Series
 * @version  V1.0.3
 * @date     19 Oct 2017
 *
   Copyright (C) 2017 Infineon Technologies AG. All rights reserved.
 *
 *
 * @par
 * Infineon Technologies AG (Infineon) is supplying this software for use with 
 * Infineon's microcontrollers.  This file can be freely distributed
 * within development tools that are supporting such microcontrollers.
 *
 * @par
 * THIS SOFTWARE IS PROVIDED AS IS.  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 * OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 * ARM SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, OR
 * CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 *
 ******************************************************************************/

#ifndef _TLE_DEVICE_H
#define _TLE_DEVICE_H

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/
/* Family definitions  */
#define     TLE98     (98)

/* Series definitions  */
#define    TLE984     (984)
#define    TLE985     (985)
#define    TLE986     (986)
#define    TLE987     (987)

/* Device definitions  */
#define    TLE9842    (9842)
#define    TLE9843    (9843)
#define    TLE9844    (9844)
#define    TLE9845    (9845)

/* Package definitions */
#define    BGA144     (1)
#define    LQFP144    (2)
#define    LQFP100    (3)
#define    BGA64      (4)
#define    LQFP64     (5)
#define    VQFN48     (6)
#define    TSSOP38    (7)
#define    TSSOP28    (8)
#define    TSSOP16    (9) 
#define    VQFN24     (10)
#define    VQFN40     (11)

#if defined(TLE9842QX)
#define UC_FAMILY       TLE98
#define UC_SERIES       TLE984
#define UC_DEVICE       TLE9842
#define UC_PACKAGE      VQFN48
#define UC_FLASH        (36UL)
#define UC_FEAT_HS      (1U)
#define UC_FEAT_MON     (4U)
#define ProgFlashSize   (0x8000U)
#define RAMSize         (0x800U)

#elif defined(TLE9842_2QX)
#define UC_FAMILY       TLE98
#define UC_SERIES       TLE984
#define UC_DEVICE       TLE9842
#define UC_PACKAGE      VQFN48
#define UC_FLASH        (40UL)
#define UC_FEAT_HS      (2U)
#define UC_FEAT_MON     (5U)
#define ProgFlashSize   (0x9000U)
#define RAMSize         (0x800U)

#elif defined(TLE9843QX)
#define UC_FAMILY       TLE98
#define UC_SERIES       TLE984
#define UC_DEVICE       TLE9843
#define UC_PACKAGE      VQFN48
#define UC_FLASH        (48UL)
#define UC_FEAT_HS      (1U)
#define UC_FEAT_MON     (4U)
#define ProgFlashSize   (0xB000U)
#define RAMSize         (0x1000U)

#elif defined(TLE9843_2QX)
#define UC_FAMILY       TLE98
#define UC_SERIES       TLE984
#define UC_DEVICE       TLE9843
#define UC_PACKAGE      VQFN48
#define UC_FLASH        (52UL)
#define UC_FEAT_HS      (2U)
#define UC_FEAT_MON     (5U)
#define ProgFlashSize   (0xC000U)
#define RAMSize         (0x1000U)

#elif defined(TLE9844QX)
#define UC_FAMILY       TLE98
#define UC_SERIES       TLE984
#define UC_DEVICE       TLE9844
#define UC_PACKAGE      VQFN48
#define UC_FLASH        (64UL)
#define UC_FEAT_HS      (1U)
#define UC_FEAT_MON     (4U)
#define ProgFlashSize   (0xF000U)
#define RAMSize         (0x1000U)

#elif defined(TLE9844_2QX)
#define UC_FAMILY       TLE98
#define UC_SERIES       TLE984
#define UC_DEVICE       TLE9844
#define UC_PACKAGE      VQFN48
#define UC_FLASH        (64UL)
#define UC_FEAT_HS      (2U)
#define UC_FEAT_MON     (5U)
#define ProgFlashSize   (0xF000U)
#define RAMSize         (0x1000U)

#elif defined(TLE9845QX)
#define UC_FAMILY       TLE98
#define UC_SERIES       TLE984
#define UC_DEVICE       TLE9845
#define UC_PACKAGE      VQFN48
#define UC_FLASH        (48UL)
#define UC_FEAT_HS      (2U)
#define UC_FEAT_MON     (5U)
#define ProgFlashSize   (0xB000U)
#define RAMSize         (0x1000U)

#else
/*lint -e309 */
#error "tle_device.h: device not supported"
/*lint -e309 */
#endif
/*----------------------------------------------------------------------------
  Define Memory
 *----------------------------------------------------------------------------*/
#define ProgFlashStart  (0x11000000U)      /* Start Address of the flash      */
#define DataFlashStart  (ProgFlashStart + ProgFlashSize)
#define DataFlashSize   (0x1000U)          /* 4KB Data Flash                  */
#define NACStart        (ProgFlashStart - 4U)
#define NADStart        (ProgFlashStart - 2U)
#define RAMStart        (0x18000000UL)     /* Start Address of the SRAM       */

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#if (UC_SERIES == 984)
  #include <TLE984x.h>
#endif
#include <types.h>
#include <RTE_Components.h>

#ifdef RTE_DEVICE_SDK_BROM
  #include <bootrom.h>
#endif
#ifdef RTE_DEVICE_SDK_WDT1
  #include <wdt1.h>
#endif
#ifdef RTE_DEVICE_SDK_SCU
  #include <scu.h>
#endif
#ifdef RTE_DEVICE_SDK_PMU
  #include <pmu.h>
#endif
#ifdef RTE_DEVICE_SDK_ADC1
  #include <adc1.h>
#endif
#ifdef RTE_DEVICE_SDK_ADC2
  #include <adc2.h>
#endif
#ifdef RTE_DEVICE_SDK_CCU6
  #include <ccu6.h>
#endif
#ifdef RTE_DEVICE_SDK_GPT12E
  #include <gpt12e.h>
#endif
#ifdef RTE_DEVICE_SDK_HS
  #include <hs.h>
#endif
#ifdef RTE_DEVICE_SDK_INT
  #include <int.h>
#endif
#ifdef RTE_DEVICE_SDK_ISR
  #include <isr.h>
#endif
#ifdef RTE_DEVICE_SDK_LIN
  #include <lin.h>
#endif
#ifdef RTE_DEVICE_SDK_LS
  #include <ls.h>
#endif
#ifdef RTE_DEVICE_SDK_MON
  #include <mon.h>
#endif
#ifdef RTE_DEVICE_SDK_PORT
  #include <port.h>
#endif
#ifdef RTE_DEVICE_SDK_SSC
  #include <ssc.h>
#endif
#ifdef RTE_DEVICE_SDK_TIMER2X
  #include <timer2x.h>
#endif
#ifdef RTE_DEVICE_SDK_UART
  #include <uart.h>
#endif

extern uint32 SystemFrequency;

void TLE_Init(void);

#endif
