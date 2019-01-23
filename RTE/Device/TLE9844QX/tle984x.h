
/****************************************************************************************************//**
 * @file     TLE984x.h
 *
 * @brief    CMSIS Cortex-M0 Peripheral Access Layer Header File for
 *           TLE984x from Infineon Technologies AG.
 *
 * @version  V1.8
 * @date     28. Oct 2017
 *
 * @note     Generated with SVDConv V2.84c 
 *           from CMSIS SVD File 'TLE984x_UM_SVD.xml' Version 1.5,
 *
 * @note:    Generated for MISRA Compliance, this File is NOT CMSIS compliant.
 *
 * @par      tbd
 *
 *******************************************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/* 
 * V1.8: 2017-10-28:  Position/Mask macros added 
 * V1.7: 2017-10-27:  Include of tle_device.h removed
 * V1.6: 2016-06-28:  Memory definition moved to tle_device.h
 * V1.5: 2016-06-23:  Version covering the TLE984xQX Users Manual 1.0 (2016-06-20)
 *                    no changes compared to V1.4
 * V1.4: 2016-06-07:  Changes:
 *                    MISRA-2012 checked with PC-lint for C/C++ (NT) Vers. 9.00L
 *                    editorial changes
 *                    Flash sizes adapted for TL9842-2 and TLE9843-2
 * V1.3: 2016-02-18:  Covering AE design step. Changes:
 *                    MISRA-2012 checked with PC-lint for C/C++ (NT) Vers. 9.00L
 *                    editorial changes
 *                    adapted Flash and RAM adresses and sizes for whole device portfolio
 *                    PMU->WAKE_CNF_GPIO0 removed (was shared register, PMU->GPUDATA8to11 remains)
 *                    PMU->GPIO_WAKE_STATUS: GPIO2 removed
 *                    PMU->RESET_STS: PMU_IntWDT removed
 *                    PMU->VDDEXT_CTRL.3..5 changed to read-only
 *                    SCU->SYS_STRTUP_STS.PG100TP_NU changed to MRAMINITSTS
 *                    CPU->NCIC_ICER renamed to NVIC_ICER
 * V1.2: 2015-06-10:  Changes:
 *                    Modules T2 and T21 renamed to TIMER2 and TIMER21, due to naming conflict (Register T2 in GPT12)
 *                    Bit PMU_WAKE_STATUS.LIN renamed to PMU_WAKE_STATUS.LIN_WAKE, due to naming conflict with Module LIN
 * V1.1: 2014-12-21:  Changes:
 *                    Bitfields added in CPU->NVIC_ISER, *ICER, *ISPR, *ICPR
 *                    Registers added: CPU->NVIC_IPR0, 1, 2, 3, 4, 5
 *                    PMU->MON_CNF2 added
 *                    SCU->MODPISEL1.XTAL12EN added
 *                    PMU->HIGHSIDE_CTRL: cyclic enable HS0+1 -> HS1+2
 *                    GPT12E->T2CON.T3UDE -> T2UDE (bitname changed)
 *                    ADC2, ch7 added in:
 *                        FILTCOEFF0_7, TH4_7_LOWER, TH4_7_UPPER,
 *                        CNT4_7_LOWER, CNT4_7_UPPER, MMODE0_7
 *                    and minor changes in descriptive text
 *                    
 * V1.0: 2014-08-20:  Initial version
 *                     
 */


/** @addtogroup Infineon Technologies AG
  * @{
  */

/** @addtogroup TLE984x
  * @{
  */

#ifndef TLE984X_H
#define TLE984X_H


#ifdef __cplusplus
extern "C" {
#endif

/* memory definition has been moved to tle_device.h */

/* -------------------------  Interrupt Number Definition  ------------------------ */

typedef enum {
/* -------------------  Cortex-M0 Processor Exceptions Numbers  ------------------- */
  Reset_IRQn                    = -15,              /*!<   1  Reset Vector, invoked on Power up and warm reset                 */
  NonMaskableInt_IRQn           = -14,              /*!<   2  Non maskable Interrupt, cannot be stopped or preempted           */
  HardFault_IRQn                = -13,              /*!<   3  Hard Fault, all classes of Fault                                 */
  SVCall_IRQn                   =  -5,              /*!<  11  System Service Call via SVC instruction                          */
  DebugMonitor_IRQn             =  -4,              /*!<  12  Debug Monitor                                                    */
  SysTick_IRQn                  =  -1,              /*!<  15  System Tick Timer                                                */
/* ---------------------  TLE984x Specific Interrupt Numbers  --------------------- */
} IRQn_Type;


/** @addtogroup Configuration_of_CMSIS
  * @{
  */


/* ================================================================================ */
/* ================      Processor and Core Peripheral Section     ================ */
/* ================================================================================ */

/* ----------------Configuration of the Cortex-M0 Processor and Core Peripherals---------------- */
#define __CM0_REV                 0x0000            /*!< Cortex-M0 Core Revision                                               */
#define __MPU_PRESENT                  0            /*!< MPU present or not                                                    */
#define __NVIC_PRIO_BITS               2            /*!< Number of Bits used for Priority Levels                               */
#define __Vendor_SysTickConfig         0            /*!< Set to 1 if different SysTick Config is used                          */
/** @} */ /* End of group Configuration_of_CMSIS */

#include "core_cm0.h"                               /*!< Cortex-M0 processor and core peripherals                              */
#include "system_TLE984x.h"                         /*!< TLE984x System                                                        */


/* ================================================================================ */
/* ================       Device Specific Peripheral Section       ================ */
/* ================================================================================ */


/** @addtogroup Device_Peripheral_Registers
  * @{
  */


/* -------------------  Start of section using anonymous unions  ------------------ */


/* ================================================================================ */
/* ================                      ADC1                      ================ */
/* ================================================================================ */


/**
  * @brief ADC1 (ADC1)
  */

typedef struct {                                    /*!< (@ 0x40004000) ADC1 Structure                                         */
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x40004000) ADC1 Control and Status Register                       */
    
    struct {
      __IO uint32_t  PD_N       :  1;               /*!< [0..0] ADC1 Power Down Signal                                         */
      __IO uint32_t  SOOC       :  1;               /*!< [1..1] ADC1 Start of Offset Calibration (software mode)               */
      __IO uint32_t  SOS        :  1;               /*!< [2..2] ADC1 Start of Sampling/Conversion (software mode)              */
           uint32_t             :  1;
      __I  uint32_t  READY      :  1;               /*!< [4..4] HVADC Ready bit                                                */
      __I  uint32_t  CAL_SIGN   :  1;               /*!< [5..5] Output of Comparator to Steer Gain / Offset calibration        */
           uint32_t             :  1;
      __I  uint32_t  EOC        :  1;               /*!< [7..7] ADC1 End of Conversion (software mode)                         */
      __IO uint32_t  SW_CH_SEL  :  4;               /*!< [8..11] Channel for software mode                                     */
           uint32_t             :  6;
      __IO uint32_t  STRTUP_DIS :  1;               /*!< [18..18] DPP1 Startup Disable                                         */
    } bit;                                          /*!< [19] BitSize                                                          */
  } CTRL_STS;
  
  union {
    __I  uint32_t  reg;                             /*!< (@ 0x40004004) Sequencer Feedback Register                            */
    
    struct {
      __I  uint32_t  SQ_FB      :  5;               /*!< [0..4] Current Sequence that caused software mode                     */
           uint32_t             :  3;
      __I  uint32_t  SQ_STOP    :  1;               /*!< [8..8] ADC1 Sequencer Stop Signal for DPP                             */
      __I  uint32_t  EIM_ACTIVE :  1;               /*!< [9..9] ADC1 EIM active                                                */
      __I  uint32_t  ESM_ACTIVE :  1;               /*!< [10..10] ADC1 ESM active                                              */
      __I  uint32_t  SQx        :  4;               /*!< [11..14] Current Active ADC1 Sequence                                 */
           uint32_t             :  1;
      __I  uint32_t  CHx        :  4;               /*!< [16..19] Current ADC1 Channel                                         */
    } bit;                                          /*!< [20] BitSize                                                          */
  } SQ_FB;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x40004008) Channel Setting Bits for Exceptional Interrupt
                                                         Measurement                                                           */
    
    struct {
      __IO uint32_t  EIM_CHx    :  4;               /*!< [0..3] Channel set for exceptional interrupt measurement (EIM)        */
           uint32_t             :  4;
      __IO uint32_t  EIM_REP    :  3;               /*!< [8..10] Repeat count for exceptional interrupt measurement (EIM)      */
      __IO uint32_t  EIM_EN     :  1;               /*!< [11..11] Exceptional interrupt measurement (EIM) Trigger Event
                                                         enable                                                                */
           uint32_t             :  4;
      __IO uint32_t  ADC1_EIM_TRIG_SEL:  3;         /*!< [16..18] Trigger selection for exceptional interrupt measurement
                                                         (EIM)                                                                 */
    } bit;                                          /*!< [19] BitSize                                                          */
  } CHx_EIM;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x4000400C) Channel Setting Bits for Exceptional Sequence
                                                         Measurement                                                           */
    
    struct {
      __IO uint32_t  ESM_0      : 12;               /*!< [0..11] Channel Sequence for Exceptional Sequence Measurement
                                                         (ESM)                                                                 */
           uint32_t             :  4;
      __IO uint32_t  ADC1_ESM_TRIG_SEL:  3;         /*!< [16..18] Trigger selection for exceptional interrupt measurement
                                                         (ESM)                                                                 */
           uint32_t             : 11;
      __IO uint32_t  ESM_EN     :  1;               /*!< [30..30] Enable for Exceptional Sequence Measurement Trigger
                                                         Event                                                                 */
      __IO uint32_t  ESM_STS    :  1;               /*!< [31..31] Exceptional Sequence Measurement is finished                 */
    } bit;                                          /*!< [32] BitSize                                                          */
  } CHx_ESM;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x40004010) Maximum Time for Software Mode                         */
    
    struct {
      __IO uint32_t  MAX_TIME   :  8;               /*!< [0..7] Maximum Time in Software Mode                                  */
    } bit;                                          /*!< [8] BitSize                                                           */
  } MAX_TIME;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x40004014) Measurement Unit 1 Control Register 2                  */
    
    struct {
      __IO uint32_t  CAL_EN     : 12;               /*!< [0..11] Calibration Enable for Channels 0 to 11                       */
    } bit;                                          /*!< [12] BitSize                                                          */
  } CTRL2;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x40004018) Measurement Unit 1 Control Register 3                  */
    
    struct {
      __IO uint32_t  MCM_PD_N   :  1;               /*!< [0..0] Power Down Signal for MCM                                      */
      __IO uint32_t  SW_MODE    :  1;               /*!< [1..1] SW Mode Enable                                                 */
           uint32_t             :  2;
      __O  uint32_t  EoC_FAIL_CLR:  1;              /*!< [4..4] Fail of ADC End of Conversion Signal Clear                     */
           uint32_t             :  1;
      __I  uint32_t  EoC_FAIL   :  1;               /*!< [6..6] Fail of ADC End of Conversion Signal                           */
      __I  uint32_t  MCM_RDY    :  1;               /*!< [7..7] Ready Signal for MCM after Power On or Reset                   */
      __IO uint32_t  SAMPLE_TIME_HVCH:  4;          /*!< [8..11] Sample time of ADC1                                           */
           uint32_t             :  4;
      __IO uint32_t  SAMPLE_TIME_LVCH:  4;          /*!< [16..19] Sample time of ADC1                                          */
    } bit;                                          /*!< [20] BitSize                                                          */
  } CTRL3;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x4000401C) Measurement Unit 1 Control Register 5                  */
    
    struct {
      __IO uint32_t  FILT_OUT_SEL_11_0: 12;         /*!< [0..11] Output Filter Selection for Channels 0 to 11                  */
    } bit;                                          /*!< [12] BitSize                                                          */
  } CTRL5;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x40004020) Measurement Unit 1 Channel Enable Bits for Cycle
                                                         0-1                                                                   */
    
    struct {
      __IO uint32_t  SQ0        : 12;               /*!< [0..11] Sequence 0 channel enable                                     */
           uint32_t             :  4;
      __IO uint32_t  SQ1        : 12;               /*!< [16..27] Sequence 1 channel enable                                    */
    } bit;                                          /*!< [28] BitSize                                                          */
  } SQ0_1;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x40004024) Measurement Unit 1 Channel Enable Bits for Cycle
                                                         2-3                                                                   */
    
    struct {
      __IO uint32_t  SQ2        : 12;               /*!< [0..11] Sequence 2 channel enable                                     */
           uint32_t             :  4;
      __IO uint32_t  SQ3        : 12;               /*!< [16..27] Sequence 3 channel enable                                    */
    } bit;                                          /*!< [28] BitSize                                                          */
  } SQ2_3;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x40004028) Measurement Unit 1 Channel Enable Bits for Cycle
                                                         4-5                                                                   */
    
    struct {
      __IO uint32_t  SQ4        : 12;               /*!< [0..11] Sequence 4 channel enable                                     */
           uint32_t             :  4;
      __IO uint32_t  SQ5        : 12;               /*!< [16..27] Sequence 5 channel enable                                    */
    } bit;                                          /*!< [28] BitSize                                                          */
  } SQ4_5;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x4000402C) Measurement Unit 1 Channel Enable Bits for Cycle
                                                         6-7                                                                   */
    
    struct {
      __IO uint32_t  SQ6        : 12;               /*!< [0..11] Sequence 6 channel enable                                     */
           uint32_t             :  4;
      __IO uint32_t  SQ7        : 12;               /*!< [16..27] Sequence 7 channel enable                                    */
    } bit;                                          /*!< [28] BitSize                                                          */
  } SQ6_7;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x40004030) Measurement Unit 1 Channel Enable Bits for Cycle
                                                         8-9                                                                   */
    
    struct {
      __IO uint32_t  SQ8        : 12;               /*!< [0..11] Sequence 8 channel enable                                     */
           uint32_t             :  4;
      __IO uint32_t  SQ9        : 12;               /*!< [16..27] Sequence 9 channel enable                                    */
    } bit;                                          /*!< [28] BitSize                                                          */
  } SQ8_9;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x40004034) Measurement Unit 1 Channel Enable Bits for Cycle
                                                         10-11                                                                 */
    
    struct {
      __IO uint32_t  SQ10       : 12;               /*!< [0..11] Sequence 10 channel enable                                    */
           uint32_t             :  4;
      __IO uint32_t  SQ11       : 12;               /*!< [16..27] Sequence 11 channel enable                                   */
    } bit;                                          /*!< [28] BitSize                                                          */
  } SQ10_11;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x40004038) Measurement Unit 1 Control Register 4                  */
    
    struct {
      __IO uint32_t  MAX_CALTIME:  4;               /*!< [0..3] Maximum ADC Calibration Time                                   */
    } bit;                                          /*!< [4] BitSize                                                           */
  } CTRL4;
  __I  uint32_t  RESERVED;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x40004040) Lower Comparator Trigger Level Channel 0-3             */
    
    struct {
      __IO uint32_t  CH0_LOW    :  8;               /*!< [0..7] Channel 0 lower trigger level                                  */
      __IO uint32_t  CH1_LOW    :  8;               /*!< [8..15] Channel 1 lower trigger level                                 */
      __IO uint32_t  CH2_LOW    :  8;               /*!< [16..23] Channel 2 lower trigger level                                */
      __IO uint32_t  CH3_LOW    :  8;               /*!< [24..31] Channel 3 lower trigger level                                */
    } bit;                                          /*!< [32] BitSize                                                          */
  } TH0_3_LOWER;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x40004044) Lower Comparator Trigger Level Channel 4-7             */
    
    struct {
      __IO uint32_t  CH4_LOW    :  8;               /*!< [0..7] Channel 4 lower trigger level                                  */
      __IO uint32_t  CH5_LOW    :  8;               /*!< [8..15] Channel 5 lower trigger level                                 */
      __IO uint32_t  CH6_LOW    :  8;               /*!< [16..23] Channel 6 lower trigger level                                */
      __IO uint32_t  CH7_LOW    :  8;               /*!< [24..31] Channel 7 lower trigger level                                */
    } bit;                                          /*!< [32] BitSize                                                          */
  } TH4_7_LOWER;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x40004048) Calibration for Channel 0 & 1                          */
    
    struct {
      __IO uint32_t  CALOFFS_CH0:  5;               /*!< [0..4] Offset Calibration for channel 0                               */
           uint32_t             :  3;
      __IO uint32_t  CALGAIN_CH0:  8;               /*!< [8..15] Gain Calibration for channel 0                                */
      __IO uint32_t  CALOFFS_CH1:  5;               /*!< [16..20] Offset Calibration for channel 1                             */
           uint32_t             :  3;
      __IO uint32_t  CALGAIN_CH1:  8;               /*!< [24..31] Gain Calibration for channel 1                               */
    } bit;                                          /*!< [32] BitSize                                                          */
  } CAL_CH0_1;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x4000404C) Calibration for Channel 2 & 3                          */
    
    struct {
      __IO uint32_t  CALOFFS_CH2:  5;               /*!< [0..4] Offset Calibration for channel 2                               */
           uint32_t             :  3;
      __IO uint32_t  CALGAIN_CH2:  8;               /*!< [8..15] Gain Calibration for channel 2                                */
      __IO uint32_t  CALOFFS_CH3:  5;               /*!< [16..20] Offset Calibration for channel 3                             */
           uint32_t             :  3;
      __IO uint32_t  CALGAIN_CH3:  8;               /*!< [24..31] Gain Calibration for channel 3                               */
    } bit;                                          /*!< [32] BitSize                                                          */
  } CAL_CH2_3;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x40004050) Calibration for Channel 4 & 5                          */
    
    struct {
      __IO uint32_t  CALOFFS_CH4:  5;               /*!< [0..4] Offset Calibration for channel 4                               */
           uint32_t             :  3;
      __IO uint32_t  CALGAIN_CH4:  8;               /*!< [8..15] Gain Calibration for channel 4                                */
      __IO uint32_t  CALOFFS_CH5:  5;               /*!< [16..20] Offset Calibration for channel 5                             */
           uint32_t             :  3;
      __IO uint32_t  CALGAIN_CH5:  8;               /*!< [24..31] Gain Calibration for channel 5                               */
    } bit;                                          /*!< [32] BitSize                                                          */
  } CAL_CH4_5;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x40004054) Calibration for Channel 6 & 7                          */
    
    struct {
      __IO uint32_t  CALOFFS_CH6:  5;               /*!< [0..4] Offset Calibration for channel 6                               */
           uint32_t             :  3;
      __IO uint32_t  CALGAIN_CH6:  8;               /*!< [8..15] Gain Calibration for channel 6                                */
      __IO uint32_t  CALOFFS_CH7:  5;               /*!< [16..20] Offset Calibration for channel 7                             */
           uint32_t             :  3;
      __IO uint32_t  CALGAIN_CH7:  8;               /*!< [24..31] Gain Calibration for channel 7                               */
    } bit;                                          /*!< [32] BitSize                                                          */
  } CAL_CH6_7;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x40004058) Calibration for Channel 8 & 9                          */
    
    struct {
      __IO uint32_t  CALOFFS_CH8:  5;               /*!< [0..4] Offset Calibration for channel 8                               */
           uint32_t             :  3;
      __IO uint32_t  CALGAIN_CH8:  8;               /*!< [8..15] Gain Calibration for channel 8                                */
      __IO uint32_t  CALOFFS_CH9:  5;               /*!< [16..20] Offset Calibration for channel 9                             */
           uint32_t             :  3;
      __IO uint32_t  CALGAIN_CH9:  8;               /*!< [24..31] Gain Calibration for channel 9                               */
    } bit;                                          /*!< [32] BitSize                                                          */
  } CAL_CH8_9;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x4000405C) Calibration for Channel 10 & 11                        */
    
    struct {
      __IO uint32_t  CALOFFS_CH10:  5;              /*!< [0..4] Offset Calibration for channel 10                              */
           uint32_t             :  3;
      __IO uint32_t  CALGAIN_CH10:  8;              /*!< [8..15] Gain Calibration for channel 10                               */
      __IO uint32_t  CALOFFS_CH11:  5;              /*!< [16..20] Offset Calibration for channel 11                            */
           uint32_t             :  3;
      __IO uint32_t  CALGAIN_CH11:  8;              /*!< [24..31] Gain Calibration for channel 11                              */
    } bit;                                          /*!< [32] BitSize                                                          */
  } CAL_CH10_11;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x40004060) Filter Coefficients Measurement Unit Channel
                                                         0-11                                                                  */
    
    struct {
      __IO uint32_t  CH0        :  2;               /*!< [0..1] Filter Coefficients ADC channel 0                              */
      __IO uint32_t  CH1        :  2;               /*!< [2..3] Filter Coefficients ADC channel 1                              */
      __IO uint32_t  CH2        :  2;               /*!< [4..5] Filter Coefficients ADC channel 2                              */
      __IO uint32_t  CH3        :  2;               /*!< [6..7] Filter Coefficients ADC channel 3                              */
      __IO uint32_t  CH4        :  2;               /*!< [8..9] Filter Coefficients ADC channel 4                              */
      __IO uint32_t  CH5        :  2;               /*!< [10..11] Filter Coefficients ADC channel 5                            */
      __IO uint32_t  CH6        :  2;               /*!< [12..13] Filter Coefficients ADC channel 6                            */
      __IO uint32_t  CH7        :  2;               /*!< [14..15] Filter Coefficients ADC channel 7                            */
      __IO uint32_t  CH8        :  2;               /*!< [16..17] Filter Coefficients ADC channel 8                            */
      __IO uint32_t  CH9        :  2;               /*!< [18..19] Filter Coefficients ADC channel 9                            */
      __IO uint32_t  CH10       :  2;               /*!< [20..21] Filter Coefficients ADC channel 10                           */
      __IO uint32_t  CH11       :  2;               /*!< [22..23] Filter Coefficients ADC channel 11                           */
    } bit;                                          /*!< [24] BitSize                                                          */
  } FILTCOEFF0_11;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x40004064) ADC1 Interrupt Status 1 Register                       */
    
    struct {
      __IO uint32_t  VBATSEN_IS :  1;               /*!< [0..0] ADC1 Channel 1 Interrupt Status                                */
      __IO uint32_t  VS_IS      :  1;               /*!< [1..1] ADC1 Channel 0 Interrupt Status                                */
      __IO uint32_t  MON1_IS    :  1;               /*!< [2..2] ADC1 Channel 2 Interrupt Status                                */
      __IO uint32_t  MON2_IS    :  1;               /*!< [3..3] ADC1 Channel 3 Interrupt Status                                */
      __IO uint32_t  MON3_IS    :  1;               /*!< [4..4] ADC1 Channel 4 Interrupt Status                                */
      __IO uint32_t  MON4_IS    :  1;               /*!< [5..5] ADC1 Channel 5 Interrupt Status                                */
      __IO uint32_t  MON5_IS    :  1;               /*!< [6..6] ADC1 Channel 6 Interrupt Status                                */
      __IO uint32_t  P2_1_IS    :  1;               /*!< [7..7] ADC1 Channel 7 Interrupt Status                                */
      __IO uint32_t  P2_2_IS    :  1;               /*!< [8..8] ADC1 Channel 8 Interrupt Status                                */
      __IO uint32_t  P2_3_IS    :  1;               /*!< [9..9] ADC1 Channel 9 Interrupt Status                                */
      __IO uint32_t  P2_6_IS    :  1;               /*!< [10..10] ADC1 Channel 10 Interrupt Status                             */
      __IO uint32_t  P2_7_IS    :  1;               /*!< [11..11] ADC1 Channel 11 Interrupt Status                             */
      __IO uint32_t  P2_0_IS    :  1;               /*!< [12..12] ADC1 Channel 12 Interrupt Status                             */
           uint32_t             :  3;
      __IO uint32_t  EIM_IS     :  1;               /*!< [16..16] Exceptional Interrupt Measurement (EIM) Status               */
      __IO uint32_t  ESM_IS     :  1;               /*!< [17..17] Exceptional Sequence Measurement (ESM) Status                */
           uint32_t             :  6;
      __IO uint32_t  DU1LO_IS   :  1;               /*!< [24..24] ADC1 Differential Unit 1 (DU1) lower Channel Interrupt
                                                         Status                                                                */
      __IO uint32_t  DU1UP_IS   :  1;               /*!< [25..25] ADC1 Differential Unit 1 (DU1) upper Channel Interrupt
                                                         Status                                                                */
      __IO uint32_t  DU2LO_IS   :  1;               /*!< [26..26] ADC1 Differential Unit 2 (DU2) lower Channel Interrupt
                                                         Status                                                                */
      __IO uint32_t  DU2UP_IS   :  1;               /*!< [27..27] ADC1 Differential Unit 2 (DU2) upper Channel Interrupt
                                                         Status                                                                */
      __IO uint32_t  DU3LO_IS   :  1;               /*!< [28..28] ADC1 Differential Unit 3 (DU3) lower Channel Interrupt
                                                         Status                                                                */
      __IO uint32_t  DU3UP_IS   :  1;               /*!< [29..29] ADC1 Differential Unit 3 (DU3) upper Channel Interrupt
                                                         Status                                                                */
      __IO uint32_t  DU4LO_IS   :  1;               /*!< [30..30] ADC1 Differential Unit 4 (DU4) lower Channel Interrupt
                                                         Status                                                                */
      __IO uint32_t  DU4UP_IS   :  1;               /*!< [31..31] ADC1 Differential Unit 4 (DU4) upper Channel Interrupt
                                                         Status                                                                */
    } bit;                                          /*!< [32] BitSize                                                          */
  } IRQS_1;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x40004068) ADC1 Interrupt Enable 1 Register                       */
    
    struct {
      __IO uint32_t  VBATSEN_IEN:  1;               /*!< [0..0] ADC1 VBAT_SENSE Interrupt Enable                               */
      __IO uint32_t  VS_IEN     :  1;               /*!< [1..1] ADC1 VS Interrupt Enable                                       */
      __IO uint32_t  MON1_IEN   :  1;               /*!< [2..2] ADC1 MON 1 Interrupt Enable                                    */
      __IO uint32_t  MON2_IEN   :  1;               /*!< [3..3] ADC1 MON 2 Interrupt Enable                                    */
      __IO uint32_t  MON3_IEN   :  1;               /*!< [4..4] ADC1 MON 3 Interrupt Enable                                    */
      __IO uint32_t  MON4_IEN   :  1;               /*!< [5..5] ADC1 MON 4 Interrupt Enable                                    */
      __IO uint32_t  MON5_IEN   :  1;               /*!< [6..6] ADC1 MON 5 Interrupt Enable                                    */
      __IO uint32_t  P2_1_IEN   :  1;               /*!< [7..7] ADC1 Port 2.1 Interrupt Enable                                 */
      __IO uint32_t  P2_2_IEN   :  1;               /*!< [8..8] ADC1 Port 2.2 Interrupt Enable                                 */
      __IO uint32_t  P2_3_IEN   :  1;               /*!< [9..9] ADC1 Port 2.3 Interrupt Enable                                 */
      __IO uint32_t  P2_6_IEN   :  1;               /*!< [10..10] ADC1 Port 2.6 Interrupt Enable                               */
      __IO uint32_t  P2_7_IEN   :  1;               /*!< [11..11] ADC1 Port 2.7 Interrupt Enable                               */
      __IO uint32_t  P2_0_IEN   :  1;               /*!< [12..12] ADC1 Port 2.0 Interrupt Enable                               */
           uint32_t             :  3;
      __IO uint32_t  EIM_IEN    :  1;               /*!< [16..16] Exceptional Interrupt Measurement (EIM) Interrupt Enable     */
      __IO uint32_t  ESM_IEN    :  1;               /*!< [17..17] Exceptional Sequence Measurement (ESM) Interrupt Enable      */
           uint32_t             :  6;
      __IO uint32_t  DU1LO_IEN  :  1;               /*!< [24..24] Differential Unit 1 lower Interrupt Enable                   */
      __IO uint32_t  DU1UP_IEN  :  1;               /*!< [25..25] Differential Unit 1 upper Interrupt Enable                   */
      __IO uint32_t  DU2LO_IEN  :  1;               /*!< [26..26] Differential Unit 2 lower Interrupt Enable                   */
      __IO uint32_t  DU2UP_IEN  :  1;               /*!< [27..27] Differential Unit 2 upper Interrupt Enable                   */
      __IO uint32_t  DU3LO_IEN  :  1;               /*!< [28..28] Differential Unit 3 lower Interrupt Enable                   */
      __IO uint32_t  DU3UP_IEN  :  1;               /*!< [29..29] Differential Unit 3 upper Interrupt Enable                   */
      __IO uint32_t  DU4LO_IEN  :  1;               /*!< [30..30] Differential Unit 4 lower Interrupt Enable                   */
      __IO uint32_t  DU4UP_IEN  :  1;               /*!< [31..31] Differential Unit 4 upper Interrupt Enable                   */
    } bit;                                          /*!< [32] BitSize                                                          */
  } IRQEN_1;
  
  union {
    __O  uint32_t  reg;                             /*!< (@ 0x4000406C) ADC1 Interrupt Status Clear 1 Register                 */
    
    struct {
      __O  uint32_t  VBATSEN_ISC:  1;               /*!< [0..0] ADC1 VBAT_SENSE Interrupt Status Clear                         */
      __O  uint32_t  VS_ISC     :  1;               /*!< [1..1] ADC1 VS Interrupt Status Clear                                 */
      __O  uint32_t  MON1_ISC   :  1;               /*!< [2..2] ADC1 MON 1 Interrupt Status Clear                              */
      __O  uint32_t  MON2_ISC   :  1;               /*!< [3..3] ADC1 MON 2 Interrupt Status Clear                              */
      __O  uint32_t  MON3_ISC   :  1;               /*!< [4..4] ADC1 MON 3 Interrupt Status Clear                              */
      __O  uint32_t  MON4_ISC   :  1;               /*!< [5..5] ADC1 MON 4 Interrupt Status Clear                              */
      __O  uint32_t  MON5_ISC   :  1;               /*!< [6..6] ADC1 MON 5 Interrupt Status Clear                              */
      __O  uint32_t  P2_1_ISC   :  1;               /*!< [7..7] ADC1 Port 2.1 Interrupt Status Clear                           */
      __O  uint32_t  P2_2_ISC   :  1;               /*!< [8..8] ADC1 Port 2.2 Interrupt Status Clear                           */
      __O  uint32_t  P2_3_ISC   :  1;               /*!< [9..9] ADC1 Port 2.3 Interrupt Status Clear                           */
      __O  uint32_t  P2_6_ISC   :  1;               /*!< [10..10] ADC1 Port 2.6 Interrupt Status Clear                         */
      __O  uint32_t  P2_7_ISC   :  1;               /*!< [11..11] ADC1 Port 2.7 Interrupt Status Clear                         */
      __O  uint32_t  P2_0_ISC   :  1;               /*!< [12..12] ADC1 Port 2.0 Interrupt Status Clear                         */
           uint32_t             :  3;
      __O  uint32_t  EIM_ISC    :  1;               /*!< [16..16] Exceptional Interrupt Measurement (EIM) Status Clear         */
      __O  uint32_t  ESM_ISC    :  1;               /*!< [17..17] Exceptional Sequence Measurement (ESM) Status Clear          */
           uint32_t             :  6;
      __O  uint32_t  DU1LO_ISC  :  1;               /*!< [24..24] Differential Unit 1 lower Interrupt Status Clear             */
      __O  uint32_t  DU1UP_ISC  :  1;               /*!< [25..25] Differential Unit 1 lower Interrupt Status Clear             */
      __O  uint32_t  DU2LO_ISC  :  1;               /*!< [26..26] Differential Unit 2 lower Interrupt Status Clear             */
      __O  uint32_t  DU2UP_ISC  :  1;               /*!< [27..27] Differential Unit 2 lower Interrupt Status Clear             */
      __O  uint32_t  DU3LO_ISC  :  1;               /*!< [28..28] Differential Unit 3 lower Interrupt Status Clear             */
      __O  uint32_t  DU3UP_ISC  :  1;               /*!< [29..29] Differential Unit 3 lower Interrupt Status Clear             */
      __O  uint32_t  DU4LO_ISC  :  1;               /*!< [30..30] Differential Unit 4 lower Interrupt Status Clear             */
      __O  uint32_t  DU4UP_ISC  :  1;               /*!< [31..31] Differential Unit 4 lower Interrupt Status Clear             */
    } bit;                                          /*!< [32] BitSize                                                          */
  } IRQCLR_1;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x40004070) ADC1 or Filter Output Channel 0                        */
    
    struct {
      __I  uint32_t  FILT_OUT_CH0: 12;              /*!< [0..11] ADC or filter output value channel 0                          */
           uint32_t             :  4;
      __IO uint32_t  WFR0       :  1;               /*!< [16..16] Wait for Read Mode                                           */
      __I  uint32_t  VF0        :  1;               /*!< [17..17] Valid Flag                                                   */
      __I  uint32_t  OF0        :  1;               /*!< [18..18] Overrun Flag                                                 */
    } bit;                                          /*!< [19] BitSize                                                          */
  } FILT_OUT0;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x40004074) ADC1 or Filter Output Channel 1                        */
    
    struct {
      __I  uint32_t  FILT_OUT_CH1: 12;              /*!< [0..11] ADC or filter output value channel 1                          */
           uint32_t             :  4;
      __IO uint32_t  WFR1       :  1;               /*!< [16..16] Wait for Read Mode                                           */
      __I  uint32_t  VF1        :  1;               /*!< [17..17] Valid Flag                                                   */
      __I  uint32_t  OF1        :  1;               /*!< [18..18] Overrun Flag                                                 */
    } bit;                                          /*!< [19] BitSize                                                          */
  } FILT_OUT1;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x40004078) ADC1 or Filter Output Channel 2                        */
    
    struct {
      __I  uint32_t  FILT_OUT_CH2: 12;              /*!< [0..11] ADC or filter output value channel 2                          */
           uint32_t             :  4;
      __IO uint32_t  WFR2       :  1;               /*!< [16..16] Wait for Read Mode                                           */
      __I  uint32_t  VF2        :  1;               /*!< [17..17] Valid Flag                                                   */
      __I  uint32_t  OF2        :  1;               /*!< [18..18] Overrun Flag                                                 */
    } bit;                                          /*!< [19] BitSize                                                          */
  } FILT_OUT2;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x4000407C) ADC1 or Filter Output Channel 3                        */
    
    struct {
      __I  uint32_t  FILT_OUT_CH3: 12;              /*!< [0..11] ADC or filter output value channel 3                          */
           uint32_t             :  4;
      __IO uint32_t  WFR3       :  1;               /*!< [16..16] Wait for Read Mode                                           */
      __I  uint32_t  VF3        :  1;               /*!< [17..17] Valid Flag                                                   */
      __I  uint32_t  OF3        :  1;               /*!< [18..18] Overrun Flag                                                 */
    } bit;                                          /*!< [19] BitSize                                                          */
  } FILT_OUT3;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x40004080) ADC1 or Filter Output Channel 4                        */
    
    struct {
      __I  uint32_t  FILT_OUT_CH4: 12;              /*!< [0..11] ADC or filter output value channel 4                          */
           uint32_t             :  4;
      __IO uint32_t  WFR4       :  1;               /*!< [16..16] Wait for Read Mode                                           */
      __I  uint32_t  VF4        :  1;               /*!< [17..17] Valid Flag                                                   */
      __I  uint32_t  OF4        :  1;               /*!< [18..18] Overrun Flag                                                 */
    } bit;                                          /*!< [19] BitSize                                                          */
  } FILT_OUT4;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x40004084) ADC1 or Filter Output Channel 5                        */
    
    struct {
      __I  uint32_t  FILT_OUT_CH5: 12;              /*!< [0..11] ADC or filter output value channel 5                          */
           uint32_t             :  4;
      __IO uint32_t  WFR5       :  1;               /*!< [16..16] Wait for Read Mode                                           */
      __I  uint32_t  VF5        :  1;               /*!< [17..17] Valid Flag                                                   */
      __I  uint32_t  OF5        :  1;               /*!< [18..18] Overrun Flag                                                 */
    } bit;                                          /*!< [19] BitSize                                                          */
  } FILT_OUT5;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x40004088) ADC1 or Filter Output Channel 6                        */
    
    struct {
      __I  uint32_t  FILT_OUT_CH6: 12;              /*!< [0..11] ADC or filter output value channel 6                          */
           uint32_t             :  4;
      __IO uint32_t  WFR6       :  1;               /*!< [16..16] Wait for Read Mode                                           */
      __I  uint32_t  VF6        :  1;               /*!< [17..17] Valid Flag                                                   */
      __I  uint32_t  OF6        :  1;               /*!< [18..18] Overrun Flag                                                 */
    } bit;                                          /*!< [19] BitSize                                                          */
  } FILT_OUT6;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x4000408C) ADC1 or Filter Output Channel 7                        */
    
    struct {
      __I  uint32_t  FILT_OUT_CH7: 12;              /*!< [0..11] ADC or filter output value channel 7                          */
           uint32_t             :  4;
      __IO uint32_t  WFR7       :  1;               /*!< [16..16] Wait for Read Mode                                           */
      __I  uint32_t  VF7        :  1;               /*!< [17..17] Valid Flag                                                   */
      __I  uint32_t  OF7        :  1;               /*!< [18..18] Overrun Flag                                                 */
    } bit;                                          /*!< [19] BitSize                                                          */
  } FILT_OUT7;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x40004090) ADC1 or Filter Output Channel 8                        */
    
    struct {
      __I  uint32_t  FILT_OUT_CH8: 12;              /*!< [0..11] ADC or filter output value channel 8                          */
           uint32_t             :  4;
      __IO uint32_t  WFR8       :  1;               /*!< [16..16] Wait for Read Mode                                           */
      __I  uint32_t  VF8        :  1;               /*!< [17..17] Valid Flag                                                   */
      __I  uint32_t  OF8        :  1;               /*!< [18..18] Overrun Flag                                                 */
    } bit;                                          /*!< [19] BitSize                                                          */
  } FILT_OUT8;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x40004094) ADC1 or Filter Output Channel 9                        */
    
    struct {
      __I  uint32_t  FILT_OUT_CH9: 12;              /*!< [0..11] ADC or filter output value channel 9                          */
           uint32_t             :  4;
      __IO uint32_t  WFR9       :  1;               /*!< [16..16] Wait for Read Mode                                           */
      __I  uint32_t  VF9        :  1;               /*!< [17..17] Valid Flag                                                   */
      __I  uint32_t  OF9        :  1;               /*!< [18..18] Overrun Flag                                                 */
    } bit;                                          /*!< [19] BitSize                                                          */
  } FILT_OUT9;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x40004098) ADC1 or Filter Output Channel 10                       */
    
    struct {
      __I  uint32_t  FILT_OUT_CH10: 12;             /*!< [0..11] ADC or filter output value channel 10                         */
           uint32_t             :  4;
      __IO uint32_t  WFR10      :  1;               /*!< [16..16] Wait for Read Mode                                           */
      __I  uint32_t  VF10       :  1;               /*!< [17..17] Valid Flag                                                   */
      __I  uint32_t  OF10       :  1;               /*!< [18..18] Overrun Flag                                                 */
    } bit;                                          /*!< [19] BitSize                                                          */
  } FILT_OUT10;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x4000409C) ADC1 or Filter Output Channel 11                       */
    
    struct {
      __I  uint32_t  FILT_OUT_CH11: 12;             /*!< [0..11] ADC or filter output value channel 11                         */
           uint32_t             :  4;
      __IO uint32_t  WFR11      :  1;               /*!< [16..16] Wait for Read Mode                                           */
      __I  uint32_t  VF11       :  1;               /*!< [17..17] Valid Flag                                                   */
      __I  uint32_t  OF11       :  1;               /*!< [18..18] Overrun Flag                                                 */
    } bit;                                          /*!< [19] BitSize                                                          */
  } FILT_OUT11;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x400040A0) ADC1 Differential Channel Output 1                     */
    
    struct {
      __I  uint32_t  DCH1       : 12;               /*!< [0..11] ADC differential output value 1                               */
           uint32_t             :  4;
      __IO uint32_t  DWFR1      :  1;               /*!< [16..16] Wait for Read Mode                                           */
      __I  uint32_t  DVF1       :  1;               /*!< [17..17] Valid Flag                                                   */
      __I  uint32_t  DOF1       :  1;               /*!< [18..18] Overrun Flag                                                 */
    } bit;                                          /*!< [19] BitSize                                                          */
  } DIFFCH_OUT1;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x400040A4) ADC1 Differential Channel Output 2                     */
    
    struct {
      __I  uint32_t  DCH2       : 12;               /*!< [0..11] ADC differential output value 2                               */
           uint32_t             :  4;
      __IO uint32_t  DWFR2      :  1;               /*!< [16..16] Wait for Read Mode                                           */
      __I  uint32_t  DVF2       :  1;               /*!< [17..17] Valid Flag                                                   */
      __I  uint32_t  DOF2       :  1;               /*!< [18..18] Overrun Flag                                                 */
    } bit;                                          /*!< [19] BitSize                                                          */
  } DIFFCH_OUT2;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x400040A8) ADC1 Differential Channel Output 3                     */
    
    struct {
      __I  uint32_t  DCH3       : 12;               /*!< [0..11] ADC differential output value 3                               */
           uint32_t             :  4;
      __IO uint32_t  DWFR3      :  1;               /*!< [16..16] Wait for Read Mode                                           */
      __I  uint32_t  DVF3       :  1;               /*!< [17..17] Valid Flag                                                   */
      __I  uint32_t  DOF3       :  1;               /*!< [18..18] Overrun Flag                                                 */
    } bit;                                          /*!< [19] BitSize                                                          */
  } DIFFCH_OUT3;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x400040AC) ADC1 Differential Channel Output 4                     */
    
    struct {
      __I  uint32_t  DCH4       : 12;               /*!< [0..11] ADC differential output value 4                               */
           uint32_t             :  4;
      __IO uint32_t  DWFR4      :  1;               /*!< [16..16] Wait for Read Mode                                           */
      __I  uint32_t  DVF4       :  1;               /*!< [17..17] Valid Flag                                                   */
      __I  uint32_t  DOF4       :  1;               /*!< [18..18] Overrun Flag                                                 */
    } bit;                                          /*!< [19] BitSize                                                          */
  } DIFFCH_OUT4;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x400040B0) Upper Threshold Filter Enable                          */
    
    struct {
      __IO uint32_t  FU_CH0_EN  :  1;               /*!< [0..0] Upper threshold IIR filter enable Channel 0                    */
      __IO uint32_t  FU_CH1_EN  :  1;               /*!< [1..1] Upper threshold IIR filter enable Channel 1                    */
      __IO uint32_t  FU_CH2_EN  :  1;               /*!< [2..2] Upper threshold IIR filter enable Channel 2                    */
      __IO uint32_t  FU_CH3_EN  :  1;               /*!< [3..3] Upper threshold IIR filter enable Channel 3                    */
      __IO uint32_t  FU_CH4_EN  :  1;               /*!< [4..4] Upper threshold IIR filter enable Channel 4                    */
      __IO uint32_t  FU_CH5_EN  :  1;               /*!< [5..5] Upper threshold IIR filter enable Channel 5                    */
      __IO uint32_t  FU_CH6_EN  :  1;               /*!< [6..6] Upper threshold IIR filter enable Channel 6                    */
      __IO uint32_t  FU_CH7_EN  :  1;               /*!< [7..7] Upper threshold IIR filter enable Channel 7                    */
      __IO uint32_t  FU_CH8_EN  :  1;               /*!< [8..8] Upper threshold IIR filter enable Channel 8                    */
      __IO uint32_t  FU_CH9_EN  :  1;               /*!< [9..9] Upper threshold IIR filter enable Channel 9                    */
      __IO uint32_t  FU_CH10_EN :  1;               /*!< [10..10] Upper threshold IIR filter enable Channel 10                 */
      __IO uint32_t  FU_CH11_EN :  1;               /*!< [11..11] Upper threshold IIR filter enable Channel 11                 */
    } bit;                                          /*!< [12] BitSize                                                          */
  } FILT_UP_CTRL;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x400040B4) Lower Threshold Filter Enable                          */
    
    struct {
      __IO uint32_t  FL_CH0_EN  :  1;               /*!< [0..0] Lower threshold IIR filter enable Channel 0                    */
      __IO uint32_t  FL_CH1_EN  :  1;               /*!< [1..1] Lower threshold IIR filter enable Channel 1                    */
      __IO uint32_t  FL_CH2_EN  :  1;               /*!< [2..2] Lower threshold IIR filter enable Channel 2                    */
      __IO uint32_t  FL_CH3_EN  :  1;               /*!< [3..3] Lower threshold IIR filter enable Channel 3                    */
      __IO uint32_t  FL_CH4_EN  :  1;               /*!< [4..4] Lower threshold IIR filter enable Channel 4                    */
      __IO uint32_t  FL_CH5_EN  :  1;               /*!< [5..5] Lower threshold IIR filter enable Channel 5                    */
      __IO uint32_t  FL_CH6_EN  :  1;               /*!< [6..6] Lower threshold IIR filter enable Channel 6                    */
      __IO uint32_t  FL_CH7_EN  :  1;               /*!< [7..7] Lower threshold IIR filter enable Channel 7                    */
      __IO uint32_t  FL_CH8_EN  :  1;               /*!< [8..8] Lower threshold IIR filter enable Channel 8                    */
      __IO uint32_t  FL_CH9_EN  :  1;               /*!< [9..9] Lower threshold IIR filter enable Channel 9                    */
      __IO uint32_t  FL_CH10_EN :  1;               /*!< [10..10] Lower threshold IIR filter enable Channel 10                 */
      __IO uint32_t  FL_CH11_EN :  1;               /*!< [11..11] Lower threshold IIR filter enable Channel 11                 */
    } bit;                                          /*!< [12] BitSize                                                          */
  } FILT_LO_CTRL;
  __I  uint32_t  RESERVED1;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x400040BC) ADC1 Status Register                                   */
    
    struct {
      __IO uint32_t  DAC_IN     :  3;               /*!< [0..2] Programs the 2-bit DAC for functional test                     */
           uint32_t             : 13;
      __IO uint32_t  SOC_JITTER :  2;               /*!< [16..17] Programs Soc Clock Jitter                                    */
           uint32_t             : 13;
      __IO uint32_t  SD_FEEDB_ON:  1;               /*!< [31..31] Sigma Delta Feedback Loop                                    */
    } bit;                                          /*!< [32] BitSize                                                          */
  } STATUS;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x400040C0) Lower Comparator Trigger Level Channel 8-11            */
    
    struct {
      __IO uint32_t  CH8_LOW    :  8;               /*!< [0..7] Channel 8 lower trigger level                                  */
      __IO uint32_t  CH9_LOW    :  8;               /*!< [8..15] Channel 9 lower trigger level                                 */
      __IO uint32_t  CH10_LOW   :  8;               /*!< [16..23] Channel 10 lower trigger level                               */
      __IO uint32_t  CH11_LOW   :  8;               /*!< [24..31] Channel 11 lower trigger level                               */
    } bit;                                          /*!< [32] BitSize                                                          */
  } TH8_11_LOWER;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x400040C4) Lower Comparator Trigger Level Differential Channel
                                                         1-4                                                                   */
    
    struct {
      __IO uint32_t  DCH1_LOW   :  8;               /*!< [0..7] Differential Channel 1 lower trigger level                     */
      __IO uint32_t  DCH2_LOW   :  8;               /*!< [8..15] Differential Channel 2 lower trigger level                    */
      __IO uint32_t  DCH3_LOW   :  8;               /*!< [16..23] Differential Channel 3 lower trigger level                   */
      __IO uint32_t  DCH4_LOW   :  8;               /*!< [24..31] Differential Channel 4 lower trigger level                   */
    } bit;                                          /*!< [32] BitSize                                                          */
  } DCHTH1_4_LOWER;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x400040C8) Upper Comparator Trigger Level Channel 0-3             */
    
    struct {
      __IO uint32_t  CH0_UP     :  8;               /*!< [0..7] Channel 0 upper trigger level                                  */
      __IO uint32_t  CH1_UP     :  8;               /*!< [8..15] Channel 1 upper trigger level                                 */
      __IO uint32_t  CH2_UP     :  8;               /*!< [16..23] Channel 2 upper trigger level                                */
      __IO uint32_t  CH3_UP     :  8;               /*!< [24..31] Channel 3 upper trigger level                                */
    } bit;                                          /*!< [32] BitSize                                                          */
  } TH0_3_UPPER;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x400040CC) Upper Comparator Trigger Level Channel 4-7             */
    
    struct {
      __IO uint32_t  CH4_UP     :  8;               /*!< [0..7] Channel 4 upper trigger level                                  */
      __IO uint32_t  CH5_UP     :  8;               /*!< [8..15] Channel 5 upper trigger level                                 */
      __IO uint32_t  CH6_UP     :  8;               /*!< [16..23] Channel 6upper trigger level                                 */
      __IO uint32_t  CH7_UP     :  8;               /*!< [24..31] Channel 7 upper trigger level                                */
    } bit;                                          /*!< [32] BitSize                                                          */
  } TH4_7_UPPER;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x400040D0) Upper Comparator Trigger Level Channel 8-11            */
    
    struct {
      __IO uint32_t  CH8_UP     :  8;               /*!< [0..7] Channel 8 upper trigger level                                  */
      __IO uint32_t  CH9_UP     :  8;               /*!< [8..15] Channel 9 upper trigger level                                 */
      __IO uint32_t  CH10_UP    :  8;               /*!< [16..23] Channel 10 upper trigger level                               */
      __IO uint32_t  CH11_UP    :  8;               /*!< [24..31] Channel 11 upper trigger level                               */
    } bit;                                          /*!< [32] BitSize                                                          */
  } TH8_11_UPPER;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x400040D4) Upper Comparator Trigger Level Differential Channel
                                                         1-4                                                                   */
    
    struct {
      __IO uint32_t  DCH1_UP    :  8;               /*!< [0..7] Differential Channel 1 upper trigger level                     */
      __IO uint32_t  DCH2_UP    :  8;               /*!< [8..15] Differential Channel 2 upper trigger level                    */
      __IO uint32_t  DCH3_UP    :  8;               /*!< [16..23] Differential Channel 3 upper trigger level                   */
      __IO uint32_t  DCH4_UP    :  8;               /*!< [24..31] Differential Channel 4 upper trigger level                   */
    } bit;                                          /*!< [32] BitSize                                                          */
  } DCHTH1_4_UPPER;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x400040D8) Lower Counter Trigger Level Channel 0-3                */
    
    struct {
      __IO uint32_t  CNT_LO_CH0 :  3;               /*!< [0..2] Lower timer trigger threshold channel 0                        */
      __IO uint32_t  HYST_LO_CH0:  2;               /*!< [3..4] Channel 0 lower hysteresis                                     */
           uint32_t             :  3;
      __IO uint32_t  CNT_LO_CH1 :  3;               /*!< [8..10] Lower timer trigger threshold channel 1                       */
      __IO uint32_t  HYST_LO_CH1:  2;               /*!< [11..12] Channel 1 lower hysteresis                                   */
           uint32_t             :  3;
      __IO uint32_t  CNT_LO_CH2 :  3;               /*!< [16..18] Lower timer trigger threshold channel 2                      */
      __IO uint32_t  HYST_LO_CH2:  2;               /*!< [19..20] Channel 2 lower hysteresis                                   */
           uint32_t             :  3;
      __IO uint32_t  CNT_LO_CH3 :  3;               /*!< [24..26] Lower timer trigger threshold channel 3                      */
      __IO uint32_t  HYST_LO_CH3:  2;               /*!< [27..28] Channel 3 lower hysteresis                                   */
    } bit;                                          /*!< [29] BitSize                                                          */
  } CNT0_3_LOWER;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x400040DC) Lower Counter Trigger Level Channel 4-7                */
    
    struct {
      __IO uint32_t  CNT_LO_CH4 :  3;               /*!< [0..2] Lower timer trigger threshold channel 4                        */
      __IO uint32_t  HYST_LO_CH4:  2;               /*!< [3..4] Channel 4 lower hysteresis                                     */
           uint32_t             :  3;
      __IO uint32_t  CNT_LO_CH5 :  3;               /*!< [8..10] Lower timer trigger threshold channel 5                       */
      __IO uint32_t  HYST_LO_CH5:  2;               /*!< [11..12] Channel 5 lower hysteresis                                   */
           uint32_t             :  3;
      __IO uint32_t  CNT_LO_CH6 :  3;               /*!< [16..18] Lower timer trigger threshold channel 6                      */
      __IO uint32_t  HYST_LO_CH6:  2;               /*!< [19..20] Channel 6 lower hysteresis                                   */
           uint32_t             :  3;
      __IO uint32_t  CNT_LO_CH7 :  3;               /*!< [24..26] Lower timer trigger threshold channel 7                      */
      __IO uint32_t  HYST_LO_CH7:  2;               /*!< [27..28] Channel 7 lower hysteresis                                   */
    } bit;                                          /*!< [29] BitSize                                                          */
  } CNT4_7_LOWER;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x400040E0) Lower Counter Trigger Level Channel 8-11               */
    
    struct {
      __IO uint32_t  CNT_LO_CH8 :  3;               /*!< [0..2] Lower timer trigger threshold channel 8                        */
      __IO uint32_t  HYST_LO_CH8:  2;               /*!< [3..4] Channel 8 lower hysteresis                                     */
           uint32_t             :  3;
      __IO uint32_t  CNT_LO_CH9 :  3;               /*!< [8..10] Lower timer trigger threshold channel 9                       */
      __IO uint32_t  HYST_LO_CH9:  2;               /*!< [11..12] Channel 9 lower hysteresis                                   */
           uint32_t             :  3;
      __IO uint32_t  CNT_LO_CH10:  3;               /*!< [16..18] Lower timer trigger threshold channel 10                     */
      __IO uint32_t  HYST_LO_CH10:  2;              /*!< [19..20] Channel 10 lower hysteresis                                  */
           uint32_t             :  3;
      __IO uint32_t  CNT_LO_CH11:  3;               /*!< [24..26] Lower timer trigger threshold channel 11                     */
      __IO uint32_t  HYST_LO_CH11:  2;              /*!< [27..28] Channel 11 lower hysteresis                                  */
    } bit;                                          /*!< [29] BitSize                                                          */
  } CNT8_11_LOWER;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x400040E4) Lower Counter Trigger Level Differential Channel
                                                         1-4                                                                   */
    
    struct {
      __IO uint32_t  CNT_LO_DCH1:  3;               /*!< [0..2] Lower timer trigger threshold differential channel 1           */
      __IO uint32_t  HYST_LO_DCH1:  2;              /*!< [3..4] Differential Channel 1 lower hysteresis                        */
           uint32_t             :  3;
      __IO uint32_t  CNT_LO_DCH2:  3;               /*!< [8..10] Lower timer trigger threshold differential channel 2          */
      __IO uint32_t  HYST_LO_DCH2:  2;              /*!< [11..12] Differential Channel 2 lower hysteresis                      */
           uint32_t             :  3;
      __IO uint32_t  CNT_LO_DCH3:  3;               /*!< [16..18] Lower timer trigger threshold differential channel
                                                         3                                                                     */
      __IO uint32_t  HYST_LO_DCH3:  2;              /*!< [19..20] Differential Channel 3 lower hysteresis                      */
           uint32_t             :  3;
      __IO uint32_t  CNT_LO_DCH4:  3;               /*!< [24..26] Lower timer trigger threshold differential channel
                                                         4                                                                     */
      __IO uint32_t  HYST_LO_DCH4:  2;              /*!< [27..28] Differential Channel 4 lower hysteresis                      */
    } bit;                                          /*!< [29] BitSize                                                          */
  } DCHCNT1_4_LOWER;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x400040E8) Upper Counter Trigger Level Channel 0-3                */
    
    struct {
      __IO uint32_t  CNT_UP_CH0 :  3;               /*!< [0..2] Upper timer trigger threshold channel 0                        */
      __IO uint32_t  HYST_UP_CH0:  2;               /*!< [3..4] Channel 0 upper hysteresis                                     */
           uint32_t             :  3;
      __IO uint32_t  CNT_UP_CH1 :  3;               /*!< [8..10] Upper timer trigger threshold channel 1                       */
      __IO uint32_t  HYST_UP_CH1:  2;               /*!< [11..12] Channel 1 upper hysteresis                                   */
           uint32_t             :  3;
      __IO uint32_t  CNT_UP_CH2 :  3;               /*!< [16..18] Upper timer trigger threshold channel 2                      */
      __IO uint32_t  HYST_UP_CH2:  2;               /*!< [19..20] Channel 2 upper hysteresis                                   */
           uint32_t             :  3;
      __IO uint32_t  CNT_UP_CH3 :  3;               /*!< [24..26] Upper timer trigger threshold channel 3                      */
      __IO uint32_t  HYST_UP_CH3:  2;               /*!< [27..28] Channel 3 upper hysteresis                                   */
    } bit;                                          /*!< [29] BitSize                                                          */
  } CNT0_3_UPPER;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x400040EC) Upper Counter Trigger Level Channel 4-7                */
    
    struct {
      __IO uint32_t  CNT_UP_CH4 :  3;               /*!< [0..2] Upper timer trigger threshold channel 4                        */
      __IO uint32_t  HYST_UP_CH4:  2;               /*!< [3..4] Channel 4 upper hysteresis                                     */
           uint32_t             :  3;
      __IO uint32_t  CNT_UP_CH5 :  3;               /*!< [8..10] Upper timer trigger threshold channel 5                       */
      __IO uint32_t  HYST_UP_CH5:  2;               /*!< [11..12] Channel 5 upper hysteresis                                   */
           uint32_t             :  3;
      __IO uint32_t  CNT_UP_CH6 :  3;               /*!< [16..18] Upper timer trigger threshold channel 6                      */
      __IO uint32_t  HYST_UP_CH6:  2;               /*!< [19..20] Channel 6 upper hysteresis                                   */
           uint32_t             :  3;
      __IO uint32_t  CNT_UP_CH7 :  3;               /*!< [24..26] Upper timer trigger threshold channel 7                      */
      __IO uint32_t  HYST_UP_CH7:  2;               /*!< [27..28] Channel 7 upper hysteresis                                   */
    } bit;                                          /*!< [29] BitSize                                                          */
  } CNT4_7_UPPER;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x400040F0) Upper Counter Trigger Level Channel 8-11               */
    
    struct {
      __IO uint32_t  CNT_UP_CH8 :  3;               /*!< [0..2] Upper timer trigger threshold channel 8                        */
      __IO uint32_t  HYST_UP_CH8:  2;               /*!< [3..4] Channel 8 upper hysteresis                                     */
           uint32_t             :  3;
      __IO uint32_t  CNT_UP_CH9 :  3;               /*!< [8..10] Upper timer trigger threshold channel 9                       */
      __IO uint32_t  HYST_UP_CH9:  2;               /*!< [11..12] Channel 9 upper hysteresis                                   */
           uint32_t             :  3;
      __IO uint32_t  CNT_UP_CH10:  3;               /*!< [16..18] Upper timer trigger threshold channel 10                     */
      __IO uint32_t  HYST_UP_CH10:  2;              /*!< [19..20] Channel 10 upper hysteresis                                  */
           uint32_t             :  3;
      __IO uint32_t  CNT_UP_CH11:  3;               /*!< [24..26] Upper timer trigger threshold channel 11                     */
      __IO uint32_t  HYST_UP_CH11:  2;              /*!< [27..28] Channel 11 upper hysteresis                                  */
    } bit;                                          /*!< [29] BitSize                                                          */
  } CNT8_11_UPPER;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x400040F4) Upper Counter Trigger Level Differential Channel
                                                         1-4                                                                   */
    
    struct {
      __IO uint32_t  CNT_UP_DCH1:  3;               /*!< [0..2] Upper timer trigger threshold differential channel 1           */
      __IO uint32_t  HYST_UP_DCH1:  2;              /*!< [3..4] Differential Channel 1 upper hysteresis                        */
           uint32_t             :  3;
      __IO uint32_t  CNT_UP_DCH2:  3;               /*!< [8..10] Upper timer trigger threshold differential channel 2          */
      __IO uint32_t  HYST_UP_DCH2:  2;              /*!< [11..12] Differential Channel 2 upper hysteresis                      */
           uint32_t             :  3;
      __IO uint32_t  CNT_UP_DCH3:  3;               /*!< [16..18] Upper timer trigger threshold differential channel
                                                         3                                                                     */
      __IO uint32_t  HYST_UP_DCH3:  2;              /*!< [19..20] Differential Channel 3 upper hysteresis                      */
           uint32_t             :  3;
      __IO uint32_t  CNT_UP_DCH4:  3;               /*!< [24..26] Upper timer trigger threshold differential channel
                                                         4                                                                     */
      __IO uint32_t  HYST_UP_DCH4:  2;              /*!< [27..28] Differential Channel 4 upper hysteresis                      */
    } bit;                                          /*!< [29] BitSize                                                          */
  } DCHCNT1_4_UPPER;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x400040F8) Overvoltage Measurement Mode of Ch 0-11                */
    
    struct {
      __IO uint32_t  MMODE_0    :  2;               /*!< [0..1] Measurement mode Channel 0                                     */
      __IO uint32_t  MMODE_1    :  2;               /*!< [2..3] Measurement mode Channel 1                                     */
      __IO uint32_t  MMODE_2    :  2;               /*!< [4..5] Measurement mode Channel 2                                     */
      __IO uint32_t  MMODE_3    :  2;               /*!< [6..7] Measurement mode Channel 3                                     */
      __IO uint32_t  MMODE_4    :  2;               /*!< [8..9] Measurement mode Channel 4                                     */
      __IO uint32_t  MMODE_5    :  2;               /*!< [10..11] Measurement mode Channel 5                                   */
      __IO uint32_t  MMODE_6    :  2;               /*!< [12..13] Measurement mode Channel 6                                   */
      __IO uint32_t  MMODE_7    :  2;               /*!< [14..15] Measurement mode Channel 7                                   */
      __IO uint32_t  MMODE_8    :  2;               /*!< [16..17] Measurement mode Channel 8                                   */
      __IO uint32_t  MMODE_9    :  2;               /*!< [18..19] Measurement mode Channel 9                                   */
      __IO uint32_t  MMODE_10   :  2;               /*!< [20..21] Measurement mode Channel 10                                  */
      __IO uint32_t  MMODE_11   :  2;               /*!< [22..23] Measurement mode Channel 11                                  */
      __IO uint32_t  MMODE_D1   :  2;               /*!< [24..25] Measurement mode Differential Channel 1                      */
      __IO uint32_t  MMODE_D2   :  2;               /*!< [26..27] Measurement mode Differential Channel 2                      */
      __IO uint32_t  MMODE_D3   :  2;               /*!< [28..29] Measurement mode Differential Channel 3                      */
      __IO uint32_t  MMODE_D4   :  2;               /*!< [30..31] Measurement mode Differential Channel 4                      */
    } bit;                                          /*!< [32] BitSize                                                          */
  } MMODE0_11;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x400040FC) Measurement Unit 1 - Differential Unit Input
                                                         Selection Register                                                    */
    
    struct {
      __IO uint32_t  DU1_EN     :  1;               /*!< [0..0] Differential Unit 1 enable                                     */
           uint32_t             :  3;
      __I  uint32_t  DU1RES_NEG :  1;               /*!< [4..4] Differential Unit 1 result negative                            */
           uint32_t             :  3;
      __IO uint32_t  DU2_EN     :  1;               /*!< [8..8] Differential Unit 2 enable                                     */
           uint32_t             :  3;
      __I  uint32_t  DU2RES_NEG :  1;               /*!< [12..12] Differential Unit 2 result negative                          */
           uint32_t             :  3;
      __IO uint32_t  DU3_EN     :  1;               /*!< [16..16] Differential Unit 3 enable                                   */
           uint32_t             :  3;
      __I  uint32_t  DU3RES_NEG :  1;               /*!< [20..20] Differential Unit 3 result negative                          */
           uint32_t             :  3;
      __IO uint32_t  DU4_EN     :  1;               /*!< [24..24] Differential Unit 4 enable                                   */
           uint32_t             :  3;
      __I  uint32_t  DU4RES_NEG :  1;               /*!< [28..28] Differential Unit 4 result negative                          */
    } bit;                                          /*!< [29] BitSize                                                          */
  } DUIN_SEL;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x40004100) ADC1 Interrupt Status 2 Register                       */
    
    struct {
           uint32_t             :  1;
      __IO uint32_t  VS_LO_IS   :  1;               /*!< [1..1] ADC1 VS Lower Threshold Interrupt Status                       */
      __IO uint32_t  MON1_LO_IS :  1;               /*!< [2..2] ADC1 MON 1 Lower Threshold Interrupt Status                    */
      __IO uint32_t  MON2_LO_IS :  1;               /*!< [3..3] ADC1 MON 2 Lower Threshold Interrupt Status                    */
      __IO uint32_t  MON3_LO_IS :  1;               /*!< [4..4] ADC1 MON 3 Lower Threshold Interrupt Status                    */
      __IO uint32_t  MON4_LO_IS :  1;               /*!< [5..5] ADC1 MON 4 Lower Threshold Interrupt Status                    */
      __IO uint32_t  MON5_LO_IS :  1;               /*!< [6..6] ADC1 MON 5 Lower Threshold Interrupt Status                    */
      __IO uint32_t  P2_1_LO_IS :  1;               /*!< [7..7] ADC1 Port 2.1 Lower Threshold Interrupt Status                 */
      __IO uint32_t  P2_2_LO_IS :  1;               /*!< [8..8] ADC1 Port 2.2 Lower Threshold Interrupt Status                 */
      __IO uint32_t  P2_3_LO_IS :  1;               /*!< [9..9] ADC1 Port 2.3 Lower Threshold Interrupt Status                 */
      __IO uint32_t  P2_6_LO_IS :  1;               /*!< [10..10] ADC1 Port 2.6 Lower Threshold Interrupt Status               */
      __IO uint32_t  P2_7_LO_IS :  1;               /*!< [11..11] ADC1 Port 2.7 Lower Threshold Interrupt Status               */
           uint32_t             :  5;
      __IO uint32_t  VS_UP_IS   :  1;               /*!< [17..17] ADC1 VS Upper Threshold Interrupt Status                     */
      __IO uint32_t  MON1_UP_IS :  1;               /*!< [18..18] ADC1 MON 1 Upper Threshold Interrupt Status                  */
      __IO uint32_t  MON2_UP_IS :  1;               /*!< [19..19] ADC1 MON 2 Upper Threshold Interrupt Status                  */
      __IO uint32_t  MON3_UP_IS :  1;               /*!< [20..20] ADC1 MON 3 Upper Threshold Interrupt Status                  */
      __IO uint32_t  MON4_UP_IS :  1;               /*!< [21..21] ADC1 MON 4 Upper Threshold Interrupt Status                  */
      __IO uint32_t  MON5_UP_IS :  1;               /*!< [22..22] ADC1 MON 5 Upper Threshold Interrupt Status                  */
      __IO uint32_t  P2_1_UP_IS :  1;               /*!< [23..23] ADC1 Port 2.1 Upper Threshold Interrupt Status               */
      __IO uint32_t  P2_2_UP_IS :  1;               /*!< [24..24] ADC1 Port 2.2 Upper Threshold Interrupt Status               */
      __IO uint32_t  P2_3_UP_IS :  1;               /*!< [25..25] ADC1 Port 2.3 Upper Threshold Interrupt Status               */
      __IO uint32_t  P2_6_UP_IS :  1;               /*!< [26..26] ADC1 Port 2.6 Upper Threshold Interrupt Status               */
      __IO uint32_t  P2_7_UP_IS :  1;               /*!< [27..27] ADC1 Port 2.7 Upper Threshold Interrupt Status               */
    } bit;                                          /*!< [28] BitSize                                                          */
  } IRQS_2;
  
  union {
    __I  uint32_t  reg;                             /*!< (@ 0x40004104) ADC1 Status 2 Register                                 */
    
    struct {
           uint32_t             :  1;
      __I  uint32_t  VS_LO_STS  :  1;               /*!< [1..1] ADC1 VS Lower Threshold Status                                 */
      __I  uint32_t  MON1_LO_STS:  1;               /*!< [2..2] ADC1 MON 1 Lower Threshold Status                              */
      __I  uint32_t  MON2_LO_STS:  1;               /*!< [3..3] ADC1 MON 2 Lower Threshold Status                              */
      __I  uint32_t  MON3_LO_STS:  1;               /*!< [4..4] ADC1 MON 3 Lower Threshold Status                              */
      __I  uint32_t  MON4_LO_STS:  1;               /*!< [5..5] ADC1 MON 4 Lower Threshold Status                              */
      __I  uint32_t  MON5_LO_STS:  1;               /*!< [6..6] ADC1 MON 5 Lower Threshold Status                              */
      __I  uint32_t  P2_1_LO_STS:  1;               /*!< [7..7] ADC1 Port 2.1 Lower Threshold Status                           */
      __I  uint32_t  P2_2_LO_STS:  1;               /*!< [8..8] ADC1 Port 2.2 Lower Threshold Status                           */
      __I  uint32_t  P2_3_LO_STS:  1;               /*!< [9..9] ADC1 Port 2.3 Lower Threshold Status                           */
      __I  uint32_t  P2_6_LO_STS:  1;               /*!< [10..10] ADC1 Port 2.6 Lower Threshold Status                         */
      __I  uint32_t  P2_7_LO_STS:  1;               /*!< [11..11] ADC1 Port 2.7 Lower Threshold Status                         */
           uint32_t             :  5;
      __I  uint32_t  VS_UP_STS  :  1;               /*!< [17..17] ADC1 VS Upper Threshold Status                               */
      __I  uint32_t  MON1_UP_STS:  1;               /*!< [18..18] ADC1 MON 1 Upper Threshold Status                            */
      __I  uint32_t  MON2_UP_STS:  1;               /*!< [19..19] ADC1 MON 2 Upper Threshold Status                            */
      __I  uint32_t  MON3_UP_STS:  1;               /*!< [20..20] ADC1 MON 3 Upper Threshold Status                            */
      __I  uint32_t  MON4_UP_STS:  1;               /*!< [21..21] ADC1 MON 4 Upper Threshold Status                            */
      __I  uint32_t  MON5_UP_STS:  1;               /*!< [22..22] ADC1 MON 5 Upper Threshold Status                            */
      __I  uint32_t  P2_1_UP_STS:  1;               /*!< [23..23] ADC1 Port 2.1 Upper Threshold Status                         */
      __I  uint32_t  P2_2_UP_STS:  1;               /*!< [24..24] ADC1 Port 2.2 Upper Threshold Status                         */
      __I  uint32_t  P2_3_UP_STS:  1;               /*!< [25..25] ADC1 Port 2.3 Upper Threshold Status                         */
      __I  uint32_t  P2_6_UP_STS:  1;               /*!< [26..26] ADC1 Port 2.6 Upper Threshold Status                         */
      __I  uint32_t  P2_7_UP_STS:  1;               /*!< [27..27] ADC1 Port 2.7 Upper Threshold Status                         */
    } bit;                                          /*!< [28] BitSize                                                          */
  } STS_2;
  
  union {
    __O  uint32_t  reg;                             /*!< (@ 0x40004108) ADC1 Interrupt Status Clear 2 Register                 */
    
    struct {
           uint32_t             :  1;
      __O  uint32_t  VS_LO_ISC  :  1;               /*!< [1..1] ADC1 VS Lower Threshold Interrupt Status Clear                 */
      __O  uint32_t  MON1_LO_ISC:  1;               /*!< [2..2] ADC1 MON 1 Lower Threshold Interrupt Status Clear              */
      __O  uint32_t  MON2_LO_ISC:  1;               /*!< [3..3] ADC1 MON 2 Lower Threshold Interrupt Status Clear              */
      __O  uint32_t  MON3_LO_ISC:  1;               /*!< [4..4] ADC1 MON 3 Lower Threshold Interrupt Status Clear              */
      __O  uint32_t  MON4_LO_ISC:  1;               /*!< [5..5] ADC1 MON 4 Lower Threshold Interrupt Status Clear              */
      __O  uint32_t  MON5_LO_ISC:  1;               /*!< [6..6] ADC1 MON 5 Lower Threshold Interrupt Status Clear              */
      __O  uint32_t  P2_1_LO_ISC:  1;               /*!< [7..7] ADC1 Port 2.1 Lower Threshold Interrupt Status Clear           */
      __O  uint32_t  P2_2_LO_ISC:  1;               /*!< [8..8] ADC1 Port 2.2 Lower Threshold Interrupt Status Clear           */
      __O  uint32_t  P2_3_LO_ISC:  1;               /*!< [9..9] ADC1 Port 2.3 Lower Threshold Interrupt Status Clear           */
      __O  uint32_t  P2_6_LO_ISC:  1;               /*!< [10..10] ADC1 Port 2.6 Lower Threshold Interrupt Status Clear         */
      __O  uint32_t  P2_7_LO_ISC:  1;               /*!< [11..11] ADC1 Port 2.7 Lower Threshold Interrupt Status Clear         */
           uint32_t             :  5;
      __O  uint32_t  VS_UP_ISC  :  1;               /*!< [17..17] ADC1 VS Upper Threshold Interrupt Status Clear               */
      __O  uint32_t  MON1_UP_ISC:  1;               /*!< [18..18] ADC1 MON 1 Upper Threshold Interrupt Status Clear            */
      __O  uint32_t  MON2_UP_ISC:  1;               /*!< [19..19] ADC1 MON 2 Upper Threshold Interrupt Status Clear            */
      __O  uint32_t  MON3_UP_ISC:  1;               /*!< [20..20] ADC1 MON 3 Upper Threshold Interrupt Status Clear            */
      __O  uint32_t  MON4_UP_ISC:  1;               /*!< [21..21] ADC1 MON 4 Upper Threshold Interrupt Status Clear            */
      __O  uint32_t  MON5_UP_ISC:  1;               /*!< [22..22] ADC1 MON 5 Upper Threshold Interrupt Status Clear            */
      __O  uint32_t  P2_1_UP_ISC:  1;               /*!< [23..23] ADC1 Port 2.1 Upper Threshold Interrupt Status Clear         */
      __O  uint32_t  P2_2_UP_ISC:  1;               /*!< [24..24] ADC1 Port 2.2 Upper Threshold Interrupt Status Clear         */
      __O  uint32_t  P2_3_UP_ISC:  1;               /*!< [25..25] ADC1 Port 2.3 Upper Threshold Interrupt Status Clear         */
      __O  uint32_t  P2_6_UP_ISC:  1;               /*!< [26..26] ADC1 Port 2.6 Upper Threshold Interrupt Status Clear         */
      __O  uint32_t  P2_7_UP_ISC:  1;               /*!< [27..27] ADC1 Port 2.7 Upper Threshold Interrupt Status Clear         */
    } bit;                                          /*!< [28] BitSize                                                          */
  } IRQCLR_2;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x4000410C) ADC1 Interrupt Enable 2 Register                       */
    
    struct {
           uint32_t             :  1;
      __IO uint32_t  VS_LO_IEN  :  1;               /*!< [1..1] ADC1 VS Lower Threshold Interrupt Enable                       */
      __IO uint32_t  MON1_LO_IEN:  1;               /*!< [2..2] ADC1 MON 1 Lower Threshold Interrupt Enable                    */
      __IO uint32_t  MON2_LO_IEN:  1;               /*!< [3..3] ADC1 MON 2 Lower Threshold Interrupt Enable                    */
      __IO uint32_t  MON3_LO_IEN:  1;               /*!< [4..4] ADC1 MON 3 Lower Threshold Interrupt Enable                    */
      __IO uint32_t  MON4_LO_IEN:  1;               /*!< [5..5] ADC1 MON 4 Lower Threshold Interrupt Enable                    */
      __IO uint32_t  MON5_LO_IEN:  1;               /*!< [6..6] ADC1 MON 5 Lower Threshold Interrupt Enable                    */
      __IO uint32_t  P2_1_LO_IEN:  1;               /*!< [7..7] ADC1 Port 2.1 Lower Threshold Interrupt Enable                 */
      __IO uint32_t  P2_2_LO_IEN:  1;               /*!< [8..8] ADC1 Port 2.2 Lower Threshold Interrupt Enable                 */
      __IO uint32_t  P2_3_LO_IEN:  1;               /*!< [9..9] ADC1 Port 2.3 Lower Threshold Interrupt Enable                 */
      __IO uint32_t  P2_6_LO_IEN:  1;               /*!< [10..10] ADC1 Port 2.6 Lower Threshold Interrupt Enable               */
      __IO uint32_t  P2_7_LO_IEN:  1;               /*!< [11..11] ADC1 Port 2.7 Lower Threshold Interrupt Enable               */
           uint32_t             :  5;
      __IO uint32_t  VS_UP_IEN  :  1;               /*!< [17..17] ADC1 VS Upper Threshold Interrupt Enable                     */
      __IO uint32_t  MON1_UP_IEN:  1;               /*!< [18..18] ADC1 MON 1 Upper Threshold Interrupt Enable                  */
      __IO uint32_t  MON2_UP_IEN:  1;               /*!< [19..19] ADC1 MON 2 Upper Threshold Interrupt Enable                  */
      __IO uint32_t  MON3_UP_IEN:  1;               /*!< [20..20] ADC1 MON 3 Upper Threshold Interrupt Enable                  */
      __IO uint32_t  MON4_UP_IEN:  1;               /*!< [21..21] ADC1 MON 4 Upper Threshold Interrupt Enable                  */
      __IO uint32_t  MON5_UP_IEN:  1;               /*!< [22..22] ADC1 MON 5 Upper Threshold Interrupt Enable                  */
      __IO uint32_t  P2_1_UP_IEN:  1;               /*!< [23..23] ADC1 Port 2.1 Upper Threshold Interrupt Enable               */
      __IO uint32_t  P2_2_UP_IEN:  1;               /*!< [24..24] ADC1 Port 2.2 Upper Threshold Interrupt Enable               */
      __IO uint32_t  P2_3_UP_IEN:  1;               /*!< [25..25] ADC1 Port 2.3 Upper Threshold Interrupt Enable               */
      __IO uint32_t  P2_6_UP_IEN:  1;               /*!< [26..26] ADC1 Port 2.6 Upper Threshold Interrupt Enable               */
      __IO uint32_t  P2_7_UP_IEN:  1;               /*!< [27..27] ADC1 Port 2.7 Upper Threshold Interrupt Enable               */
    } bit;                                          /*!< [28] BitSize                                                          */
  } IRQEN_2;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x40004110) ADC1 or Filter Output Channel 12                       */
    
    struct {
      __I  uint32_t  FILT_OUT_CH12: 12;             /*!< [0..11] ADC or filter output value channel 12                         */
           uint32_t             :  4;
      __IO uint32_t  WFR12      :  1;               /*!< [16..16] Wait for Read Mode                                           */
      __I  uint32_t  VF12       :  1;               /*!< [17..17] Valid Flag                                                   */
      __I  uint32_t  OF12       :  1;               /*!< [18..18] Overrun Flag                                                 */
    } bit;                                          /*!< [19] BitSize                                                          */
  } FILT_OUT12;
  __I  uint32_t  RESERVED2[3];
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x40004120) ADC1 or Filter Output of EIM                           */
    
    struct {
      __I  uint32_t  FILT_OUT_EIM: 12;              /*!< [0..11] ADC or filter output value for last EIM measurement           */
           uint32_t             :  4;
      __IO uint32_t  WFR_EIM    :  1;               /*!< [16..16] Wait for Read Mode                                           */
      __I  uint32_t  VF_EIM     :  1;               /*!< [17..17] Valid Flag                                                   */
      __I  uint32_t  OF_EIM     :  1;               /*!< [18..18] Overrun Flag                                                 */
    } bit;                                          /*!< [19] BitSize                                                          */
  } FILT_OUTEIM;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x40004124) ADC1 Status 1 Register                                 */
    
    struct {
           uint32_t             : 24;
      __IO uint32_t  DU1LO_STS  :  1;               /*!< [24..24] ADC1 Differential Unit 1 (DU1) lower Channel Status          */
      __IO uint32_t  DU1UP_STS  :  1;               /*!< [25..25] ADC1 Differential Unit 1 (DU1) upper Channel Status          */
      __IO uint32_t  DU2LO_STS  :  1;               /*!< [26..26] ADC1 Differential Unit 2 (DU2) lower Channel Status          */
      __IO uint32_t  DU2UP_STS  :  1;               /*!< [27..27] ADC1 Differential Unit 2 (DU2) upper Channel Status          */
      __IO uint32_t  DU3LO_STS  :  1;               /*!< [28..28] ADC1 Differential Unit 3 (DU3) lower Channel Status          */
      __IO uint32_t  DU3UP_STS  :  1;               /*!< [29..29] ADC1 Differential Unit 3 (DU3) upper Channel Status          */
      __IO uint32_t  DU4LO_STS  :  1;               /*!< [30..30] ADC1 Differential Unit 4 (DU4) lower Channel Status          */
      __IO uint32_t  DU4UP_STS  :  1;               /*!< [31..31] ADC1 Differential Unit 4 (DU4) upper Channel Status          */
    } bit;                                          /*!< [32] BitSize                                                          */
  } STS_1;
  
  union {
    __O  uint32_t  reg;                             /*!< (@ 0x40004128) ADC1 Status Clear 1 Register                           */
    
    struct {
           uint32_t             : 24;
      __O  uint32_t  DU1LO_SC   :  1;               /*!< [24..24] ADC1 Differential Unit 1 (DU1) lower Channel Status
                                                         Clear                                                                 */
      __O  uint32_t  DU1UP_SC   :  1;               /*!< [25..25] ADC1 Differential Unit 1 (DU1) upper Channel Status
                                                         Clear                                                                 */
      __O  uint32_t  DU2LO_SC   :  1;               /*!< [26..26] ADC1 Differential Unit 2 (DU2) lower Channel Status
                                                         Clear                                                                 */
      __O  uint32_t  DU2UP_SC   :  1;               /*!< [27..27] ADC1 Differential Unit 2 (DU2) upper Channel Status
                                                         Clear                                                                 */
      __O  uint32_t  DU3LO_SC   :  1;               /*!< [28..28] ADC1 Differential Unit 3 (DU3) lower Channel Status
                                                         Clear                                                                 */
      __O  uint32_t  DU3UP_SC   :  1;               /*!< [29..29] ADC1 Differential Unit 3 (DU3) upper Channel Status
                                                         Clear                                                                 */
      __O  uint32_t  DU4LO_SC   :  1;               /*!< [30..30] ADC1 Differential Unit 4 (DU4) lower Channel Status
                                                         Clear                                                                 */
      __O  uint32_t  DU4UP_SC   :  1;               /*!< [31..31] ADC1 Differential Unit 4 (DU4) upper Channel Status
                                                         Clear                                                                 */
    } bit;                                          /*!< [32] BitSize                                                          */
  } STSCLR_1;
} ADC1_Type;


/* ================================================================================ */
/* ================                      ADC2                      ================ */
/* ================================================================================ */


/**
  * @brief ADC2 (ADC2)
  */

typedef struct {                                    /*!< (@ 0x4801C000) ADC2 Structure                                         */
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x4801C000) ADC2 Control and Status Register                       */
    
    struct {
           uint32_t             :  2;
      __IO uint32_t  SOS        :  1;               /*!< [2..2] ADC2 Start of Sampling/Conversion (software mode)              */
      __I  uint32_t  EOC        :  1;               /*!< [3..3] ADC2 End of Conversion (software mode)                         */
           uint32_t             :  4;
      __IO uint32_t  IN_MUX_SEL :  4;               /*!< [8..11] Channel for software mode                                     */
    } bit;                                          /*!< [12] BitSize                                                          */
  } CTRL_STS;
  
  union {
    __I  uint32_t  reg;                             /*!< (@ 0x4801C004) Sequencer Feedback Register                            */
    
    struct {
      __I  uint32_t  SQ_FB      :  4;               /*!< [0..3] Current Sequence that caused software mode                     */
           uint32_t             :  4;
      __I  uint32_t  SQ_STOP    :  1;               /*!< [8..8] ADC2 Sequencer Stop Signal for DPP                             */
      __I  uint32_t  EIM_ACTIVE :  1;               /*!< [9..9] ADC2 EIM active                                                */
           uint32_t             :  1;
      __I  uint32_t  SQx_STS    :  3;               /*!< [11..13] Current Active ADC2 Sequence                                 */
           uint32_t             :  2;
      __I  uint32_t  CHx_STS    :  4;               /*!< [16..19] Current ADC2 Channel                                         */
    } bit;                                          /*!< [20] BitSize                                                          */
  } SQ_FB;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x4801C008) Channel Settings Bits for Exceptional Interrupt
                                                         Measurement                                                           */
    
    struct {
      __IO uint32_t  CHx_SEL    :  3;               /*!< [0..2] Channel set for exceptional interrupt measurement (EIM)        */
           uint32_t             :  5;
      __IO uint32_t  REP        :  3;               /*!< [8..10] Repeat count for exceptional interrupt measurement (EIM)      */
      __IO uint32_t  EN         :  1;               /*!< [11..11] Exceptional interrupt measurement (EIM) Trigger Event
                                                         enable                                                                */
      __IO uint32_t  SEL        :  1;               /*!< [12..12] Exceptional interrupt measurement (EIM) Trigger select       */
    } bit;                                          /*!< [13] BitSize                                                          */
  } CHx_EIM;
  __I  uint32_t  RESERVED;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x4801C010) Maximum Time for Software Mode                         */
    
    struct {
      __IO uint32_t  MAX_TIME   :  8;               /*!< [0..7] Maximum Time in Software Mode                                  */
    } bit;                                          /*!< [8] BitSize                                                           */
  } MAX_TIME;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x4801C014) Measurement Unit Control Register 1                    */
    
    struct {
      __IO uint32_t  CALIB_EN_6_0:  7;              /*!< [0..6] Calibration Enable for Channels 6 to 0                         */
    } bit;                                          /*!< [7] BitSize                                                           */
  } CTRL1;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x4801C018) Measurement Unit Control Register 2                    */
    
    struct {
      __IO uint32_t  MCM_PD_N   :  1;               /*!< [0..0] Power Down Signal for MCM                                      */
           uint32_t             :  6;
      __I  uint32_t  MCM_RDY    :  1;               /*!< [7..7] Ready Signal for MCM after Power On or Reset                   */
      __IO uint32_t  SAMPLE_TIME_int:  4;           /*!< [8..11] Sample time of ADC2                                           */
    } bit;                                          /*!< [12] BitSize                                                          */
  } CTRL2;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x4801C01C) Measurement Unit Control Register 4                    */
    
    struct {
      __IO uint32_t  FILT_OUT_SEL_6_0:  7;          /*!< [0..6] Output Filter Selection for Channels 0 to 5                    */
    } bit;                                          /*!< [7] BitSize                                                           */
  } CTRL4;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x4801C020) Measurement Channel Enable Bits for Cycle 1-4          */
    
    struct {
      __IO uint32_t  SQ1        :  7;               /*!< [0..6] Sequence 1 channel enable                                      */
           uint32_t             :  1;
      __IO uint32_t  SQ2        :  7;               /*!< [8..14] Sequence 2 channel enable                                     */
           uint32_t             :  1;
      __IO uint32_t  SQ3        :  7;               /*!< [16..22] Sequence 3 channel enable                                    */
           uint32_t             :  1;
      __IO uint32_t  SQ4        :  7;               /*!< [24..30] Sequence 4 channel enable                                    */
    } bit;                                          /*!< [31] BitSize                                                          */
  } SQ1_4;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x4801C024) Measurement Channel Enable Bits for Cycle 5 -
                                                         8                                                                     */
    
    struct {
      __IO uint32_t  SQ5        :  7;               /*!< [0..6] Sequence 5 channel enable                                      */
           uint32_t             :  1;
      __IO uint32_t  SQ6        :  7;               /*!< [8..14] Sequence 6 channel enable                                     */
           uint32_t             :  1;
      __IO uint32_t  SQ7        :  7;               /*!< [16..22] Sequence 7 channel enable                                    */
    } bit;                                          /*!< [23] BitSize                                                          */
  } SQ5_8;
  __I  uint32_t  RESERVED1[3];
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x4801C034) Calibration for Channel 0 & 1                          */
    
    struct {
      __IO uint32_t  OFFS_CH0   :  5;               /*!< [0..4] Offset Calibration for channel 0                               */
           uint32_t             :  3;
      __IO uint32_t  GAIN_CH0   :  8;               /*!< [8..15] Gain Calibration for channel 0                                */
      __IO uint32_t  OFFS_CH1   :  5;               /*!< [16..20] Offset Calibration for channel 1                             */
           uint32_t             :  3;
      __IO uint32_t  GAIN_CH1   :  8;               /*!< [24..31] Gain Calibration for channel 1                               */
    } bit;                                          /*!< [32] BitSize                                                          */
  } CAL_CH0_1;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x4801C038) Calibration for Channel 2 & 3                          */
    
    struct {
      __IO uint32_t  OFFS_CH2   :  5;               /*!< [0..4] Offset Calibration for channel 2                               */
           uint32_t             :  3;
      __IO uint32_t  GAIN_CH2   :  8;               /*!< [8..15] Gain Calibration for channel 2                                */
      __IO uint32_t  OFFS_CH3   :  5;               /*!< [16..20] Offset Calibration for channel 3                             */
           uint32_t             :  3;
      __IO uint32_t  GAIN_CH3   :  8;               /*!< [24..31] Gain Calibration for channel 3                               */
    } bit;                                          /*!< [32] BitSize                                                          */
  } CAL_CH2_3;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x4801C03C) Calibration for Channel 4 & 5                          */
    
    struct {
      __IO uint32_t  OFFS_CH4   :  5;               /*!< [0..4] Offset Calibration for channel 4                               */
           uint32_t             :  3;
      __IO uint32_t  GAIN_CH4   :  8;               /*!< [8..15] Gain Calibration for channel 4                                */
      __IO uint32_t  OFFS_CH5   :  5;               /*!< [16..20] Offset Calibration for channel 5                             */
           uint32_t             :  3;
      __IO uint32_t  GAIN_CH5   :  8;               /*!< [24..31] Gain Calibration for channel 5                               */
    } bit;                                          /*!< [32] BitSize                                                          */
  } CAL_CH4_5;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x4801C040) Calibration for Channel 6 & 7                          */
    
    struct {
      __IO uint32_t  OFFS_CH6   :  5;               /*!< [0..4] Offset Calibration for channel 6                               */
           uint32_t             :  3;
      __IO uint32_t  GAIN_CH6   :  8;               /*!< [8..15] Gain Calibration for channel 6                                */
    } bit;                                          /*!< [16] BitSize                                                          */
  } CAL_CH6_7;
  __I  uint32_t  RESERVED2;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x4801C048) Filter Coefficients ADC Channel 0-7                    */
    
    struct {
      __IO uint32_t  A_CH0      :  2;               /*!< [0..1] Filter Coefficient A for ADC channel 0                         */
      __IO uint32_t  A_CH1      :  2;               /*!< [2..3] Filter Coefficient A for ADC channel 1                         */
      __IO uint32_t  A_CH2      :  2;               /*!< [4..5] Filter Coefficient A for ADC channel 2                         */
      __IO uint32_t  A_CH3      :  2;               /*!< [6..7] Filter Coefficient A for ADC channel 3                         */
      __IO uint32_t  A_CH4      :  2;               /*!< [8..9] Filter Coefficient A for ADC channel 4                         */
      __IO uint32_t  A_CH5      :  2;               /*!< [10..11] Filter Coefficient A for ADC channel 5                       */
      __IO uint32_t  A_CH6      :  2;               /*!< [12..13] Filter Coefficient A for ADC channel 6                       */
      __IO uint32_t  A_CH7      :  2;               /*!< [14..15] Filter Coefficient A for ADC channel 7                       */
    } bit;                                          /*!< [16] BitSize                                                          */
  } FILTCOEFF0_7;
  __I  uint32_t  RESERVED3;
  
  union {
    __I  uint32_t  reg;                             /*!< (@ 0x4801C050) ADC or Filter Output Channel 0                         */
    
    struct {
      __I  uint32_t  OUT_CH0    : 10;               /*!< [0..9] ADC or filter output value channel 0                           */
    } bit;                                          /*!< [10] BitSize                                                          */
  } FILT_OUT0;
  
  union {
    __I  uint32_t  reg;                             /*!< (@ 0x4801C054) ADC or Filter Output Channel 1                         */
    
    struct {
      __I  uint32_t  OUT_CH1    : 10;               /*!< [0..9] ADC or filter output value channel 1                           */
    } bit;                                          /*!< [10] BitSize                                                          */
  } FILT_OUT1;
  
  union {
    __I  uint32_t  reg;                             /*!< (@ 0x4801C058) ADC or Filter Output Channel 2                         */
    
    struct {
      __I  uint32_t  OUT_CH2    : 10;               /*!< [0..9] ADC or filter output value channel 2                           */
    } bit;                                          /*!< [10] BitSize                                                          */
  } FILT_OUT2;
  
  union {
    __I  uint32_t  reg;                             /*!< (@ 0x4801C05C) ADC or Filter Output Channel 3                         */
    
    struct {
      __I  uint32_t  OUT_CH3    : 10;               /*!< [0..9] ADC or filter output value channel 3                           */
    } bit;                                          /*!< [10] BitSize                                                          */
  } FILT_OUT3;
  
  union {
    __I  uint32_t  reg;                             /*!< (@ 0x4801C060) ADC or Filter Output Channel 4                         */
    
    struct {
      __I  uint32_t  OUT_CH4    : 10;               /*!< [0..9] ADC or filter output value channel 4                           */
    } bit;                                          /*!< [10] BitSize                                                          */
  } FILT_OUT4;
  
  union {
    __I  uint32_t  reg;                             /*!< (@ 0x4801C064) ADC or Filter Output Channel 5                         */
    
    struct {
      __I  uint32_t  OUT_CH5    : 10;               /*!< [0..9] ADC or filter output value channel 5                           */
    } bit;                                          /*!< [10] BitSize                                                          */
  } FILT_OUT5;
  
  union {
    __I  uint32_t  reg;                             /*!< (@ 0x4801C068) ADC or Filter Output Channel 6                         */
    
    struct {
      __I  uint32_t  OUT_CH6    : 10;               /*!< [0..9] ADC or filter output value channel 6                           */
    } bit;                                          /*!< [10] BitSize                                                          */
  } FILT_OUT6;
  __I  uint32_t  RESERVED4[3];
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x4801C078) Upper Threshold Filter Enable                          */
    
    struct {
      __IO uint32_t  UPEN_Ch0   :  1;               /*!< [0..0] Upper threshold IIR filter enable ch 0                         */
      __IO uint32_t  UPEN_Ch1   :  1;               /*!< [1..1] Upper threshold IIR filter enable ch 1                         */
      __IO uint32_t  UPEN_Ch2   :  1;               /*!< [2..2] Upper threshold IIR filter enable ch 2                         */
      __IO uint32_t  UPEN_Ch3   :  1;               /*!< [3..3] Upper threshold IIR filter enable ch 3                         */
      __IO uint32_t  UPEN_Ch4   :  1;               /*!< [4..4] Upper threshold IIR filter enable ch 4                         */
      __IO uint32_t  UPEN_Ch5   :  1;               /*!< [5..5] Upper threshold IIR filter enable ch 5                         */
      __IO uint32_t  UPEN_Ch6   :  1;               /*!< [6..6] Upper threshold IIR filter enable ch 6                         */
    } bit;                                          /*!< [7] BitSize                                                           */
  } FILT_UP_CTRL;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x4801C07C) Lower Threshold Filter Enable                          */
    
    struct {
      __IO uint32_t  LOEN_Ch0   :  1;               /*!< [0..0] Lower threshold IIR filter enable ch 0                         */
      __IO uint32_t  LOEN_Ch1   :  1;               /*!< [1..1] Lower threshold IIR filter enable ch 1                         */
      __IO uint32_t  LOEN_Ch2   :  1;               /*!< [2..2] Lower threshold IIR filter enable ch 2                         */
      __IO uint32_t  LOEN_Ch3   :  1;               /*!< [3..3] Lower threshold IIR filter enable ch 3                         */
      __IO uint32_t  LOEN_Ch4   :  1;               /*!< [4..4] Lower threshold IIR filter enable ch 4                         */
      __IO uint32_t  LOEN_Ch5   :  1;               /*!< [5..5] Lower threshold IIR filter enable ch 5                         */
      __IO uint32_t  LOEN_Ch6   :  1;               /*!< [6..6] Lower threshold IIR filter enable ch 6                         */
    } bit;                                          /*!< [7] BitSize                                                           */
  } FILT_LO_CTRL;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x4801C080) Lower Comparator Trigger Level Channel 0 -3            */
    
    struct {
      __IO uint32_t  THLO_CH0   :  8;               /*!< [0..7] Channel 0 lower trigger level                                  */
      __IO uint32_t  THLO_CH1   :  8;               /*!< [8..15] Channel 1 lower trigger level                                 */
      __IO uint32_t  THLO_CH2   :  8;               /*!< [16..23] Channel 2 lower trigger level                                */
      __IO uint32_t  THLO_CH3   :  8;               /*!< [24..31] Channel 3 lower trigger level                                */
    } bit;                                          /*!< [32] BitSize                                                          */
  } TH0_3_LOWER;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x4801C084) Lower Comparator Trigger Level Channel 4 to 7          */
    
    struct {
      __IO uint32_t  THLO_CH4   :  8;               /*!< [0..7] Channel 4 lower trigger level                                  */
      __IO uint32_t  THLO_CH5   :  8;               /*!< [8..15] Channel 5 lower trigger level                                 */
      __IO uint32_t  THLO_CH6   :  8;               /*!< [16..23] Channel 6 lower trigger level                                */
      __IO uint32_t  THLO_CH7   :  8;               /*!< [24..31] Channel 7 lower trigger level                                */
    } bit;                                          /*!< [32] BitSize                                                          */
  } TH4_7_LOWER;
  __I  uint32_t  RESERVED5;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x4801C08C) Upper Comparator Trigger Level Channel 0-3             */
    
    struct {
      __IO uint32_t  THUP_CH0   :  8;               /*!< [0..7] Channel 0 upper trigger level                                  */
      __IO uint32_t  THUP_CH1   :  8;               /*!< [8..15] Channel 1 upper trigger level                                 */
      __IO uint32_t  THUP_CH2   :  8;               /*!< [16..23] Channel 2 upper trigger level                                */
      __IO uint32_t  THUP_CH3   :  8;               /*!< [24..31] Channel 3 upper trigger level                                */
    } bit;                                          /*!< [32] BitSize                                                          */
  } TH0_3_UPPER;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x4801C090) Upper Comparator Trigger Level Channel 4 -7            */
    
    struct {
      __IO uint32_t  THUP_CH4   :  8;               /*!< [0..7] Channel 4 upper trigger level                                  */
      __IO uint32_t  THUP_CH5   :  8;               /*!< [8..15] Channel 5 upper trigger level                                 */
      __IO uint32_t  THUP_CH6   :  8;               /*!< [16..23] Channel 6 upper trigger level                                */
      __IO uint32_t  THUP_CH7   :  8;               /*!< [24..31] Channel 7 upper trigger level                                */
    } bit;                                          /*!< [32] BitSize                                                          */
  } TH4_7_UPPER;
  __I  uint32_t  RESERVED6;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x4801C098) Lower Counter Trigger Level Channel 0 - 3              */
    
    struct {
      __IO uint32_t  CNT_LO_CH0 :  3;               /*!< [0..2] Lower timer trigger threshold channel 0                        */
      __IO uint32_t  HYST_LO_CH0:  2;               /*!< [3..4] Channel 0 lower hysteresis                                     */
           uint32_t             :  3;
      __IO uint32_t  CNT_LO_CH1 :  3;               /*!< [8..10] Lower timer trigger threshold channel 1                       */
      __IO uint32_t  HYST_LO_CH1:  2;               /*!< [11..12] Channel 1 lower hysteresis                                   */
           uint32_t             :  3;
      __IO uint32_t  CNT_LO_CH2 :  3;               /*!< [16..18] Lower timer trigger threshold channel 2                      */
      __IO uint32_t  HYST_LO_CH2:  2;               /*!< [19..20] Channel 2 lower hysteresis                                   */
           uint32_t             :  3;
      __IO uint32_t  CNT_LO_CH3 :  3;               /*!< [24..26] Lower timer trigger threshold channel 3                      */
      __IO uint32_t  HYST_LO_CH3:  2;               /*!< [27..28] Channel 3 lower hysteresis                                   */
    } bit;                                          /*!< [29] BitSize                                                          */
  } CNT0_3_LOWER;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x4801C09C) Lower Counter Trigger Level Channel 4 to 7             */
    
    struct {
      __IO uint32_t  CNT_LO_CH4 :  3;               /*!< [0..2] Lower timer trigger threshold channel 4                        */
      __IO uint32_t  HYST_LO_CH4:  2;               /*!< [3..4] Channel 4 lower hysteresis                                     */
           uint32_t             :  3;
      __IO uint32_t  CNT_LO_CH5 :  3;               /*!< [8..10] Lower timer trigger threshold channel 5                       */
      __IO uint32_t  HYST_LO_CH5:  2;               /*!< [11..12] Channel 5 lower hysteresis                                   */
           uint32_t             :  3;
      __IO uint32_t  CNT_LO_CH6 :  3;               /*!< [16..18] Lower timer trigger threshold channel 6                      */
      __IO uint32_t  HYST_LO_CH6:  2;               /*!< [19..20] Channel 6 lower hysteresis                                   */
           uint32_t             :  3;
      __IO uint32_t  CNT_LO_CH7 :  3;               /*!< [24..26] Lower timer trigger threshold channel 6                      */
      __IO uint32_t  HYST_LO_CH7:  2;               /*!< [27..28] Channel 6 lower hysteresis                                   */
    } bit;                                          /*!< [29] BitSize                                                          */
  } CNT4_7_LOWER;
  __I  uint32_t  RESERVED7;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x4801C0A4) Upper Counter Trigger Level Channel 0 - 3              */
    
    struct {
      __IO uint32_t  CNT_UP_CH0 :  3;               /*!< [0..2] Upper timer trigger threshold channel 0                        */
      __IO uint32_t  HYST_UP_CH0:  2;               /*!< [3..4] Channel 0 upper hysteresis                                     */
           uint32_t             :  3;
      __IO uint32_t  CNT_UP_CH1 :  3;               /*!< [8..10] Upper timer trigger threshold channel 1                       */
      __IO uint32_t  HYST_UP_CH1:  2;               /*!< [11..12] Channel 1 upper hysteresis                                   */
           uint32_t             :  3;
      __IO uint32_t  CNT_UP_CH2 :  3;               /*!< [16..18] Upper timer trigger threshold channel 2                      */
      __IO uint32_t  HYST_UP_CH2:  2;               /*!< [19..20] Channel 2 upper hysteresis                                   */
           uint32_t             :  3;
      __IO uint32_t  CNT_UP_CH3 :  3;               /*!< [24..26] Upper timer trigger threshold channel 3                      */
      __IO uint32_t  HYST_UP_CH3:  2;               /*!< [27..28] Channel 3 upper hysteresis                                   */
    } bit;                                          /*!< [29] BitSize                                                          */
  } CNT0_3_UPPER;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x4801C0A8) Upper Counter Trigger Level Channel 4 to 7             */
    
    struct {
      __IO uint32_t  CNT_UP_CH4 :  3;               /*!< [0..2] Upper timer trigger threshold channel 4                        */
      __IO uint32_t  HYST_UP_CH4:  2;               /*!< [3..4] Channel 4 upper hysteresis                                     */
           uint32_t             :  3;
      __IO uint32_t  CNT_UP_CH5 :  3;               /*!< [8..10] Upper timer trigger threshold channel 5                       */
      __IO uint32_t  HYST_UP_CH5:  2;               /*!< [11..12] Channel 5 upper hysteresis                                   */
           uint32_t             :  3;
      __IO uint32_t  CNT_UP_CH6 :  3;               /*!< [16..18] Upper timer trigger threshold channel 6                      */
      __IO uint32_t  HYST_UP_CH6:  2;               /*!< [19..20] Channel 6 upper hysteresis                                   */
           uint32_t             :  3;
      __IO uint32_t  CNT_UP_CH7 :  3;               /*!< [24..26] Upper timer trigger threshold channel 7                      */
      __IO uint32_t  HYST_UP_CH7:  2;               /*!< [27..28] Channel 7 upper hysteresis                                   */
    } bit;                                          /*!< [29] BitSize                                                          */
  } CNT4_7_UPPER;
  __I  uint32_t  RESERVED8;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x4801C0B0) Measurement Mode of Ch 0-7                             */
    
    struct {
      __IO uint32_t  MSEL_Ch0   :  2;               /*!< [0..1] Measurement mode ch 0                                          */
      __IO uint32_t  MSEL_Ch1   :  2;               /*!< [2..3] Measurement mode ch 1                                          */
      __IO uint32_t  MSEL_Ch2   :  2;               /*!< [4..5] Measurement mode ch 2                                          */
      __IO uint32_t  MSEL_Ch3   :  2;               /*!< [6..7] Measurement mode ch 3                                          */
      __IO uint32_t  MSEL_Ch4   :  2;               /*!< [8..9] Measurement mode ch 4                                          */
      __IO uint32_t  MSEL_Ch5   :  2;               /*!< [10..11] Measurement mode ch 5                                        */
      __IO uint32_t  MSEL_Ch6   :  2;               /*!< [12..13] Measurement mode ch 6                                        */
      __IO uint32_t  MSEL_Ch7   :  2;               /*!< [14..15] Measurement mode ch 7                                        */
    } bit;                                          /*!< [16] BitSize                                                          */
  } MMODE0_7;
  __I  uint32_t  RESERVED9[2];
  
  union {
    __I  uint32_t  reg;                             /*!< (@ 0x4801C0BC) ADC2 HV Status Register                                */
    
    struct {
           uint32_t             :  1;
      __I  uint32_t  READY      :  1;               /*!< [1..1] HVADC Ready bit                                                */
    } bit;                                          /*!< [2] BitSize                                                           */
  } STATUS;
} ADC2_Type;


/* ================================================================================ */
/* ================                      CCU6                      ================ */
/* ================================================================================ */


/**
  * @brief CCU6 (CCU6)
  */

/*lint -e46 field type should be _Bool, unsigned int or signed int [MISRA 2012 Rule 6.1, required] */

typedef struct {                                    /*!< (@ 0x4000C000) CCU6 Structure                                         */
  
  union {
    __I  uint16_t  reg;                             /*!< (@ 0x4000C000) Capture/Compare Register for Channel CC63              */
    
    struct {
      __I  uint16_t  CCV        : 16;               /*!< [0..15] Channel CC63 Compare Value Low Byte                           */
    } bit;                                          /*!< [16] BitSize                                                          */
  } CC63R;
  __I  uint16_t  RESERVED;
  
  union {
    __O  uint16_t  reg;                             /*!< (@ 0x4000C004) Timer Control Register 4                               */
    
    struct {
      __O  uint16_t  T12RR      :  1;               /*!< [0..0] Timer T12 Run Reset                                            */
      __O  uint16_t  T12RS      :  1;               /*!< [1..1] Timer T12 Run Set                                              */
      __O  uint16_t  T12RES     :  1;               /*!< [2..2] Timer T12 Reset                                                */
      __O  uint16_t  DTRES      :  1;               /*!< [3..3] Dead-Time Counter Reset                                        */
           uint16_t             :  1;
      __O  uint16_t  T12CNT     :  1;               /*!< [5..5] Timer T12 Count Event                                          */
      __O  uint16_t  T12STR     :  1;               /*!< [6..6] Timer T12 Shadow Transfer Request                              */
      __O  uint16_t  T12STD     :  1;               /*!< [7..7] Timer T12 Shadow Transfer Disable                              */
      __O  uint16_t  T13RR      :  1;               /*!< [8..8] Timer T13 Run Reset                                            */
      __O  uint16_t  T13RS      :  1;               /*!< [9..9] Timer T13 Run Set                                              */
      __O  uint16_t  T13RES     :  1;               /*!< [10..10] Timer T13 Reset                                              */
           uint16_t             :  2;
      __O  uint16_t  T13CNT     :  1;               /*!< [13..13] Timer T13 Count Event                                        */
      __O  uint16_t  T13STR     :  1;               /*!< [14..14] Timer T13 Shadow Transfer Request                            */
      __O  uint16_t  T13STD     :  1;               /*!< [15..15] Timer T13 Shadow Transfer Disable                            */
    } bit;                                          /*!< [16] BitSize                                                          */
  } TCTR4;
  __I  uint16_t  RESERVED1;
  
  union {
    __IO uint16_t  reg;                             /*!< (@ 0x4000C008) Multi-Channel Mode Output Shadow Register              */
    
    struct {
      __IO uint16_t  MCMPS      :  6;               /*!< [0..5] Multi-Channel PWM Pattern Shadow                               */
           uint16_t             :  1;
      __O  uint16_t  STRMCM     :  1;               /*!< [7..7] Shadow Transfer Request for MCMPS                              */
      __IO uint16_t  EXPHS      :  3;               /*!< [8..10] Expected Hall Pattern Shadow                                  */
      __IO uint16_t  CURHS      :  3;               /*!< [11..13] Current Hall Pattern Shadow                                  */
           uint16_t             :  1;
      __O  uint16_t  STRHP      :  1;               /*!< [15..15] Shadow Transfer Request for the Hall Pattern                 */
    } bit;                                          /*!< [16] BitSize                                                          */
  } MCMOUTS;
  __I  uint16_t  RESERVED2;
  
  union {
    __O  uint16_t  reg;                             /*!< (@ 0x4000C00C) Capture/Compare Interrupt Status Reset Register        */
    
    struct {
      __O  uint16_t  RCC60R     :  1;               /*!< [0..0] Reset Capture, Compare-Match Rising Edge Flag                  */
      __O  uint16_t  RCC60F     :  1;               /*!< [1..1] Reset Capture, Compare-Match Falling Edge Flag                 */
      __O  uint16_t  RCC61R     :  1;               /*!< [2..2] Reset Capture, Compare-Match Rising Edge Flag                  */
      __O  uint16_t  RCC61F     :  1;               /*!< [3..3] Reset Capture, Compare-Match Falling Edge Flag                 */
      __O  uint16_t  RCC62R     :  1;               /*!< [4..4] Reset Capture, Compare-Match Rising Edge Flag                  */
      __O  uint16_t  RCC62F     :  1;               /*!< [5..5] Reset Capture, Compare-Match Falling Edge Flag                 */
      __O  uint16_t  RT12OM     :  1;               /*!< [6..6] Reset Timer T12 One-Match Flag                                 */
      __O  uint16_t  RT12PM     :  1;               /*!< [7..7] Reset Timer T12 Period-Match Flag                              */
      __O  uint16_t  RT13CM     :  1;               /*!< [8..8] Reset Timer T13 Compare-Match Flag                             */
      __O  uint16_t  RT13PM     :  1;               /*!< [9..9] Reset Timer T13 Period-Match Flag                              */
      __O  uint16_t  RTRPF      :  1;               /*!< [10..10] Reset Trap Flag                                              */
           uint16_t             :  1;
      __O  uint16_t  RCHE       :  1;               /*!< [12..12] Reset Correct Hall Event Flag                                */
      __O  uint16_t  RWHE       :  1;               /*!< [13..13] Reset Wrong Hall Event Flag                                  */
      __O  uint16_t  RIDLE      :  1;               /*!< [14..14] Reset IDLE Flag                                              */
      __O  uint16_t  RSTR       :  1;               /*!< [15..15] Reset STR Flag                                               */
    } bit;                                          /*!< [16] BitSize                                                          */
  } ISR;
  __I  uint16_t  RESERVED3;
  
  union {
    __O  uint16_t  reg;                             /*!< (@ 0x4000C010) Compare State Modification Register                    */
    
    struct {
      __O  uint16_t  MCC60S     :  1;               /*!< [0..0] Capture/Compare Status Modification Bit 0 (Set)                */
      __O  uint16_t  MCC61S     :  1;               /*!< [1..1] Capture/Compare Status Modification Bit 1 (Set)                */
      __O  uint16_t  MCC62S     :  1;               /*!< [2..2] Capture/Compare Status Modification Bit 2 (Set)                */
           uint16_t             :  3;
      __O  uint16_t  MCC63S     :  1;               /*!< [6..6] Capture/Compare Status Modification Bits (Set)                 */
           uint16_t             :  1;
      __O  uint16_t  MCC60R     :  1;               /*!< [8..8] Capture/Compare Status Modification Bit 0(Reset)               */
      __O  uint16_t  MCC61R     :  1;               /*!< [9..9] Capture/Compare Status Modification Bit 1(Reset)               */
      __O  uint16_t  MCC62R     :  1;               /*!< [10..10] Capture/Compare Status Modification Bit 2(Reset)             */
           uint16_t             :  3;
      __O  uint16_t  MCC63R     :  1;               /*!< [14..14] Capture/Compare Status Modification Bits (Reset)             */
    } bit;                                          /*!< [15] BitSize                                                          */
  } CMPMODIF;
  __I  uint16_t  RESERVED4;
  
  union {
    __IO uint16_t  reg;                             /*!< (@ 0x4000C014) Capture/Compare Shadow Register for Channel CC60       */
    
    struct {
      __IO uint16_t  CCS        : 16;               /*!< [0..15] Shadow Register for Channel 0 Capture/Compare Value           */
    } bit;                                          /*!< [16] BitSize                                                          */
  } CC60SR;
  __I  uint16_t  RESERVED5;
  
  union {
    __IO uint16_t  reg;                             /*!< (@ 0x4000C018) Capture/Compare Shadow Register for Channel CC61       */
    
    struct {
      __IO uint16_t  CCS        : 16;               /*!< [0..15] Shadow Register for Channel 1 Capture/Compare Value           */
    } bit;                                          /*!< [16] BitSize                                                          */
  } CC61SR;
  __I  uint16_t  RESERVED6;
  
  union {
    __IO uint16_t  reg;                             /*!< (@ 0x4000C01C) Capture/Compare Shadow Register for Channel CC62       */
    
    struct {
      __IO uint16_t  CCS        : 16;               /*!< [0..15] Shadow Register for Channel 2 Capture/Compare Value           */
    } bit;                                          /*!< [16] BitSize                                                          */
  } CC62SR;
  __I  uint16_t  RESERVED7;
  
  union {
    __IO uint16_t  reg;                             /*!< (@ 0x4000C020) Capture/Compare Shadow Register for Channel CC63       */
    
    struct {
      __IO uint16_t  CCS        : 16;               /*!< [0..15] Shadow Register for Channel CC63 Compare Value                */
    } bit;                                          /*!< [16] BitSize                                                          */
  } CC63SR;
  __I  uint16_t  RESERVED8;
  
  union {
    __IO uint16_t  reg;                             /*!< (@ 0x4000C024) Timer T12 Period Register                              */
    
    struct {
      __IO uint16_t  T12PV      : 16;               /*!< [0..15] T12 Period Value                                              */
    } bit;                                          /*!< [16] BitSize                                                          */
  } T12PR;
  __I  uint16_t  RESERVED9;
  
  union {
    __IO uint16_t  reg;                             /*!< (@ 0x4000C028) Timer T13 Period Register                              */
    
    struct {
      __IO uint16_t  T13PV      : 16;               /*!< [0..15] T13 Period Value                                              */
    } bit;                                          /*!< [16] BitSize                                                          */
  } T13PR;
  __I  uint16_t  RESERVED10;
  
  union {
    __IO uint16_t  reg;                             /*!< (@ 0x4000C02C) Dead-Time Control Register for Timer T12 Low           */
    
    struct {
      __IO uint16_t  DTM        :  8;               /*!< [0..7] Dead-Time                                                      */
      __IO uint16_t  DTE0       :  1;               /*!< [8..8] Dead-Time Enable Bit 0                                         */
      __IO uint16_t  DTE1       :  1;               /*!< [9..9] Dead-Time Enable Bit 1                                         */
      __IO uint16_t  DTE2       :  1;               /*!< [10..10] Dead-Time Enable Bit 2                                       */
           uint16_t             :  1;
      __I  uint16_t  DTR0       :  1;               /*!< [12..12] Dead-Time Run Indication Bit 0                               */
      __I  uint16_t  DTR1       :  1;               /*!< [13..13] Dead-Time Run Indication Bit 1                               */
      __I  uint16_t  DTR2       :  1;               /*!< [14..14] Dead-Time Run Indication Bit 2                               */
    } bit;                                          /*!< [15] BitSize                                                          */
  } T12DTC;
  __I  uint16_t  RESERVED11;
  
  union {
    __IO uint16_t  reg;                             /*!< (@ 0x4000C030) Timer Control Register 0                               */
    
    struct {
      __IO uint16_t  T12CLK     :  3;               /*!< [0..2] Timer T12 Input Clock Select                                   */
      __IO uint16_t  T12PRE     :  1;               /*!< [3..3] Timer T12 Prescaler Bit                                        */
      __I  uint16_t  T12R       :  1;               /*!< [4..4] Timer T12 Run Bit                                              */
      __I  uint16_t  STE12      :  1;               /*!< [5..5] Timer T12 Shadow Transfer Enable                               */
      __I  uint16_t  CDIR       :  1;               /*!< [6..6] Count Direction of Timer T12                                   */
      __IO uint16_t  CTM        :  1;               /*!< [7..7] T12 Operating Mode                                             */
      __IO uint16_t  T13CLK     :  3;               /*!< [8..10] Timer T13 Input Clock Select                                  */
      __IO uint16_t  T13PRE     :  1;               /*!< [11..11] Timer T13 Prescaler Bit                                      */
      __I  uint16_t  T13R       :  1;               /*!< [12..12] Timer T13 Run Bit                                            */
      __I  uint16_t  STE13      :  1;               /*!< [13..13] Timer T13 Shadow Transfer Enable                             */
    } bit;                                          /*!< [14] BitSize                                                          */
  } TCTR0;
  __I  uint16_t  RESERVED12;
  
  union {
    __I  uint16_t  reg;                             /*!< (@ 0x4000C034) Capture/Compare Register for Channel CC60              */
    
    struct {
      __I  uint16_t  CCV        : 16;               /*!< [0..15] Channel 0 Capture/Compare Value                               */
    } bit;                                          /*!< [16] BitSize                                                          */
  } CC60R;
  __I  uint16_t  RESERVED13;
  
  union {
    __I  uint16_t  reg;                             /*!< (@ 0x4000C038) Capture/Compare Register for Channel CC61              */
    
    struct {
      __I  uint16_t  CCV        : 16;               /*!< [0..15] Channel 1 Capture/Compare Value                               */
    } bit;                                          /*!< [16] BitSize                                                          */
  } CC61R;
  __I  uint16_t  RESERVED14;
  
  union {
    __I  uint16_t  reg;                             /*!< (@ 0x4000C03C) Capture/Compare Register for Channel CC62              */
    
    struct {
      __I  uint16_t  CCV        : 16;               /*!< [0..15] Channel 2 Capture/Compare Value                               */
    } bit;                                          /*!< [16] BitSize                                                          */
  } CC62R;
  __I  uint16_t  RESERVED15;
  
  union {
    __IO uint16_t  reg;                             /*!< (@ 0x4000C040) T12 Capture/Compare Mode Select Register               */
    
    struct {
      __IO uint16_t  MSEL60     :  4;               /*!< [0..3] Capture/Compare Mode Selection                                 */
      __IO uint16_t  MSEL61     :  4;               /*!< [4..7] Capture/Compare Mode Selection                                 */
      __IO uint16_t  MSEL62     :  4;               /*!< [8..11] Capture/Compare Mode Selection                                */
      __IO uint16_t  HSYNC      :  3;               /*!< [12..14] Hall Synchronization                                         */
      __IO uint16_t  DBYP       :  1;               /*!< [15..15] Delay Bypass                                                 */
    } bit;                                          /*!< [16] BitSize                                                          */
  } T12MSEL;
  __I  uint16_t  RESERVED16;
  
  union {
    __IO uint16_t  reg;                             /*!< (@ 0x4000C044) Capture/Compare Interrupt Enable Register              */
    
    struct {
      __IO uint16_t  ENCC60R    :  1;               /*!< [0..0] Capture, Compare-Match Rising Edge Interrupt Enable for
                                                         Channel 0                                                             */
      __IO uint16_t  ENCC60F    :  1;               /*!< [1..1] Capture, Compare-Match Falling Edge Interrupt Enable
                                                         for Channel 0                                                         */
      __IO uint16_t  ENCC61R    :  1;               /*!< [2..2] Capture, Compare-Match Rising Edge Interrupt Enable for
                                                         Channel 1                                                             */
      __IO uint16_t  ENCC61F    :  1;               /*!< [3..3] Capture, Compare-Match Falling Edge Interrupt Enable
                                                         for Channel 1                                                         */
      __IO uint16_t  ENCC62R    :  1;               /*!< [4..4] Capture, Compare-Match Rising Edge Interrupt Enable for
                                                         Channel 2                                                             */
      __IO uint16_t  ENCC62F    :  1;               /*!< [5..5] Capture, Compare-Match Falling Edge Interrupt Enable
                                                         for Channel 2                                                         */
      __IO uint16_t  ENT12OM    :  1;               /*!< [6..6] Enable Interrupt for T12 One-Match                             */
      __IO uint16_t  ENT12PM    :  1;               /*!< [7..7] Enable Interrupt for T12 Period-Match                          */
      __IO uint16_t  ENT13CM    :  1;               /*!< [8..8] Enable Interrupt for T13 Compare-Match                         */
      __IO uint16_t  ENT13PM    :  1;               /*!< [9..9] Enable Interrupt for T13 Period-Match                          */
      __IO uint16_t  ENTRPF     :  1;               /*!< [10..10] Enable Interrupt for Trap Flag                               */
           uint16_t             :  1;
      __IO uint16_t  ENCHE      :  1;               /*!< [12..12] Enable Interrupt for Correct Hall Event                      */
      __IO uint16_t  ENWHE      :  1;               /*!< [13..13] Enable Interrupt for Wrong Hall Event                        */
      __IO uint16_t  ENIDLE     :  1;               /*!< [14..14] Enable Idle                                                  */
      __IO uint16_t  ENSTR      :  1;               /*!< [15..15] Enable Multi-Channel Mode Shadow Transfer Interrupt          */
    } bit;                                          /*!< [16] BitSize                                                          */
  } IEN;
  __I  uint16_t  RESERVED17;
  
  union {
    __IO uint16_t  reg;                             /*!< (@ 0x4000C048) Capture/Compare Interrupt Node Pointer Register        */
    
    struct {
      __IO uint16_t  INPCC60    :  2;               /*!< [0..1] Interrupt Node Pointer for Channel 0 Interrupts                */
      __IO uint16_t  INPCC61    :  2;               /*!< [2..3] Interrupt Node Pointer for Channel 1 Interrupts                */
      __IO uint16_t  INPCC62    :  2;               /*!< [4..5] Interrupt Node Pointer for Channel 2 Interrupts                */
      __IO uint16_t  INPCHE     :  2;               /*!< [6..7] Interrupt Node Pointer for the CHE Interrupt                   */
      __IO uint16_t  INPERR     :  2;               /*!< [8..9] Interrupt Node Pointer for Error Interrupts                    */
      __IO uint16_t  INPT12     :  2;               /*!< [10..11] Interrupt Node Pointer for Timer T12 Interrupts              */
      __IO uint16_t  INPT13     :  2;               /*!< [12..13] Interrupt Node Pointer for Timer T13 Interrupts              */
    } bit;                                          /*!< [14] BitSize                                                          */
  } INP;
  __I  uint16_t  RESERVED18;
  
  union {
    __O  uint16_t  reg;                             /*!< (@ 0x4000C04C) Capture/Compare Interrupt Status Set Register          */
    
    struct {
      __O  uint16_t  SCC60R     :  1;               /*!< [0..0] Set Capture, Compare-Match Rising Edge Flag                    */
      __O  uint16_t  SCC60F     :  1;               /*!< [1..1] Set Capture, Compare-Match Falling Edge Flag                   */
      __O  uint16_t  SCC61R     :  1;               /*!< [2..2] Set Capture, Compare-Match Rising Edge Flag                    */
      __O  uint16_t  SCC61F     :  1;               /*!< [3..3] Set Capture, Compare-Match Falling Edge Flag                   */
      __O  uint16_t  SCC62R     :  1;               /*!< [4..4] Set Capture, Compare-Match Rising Edge Flag                    */
      __O  uint16_t  SCC62F     :  1;               /*!< [5..5] Set Capture, Compare-Match Falling Edge Flag                   */
      __O  uint16_t  ST12OM     :  1;               /*!< [6..6] Set Timer T12 One-Match Flag                                   */
      __O  uint16_t  ST12PM     :  1;               /*!< [7..7] Set Timer T12 Period-Match Flag                                */
      __O  uint16_t  ST13CM     :  1;               /*!< [8..8] Set Timer T13 Compare-Match Flag                               */
      __O  uint16_t  ST13PM     :  1;               /*!< [9..9] Set Timer T13 Period-Match Flag                                */
      __O  uint16_t  STRPF      :  1;               /*!< [10..10] Set Trap Flag                                                */
      __O  uint16_t  SWHC       :  1;               /*!< [11..11] Software Hall Compare                                        */
      __O  uint16_t  SCHE       :  1;               /*!< [12..12] Set Correct Hall Event Flag                                  */
      __O  uint16_t  SWHE       :  1;               /*!< [13..13] Set Wrong Hall Event Flag                                    */
      __O  uint16_t  SIDLE      :  1;               /*!< [14..14] Set IDLE Flag                                                */
      __O  uint16_t  SSTR       :  1;               /*!< [15..15] Set STR Flag                                                 */
    } bit;                                          /*!< [16] BitSize                                                          */
  } ISS;
  __I  uint16_t  RESERVED19;
  
  union {
    __IO uint16_t  reg;                             /*!< (@ 0x4000C050) Passive State Level Register                           */
    
    struct {
      __IO uint16_t  PSL        :  6;               /*!< [0..5] Compare Outputs Passive State Level                            */
           uint16_t             :  1;
      __IO uint16_t  PSL63      :  1;               /*!< [7..7] Passive State Level of Output COUT63                           */
    } bit;                                          /*!< [8] BitSize                                                           */
  } PSLR;
  __I  uint16_t  RESERVED20;
  
  union {
    __IO uint16_t  reg;                             /*!< (@ 0x4000C054) Multi-Channel Mode Control Register                    */
    
    struct {
      __IO uint16_t  SWSEL      :  3;               /*!< [0..2] Switching Selection                                            */
           uint16_t             :  1;
      __IO uint16_t  SWSYN      :  2;               /*!< [4..5] Switching Synchronization                                      */
           uint16_t             :  2;
      __IO uint16_t  STE12U     :  1;               /*!< [8..8] Shadow Transfer Enable for T12 Upcounting                      */
      __IO uint16_t  STE12D     :  1;               /*!< [9..9] Shadow Transfer Enable for T12 Downcounting                    */
      __IO uint16_t  STE13U     :  1;               /*!< [10..10] Shadow Transfer Enable for T13 Upcounting                    */
    } bit;                                          /*!< [11] BitSize                                                          */
  } MCMCTR;
  __I  uint16_t  RESERVED21;
  
  union {
    __IO uint16_t  reg;                             /*!< (@ 0x4000C058) Timer Control Register 2                               */
    
    struct {
      __IO uint16_t  T12SSC     :  1;               /*!< [0..0] Timer T12 Single Shot Control                                  */
      __IO uint16_t  T13SSC     :  1;               /*!< [1..1] Timer T13 Single Shot Control                                  */
      __IO uint16_t  T13TEC     :  3;               /*!< [2..4] T13 Trigger Event Control                                      */
      __IO uint16_t  T13TED     :  2;               /*!< [5..6] Timer T13 Trigger Event Direction                              */
           uint16_t             :  1;
      __IO uint16_t  T12RSEL    :  2;               /*!< [8..9] Timer T12 External Run Selection                               */
      __IO uint16_t  T13RSEL    :  2;               /*!< [10..11] Timer T13 External Run Selection                             */
    } bit;                                          /*!< [12] BitSize                                                          */
  } TCTR2;
  __I  uint16_t  RESERVED22;
  
  union {
    __IO uint16_t  reg;                             /*!< (@ 0x4000C05C) Modulation Control Register                            */
    
    struct {
      __IO uint16_t  T12MODEN   :  6;               /*!< [0..5] T12 Modulation Enable                                          */
           uint16_t             :  1;
      __IO uint16_t  MCMEN      :  1;               /*!< [7..7] Multi-Channel Mode Enable                                      */
      __IO uint16_t  T13MODEN   :  6;               /*!< [8..13] T13 Modulation Enable                                         */
           uint16_t             :  1;
      __IO uint16_t  ECT13O     :  1;               /*!< [15..15] Enable Compare Timer T13 Output                              */
    } bit;                                          /*!< [16] BitSize                                                          */
  } MODCTR;
  __I  uint16_t  RESERVED23;
  
  union {
    __IO uint16_t  reg;                             /*!< (@ 0x4000C060) Trap Control Register                                  */
    
    struct {
      __IO uint16_t  TRPM10     :  2;               /*!< [0..1] Trap Mode Control Bits 1, 0                                    */
      __IO uint16_t  TRPM2      :  1;               /*!< [2..2] Trap Mode Control Bit 2                                        */
           uint16_t             :  5;
      __IO uint16_t  TRPEN      :  6;               /*!< [8..13] Trap Enable Control                                           */
      __IO uint16_t  TRPEN13    :  1;               /*!< [14..14] Trap Enable Control for Timer T13                            */
      __IO uint16_t  TRPPEN     :  1;               /*!< [15..15] Trap Pin Enable                                              */
    } bit;                                          /*!< [16] BitSize                                                          */
  } TRPCTR;
  __I  uint16_t  RESERVED24;
  
  union {
    __I  uint16_t  reg;                             /*!< (@ 0x4000C064) Multi-Channel Mode Output Register                     */
    
    struct {
      __I  uint16_t  MCMP       :  6;               /*!< [0..5] Multi-Channel PWM Pattern                                      */
      __I  uint16_t  R          :  1;               /*!< [6..6] Reminder Flag                                                  */
           uint16_t             :  1;
      __I  uint16_t  EXPH       :  3;               /*!< [8..10] Expected Hall Pattern                                         */
      __I  uint16_t  CURH       :  3;               /*!< [11..13] Current Hall Pattern                                         */
    } bit;                                          /*!< [14] BitSize                                                          */
  } MCMOUT;
  __I  uint16_t  RESERVED25;
  
  union {
    __I  uint16_t  reg;                             /*!< (@ 0x4000C068) Capture/Compare Interrupt Status Register              */
    
    struct {
      __I  uint16_t  ICC60R     :  1;               /*!< [0..0] Capture, Compare-Match Rising Edge Flag                        */
      __I  uint16_t  ICC60F     :  1;               /*!< [1..1] Capture, Compare-Match Falling Edge Flag                       */
      __I  uint16_t  ICC61R     :  1;               /*!< [2..2] Capture, Compare-Match Rising Edge Flag                        */
      __I  uint16_t  ICC61F     :  1;               /*!< [3..3] Capture, Compare-Match Falling Edge Flag                       */
      __I  uint16_t  ICC62R     :  1;               /*!< [4..4] Capture, Compare-Match Rising Edge Flag                        */
      __I  uint16_t  ICC62F     :  1;               /*!< [5..5] Capture, Compare-Match Falling Edge Flag                       */
      __I  uint16_t  T12OM      :  1;               /*!< [6..6] Timer T12 One-Match Flag                                       */
      __I  uint16_t  T12PM      :  1;               /*!< [7..7] Timer T12 Period-Match Flag                                    */
      __I  uint16_t  T13CM      :  1;               /*!< [8..8] Timer T13 Compare-Match Flag                                   */
      __I  uint16_t  T13PM      :  1;               /*!< [9..9] Timer T13 Period-Match Flag                                    */
      __I  uint16_t  TRPF       :  1;               /*!< [10..10] Trap Flag                                                    */
      __I  uint16_t  TRPS       :  1;               /*!< [11..11] Trap State                                                   */
      __I  uint16_t  CHE        :  1;               /*!< [12..12] Correct Hall Event                                           */
      __I  uint16_t  WHE        :  1;               /*!< [13..13] Wrong Hall Event                                             */
      __I  uint16_t  IDLE       :  1;               /*!< [14..14] IDLE State                                                   */
      __I  uint16_t  STR        :  1;               /*!< [15..15] Multi-Channel Mode Shadow Transfer Request                   */
    } bit;                                          /*!< [16] BitSize                                                          */
  } IS;
  __I  uint16_t  RESERVED26;
  
  union {
    __IO uint16_t  reg;                             /*!< (@ 0x4000C06C) Port Input Select Register 0                           */
    
    struct {
      __IO uint16_t  ISCC60     :  2;               /*!< [0..1] Input Select for CC60                                          */
      __IO uint16_t  ISCC61     :  2;               /*!< [2..3] Input Select for CC61                                          */
      __IO uint16_t  ISCC62     :  2;               /*!< [4..5] Input Select for CC62                                          */
      __IO uint16_t  ISTRP      :  2;               /*!< [6..7] Input Select for CTRAP                                         */
      __IO uint16_t  ISPOS0     :  2;               /*!< [8..9] Input Select for CCPOS0                                        */
      __IO uint16_t  ISPOS1     :  2;               /*!< [10..11] Input Select for CCPOS1                                      */
      __IO uint16_t  ISPOS2     :  2;               /*!< [12..13] Input Select for CCPOS2                                      */
      __IO uint16_t  IST12HR    :  2;               /*!< [14..15] Input Select for T12HR                                       */
    } bit;                                          /*!< [16] BitSize                                                          */
  } PISEL0;
  __I  uint16_t  RESERVED27[3];
  
  union {
    __IO uint16_t  reg;                             /*!< (@ 0x4000C074) Port Input Select Register 2                           */
    
    struct {
      __IO uint16_t  IST13HR    :  2;               /*!< [0..1] Input Select for T13HR                                         */
      __IO uint16_t  ISCNT12    :  2;               /*!< [2..3] Input Select for T12 Counting Input                            */
      __IO uint16_t  ISCNT13    :  2;               /*!< [4..5] Input Select for T13 Counting Input                            */
      __IO uint16_t  T12EXT     :  1;               /*!< [6..6] Extension for T12HR Inputs                                     */
      __IO uint16_t  T13EXT     :  1;               /*!< [7..7] Extension for T13HR Inputs                                     */
    } bit;                                          /*!< [8] BitSize                                                           */
  } PISEL2;
  __I  uint16_t  RESERVED28;
  
  union {
    __IO uint16_t  reg;                             /*!< (@ 0x4000C078) Timer T12 Counter Register                             */
    
    struct {
      __IO uint16_t  T12CV      : 16;               /*!< [0..15] Timer T12 Counter Value                                       */
    } bit;                                          /*!< [16] BitSize                                                          */
  } T12;
  __I  uint16_t  RESERVED29;
  
  union {
    __IO uint16_t  reg;                             /*!< (@ 0x4000C07C) Timer T13 Counter Register                             */
    
    struct {
      __IO uint16_t  T13CV      : 16;               /*!< [0..15] Timer T13 Counter Value                                       */
    } bit;                                          /*!< [16] BitSize                                                          */
  } T13;
  __I  uint16_t  RESERVED30;
  
  union {
    __IO uint16_t  reg;                             /*!< (@ 0x4000C080) Compare State Register                                 */
    
    struct {
      __I  uint16_t  CC60ST     :  1;               /*!< [0..0] Capture/Compare State Bits                                     */
      __I  uint16_t  CC61ST     :  1;               /*!< [1..1] Capture/Compare State Bits                                     */
      __I  uint16_t  CC62ST     :  1;               /*!< [2..2] Capture/Compare State Bits                                     */
      __I  uint16_t  CCPOS0     :  1;               /*!< [3..3] Sampled Hall Pattern Bit 0                                     */
      __I  uint16_t  CCPOS1     :  1;               /*!< [4..4] Sampled Hall Pattern Bit 1                                     */
      __I  uint16_t  CCPOS2     :  1;               /*!< [5..5] Sampled Hall Pattern Bit 2                                     */
      __I  uint16_t  CC63ST     :  1;               /*!< [6..6] Capture/Compare State Bits                                     */
           uint16_t             :  1;
      __IO uint16_t  CC60PS     :  1;               /*!< [8..8] Passive State Select for Compare Outputs                       */
      __IO uint16_t  COUT60PS   :  1;               /*!< [9..9] Passive State Select for Compare Outputs                       */
      __IO uint16_t  CC61PS     :  1;               /*!< [10..10] Passive State Select for Compare Outputs                     */
      __IO uint16_t  COUT61PS   :  1;               /*!< [11..11] Passive State Select for Compare Outputs                     */
      __IO uint16_t  CC62PS     :  1;               /*!< [12..12] Passive State Select for Compare Outputs                     */
      __IO uint16_t  COUT62PS   :  1;               /*!< [13..13] Passive State Select for Compare Outputs                     */
      __IO uint16_t  COUT63PS   :  1;               /*!< [14..14] Passive State Select for Compare Outputs                     */
      __IO uint16_t  T13IM      :  1;               /*!< [15..15] T13 Inverted Modulation                                      */
    } bit;                                          /*!< [16] BitSize                                                          */
  } CMPSTAT;
} CCU6_Type;

/*lint +e46 */


/* ================================================================================ */
/* ================                       CPU                      ================ */
/* ================================================================================ */


/**
  * @brief CPU (CPU)
  */

typedef struct {                                    /*!< (@ 0xE000E000) CPU Structure                                          */
  __I  uint32_t  RESERVED[4];
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0xE000E010) SysTick Control and Status Register                    */
    
    struct {
      __IO uint32_t  ENABLE     :  1;               /*!< [0..0] Enable                                                         */
      __IO uint32_t  TICKINT    :  1;               /*!< [1..1] TICKINT                                                        */
      __IO uint32_t  CLKSOURCE  :  1;               /*!< [2..2] CLK Source                                                     */
           uint32_t             : 13;
      __IO uint32_t  COUNTFLAG  :  1;               /*!< [16..16] Count Flag                                                   */
    } bit;                                          /*!< [17] BitSize                                                          */
  } SYSTICK_CSR;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0xE000E014) SysTick Reload Value Register                          */
    
    struct {
      __IO uint32_t  RELOAD     : 24;               /*!< [0..23] Reload                                                        */
    } bit;                                          /*!< [24] BitSize                                                          */
  } SYSTICK_RVR;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0xE000E018) SysTick Current Value Register                         */
    
    struct {
      __IO uint32_t  CURRENT    : 24;               /*!< [0..23] Current                                                       */
    } bit;                                          /*!< [24] BitSize                                                          */
  } SYSTICK_CVR;
  
  union {
    __I  uint32_t  reg;                             /*!< (@ 0xE000E01C) SysTick Calibration Value Register                     */
    
    struct {
      __I  uint32_t  TENMS      : 24;               /*!< [0..23] Tenms                                                         */
           uint32_t             :  6;
      __I  uint32_t  SKEW       :  1;               /*!< [30..30] Skew                                                         */
      __I  uint32_t  NOREF      :  1;               /*!< [31..31] No Reference Clock                                           */
    } bit;                                          /*!< [32] BitSize                                                          */
  } SYSTICK_CALIB;
  __I  uint32_t  RESERVED1[56];
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0xE000E100) Interrupt Set-Enable                                   */
    
    struct {
      __IO uint32_t  Int_GPT1   :  1;               /*!< [0..0] Interrupt Set for GPT1                                         */
      __IO uint32_t  Int_GPT2   :  1;               /*!< [1..1] Interrupt Set for GPT2                                         */
      __IO uint32_t  Int_ADC2   :  1;               /*!< [2..2] Interrupt Set for MU, ADC2                                     */
      __IO uint32_t  Int_ADC1   :  1;               /*!< [3..3] Interrupt Set for ADC1                                         */
      __IO uint32_t  Int_CCU6SR0:  1;               /*!< [4..4] Interrupt Set for CCU6 SR0                                     */
      __IO uint32_t  Int_CCU6SR1:  1;               /*!< [5..5] Interrupt Set for CCU6 SR1                                     */
      __IO uint32_t  Int_CCU6SR2:  1;               /*!< [6..6] Interrupt Set for CCU6 SR2                                     */
      __IO uint32_t  Int_CCU6SR3:  1;               /*!< [7..7] Interrupt Set for CCU6 SR3                                     */
      __IO uint32_t  Int_SSC1   :  1;               /*!< [8..8] Interrupt Set for SSC1                                         */
      __IO uint32_t  Int_SSC2   :  1;               /*!< [9..9] Interrupt Set for SSC2                                         */
      __IO uint32_t  Int_UART1  :  1;               /*!< [10..10] Interrupt Set for UART1                                      */
      __IO uint32_t  Int_UART2  :  1;               /*!< [11..11] Interrupt Set for UART2                                      */
      __IO uint32_t  Int_EXINT0 :  1;               /*!< [12..12] Interrupt Set for External Int 0                             */
      __IO uint32_t  Int_EXINT1 :  1;               /*!< [13..13] Interrupt Set for External Int 1                             */
      __IO uint32_t  Int_WAKEUP :  1;               /*!< [14..14] Interrupt Set for WAKEUP                                     */
           uint32_t             :  2;
      __IO uint32_t  Int_LS1    :  1;               /*!< [17..17] Interrupt Set for LS1                                        */
      __IO uint32_t  Int_LS2    :  1;               /*!< [18..18] Interrupt Set for LS2                                        */
      __IO uint32_t  Int_HS1    :  1;               /*!< [19..19] Interrupt Set for HS1                                        */
      __IO uint32_t  Int_HS2    :  1;               /*!< [20..20] Interrupt Set for HS2                                        */
      __IO uint32_t  Int_DU     :  1;               /*!< [21..21] Interrupt Set for Differential Unit                          */
      __IO uint32_t  Int_MON    :  1;               /*!< [22..22] Interrupt Set for MON                                        */
      __IO uint32_t  Int_PORT2  :  1;               /*!< [23..23] Interrupt Set for PORT2                                      */
    } bit;                                          /*!< [24] BitSize                                                          */
  } NVIC_ISER;
  __I  uint32_t  RESERVED2[31];
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0xE000E180) Interrupt Clear-Enable                                 */
    
    struct {
      __IO uint32_t  Int_GPT1   :  1;               /*!< [0..0] Interrupt Clear for GPT1                                       */
      __IO uint32_t  Int_GPT2   :  1;               /*!< [1..1] Interrupt Clear for GPT2                                       */
      __IO uint32_t  Int_ADC2   :  1;               /*!< [2..2] Interrupt Clear for MU, ADC2                                   */
      __IO uint32_t  Int_ADC1   :  1;               /*!< [3..3] Interrupt Clear for ADC1                                       */
      __IO uint32_t  Int_CCU6SR0:  1;               /*!< [4..4] Interrupt Clear for CCU6 SR0                                   */
      __IO uint32_t  Int_CCU6SR1:  1;               /*!< [5..5] Interrupt Clear for CCU6 SR1                                   */
      __IO uint32_t  Int_CCU6SR2:  1;               /*!< [6..6] Interrupt Clear for CCU6 SR2                                   */
      __IO uint32_t  Int_CCU6SR3:  1;               /*!< [7..7] Interrupt Clear for CCU6 SR3                                   */
      __IO uint32_t  Int_SSC1   :  1;               /*!< [8..8] Interrupt Clear for SSC1                                       */
      __IO uint32_t  Int_SSC2   :  1;               /*!< [9..9] Interrupt Clear for SSC2                                       */
      __IO uint32_t  Int_UART1  :  1;               /*!< [10..10] Interrupt Clear for UART1                                    */
      __IO uint32_t  Int_UART2  :  1;               /*!< [11..11] Interrupt Clear for UART2                                    */
      __IO uint32_t  Int_EXINT0 :  1;               /*!< [12..12] Interrupt Clear for External Int 0                           */
      __IO uint32_t  Int_EXINT1 :  1;               /*!< [13..13] Interrupt Clear for External Int 1                           */
      __IO uint32_t  Int_WAKEUP :  1;               /*!< [14..14] Interrupt Clear for WAKEUP                                   */
           uint32_t             :  2;
      __IO uint32_t  Int_LS1    :  1;               /*!< [17..17] Interrupt Clear for LS1                                      */
      __IO uint32_t  Int_LS2    :  1;               /*!< [18..18] Interrupt Clear for LS2                                      */
      __IO uint32_t  Int_HS1    :  1;               /*!< [19..19] Interrupt Clear for HS1                                      */
      __IO uint32_t  Int_HS2    :  1;               /*!< [20..20] Interrupt Clear for HS2                                      */
      __IO uint32_t  Int_DU     :  1;               /*!< [21..21] Interrupt Clear for Differential Unit                        */
      __IO uint32_t  Int_MON    :  1;               /*!< [22..22] Interrupt Clear for MON                                      */
      __IO uint32_t  Int_PORT2  :  1;               /*!< [23..23] Interrupt Clear for PORT2                                    */
    } bit;                                          /*!< [24] BitSize                                                          */
  } NVIC_ICER;
  __I  uint32_t  RESERVED3[31];
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0xE000E200) Interrupt Set-Pending                                  */
    
    struct {
      __IO uint32_t  Int_GPT1   :  1;               /*!< [0..0] Interrupt Set Pending for GPT1                                 */
      __IO uint32_t  Int_GPT2   :  1;               /*!< [1..1] Interrupt Set Pending for GPT2                                 */
      __IO uint32_t  Int_ADC2   :  1;               /*!< [2..2] Interrupt Set Pending for MU, ADC2                             */
      __IO uint32_t  Int_ADC1   :  1;               /*!< [3..3] Interrupt Set Pending for ADC1                                 */
      __IO uint32_t  Int_CCU6SR0:  1;               /*!< [4..4] Interrupt Set Pending for CCU6 SR0                             */
      __IO uint32_t  Int_CCU6SR1:  1;               /*!< [5..5] Interrupt Set Pending for CCU6 SR1                             */
      __IO uint32_t  Int_CCU6SR2:  1;               /*!< [6..6] Interrupt Set Pending for CCU6 SR2                             */
      __IO uint32_t  Int_CCU6SR3:  1;               /*!< [7..7] Interrupt Set Pending for CCU6 SR3                             */
      __IO uint32_t  Int_SSC1   :  1;               /*!< [8..8] Interrupt Set Pending for SSC1                                 */
      __IO uint32_t  Int_SSC2   :  1;               /*!< [9..9] Interrupt Set Pending for SSC2                                 */
      __IO uint32_t  Int_UART1  :  1;               /*!< [10..10] Interrupt Set Pending for UART1                              */
      __IO uint32_t  Int_UART2  :  1;               /*!< [11..11] Interrupt Set Pending for UART2                              */
      __IO uint32_t  Int_EXINT0 :  1;               /*!< [12..12] Interrupt Set Pending for External Int 0                     */
      __IO uint32_t  Int_EXINT1 :  1;               /*!< [13..13] Interrupt Set Pending for External Int 1                     */
      __IO uint32_t  Int_WAKEUP :  1;               /*!< [14..14] Interrupt Set Pending for WAKEUP                             */
           uint32_t             :  2;
      __IO uint32_t  Int_LS1    :  1;               /*!< [17..17] Interrupt Set Pending for LS1                                */
      __IO uint32_t  Int_LS2    :  1;               /*!< [18..18] Interrupt Set Pending for LS2                                */
      __IO uint32_t  Int_HS1    :  1;               /*!< [19..19] Interrupt Set Pending for HS1                                */
      __IO uint32_t  Int_HS2    :  1;               /*!< [20..20] Interrupt Set Pending for HS2                                */
      __IO uint32_t  Int_DU     :  1;               /*!< [21..21] Interrupt Set Pending for Differential Unit                  */
      __IO uint32_t  Int_MON    :  1;               /*!< [22..22] Interrupt Set Pending for MON                                */
      __IO uint32_t  Int_PORT2  :  1;               /*!< [23..23] Interrupt Set Pending for PORT2                              */
    } bit;                                          /*!< [24] BitSize                                                          */
  } NVIC_ISPR;
  __I  uint32_t  RESERVED4[31];
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0xE000E280) Interrupt Clear-Pending                                */
    
    struct {
      __IO uint32_t  Int_GPT1   :  1;               /*!< [0..0] Interrupt Clear Pending for GPT1                               */
      __IO uint32_t  Int_GPT2   :  1;               /*!< [1..1] Interrupt Clear Pending for GPT2                               */
      __IO uint32_t  Int_ADC2   :  1;               /*!< [2..2] Interrupt Clear Pending for MU, ADC2                           */
      __IO uint32_t  Int_ADC1   :  1;               /*!< [3..3] Interrupt Clear Pending for ADC1                               */
      __IO uint32_t  Int_CCU6SR0:  1;               /*!< [4..4] Interrupt Clear Pending for CCU6 SR0                           */
      __IO uint32_t  Int_CCU6SR1:  1;               /*!< [5..5] Interrupt Clear Pending for CCU6 SR1                           */
      __IO uint32_t  Int_CCU6SR2:  1;               /*!< [6..6] Interrupt Clear Pending for CCU6 SR2                           */
      __IO uint32_t  Int_CCU6SR3:  1;               /*!< [7..7] Interrupt Clear Pending for CCU6 SR3                           */
      __IO uint32_t  Int_SSC1   :  1;               /*!< [8..8] Interrupt Clear Pending for SSC1                               */
      __IO uint32_t  Int_SSC2   :  1;               /*!< [9..9] Interrupt Clear Pending for SSC2                               */
      __IO uint32_t  Int_UART1  :  1;               /*!< [10..10] Interrupt Clear Pending for UART1                            */
      __IO uint32_t  Int_UART2  :  1;               /*!< [11..11] Interrupt Clear Pending for UART2                            */
      __IO uint32_t  Int_EXINT0 :  1;               /*!< [12..12] Interrupt Clear Pending for External Int 0                   */
      __IO uint32_t  Int_EXINT1 :  1;               /*!< [13..13] Interrupt Clear Pending for External Int 1                   */
      __IO uint32_t  Int_WAKEUP :  1;               /*!< [14..14] Interrupt Clear Pending for WAKEUP                           */
           uint32_t             :  2;
      __IO uint32_t  Int_LS1    :  1;               /*!< [17..17] Interrupt Clear Pending for LS1                              */
      __IO uint32_t  Int_LS2    :  1;               /*!< [18..18] Interrupt Clear Pending for LS2                              */
      __IO uint32_t  Int_HS1    :  1;               /*!< [19..19] Interrupt Clear Pending for HS1                              */
      __IO uint32_t  Int_HS2    :  1;               /*!< [20..20] Interrupt Clear Pending for HS2                              */
      __IO uint32_t  Int_DU     :  1;               /*!< [21..21] Interrupt Clear Pending for Differential Unit                */
      __IO uint32_t  Int_MON    :  1;               /*!< [22..22] Interrupt Clear Pending for MON                              */
      __IO uint32_t  Int_PORT2  :  1;               /*!< [23..23] Interrupt Clear Pending for PORT2                            */
    } bit;                                          /*!< [24] BitSize                                                          */
  } NVIC_ICPR;
  __I  uint32_t  RESERVED5[95];
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0xE000E400) Interrupt Priority                                     */
    
    struct {
      __IO uint32_t  PRI_GPT1   :  8;               /*!< [0..7] Priority for GPT1                                              */
      __IO uint32_t  PRI_GPT2   :  8;               /*!< [8..15] Priority for GPT2                                             */
      __IO uint32_t  PRI_ADC2   :  8;               /*!< [16..23] Priority for MU, ADC2                                        */
      __IO uint32_t  PRI_ADC1   :  8;               /*!< [24..31] Priority for ADC1                                            */
    } bit;                                          /*!< [32] BitSize                                                          */
  } NVIC_IPR0;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0xE000E404) Interrupt Priority                                     */
    
    struct {
      __IO uint32_t  PRI_CCU6SR0:  8;               /*!< [0..7] Priority for CCU6 SR0                                          */
      __IO uint32_t  PRI_CCU6SR1:  8;               /*!< [8..15] Priority for CCU6 SR1                                         */
      __IO uint32_t  PRI_CCU6SR2:  8;               /*!< [16..23] Priority for CCU6 SR2                                        */
      __IO uint32_t  PRI_CCU6SR3:  8;               /*!< [24..31] Priority for CCU6 SR3                                        */
    } bit;                                          /*!< [32] BitSize                                                          */
  } NVIC_IPR1;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0xE000E408) Interrupt Priority                                     */
    
    struct {
      __IO uint32_t  PRI_SSC1   :  8;               /*!< [0..7] Priority for CCU6 SSC1                                         */
      __IO uint32_t  PRI_SSC2   :  8;               /*!< [8..15] Priority for CCU6 SSC2                                        */
      __IO uint32_t  PRI_UART1  :  8;               /*!< [16..23] Priority for CCU6 UART1                                      */
      __IO uint32_t  PRI_UART2  :  8;               /*!< [24..31] Priority for CCU6 UART2                                      */
    } bit;                                          /*!< [32] BitSize                                                          */
  } NVIC_IPR2;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0xE000E40C) Interrupt Priority                                     */
    
    struct {
      __IO uint32_t  PRI_EXINT0 :  8;               /*!< [0..7] Priority for External Int 0                                    */
      __IO uint32_t  PRI_EXINT1 :  8;               /*!< [8..15] Priority for External Int 1                                   */
      __IO uint32_t  PRI_WAKEUP :  8;               /*!< [16..23] Priority for WAKEUP                                          */
    } bit;                                          /*!< [24] BitSize                                                          */
  } NVIC_IPR3;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0xE000E410) Interrupt Priority                                     */
    
    struct {
           uint32_t             :  8;
      __IO uint32_t  PRI_LS1    :  8;               /*!< [8..15] Priority for LS1                                              */
      __IO uint32_t  PRI_LS2    :  8;               /*!< [16..23] Priority for LS2                                             */
      __IO uint32_t  PRI_HS1    :  8;               /*!< [24..31] Priority for HS1                                             */
    } bit;                                          /*!< [32] BitSize                                                          */
  } NVIC_IPR4;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0xE000E414) Interrupt Priority                                     */
    
    struct {
      __IO uint32_t  PRI_HS2    :  8;               /*!< [0..7] Priority for HS2                                               */
      __IO uint32_t  PRI_DU     :  8;               /*!< [8..15] Priority for Differential Unit                                */
      __IO uint32_t  PRI_MON    :  8;               /*!< [16..23] Priority for MON                                             */
      __IO uint32_t  PRI_PORT2  :  8;               /*!< [24..31] Priority for PORT2                                           */
    } bit;                                          /*!< [32] BitSize                                                          */
  } NVIC_IPR5;
  __I  uint32_t  RESERVED6[570];
  
  union {
    __I  uint32_t  reg;                             /*!< (@ 0xE000ED00) CPU ID Base Register                                   */
    
    struct {
      __I  uint32_t  REVISION   :  4;               /*!< [0..3] Revision Number                                                */
      __I  uint32_t  PARTNO     : 12;               /*!< [4..15] Part Number                                                   */
      __I  uint32_t  CONSTANT   :  4;               /*!< [16..19] Constant                                                     */
      __I  uint32_t  VARIANT    :  4;               /*!< [20..23] Variant Number                                               */
      __I  uint32_t  IMPLEMENTER:  8;               /*!< [24..31] Implementer Code                                             */
    } bit;                                          /*!< [32] BitSize                                                          */
  } CPUID;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0xE000ED04) Interrupt Control and State Register                   */
    
    struct {
      __I  uint32_t  VECTACTIVE :  6;               /*!< [0..5] VECTACTIVE                                                     */
           uint32_t             :  6;
      __I  uint32_t  VECTPENDING:  6;               /*!< [12..17] VECTPENDING                                                  */
           uint32_t             :  4;
      __I  uint32_t  ISRPENDING :  1;               /*!< [22..22] Interrupt Pending Flag                                       */
           uint32_t             :  2;
      __O  uint32_t  PENDSTCLR  :  1;               /*!< [25..25] SysTick Exception Clear Pending                              */
      __IO uint32_t  PENDSTSET  :  1;               /*!< [26..26] SysTick Exception Set Pending                                */
      __O  uint32_t  PENDSVCLR  :  1;               /*!< [27..27] PENDSV Clear Pending                                         */
      __IO uint32_t  PENDSVSET  :  1;               /*!< [28..28] PENDSV Set Pending                                           */
           uint32_t             :  2;
      __IO uint32_t  NMIPENDSET :  1;               /*!< [31..31] NMI Set Pending                                              */
    } bit;                                          /*!< [32] BitSize                                                          */
  } ICSR;
  __I  uint32_t  RESERVED7;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0xE000ED0C) Application Interrupt/Reset Control Register           */
    
    struct {
           uint32_t             :  1;
      __O  uint32_t  VECTCLRACTIVE:  1;             /*!< [1..1] VECTCLRACTIVE                                                  */
      __O  uint32_t  SYSRESETREQ:  1;               /*!< [2..2] System Reset Request                                           */
           uint32_t             : 12;
      __I  uint32_t  ENDIANNESS :  1;               /*!< [15..15] Data Endianness                                              */
      __IO uint32_t  VECTKEY    : 16;               /*!< [16..31] Vector Key                                                   */
    } bit;                                          /*!< [32] BitSize                                                          */
  } AIRCR;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0xE000ED10) System Control Register                                */
    
    struct {
           uint32_t             :  1;
      __IO uint32_t  SLEEPONEXIT:  1;               /*!< [1..1] Sleep on Exit                                                  */
      __IO uint32_t  SLEEPDEEP  :  1;               /*!< [2..2] Sleep Deep                                                     */
           uint32_t             :  1;
      __IO uint32_t  SEVONPEND  :  1;               /*!< [4..4] SEVONPEND                                                      */
    } bit;                                          /*!< [5] BitSize                                                           */
  } SCR;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0xE000ED14) Configuration Control Register                         */
    
    struct {
           uint32_t             :  3;
      __IO uint32_t  UNALIGN_TRP:  1;               /*!< [3..3] UNALIGN_TRP                                                    */
           uint32_t             :  5;
      __IO uint32_t  STKALIGN   :  1;               /*!< [9..9] STKALIGN                                                       */
    } bit;                                          /*!< [10] BitSize                                                          */
  } CCR;
  __I  uint32_t  RESERVED8;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0xE000ED1C) System Handler Priority Register 2                     */
    
    struct {
           uint32_t             : 24;
      __IO uint32_t  PRI_11     :  8;               /*!< [24..31] Priority of System Handler 11, SVCall                        */
    } bit;                                          /*!< [32] BitSize                                                          */
  } SHPR2;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0xE000ED20) System Handler Priority Register 3                     */
    
    struct {
           uint32_t             : 16;
      __IO uint32_t  PRI_14     :  8;               /*!< [16..23] Priority of System Handler 14, PendSV                        */
      __IO uint32_t  PRI_15     :  8;               /*!< [24..31] Priority of System Handler 15, SysTick                       */
    } bit;                                          /*!< [32] BitSize                                                          */
  } SHPR3;
} CPU_Type;


/* ================================================================================ */
/* ================                     GPT12E                     ================ */
/* ================================================================================ */


/**
  * @brief GPT12E (GPT12E)
  */

typedef struct {                                    /*!< (@ 0x40010000) GPT12E Structure                                       */
  
  union {
    __I  uint32_t  reg;                             /*!< (@ 0x40010000) Module Identification Register                         */
    
    struct {
      __I  uint32_t  MOD_REV    :  8;               /*!< [0..7] Module Revision Number                                         */
      __I  uint32_t  MOD_TYPE   :  8;               /*!< [8..15] Module Identification Number                                  */
    } bit;                                          /*!< [16] BitSize                                                          */
  } ID;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x40010004) Port Input Select Register                             */
    
    struct {
      __IO uint32_t  IST2IN     :  1;               /*!< [0..0] Input Select for T2IN                                          */
      __IO uint32_t  IST2EUD    :  1;               /*!< [1..1] Input Select for T2EUD                                         */
      __IO uint32_t  IST3IN     :  2;               /*!< [2..3] Input Select for T3IN                                          */
      __IO uint32_t  IST3EUD    :  2;               /*!< [4..5] Input Select for T3EUD                                         */
      __IO uint32_t  IST4IN     :  2;               /*!< [6..7] Input Select for T4IN                                          */
      __IO uint32_t  IST4EUD    :  2;               /*!< [8..9] Input Select for TEUD                                          */
      __IO uint32_t  IST5IN     :  1;               /*!< [10..10] Input Select for T5IN                                        */
      __IO uint32_t  IST5EUD    :  1;               /*!< [11..11] Input Select for T5EUD                                       */
      __IO uint32_t  IST6IN     :  1;               /*!< [12..12] Input Select for T6IN                                        */
      __IO uint32_t  IST6EUD    :  1;               /*!< [13..13] Input Select for T6EUD                                       */
      __IO uint32_t  ISCAPIN    :  2;               /*!< [14..15] Input Select for CAPIN                                       */
    } bit;                                          /*!< [16] BitSize                                                          */
  } PISEL;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x40010008) Timer T2 Control Register                              */
    
    struct {
      __IO uint32_t  T2I        :  3;               /*!< [0..2] Timer T2 Input Parameter Selection                             */
      __IO uint32_t  T2M        :  3;               /*!< [3..5] Timer T2 Input Mode Control                                    */
      __IO uint32_t  T2R        :  1;               /*!< [6..6] Timer T2 Input Run Bit                                         */
      __IO uint32_t  T2UD       :  1;               /*!< [7..7] Timer T2 Up/Down Control                                       */
      __IO uint32_t  T2UDE      :  1;               /*!< [8..8] Timer T2 External Up/Down Enable                               */
      __IO uint32_t  T2RC       :  1;               /*!< [9..9] Timer T2 Remote Control                                        */
           uint32_t             :  2;
      __IO uint32_t  T2IRIDIS   :  1;               /*!< [12..12] Timer T2 Interrupt Disable                                   */
      __IO uint32_t  T2EDGE     :  1;               /*!< [13..13] Timer T2 Edge Detection                                      */
      __IO uint32_t  T2CHDIR    :  1;               /*!< [14..14] Timer T2 Count Direction Change                              */
      __I  uint32_t  T2DIR      :  1;               /*!< [15..15] Timer T2 Rotation Direction                                  */
    } bit;                                          /*!< [16] BitSize                                                          */
  } T2CON;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x4001000C) Timer T3 Control Register                              */
    
    struct {
      __IO uint32_t  T3I        :  3;               /*!< [0..2] Timer T3 Input Parameter Selection                             */
      __IO uint32_t  T3M        :  3;               /*!< [3..5] Timer T3 Input Mode Control                                    */
      __IO uint32_t  T3R        :  1;               /*!< [6..6] Timer T3 Input Run Bit                                         */
      __IO uint32_t  T3UD       :  1;               /*!< [7..7] Timer T3 Up/Down Control                                       */
      __IO uint32_t  T3UDE      :  1;               /*!< [8..8] Timer T3 External Up/Down Enable                               */
      __IO uint32_t  T3OE       :  1;               /*!< [9..9] Overflow/Underflow Output Enable                               */
      __IO uint32_t  T3OTL      :  1;               /*!< [10..10] Timer T3 Overflow Toggle Latch                               */
      __IO uint32_t  BPS1       :  2;               /*!< [11..12] GPT1 Block Prescaler Control                                 */
      __IO uint32_t  T3EDGE     :  1;               /*!< [13..13] Timer T3 Edge Detection Flag                                 */
      __IO uint32_t  T3CHDIR    :  1;               /*!< [14..14] Timer T3 Count Direction Change Flag                         */
      __I  uint32_t  T3DIR      :  1;               /*!< [15..15] Timer T3 Rotation Direction Flag                             */
    } bit;                                          /*!< [16] BitSize                                                          */
  } T3CON;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x40010010) Timer T4 Control Register                              */
    
    struct {
      __IO uint32_t  T4I        :  3;               /*!< [0..2] Timer T4 Input Parameter Selection                             */
      __IO uint32_t  T4M        :  3;               /*!< [3..5] Timer T4 Mode Control (Basic Operating Mode)                   */
      __IO uint32_t  T4R        :  1;               /*!< [6..6] Timer T4 Input Run Bit                                         */
      __IO uint32_t  T4UD       :  1;               /*!< [7..7] Timer T2 Up/Down Control                                       */
      __IO uint32_t  T4UDE      :  1;               /*!< [8..8] Timer T4 External Up/Down Enable                               */
      __IO uint32_t  T4RC       :  1;               /*!< [9..9] Timer T4 Remote Control                                        */
      __IO uint32_t  CLRT2EN    :  1;               /*!< [10..10] Clear Timer T2 Enable                                        */
      __IO uint32_t  CLRT3EN    :  1;               /*!< [11..11] Clear Timer T3 Enable                                        */
      __IO uint32_t  T4IRDIS    :  1;               /*!< [12..12] Timer T4 Interrupt Disable                                   */
      __IO uint32_t  T4EDGE     :  1;               /*!< [13..13] Timer T4 Edge Direction                                      */
      __IO uint32_t  T4CHDIR    :  1;               /*!< [14..14] Timer T4 Count Direction Change                              */
      __I  uint32_t  T4RDIR     :  1;               /*!< [15..15] Timer T4 Rotation Direction                                  */
    } bit;                                          /*!< [16] BitSize                                                          */
  } T4CON;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x40010014) Timer T5 Control Register                              */
    
    struct {
      __IO uint32_t  T5I        :  3;               /*!< [0..2] Timer T5 Input Parameter Selection                             */
      __IO uint32_t  T5M        :  2;               /*!< [3..4] Timer T5 Input Mode Control                                    */
           uint32_t             :  1;
      __IO uint32_t  T5R        :  1;               /*!< [6..6] Timer T5 Run Bit                                               */
      __IO uint32_t  T5UD       :  1;               /*!< [7..7] Timer T2 Up/Down Control                                       */
      __IO uint32_t  T5UDE      :  1;               /*!< [8..8] Timer T5 External Up/Down Enable                               */
      __IO uint32_t  T5RC       :  1;               /*!< [9..9] Timer T5 Remote Control                                        */
      __IO uint32_t  CT3        :  1;               /*!< [10..10] Timer T3 Capture Trigger Enable                              */
           uint32_t             :  1;
      __IO uint32_t  CI         :  2;               /*!< [12..13] Register CAPREL Capture Trigger Selection                    */
      __IO uint32_t  T5CLR      :  1;               /*!< [14..14] Timer T5 Clear Enable Bit                                    */
      __IO uint32_t  T5SC       :  1;               /*!< [15..15] Timer T5 Capture Mode Enable                                 */
    } bit;                                          /*!< [16] BitSize                                                          */
  } T5CON;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x40010018) Timer T6 Control Register                              */
    
    struct {
      __IO uint32_t  T6I        :  3;               /*!< [0..2] Timer T6 Input Parameter Selection                             */
      __IO uint32_t  T6M        :  3;               /*!< [3..5] Timer T6 Mode Control                                          */
      __IO uint32_t  T6R        :  1;               /*!< [6..6] Timer T6 Input Run Bit                                         */
      __IO uint32_t  T6UD       :  1;               /*!< [7..7] Timer T6 Up/Down Control                                       */
      __IO uint32_t  T6UDE      :  1;               /*!< [8..8] Timer T6 External Up/Down Enable                               */
      __IO uint32_t  T6OE       :  1;               /*!< [9..9] Overflow/Underflow Output Enable                               */
      __IO uint32_t  T6OTL      :  1;               /*!< [10..10] Timer T6 Overflow Toggle Latch                               */
      __IO uint32_t  BPS2       :  2;               /*!< [11..12] GPT2 Block Prescaler Control                                 */
           uint32_t             :  1;
      __IO uint32_t  T6CLR      :  1;               /*!< [14..14] Timer T6 Clear Enable Bit                                    */
      __IO uint32_t  T6SR       :  1;               /*!< [15..15] Timer T6 Reload Mode Enable                                  */
    } bit;                                          /*!< [16] BitSize                                                          */
  } T6CON;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x4001001C) Capture/Reload Register                                */
    
    struct {
      __IO uint32_t  CAPREL     : 16;               /*!< [0..15] Current reload value or Captured value                        */
    } bit;                                          /*!< [16] BitSize                                                          */
  } CAPREL;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x40010020) Timer T2 Count Register                                */
    
    struct {
      __IO uint32_t  T2         : 16;               /*!< [0..15] Timer T2 Current Value                                        */
    } bit;                                          /*!< [16] BitSize                                                          */
  } T2;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x40010024) Timer T3 Count Register                                */
    
    struct {
      __IO uint32_t  T3         : 16;               /*!< [0..15] Timer T3 Current Value                                        */
    } bit;                                          /*!< [16] BitSize                                                          */
  } T3;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x40010028) Timer T4 Count Register                                */
    
    struct {
      __IO uint32_t  T4         : 16;               /*!< [0..15] Timer T4 Current Value                                        */
    } bit;                                          /*!< [16] BitSize                                                          */
  } T4;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x4001002C) Timer 5 Count Register                                 */
    
    struct {
      __IO uint32_t  T5         : 16;               /*!< [0..15] Timer T5 Current Value                                        */
    } bit;                                          /*!< [16] BitSize                                                          */
  } T5;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x40010030) Timer 6 Count Register                                 */
    
    struct {
      __IO uint32_t  T6         : 16;               /*!< [0..15] Timer T6 Current Value                                        */
    } bit;                                          /*!< [16] BitSize                                                          */
  } T6;
} GPT12E_Type;


/* ================================================================================ */
/* ================                       HS                       ================ */
/* ================================================================================ */


/**
  * @brief HS (HS)
  */

typedef struct {                                    /*!< (@ 0x40024000) HS Structure                                           */
  __I  uint32_t  RESERVED;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x40024004) High Side Driver Control                               */
    
    struct {
      __IO uint32_t  HS1_EN     :  1;               /*!< [0..0] High Side 1 Enable                                             */
      __IO uint32_t  HS1_PWM    :  1;               /*!< [1..1] High Side 1 PWM Enable                                         */
      __IO uint32_t  HS1_ON     :  1;               /*!< [2..2] High Side 1 On                                                 */
      __IO uint32_t  HS1_OL_EN  :  1;               /*!< [3..3] High Side 1 Open Load Detection Enable                         */
           uint32_t             :  3;
      __IO uint32_t  HS1_CYC_ON_ACTIVE:  1;         /*!< [7..7] High Side 1 Cyclic ON Driver                                   */
      __IO uint32_t  HS1_SRCTL_SEL:  1;             /*!< [8..8] High Side 1 Slew Rate Control select                           */
           uint32_t             :  3;
      __IO uint32_t  HS1_OC_SEL :  2;               /*!< [12..13] High Side 1 Overcurrent Threshold Selection                  */
           uint32_t             :  2;
      __IO uint32_t  HS2_EN     :  1;               /*!< [16..16] High Side 2 Enable                                           */
      __IO uint32_t  HS2_PWM    :  1;               /*!< [17..17] High Side 2 PWM Enable                                       */
      __IO uint32_t  HS2_ON     :  1;               /*!< [18..18] High Side 2 On                                               */
      __IO uint32_t  HS2_OL_EN  :  1;               /*!< [19..19] High Side 2 Open Load Detection Enable                       */
           uint32_t             :  3;
      __IO uint32_t  HS2_CYC_ON_ACTIVE:  1;         /*!< [23..23] High Side 2 Cyclic ON Driver                                 */
      __IO uint32_t  HS2_SRCTL_SEL:  1;             /*!< [24..24] High Side 2 Slew Rate Control select                         */
           uint32_t             :  3;
      __IO uint32_t  HS2_OC_SEL :  2;               /*!< [28..29] High Side 1 Overcurrent Threshold Selection                  */
    } bit;                                          /*!< [30] BitSize                                                          */
  } CTRL;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x40024008) High Side Driver Interrupt Status                      */
    
    struct {
           uint32_t             :  5;
      __IO uint32_t  HS1_OT_IS  :  1;               /*!< [5..5] High Side 1 Overtemperature Interrupt Status                   */
      __IO uint32_t  HS1_OL_IS  :  1;               /*!< [6..6] High Side 1 Open Load Interrupt Status                         */
      __IO uint32_t  HS1_OC_IS  :  1;               /*!< [7..7] High Side 1 Overcurrent Interrupt Status                       */
           uint32_t             :  5;
      __IO uint32_t  HS1_OT_STS :  1;               /*!< [13..13] High Side 1 Overtemperature Status                           */
      __IO uint32_t  HS1_OL_STS :  1;               /*!< [14..14] High Side 1 Open Load Interrupt Status                       */
           uint32_t             :  6;
      __IO uint32_t  HS2_OT_IS  :  1;               /*!< [21..21] High Side 2 Overtemperature Interrupt Status                 */
      __IO uint32_t  HS2_OL_IS  :  1;               /*!< [22..22] High Side 2 Open Load Interrupt Status                       */
      __IO uint32_t  HS2_OC_IS  :  1;               /*!< [23..23] High Side 2 Overcurrent Interrupt Status                     */
           uint32_t             :  5;
      __IO uint32_t  HS2_OT_STS :  1;               /*!< [29..29] High Side 2 Overtemperature Status                           */
      __IO uint32_t  HS2_OL_STS :  1;               /*!< [30..30] High Side 2 Open Load Interrupt Status                       */
    } bit;                                          /*!< [31] BitSize                                                          */
  } IRQS;
  
  union {
    __O  uint32_t  reg;                             /*!< (@ 0x4002400C) High Side Driver Interrupt Status Clear Register       */
    
    struct {
           uint32_t             :  5;
      __O  uint32_t  HS1_OT_ISC :  1;               /*!< [5..5] High Side 1 Overtemperature Interrupt Status Clear             */
      __O  uint32_t  HS1_OL_ISC :  1;               /*!< [6..6] High Side 1 Open Load Interrupt Status Clear                   */
      __O  uint32_t  HS1_OC_ISC :  1;               /*!< [7..7] High Side 1 Overcurrent Interrupt Status Clear                 */
           uint32_t             :  5;
      __O  uint32_t  HS1_OT_SC  :  1;               /*!< [13..13] High Side 1 Overtemperature Status Clear                     */
      __O  uint32_t  HS1_OL_SC  :  1;               /*!< [14..14] High Side 1 Open Load Status Clear                           */
           uint32_t             :  6;
      __O  uint32_t  HS2_OT_ISC :  1;               /*!< [21..21] High Side 2 Overtemperature Interrupt Status Clear           */
      __O  uint32_t  HS2_OL_ISC :  1;               /*!< [22..22] High Side 2 Open Load Interrupt Status Clear                 */
      __O  uint32_t  HS2_OC_ISC :  1;               /*!< [23..23] High Side 2 Overcurrent Interrupt Status Clear               */
           uint32_t             :  5;
      __O  uint32_t  HS2_OT_SC  :  1;               /*!< [29..29] High Side 2 Overtemperature Status Clear                     */
      __O  uint32_t  HS2_OL_SC  :  1;               /*!< [30..30] High Side 2 Open Load Status Clear                           */
    } bit;                                          /*!< [31] BitSize                                                          */
  } IRQCLR;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x40024010) High Side Driver Interrupt Enable Register             */
    
    struct {
           uint32_t             :  5;
      __IO uint32_t  HS1_OT_IEN :  1;               /*!< [5..5] High Side 1 Overtemperature interrupt enable                   */
      __IO uint32_t  HS1_OL_IEN :  1;               /*!< [6..6] High Side 1 Open Load interrupt enable                         */
      __IO uint32_t  HS1_OC_IEN :  1;               /*!< [7..7] High Side 1 Overcurrent interrupt enable                       */
           uint32_t             : 13;
      __IO uint32_t  HS2_OT_IEN :  1;               /*!< [21..21] High Side 2 Overtemperature interrupt enable                 */
      __IO uint32_t  HS2_OL_IEN :  1;               /*!< [22..22] High Side 2 Open Load interrupt enable                       */
      __IO uint32_t  HS2_OC_IEN :  1;               /*!< [23..23] High Side 2 Overcurrent interrupt enable                     */
    } bit;                                          /*!< [24] BitSize                                                          */
  } IRQEN;
  __I  uint32_t  RESERVED1[2];
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x4002401C) High Side Driver 1 TRIM                                */
    
    struct {
      __IO uint32_t  HS1_OL_BTFILT_SEL:  2;         /*!< [0..1] Blanking Time Filter Select for HS1 Open Load Detection        */
           uint32_t             :  6;
      __IO uint32_t  HS1_OC_OT_BTFILT_SEL:  2;      /*!< [8..9] Blanking Time Filter Select for HS1 Overcurrent / Overtemperature
                                                         Detection                                                             */
    } bit;                                          /*!< [10] BitSize                                                          */
  } HS1_TRIM;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x40024020) High Side Driver 2 TRIM                                */
    
    struct {
      __IO uint32_t  HS2_OL_BTFILT_SEL:  2;         /*!< [0..1] Blanking Time Filter Select for HS2 Open Load Detection        */
           uint32_t             :  6;
      __IO uint32_t  HS2_OC_OT_BTFILT_SEL:  2;      /*!< [8..9] Blanking Time Filter Select for HS2 Overcurrent / Overtemperature
                                                         Detection                                                             */
    } bit;                                          /*!< [10] BitSize                                                          */
  } HS2_TRIM;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x40024024) High Side PWM Source Selection Register                */
    
    struct {
      __IO uint32_t  HS2_SRC_SEL:  3;               /*!< [0..2] HS2 PWM Source Selection                                       */
      __IO uint32_t  HS1_SRC_SEL:  3;               /*!< [3..5] HS1 PWM Source Selection                                       */
    } bit;                                          /*!< [6] BitSize                                                           */
  } PWMSRCSEL;
} HS_Type;


/* ================================================================================ */
/* ================                       LIN                      ================ */
/* ================================================================================ */


/**
  * @brief LIN (LIN)
  */

typedef struct {                                    /*!< (@ 0x4801E000) LIN Structure                                          */
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x4801E000) LIN Transceiver Control                                */
    
    struct {
           uint32_t             :  1;
      __IO uint32_t  MODE       :  2;               /*!< [1..2] LIN transceiver power mode control                             */
           uint32_t             :  1;
      __I  uint32_t  MODE_FB    :  3;               /*!< [4..6] Feedback Signals for LIN Transmitter Mode Settings             */
           uint32_t             :  2;
      __IO uint32_t  TXD        :  1;               /*!< [9..9] LIN Transmitter switch on (only used when LIN_HV_MODE
                                                         is set)                                                               */
      __I  uint32_t  RXD        :  1;               /*!< [10..10] Output Signal of Receiver                                    */
      __IO uint32_t  SM         :  2;               /*!< [11..12] LIN Transmitter Slope mode control                           */
      __I  uint32_t  FB_SM1     :  1;               /*!< [13..13] Feedback Signal 1 for Slope Mode Setting                     */
      __I  uint32_t  FB_SM2     :  1;               /*!< [14..14] Feedback Signal 2 for Slope Mode Setting                     */
      __I  uint32_t  FB_SM3     :  1;               /*!< [15..15] Feedback Signal 3 for Slope Mode Setting                     */
           uint32_t             :  5;
      __IO uint32_t  HV_MODE    :  1;               /*!< [21..21] LIN Transceiver High Voltage Input - Output Mode             */
    } bit;                                          /*!< [22] BitSize                                                          */
  } CTRL;
  
  union {
    __I  uint32_t  reg;                             /*!< (@ 0x4801E004) LIN Transceiver Interrupt Status                       */
    
    struct {
           uint32_t             :  3;
      __I  uint32_t  M_SM_ERR_IS:  1;               /*!< [3..3] LIN Transceiver Mode Error - Slope Mode Error Interrupt
                                                         Status                                                                */
      __I  uint32_t  OT_IS      :  1;               /*!< [4..4] LIN Receiver Overtemperature Interrupt Status                  */
      __I  uint32_t  OC_IS      :  1;               /*!< [5..5] LIN Receiver Overcurrent Interrupt Status                      */
      __I  uint32_t  TXD_TMOUT_IS:  1;              /*!< [6..6] LIN TXD time-out Interrupt Status                              */
           uint32_t             :  1;
      __I  uint32_t  M_SM_ERR_STS:  1;              /*!< [8..8] LIN Transceiver Mode Error - Slope Mode Error Status           */
      __I  uint32_t  OT_STS     :  1;               /*!< [9..9] LIN Receiver Overtemperature Status                            */
           uint32_t             :  1;
      __I  uint32_t  TXD_TMOUT_STS:  1;             /*!< [11..11] LIN TXD time-out Status                                      */
    } bit;                                          /*!< [12] BitSize                                                          */
  } IRQS;
  
  union {
    __O  uint32_t  reg;                             /*!< (@ 0x4801E008) LIN Transceiver Interrupt Status Register Clear        */
    
    struct {
           uint32_t             :  3;
      __O  uint32_t  M_SM_ERR_ISC:  1;              /*!< [3..3] LIN Transceiver Mode Error - Slope Mode Error Interrupt
                                                         Status Clear                                                          */
      __O  uint32_t  OT_ISC     :  1;               /*!< [4..4] LIN Receiver Overtemperature Interrupt Status / Status
                                                         Clear                                                                 */
      __O  uint32_t  OC_ISC     :  1;               /*!< [5..5] LIN Receiver Overcurrent Interrupt Status Clear                */
      __O  uint32_t  TXD_TMOUT_ISC:  1;             /*!< [6..6] LIN TXD time-out Interrupt Status Clear                        */
           uint32_t             :  1;
      __O  uint32_t  M_SM_ERR_SC:  1;               /*!< [8..8] LIN Transceiver Mode Error - Slope Mode Error Status
                                                         Clear                                                                 */
      __O  uint32_t  OT_SC      :  1;               /*!< [9..9] LIN Receiver Overtemperature Status Clear                      */
           uint32_t             :  1;
      __O  uint32_t  TXD_TMOUT_SC:  1;              /*!< [11..11] LIN TXD time-out Status Clear                                */
    } bit;                                          /*!< [12] BitSize                                                          */
  } IRQCLR;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x4801E00C) LIN Transceiver Interrupt Enable Register              */
    
    struct {
           uint32_t             :  3;
      __IO uint32_t  M_SM_ERR_IEN:  1;              /*!< [3..3] LIN Transceiver Mode - Slope Mode Error interrupt enable       */
      __IO uint32_t  OT_IEN     :  1;               /*!< [4..4] LIN Transceiver Overtemperature interrupt enable               */
      __IO uint32_t  OC_IEN     :  1;               /*!< [5..5] LIN Transceiver Overcurrent interrupt enable                   */
      __IO uint32_t  TXD_TMOUT_IEN:  1;             /*!< [6..6] LIN Transceiver TxD-Timeout interrupt enable                   */
    } bit;                                          /*!< [7] BitSize                                                           */
  } IRQEN;
} LIN_Type;


/* ================================================================================ */
/* ================                       LS                       ================ */
/* ================================================================================ */


/**
  * @brief LS (LS)
  */

typedef struct {                                    /*!< (@ 0x4001C000) LS Structure                                           */
  __I  uint32_t  RESERVED;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x4001C004) Low Side Driver Control                                */
    
    struct {
      __IO uint32_t  LS1_EN     :  1;               /*!< [0..0] Low-Side switch 1 Enable                                       */
      __IO uint32_t  LS1_PWM    :  1;               /*!< [1..1] Low-Side switch 1 PWM Enable                                   */
      __IO uint32_t  LS1_ON     :  1;               /*!< [2..2] Low-Side switch 1 On/Off                                       */
      __IO uint32_t  LS1_OL_EN  :  1;               /*!< [3..3] Open load Detection Enable                                     */
           uint32_t             :  4;
      __IO uint32_t  LS1_SRCTL_SEL:  1;             /*!< [8..8] Low-Side switch 1 Slew Rate selection                          */
           uint32_t             :  7;
      __IO uint32_t  LS2_EN     :  1;               /*!< [16..16] Low-Side switch 2 Enable                                     */
      __IO uint32_t  LS2_PWM    :  1;               /*!< [17..17] Low-Side switch 2 PWM Enable                                 */
      __IO uint32_t  LS2_ON     :  1;               /*!< [18..18] Low-Side switch 2 On/Off                                     */
      __IO uint32_t  LS2_OL_EN  :  1;               /*!< [19..19] Open load Detection Enable                                   */
           uint32_t             :  4;
      __IO uint32_t  LS2_SRCTL_SEL:  1;             /*!< [24..24] Low-Side switch 2 Slew Rate selection                        */
    } bit;                                          /*!< [25] BitSize                                                          */
  } CTRL;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x4001C008) Low Side Driver Interrupt Status                       */
    
    struct {
           uint32_t             :  4;
      __IO uint32_t  LS1_OT_PREWARN_IS:  1;         /*!< [4..4] Low-Side 1 Overtemperature Prewarning Interrupt Status         */
      __IO uint32_t  LS1_OT_IS  :  1;               /*!< [5..5] Low-Side 1 Overtemperature Interrupt Status                    */
      __IO uint32_t  LS1_OL_IS  :  1;               /*!< [6..6] Low-Side 1 Open Load Interrupt Status                          */
      __IO uint32_t  LS1_OC_IS  :  1;               /*!< [7..7] Low-Side 1 Overcurrent Interrupt Status                        */
           uint32_t             :  4;
      __IO uint32_t  LS1_OT_PREWARN_STS:  1;        /*!< [12..12] Low-Side 1 Overtemperature Prewarning Status                 */
      __IO uint32_t  LS1_OT_STS :  1;               /*!< [13..13] Low-Side 1 Overtemperature Status                            */
      __IO uint32_t  LS1_OL_STS :  1;               /*!< [14..14] Low-Side 1 Open Load Status                                  */
           uint32_t             :  5;
      __IO uint32_t  LS2_OT_PREWARN_IS:  1;         /*!< [20..20] Low-Side 2 Overtemperature Prewarning Interrupt Status       */
      __IO uint32_t  LS2_OT_IS  :  1;               /*!< [21..21] Low-Side 2 Overtemperature Interrupt Status                  */
      __IO uint32_t  LS2_OL_IS  :  1;               /*!< [22..22] Low-Side 2 Open Load Interrupt Status                        */
      __IO uint32_t  LS2_OC_IS  :  1;               /*!< [23..23] Low-Side 2 Overcurrent Interrupt Status                      */
           uint32_t             :  4;
      __IO uint32_t  LS2_OT_PREWARN_STS:  1;        /*!< [28..28] Low-Side 2 Overtemperature Prewarning Status                 */
      __IO uint32_t  LS2_OT_STS :  1;               /*!< [29..29] Low-Side 2 Overtemperature Status                            */
      __IO uint32_t  LS2_OL_STS :  1;               /*!< [30..30] Low-Side 2 Open Load Status                                  */
    } bit;                                          /*!< [31] BitSize                                                          */
  } IRQS;
  
  union {
    __O  uint32_t  reg;                             /*!< (@ 0x4001C00C) Low Side Driver Interrupt Status Register Clear        */
    
    struct {
           uint32_t             :  4;
      __O  uint32_t  LS1_OT_PREWARN_ISC:  1;        /*!< [4..4] Low-Side 1 Overtemperature prewarn interrupt status clear      */
      __O  uint32_t  LS1_OT_ISC :  1;               /*!< [5..5] Low-Side 1 Overtemperature interrupt status clear              */
      __O  uint32_t  LS1_OL_ISC :  1;               /*!< [6..6] Low-Side 1 Open Load interrupt status clear                    */
      __O  uint32_t  LS1_OC_ISC :  1;               /*!< [7..7] Low-Side 1 Overcurrent interrupt status clear                  */
           uint32_t             :  4;
      __O  uint32_t  LS1_OT_PREWARN_SC:  1;         /*!< [12..12] Low-Side 1 Overtemperature prewarn status clear              */
      __O  uint32_t  LS1_OT_SC  :  1;               /*!< [13..13] Low-Side 1 Overtemperature status clear                      */
      __O  uint32_t  LS1_OL_SC  :  1;               /*!< [14..14] Low-Side 1 Open Load status clear                            */
           uint32_t             :  5;
      __O  uint32_t  LS2_OT_PREWARN_ISC:  1;        /*!< [20..20] Low-Side 2Overtemperature prewarn interrupt status
                                                         clear                                                                 */
      __O  uint32_t  LS2_OT_ISC :  1;               /*!< [21..21] Low-Side 2 Overtemperature interrupt status clear            */
      __O  uint32_t  LS2_OL_ISC :  1;               /*!< [22..22] Low-Side 2 Open Load interrupt status clear                  */
      __O  uint32_t  LS2_OC_ISC :  1;               /*!< [23..23] Low-Side 2 Overcurrent interrupt status clear                */
           uint32_t             :  4;
      __O  uint32_t  LS2_OT_PREWARN_SC:  1;         /*!< [28..28] Low-Side 2 Overtemperature prewarn status clear              */
      __O  uint32_t  LS2_OT_SC  :  1;               /*!< [29..29] Low-Side switch 2 Overtemperature status Clear               */
      __O  uint32_t  LS2_OL_SC  :  1;               /*!< [30..30] Low-Side 2 Open Load status clear                            */
    } bit;                                          /*!< [31] BitSize                                                          */
  } IRQCLR;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x4001C010) Low Side Driver Interrupt Enable Register              */
    
    struct {
           uint32_t             :  4;
      __IO uint32_t  LS1_OT_PREWARN_IEN:  1;        /*!< [4..4] Low-Side 1 Overtemperature prewarn interrupt enable            */
      __IO uint32_t  LS1_OT_IEN :  1;               /*!< [5..5] Low-Side 1 Overtemperature interrupt enable                    */
      __IO uint32_t  LS1_OL_IEN :  1;               /*!< [6..6] Low-Side 1 Open Load interrupt enable                          */
      __IO uint32_t  LS1_OC_IEN :  1;               /*!< [7..7] Low-Side 1 Overcurrent interrupt enable                        */
           uint32_t             : 12;
      __IO uint32_t  LS2_OT_PREWARN_IEN:  1;        /*!< [20..20] Low-Side 2 Overtemperature prewarn interrupt enable          */
      __IO uint32_t  LS2_OT_IEN :  1;               /*!< [21..21] Low-Side 2 Overtemperature interrupt enable                  */
      __IO uint32_t  LS2_OL_IEN :  1;               /*!< [22..22] Low-Side 2 Open Load interrupt enable                        */
      __IO uint32_t  LS2_OC_IEN :  1;               /*!< [23..23] Low-Side 2 Overcurrent interrupt enable                      */
    } bit;                                          /*!< [24] BitSize                                                          */
  } IRQEN;
  __I  uint32_t  RESERVED1;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x4001C018) Low Side Trimming Register                             */
    
    struct {
      __IO uint32_t  LS1_OL_BTFILT_SEL:  2;         /*!< [0..1] Open load Blank Time Select for LS1                            */
           uint32_t             :  6;
      __IO uint32_t  LS1_OC_BTFILT_SEL:  2;         /*!< [8..9] Overcurrent BlankTime Select for LS1                           */
    } bit;                                          /*!< [10] BitSize                                                          */
  } LS1_TRIM;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x4001C01C) Low Side PWM Source Selection Register                 */
    
    struct {
      __IO uint32_t  LS2_SRC_SEL:  3;               /*!< [0..2] LS2 PWM Source Selection                                       */
      __IO uint32_t  LS1_SRC_SEL:  3;               /*!< [3..5] LS1 PWM Source Selection                                       */
    } bit;                                          /*!< [6] BitSize                                                           */
  } PWMSRCSEL;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x4001C020) Low Side Trimming Register                             */
    
    struct {
      __IO uint32_t  LS2_OL_BTFILT_SEL:  2;         /*!< [0..1] Open load Blank Time Select for LS2                            */
           uint32_t             :  6;
      __IO uint32_t  LS2_OC_BTFILT_SEL:  2;         /*!< [8..9] Overcurrent BlankTime Select for LS2                           */
    } bit;                                          /*!< [10] BitSize                                                          */
  } LS2_TRIM;
} LS_Type;


/* ================================================================================ */
/* ================                       MF                       ================ */
/* ================================================================================ */


/**
  * @brief MF (MF)
  */

typedef struct {                                    /*!< (@ 0x48018000) MF Structure                                           */
  __I  uint32_t  RESERVED[4];
  
  union {
    __I  uint32_t  reg;                             /*!< (@ 0x48018010) Temperature Sensor Control Register                    */
    
    struct {
           uint32_t             :  4;
      __I  uint32_t  LS_OTWARN_STS:  1;             /*!< [4..4] Low Side Overtemperature Warning (MU) Status                   */
      __I  uint32_t  LS_OT_STS  :  1;               /*!< [5..5] Low Side Overtemperature (MU) Status                           */
      __I  uint32_t  SYS_OTWARN_STS:  1;            /*!< [6..6] System Overtemperature Warning (MU) Status                     */
      __I  uint32_t  SYS_OT_STS :  1;               /*!< [7..7] System Overtemperature (MU) Status                             */
    } bit;                                          /*!< [8] BitSize                                                           */
  } TEMPSENSE_CTRL;
  
  union {
    __I  uint32_t  reg;                             /*!< (@ 0x48018014) Reference 1 Status Register                            */
    
    struct {
           uint32_t             :  4;
      __I  uint32_t  REFBG_LOTHWARN_STS:  1;        /*!< [4..4] Status for Undervoltage Threshold Measurement of internal
                                                         VAREF                                                                 */
      __I  uint32_t  REFBG_UPTHWARN_STS:  1;        /*!< [5..5] Status for Overvoltage Threshold Measurement of internal
                                                         VAREF                                                                 */
    } bit;                                          /*!< [6] BitSize                                                           */
  } REF1_STS;
} MF_Type;


/* ================================================================================ */
/* ================                       PMU                      ================ */
/* ================================================================================ */


/**
  * @brief PMU (PMU)
  */

typedef struct {                                    /*!< (@ 0x50004000) PMU Structure                                          */
  
  union {
    __I  uint32_t  reg;                             /*!< (@ 0x50004000) Main wake status register                              */
    
    struct {
      __I  uint32_t  LIN_WAKE   :  1;               /*!< [0..0] Wake-up via LIN- Message                                       */
      __I  uint32_t  MON        :  1;               /*!< [1..1] Wake-up via MON which is a logical OR combination of
                                                         all Wake_STS_MON bits                                                 */
      __I  uint32_t  GPIO0      :  1;               /*!< [2..2] Wake-up via GPIO0 which is a logical OR combination of
                                                         all Wake_STS_GPIO0 bits                                               */
      __I  uint32_t  GPIO1      :  1;               /*!< [3..3] Wake-up via GPIO1 which is a logical OR combination of
                                                         all Wake_STS_GPIO1 bits                                               */
      __I  uint32_t  CYC_WAKE   :  1;               /*!< [4..4] Wake-up caused by Cyclic Wake                                  */
      __I  uint32_t  FAIL       :  1;               /*!< [5..5] Wake-up after VDDEXT Fail                                      */
      __I  uint32_t  GPIO2      :  1;               /*!< [6..6] Wake-up via GPIO2 which is a logical OR combination of
                                                         all Wake_STS_GPIO2 bits                                               */
           uint32_t             :  1;
      __I  uint32_t  MON1_WAKE_STS:  1;             /*!< [8..8] Status of MON1                                                 */
      __I  uint32_t  MON2_WAKE_STS:  1;             /*!< [9..9] Status of MON2                                                 */
      __I  uint32_t  MON3_WAKE_STS:  1;             /*!< [10..10] Status of MON3                                               */
      __I  uint32_t  MON4_WAKE_STS:  1;             /*!< [11..11] Status of MON4                                               */
      __I  uint32_t  MON5_WAKE_STS:  1;             /*!< [12..12] Status of MON5                                               */
           uint32_t             :  4;
      __I  uint32_t  VDDEXT_OT  :  1;               /*!< [17..17] Wake VDDEXT Overtemperature                                  */
      __I  uint32_t  VDDEXT_UV  :  1;               /*!< [18..18] Wake VDDEXT Undervoltage                                     */
    } bit;                                          /*!< [19] BitSize                                                          */
  } WAKE_STATUS;
  
  union {
    __I  uint32_t  reg;                             /*!< (@ 0x50004004) GPIO Port wake status register                         */
    
    struct {
      __I  uint32_t  GPIO0_STS_0:  1;               /*!< [0..0] Status of GPIO0_0                                              */
      __I  uint32_t  GPIO0_STS_1:  1;               /*!< [1..1] Status of GPIO0_1                                              */
      __I  uint32_t  GPIO0_STS_2:  1;               /*!< [2..2] Status of GPIO0_2                                              */
      __I  uint32_t  GPIO0_STS_3:  1;               /*!< [3..3] Status of GPIO0_3                                              */
      __I  uint32_t  GPIO0_STS_4:  1;               /*!< [4..4] Status of GPIO0_4                                              */
           uint32_t             :  3;
      __I  uint32_t  GPIO1_STS_0:  1;               /*!< [8..8] Wake GPIO1_0                                                   */
      __I  uint32_t  GPIO1_STS_1:  1;               /*!< [9..9] Wake GPIO1_1                                                   */
      __I  uint32_t  GPIO1_STS_2:  1;               /*!< [10..10] Wake GPIO1_2                                                 */
           uint32_t             :  1;
      __I  uint32_t  GPIO1_STS_4:  1;               /*!< [12..12] Wake GPIO1_4                                                 */
    } bit;                                          /*!< [13] BitSize                                                          */
  } GPIO_WAKE_STATUS;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x50004008) Voltage Reg Status Register                            */
    
    struct {
      __I  uint32_t  PMU_1V5_OVERVOLT:  1;          /*!< [0..0] Overvoltage at VDDC regulator                                  */
      __I  uint32_t  PMU_1V5_OVERLOAD:  1;          /*!< [1..1] Overload at VDDC regulator                                     */
      __IO uint32_t  PMU_1V5_FAIL_EN:  1;           /*!< [2..2] Enabling of VDDC status information as interrupt source        */
           uint32_t             :  1;
      __I  uint32_t  PMU_5V_OVERVOLT:  1;           /*!< [4..4] Overvoltage at VDDP regulator                                  */
      __I  uint32_t  PMU_5V_OVERLOAD:  1;           /*!< [5..5] Overload at VDDP regulator                                     */
      __IO uint32_t  PMU_5V_FAIL_EN:  1;            /*!< [6..6] Enabling of VDDP status information as interrupt source        */
    } bit;                                          /*!< [7] BitSize                                                           */
  } SUPPLY_STS;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x5000400C) VDDEXT Control                                         */
    
    struct {
      __IO uint32_t  VDDEXT_ENABLE:  1;             /*!< [0..0] VDDEXT Supply Enable                                           */
      __IO uint32_t  VDDEXT_CYC_EN:  1;             /*!< [1..1] VDDEXT Supply for Cyclic Sense Enable                          */
      __IO uint32_t  VDDEXT_FAIL_EN:  1;            /*!< [2..2] Enabling of VDDEXT Supply status information as interrupt
                                                         source                                                                */
      __I  uint32_t  VDDEXT_OT_IS:  1;              /*!< [3..3] VDDEXT Supply Overtemperature Interrupt Status                 */
      __I  uint32_t  VDDEXT_UV_IS:  1;              /*!< [4..4] VDDEXT Supply Undervoltage Interrupt Status                    */
      __I  uint32_t  VDDEXT_OT_STS:  1;             /*!< [5..5] VDDEXT Supply Overtemperature Status                           */
      __I  uint32_t  VDDEXT_OT  :  1;               /*!< [6..6] VDDEXT Supply Overtemperature                                  */
      __I  uint32_t  VDDEXT_STABLE:  1;             /*!< [7..7] VDDEXT Supply Stable                                           */
           uint32_t             :  3;
      __O  uint32_t  VDDEXT_OT_ISC:  1;             /*!< [11..11] VDDEXT Supply Overtemperature Interrupt Status clear         */
      __O  uint32_t  VDDEXT_UV_ISC:  1;             /*!< [12..12] VDDEXT Supply Undervoltage Interrupt Status clear            */
      __O  uint32_t  VDDEXT_OT_SC:  1;              /*!< [13..13] VDDEXT Supply Overtemperature Status clear                   */
    } bit;                                          /*!< [14] BitSize                                                          */
  } VDDEXT_CTRL;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x50004010) Reset Status Register                                  */
    
    struct {
      __IO uint32_t  SYS_FAIL   :  1;               /*!< [0..0] Flag which indicates a reset caused by a System Fail
                                                         reported in the corresponding Fail Register                           */
      __IO uint32_t  PMU_WAKE   :  1;               /*!< [1..1] Flag which indicates a reset caused by Stop-Exit               */
      __IO uint32_t  PMU_SleepEX:  1;               /*!< [2..2] Flag which indicates a reset caused by Sleep-Exit              */
      __IO uint32_t  PMU_LPR    :  1;               /*!< [3..3] Low Priority Resets                                            */
      __IO uint32_t  PMU_ClkWDT :  1;               /*!< [4..4] Clock Watchdog (CLKWDT) Reset Flag                             */
      __IO uint32_t  PMU_ExtWDT :  1;               /*!< [5..5] External Watchdog (WDT1) Reset Flag                            */
      __IO uint32_t  PMU_PIN    :  1;               /*!< [6..6] PIN-Reset Flag                                                 */
      __IO uint32_t  PMU_VS_POR :  1;               /*!< [7..7] Power-On Reset Flag                                            */
           uint32_t             :  1;
      __IO uint32_t  PMU_SOFT   :  1;               /*!< [9..9] Soft-Reset Flag                                                */
      __IO uint32_t  LOCKUP     :  1;               /*!< [10..10] Lockup-Reset Flag                                            */
    } bit;                                          /*!< [11] BitSize                                                          */
  } RESET_STS;
  __I  uint32_t  RESERVED[3];
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x50004020) PMU Sleep Behavior Register                            */
    
    struct {
      __IO uint32_t  WAKE_W_RST :  1;               /*!< [0..0] Wake-up with reset execution                                   */
      __IO uint32_t  EN_0V9_N   :  1;               /*!< [1..1] Enables the reduction of the VDDC regulator output to
                                                         0.9 V during Stop-Mode                                                */
      __IO uint32_t  CYC_WAKE_EN:  1;               /*!< [2..2] Enabling Cyclic Wake                                           */
      __IO uint32_t  CYC_SENSE_EN:  1;              /*!< [3..3] Enabling Cyclic Sense                                          */
      __IO uint32_t  RFU        :  1;               /*!< [4..4] Reserved for Future Use                                        */
           uint32_t             :  3;
      __IO uint32_t  CYC_SENSE_M03:  4;             /*!< [8..11] Mantissa                                                      */
      __IO uint32_t  CYC_SENSE_E01:  2;             /*!< [12..13] Exponent                                                     */
           uint32_t             :  2;
      __IO uint32_t  CYC_WAKE_M03:  4;              /*!< [16..19] Mantissa                                                     */
      __IO uint32_t  CYC_WAKE_E01:  2;              /*!< [20..21] Exponent                                                     */
           uint32_t             :  2;
      __IO uint32_t  CYC_SENSE_S_DEL:  3;           /*!< [24..26] Sample Delay in Cyclic Sense Mode                            */
    } bit;                                          /*!< [27] BitSize                                                          */
  } SLEEP;
  __I  uint32_t  RESERVED1[4];
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x50004034) Settings Monitor 1-4                                   */
    
    struct {
      __IO uint32_t  MON1_EN    :  1;               /*!< [0..0] MON1 Enable                                                    */
      __IO uint32_t  MON1_FALL  :  1;               /*!< [1..1] MON1 Wake-up on Falling Edge Enable                            */
      __IO uint32_t  MON1_RISE  :  1;               /*!< [2..2] MON1 Wake-up on Rising Edge Enable                             */
      __IO uint32_t  MON1_CYC   :  1;               /*!< [3..3] MON1 for Cycle Sense Enable                                    */
      __IO uint32_t  MON1_PD    :  1;               /*!< [4..4] Pull-Down Current Source for MON1 Input Enable                 */
      __IO uint32_t  MON1_PU    :  1;               /*!< [5..5] Pull-Up Current Source for MON1 Input Enable                   */
           uint32_t             :  1;
      __I  uint32_t  MON1_STS   :  1;               /*!< [7..7] MON1 Status Input                                              */
      __IO uint32_t  MON2_EN    :  1;               /*!< [8..8] MON2 Enable                                                    */
      __IO uint32_t  MON2_FALL  :  1;               /*!< [9..9] MON2 Wake-up on Falling Edge Enable                            */
      __IO uint32_t  MON2_RISE  :  1;               /*!< [10..10] MON2 Wake-up on Rising Edge Enable                           */
      __IO uint32_t  MON2_CYC   :  1;               /*!< [11..11] MON2 for Cycle Sense Enable                                  */
      __IO uint32_t  MON2_PD    :  1;               /*!< [12..12] Pull-Down Current Source for MON2 Input Enable               */
      __IO uint32_t  MON2_PU    :  1;               /*!< [13..13] Pull-Up Current Source for MON2 Input Enable                 */
           uint32_t             :  1;
      __I  uint32_t  MON2_STS   :  1;               /*!< [15..15] MON2 Status Input                                            */
      __IO uint32_t  MON3_EN    :  1;               /*!< [16..16] MON3 Enable                                                  */
      __IO uint32_t  MON3_FALL  :  1;               /*!< [17..17] MON3 Wake-up on Falling Edge Enable                          */
      __IO uint32_t  MON3_RISE  :  1;               /*!< [18..18] MON3 Wake-up on Rising Edge Enable                           */
      __IO uint32_t  MON3_CYC   :  1;               /*!< [19..19] MON3 for Cycle Sense Enable                                  */
      __IO uint32_t  MON3_PD    :  1;               /*!< [20..20] Pull-Down Current Source for MON3 Input Enable               */
      __IO uint32_t  MON3_PU    :  1;               /*!< [21..21] Pull-Up Current Source for MON3 Input Enable                 */
           uint32_t             :  1;
      __I  uint32_t  MON3_STS   :  1;               /*!< [23..23] MON3 Status Input                                            */
      __IO uint32_t  MON4_EN    :  1;               /*!< [24..24] MON4 Enable                                                  */
      __IO uint32_t  MON4_FALL  :  1;               /*!< [25..25] MON4 Wake-up on Falling Edge Enable                          */
      __IO uint32_t  MON4_RISE  :  1;               /*!< [26..26] MON4 Wake-up on Rising Edge Enable                           */
      __IO uint32_t  MON4_CYC   :  1;               /*!< [27..27] MON4 for Cycle Sense Enable                                  */
      __IO uint32_t  MON4_PD    :  1;               /*!< [28..28] Pull-Down Current Source for MON4 Input Enable               */
      __IO uint32_t  MON4_PU    :  1;               /*!< [29..29] Pull-Up Current Source for MON4 Input Enable                 */
           uint32_t             :  1;
      __I  uint32_t  MON4_STS   :  1;               /*!< [31..31] MON4 Status Input                                            */
    } bit;                                          /*!< [32] BitSize                                                          */
  } MON_CNF1;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x50004038) Settings Monitor 5                                     */
    
    struct {
      __IO uint32_t  MON5_EN    :  1;               /*!< [0..0] MON5 Enable                                                    */
      __IO uint32_t  MON5_FALL  :  1;               /*!< [1..1] MON5 Wake-up on Falling Edge Enable                            */
      __IO uint32_t  MON5_RISE  :  1;               /*!< [2..2] MON5 Wake-up on Rising Edge Enable                             */
      __IO uint32_t  MON5_CYC   :  1;               /*!< [3..3] MON5 for Cycle Sense Enable                                    */
      __IO uint32_t  MON5_PD    :  1;               /*!< [4..4] Pull-Down Current Source for MON5 Input Enable                 */
      __IO uint32_t  MON5_PU    :  1;               /*!< [5..5] Pull-Up Current Source for MON5 Input Enable                   */
           uint32_t             :  1;
      __I  uint32_t  MON5_STS   :  1;               /*!< [7..7] MON5 Status Input                                              */
    } bit;                                          /*!< [8] BitSize                                                           */
  } MON_CNF2;
  __I  uint32_t  RESERVED2[5];
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x50004050) LIN Wake Enable                                        */
    
    struct {
           uint32_t             :  7;
      __IO uint32_t  LIN_EN     :  1;               /*!< [7..7] Lin Wake enable                                                */
    } bit;                                          /*!< [8] BitSize                                                           */
  } LIN_WAKE_EN;
  __I  uint32_t  RESERVED3[2];
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x5000405C) High-side Control Register                             */
    
    struct {
           uint32_t             :  2;
      __IO uint32_t  HS1_CYC_EN :  1;               /*!< [2..2] High-side 1 switch enable for cyclic sense                     */
           uint32_t             :  7;
      __IO uint32_t  HS2_CYC_EN :  1;               /*!< [10..10] High-side 2 switch enable for cyclic sense                   */
    } bit;                                          /*!< [11] BitSize                                                          */
  } HIGHSIDE_CTRL;
  __I  uint32_t  RESERVED4[3];
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x5000406C) Reset Blind Time Register                              */
    
    struct {
      __IO uint32_t  RST_TFB    :  2;               /*!< [0..1] Reset Pin Blind Time Selection Bits                            */
    } bit;                                          /*!< [2] BitSize                                                           */
  } CNF_RST_TFB;
  
  union {
    __I  uint32_t  reg;                             /*!< (@ 0x50004070) WFS System Fail Register                               */
    
    struct {
      __I  uint32_t  SUPP_SHORT :  1;               /*!< [0..0] Supply Short                                                   */
      __I  uint32_t  SUPP_TMOUT :  1;               /*!< [1..1] Supply Time Out                                                */
      __I  uint32_t  PMU_1V5_OVL:  1;               /*!< [2..2] VDDC Overload Flag                                             */
      __I  uint32_t  PMU_5V_OVL :  1;               /*!< [3..3] VDDP Overload Flag                                             */
      __I  uint32_t  SYS_CLK_WDT:  1;               /*!< [4..4] System Clock (fsys)Watchdog Fail                               */
      __I  uint32_t  SYS_OT     :  1;               /*!< [5..5] System Overtemperature Indication Flag                         */
      __I  uint32_t  WDT1_SEQ_FAIL:  1;             /*!< [6..6] External Watchdog (WDT1) Sequential Fail                       */
      __I  uint32_t  LP_CLKWD   :  1;               /*!< [7..7] LP_CLKWD                                                       */
    } bit;                                          /*!< [8] BitSize                                                           */
  } WFS;
  __I  uint32_t  RESERVED5[2];
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x5000407C) GPREG CNF                                              */
    
    struct {
      __IO uint32_t  SEL_GPIO   :  1;               /*!< [0..0] SEL_GPIO                                                       */
    } bit;                                          /*!< [1] BitSize                                                           */
  } CPREG_CNF;
  __I  uint32_t  RESERVED6[11];
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x500040AC) PMU Wake-up Timing Register                            */
    
    struct {
      __IO uint32_t  CNF_LIN_FT :  1;               /*!< [0..0] Wake-up Filter time for LIN WAKE                               */
      __IO uint32_t  CNF_MON_FT :  1;               /*!< [1..1] Wake-up Filter time for Monitoring Inputs                      */
      __IO uint32_t  CNF_GPIO_FT:  2;               /*!< [2..3] Wake-up Filter time for General Purpose IO                     */
    } bit;                                          /*!< [4] BitSize                                                           */
  } CNF_WAKE_FILTER;
  __I  uint32_t  RESERVED7[4];
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x500040C0) General Purpose User DATA0to3                          */
    
    struct {
      __IO uint32_t  DATA0      :  8;               /*!< [0..7] DATA0 Storage Byte                                             */
      __IO uint32_t  DATA1      :  8;               /*!< [8..15] DATA1 Storage Byte                                            */
      __IO uint32_t  DATA2      :  8;               /*!< [16..23] DATA2 Storage Byte                                           */
      __IO uint32_t  DATA3      :  8;               /*!< [24..31] DATA3 Storage Byte                                           */
    } bit;                                          /*!< [32] BitSize                                                          */
  } GPUDATA0to3;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x500040C4) General Purpose User DATA4to7                          */
    
    struct {
      __IO uint32_t  DATA4      :  8;               /*!< [0..7] DATA4 Storage Byte                                             */
      __IO uint32_t  DATA5      :  8;               /*!< [8..15] DATA5 Storage Byte                                            */
      __IO uint32_t  DATA6      :  8;               /*!< [16..23] DATA6 Storage Byte                                           */
      __IO uint32_t  DATA7      :  8;               /*!< [24..31] DATA7 Storage Byte                                           */
    } bit;                                          /*!< [32] BitSize                                                          */
  } GPUDATA4to7;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x500040C8) General Purpose User DATA8to11                         */
    
    struct {
      __IO uint32_t  DATA8      :  8;               /*!< [0..7] DATA8 Storage Byte                                             */
      __IO uint32_t  DATA9      :  8;               /*!< [8..15] DATA9 Storage Byte                                            */
      __IO uint32_t  DATA10     :  8;               /*!< [16..23] DATA10 Storage Byte                                          */
      __IO uint32_t  DATA11     :  8;               /*!< [24..31] DATA11 Storage Byte                                          */
    } bit;                                          /*!< [32] BitSize                                                          */
  } GPUDATA8to11;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x500040CC) Wake Configuration GPIO Port 1 Register                */
    
    struct {
      __IO uint32_t  RI_0       :  1;               /*!< [0..0] Port 1_0 Wake-up on Rising Edge enable                         */
      __IO uint32_t  RI_1       :  1;               /*!< [1..1] Port 1_1 Wake-up on Rising Edge enable                         */
      __IO uint32_t  RI_2       :  1;               /*!< [2..2] Port 1_2 Wake-up on Rising Edge enable                         */
      __IO uint32_t  RI_3       :  1;               /*!< [3..3] Port 1_3 Wake-up on Rising Edge enable                         */
      __IO uint32_t  RI_4       :  1;               /*!< [4..4] Port 1_4 Wake-up on Rising Edge enable                         */
           uint32_t             :  3;
      __IO uint32_t  FA_0       :  1;               /*!< [8..8] Port 1_0 Wake-up on Falling Edge enable                        */
      __IO uint32_t  FA_1       :  1;               /*!< [9..9] Port 1_1 Wake-up on Falling Edge enable                        */
      __IO uint32_t  FA_2       :  1;               /*!< [10..10] Port 1_2 Wake-up on Falling Edge enable                      */
      __IO uint32_t  FA_3       :  1;               /*!< [11..11] Port 1_3 Wake-up on Falling Edge enable                      */
      __IO uint32_t  FA_4       :  1;               /*!< [12..12] Port 1_4 Wake-up on Falling Edge enable                      */
           uint32_t             :  3;
      __IO uint32_t  CYC_0      :  1;               /*!< [16..16] GPIO1_0 input for cycle sense enable                         */
      __IO uint32_t  CYC_1      :  1;               /*!< [17..17] GPIO1_1 input for cycle sense enable                         */
      __IO uint32_t  CYC_2      :  1;               /*!< [18..18] GPIO1_2 input for cycle sense enable                         */
      __IO uint32_t  CYC_3      :  1;               /*!< [19..19] GPIO1_3 input for cycle sense enable                         */
      __IO uint32_t  CYC_4      :  1;               /*!< [20..20] GPIO1_4 input for cycle sense enable                         */
    } bit;                                          /*!< [21] BitSize                                                          */
  } WAKE_CNF_GPIO1;
} PMU_Type;


/* ================================================================================ */
/* ================                      PORT                      ================ */
/* ================================================================================ */


/**
  * @brief PORT (PORT)
  */

typedef struct {                                    /*!< (@ 0x48028000) PORT Structure                                         */
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x48028000) Port 0 Data Register                                   */
    
    struct {
      __IO uint32_t  PP0        :  1;               /*!< [0..0] Port 0 Pin 0 Data Value                                        */
      __IO uint32_t  PP1        :  1;               /*!< [1..1] Port 0 Pin 1 Data Value                                        */
      __IO uint32_t  PP2        :  1;               /*!< [2..2] Port 0 Pin 2 Data Value                                        */
      __IO uint32_t  PP3        :  1;               /*!< [3..3] Port 0 Pin 3 Data Value                                        */
      __IO uint32_t  PP4        :  1;               /*!< [4..4] Port 0 Pin 4 Data Value                                        */
      __IO uint32_t  PP5        :  1;               /*!< [5..5] Port 0 Pin 5 Data Value                                        */
           uint32_t             : 10;
      __I  uint32_t  PP0_STS    :  1;               /*!< [16..16] Port 0 Pin 0 Data Value (read back of Port Data when
                                                         IO is configured as output)                                           */
      __I  uint32_t  PP1_STS    :  1;               /*!< [17..17] Port 0 Pin 1 Data Value (read back of Port Data when
                                                         IO is configured as output)                                           */
      __I  uint32_t  PP2_STS    :  1;               /*!< [18..18] Port 0 Pin 2 Data Value (read back of Port Data when
                                                         IO is configured as output)                                           */
      __I  uint32_t  PP3_STS    :  1;               /*!< [19..19] Port 0 Pin 3 Data Value (read back of Port Data when
                                                         IO is configured as output)                                           */
      __I  uint32_t  PP4_STS    :  1;               /*!< [20..20] Port 0 Pin 4 Data Value (read back of Port Data when
                                                         IO is configured as output)                                           */
      __I  uint32_t  PP5_STS    :  1;               /*!< [21..21] Port 0 Pin 5 Data Value (read back of Port Data when
                                                         IO is configured as output)                                           */
    } bit;                                          /*!< [22] BitSize                                                          */
  } P0_DATA;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x48028004) Port 0 Direction Register                              */
    
    struct {
      __IO uint32_t  PP0        :  1;               /*!< [0..0] Port 0 Pin 0 Direction Control                                 */
      __IO uint32_t  PP1        :  1;               /*!< [1..1] Port 0 Pin 1 Direction Control                                 */
      __IO uint32_t  PP2        :  1;               /*!< [2..2] Port 0 Pin 2 Direction Control                                 */
      __IO uint32_t  PP3        :  1;               /*!< [3..3] Port 0 Pin 3 Direction Control                                 */
      __IO uint32_t  PP4        :  1;               /*!< [4..4] Port 0 Pin 4 Direction Control                                 */
      __IO uint32_t  PP5        :  1;               /*!< [5..5] Port 0 Pin 5 Direction Control                                 */
           uint32_t             : 10;
      __IO uint32_t  PP0_INEN   :  1;               /*!< [16..16] Port 0 Pin 0 Input Schmitt Trigger enable (only valid
                                                         if IO is configured as output)                                        */
      __IO uint32_t  PP1_INEN   :  1;               /*!< [17..17] Port 0 Pin 1 Input Schmitt Trigger enable (only valid
                                                         if IO is configured as output)                                        */
      __IO uint32_t  PP2_INEN   :  1;               /*!< [18..18] Port 0 Pin 2 Input Schmitt Trigger enable (only valid
                                                         if IO is configured as output)                                        */
      __IO uint32_t  PP3_INEN   :  1;               /*!< [19..19] Port 0 Pin 3 Input Schmitt Trigger enable (only valid
                                                         if IO is configured as output)                                        */
      __IO uint32_t  PP4_INEN   :  1;               /*!< [20..20] Port 0 Pin 4 Input Schmitt Trigger enable (only valid
                                                         if IO is configured as output)                                        */
      __IO uint32_t  PP5_INEN   :  1;               /*!< [21..21] Port 0 Pin 5 Input Schmitt Trigger enable (only valid
                                                         if IO is configured as output)                                        */
    } bit;                                          /*!< [22] BitSize                                                          */
  } P0_DIR;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x48028008) Port 0 Open Drain Control Register                     */
    
    struct {
      __IO uint32_t  PP0        :  1;               /*!< [0..0] Port 0 Pin 0 Open Drain Mode                                   */
      __IO uint32_t  PP1        :  1;               /*!< [1..1] Port 0 Pin 1 Open Drain Mode                                   */
      __IO uint32_t  PP2        :  1;               /*!< [2..2] Port 0 Pin 2 Open Drain Mode                                   */
      __IO uint32_t  PP3        :  1;               /*!< [3..3] Port 0 Pin 3 Open Drain Mode                                   */
      __IO uint32_t  PP4        :  1;               /*!< [4..4] Port 0 Pin 4 Open Drain Mode                                   */
      __IO uint32_t  PP5        :  1;               /*!< [5..5] Port 0 Pin 5 Open Drain Mode                                   */
    } bit;                                          /*!< [6] BitSize                                                           */
  } P0_OD;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x4802800C) Port 0 Pull-Up/Pull-Down Select Register               */
    
    struct {
      __IO uint32_t  PP0        :  1;               /*!< [0..0] Pull-Up/Pull-Down Select Port 0 Bit 0                          */
      __IO uint32_t  PP1        :  1;               /*!< [1..1] Pull-Up/Pull-Down Select Port 0 Bit 1                          */
      __IO uint32_t  PP2        :  1;               /*!< [2..2] Pull-Up/Pull-Down Select Port 0 Bit 2                          */
      __IO uint32_t  PP3        :  1;               /*!< [3..3] Pull-Up/Pull-Down Select Port 0 Bit 3                          */
      __IO uint32_t  PP4        :  1;               /*!< [4..4] Pull-Up/Pull-Down Select Port 0 Bit 4                          */
      __IO uint32_t  PP5        :  1;               /*!< [5..5] Pull-Up/Pull-Down Select Port 0 Bit 5                          */
    } bit;                                          /*!< [6] BitSize                                                           */
  } P0_PUDSEL;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x48028010) Port 0 Pull-Up/Pull-Down Enable Register               */
    
    struct {
      __IO uint32_t  PP0        :  1;               /*!< [0..0] Pull-Up/Pull-Down Enable at Port 0 Bit 0                       */
      __IO uint32_t  PP1        :  1;               /*!< [1..1] Pull-Up/Pull-Down Enable at Port 0 Bit 1                       */
      __IO uint32_t  PP2        :  1;               /*!< [2..2] Pull-Up/Pull-Down Enable at Port 0 Bit 2                       */
      __IO uint32_t  PP3        :  1;               /*!< [3..3] Pull-Up/Pull-Down Enable at Port 0 Bit 3                       */
      __IO uint32_t  PP4        :  1;               /*!< [4..4] Pull-Up/Pull-Down Enable at Port 0 Bit 4                       */
      __IO uint32_t  PP5        :  1;               /*!< [5..5] Pull-Up/Pull-Down Enable at Port 0 Bit 5                       */
    } bit;                                          /*!< [6] BitSize                                                           */
  } P0_PUDEN;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x48028014) Port 0 Alternate Select Register 0                     */
    
    struct {
      __IO uint32_t  PP0        :  1;               /*!< [0..0] See                                                            */
      __IO uint32_t  PP1        :  1;               /*!< [1..1] See                                                            */
      __IO uint32_t  PP2        :  1;               /*!< [2..2] See                                                            */
      __IO uint32_t  PP3        :  1;               /*!< [3..3] See                                                            */
      __IO uint32_t  PP4        :  1;               /*!< [4..4] See                                                            */
      __IO uint32_t  PP5        :  1;               /*!< [5..5] See                                                            */
    } bit;                                          /*!< [6] BitSize                                                           */
  } P0_ALTSEL0;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x48028018) Port 0 Alternate Select Register 1                     */
    
    struct {
      __IO uint32_t  PP0        :  1;               /*!< [0..0] See                                                            */
      __IO uint32_t  PP1        :  1;               /*!< [1..1] See                                                            */
      __IO uint32_t  PP2        :  1;               /*!< [2..2] See                                                            */
      __IO uint32_t  PP3        :  1;               /*!< [3..3] See                                                            */
      __IO uint32_t  PP4        :  1;               /*!< [4..4] See                                                            */
      __IO uint32_t  PP5        :  1;               /*!< [5..5] See                                                            */
    } bit;                                          /*!< [6] BitSize                                                           */
  } P0_ALTSEL1;
  __I  uint32_t  RESERVED;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x48028020) Port 1 Data Register                                   */
    
    struct {
      __IO uint32_t  PP0        :  1;               /*!< [0..0] Port 1 Pin 0 Data Value                                        */
      __IO uint32_t  PP1        :  1;               /*!< [1..1] Port 1 Pin 1 Data Value                                        */
      __IO uint32_t  PP2        :  1;               /*!< [2..2] Port 1 Pin 2 Data Value                                        */
           uint32_t             :  1;
      __IO uint32_t  PP4        :  1;               /*!< [4..4] Port 1 Pin 4 Data Value                                        */
           uint32_t             : 11;
      __IO uint32_t  PP0_STS    :  1;               /*!< [16..16] Port 1 Pin 0 Data Value (read back of Port Data when
                                                         IO is configured as output)                                           */
      __IO uint32_t  PP1_STS    :  1;               /*!< [17..17] Port 1 Pin 1 Data Value (read back of Port Data when
                                                         IO is configured as output)                                           */
      __IO uint32_t  PP2_STS    :  1;               /*!< [18..18] Port 1 Pin 2 Data Value (read back of Port Data when
                                                         IO is configured as output)                                           */
           uint32_t             :  1;
      __IO uint32_t  PP4_STS    :  1;               /*!< [20..20] Port 1 Pin 4 Data Value (read back of Port Data when
                                                         IO is configured as output)                                           */
    } bit;                                          /*!< [21] BitSize                                                          */
  } P1_DATA;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x48028024) Port 1 Direction Register                              */
    
    struct {
      __IO uint32_t  PP0        :  1;               /*!< [0..0] Port 1 Pin 0 Direction Control                                 */
      __IO uint32_t  PP1        :  1;               /*!< [1..1] Port 1 Pin 1 Direction Control                                 */
      __IO uint32_t  PP2        :  1;               /*!< [2..2] Port 1 Pin 2 Direction Control                                 */
           uint32_t             :  1;
      __IO uint32_t  PP4        :  1;               /*!< [4..4] Port 1 Pin 4 Direction Control                                 */
           uint32_t             : 11;
      __IO uint32_t  PP0_INEN   :  1;               /*!< [16..16] Port 1 Pin 0 Input Schmitt Trigger enable (only valid
                                                         if IO is configured as output)                                        */
      __IO uint32_t  PP1_INEN   :  1;               /*!< [17..17] Port 1 Pin 1 Input Schmitt Trigger enable (only valid
                                                         if IO is configured as output)                                        */
      __IO uint32_t  PP2_INEN   :  1;               /*!< [18..18] Port 1 Pin 2 Input Schmitt Trigger enable (only valid
                                                         if IO is configured as output)                                        */
           uint32_t             :  1;
      __IO uint32_t  PP4_INEN   :  1;               /*!< [20..20] Port 1 Pin 4 Input Schmitt Trigger enable (only valid
                                                         if IO is configured as output)                                        */
    } bit;                                          /*!< [21] BitSize                                                          */
  } P1_DIR;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x48028028) Port 1 Open Drain Control Register                     */
    
    struct {
      __IO uint32_t  PP0        :  1;               /*!< [0..0] Port 1 Pin 0 Open Drain Mode                                   */
      __IO uint32_t  PP1        :  1;               /*!< [1..1] Port 1 Pin 1 Open Drain Mode                                   */
      __IO uint32_t  PP2        :  1;               /*!< [2..2] Port 1 Pin 2 Open Drain Mode                                   */
           uint32_t             :  1;
      __IO uint32_t  PP4        :  1;               /*!< [4..4] Port 1 Pin 4 Open Drain Mode                                   */
    } bit;                                          /*!< [5] BitSize                                                           */
  } P1_OD;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x4802802C) Port 1 Pull-Up/Pull-Down Select Register               */
    
    struct {
      __IO uint32_t  PP0        :  1;               /*!< [0..0] Pull-Up/Pull-Down Select Port 1 Bit 0                          */
      __IO uint32_t  PP1        :  1;               /*!< [1..1] Pull-Up/Pull-Down Select Port 1 Bit 1                          */
      __IO uint32_t  PP2        :  1;               /*!< [2..2] Pull-Up/Pull-Down Select Port 1 Bit 2                          */
           uint32_t             :  1;
      __IO uint32_t  PP4        :  1;               /*!< [4..4] Pull-Up/Pull-Down Select Port 1 Bit 4                          */
    } bit;                                          /*!< [5] BitSize                                                           */
  } P1_PUDSEL;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x48028030) Port 1 Pull-Up/Pull-Down Enable Register               */
    
    struct {
      __IO uint32_t  PP0        :  1;               /*!< [0..0] Pull-Up/Pull-Down Enable at Port 1 Bit 0                       */
      __IO uint32_t  PP1        :  1;               /*!< [1..1] Pull-Up/Pull-Down Enable at Port 1 Bit 1                       */
      __IO uint32_t  PP2        :  1;               /*!< [2..2] Pull-Up/Pull-Down Enable at Port 1 Bit 2                       */
           uint32_t             :  1;
      __IO uint32_t  PP4        :  1;               /*!< [4..4] Pull-Up/Pull-Down Enable at Port 1 Bit 4                       */
    } bit;                                          /*!< [5] BitSize                                                           */
  } P1_PUDEN;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x48028034) Port 1 Alternate Select Register 0                     */
    
    struct {
      __IO uint32_t  PP0        :  1;               /*!< [0..0] See                                                            */
      __IO uint32_t  PP1        :  1;               /*!< [1..1] See                                                            */
      __IO uint32_t  PP2        :  1;               /*!< [2..2] See                                                            */
           uint32_t             :  1;
      __IO uint32_t  PP4        :  1;               /*!< [4..4] See                                                            */
    } bit;                                          /*!< [5] BitSize                                                           */
  } P1_ALTSEL0;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x48028038) Port 1 Alternate Select Register 1                     */
    
    struct {
      __IO uint32_t  PP0        :  1;               /*!< [0..0] See                                                            */
      __IO uint32_t  PP1        :  1;               /*!< [1..1] See                                                            */
      __IO uint32_t  PP2        :  1;               /*!< [2..2] See                                                            */
           uint32_t             :  1;
      __IO uint32_t  PP4        :  1;               /*!< [4..4] See                                                            */
    } bit;                                          /*!< [5] BitSize                                                           */
  } P1_ALTSEL1;
  __I  uint32_t  RESERVED1;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x48028040) Port 2 Data Register                                   */
    
    struct {
      __IO uint32_t  PP0        :  1;               /*!< [0..0] Port 2 Pin 0 Data Value                                        */
      __IO uint32_t  PP1        :  1;               /*!< [1..1] Port 2 Pin 1 Data Value                                        */
      __IO uint32_t  PP2        :  1;               /*!< [2..2] Port 2 Pin 2 Data Value                                        */
      __IO uint32_t  PP3        :  1;               /*!< [3..3] Port 2 Pin 3 Data Value                                        */
      __IO uint32_t  PP4        :  1;               /*!< [4..4] Port 2 Pin 4 Data Value                                        */
      __IO uint32_t  PP5        :  1;               /*!< [5..5] Port 2 Pin 5 Data Value                                        */
      __IO uint32_t  PP6        :  1;               /*!< [6..6] Port 2 Pin 6 Data Value                                        */
      __IO uint32_t  PP7        :  1;               /*!< [7..7] Port 2 Pin 7 Data Value                                        */
    } bit;                                          /*!< [8] BitSize                                                           */
  } P2_DATA;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x48028044) Port 2 Direction Register                              */
    
    struct {
      __IO uint32_t  PP0        :  1;               /*!< [0..0] Port 2 Pin 0 Driver Control                                    */
      __IO uint32_t  PP1        :  1;               /*!< [1..1] Port 2 Pin 1 Driver Control                                    */
      __IO uint32_t  PP2        :  1;               /*!< [2..2] Port 2 Pin 2 Driver Control                                    */
      __IO uint32_t  PP3        :  1;               /*!< [3..3] Port 2 Pin 3 Driver Control                                    */
      __IO uint32_t  PP4        :  1;               /*!< [4..4] Port 2 Pin 4 Driver Control                                    */
      __IO uint32_t  PP5        :  1;               /*!< [5..5] Port 2 Pin 5 Driver Control                                    */
      __IO uint32_t  PP6        :  1;               /*!< [6..6] Port 2 Pin 6 Driver Control                                    */
      __IO uint32_t  PP7        :  1;               /*!< [7..7] Port 2 Pin 7 Driver Control                                    */
    } bit;                                          /*!< [8] BitSize                                                           */
  } P2_DIR;
  __I  uint32_t  RESERVED2;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x4802804C) Port 2 Pull-Up/Pull-Down Select Register               */
    
    struct {
      __IO uint32_t  PP0        :  1;               /*!< [0..0] Pull-Up/Pull-Down Select Port 2 Bit 0                          */
      __IO uint32_t  PP1        :  1;               /*!< [1..1] Pull-Up/Pull-Down Select Port 2 Bit 1                          */
      __IO uint32_t  PP2        :  1;               /*!< [2..2] Pull-Up/Pull-Down Select Port 2 Bit 2                          */
      __IO uint32_t  PP3        :  1;               /*!< [3..3] Pull-Up/Pull-Down Select Port 2 Bit 3                          */
      __IO uint32_t  PP4        :  1;               /*!< [4..4] Pull-Up/Pull-Down Select Port 2 Bit 4                          */
      __IO uint32_t  PP5        :  1;               /*!< [5..5] Pull-Up/Pull-Down Select Port 2 Bit 5                          */
      __IO uint32_t  PP6        :  1;               /*!< [6..6] Pull-Up/Pull-Down Select Port 2 Bit 6                          */
      __IO uint32_t  PP7        :  1;               /*!< [7..7] Pull-Up/Pull-Down Select Port 2 Bit 7                          */
    } bit;                                          /*!< [8] BitSize                                                           */
  } P2_PUDSEL;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x48028050) Port 2 Pull-Up/Pull-Down Enable Register               */
    
    struct {
      __IO uint32_t  PP0        :  1;               /*!< [0..0] Pull-Up/Pull-Down Enable at Port 2 Bit 0                       */
      __IO uint32_t  PP1        :  1;               /*!< [1..1] Pull-Up/Pull-Down Enable at Port 2 Bit 1                       */
      __IO uint32_t  PP2        :  1;               /*!< [2..2] Pull-Up/Pull-Down Enable at Port 2 Bit 2                       */
      __IO uint32_t  PP3        :  1;               /*!< [3..3] Pull-Up/Pull-Down Enable at Port 2 Bit 3                       */
      __IO uint32_t  PP4        :  1;               /*!< [4..4] Pull-Up/Pull-Down Enable at Port 2 Bit 4                       */
      __IO uint32_t  PP5        :  1;               /*!< [5..5] Pull-Up/Pull-Down Enable at Port 2 Bit 5                       */
      __IO uint32_t  PP6        :  1;               /*!< [6..6] Pull-Up/Pull-Down Enable at Port 2 Bit 6                       */
      __IO uint32_t  PP7        :  1;               /*!< [7..7] Pull-Up/Pull-Down Enable at Port 2 Bit 7                       */
    } bit;                                          /*!< [8] BitSize                                                           */
  } P2_PUDEN;
} PORT_Type;


/* ================================================================================ */
/* ================                       SCU                      ================ */
/* ================================================================================ */


/**
  * @brief SCU (SCU)
  */

typedef struct {                                    /*!< (@ 0x50005000) SCU Structure                                          */
  
  union {
    __O  uint32_t  reg;                             /*!< (@ 0x50005000) NMI Status Clear Register                              */
    
    struct {
           uint32_t             :  1;
      __O  uint32_t  FNMIPLLC   :  1;               /*!< [1..1] PLL NMI Flag                                                   */
      __O  uint32_t  FNMINVMC   :  1;               /*!< [2..2] NVM Operation Complete NMI Flag                                */
      __O  uint32_t  FNMIOTC    :  1;               /*!< [3..3] Overtemperature NMI Flag                                       */
      __O  uint32_t  FNMIOWDC   :  1;               /*!< [4..4] Oscillator Watchdog NMI Flag                                   */
      __O  uint32_t  FNMIMAPC   :  1;               /*!< [5..5] NVM Map Error NMI Flag                                         */
      __O  uint32_t  FNMIECCC   :  1;               /*!< [6..6] ECC Error NMI Flag                                             */
      __O  uint32_t  FNMISUPC   :  1;               /*!< [7..7] Supply Prewarning NMI Flag                                     */
    } bit;                                          /*!< [8] BitSize                                                           */
  } NMISRCLR;
  
  union {
    __I  uint32_t  reg;                             /*!< (@ 0x50005004) Interrupt Request Register 0                           */
    
    struct {
      __I  uint32_t  EXINT0R    :  1;               /*!< [0..0] Interrupt Flag for External Interrupt 0x on rising edge        */
      __I  uint32_t  EXINT0F    :  1;               /*!< [1..1] Interrupt Flag for External Interrupt 0x on falling edge       */
      __I  uint32_t  EXINT1R    :  1;               /*!< [2..2] Interrupt Flag for External Interrupt 1x on rising edge        */
      __I  uint32_t  EXINT1F    :  1;               /*!< [3..3] Interrupt Flag for External Interrupt 1x on falling edge       */
      __I  uint32_t  EXINT2R    :  1;               /*!< [4..4] Interrupt Flag for External Interrupt 2x on rising edge        */
      __I  uint32_t  EXINT2F    :  1;               /*!< [5..5] Interrupt Flag for External Interrupt 2x on falling edge       */
    } bit;                                          /*!< [6] BitSize                                                           */
  } IRCON0;
  
  union {
    __I  uint32_t  reg;                             /*!< (@ 0x50005008) Interrupt Request Register 1                           */
    
    struct {
      __I  uint32_t  MON1R      :  1;               /*!< [0..0] Interrupt Flag for MON1x on rising edge                        */
      __I  uint32_t  MON1F      :  1;               /*!< [1..1] Interrupt Flag for MON1x on falling edge                       */
      __I  uint32_t  MON2R      :  1;               /*!< [2..2] Interrupt Flag for MON2x on rising edge                        */
      __I  uint32_t  MON2F      :  1;               /*!< [3..3] Interrupt Flag for MON2x on falling edge                       */
      __I  uint32_t  MON3R      :  1;               /*!< [4..4] Interrupt Flag for MON3x on rising edge                        */
      __I  uint32_t  MON3F      :  1;               /*!< [5..5] Interrupt Flag for MON3x on falling edge                       */
      __I  uint32_t  MON4R      :  1;               /*!< [6..6] Interrupt Flag for MON4x on rising edge                        */
      __I  uint32_t  MON4F      :  1;               /*!< [7..7] Interrupt Flag for MON4x on falling edge                       */
      __I  uint32_t  MON5R      :  1;               /*!< [8..8] Interrupt Flag for MON5x on rising edge                        */
      __I  uint32_t  MON5F      :  1;               /*!< [9..9] Interrupt Flag for MON5x on falling edge                       */
    } bit;                                          /*!< [10] BitSize                                                          */
  } IRCON1;
  
  union {
    __I  uint32_t  reg;                             /*!< (@ 0x5000500C) Interrupt Request Register 2                           */
    
    struct {
      __I  uint32_t  EIR1       :  1;               /*!< [0..0] Error Interrupt Flag for SSC1                                  */
      __I  uint32_t  TIR1       :  1;               /*!< [1..1] Transmit Interrupt Flag for SSC1                               */
      __I  uint32_t  RIR1       :  1;               /*!< [2..2] Receive Interrupt Flag for SSC1                                */
    } bit;                                          /*!< [3] BitSize                                                           */
  } IRCON2;
  
  union {
    __I  uint32_t  reg;                             /*!< (@ 0x50005010) Interrupt Request Register 3                           */
    
    struct {
      __I  uint32_t  EIR2       :  1;               /*!< [0..0] Error Interrupt Flag for SSC2                                  */
      __I  uint32_t  TIR2       :  1;               /*!< [1..1] Transmit Interrupt Flag for SSC2                               */
      __I  uint32_t  RIR2       :  1;               /*!< [2..2] Receive Interrupt Flag for SSC2                                */
    } bit;                                          /*!< [3] BitSize                                                           */
  } IRCON3;
  
  union {
    __I  uint32_t  reg;                             /*!< (@ 0x50005014) Interrupt Request Register 4                           */
    
    struct {
      __I  uint32_t  CCU6SR0    :  1;               /*!< [0..0] Interrupt Flag 0 for CCU6                                      */
           uint32_t             :  3;
      __I  uint32_t  CCU6SR1    :  1;               /*!< [4..4] Interrupt Flag 1 for CCU6                                      */
           uint32_t             : 11;
      __I  uint32_t  CCU6SR2    :  1;               /*!< [16..16] Interrupt Flag 2 for CCU6                                    */
           uint32_t             :  3;
      __I  uint32_t  CCU6SR3    :  1;               /*!< [20..20] Interrupt Flag 3 for CCU6                                    */
    } bit;                                          /*!< [21] BitSize                                                          */
  } IRCON4;
  
  union {
    __I  uint32_t  reg;                             /*!< (@ 0x50005018) NMI Status Register                                    */
    
    struct {
           uint32_t             :  1;
      __I  uint32_t  FNMIPLL    :  1;               /*!< [1..1] PLL NMI Flag                                                   */
      __I  uint32_t  FNMINVM    :  1;               /*!< [2..2] NVM Operation Complete NMI Flag                                */
      __I  uint32_t  FNMIOT     :  1;               /*!< [3..3] Overtemperature NMI Flag                                       */
      __I  uint32_t  FNMIOWD    :  1;               /*!< [4..4] Oscillator Watchdog NMI Flag                                   */
      __I  uint32_t  FNMIMAP    :  1;               /*!< [5..5] NVM Map Error NMI Flag                                         */
      __I  uint32_t  FNMIECC    :  1;               /*!< [6..6] ECC Error NMI Flag                                             */
      __I  uint32_t  FNMISUP    :  1;               /*!< [7..7] Supply Prewarning NMI Flag                                     */
    } bit;                                          /*!< [8] BitSize                                                           */
  } NMISR;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x5000501C) Interrupt Enable Register 0                            */
    
    struct {
           uint32_t             : 31;
      __IO uint32_t  EA         :  1;               /*!< [31..31] Global Interrupt Mask                                        */
    } bit;                                          /*!< [32] BitSize                                                          */
  } IEN0;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x50005020) Vector Table Reallocation Register                     */
    
    struct {
      __IO uint32_t  VTOR_BYP   :  2;               /*!< [0..1] Vector Table Bypass Mode                                       */
    } bit;                                          /*!< [2] BitSize                                                           */
  } VTOR;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x50005024) NMI Control Register                                   */
    
    struct {
           uint32_t             :  1;
      __IO uint32_t  NMIPLL     :  1;               /*!< [1..1] PLL Loss of Lock NMI Enable                                    */
      __IO uint32_t  NMINVM     :  1;               /*!< [2..2] NVM Operation Complete NMI Enable                              */
      __IO uint32_t  NMIOT      :  1;               /*!< [3..3] NMI OT Enable                                                  */
      __IO uint32_t  NMIOWD     :  1;               /*!< [4..4] Oscillator Watchdog NMI Enable                                 */
      __IO uint32_t  NMIMAP     :  1;               /*!< [5..5] NVM Map Error NMI Enable                                       */
      __IO uint32_t  NMIECC     :  1;               /*!< [6..6] ECC Error NMI Enable                                           */
      __IO uint32_t  NMISUP     :  1;               /*!< [7..7] Supply Prewarning NMI Enable                                   */
    } bit;                                          /*!< [8] BitSize                                                           */
  } NMICON;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x50005028) External Interrupt Control Register 0                  */
    
    struct {
      __IO uint32_t  EXINT0     :  2;               /*!< [0..1] External Interrupt 0 Trigger Select                            */
      __IO uint32_t  EXINT1     :  2;               /*!< [2..3] External Interrupt 1 Trigger Select                            */
      __IO uint32_t  EXINT2     :  2;               /*!< [4..5] External Interrupt 2 Trigger Select                            */
    } bit;                                          /*!< [6] BitSize                                                           */
  } EXICON0;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x5000502C) External Interrupt Control Register 1                  */
    
    struct {
      __IO uint32_t  MON1       :  2;               /*!< [0..1] MON1 Input Trigger Select                                      */
      __IO uint32_t  MON2       :  2;               /*!< [2..3] MON2 Input Trigger Select                                      */
      __IO uint32_t  MON3       :  2;               /*!< [4..5] MON3 Input Trigger Select                                      */
      __IO uint32_t  MON4       :  2;               /*!< [6..7] MON4 Input Trigger Select                                      */
      __IO uint32_t  MON5       :  2;               /*!< [8..9] MON5 Input Trigger Select                                      */
    } bit;                                          /*!< [10] BitSize                                                          */
  } EXICON1;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x50005030) Peripheral Interrupt Enable Register 1                 */
    
    struct {
      __IO uint32_t  EIREN1     :  1;               /*!< [0..0] SSC 1 Error Interrupt Enable                                   */
      __IO uint32_t  TIREN1     :  1;               /*!< [1..1] SSC 1 Transmit Interrupt Enable                                */
      __IO uint32_t  RIREN1     :  1;               /*!< [2..2] SSC 1 Receive Interrupt Enable                                 */
           uint32_t             :  5;
      __IO uint32_t  EIREN2     :  1;               /*!< [8..8] SSC 2 Error Interrupt Enable                                   */
      __IO uint32_t  TIREN2     :  1;               /*!< [9..9] SSC 2 Transmit Interrupt Enable                                */
      __IO uint32_t  RIREN2     :  1;               /*!< [10..10] SSC 2 Receive Interrupt Enable                               */
    } bit;                                          /*!< [11] BitSize                                                          */
  } MODIEN1;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x50005034) Peripheral Interrupt Enable Register 2                 */
    
    struct {
      __IO uint32_t  RIEN1      :  1;               /*!< [0..0] UART 1 Receive Interrupt Enable                                */
      __IO uint32_t  TIEN1      :  1;               /*!< [1..1] UART 1 Transmit Interrupt Enable                               */
           uint32_t             :  3;
      __IO uint32_t  EXINT2_EN  :  1;               /*!< [5..5] External Interrupt 2 Enable                                    */
      __IO uint32_t  RIEN2      :  1;               /*!< [6..6] UART 2 Receive Interrupt Enable                                */
      __IO uint32_t  TIEN2      :  1;               /*!< [7..7] UART 2 Transmit Interrupt Enable                               */
    } bit;                                          /*!< [8] BitSize                                                           */
  } MODIEN2;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x50005038) Peripheral Interrupt Enable Register 3                 */
    
    struct {
      __IO uint32_t  IE0        :  1;               /*!< [0..0] External Interrupt Enable                                      */
    } bit;                                          /*!< [1] BitSize                                                           */
  } MODIEN3;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x5000503C) Peripheral Interrupt Enable Register 4                 */
    
    struct {
      __IO uint32_t  IE1        :  1;               /*!< [0..0] External Interrupt Enable                                      */
    } bit;                                          /*!< [1] BitSize                                                           */
  } MODIEN4;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x50005040) Power Mode Control Register 0                          */
    
    struct {
      __IO uint32_t  XTAL_ON    :  1;               /*!< [0..0] OSC_HP Operation in Power Down Mode                            */
      __IO uint32_t  SL         :  1;               /*!< [1..1] Sleep Mode Enable. Active High.                                */
      __IO uint32_t  PD         :  1;               /*!< [2..2] Power Down Mode (Stop mode) Enable. Active High.               */
      __IO uint32_t  SD         :  1;               /*!< [3..3] Slow Down Mode Enable. Active High.                            */
    } bit;                                          /*!< [4] BitSize                                                           */
  } PMCON0;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x50005044) PLL Control Register                                   */
    
    struct {
      __I  uint32_t  LOCK       :  1;               /*!< [0..0] PLL Lock Status Flag                                           */
      __IO uint32_t  RESLD      :  1;               /*!< [1..1] Restart Lock Detection                                         */
      __IO uint32_t  OSCDISC    :  1;               /*!< [2..2] Oscillator Disconnect                                          */
      __IO uint32_t  VCOBYP     :  1;               /*!< [3..3] PLL VCO Bypass Mode Select                                     */
      __IO uint32_t  NDIV       :  4;               /*!< [4..7] PLL N-Divider                                                  */
           uint32_t             :  2;
      __O  uint32_t  UNPROT_OSCDISC:  1;            /*!< [10..10] Unprotect write access of OSC_DISC                           */
      __O  uint32_t  UNPROT_VCOBYP:  1;             /*!< [11..11] Unprotect write access of VCO_BYP                            */
    } bit;                                          /*!< [12] BitSize                                                          */
  } PLL_CON;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x50005048) Clock Control Register 1                               */
    
    struct {
      __IO uint32_t  CLKREL     :  4;               /*!< [0..3] Slow Down Clock Divider for fCCLK Generation                   */
      __IO uint32_t  K2DIV      :  2;               /*!< [4..5] PLL K2-Divider                                                 */
      __IO uint32_t  K1DIV      :  1;               /*!< [6..6] PLL K1-Divider                                                 */
           uint32_t             :  1;
      __IO uint32_t  PDIV       :  2;               /*!< [8..9] PLL PDIV-Divider                                               */
    } bit;                                          /*!< [10] BitSize                                                          */
  } CMCON1;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x5000504C) Clock Control Register 2                               */
    
    struct {
      __IO uint32_t  PBA0CLKREL :  1;               /*!< [0..0] PBA0 Clock Divider                                             */
    } bit;                                          /*!< [1] BitSize                                                           */
  } CMCON2;
  __I  uint32_t  RESERVED;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x50005054) Analog Peripheral Clock Control Register               */
    
    struct {
      __IO uint32_t  APCLK_SET  :  1;               /*!< [0..0] Set and Overtake Flag for Clock Settings                       */
           uint32_t             :  7;
      __IO uint32_t  CLKWDT_IE  :  1;               /*!< [8..8] Clock Watchdog Interrupt Enable                                */
    } bit;                                          /*!< [9] BitSize                                                           */
  } APCLK_CTRL;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x50005058) Analog Peripheral Clock Register                       */
    
    struct {
      __IO uint32_t  APCLK1FAC  :  2;               /*!< [0..1] Analog Module Clock Factor                                     */
           uint32_t             :  6;
      __IO uint32_t  APCLK2FAC  :  5;               /*!< [8..12] Slow Down Clock Divider for TFILT_CLK Generation              */
           uint32_t             : 11;
      __IO uint32_t  BGCLK_SEL  :  1;               /*!< [24..24] Bandgap Clock Selection                                      */
      __IO uint32_t  BGCLK_DIV  :  1;               /*!< [25..25] Bandgap Clock Divider                                        */
    } bit;                                          /*!< [26] BitSize                                                          */
  } APCLK;
  
  union {
    __I  uint32_t  reg;                             /*!< (@ 0x5000505C) Analog Peripheral Clock Status Register                */
    
    struct {
      __I  uint32_t  APCLK1STS  :  2;               /*!< [0..1] Analog Peripherals Clock Status                                */
           uint32_t             :  6;
      __I  uint32_t  APCLK2STS  :  2;               /*!< [8..9] Analog Peripherals Clock Status                                */
           uint32_t             :  6;
      __I  uint32_t  APCLK3STS  :  1;               /*!< [16..16] Loss of Clock Status                                         */
           uint32_t             :  7;
      __I  uint32_t  PLL_LOCK   :  1;               /*!< [24..24] PLL LOCK Status                                              */
    } bit;                                          /*!< [25] BitSize                                                          */
  } APCLK_STS;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x50005060) Peripheral Management Control Register                 */
    
    struct {
      __IO uint32_t  ADC1_DIS   :  1;               /*!< [0..0] ADC1 Disable Request. Active high.                             */
      __IO uint32_t  SSC1_DIS   :  1;               /*!< [1..1] SSC1 Disable Request. Active high.                             */
      __IO uint32_t  CCU_DIS    :  1;               /*!< [2..2] CCU Disable Request. Active high.                              */
      __IO uint32_t  T2_DIS     :  1;               /*!< [3..3] T2 Disable Request. Active high.                               */
      __IO uint32_t  GPT12_DIS  :  1;               /*!< [4..4] General Purpose Timer 12 Disable Request. Active high.         */
           uint32_t             :  3;
      __IO uint32_t  SSC2_DIS   :  1;               /*!< [8..8] SSC2 Disable Request. Active high.                             */
           uint32_t             :  1;
      __IO uint32_t  T21_DIS    :  1;               /*!< [10..10] T21 Disable Request. Active high.                            */
    } bit;                                          /*!< [11] BitSize                                                          */
  } PMCON;
  
  union {
    __O  uint32_t  reg;                             /*!< (@ 0x50005064) Analog Peripheral Clock Status Clear Register          */
    
    struct {
      __O  uint32_t  APCLK1SCLR :  1;               /*!< [0..0] Analog Peripherals Clock Status Clear                          */
           uint32_t             :  7;
      __O  uint32_t  APCLK2SCLR :  1;               /*!< [8..8] Analog Peripherals Clock Status Clear                          */
           uint32_t             :  7;
      __O  uint32_t  APCLK3SCLR :  1;               /*!< [16..16] Analog Peripherals Clock 3 Status Clear                      */
           uint32_t             :  7;
      __O  uint32_t  PLL_LOCK_SCLR:  1;             /*!< [24..24] PLL Lock Status Clear                                        */
    } bit;                                          /*!< [25] BitSize                                                          */
  } APCLK_SCLR;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x50005068) Reset Control Register                                 */
    
    struct {
      __IO uint32_t  LOCKUP     :  1;               /*!< [0..0] Lockup Flag                                                    */
           uint32_t             :  6;
      __IO uint32_t  LOCKUP_EN  :  1;               /*!< [7..7] Lockup Reset Enable Flag                                       */
    } bit;                                          /*!< [8] BitSize                                                           */
  } RSTCON;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x5000506C) ADC1 Peripheral Clock Register                         */
    
    struct {
      __IO uint32_t  ADC1_CLK_DIV:  4;              /*!< [0..3] ADC1 Clock divider                                             */
           uint32_t             :  4;
      __IO uint32_t  DPP1_CLK_DIV:  2;              /*!< [8..9] ADC1 Post processing clock divider                             */
    } bit;                                          /*!< [10] BitSize                                                          */
  } ADC1_CLK;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x50005070) System Control Register 0                              */
    
    struct {
           uint32_t             :  4;
      __I  uint32_t  NVMCLKFAC  :  2;               /*!< [4..5] NVM Access Clock Factor                                        */
      __IO uint32_t  SYSCLKSEL  :  2;               /*!< [6..7] System Clock Select                                            */
    } bit;                                          /*!< [8] BitSize                                                           */
  } SYSCON0;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x50005074) System Startup Status Register                         */
    
    struct {
      __IO uint32_t  INIT_FAIL  :  1;               /*!< [0..0] Initialization at startup failed                               */
      __IO uint32_t  MRAMINITSTS:  1;               /*!< [1..1] Map RAM Initialisation Status                                  */
      __IO uint32_t  PG100TP_CHKS_ERR:  1;          /*!< [2..2] 100 TP Page Checksum Error                                     */
    } bit;                                          /*!< [3] BitSize                                                           */
  } SYS_STRTUP_STS;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x50005078) Wakeup Interrupt Control Register                      */
    
    struct {
      __IO uint32_t  WAKEUPEN   :  1;               /*!< [0..0] Wakeup Interrupt Enable                                        */
    } bit;                                          /*!< [1] BitSize                                                           */
  } WAKECON;
  
  union {
    __I  uint32_t  reg;                             /*!< (@ 0x5000507C) Interrupt Request Register 5                           */
    
    struct {
      __I  uint32_t  WAKEUP     :  1;               /*!< [0..0] Interrupt Flag for Wakeup                                      */
    } bit;                                          /*!< [1] BitSize                                                           */
  } IRCON5;
  __I  uint32_t  RESERVED1[2];
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x50005088) Baud Rate Control Register 1                           */
    
    struct {
      __IO uint32_t  BR1_R      :  1;               /*!< [0..0] Baud Rate Generator Run Control Bit                            */
      __IO uint32_t  BR1_PRE    :  3;               /*!< [1..3] Prescaler Bit                                                  */
    } bit;                                          /*!< [4] BitSize                                                           */
  } BCON1;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x5000508C) Baud Rate Timer/Reload Register, Low Byte 1            */
    
    struct {
      __IO uint32_t  BG1_FD_SEL :  5;               /*!< [0..4] Fractional Divider Selection                                   */
    } bit;                                          /*!< [5] BitSize                                                           */
  } BGL1;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x50005090) Baud Rate Timer/Reload Register                        */
    
    struct {
      __IO uint32_t  BG1_BR_VALUE: 11;              /*!< [0..10] Baud Rate Timer/Reload Value UART1                            */
    } bit;                                          /*!< [11] BitSize                                                          */
  } BG1;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x50005094) LIN Status Register                                    */
    
    struct {
      __IO uint32_t  BRDIS      :  1;               /*!< [0..0] Baud Rate Detection Disable                                    */
      __IO uint32_t  BGSEL      :  2;               /*!< [1..2] Baud Rate Select for Detection                                 */
      __I  uint32_t  BRK        :  1;               /*!< [3..3] Break Field Flag                                               */
      __I  uint32_t  EOFSYN     :  1;               /*!< [4..4] End of SYN Byte Interrupt Flag                                 */
      __I  uint32_t  ERRSYN     :  1;               /*!< [5..5] SYN Byte Error Interrupt Flag                                  */
      __IO uint32_t  SYNEN      :  1;               /*!< [6..6] End of SYN Byte and SYN Byte Error Interrupts Enable           */
    } bit;                                          /*!< [7] BitSize                                                           */
  } LINST;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x50005098) Baud Rate Control Register 2                           */
    
    struct {
      __IO uint32_t  BR2_R      :  1;               /*!< [0..0] Baud Rate Generator Run Control Bit                            */
      __IO uint32_t  BR2_PRE    :  3;               /*!< [1..3] Prescaler Bit                                                  */
    } bit;                                          /*!< [4] BitSize                                                           */
  } BCON2;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x5000509C) Baud Rate Timer/Reload Register, Low Byte 2            */
    
    struct {
      __IO uint32_t  BG2_FD_SEL :  5;               /*!< [0..4] Fractional Divider Selection                                   */
    } bit;                                          /*!< [5] BitSize                                                           */
  } BGL2;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x500050A0) Baud Rate Timer/Reload Register                        */
    
    struct {
      __IO uint32_t  BG2_BR_VALUE: 11;              /*!< [0..10] Baud Rate Timer/Reload Value UART2                            */
    } bit;                                          /*!< [11] BitSize                                                          */
  } BG2;
  
  union {
    __O  uint32_t  reg;                             /*!< (@ 0x500050A4) LIN Status Clear Register                              */
    
    struct {
           uint32_t             :  3;
      __O  uint32_t  BRKC       :  1;               /*!< [3..3] Break Field Flag Clear                                         */
      __O  uint32_t  EOFSYNC    :  1;               /*!< [4..4] End of SYN Byte Interrupt Flag Clear                           */
      __O  uint32_t  ERRSYNC    :  1;               /*!< [5..5] SYN Byte Error Interrupt Flag                                  */
    } bit;                                          /*!< [6] BitSize                                                           */
  } LINSCLR;
  
  union {
    __I  uint32_t  reg;                             /*!< (@ 0x500050A8) Identity Register                                      */
    
    struct {
      __I  uint32_t  VERID      :  3;               /*!< [0..2] Version ID                                                     */
      __I  uint32_t  PRODID     :  5;               /*!< [3..7] Product ID                                                     */
    } bit;                                          /*!< [8] BitSize                                                           */
  } ID;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x500050AC) Password Register                                      */
    
    struct {
      __IO uint32_t  PW_MODE    :  2;               /*!< [0..1] Bit-Protection Scheme Control Bit                              */
      __I  uint32_t  PROTECT_S  :  1;               /*!< [2..2] Bit-Protection Signal Status Bit                               */
      __IO uint32_t  PASS       :  5;               /*!< [3..7] Password Bits                                                  */
    } bit;                                          /*!< [8] BitSize                                                           */
  } PASSWD;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x500050B0) OSC Control Register                                   */
    
    struct {
      __IO uint32_t  OSCSS      :  2;               /*!< [0..1] Oscillator Source Select                                       */
      __IO uint32_t  OSCWDTRST  :  1;               /*!< [2..2] Oscillator Watchdog Reset                                      */
      __I  uint32_t  OSC2L      :  1;               /*!< [3..3] OSC-Too-Low Condition Flag                                     */
      __IO uint32_t  XPD        :  1;               /*!< [4..4] XTAL (OSC_HP) Power Down Control                               */
    } bit;                                          /*!< [5] BitSize                                                           */
  } OSC_CON;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x500050B4) Clock Output Control Register                          */
    
    struct {
      __IO uint32_t  COREL      :  4;               /*!< [0..3] Clock Output Divider                                           */
      __IO uint32_t  COUTS0     :  1;               /*!< [4..4] Clock Out Source Select Bit 0                                  */
      __IO uint32_t  TLEN       :  1;               /*!< [5..5] Toggle Latch Enable                                            */
      __IO uint32_t  COUTS1     :  1;               /*!< [6..6] Clock Out Source Select Bit 1                                  */
      __IO uint32_t  EN         :  1;               /*!< [7..7] CLKOUT Enable                                                  */
    } bit;                                          /*!< [8] BitSize                                                           */
  } COCON;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x500050B8) Peripheral Input Select Register                       */
    
    struct {
      __IO uint32_t  EXINT0IS   :  2;               /*!< [0..1] External Interrupt 0 Input Select                              */
      __IO uint32_t  EXINT1IS   :  2;               /*!< [2..3] External Interrupt 1 Input Select                              */
      __IO uint32_t  EXINT2IS   :  2;               /*!< [4..5] External Interrupt 2 Input Select                              */
      __IO uint32_t  URIOS1     :  1;               /*!< [6..6] UART1 Input/Output Select                                      */
      __IO uint32_t  U_TX_CONDIS:  1;               /*!< [7..7] UART1 TxD Connection Disable                                   */
           uint32_t             :  8;
      __IO uint32_t  SSC12_M_SCK_OUTSEL:  1;        /*!< [16..16] Output selection for SSC12_M_SCK                             */
      __IO uint32_t  SSC12_M_MTSR_OUTSEL:  1;       /*!< [17..17] Output selection for SSC12_M_MTSR                            */
      __IO uint32_t  SSC12_S_MRST_OUTSEL:  1;       /*!< [18..18] Output selection for SSC12_S_MRST                            */
    } bit;                                          /*!< [19] BitSize                                                          */
  } MODPISEL;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x500050BC) Peripheral Input Select Register 1                     */
    
    struct {
      __IO uint32_t  XTAL12EN   :  1;               /*!< [0..0] Pins XTAL1/2 Enable Bit                                        */
           uint32_t             :  5;
      __IO uint32_t  T2EXCON    :  1;               /*!< [6..6] Timer 2 External Input Control                                 */
      __IO uint32_t  T21EXCON   :  1;               /*!< [7..7] Timer 21 External Input Control                                */
    } bit;                                          /*!< [8] BitSize                                                           */
  } MODPISEL1;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x500050C0) Peripheral Input Select Register 2                     */
    
    struct {
      __IO uint32_t  T2IS       :  2;               /*!< [0..1] Timer 2 Input Select                                           */
      __IO uint32_t  T21IS      :  2;               /*!< [2..3] Timer 21 Input Select                                          */
      __IO uint32_t  T2EXIS     :  2;               /*!< [4..5] Timer 2 External Input Select                                  */
      __IO uint32_t  T21EXIS    :  2;               /*!< [6..7] Timer 21 External Input Select                                 */
    } bit;                                          /*!< [8] BitSize                                                           */
  } MODPISEL2;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x500050C4) Peripheral Input Select Register 3                     */
    
    struct {
           uint32_t             :  6;
      __IO uint32_t  URIOS2     :  1;               /*!< [6..6] UART2 Input/Output Select                                      */
    } bit;                                          /*!< [7] BitSize                                                           */
  } MODPISEL3;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x500050C8) Module Suspend Control Register                        */
    
    struct {
           uint32_t             :  1;
      __IO uint32_t  T12SUSP    :  1;               /*!< [1..1] Timer 12 Debug Suspend Bit                                     */
      __IO uint32_t  T13SUSP    :  1;               /*!< [2..2] Timer 13 Debug Suspend Bit                                     */
      __IO uint32_t  T2_SUSP    :  1;               /*!< [3..3] Timer2 Debug Suspend Bit                                       */
      __IO uint32_t  GPT12_SUSP :  1;               /*!< [4..4] GPT12 Debug Suspend Bit                                        */
           uint32_t             :  1;
      __IO uint32_t  T21_SUSP   :  1;               /*!< [6..6] Timer21 Debug Suspend Bit                                      */
      __IO uint32_t  WDT1SUSP   :  1;               /*!< [7..7] Watchdog Timer 1 Debug Suspend Bit                             */
           uint32_t             :  1;
      __IO uint32_t  MU_SUSP    :  1;               /*!< [9..9] Measurement Unit Debug Suspend Bit                             */
      __IO uint32_t  ADC1_SUSP  :  1;               /*!< [10..10] ADC1 Unit Debug Suspend Bit                                  */
    } bit;                                          /*!< [11] BitSize                                                          */
  } MODSUSP;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x500050CC) Emergency and Program Operation Status Register        */
    
    struct {
      __IO uint32_t  NVMPROP    :  1;               /*!< [0..0] NVM Program Operation Status Bit                               */
      __IO uint32_t  EMPROP     :  1;               /*!< [1..1] Emergency Program Operation Status Bit                         */
    } bit;                                          /*!< [2] BitSize                                                           */
  } EMOP;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x500050D0) GPT12 Peripheral Input Select Register                 */
    
    struct {
      __IO uint32_t  GPT12      :  4;               /*!< [0..3] GPT12 TIN3B / TIN4D Input Select                               */
      __IO uint32_t  TRIG_CONF  :  1;               /*!< [4..4] CCU6 Trigger Configuration.                                    */
      __IO uint32_t  GPT12_SEL  :  1;               /*!< [5..5] CCU6 Trigger Configuration.                                    */
    } bit;                                          /*!< [6] BitSize                                                           */
  } GPT12PISEL;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x500050D4) Error Detection and Correction Control Register        */
    
    struct {
      __IO uint32_t  RIE        :  1;               /*!< [0..0] RAM Double Bit ECC Error Interrupt Enable                      */
           uint32_t             :  1;
      __IO uint32_t  NVMIE      :  1;               /*!< [2..2] NVM Double Bit ECC Error Interrupt Enable                      */
    } bit;                                          /*!< [3] BitSize                                                           */
  } EDCCON;
  
  union {
    __I  uint32_t  reg;                             /*!< (@ 0x500050D8) Error Detection and Correction Status Register         */
    
    struct {
      __I  uint32_t  RDBE       :  1;               /*!< [0..0] RAM Double Bit Error                                           */
           uint32_t             :  1;
      __I  uint32_t  NVMDBE     :  1;               /*!< [2..2] NVM Double Bit Error                                           */
           uint32_t             :  1;
      __I  uint32_t  RSBE       :  1;               /*!< [4..4] RAM Single Bit Error                                           */
    } bit;                                          /*!< [5] BitSize                                                           */
  } EDCSTAT;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x500050DC) Memory Status Register                                 */
    
    struct {
      __IO uint32_t  SECTORINFO :  6;               /*!< [0..5] Sector Information                                             */
      __IO uint32_t  SASTATUS   :  2;               /*!< [6..7] Service Algorithm Status                                       */
    } bit;                                          /*!< [8] BitSize                                                           */
  } MEMSTAT;
  
  union {
    __I  uint32_t  reg;                             /*!< (@ 0x500050E0) NVM Protection Status Register                         */
    
    struct {
      __I  uint32_t  EN_PRG_NL  :  1;               /*!< [0..0] NVM Protection of Data in Non-Linear Sectors                   */
      __I  uint32_t  EN_PRG_LIN :  1;               /*!< [1..1] NVM Protection of Data in Linear Sectors                       */
      __I  uint32_t  EN_PRG_CBSL:  1;               /*!< [2..2] NVM Protection of Data in CBSL Region                          */
      __I  uint32_t  EN_RD_NL   :  1;               /*!< [3..3] NVM Read Protection of Data in Non-Linear Sectors              */
      __I  uint32_t  EN_RD_LIN  :  1;               /*!< [4..4] NVM Read Protection of Data in Linear Sectors                  */
      __I  uint32_t  EN_RD_CBSL :  1;               /*!< [5..5] NVM Read Protection of Data in CBSL Region                     */
           uint32_t             :  2;
      __I  uint32_t  EN_RD_S0   :  1;               /*!< [8..8] NVM Read Protection for Sector 0                               */
      __I  uint32_t  DIS_RDUS   :  1;               /*!< [9..9] Configuration of NVM Read Protection for Sector 1...n
                                                         with EN_RD_* = 0                                                      */
      __I  uint32_t  DIS_RDUS_S0:  1;               /*!< [10..10] Configuration of NVM Read Protection for Sector 0 with
                                                         EN_RD_S0 = 0                                                          */
      __I  uint32_t  NL_PW      :  1;               /*!< [11..11] Status of Non-Linear Region Password / Protection            */
      __I  uint32_t  LIN_PW     :  1;               /*!< [12..12] Status of Linear Region Password / Protection                */
      __I  uint32_t  CBSL_PW    :  1;               /*!< [13..13] Status of CBSL Region Password / Protection                  */
      __I  uint32_t  NVMBSL     :  2;               /*!< [14..15] CBSL Region Size Definition                                  */
    } bit;                                          /*!< [16] BitSize                                                          */
  } NVM_PROT_STS;
  
  union {
    __I  uint32_t  reg;                             /*!< (@ 0x500050E4) Memory Access Status Register                          */
    
    struct {
      __I  uint32_t  NVM_PROT_ERR:  1;              /*!< [0..0] NVM Access Protection                                          */
      __I  uint32_t  NVM_ADDR_ERR:  1;              /*!< [1..1] NVM Address Protection                                         */
      __I  uint32_t  NVM_SFR_PROT_ERR:  1;          /*!< [2..2] NVM SFR Access Protection                                      */
      __I  uint32_t  NVM_SFR_ADDR_ERR:  1;          /*!< [3..3] NVM SFR Address Protection                                     */
      __I  uint32_t  ROM_PROT_ERR:  1;              /*!< [4..4] ROM Access Protection                                          */
    } bit;                                          /*!< [5] BitSize                                                           */
  } MEM_ACC_STS;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x500050E8) Port Output Control Register                           */
    
    struct {
      __IO uint32_t  P0_PDM0    :  3;               /*!< [0..2] P0.0 Port Driver Mode                                          */
           uint32_t             :  1;
      __IO uint32_t  P0_PDM1    :  3;               /*!< [4..6] P0.1 Port Driver Mode                                          */
           uint32_t             :  1;
      __IO uint32_t  P0_PDM2    :  3;               /*!< [8..10] P0.2 Port Driver Mode                                         */
           uint32_t             :  1;
      __IO uint32_t  P0_PDM3    :  3;               /*!< [12..14] P0.3 Port Driver Mode                                        */
           uint32_t             :  1;
      __IO uint32_t  P0_PDM4    :  3;               /*!< [16..18] P0.4 Port Driver Mode                                        */
           uint32_t             :  1;
      __IO uint32_t  P0_PDM5    :  3;               /*!< [20..22] P0.5 Port Driver Mode                                        */
    } bit;                                          /*!< [23] BitSize                                                          */
  } P0_POCON0;
  __I  uint32_t  RESERVED2[2];
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x500050F4) Temperature Compensation Control Register              */
    
    struct {
      __IO uint32_t  TCC        :  2;               /*!< [0..1] Temperature Compensation Control                               */
    } bit;                                          /*!< [2] BitSize                                                           */
  } TCCR;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x500050F8) Port Output Control Register                           */
    
    struct {
      __IO uint32_t  P1_PDM0    :  3;               /*!< [0..2] P1.0 Port Driver Mode                                          */
           uint32_t             :  1;
      __IO uint32_t  P1_PDM1    :  3;               /*!< [4..6] P1.1 Port Driver Mode                                          */
           uint32_t             :  1;
      __IO uint32_t  P1_PDM2    :  3;               /*!< [8..10] P1.2 Port Driver Mode                                         */
           uint32_t             :  5;
      __IO uint32_t  P1_PDM4    :  3;               /*!< [16..18] P1.4 Port Driver Mode                                        */
    } bit;                                          /*!< [19] BitSize                                                          */
  } P1_POCON0;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x500050FC) Peripheral Input Select Register 4                     */
    
    struct {
      __IO uint32_t  DU1TRIGGEN :  3;               /*!< [0..2] Differential Unit Trigger Enable                               */
           uint32_t             :  5;
      __IO uint32_t  DU2TRIGGEN :  3;               /*!< [8..10] Differential Unit Trigger Enable                              */
           uint32_t             :  5;
      __IO uint32_t  DU3TRIGGEN :  3;               /*!< [16..18] Differential Unit Trigger Enable                             */
           uint32_t             :  5;
      __IO uint32_t  DU4TRIGGEN :  3;               /*!< [24..26] Differential Unit Trigger Enable                             */
    } bit;                                          /*!< [27] BitSize                                                          */
  } MODPISEL4;
  __I  uint32_t  RESERVED3[3];
  
  union {
    __O  uint32_t  reg;                             /*!< (@ 0x5000510C) Error Detection and Correction Status Clear Register   */
    
    struct {
      __O  uint32_t  RDBEC      :  1;               /*!< [0..0] RAM Double Bit Error Clear                                     */
           uint32_t             :  1;
      __O  uint32_t  NVMDBEC    :  1;               /*!< [2..2] NVM Double Bit Error Clear                                     */
           uint32_t             :  1;
      __O  uint32_t  RSBEC      :  1;               /*!< [4..4] RAM Single Bit Error Clear                                     */
    } bit;                                          /*!< [5] BitSize                                                           */
  } EDCSCLR;
  __I  uint32_t  RESERVED4[19];
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x5000515C) General Purpose Timer 12 Interrupt Enable Register     */
    
    struct {
      __IO uint32_t  T2IE       :  1;               /*!< [0..0] GPT12 T2 Interrupt Enable                                      */
      __IO uint32_t  T3IE       :  1;               /*!< [1..1] GPT12 T3 Interrupt Enable                                      */
      __IO uint32_t  T4IE       :  1;               /*!< [2..2] GPT12 T4 Interrupt Enable                                      */
      __IO uint32_t  T5IE       :  1;               /*!< [3..3] GPT12 T5 Interrupt Enable                                      */
      __IO uint32_t  T6IE       :  1;               /*!< [4..4] GPT12 T6 Interrupt Enable                                      */
      __IO uint32_t  CRIE       :  1;               /*!< [5..5] GPT12 Capture and Reload Interrupt Enable                      */
    } bit;                                          /*!< [6] BitSize                                                           */
  } GPT12IEN;
  
  union {
    __I  uint32_t  reg;                             /*!< (@ 0x50005160) Timer and Counter Control/Status Register              */
    
    struct {
      __I  uint32_t  GPT1T2     :  1;               /*!< [0..0] GPT Module 1 Timer 2 Interrupt Status                          */
      __I  uint32_t  GPT1T3     :  1;               /*!< [1..1] GPT Module 1 Timer3 Interrupt Status                           */
      __I  uint32_t  GPT1T4     :  1;               /*!< [2..2] GPT Module 1 Timer4 Interrupt Status                           */
      __I  uint32_t  GPT2T5     :  1;               /*!< [3..3] GPT Module 2 Timer5 Interrupt Status                           */
      __I  uint32_t  GPT2T6     :  1;               /*!< [4..4] GPT Module 2Timer6 Interrupt Status                            */
      __I  uint32_t  GPT12CR    :  1;               /*!< [5..5] GPT 12 Capture Reload Interrupt Status                         */
    } bit;                                          /*!< [6] BitSize                                                           */
  } GPT12IRC;
  __I  uint32_t  RESERVED5[5];
  
  union {
    __O  uint32_t  reg;                             /*!< (@ 0x50005178) Interrupt Request 0 Clear Register                     */
    
    struct {
      __O  uint32_t  EXINT0RC   :  1;               /*!< [0..0] Interrupt Flag for External Interrupt 0x on rising edge        */
      __O  uint32_t  EXINT0FC   :  1;               /*!< [1..1] Interrupt Flag for External Interrupt 0x on falling edge       */
      __O  uint32_t  EXINT1RC   :  1;               /*!< [2..2] Interrupt Flag for External Interrupt 1x on rising edge        */
      __O  uint32_t  EXINT1FC   :  1;               /*!< [3..3] Interrupt Flag for External Interrupt 1x on falling edge       */
      __O  uint32_t  EXINT2RC   :  1;               /*!< [4..4] Interrupt Flag for External Interrupt 2x on rising edge        */
      __O  uint32_t  EXINT2FC   :  1;               /*!< [5..5] Interrupt Flag for External Interrupt 2x on falling edge       */
    } bit;                                          /*!< [6] BitSize                                                           */
  } IRCON0CLR;
  
  union {
    __O  uint32_t  reg;                             /*!< (@ 0x5000517C) Interrupt Request 1 Clear Register                     */
    
    struct {
      __O  uint32_t  MON1RC     :  1;               /*!< [0..0] Interrupt Flag for MON1x on rising edge                        */
      __O  uint32_t  MON1FC     :  1;               /*!< [1..1] Interrupt Flag for MON1x on falling edge                       */
      __O  uint32_t  MON2RC     :  1;               /*!< [2..2] Interrupt Flag for MON2x on rising edge                        */
      __O  uint32_t  MON2FC     :  1;               /*!< [3..3] Interrupt Flag for MON2x on falling edge                       */
      __O  uint32_t  MON3RC     :  1;               /*!< [4..4] Interrupt Flag for MON3x on rising edge                        */
      __O  uint32_t  MON3FC     :  1;               /*!< [5..5] Interrupt Flag for MON3x on falling edge                       */
      __O  uint32_t  MON4RC     :  1;               /*!< [6..6] Interrupt Flag for MON4x on rising edge                        */
      __O  uint32_t  MON4FC     :  1;               /*!< [7..7] Interrupt Flag for MON4x on falling edge                       */
      __O  uint32_t  MON5RC     :  1;               /*!< [8..8] Interrupt Flag for MON5x on rising edge                        */
      __O  uint32_t  MON5FC     :  1;               /*!< [9..9] Interrupt Flag for MON5x on falling edge                       */
    } bit;                                          /*!< [10] BitSize                                                          */
  } IRCON1CLR;
  
  union {
    __O  uint32_t  reg;                             /*!< (@ 0x50005180) Timer and Counter Control/Status Clear Register        */
    
    struct {
      __O  uint32_t  GPT1T2C    :  1;               /*!< [0..0] GPT Module 1 Timer 2 Interrupt Status                          */
      __O  uint32_t  GPT1T3C    :  1;               /*!< [1..1] GPT Module 1 Timer3 Interrupt Status                           */
      __O  uint32_t  GPT1T4C    :  1;               /*!< [2..2] GPT Module 1 Timer4 Interrupt Status                           */
      __O  uint32_t  GPT2T5C    :  1;               /*!< [3..3] GPT Module 2 Timer5 Interrupt Status                           */
      __O  uint32_t  GPT2T6C    :  1;               /*!< [4..4] GPT Module 2 Timer6 Interrupt Status                           */
      __O  uint32_t  GPT12CRC   :  1;               /*!< [5..5] GPT Module 1 Capture Reload Interrupt Status                   */
    } bit;                                          /*!< [6] BitSize                                                           */
  } GPT12ICLR;
  __I  uint32_t  RESERVED6[2];
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x5000518C) Monitoring Input Interrupt Enable Register             */
    
    struct {
      __IO uint32_t  MON1IE     :  1;               /*!< [0..0] MON1 Interrupt Enable                                          */
      __IO uint32_t  MON2IE     :  1;               /*!< [1..1] MON2 Interrupt Enable                                          */
      __IO uint32_t  MON3IE     :  1;               /*!< [2..2] MON3 Interrupt Enable                                          */
      __IO uint32_t  MON4IE     :  1;               /*!< [3..3] MON4 Interrupt Enable                                          */
      __IO uint32_t  MON5IE     :  1;               /*!< [4..4] MON5 Interrupt Enable                                          */
    } bit;                                          /*!< [5] BitSize                                                           */
  } MONIEN;
  
  union {
    __O  uint32_t  reg;                             /*!< (@ 0x50005190) Interrupt Request 2 Clear Register                     */
    
    struct {
      __O  uint32_t  EIR1C      :  1;               /*!< [0..0] Error Interrupt Flag for SSC1                                  */
      __O  uint32_t  TIR1C      :  1;               /*!< [1..1] Transmit Interrupt Flag for SSC1                               */
      __O  uint32_t  RIR1C      :  1;               /*!< [2..2] Receive Interrupt Flag for SSC1                                */
    } bit;                                          /*!< [3] BitSize                                                           */
  } IRCON2CLR;
  
  union {
    __O  uint32_t  reg;                             /*!< (@ 0x50005194) Interrupt Request 3 Clear Register                     */
    
    struct {
      __O  uint32_t  EIR2C      :  1;               /*!< [0..0] Error Interrupt Flag for SSC2                                  */
      __O  uint32_t  TIR2C      :  1;               /*!< [1..1] Transmit Interrupt Flag for SSC2                               */
      __O  uint32_t  RIR2C      :  1;               /*!< [2..2] Receive Interrupt Flag for SSC2                                */
    } bit;                                          /*!< [3] BitSize                                                           */
  } IRCON3CLR;
  
  union {
    __O  uint32_t  reg;                             /*!< (@ 0x50005198) Interrupt Request 4 Clear Register                     */
    
    struct {
      __O  uint32_t  CCU6SR0C   :  1;               /*!< [0..0] Interrupt Flag 1 for CCU6                                      */
           uint32_t             :  3;
      __O  uint32_t  CCU6SR1C   :  1;               /*!< [4..4] Interrupt Flag 1 for CCU6                                      */
           uint32_t             : 11;
      __O  uint32_t  CCU6SR2C   :  1;               /*!< [16..16] Interrupt Flag 1 for CCU6                                    */
           uint32_t             :  3;
      __O  uint32_t  CCU6SR3C   :  1;               /*!< [20..20] Interrupt Flag 1 for CCU6                                    */
    } bit;                                          /*!< [21] BitSize                                                          */
  } IRCON4CLR;
  
  union {
    __O  uint32_t  reg;                             /*!< (@ 0x5000519C) Interrupt Request 5 Clear Register                     */
    
    struct {
      __O  uint32_t  WAKEUPC    :  1;               /*!< [0..0] Clear Flag for Wakeup Interrupt                                */
    } bit;                                          /*!< [1] BitSize                                                           */
  } IRCON5CLR;
} SCU_Type;


/* ================================================================================ */
/* ================                      SCUPM                     ================ */
/* ================================================================================ */


/**
  * @brief SCUPM (SCUPM)
  */

typedef struct {                                    /*!< (@ 0x50006000) SCUPM Structure                                        */
  
  union {
    __I  uint32_t  reg;                             /*!< (@ 0x50006000) Analog Module Clock Frequency Status Register          */
    
    struct {
      __I  uint32_t  AMCLK1_FREQ:  6;               /*!< [0..5] Current frequency of Analog Module Clock System Clock
                                                         (MI_CLK)                                                              */
           uint32_t             :  2;
      __I  uint32_t  AMCLK2_FREQ:  6;               /*!< [8..13] Current frequency of Analog Module Clock 2 (TFILT_CLK)        */
    } bit;                                          /*!< [14] BitSize                                                          */
  } AMCLK_FREQ_STS;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x50006004) Analog Module Clock Control Register                   */
    
    struct {
      __IO uint32_t  CLKWDT_PD_N:  1;               /*!< [0..0] Clock Watchdog Powerdown                                       */
    } bit;                                          /*!< [1] BitSize                                                           */
  } AMCLK_CTRL;
  __I  uint32_t  RESERVED;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x5000600C) Analog Module Clock Limit Register                     */
    
    struct {
      __IO uint32_t  AMCLK1_UP_TH:  6;              /*!< [0..5] Analog Module Clock 1 (MI_CLK) Upper Limit Threshold           */
      __IO uint32_t  AMCLK1_UP_HYS:  2;             /*!< [6..7] Analog Module Clock 1 (MI_CLK) Upper Hysteresis                */
      __IO uint32_t  AMCLK1_LOW_TH:  6;             /*!< [8..13] Analog Module Clock 1 (MI_CLK) Lower Limit Threshold          */
      __IO uint32_t  AMCLK1_LOW_HYS:  2;            /*!< [14..15] Analog Module Clock 1 (MI_CLK) Lower Hysteresis              */
      __IO uint32_t  AMCLK2_UP_TH:  6;              /*!< [16..21] Analog Module Clock 2 (TFILT_CLK) Upper Limit Threshold      */
      __IO uint32_t  AMCLK2_UP_HYS:  2;             /*!< [22..23] Analog Module Clock 2 (TFILT_CLK) Upper Hysteresis           */
      __IO uint32_t  AMCLK2_LOW_TH:  6;             /*!< [24..29] Analog Module Clock 2 (TFILT_CLK) Lower Limit Threshold      */
      __IO uint32_t  AMCLK2_LOW_HYS:  2;            /*!< [30..31] Analog Module Clock 2 (TFILT_CLK) Lower Hysteresis           */
    } bit;                                          /*!< [32] BitSize                                                          */
  } AMCLK_TH_HYS;
  __I  uint32_t  RESERVED1;
  
  union {
    __O  uint32_t  reg;                             /*!< (@ 0x50006014) System Interrupt Status Clear Register                 */
    
    struct {
           uint32_t             :  8;
      __O  uint32_t  SYS_OTWARN_ISC:  1;            /*!< [8..8] System Overtemperature Prewarning status clear                 */
      __O  uint32_t  SYS_OT_ISC :  1;               /*!< [9..9] System Overtemperature Shutdown status clear                   */
      __O  uint32_t  REFBG_LOTHWARN_ISC:  1;        /*!< [10..10] 8-Bit ADC2 Reference Undervoltage interrupt status
                                                         clear                                                                 */
      __O  uint32_t  REFBG_UPTHWARN_ISC:  1;        /*!< [11..11] 8-Bit ADC2 Reference Overvoltage interrupt status clear      */
           uint32_t             : 12;
      __O  uint32_t  SYS_OTWARN_SC:  1;             /*!< [24..24] System Overtemperature Prewarning status clear               */
      __O  uint32_t  SYS_OT_SC  :  1;               /*!< [25..25] System Overtemperature Shutdown status clear                 */
    } bit;                                          /*!< [26] BitSize                                                          */
  } SYS_ISCLR;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x50006018) System Interrupt Status Register                       */
    
    struct {
      __I  uint32_t  LS1_FAIL_IS:  1;               /*!< [0..0] Low Side Driver 1 Fail Interrupt Status                        */
      __I  uint32_t  LS2_FAIL_IS:  1;               /*!< [1..1] Low Side Driver 2 Fail Interrupt Status                        */
      __I  uint32_t  HS1_FAIL_IS:  1;               /*!< [2..2] High Side Driver 1 Fail Interrupt Status                       */
      __I  uint32_t  HS2_FAIL_IS:  1;               /*!< [3..3] High Side Driver 2 Fail Interrupt Status                       */
           uint32_t             :  2;
      __I  uint32_t  LIN_FAIL_IS:  1;               /*!< [6..6] LIN Fail Interrupt Status                                      */
           uint32_t             :  1;
      __IO uint32_t  SYS_OTWARN_IS:  1;             /*!< [8..8] System Overtemperature Prewarning (ADC2, Channel 6) interrupt
                                                         status                                                                */
      __IO uint32_t  SYS_OT_IS  :  1;               /*!< [9..9] System Overtemperature Shutdown (ADC2, Channel 6) interrupt
                                                         status                                                                */
      __IO uint32_t  REFBG_LOTHWARN_IS:  1;         /*!< [10..10] 8-Bit ADC2 Reference Undervoltage (ADC2, Channel 4)
                                                         interrupt status                                                      */
      __IO uint32_t  REFBG_UPTHWARN_IS:  1;         /*!< [11..11] 8-Bit ADC2 Reference Overvoltage (ADC2, Channel 4)
                                                         interrupt status                                                      */
      __I  uint32_t  SYS_SUPPLY_IS:  1;             /*!< [12..12] System Supply Interrupt Status                               */
           uint32_t             :  3;
      __I  uint32_t  LS1_FAIL_STS:  1;              /*!< [16..16] Low Side Driver 1 Fail Status                                */
      __I  uint32_t  LS2_FAIL_STS:  1;              /*!< [17..17] Low Side Driver 2 Fail Status                                */
      __I  uint32_t  HS1_FAIL_STS:  1;              /*!< [18..18] High Side Driver 1 Fail Status                               */
      __I  uint32_t  HS2_FAIL_STS:  1;              /*!< [19..19] High Side Driver 2 Fail Status                               */
           uint32_t             :  2;
      __I  uint32_t  LIN_FAIL_STS:  1;              /*!< [22..22] LIN Fail Status                                              */
           uint32_t             :  1;
      __IO uint32_t  SYS_OTWARN_STS:  1;            /*!< [24..24] System Overtemperature Prewarning (ADC2, Channel 6)
                                                         status                                                                */
      __IO uint32_t  SYS_OT_STS :  1;               /*!< [25..25] System Overtemperature Shutdown (ADC2, Channel 6) status     */
           uint32_t             :  2;
      __I  uint32_t  SYS_SUPPLY_STS:  1;            /*!< [28..28] System Supply Status                                         */
    } bit;                                          /*!< [29] BitSize                                                          */
  } SYS_IS;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x5000601C) System Supply Interrupt Status Register                */
    
    struct {
      __IO uint32_t  VBAT_UV_IS :  1;               /*!< [0..0] VBAT Undervoltage Interrupt Status (ADC2 channel 0)            */
      __IO uint32_t  VS_UV_IS   :  1;               /*!< [1..1] VS Undervoltage Interrupt Status (ADC2 channel 1)              */
      __IO uint32_t  VDD5V_UV_IS:  1;               /*!< [2..2] VDDP Undervoltage Interrupt Status (ADC2 channel 2)            */
      __IO uint32_t  VDD1V5_UV_IS:  1;              /*!< [3..3] VDDC Undervoltage Interrupt Status (ADC2 channel 3)            */
      __IO uint32_t  VDDEXT_UV_IS:  1;              /*!< [4..4] VDDEXT Undervoltage Interrupt Status (ADC2 channel 2)          */
      __IO uint32_t  VBAT_OV_IS :  1;               /*!< [5..5] VBAT Overvoltage Interrupt Status (ADC2 channel 0)             */
      __IO uint32_t  VS_OV_IS   :  1;               /*!< [6..6] VS Overvoltage Interrupt Status (ADC2 channel 1)               */
      __IO uint32_t  VDD5V_OV_IS:  1;               /*!< [7..7] VDDP Overvoltage Interrupt Status (ADC2 channel 2)             */
      __IO uint32_t  VDD1V5_OV_IS:  1;              /*!< [8..8] VDDC Overvoltage Interrupt Status (ADC2 channel 3)             */
      __IO uint32_t  VDDEXT_OV_IS:  1;              /*!< [9..9] VDDEXT Overvoltage Interrupt Status (ADC2 channel 2)           */
           uint32_t             :  6;
      __IO uint32_t  VBAT_UV_STS:  1;               /*!< [16..16] VBAT Undervoltage Status                                     */
      __IO uint32_t  VS_UV_STS  :  1;               /*!< [17..17] VS Undervoltage Status                                       */
      __IO uint32_t  VDD5V_UV_STS:  1;              /*!< [18..18] VDDP Undervoltage Status                                     */
      __IO uint32_t  VDD1V5_UV_STS:  1;             /*!< [19..19] VDDC Undervoltage Status                                     */
      __IO uint32_t  VDDEXT_UV_STS:  1;             /*!< [20..20] VDDEXT Undervoltage Status                                   */
      __IO uint32_t  VBAT_OV_STS:  1;               /*!< [21..21] VBAT Overvoltage Status                                      */
      __IO uint32_t  VS_OV_STS  :  1;               /*!< [22..22] VS Overvoltage Interrupt Status                              */
      __IO uint32_t  VDD5V_OV_STS:  1;              /*!< [23..23] VDDP Overvoltage Status                                      */
      __IO uint32_t  VDD1V5_OV_STS:  1;             /*!< [24..24] VDDC Overvoltage Status                                      */
      __IO uint32_t  VDDEXT_OV_STS:  1;             /*!< [25..25] VDDEXT Overvoltage Status                                    */
    } bit;                                          /*!< [26] BitSize                                                          */
  } SYS_SUPPLY_IRQ_STS;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x50006020) System Supply Interrupt Control Register               */
    
    struct {
      __IO uint32_t  VBAT_UV_IE :  1;               /*!< [0..0] VBAT Undervoltage Interrupt Enable                             */
      __IO uint32_t  VS_UV_IE   :  1;               /*!< [1..1] VS Undervoltage Interrupt Enable                               */
      __IO uint32_t  VDD5V_UV_IE:  1;               /*!< [2..2] VDDP Undervoltage Interrupt Enable                             */
      __IO uint32_t  VDD1V5_UV_IE:  1;              /*!< [3..3] VDDC Undervoltage Interrupt Enable                             */
      __IO uint32_t  VDDEXT_UV_IE:  1;              /*!< [4..4] VDDEXT Undervoltage Interrupt Enable                           */
      __IO uint32_t  VBAT_OV_IE :  1;               /*!< [5..5] VBAT Overvoltage Interrupt Enable                              */
      __IO uint32_t  VS_OV_IE   :  1;               /*!< [6..6] VS Overvoltage Interrupt Enable                                */
      __IO uint32_t  VDD5V_OV_IE:  1;               /*!< [7..7] VDDP Overvoltage Interrupt Enable                              */
      __IO uint32_t  VDD1V5_OV_IE:  1;              /*!< [8..8] VDDC Overvoltage Interrupt Enable                              */
      __IO uint32_t  VDDEXT_OV_IE:  1;              /*!< [9..9] VDDEXT Overvoltage Interrupt Enable                            */
    } bit;                                          /*!< [10] BitSize                                                          */
  } SYS_SUPPLY_IRQ_CTRL;
  
  union {
    __O  uint32_t  reg;                             /*!< (@ 0x50006024) System Supply Interrupt Status Clear Register          */
    
    struct {
      __O  uint32_t  VBAT_UV_ISC:  1;               /*!< [0..0] VBAT Undervoltage Interrupt Status clear                       */
      __O  uint32_t  VS_UV_ISC  :  1;               /*!< [1..1] VS Undervoltage Interrupt Status clear                         */
      __O  uint32_t  VDD5V_UV_ISC:  1;              /*!< [2..2] VDDP Undervoltage Interrupt Status clear                       */
      __O  uint32_t  VDD1V5_UV_ISC:  1;             /*!< [3..3] VDDC Undervoltage Interrupt Status clear                       */
      __O  uint32_t  VDDEXT_UV_ISC:  1;             /*!< [4..4] VDDEXT Undervoltage Interrupt Status clear                     */
      __O  uint32_t  VBAT_OV_ISC:  1;               /*!< [5..5] VBAT Overvoltage Interrupt Status clear                        */
      __O  uint32_t  VS_OV_ISC  :  1;               /*!< [6..6] VS Overvoltage Interrupt Status clear                          */
      __O  uint32_t  VDD5V_OV_ISC:  1;              /*!< [7..7] VDDP Overvoltage Interrupt Status clear                        */
      __O  uint32_t  VDD1V5_OV_ISC:  1;             /*!< [8..8] VDDC Overvoltage Interrupt Status clear                        */
      __O  uint32_t  VDDEXT_OV_ISC:  1;             /*!< [9..9] VDDEXT Overvoltage Interrupt Status clear                      */
           uint32_t             :  6;
      __O  uint32_t  VBAT_UV_SC :  1;               /*!< [16..16] VBAT Undervoltage Status clear                               */
      __O  uint32_t  VS_UV_SC   :  1;               /*!< [17..17] VS Undervoltage Status clear                                 */
      __O  uint32_t  VDD5V_UV_SC:  1;               /*!< [18..18] VDDP Undervoltage Status clear                               */
      __O  uint32_t  VDD1V5_UV_SC:  1;              /*!< [19..19] VDDC Undervoltage Status clear                               */
      __O  uint32_t  VDDEXT_UV_SC:  1;              /*!< [20..20] VDDEXT Undervoltage Status clear                             */
      __O  uint32_t  VBAT_OV_SC :  1;               /*!< [21..21] VBAT Overvoltage Status clear                                */
      __O  uint32_t  VS_OV_SC   :  1;               /*!< [22..22] VS Overvoltage Interrupt Status clear                        */
      __O  uint32_t  VDD5V_OV_SC:  1;               /*!< [23..23] VDDP Overvoltage Status clear                                */
      __O  uint32_t  VDD1V5_OV_SC:  1;              /*!< [24..24] VDDC Overvoltage Status clear                                */
      __O  uint32_t  VDDEXT_OV_SC:  1;              /*!< [25..25] VDDEXT Overvoltage Status clear                              */
    } bit;                                          /*!< [26] BitSize                                                          */
  } SYS_SUPPLY_IRQ_CLR;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x50006028) System Interrupt Control Register                      */
    
    struct {
           uint32_t             :  8;
      __IO uint32_t  SYS_OTWARN_IE:  1;             /*!< [8..8] System Overtemperature Warning Interrupt Enable                */
      __IO uint32_t  SYS_OT_IE  :  1;               /*!< [9..9] System Overtemperature Shutdown Interrupt Enable (leads
                                                         to shutdown of System)                                                */
      __IO uint32_t  REFBG_LOTHWARN_IE:  1;         /*!< [10..10] Reference Voltage Undervoltage Interrupt Enable              */
      __IO uint32_t  REFBG_UPTHWARN_IE:  1;         /*!< [11..11] Reference Voltage Overvoltage Interrupt Enable               */
    } bit;                                          /*!< [12] BitSize                                                          */
  } SYS_IRQ_CTRL;
  __I  uint32_t  RESERVED2;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x50006030) Power Control Unit Control Status Register             */
    
    struct {
           uint32_t             :  1;
      __IO uint32_t  CLKWDT_SD_DIS:  1;             /*!< [1..1] Power Modules Clock Watchdog Shutdown Disable                  */
           uint32_t             :  6;
      __IO uint32_t  LIN_VS_UV_SD_DIS:  1;          /*!< [8..8] LIN Module VS Undervoltage Transmitter Shutdown                */
    } bit;                                          /*!< [9] BitSize                                                           */
  } PCU_CTRL_STS;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x50006034) WDT1 Watchdog Control                                  */
    
    struct {
      __IO uint32_t  WDP_SEL    :  6;               /*!< [0..5] Watchdog Period Selection and trigger                          */
      __IO uint32_t  SOWCONF    :  2;               /*!< [6..7] Short Open Window Configuration                                */
    } bit;                                          /*!< [8] BitSize                                                           */
  } WDT1_TRIG;
  __I  uint32_t  RESERVED3[13];
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x5000606C) System Tick Calibration Register                       */
    
    struct {
      __IO uint32_t  STCALIB    : 26;               /*!< [0..25] System Tick Calibration                                       */
    } bit;                                          /*!< [26] BitSize                                                          */
  } STCALIB;
  __I  uint32_t  RESERVED4[8];
  
  union {
    __I  uint32_t  reg;                             /*!< (@ 0x50006090) Package Configuration Register 1                       */
    
    struct {
           uint32_t             :  8;
      __I  uint32_t  HS2EN      :  1;               /*!< [8..8] High Side 2 Enable                                             */
    } bit;                                          /*!< [9] BitSize                                                           */
  } PKGCFG1;
} SCUPM_Type;


/* ================================================================================ */
/* ================                      SSCx                      ================ */
/* ================================================================================ */


/**
  * @brief SSCx (SSCx)
  */

typedef struct {                                    /*!< (@ 0x48024000) SSC1 Structure                                         */
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x48024000) Port Input Select Register                             */
    
    struct {
      __IO uint32_t  MIS_0      :  1;               /*!< [0..0] Master Mode Input Select Bit 0 (Master Mode only)              */
      __IO uint32_t  SIS        :  1;               /*!< [1..1] Slave Mode Input Select (Slave Mode only)                      */
      __IO uint32_t  CIS        :  1;               /*!< [2..2] Clock Input Select (Slave Mode only)                           */
      __IO uint32_t  MIS_1      :  1;               /*!< [3..3] Master Mode Input Select Bit 1 (Master Mode only)              */
    } bit;                                          /*!< [4] BitSize                                                           */
  } PISEL;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x48024004) Control Register                                       */
    
    struct {
      __IO uint32_t  BM         :  4;               /*!< [0..3] Data Width Selection                                           */
      __IO uint32_t  HB         :  1;               /*!< [4..4] Heading Control                                                */
      __IO uint32_t  PH         :  1;               /*!< [5..5] Clock Phase Control                                            */
      __IO uint32_t  PO         :  1;               /*!< [6..6] Clock Polarity Control                                         */
      __IO uint32_t  LB         :  1;               /*!< [7..7] Loop Back Control                                              */
      __IO uint32_t  TEN        :  1;               /*!< [8..8] Transmit Error Enable                                          */
      __IO uint32_t  REN        :  1;               /*!< [9..9] Receive Error Enable                                           */
      __IO uint32_t  PEN        :  1;               /*!< [10..10] Phase Error Enable                                           */
      __IO uint32_t  BEN        :  1;               /*!< [11..11] Baud Rate Error Enable                                       */
      __IO uint32_t  AREN       :  1;               /*!< [12..12] Automatic Reset Enable                                       */
           uint32_t             :  1;
      __IO uint32_t  MS         :  1;               /*!< [14..14] Master Select                                                */
      __IO uint32_t  EN         :  1;               /*!< [15..15] Enable Bit                                                   */
      __I  uint32_t  BC         :  4;               /*!< [16..19] Bit Count Field                                              */
           uint32_t             :  4;
      __I  uint32_t  TE         :  1;               /*!< [24..24] Transmit Error Flag                                          */
      __I  uint32_t  RE         :  1;               /*!< [25..25] Receive Error Flag                                           */
      __I  uint32_t  PE         :  1;               /*!< [26..26] Phase Error Flag                                             */
      __I  uint32_t  BE         :  1;               /*!< [27..27] Baud Rate Error Flag                                         */
      __I  uint32_t  BSY        :  1;               /*!< [28..28] Busy Flag                                                    */
    } bit;                                          /*!< [29] BitSize                                                          */
  } CON;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x48024008) Transmitter Buffer Register                            */
    
    struct {
      __IO uint32_t  TB_VALUE   : 16;               /*!< [0..15] Transmit Data Register Value                                  */
    } bit;                                          /*!< [16] BitSize                                                          */
  } TB;
  
  union {
    __I  uint32_t  reg;                             /*!< (@ 0x4802400C) Receiver Buffer Register                               */
    
    struct {
      __I  uint32_t  RB_VALUE   : 16;               /*!< [0..15] Receive Data Register Value                                   */
    } bit;                                          /*!< [16] BitSize                                                          */
  } RB;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x48024010) Baud Rate Timer Reload Register                        */
    
    struct {
      __IO uint32_t  BR_VALUE   : 16;               /*!< [0..15] Baud Rate Timer/Reload Register Value                         */
    } bit;                                          /*!< [16] BitSize                                                          */
  } BR;
  
  union {
    __O  uint32_t  reg;                             /*!< (@ 0x48024014) Interrupt Status Register Clear                        */
    
    struct {
           uint32_t             :  8;
      __O  uint32_t  TECLR      :  1;               /*!< [8..8] Transmit Error Flag Clear                                      */
      __O  uint32_t  RECLR      :  1;               /*!< [9..9] Receive Error Flag Clear                                       */
      __O  uint32_t  PECLR      :  1;               /*!< [10..10] Phase Error Flag Clear                                       */
      __O  uint32_t  BECLR      :  1;               /*!< [11..11] Baud Rate Error Flag Clear                                   */
    } bit;                                          /*!< [12] BitSize                                                          */
  } ISRCLR;
} SSCx_Type;




/* ================================================================================ */
/* ================                     TIMER2x                     ================ */
/* ================================================================================ */


/**
  * @brief TIMER2x (TIMER2x)
  */

typedef struct {                                    /*!< (@ 0x48004000) TIMER2 Structure                                       */
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x48004000) Timer 2 Control Register                               */
    
    struct {
      __IO uint32_t  CP_RL2     :  1;               /*!< [0..0] Capture/Reload Select                                          */
      __IO uint32_t  C_T2       :  1;               /*!< [1..1] Timer or Counter Select                                        */
      __IO uint32_t  TR2        :  1;               /*!< [2..2] Timer 2 Start/Stop Control                                     */
      __IO uint32_t  EXEN2      :  1;               /*!< [3..3] Timer 2 External Enable Control                                */
           uint32_t             :  2;
      __I  uint32_t  EXF2       :  1;               /*!< [6..6] Timer 2 External Flag                                          */
      __I  uint32_t  TF2        :  1;               /*!< [7..7] Timer 2 Overflow/Underflow Flag                                */
    } bit;                                          /*!< [8] BitSize                                                           */
  } CON;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x48004004) Timer 2 Mode Register                                  */
    
    struct {
      __IO uint32_t  DCEN       :  1;               /*!< [0..0] Up/Down Counter Enable                                         */
      __IO uint32_t  T2PRE      :  3;               /*!< [1..3] Timer 2 Prescaler Bit                                          */
      __IO uint32_t  PREN       :  1;               /*!< [4..4] Prescaler Enable                                               */
      __IO uint32_t  EDGESEL    :  1;               /*!< [5..5] Edge Select in Capture Mode/Reload Mode                        */
      __IO uint32_t  T2RHEN     :  1;               /*!< [6..6] Timer 2 External Start Enable                                  */
      __IO uint32_t  T2REGS     :  1;               /*!< [7..7] Edge Select for Timer 2 External Start                         */
    } bit;                                          /*!< [8] BitSize                                                           */
  } MOD;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x48004008) Timer 2 Reload/Capture Register                        */
    
    struct {
      __IO uint32_t  RCL2       :  8;               /*!< [0..7] Reload/Capture Value                                           */
      __IO uint32_t  RCH2       :  8;               /*!< [8..15] Reload/Capture Value                                          */
    } bit;                                          /*!< [16] BitSize                                                          */
  } RC;
  __I  uint32_t  RESERVED;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x48004010) Timer 2 Count Register                                 */
    
    struct {
      __IO uint32_t  T2L        :  8;               /*!< [0..7] Timer 2 Value                                                  */
      __IO uint32_t  T2H        :  8;               /*!< [8..15] Timer 2 Value                                                 */
    } bit;                                          /*!< [16] BitSize                                                          */
  } CNT;
  __I  uint32_t  RESERVED1;
  
  union {
    __O  uint32_t  reg;                             /*!< (@ 0x48004018) Timer 2 Interrupt Clear Register                       */
    
    struct {
           uint32_t             :  6;
      __O  uint32_t  EXF2CLR    :  1;               /*!< [6..6] External Interrupt Clear Flag                                  */
      __O  uint32_t  TF2CLR     :  1;               /*!< [7..7] Overflow/Underflow Interrupt Clear Flag                        */
    } bit;                                          /*!< [8] BitSize                                                           */
  } ICLR;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x4800401C) Timer 2 Control Register 1                             */
    
    struct {
      __IO uint32_t  EXF2EN     :  1;               /*!< [0..0] External Interrupt Enable                                      */
      __IO uint32_t  TF2EN      :  1;               /*!< [1..1] Overflow/Underflow Interrupt Enable                            */
    } bit;                                          /*!< [2] BitSize                                                           */
  } CON1;
} TIMER2x_Type;


/* ================================================================================ */
/* ================                      UARTx                     ================ */
/* ================================================================================ */


/**
  * @brief UARTx (UARTx)
  */

typedef struct {                                    /*!< (@ 0x48020000) UART1 Structure                                        */
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x48020000) Serial Channel Control Register                        */
    
    struct {
      __IO uint32_t  RI         :  1;               /*!< [0..0] Receive Interrupt Flag                                         */
      __IO uint32_t  TI         :  1;               /*!< [1..1] Transmit Interrupt Flag                                        */
      __IO uint32_t  RB8        :  1;               /*!< [2..2] Serial Port Receiver Bit 9                                     */
      __IO uint32_t  TB8        :  1;               /*!< [3..3] Serial Port Transmitter Bit 9                                  */
      __IO uint32_t  REN        :  1;               /*!< [4..4] Enable Receiver of Serial Port                                 */
      __IO uint32_t  SM2        :  1;               /*!< [5..5] Enable Serial Port Multiprocessor Communication in Modes
                                                         2 and 3                                                               */
      __IO uint32_t  SM1        :  1;               /*!< [6..6] Serial Port Operating Mode Selection                           */
      __IO uint32_t  SM0        :  1;               /*!< [7..7] Serial Port Operating Mode Selection                           */
    } bit;                                          /*!< [8] BitSize                                                           */
  } SCON;
  
  union {
    __IO uint32_t  reg;                             /*!< (@ 0x48020004) Serial Data Buffer                                     */
    
    struct {
      __IO uint32_t  VAL        :  8;               /*!< [0..7] Serial Interface Buffer Register                               */
    } bit;                                          /*!< [8] BitSize                                                           */
  } SBUF;
  
  union {
    __O  uint32_t  reg;                             /*!< (@ 0x48020008) Serial Channel Control Clear Register                  */
    
    struct {
      __O  uint32_t  RICLR      :  1;               /*!< [0..0] SCON.RI Clear Flag                                             */
      __O  uint32_t  TICLR      :  1;               /*!< [1..1] SCON.TI Clear Flag                                             */
      __O  uint32_t  RB8CLR     :  1;               /*!< [2..2] SCON.RB8 Clear Flag                                            */
    } bit;                                          /*!< [3] BitSize                                                           */
  } SCONCLR;
} UARTx_Type;




/* --------------------  End of section using anonymous unions  ------------------- */



/* ================================================================================ */
/* ================              Peripheral memory map             ================ */
/* ================================================================================ */

#define ADC1_BASE                       0x40004000UL
#define ADC2_BASE                       0x4801C000UL
#define CCU6_BASE                       0x4000C000UL
#define CPU_BASE                        0xE000E000UL
#define GPT12E_BASE                     0x40010000UL
#define HS_BASE                         0x40024000UL
#define LIN_BASE                        0x4801E000UL
#define LS_BASE                         0x4001C000UL
#define MF_BASE                         0x48018000UL
#define PMU_BASE                        0x50004000UL
#define PORT_BASE                       0x48028000UL
#define SCU_BASE                        0x50005000UL
#define SCUPM_BASE                      0x50006000UL
#define SSC1_BASE                       0x48024000UL
#define SSC2_BASE                       0x48026000UL
#define TIMER2_BASE                     0x48004000UL
#define TIMER21_BASE                    0x48005000UL
#define UART1_BASE                      0x48020000UL
#define UART2_BASE                      0x48022000UL


/* ================================================================================ */
/* ================             Peripheral declaration             ================ */
/* ================================================================================ */

#define ADC1                            ((ADC1_Type               *) ADC1_BASE)
#define ADC2                            ((ADC2_Type               *) ADC2_BASE)
#define CCU6                            ((CCU6_Type               *) CCU6_BASE)
#define CPU                             ((CPU_Type                *) CPU_BASE)
#define GPT12E                          ((GPT12E_Type             *) GPT12E_BASE)
#define HS                              ((HS_Type                 *) HS_BASE)
#define LIN                             ((LIN_Type                *) LIN_BASE)
#define LS                              ((LS_Type                 *) LS_BASE)
#define MF                              ((MF_Type                 *) MF_BASE)
#define PMU                             ((PMU_Type                *) PMU_BASE)
#define PORT                            ((PORT_Type               *) PORT_BASE)
#define SCU                             ((SCU_Type                *) SCU_BASE)
#define SCUPM                           ((SCUPM_Type              *) SCUPM_BASE)
#define SSC1                            ((SSCx_Type               *) SSC1_BASE)
#define SSC2                            ((SSCx_Type               *) SSC2_BASE)
#define TIMER2                          ((TIMER2x_Type             *) TIMER2_BASE)
#define TIMER21                         ((TIMER2x_Type            *) TIMER21_BASE)
#define UART1                           ((UARTx_Type              *) UART1_BASE)
#define UART2                           ((UARTx_Type              *) UART2_BASE)


/** @} */ /* End of group Device_Peripheral_Registers */

/* =========================================================================================================================== */
/* ================                                Pos/Mask Peripheral Section                                ================ */
/* =========================================================================================================================== */


/** @addtogroup PosMask_peripherals
  * @{
  */



/* =========================================================================================================================== */
/* ================                                           ADC1                                            ================ */
/* =========================================================================================================================== */

/* =======================================================  CTRL_STS  ======================================================== */
#define ADC1_CTRL_STS_STRTUP_DIS_Pos      (18UL)                    /*!< ADC1 CTRL_STS: STRTUP_DIS (Bit 18)                    */
#define ADC1_CTRL_STS_STRTUP_DIS_Msk      (0x40000UL)               /*!< ADC1 CTRL_STS: STRTUP_DIS (Bitfield-Mask: 0x01)       */
#define ADC1_CTRL_STS_SW_CH_SEL_Pos       (8UL)                     /*!< ADC1 CTRL_STS: SW_CH_SEL (Bit 8)                      */
#define ADC1_CTRL_STS_SW_CH_SEL_Msk       (0xf00UL)                 /*!< ADC1 CTRL_STS: SW_CH_SEL (Bitfield-Mask: 0x0f)        */
#define ADC1_CTRL_STS_EOC_Pos             (7UL)                     /*!< ADC1 CTRL_STS: EOC (Bit 7)                            */
#define ADC1_CTRL_STS_EOC_Msk             (0x80UL)                  /*!< ADC1 CTRL_STS: EOC (Bitfield-Mask: 0x01)              */
#define ADC1_CTRL_STS_CAL_SIGN_Pos        (5UL)                     /*!< ADC1 CTRL_STS: CAL_SIGN (Bit 5)                       */
#define ADC1_CTRL_STS_CAL_SIGN_Msk        (0x20UL)                  /*!< ADC1 CTRL_STS: CAL_SIGN (Bitfield-Mask: 0x01)         */
#define ADC1_CTRL_STS_READY_Pos           (4UL)                     /*!< ADC1 CTRL_STS: READY (Bit 4)                          */
#define ADC1_CTRL_STS_READY_Msk           (0x10UL)                  /*!< ADC1 CTRL_STS: READY (Bitfield-Mask: 0x01)            */
#define ADC1_CTRL_STS_SOS_Pos             (2UL)                     /*!< ADC1 CTRL_STS: SOS (Bit 2)                            */
#define ADC1_CTRL_STS_SOS_Msk             (0x4UL)                   /*!< ADC1 CTRL_STS: SOS (Bitfield-Mask: 0x01)              */
#define ADC1_CTRL_STS_SOOC_Pos            (1UL)                     /*!< ADC1 CTRL_STS: SOOC (Bit 1)                           */
#define ADC1_CTRL_STS_SOOC_Msk            (0x2UL)                   /*!< ADC1 CTRL_STS: SOOC (Bitfield-Mask: 0x01)             */
#define ADC1_CTRL_STS_PD_N_Pos            (0UL)                     /*!< ADC1 CTRL_STS: PD_N (Bit 0)                           */
#define ADC1_CTRL_STS_PD_N_Msk            (0x1UL)                   /*!< ADC1 CTRL_STS: PD_N (Bitfield-Mask: 0x01)             */
/* ========================================================  STATUS  ========================================================= */
#define ADC1_STATUS_SD_FEEDB_ON_Pos       (31UL)                    /*!< ADC1 STATUS: SD_FEEDB_ON (Bit 31)                     */
#define ADC1_STATUS_SD_FEEDB_ON_Msk       (0x80000000UL)            /*!< ADC1 STATUS: SD_FEEDB_ON (Bitfield-Mask: 0x01)        */
#define ADC1_STATUS_SOC_JITTER_Pos        (16UL)                    /*!< ADC1 STATUS: SOC_JITTER (Bit 16)                      */
#define ADC1_STATUS_SOC_JITTER_Msk        (0x30000UL)               /*!< ADC1 STATUS: SOC_JITTER (Bitfield-Mask: 0x03)         */
#define ADC1_STATUS_DAC_IN_Pos            (0UL)                     /*!< ADC1 STATUS: DAC_IN (Bit 0)                           */
#define ADC1_STATUS_DAC_IN_Msk            (0x7UL)                   /*!< ADC1 STATUS: DAC_IN (Bitfield-Mask: 0x07)             */
/* =========================================================  CTRL2  ========================================================= */
#define ADC1_CTRL2_CAL_EN_Pos             (0UL)                     /*!< ADC1 CTRL2: CAL_EN (Bit 0)                            */
#define ADC1_CTRL2_CAL_EN_Msk             (0xfffUL)                 /*!< ADC1 CTRL2: CAL_EN (Bitfield-Mask: 0xfff)             */
/* =========================================================  CTRL3  ========================================================= */
#define ADC1_CTRL3_SAMPLE_TIME_LVCH_Pos   (16UL)                    /*!< ADC1 CTRL3: SAMPLE_TIME_LVCH (Bit 16)                 */
#define ADC1_CTRL3_SAMPLE_TIME_LVCH_Msk   (0xf0000UL)               /*!< ADC1 CTRL3: SAMPLE_TIME_LVCH (Bitfield-Mask: 0x0f)    */
#define ADC1_CTRL3_SAMPLE_TIME_HVCH_Pos   (8UL)                     /*!< ADC1 CTRL3: SAMPLE_TIME_HVCH (Bit 8)                  */
#define ADC1_CTRL3_SAMPLE_TIME_HVCH_Msk   (0xf00UL)                 /*!< ADC1 CTRL3: SAMPLE_TIME_HVCH (Bitfield-Mask: 0x0f)    */
#define ADC1_CTRL3_MCM_RDY_Pos            (7UL)                     /*!< ADC1 CTRL3: MCM_RDY (Bit 7)                           */
#define ADC1_CTRL3_MCM_RDY_Msk            (0x80UL)                  /*!< ADC1 CTRL3: MCM_RDY (Bitfield-Mask: 0x01)             */
#define ADC1_CTRL3_EoC_FAIL_Pos           (6UL)                     /*!< ADC1 CTRL3: EoC_FAIL (Bit 6)                          */
#define ADC1_CTRL3_EoC_FAIL_Msk           (0x40UL)                  /*!< ADC1 CTRL3: EoC_FAIL (Bitfield-Mask: 0x01)            */
#define ADC1_CTRL3_EoC_FAIL_CLR_Pos       (4UL)                     /*!< ADC1 CTRL3: EoC_FAIL_CLR (Bit 4)                      */
#define ADC1_CTRL3_EoC_FAIL_CLR_Msk       (0x10UL)                  /*!< ADC1 CTRL3: EoC_FAIL_CLR (Bitfield-Mask: 0x01)        */
#define ADC1_CTRL3_SW_MODE_Pos            (1UL)                     /*!< ADC1 CTRL3: SW_MODE (Bit 1)                           */
#define ADC1_CTRL3_SW_MODE_Msk            (0x2UL)                   /*!< ADC1 CTRL3: SW_MODE (Bitfield-Mask: 0x01)             */
#define ADC1_CTRL3_MCM_PD_N_Pos           (0UL)                     /*!< ADC1 CTRL3: MCM_PD_N (Bit 0)                          */
#define ADC1_CTRL3_MCM_PD_N_Msk           (0x1UL)                   /*!< ADC1 CTRL3: MCM_PD_N (Bitfield-Mask: 0x01)            */
/* =========================================================  CTRL4  ========================================================= */
#define ADC1_CTRL4_MAX_CALTIME_Pos        (0UL)                     /*!< ADC1 CTRL4: MAX_CALTIME (Bit 0)                       */
#define ADC1_CTRL4_MAX_CALTIME_Msk        (0xfUL)                   /*!< ADC1 CTRL4: MAX_CALTIME (Bitfield-Mask: 0x0f)         */
/* =========================================================  CTRL5  ========================================================= */
#define ADC1_CTRL5_FILT_OUT_SEL_11_0_Pos  (0UL)                     /*!< ADC1 CTRL5: FILT_OUT_SEL_11_0 (Bit 0)                 */
#define ADC1_CTRL5_FILT_OUT_SEL_11_0_Msk  (0xfffUL)                 /*!< ADC1 CTRL5: FILT_OUT_SEL_11_0 (Bitfield-Mask: 0xfff)  */
/* =========================================================  SQ0_1  ========================================================= */
#define ADC1_SQ0_1_SQ1_Pos                (16UL)                    /*!< ADC1 SQ0_1: SQ1 (Bit 16)                              */
#define ADC1_SQ0_1_SQ1_Msk                (0xfff0000UL)             /*!< ADC1 SQ0_1: SQ1 (Bitfield-Mask: 0xfff)                */
#define ADC1_SQ0_1_SQ0_Pos                (0UL)                     /*!< ADC1 SQ0_1: SQ0 (Bit 0)                               */
#define ADC1_SQ0_1_SQ0_Msk                (0xfffUL)                 /*!< ADC1 SQ0_1: SQ0 (Bitfield-Mask: 0xfff)                */
/* =========================================================  SQ2_3  ========================================================= */
#define ADC1_SQ2_3_SQ3_Pos                (16UL)                    /*!< ADC1 SQ2_3: SQ3 (Bit 16)                              */
#define ADC1_SQ2_3_SQ3_Msk                (0xfff0000UL)             /*!< ADC1 SQ2_3: SQ3 (Bitfield-Mask: 0xfff)                */
#define ADC1_SQ2_3_SQ2_Pos                (0UL)                     /*!< ADC1 SQ2_3: SQ2 (Bit 0)                               */
#define ADC1_SQ2_3_SQ2_Msk                (0xfffUL)                 /*!< ADC1 SQ2_3: SQ2 (Bitfield-Mask: 0xfff)                */
/* =========================================================  SQ4_5  ========================================================= */
#define ADC1_SQ4_5_SQ5_Pos                (16UL)                    /*!< ADC1 SQ4_5: SQ5 (Bit 16)                              */
#define ADC1_SQ4_5_SQ5_Msk                (0xfff0000UL)             /*!< ADC1 SQ4_5: SQ5 (Bitfield-Mask: 0xfff)                */
#define ADC1_SQ4_5_SQ4_Pos                (0UL)                     /*!< ADC1 SQ4_5: SQ4 (Bit 0)                               */
#define ADC1_SQ4_5_SQ4_Msk                (0xfffUL)                 /*!< ADC1 SQ4_5: SQ4 (Bitfield-Mask: 0xfff)                */
/* =========================================================  SQ6_7  ========================================================= */
#define ADC1_SQ6_7_SQ7_Pos                (16UL)                    /*!< ADC1 SQ6_7: SQ7 (Bit 16)                              */
#define ADC1_SQ6_7_SQ7_Msk                (0xfff0000UL)             /*!< ADC1 SQ6_7: SQ7 (Bitfield-Mask: 0xfff)                */
#define ADC1_SQ6_7_SQ6_Pos                (0UL)                     /*!< ADC1 SQ6_7: SQ6 (Bit 0)                               */
#define ADC1_SQ6_7_SQ6_Msk                (0xfffUL)                 /*!< ADC1 SQ6_7: SQ6 (Bitfield-Mask: 0xfff)                */
/* =========================================================  SQ8_9  ========================================================= */
#define ADC1_SQ8_9_SQ9_Pos                (16UL)                    /*!< ADC1 SQ8_9: SQ9 (Bit 16)                              */
#define ADC1_SQ8_9_SQ9_Msk                (0xfff0000UL)             /*!< ADC1 SQ8_9: SQ9 (Bitfield-Mask: 0xfff)                */
#define ADC1_SQ8_9_SQ8_Pos                (0UL)                     /*!< ADC1 SQ8_9: SQ8 (Bit 0)                               */
#define ADC1_SQ8_9_SQ8_Msk                (0xfffUL)                 /*!< ADC1 SQ8_9: SQ8 (Bitfield-Mask: 0xfff)                */
/* ========================================================  SQ10_11  ======================================================== */
#define ADC1_SQ10_11_SQ11_Pos             (16UL)                    /*!< ADC1 SQ10_11: SQ11 (Bit 16)                           */
#define ADC1_SQ10_11_SQ11_Msk             (0xfff0000UL)             /*!< ADC1 SQ10_11: SQ11 (Bitfield-Mask: 0xfff)             */
#define ADC1_SQ10_11_SQ10_Pos             (0UL)                     /*!< ADC1 SQ10_11: SQ10 (Bit 0)                            */
#define ADC1_SQ10_11_SQ10_Msk             (0xfffUL)                 /*!< ADC1 SQ10_11: SQ10 (Bitfield-Mask: 0xfff)             */
/* =========================================================  SQ_FB  ========================================================= */
#define ADC1_SQ_FB_CHx_Pos                (16UL)                    /*!< ADC1 SQ_FB: CHx (Bit 16)                              */
#define ADC1_SQ_FB_CHx_Msk                (0xf0000UL)               /*!< ADC1 SQ_FB: CHx (Bitfield-Mask: 0x0f)                 */
#define ADC1_SQ_FB_SQx_Pos                (11UL)                    /*!< ADC1 SQ_FB: SQx (Bit 11)                              */
#define ADC1_SQ_FB_SQx_Msk                (0x7800UL)                /*!< ADC1 SQ_FB: SQx (Bitfield-Mask: 0x0f)                 */
#define ADC1_SQ_FB_ESM_ACTIVE_Pos         (10UL)                    /*!< ADC1 SQ_FB: ESM_ACTIVE (Bit 10)                       */
#define ADC1_SQ_FB_ESM_ACTIVE_Msk         (0x400UL)                 /*!< ADC1 SQ_FB: ESM_ACTIVE (Bitfield-Mask: 0x01)          */
#define ADC1_SQ_FB_EIM_ACTIVE_Pos         (9UL)                     /*!< ADC1 SQ_FB: EIM_ACTIVE (Bit 9)                        */
#define ADC1_SQ_FB_EIM_ACTIVE_Msk         (0x200UL)                 /*!< ADC1 SQ_FB: EIM_ACTIVE (Bitfield-Mask: 0x01)          */
#define ADC1_SQ_FB_SQ_STOP_Pos            (8UL)                     /*!< ADC1 SQ_FB: SQ_STOP (Bit 8)                           */
#define ADC1_SQ_FB_SQ_STOP_Msk            (0x100UL)                 /*!< ADC1 SQ_FB: SQ_STOP (Bitfield-Mask: 0x01)             */
#define ADC1_SQ_FB_SQ_FB_Pos              (0UL)                     /*!< ADC1 SQ_FB: SQ_FB (Bit 0)                             */
#define ADC1_SQ_FB_SQ_FB_Msk              (0x1fUL)                  /*!< ADC1 SQ_FB: SQ_FB (Bitfield-Mask: 0x1f)               */
/* ========================================================  CHx_EIM  ======================================================== */
#define ADC1_CHx_EIM_ADC1_EIM_TRIG_SEL_Pos (16UL)                   /*!< ADC1 CHx_EIM: ADC1_EIM_TRIG_SEL (Bit 16)              */
#define ADC1_CHx_EIM_ADC1_EIM_TRIG_SEL_Msk (0x70000UL)              /*!< ADC1 CHx_EIM: ADC1_EIM_TRIG_SEL (Bitfield-Mask: 0x07) */
#define ADC1_CHx_EIM_EIM_EN_Pos           (11UL)                    /*!< ADC1 CHx_EIM: EIM_EN (Bit 11)                         */
#define ADC1_CHx_EIM_EIM_EN_Msk           (0x800UL)                 /*!< ADC1 CHx_EIM: EIM_EN (Bitfield-Mask: 0x01)            */
#define ADC1_CHx_EIM_EIM_REP_Pos          (8UL)                     /*!< ADC1 CHx_EIM: EIM_REP (Bit 8)                         */
#define ADC1_CHx_EIM_EIM_REP_Msk          (0x700UL)                 /*!< ADC1 CHx_EIM: EIM_REP (Bitfield-Mask: 0x07)           */
#define ADC1_CHx_EIM_EIM_CHx_Pos          (0UL)                     /*!< ADC1 CHx_EIM: EIM_CHx (Bit 0)                         */
#define ADC1_CHx_EIM_EIM_CHx_Msk          (0xfUL)                   /*!< ADC1 CHx_EIM: EIM_CHx (Bitfield-Mask: 0x0f)           */
/* ========================================================  CHx_ESM  ======================================================== */
#define ADC1_CHx_ESM_ESM_STS_Pos          (31UL)                    /*!< ADC1 CHx_ESM: ESM_STS (Bit 31)                        */
#define ADC1_CHx_ESM_ESM_STS_Msk          (0x80000000UL)            /*!< ADC1 CHx_ESM: ESM_STS (Bitfield-Mask: 0x01)           */
#define ADC1_CHx_ESM_ESM_EN_Pos           (30UL)                    /*!< ADC1 CHx_ESM: ESM_EN (Bit 30)                         */
#define ADC1_CHx_ESM_ESM_EN_Msk           (0x40000000UL)            /*!< ADC1 CHx_ESM: ESM_EN (Bitfield-Mask: 0x01)            */
#define ADC1_CHx_ESM_ADC1_ESM_TRIG_SEL_Pos (16UL)                   /*!< ADC1 CHx_ESM: ADC1_ESM_TRIG_SEL (Bit 16)              */
#define ADC1_CHx_ESM_ADC1_ESM_TRIG_SEL_Msk (0x70000UL)              /*!< ADC1 CHx_ESM: ADC1_ESM_TRIG_SEL (Bitfield-Mask: 0x07) */
#define ADC1_CHx_ESM_ESM_0_Pos            (0UL)                     /*!< ADC1 CHx_ESM: ESM_0 (Bit 0)                           */
#define ADC1_CHx_ESM_ESM_0_Msk            (0xfffUL)                 /*!< ADC1 CHx_ESM: ESM_0 (Bitfield-Mask: 0xfff)            */
/* =======================================================  MAX_TIME  ======================================================== */
#define ADC1_MAX_TIME_MAX_TIME_Pos        (0UL)                     /*!< ADC1 MAX_TIME: MAX_TIME (Bit 0)                       */
#define ADC1_MAX_TIME_MAX_TIME_Msk        (0xffUL)                  /*!< ADC1 MAX_TIME: MAX_TIME (Bitfield-Mask: 0xff)         */
/* =======================================================  CAL_CH0_1  ======================================================= */
#define ADC1_CAL_CH0_1_CALGAIN_CH1_Pos    (24UL)                    /*!< ADC1 CAL_CH0_1: CALGAIN_CH1 (Bit 24)                  */
#define ADC1_CAL_CH0_1_CALGAIN_CH1_Msk    (0xff000000UL)            /*!< ADC1 CAL_CH0_1: CALGAIN_CH1 (Bitfield-Mask: 0xff)     */
#define ADC1_CAL_CH0_1_CALOFFS_CH1_Pos    (16UL)                    /*!< ADC1 CAL_CH0_1: CALOFFS_CH1 (Bit 16)                  */
#define ADC1_CAL_CH0_1_CALOFFS_CH1_Msk    (0x1f0000UL)              /*!< ADC1 CAL_CH0_1: CALOFFS_CH1 (Bitfield-Mask: 0x1f)     */
#define ADC1_CAL_CH0_1_CALGAIN_CH0_Pos    (8UL)                     /*!< ADC1 CAL_CH0_1: CALGAIN_CH0 (Bit 8)                   */
#define ADC1_CAL_CH0_1_CALGAIN_CH0_Msk    (0xff00UL)                /*!< ADC1 CAL_CH0_1: CALGAIN_CH0 (Bitfield-Mask: 0xff)     */
#define ADC1_CAL_CH0_1_CALOFFS_CH0_Pos    (0UL)                     /*!< ADC1 CAL_CH0_1: CALOFFS_CH0 (Bit 0)                   */
#define ADC1_CAL_CH0_1_CALOFFS_CH0_Msk    (0x1fUL)                  /*!< ADC1 CAL_CH0_1: CALOFFS_CH0 (Bitfield-Mask: 0x1f)     */
/* =======================================================  CAL_CH2_3  ======================================================= */
#define ADC1_CAL_CH2_3_CALGAIN_CH3_Pos    (24UL)                    /*!< ADC1 CAL_CH2_3: CALGAIN_CH3 (Bit 24)                  */
#define ADC1_CAL_CH2_3_CALGAIN_CH3_Msk    (0xff000000UL)            /*!< ADC1 CAL_CH2_3: CALGAIN_CH3 (Bitfield-Mask: 0xff)     */
#define ADC1_CAL_CH2_3_CALOFFS_CH3_Pos    (16UL)                    /*!< ADC1 CAL_CH2_3: CALOFFS_CH3 (Bit 16)                  */
#define ADC1_CAL_CH2_3_CALOFFS_CH3_Msk    (0x1f0000UL)              /*!< ADC1 CAL_CH2_3: CALOFFS_CH3 (Bitfield-Mask: 0x1f)     */
#define ADC1_CAL_CH2_3_CALGAIN_CH2_Pos    (8UL)                     /*!< ADC1 CAL_CH2_3: CALGAIN_CH2 (Bit 8)                   */
#define ADC1_CAL_CH2_3_CALGAIN_CH2_Msk    (0xff00UL)                /*!< ADC1 CAL_CH2_3: CALGAIN_CH2 (Bitfield-Mask: 0xff)     */
#define ADC1_CAL_CH2_3_CALOFFS_CH2_Pos    (0UL)                     /*!< ADC1 CAL_CH2_3: CALOFFS_CH2 (Bit 0)                   */
#define ADC1_CAL_CH2_3_CALOFFS_CH2_Msk    (0x1fUL)                  /*!< ADC1 CAL_CH2_3: CALOFFS_CH2 (Bitfield-Mask: 0x1f)     */
/* =======================================================  CAL_CH4_5  ======================================================= */
#define ADC1_CAL_CH4_5_CALGAIN_CH5_Pos    (24UL)                    /*!< ADC1 CAL_CH4_5: CALGAIN_CH5 (Bit 24)                  */
#define ADC1_CAL_CH4_5_CALGAIN_CH5_Msk    (0xff000000UL)            /*!< ADC1 CAL_CH4_5: CALGAIN_CH5 (Bitfield-Mask: 0xff)     */
#define ADC1_CAL_CH4_5_CALOFFS_CH5_Pos    (16UL)                    /*!< ADC1 CAL_CH4_5: CALOFFS_CH5 (Bit 16)                  */
#define ADC1_CAL_CH4_5_CALOFFS_CH5_Msk    (0x1f0000UL)              /*!< ADC1 CAL_CH4_5: CALOFFS_CH5 (Bitfield-Mask: 0x1f)     */
#define ADC1_CAL_CH4_5_CALGAIN_CH4_Pos    (8UL)                     /*!< ADC1 CAL_CH4_5: CALGAIN_CH4 (Bit 8)                   */
#define ADC1_CAL_CH4_5_CALGAIN_CH4_Msk    (0xff00UL)                /*!< ADC1 CAL_CH4_5: CALGAIN_CH4 (Bitfield-Mask: 0xff)     */
#define ADC1_CAL_CH4_5_CALOFFS_CH4_Pos    (0UL)                     /*!< ADC1 CAL_CH4_5: CALOFFS_CH4 (Bit 0)                   */
#define ADC1_CAL_CH4_5_CALOFFS_CH4_Msk    (0x1fUL)                  /*!< ADC1 CAL_CH4_5: CALOFFS_CH4 (Bitfield-Mask: 0x1f)     */
/* =======================================================  CAL_CH6_7  ======================================================= */
#define ADC1_CAL_CH6_7_CALGAIN_CH7_Pos    (24UL)                    /*!< ADC1 CAL_CH6_7: CALGAIN_CH7 (Bit 24)                  */
#define ADC1_CAL_CH6_7_CALGAIN_CH7_Msk    (0xff000000UL)            /*!< ADC1 CAL_CH6_7: CALGAIN_CH7 (Bitfield-Mask: 0xff)     */
#define ADC1_CAL_CH6_7_CALOFFS_CH7_Pos    (16UL)                    /*!< ADC1 CAL_CH6_7: CALOFFS_CH7 (Bit 16)                  */
#define ADC1_CAL_CH6_7_CALOFFS_CH7_Msk    (0x1f0000UL)              /*!< ADC1 CAL_CH6_7: CALOFFS_CH7 (Bitfield-Mask: 0x1f)     */
#define ADC1_CAL_CH6_7_CALGAIN_CH6_Pos    (8UL)                     /*!< ADC1 CAL_CH6_7: CALGAIN_CH6 (Bit 8)                   */
#define ADC1_CAL_CH6_7_CALGAIN_CH6_Msk    (0xff00UL)                /*!< ADC1 CAL_CH6_7: CALGAIN_CH6 (Bitfield-Mask: 0xff)     */
#define ADC1_CAL_CH6_7_CALOFFS_CH6_Pos    (0UL)                     /*!< ADC1 CAL_CH6_7: CALOFFS_CH6 (Bit 0)                   */
#define ADC1_CAL_CH6_7_CALOFFS_CH6_Msk    (0x1fUL)                  /*!< ADC1 CAL_CH6_7: CALOFFS_CH6 (Bitfield-Mask: 0x1f)     */
/* =======================================================  CAL_CH8_9  ======================================================= */
#define ADC1_CAL_CH8_9_CALGAIN_CH9_Pos    (24UL)                    /*!< ADC1 CAL_CH8_9: CALGAIN_CH9 (Bit 24)                  */
#define ADC1_CAL_CH8_9_CALGAIN_CH9_Msk    (0xff000000UL)            /*!< ADC1 CAL_CH8_9: CALGAIN_CH9 (Bitfield-Mask: 0xff)     */
#define ADC1_CAL_CH8_9_CALOFFS_CH9_Pos    (16UL)                    /*!< ADC1 CAL_CH8_9: CALOFFS_CH9 (Bit 16)                  */
#define ADC1_CAL_CH8_9_CALOFFS_CH9_Msk    (0x1f0000UL)              /*!< ADC1 CAL_CH8_9: CALOFFS_CH9 (Bitfield-Mask: 0x1f)     */
#define ADC1_CAL_CH8_9_CALGAIN_CH8_Pos    (8UL)                     /*!< ADC1 CAL_CH8_9: CALGAIN_CH8 (Bit 8)                   */
#define ADC1_CAL_CH8_9_CALGAIN_CH8_Msk    (0xff00UL)                /*!< ADC1 CAL_CH8_9: CALGAIN_CH8 (Bitfield-Mask: 0xff)     */
#define ADC1_CAL_CH8_9_CALOFFS_CH8_Pos    (0UL)                     /*!< ADC1 CAL_CH8_9: CALOFFS_CH8 (Bit 0)                   */
#define ADC1_CAL_CH8_9_CALOFFS_CH8_Msk    (0x1fUL)                  /*!< ADC1 CAL_CH8_9: CALOFFS_CH8 (Bitfield-Mask: 0x1f)     */
/* ======================================================  CAL_CH10_11  ====================================================== */
#define ADC1_CAL_CH10_11_CALGAIN_CH11_Pos (24UL)                    /*!< ADC1 CAL_CH10_11: CALGAIN_CH11 (Bit 24)               */
#define ADC1_CAL_CH10_11_CALGAIN_CH11_Msk (0xff000000UL)            /*!< ADC1 CAL_CH10_11: CALGAIN_CH11 (Bitfield-Mask: 0xff)  */
#define ADC1_CAL_CH10_11_CALOFFS_CH11_Pos (16UL)                    /*!< ADC1 CAL_CH10_11: CALOFFS_CH11 (Bit 16)               */
#define ADC1_CAL_CH10_11_CALOFFS_CH11_Msk (0x1f0000UL)              /*!< ADC1 CAL_CH10_11: CALOFFS_CH11 (Bitfield-Mask: 0x1f)  */
#define ADC1_CAL_CH10_11_CALGAIN_CH10_Pos (8UL)                     /*!< ADC1 CAL_CH10_11: CALGAIN_CH10 (Bit 8)                */
#define ADC1_CAL_CH10_11_CALGAIN_CH10_Msk (0xff00UL)                /*!< ADC1 CAL_CH10_11: CALGAIN_CH10 (Bitfield-Mask: 0xff)  */
#define ADC1_CAL_CH10_11_CALOFFS_CH10_Pos (0UL)                     /*!< ADC1 CAL_CH10_11: CALOFFS_CH10 (Bit 0)                */
#define ADC1_CAL_CH10_11_CALOFFS_CH10_Msk (0x1fUL)                  /*!< ADC1 CAL_CH10_11: CALOFFS_CH10 (Bitfield-Mask: 0x1f)  */
/* =====================================================  FILTCOEFF0_11  ===================================================== */
#define ADC1_FILTCOEFF0_11_CH11_Pos       (22UL)                    /*!< ADC1 FILTCOEFF0_11: CH11 (Bit 22)                     */
#define ADC1_FILTCOEFF0_11_CH11_Msk       (0xc00000UL)              /*!< ADC1 FILTCOEFF0_11: CH11 (Bitfield-Mask: 0x03)        */
#define ADC1_FILTCOEFF0_11_CH10_Pos       (20UL)                    /*!< ADC1 FILTCOEFF0_11: CH10 (Bit 20)                     */
#define ADC1_FILTCOEFF0_11_CH10_Msk       (0x300000UL)              /*!< ADC1 FILTCOEFF0_11: CH10 (Bitfield-Mask: 0x03)        */
#define ADC1_FILTCOEFF0_11_CH9_Pos        (18UL)                    /*!< ADC1 FILTCOEFF0_11: CH9 (Bit 18)                      */
#define ADC1_FILTCOEFF0_11_CH9_Msk        (0xc0000UL)               /*!< ADC1 FILTCOEFF0_11: CH9 (Bitfield-Mask: 0x03)         */
#define ADC1_FILTCOEFF0_11_CH8_Pos        (16UL)                    /*!< ADC1 FILTCOEFF0_11: CH8 (Bit 16)                      */
#define ADC1_FILTCOEFF0_11_CH8_Msk        (0x30000UL)               /*!< ADC1 FILTCOEFF0_11: CH8 (Bitfield-Mask: 0x03)         */
#define ADC1_FILTCOEFF0_11_CH7_Pos        (14UL)                    /*!< ADC1 FILTCOEFF0_11: CH7 (Bit 14)                      */
#define ADC1_FILTCOEFF0_11_CH7_Msk        (0xc000UL)                /*!< ADC1 FILTCOEFF0_11: CH7 (Bitfield-Mask: 0x03)         */
#define ADC1_FILTCOEFF0_11_CH6_Pos        (12UL)                    /*!< ADC1 FILTCOEFF0_11: CH6 (Bit 12)                      */
#define ADC1_FILTCOEFF0_11_CH6_Msk        (0x3000UL)                /*!< ADC1 FILTCOEFF0_11: CH6 (Bitfield-Mask: 0x03)         */
#define ADC1_FILTCOEFF0_11_CH5_Pos        (10UL)                    /*!< ADC1 FILTCOEFF0_11: CH5 (Bit 10)                      */
#define ADC1_FILTCOEFF0_11_CH5_Msk        (0xc00UL)                 /*!< ADC1 FILTCOEFF0_11: CH5 (Bitfield-Mask: 0x03)         */
#define ADC1_FILTCOEFF0_11_CH4_Pos        (8UL)                     /*!< ADC1 FILTCOEFF0_11: CH4 (Bit 8)                       */
#define ADC1_FILTCOEFF0_11_CH4_Msk        (0x300UL)                 /*!< ADC1 FILTCOEFF0_11: CH4 (Bitfield-Mask: 0x03)         */
#define ADC1_FILTCOEFF0_11_CH3_Pos        (6UL)                     /*!< ADC1 FILTCOEFF0_11: CH3 (Bit 6)                       */
#define ADC1_FILTCOEFF0_11_CH3_Msk        (0xc0UL)                  /*!< ADC1 FILTCOEFF0_11: CH3 (Bitfield-Mask: 0x03)         */
#define ADC1_FILTCOEFF0_11_CH2_Pos        (4UL)                     /*!< ADC1 FILTCOEFF0_11: CH2 (Bit 4)                       */
#define ADC1_FILTCOEFF0_11_CH2_Msk        (0x30UL)                  /*!< ADC1 FILTCOEFF0_11: CH2 (Bitfield-Mask: 0x03)         */
#define ADC1_FILTCOEFF0_11_CH1_Pos        (2UL)                     /*!< ADC1 FILTCOEFF0_11: CH1 (Bit 2)                       */
#define ADC1_FILTCOEFF0_11_CH1_Msk        (0xcUL)                   /*!< ADC1 FILTCOEFF0_11: CH1 (Bitfield-Mask: 0x03)         */
#define ADC1_FILTCOEFF0_11_CH0_Pos        (0UL)                     /*!< ADC1 FILTCOEFF0_11: CH0 (Bit 0)                       */
#define ADC1_FILTCOEFF0_11_CH0_Msk        (0x3UL)                   /*!< ADC1 FILTCOEFF0_11: CH0 (Bitfield-Mask: 0x03)         */
/* =======================================================  FILT_OUT0  ======================================================= */
#define ADC1_FILT_OUT0_OF0_Pos            (18UL)                    /*!< ADC1 FILT_OUT0: OF0 (Bit 18)                          */
#define ADC1_FILT_OUT0_OF0_Msk            (0x40000UL)               /*!< ADC1 FILT_OUT0: OF0 (Bitfield-Mask: 0x01)             */
#define ADC1_FILT_OUT0_VF0_Pos            (17UL)                    /*!< ADC1 FILT_OUT0: VF0 (Bit 17)                          */
#define ADC1_FILT_OUT0_VF0_Msk            (0x20000UL)               /*!< ADC1 FILT_OUT0: VF0 (Bitfield-Mask: 0x01)             */
#define ADC1_FILT_OUT0_WFR0_Pos           (16UL)                    /*!< ADC1 FILT_OUT0: WFR0 (Bit 16)                         */
#define ADC1_FILT_OUT0_WFR0_Msk           (0x10000UL)               /*!< ADC1 FILT_OUT0: WFR0 (Bitfield-Mask: 0x01)            */
#define ADC1_FILT_OUT0_FILT_OUT_CH0_Pos   (0UL)                     /*!< ADC1 FILT_OUT0: FILT_OUT_CH0 (Bit 0)                  */
#define ADC1_FILT_OUT0_FILT_OUT_CH0_Msk   (0xfffUL)                 /*!< ADC1 FILT_OUT0: FILT_OUT_CH0 (Bitfield-Mask: 0xfff)   */
/* =======================================================  FILT_OUT1  ======================================================= */
#define ADC1_FILT_OUT1_OF1_Pos            (18UL)                    /*!< ADC1 FILT_OUT1: OF1 (Bit 18)                          */
#define ADC1_FILT_OUT1_OF1_Msk            (0x40000UL)               /*!< ADC1 FILT_OUT1: OF1 (Bitfield-Mask: 0x01)             */
#define ADC1_FILT_OUT1_VF1_Pos            (17UL)                    /*!< ADC1 FILT_OUT1: VF1 (Bit 17)                          */
#define ADC1_FILT_OUT1_VF1_Msk            (0x20000UL)               /*!< ADC1 FILT_OUT1: VF1 (Bitfield-Mask: 0x01)             */
#define ADC1_FILT_OUT1_WFR1_Pos           (16UL)                    /*!< ADC1 FILT_OUT1: WFR1 (Bit 16)                         */
#define ADC1_FILT_OUT1_WFR1_Msk           (0x10000UL)               /*!< ADC1 FILT_OUT1: WFR1 (Bitfield-Mask: 0x01)            */
#define ADC1_FILT_OUT1_FILT_OUT_CH1_Pos   (0UL)                     /*!< ADC1 FILT_OUT1: FILT_OUT_CH1 (Bit 0)                  */
#define ADC1_FILT_OUT1_FILT_OUT_CH1_Msk   (0xfffUL)                 /*!< ADC1 FILT_OUT1: FILT_OUT_CH1 (Bitfield-Mask: 0xfff)   */
/* =======================================================  FILT_OUT2  ======================================================= */
#define ADC1_FILT_OUT2_OF2_Pos            (18UL)                    /*!< ADC1 FILT_OUT2: OF2 (Bit 18)                          */
#define ADC1_FILT_OUT2_OF2_Msk            (0x40000UL)               /*!< ADC1 FILT_OUT2: OF2 (Bitfield-Mask: 0x01)             */
#define ADC1_FILT_OUT2_VF2_Pos            (17UL)                    /*!< ADC1 FILT_OUT2: VF2 (Bit 17)                          */
#define ADC1_FILT_OUT2_VF2_Msk            (0x20000UL)               /*!< ADC1 FILT_OUT2: VF2 (Bitfield-Mask: 0x01)             */
#define ADC1_FILT_OUT2_WFR2_Pos           (16UL)                    /*!< ADC1 FILT_OUT2: WFR2 (Bit 16)                         */
#define ADC1_FILT_OUT2_WFR2_Msk           (0x10000UL)               /*!< ADC1 FILT_OUT2: WFR2 (Bitfield-Mask: 0x01)            */
#define ADC1_FILT_OUT2_FILT_OUT_CH2_Pos   (0UL)                     /*!< ADC1 FILT_OUT2: FILT_OUT_CH2 (Bit 0)                  */
#define ADC1_FILT_OUT2_FILT_OUT_CH2_Msk   (0xfffUL)                 /*!< ADC1 FILT_OUT2: FILT_OUT_CH2 (Bitfield-Mask: 0xfff)   */
/* =======================================================  FILT_OUT3  ======================================================= */
#define ADC1_FILT_OUT3_OF3_Pos            (18UL)                    /*!< ADC1 FILT_OUT3: OF3 (Bit 18)                          */
#define ADC1_FILT_OUT3_OF3_Msk            (0x40000UL)               /*!< ADC1 FILT_OUT3: OF3 (Bitfield-Mask: 0x01)             */
#define ADC1_FILT_OUT3_VF3_Pos            (17UL)                    /*!< ADC1 FILT_OUT3: VF3 (Bit 17)                          */
#define ADC1_FILT_OUT3_VF3_Msk            (0x20000UL)               /*!< ADC1 FILT_OUT3: VF3 (Bitfield-Mask: 0x01)             */
#define ADC1_FILT_OUT3_WFR3_Pos           (16UL)                    /*!< ADC1 FILT_OUT3: WFR3 (Bit 16)                         */
#define ADC1_FILT_OUT3_WFR3_Msk           (0x10000UL)               /*!< ADC1 FILT_OUT3: WFR3 (Bitfield-Mask: 0x01)            */
#define ADC1_FILT_OUT3_FILT_OUT_CH3_Pos   (0UL)                     /*!< ADC1 FILT_OUT3: FILT_OUT_CH3 (Bit 0)                  */
#define ADC1_FILT_OUT3_FILT_OUT_CH3_Msk   (0xfffUL)                 /*!< ADC1 FILT_OUT3: FILT_OUT_CH3 (Bitfield-Mask: 0xfff)   */
/* =======================================================  FILT_OUT4  ======================================================= */
#define ADC1_FILT_OUT4_OF4_Pos            (18UL)                    /*!< ADC1 FILT_OUT4: OF4 (Bit 18)                          */
#define ADC1_FILT_OUT4_OF4_Msk            (0x40000UL)               /*!< ADC1 FILT_OUT4: OF4 (Bitfield-Mask: 0x01)             */
#define ADC1_FILT_OUT4_VF4_Pos            (17UL)                    /*!< ADC1 FILT_OUT4: VF4 (Bit 17)                          */
#define ADC1_FILT_OUT4_VF4_Msk            (0x20000UL)               /*!< ADC1 FILT_OUT4: VF4 (Bitfield-Mask: 0x01)             */
#define ADC1_FILT_OUT4_WFR4_Pos           (16UL)                    /*!< ADC1 FILT_OUT4: WFR4 (Bit 16)                         */
#define ADC1_FILT_OUT4_WFR4_Msk           (0x10000UL)               /*!< ADC1 FILT_OUT4: WFR4 (Bitfield-Mask: 0x01)            */
#define ADC1_FILT_OUT4_FILT_OUT_CH4_Pos   (0UL)                     /*!< ADC1 FILT_OUT4: FILT_OUT_CH4 (Bit 0)                  */
#define ADC1_FILT_OUT4_FILT_OUT_CH4_Msk   (0xfffUL)                 /*!< ADC1 FILT_OUT4: FILT_OUT_CH4 (Bitfield-Mask: 0xfff)   */
/* =======================================================  FILT_OUT5  ======================================================= */
#define ADC1_FILT_OUT5_OF5_Pos            (18UL)                    /*!< ADC1 FILT_OUT5: OF5 (Bit 18)                          */
#define ADC1_FILT_OUT5_OF5_Msk            (0x40000UL)               /*!< ADC1 FILT_OUT5: OF5 (Bitfield-Mask: 0x01)             */
#define ADC1_FILT_OUT5_VF5_Pos            (17UL)                    /*!< ADC1 FILT_OUT5: VF5 (Bit 17)                          */
#define ADC1_FILT_OUT5_VF5_Msk            (0x20000UL)               /*!< ADC1 FILT_OUT5: VF5 (Bitfield-Mask: 0x01)             */
#define ADC1_FILT_OUT5_WFR5_Pos           (16UL)                    /*!< ADC1 FILT_OUT5: WFR5 (Bit 16)                         */
#define ADC1_FILT_OUT5_WFR5_Msk           (0x10000UL)               /*!< ADC1 FILT_OUT5: WFR5 (Bitfield-Mask: 0x01)            */
#define ADC1_FILT_OUT5_FILT_OUT_CH5_Pos   (0UL)                     /*!< ADC1 FILT_OUT5: FILT_OUT_CH5 (Bit 0)                  */
#define ADC1_FILT_OUT5_FILT_OUT_CH5_Msk   (0xfffUL)                 /*!< ADC1 FILT_OUT5: FILT_OUT_CH5 (Bitfield-Mask: 0xfff)   */
/* =======================================================  FILT_OUT6  ======================================================= */
#define ADC1_FILT_OUT6_OF6_Pos            (18UL)                    /*!< ADC1 FILT_OUT6: OF6 (Bit 18)                          */
#define ADC1_FILT_OUT6_OF6_Msk            (0x40000UL)               /*!< ADC1 FILT_OUT6: OF6 (Bitfield-Mask: 0x01)             */
#define ADC1_FILT_OUT6_VF6_Pos            (17UL)                    /*!< ADC1 FILT_OUT6: VF6 (Bit 17)                          */
#define ADC1_FILT_OUT6_VF6_Msk            (0x20000UL)               /*!< ADC1 FILT_OUT6: VF6 (Bitfield-Mask: 0x01)             */
#define ADC1_FILT_OUT6_WFR6_Pos           (16UL)                    /*!< ADC1 FILT_OUT6: WFR6 (Bit 16)                         */
#define ADC1_FILT_OUT6_WFR6_Msk           (0x10000UL)               /*!< ADC1 FILT_OUT6: WFR6 (Bitfield-Mask: 0x01)            */
#define ADC1_FILT_OUT6_FILT_OUT_CH6_Pos   (0UL)                     /*!< ADC1 FILT_OUT6: FILT_OUT_CH6 (Bit 0)                  */
#define ADC1_FILT_OUT6_FILT_OUT_CH6_Msk   (0xfffUL)                 /*!< ADC1 FILT_OUT6: FILT_OUT_CH6 (Bitfield-Mask: 0xfff)   */
/* =======================================================  FILT_OUT7  ======================================================= */
#define ADC1_FILT_OUT7_OF7_Pos            (18UL)                    /*!< ADC1 FILT_OUT7: OF7 (Bit 18)                          */
#define ADC1_FILT_OUT7_OF7_Msk            (0x40000UL)               /*!< ADC1 FILT_OUT7: OF7 (Bitfield-Mask: 0x01)             */
#define ADC1_FILT_OUT7_VF7_Pos            (17UL)                    /*!< ADC1 FILT_OUT7: VF7 (Bit 17)                          */
#define ADC1_FILT_OUT7_VF7_Msk            (0x20000UL)               /*!< ADC1 FILT_OUT7: VF7 (Bitfield-Mask: 0x01)             */
#define ADC1_FILT_OUT7_WFR7_Pos           (16UL)                    /*!< ADC1 FILT_OUT7: WFR7 (Bit 16)                         */
#define ADC1_FILT_OUT7_WFR7_Msk           (0x10000UL)               /*!< ADC1 FILT_OUT7: WFR7 (Bitfield-Mask: 0x01)            */
#define ADC1_FILT_OUT7_FILT_OUT_CH7_Pos   (0UL)                     /*!< ADC1 FILT_OUT7: FILT_OUT_CH7 (Bit 0)                  */
#define ADC1_FILT_OUT7_FILT_OUT_CH7_Msk   (0xfffUL)                 /*!< ADC1 FILT_OUT7: FILT_OUT_CH7 (Bitfield-Mask: 0xfff)   */
/* =======================================================  FILT_OUT8  ======================================================= */
#define ADC1_FILT_OUT8_OF8_Pos            (18UL)                    /*!< ADC1 FILT_OUT8: OF8 (Bit 18)                          */
#define ADC1_FILT_OUT8_OF8_Msk            (0x40000UL)               /*!< ADC1 FILT_OUT8: OF8 (Bitfield-Mask: 0x01)             */
#define ADC1_FILT_OUT8_VF8_Pos            (17UL)                    /*!< ADC1 FILT_OUT8: VF8 (Bit 17)                          */
#define ADC1_FILT_OUT8_VF8_Msk            (0x20000UL)               /*!< ADC1 FILT_OUT8: VF8 (Bitfield-Mask: 0x01)             */
#define ADC1_FILT_OUT8_WFR8_Pos           (16UL)                    /*!< ADC1 FILT_OUT8: WFR8 (Bit 16)                         */
#define ADC1_FILT_OUT8_WFR8_Msk           (0x10000UL)               /*!< ADC1 FILT_OUT8: WFR8 (Bitfield-Mask: 0x01)            */
#define ADC1_FILT_OUT8_FILT_OUT_CH8_Pos   (0UL)                     /*!< ADC1 FILT_OUT8: FILT_OUT_CH8 (Bit 0)                  */
#define ADC1_FILT_OUT8_FILT_OUT_CH8_Msk   (0xfffUL)                 /*!< ADC1 FILT_OUT8: FILT_OUT_CH8 (Bitfield-Mask: 0xfff)   */
/* =======================================================  FILT_OUT9  ======================================================= */
#define ADC1_FILT_OUT9_OF9_Pos            (18UL)                    /*!< ADC1 FILT_OUT9: OF9 (Bit 18)                          */
#define ADC1_FILT_OUT9_OF9_Msk            (0x40000UL)               /*!< ADC1 FILT_OUT9: OF9 (Bitfield-Mask: 0x01)             */
#define ADC1_FILT_OUT9_VF9_Pos            (17UL)                    /*!< ADC1 FILT_OUT9: VF9 (Bit 17)                          */
#define ADC1_FILT_OUT9_VF9_Msk            (0x20000UL)               /*!< ADC1 FILT_OUT9: VF9 (Bitfield-Mask: 0x01)             */
#define ADC1_FILT_OUT9_WFR9_Pos           (16UL)                    /*!< ADC1 FILT_OUT9: WFR9 (Bit 16)                         */
#define ADC1_FILT_OUT9_WFR9_Msk           (0x10000UL)               /*!< ADC1 FILT_OUT9: WFR9 (Bitfield-Mask: 0x01)            */
#define ADC1_FILT_OUT9_FILT_OUT_CH9_Pos   (0UL)                     /*!< ADC1 FILT_OUT9: FILT_OUT_CH9 (Bit 0)                  */
#define ADC1_FILT_OUT9_FILT_OUT_CH9_Msk   (0xfffUL)                 /*!< ADC1 FILT_OUT9: FILT_OUT_CH9 (Bitfield-Mask: 0xfff)   */
/* ======================================================  FILT_OUT10  ======================================================= */
#define ADC1_FILT_OUT10_OF10_Pos          (18UL)                    /*!< ADC1 FILT_OUT10: OF10 (Bit 18)                        */
#define ADC1_FILT_OUT10_OF10_Msk          (0x40000UL)               /*!< ADC1 FILT_OUT10: OF10 (Bitfield-Mask: 0x01)           */
#define ADC1_FILT_OUT10_VF10_Pos          (17UL)                    /*!< ADC1 FILT_OUT10: VF10 (Bit 17)                        */
#define ADC1_FILT_OUT10_VF10_Msk          (0x20000UL)               /*!< ADC1 FILT_OUT10: VF10 (Bitfield-Mask: 0x01)           */
#define ADC1_FILT_OUT10_WFR10_Pos         (16UL)                    /*!< ADC1 FILT_OUT10: WFR10 (Bit 16)                       */
#define ADC1_FILT_OUT10_WFR10_Msk         (0x10000UL)               /*!< ADC1 FILT_OUT10: WFR10 (Bitfield-Mask: 0x01)          */
#define ADC1_FILT_OUT10_FILT_OUT_CH10_Pos (0UL)                     /*!< ADC1 FILT_OUT10: FILT_OUT_CH10 (Bit 0)                */
#define ADC1_FILT_OUT10_FILT_OUT_CH10_Msk (0xfffUL)                 /*!< ADC1 FILT_OUT10: FILT_OUT_CH10 (Bitfield-Mask: 0xfff) */
/* ======================================================  FILT_OUT11  ======================================================= */
#define ADC1_FILT_OUT11_OF11_Pos          (18UL)                    /*!< ADC1 FILT_OUT11: OF11 (Bit 18)                        */
#define ADC1_FILT_OUT11_OF11_Msk          (0x40000UL)               /*!< ADC1 FILT_OUT11: OF11 (Bitfield-Mask: 0x01)           */
#define ADC1_FILT_OUT11_VF11_Pos          (17UL)                    /*!< ADC1 FILT_OUT11: VF11 (Bit 17)                        */
#define ADC1_FILT_OUT11_VF11_Msk          (0x20000UL)               /*!< ADC1 FILT_OUT11: VF11 (Bitfield-Mask: 0x01)           */
#define ADC1_FILT_OUT11_WFR11_Pos         (16UL)                    /*!< ADC1 FILT_OUT11: WFR11 (Bit 16)                       */
#define ADC1_FILT_OUT11_WFR11_Msk         (0x10000UL)               /*!< ADC1 FILT_OUT11: WFR11 (Bitfield-Mask: 0x01)          */
#define ADC1_FILT_OUT11_FILT_OUT_CH11_Pos (0UL)                     /*!< ADC1 FILT_OUT11: FILT_OUT_CH11 (Bit 0)                */
#define ADC1_FILT_OUT11_FILT_OUT_CH11_Msk (0xfffUL)                 /*!< ADC1 FILT_OUT11: FILT_OUT_CH11 (Bitfield-Mask: 0xfff) */
/* ======================================================  FILT_OUT12  ======================================================= */
#define ADC1_FILT_OUT12_OF12_Pos          (18UL)                    /*!< ADC1 FILT_OUT12: OF12 (Bit 18)                        */
#define ADC1_FILT_OUT12_OF12_Msk          (0x40000UL)               /*!< ADC1 FILT_OUT12: OF12 (Bitfield-Mask: 0x01)           */
#define ADC1_FILT_OUT12_VF12_Pos          (17UL)                    /*!< ADC1 FILT_OUT12: VF12 (Bit 17)                        */
#define ADC1_FILT_OUT12_VF12_Msk          (0x20000UL)               /*!< ADC1 FILT_OUT12: VF12 (Bitfield-Mask: 0x01)           */
#define ADC1_FILT_OUT12_WFR12_Pos         (16UL)                    /*!< ADC1 FILT_OUT12: WFR12 (Bit 16)                       */
#define ADC1_FILT_OUT12_WFR12_Msk         (0x10000UL)               /*!< ADC1 FILT_OUT12: WFR12 (Bitfield-Mask: 0x01)          */
#define ADC1_FILT_OUT12_FILT_OUT_CH12_Pos (0UL)                     /*!< ADC1 FILT_OUT12: FILT_OUT_CH12 (Bit 0)                */
#define ADC1_FILT_OUT12_FILT_OUT_CH12_Msk (0xfffUL)                 /*!< ADC1 FILT_OUT12: FILT_OUT_CH12 (Bitfield-Mask: 0xfff) */
/* ======================================================  FILT_OUTEIM  ====================================================== */
#define ADC1_FILT_OUTEIM_OF_EIM_Pos       (18UL)                    /*!< ADC1 FILT_OUTEIM: OF_EIM (Bit 18)                     */
#define ADC1_FILT_OUTEIM_OF_EIM_Msk       (0x40000UL)               /*!< ADC1 FILT_OUTEIM: OF_EIM (Bitfield-Mask: 0x01)        */
#define ADC1_FILT_OUTEIM_VF_EIM_Pos       (17UL)                    /*!< ADC1 FILT_OUTEIM: VF_EIM (Bit 17)                     */
#define ADC1_FILT_OUTEIM_VF_EIM_Msk       (0x20000UL)               /*!< ADC1 FILT_OUTEIM: VF_EIM (Bitfield-Mask: 0x01)        */
#define ADC1_FILT_OUTEIM_WFR_EIM_Pos      (16UL)                    /*!< ADC1 FILT_OUTEIM: WFR_EIM (Bit 16)                    */
#define ADC1_FILT_OUTEIM_WFR_EIM_Msk      (0x10000UL)               /*!< ADC1 FILT_OUTEIM: WFR_EIM (Bitfield-Mask: 0x01)       */
#define ADC1_FILT_OUTEIM_FILT_OUT_EIM_Pos (0UL)                     /*!< ADC1 FILT_OUTEIM: FILT_OUT_EIM (Bit 0)                */
#define ADC1_FILT_OUTEIM_FILT_OUT_EIM_Msk (0xfffUL)                 /*!< ADC1 FILT_OUTEIM: FILT_OUT_EIM (Bitfield-Mask: 0xfff) */
/* ======================================================  DIFFCH_OUT1  ====================================================== */
#define ADC1_DIFFCH_OUT1_DOF1_Pos         (18UL)                    /*!< ADC1 DIFFCH_OUT1: DOF1 (Bit 18)                       */
#define ADC1_DIFFCH_OUT1_DOF1_Msk         (0x40000UL)               /*!< ADC1 DIFFCH_OUT1: DOF1 (Bitfield-Mask: 0x01)          */
#define ADC1_DIFFCH_OUT1_DVF1_Pos         (17UL)                    /*!< ADC1 DIFFCH_OUT1: DVF1 (Bit 17)                       */
#define ADC1_DIFFCH_OUT1_DVF1_Msk         (0x20000UL)               /*!< ADC1 DIFFCH_OUT1: DVF1 (Bitfield-Mask: 0x01)          */
#define ADC1_DIFFCH_OUT1_DWFR1_Pos        (16UL)                    /*!< ADC1 DIFFCH_OUT1: DWFR1 (Bit 16)                      */
#define ADC1_DIFFCH_OUT1_DWFR1_Msk        (0x10000UL)               /*!< ADC1 DIFFCH_OUT1: DWFR1 (Bitfield-Mask: 0x01)         */
#define ADC1_DIFFCH_OUT1_DCH1_Pos         (0UL)                     /*!< ADC1 DIFFCH_OUT1: DCH1 (Bit 0)                        */
#define ADC1_DIFFCH_OUT1_DCH1_Msk         (0xfffUL)                 /*!< ADC1 DIFFCH_OUT1: DCH1 (Bitfield-Mask: 0xfff)         */
/* ======================================================  DIFFCH_OUT2  ====================================================== */
#define ADC1_DIFFCH_OUT2_DOF2_Pos         (18UL)                    /*!< ADC1 DIFFCH_OUT2: DOF2 (Bit 18)                       */
#define ADC1_DIFFCH_OUT2_DOF2_Msk         (0x40000UL)               /*!< ADC1 DIFFCH_OUT2: DOF2 (Bitfield-Mask: 0x01)          */
#define ADC1_DIFFCH_OUT2_DVF2_Pos         (17UL)                    /*!< ADC1 DIFFCH_OUT2: DVF2 (Bit 17)                       */
#define ADC1_DIFFCH_OUT2_DVF2_Msk         (0x20000UL)               /*!< ADC1 DIFFCH_OUT2: DVF2 (Bitfield-Mask: 0x01)          */
#define ADC1_DIFFCH_OUT2_DWFR2_Pos        (16UL)                    /*!< ADC1 DIFFCH_OUT2: DWFR2 (Bit 16)                      */
#define ADC1_DIFFCH_OUT2_DWFR2_Msk        (0x10000UL)               /*!< ADC1 DIFFCH_OUT2: DWFR2 (Bitfield-Mask: 0x01)         */
#define ADC1_DIFFCH_OUT2_DCH2_Pos         (0UL)                     /*!< ADC1 DIFFCH_OUT2: DCH2 (Bit 0)                        */
#define ADC1_DIFFCH_OUT2_DCH2_Msk         (0xfffUL)                 /*!< ADC1 DIFFCH_OUT2: DCH2 (Bitfield-Mask: 0xfff)         */
/* ======================================================  DIFFCH_OUT3  ====================================================== */
#define ADC1_DIFFCH_OUT3_DOF3_Pos         (18UL)                    /*!< ADC1 DIFFCH_OUT3: DOF3 (Bit 18)                       */
#define ADC1_DIFFCH_OUT3_DOF3_Msk         (0x40000UL)               /*!< ADC1 DIFFCH_OUT3: DOF3 (Bitfield-Mask: 0x01)          */
#define ADC1_DIFFCH_OUT3_DVF3_Pos         (17UL)                    /*!< ADC1 DIFFCH_OUT3: DVF3 (Bit 17)                       */
#define ADC1_DIFFCH_OUT3_DVF3_Msk         (0x20000UL)               /*!< ADC1 DIFFCH_OUT3: DVF3 (Bitfield-Mask: 0x01)          */
#define ADC1_DIFFCH_OUT3_DWFR3_Pos        (16UL)                    /*!< ADC1 DIFFCH_OUT3: DWFR3 (Bit 16)                      */
#define ADC1_DIFFCH_OUT3_DWFR3_Msk        (0x10000UL)               /*!< ADC1 DIFFCH_OUT3: DWFR3 (Bitfield-Mask: 0x01)         */
#define ADC1_DIFFCH_OUT3_DCH3_Pos         (0UL)                     /*!< ADC1 DIFFCH_OUT3: DCH3 (Bit 0)                        */
#define ADC1_DIFFCH_OUT3_DCH3_Msk         (0xfffUL)                 /*!< ADC1 DIFFCH_OUT3: DCH3 (Bitfield-Mask: 0xfff)         */
/* ======================================================  DIFFCH_OUT4  ====================================================== */
#define ADC1_DIFFCH_OUT4_DOF4_Pos         (18UL)                    /*!< ADC1 DIFFCH_OUT4: DOF4 (Bit 18)                       */
#define ADC1_DIFFCH_OUT4_DOF4_Msk         (0x40000UL)               /*!< ADC1 DIFFCH_OUT4: DOF4 (Bitfield-Mask: 0x01)          */
#define ADC1_DIFFCH_OUT4_DVF4_Pos         (17UL)                    /*!< ADC1 DIFFCH_OUT4: DVF4 (Bit 17)                       */
#define ADC1_DIFFCH_OUT4_DVF4_Msk         (0x20000UL)               /*!< ADC1 DIFFCH_OUT4: DVF4 (Bitfield-Mask: 0x01)          */
#define ADC1_DIFFCH_OUT4_DWFR4_Pos        (16UL)                    /*!< ADC1 DIFFCH_OUT4: DWFR4 (Bit 16)                      */
#define ADC1_DIFFCH_OUT4_DWFR4_Msk        (0x10000UL)               /*!< ADC1 DIFFCH_OUT4: DWFR4 (Bitfield-Mask: 0x01)         */
#define ADC1_DIFFCH_OUT4_DCH4_Pos         (0UL)                     /*!< ADC1 DIFFCH_OUT4: DCH4 (Bit 0)                        */
#define ADC1_DIFFCH_OUT4_DCH4_Msk         (0xfffUL)                 /*!< ADC1 DIFFCH_OUT4: DCH4 (Bitfield-Mask: 0xfff)         */
/* =====================================================  FILT_UP_CTRL  ====================================================== */
#define ADC1_FILT_UP_CTRL_FU_CH11_EN_Pos  (11UL)                    /*!< ADC1 FILT_UP_CTRL: FU_CH11_EN (Bit 11)                */
#define ADC1_FILT_UP_CTRL_FU_CH11_EN_Msk  (0x800UL)                 /*!< ADC1 FILT_UP_CTRL: FU_CH11_EN (Bitfield-Mask: 0x01)   */
#define ADC1_FILT_UP_CTRL_FU_CH10_EN_Pos  (10UL)                    /*!< ADC1 FILT_UP_CTRL: FU_CH10_EN (Bit 10)                */
#define ADC1_FILT_UP_CTRL_FU_CH10_EN_Msk  (0x400UL)                 /*!< ADC1 FILT_UP_CTRL: FU_CH10_EN (Bitfield-Mask: 0x01)   */
#define ADC1_FILT_UP_CTRL_FU_CH9_EN_Pos   (9UL)                     /*!< ADC1 FILT_UP_CTRL: FU_CH9_EN (Bit 9)                  */
#define ADC1_FILT_UP_CTRL_FU_CH9_EN_Msk   (0x200UL)                 /*!< ADC1 FILT_UP_CTRL: FU_CH9_EN (Bitfield-Mask: 0x01)    */
#define ADC1_FILT_UP_CTRL_FU_CH8_EN_Pos   (8UL)                     /*!< ADC1 FILT_UP_CTRL: FU_CH8_EN (Bit 8)                  */
#define ADC1_FILT_UP_CTRL_FU_CH8_EN_Msk   (0x100UL)                 /*!< ADC1 FILT_UP_CTRL: FU_CH8_EN (Bitfield-Mask: 0x01)    */
#define ADC1_FILT_UP_CTRL_FU_CH7_EN_Pos   (7UL)                     /*!< ADC1 FILT_UP_CTRL: FU_CH7_EN (Bit 7)                  */
#define ADC1_FILT_UP_CTRL_FU_CH7_EN_Msk   (0x80UL)                  /*!< ADC1 FILT_UP_CTRL: FU_CH7_EN (Bitfield-Mask: 0x01)    */
#define ADC1_FILT_UP_CTRL_FU_CH6_EN_Pos   (6UL)                     /*!< ADC1 FILT_UP_CTRL: FU_CH6_EN (Bit 6)                  */
#define ADC1_FILT_UP_CTRL_FU_CH6_EN_Msk   (0x40UL)                  /*!< ADC1 FILT_UP_CTRL: FU_CH6_EN (Bitfield-Mask: 0x01)    */
#define ADC1_FILT_UP_CTRL_FU_CH5_EN_Pos   (5UL)                     /*!< ADC1 FILT_UP_CTRL: FU_CH5_EN (Bit 5)                  */
#define ADC1_FILT_UP_CTRL_FU_CH5_EN_Msk   (0x20UL)                  /*!< ADC1 FILT_UP_CTRL: FU_CH5_EN (Bitfield-Mask: 0x01)    */
#define ADC1_FILT_UP_CTRL_FU_CH4_EN_Pos   (4UL)                     /*!< ADC1 FILT_UP_CTRL: FU_CH4_EN (Bit 4)                  */
#define ADC1_FILT_UP_CTRL_FU_CH4_EN_Msk   (0x10UL)                  /*!< ADC1 FILT_UP_CTRL: FU_CH4_EN (Bitfield-Mask: 0x01)    */
#define ADC1_FILT_UP_CTRL_FU_CH3_EN_Pos   (3UL)                     /*!< ADC1 FILT_UP_CTRL: FU_CH3_EN (Bit 3)                  */
#define ADC1_FILT_UP_CTRL_FU_CH3_EN_Msk   (0x8UL)                   /*!< ADC1 FILT_UP_CTRL: FU_CH3_EN (Bitfield-Mask: 0x01)    */
#define ADC1_FILT_UP_CTRL_FU_CH2_EN_Pos   (2UL)                     /*!< ADC1 FILT_UP_CTRL: FU_CH2_EN (Bit 2)                  */
#define ADC1_FILT_UP_CTRL_FU_CH2_EN_Msk   (0x4UL)                   /*!< ADC1 FILT_UP_CTRL: FU_CH2_EN (Bitfield-Mask: 0x01)    */
#define ADC1_FILT_UP_CTRL_FU_CH1_EN_Pos   (1UL)                     /*!< ADC1 FILT_UP_CTRL: FU_CH1_EN (Bit 1)                  */
#define ADC1_FILT_UP_CTRL_FU_CH1_EN_Msk   (0x2UL)                   /*!< ADC1 FILT_UP_CTRL: FU_CH1_EN (Bitfield-Mask: 0x01)    */
#define ADC1_FILT_UP_CTRL_FU_CH0_EN_Pos   (0UL)                     /*!< ADC1 FILT_UP_CTRL: FU_CH0_EN (Bit 0)                  */
#define ADC1_FILT_UP_CTRL_FU_CH0_EN_Msk   (0x1UL)                   /*!< ADC1 FILT_UP_CTRL: FU_CH0_EN (Bitfield-Mask: 0x01)    */
/* =====================================================  FILT_LO_CTRL  ====================================================== */
#define ADC1_FILT_LO_CTRL_FL_CH11_EN_Pos  (11UL)                    /*!< ADC1 FILT_LO_CTRL: FL_CH11_EN (Bit 11)                */
#define ADC1_FILT_LO_CTRL_FL_CH11_EN_Msk  (0x800UL)                 /*!< ADC1 FILT_LO_CTRL: FL_CH11_EN (Bitfield-Mask: 0x01)   */
#define ADC1_FILT_LO_CTRL_FL_CH10_EN_Pos  (10UL)                    /*!< ADC1 FILT_LO_CTRL: FL_CH10_EN (Bit 10)                */
#define ADC1_FILT_LO_CTRL_FL_CH10_EN_Msk  (0x400UL)                 /*!< ADC1 FILT_LO_CTRL: FL_CH10_EN (Bitfield-Mask: 0x01)   */
#define ADC1_FILT_LO_CTRL_FL_CH9_EN_Pos   (9UL)                     /*!< ADC1 FILT_LO_CTRL: FL_CH9_EN (Bit 9)                  */
#define ADC1_FILT_LO_CTRL_FL_CH9_EN_Msk   (0x200UL)                 /*!< ADC1 FILT_LO_CTRL: FL_CH9_EN (Bitfield-Mask: 0x01)    */
#define ADC1_FILT_LO_CTRL_FL_CH8_EN_Pos   (8UL)                     /*!< ADC1 FILT_LO_CTRL: FL_CH8_EN (Bit 8)                  */
#define ADC1_FILT_LO_CTRL_FL_CH8_EN_Msk   (0x100UL)                 /*!< ADC1 FILT_LO_CTRL: FL_CH8_EN (Bitfield-Mask: 0x01)    */
#define ADC1_FILT_LO_CTRL_FL_CH7_EN_Pos   (7UL)                     /*!< ADC1 FILT_LO_CTRL: FL_CH7_EN (Bit 7)                  */
#define ADC1_FILT_LO_CTRL_FL_CH7_EN_Msk   (0x80UL)                  /*!< ADC1 FILT_LO_CTRL: FL_CH7_EN (Bitfield-Mask: 0x01)    */
#define ADC1_FILT_LO_CTRL_FL_CH6_EN_Pos   (6UL)                     /*!< ADC1 FILT_LO_CTRL: FL_CH6_EN (Bit 6)                  */
#define ADC1_FILT_LO_CTRL_FL_CH6_EN_Msk   (0x40UL)                  /*!< ADC1 FILT_LO_CTRL: FL_CH6_EN (Bitfield-Mask: 0x01)    */
#define ADC1_FILT_LO_CTRL_FL_CH5_EN_Pos   (5UL)                     /*!< ADC1 FILT_LO_CTRL: FL_CH5_EN (Bit 5)                  */
#define ADC1_FILT_LO_CTRL_FL_CH5_EN_Msk   (0x20UL)                  /*!< ADC1 FILT_LO_CTRL: FL_CH5_EN (Bitfield-Mask: 0x01)    */
#define ADC1_FILT_LO_CTRL_FL_CH4_EN_Pos   (4UL)                     /*!< ADC1 FILT_LO_CTRL: FL_CH4_EN (Bit 4)                  */
#define ADC1_FILT_LO_CTRL_FL_CH4_EN_Msk   (0x10UL)                  /*!< ADC1 FILT_LO_CTRL: FL_CH4_EN (Bitfield-Mask: 0x01)    */
#define ADC1_FILT_LO_CTRL_FL_CH3_EN_Pos   (3UL)                     /*!< ADC1 FILT_LO_CTRL: FL_CH3_EN (Bit 3)                  */
#define ADC1_FILT_LO_CTRL_FL_CH3_EN_Msk   (0x8UL)                   /*!< ADC1 FILT_LO_CTRL: FL_CH3_EN (Bitfield-Mask: 0x01)    */
#define ADC1_FILT_LO_CTRL_FL_CH2_EN_Pos   (2UL)                     /*!< ADC1 FILT_LO_CTRL: FL_CH2_EN (Bit 2)                  */
#define ADC1_FILT_LO_CTRL_FL_CH2_EN_Msk   (0x4UL)                   /*!< ADC1 FILT_LO_CTRL: FL_CH2_EN (Bitfield-Mask: 0x01)    */
#define ADC1_FILT_LO_CTRL_FL_CH1_EN_Pos   (1UL)                     /*!< ADC1 FILT_LO_CTRL: FL_CH1_EN (Bit 1)                  */
#define ADC1_FILT_LO_CTRL_FL_CH1_EN_Msk   (0x2UL)                   /*!< ADC1 FILT_LO_CTRL: FL_CH1_EN (Bitfield-Mask: 0x01)    */
#define ADC1_FILT_LO_CTRL_FL_CH0_EN_Pos   (0UL)                     /*!< ADC1 FILT_LO_CTRL: FL_CH0_EN (Bit 0)                  */
#define ADC1_FILT_LO_CTRL_FL_CH0_EN_Msk   (0x1UL)                   /*!< ADC1 FILT_LO_CTRL: FL_CH0_EN (Bitfield-Mask: 0x01)    */
/* =======================================================  MMODE0_11  ======================================================= */
#define ADC1_MMODE0_11_MMODE_D4_Pos       (30UL)                    /*!< ADC1 MMODE0_11: MMODE_D4 (Bit 30)                     */
#define ADC1_MMODE0_11_MMODE_D4_Msk       (0xc0000000UL)            /*!< ADC1 MMODE0_11: MMODE_D4 (Bitfield-Mask: 0x03)        */
#define ADC1_MMODE0_11_MMODE_D3_Pos       (28UL)                    /*!< ADC1 MMODE0_11: MMODE_D3 (Bit 28)                     */
#define ADC1_MMODE0_11_MMODE_D3_Msk       (0x30000000UL)            /*!< ADC1 MMODE0_11: MMODE_D3 (Bitfield-Mask: 0x03)        */
#define ADC1_MMODE0_11_MMODE_D2_Pos       (26UL)                    /*!< ADC1 MMODE0_11: MMODE_D2 (Bit 26)                     */
#define ADC1_MMODE0_11_MMODE_D2_Msk       (0xc000000UL)             /*!< ADC1 MMODE0_11: MMODE_D2 (Bitfield-Mask: 0x03)        */
#define ADC1_MMODE0_11_MMODE_D1_Pos       (24UL)                    /*!< ADC1 MMODE0_11: MMODE_D1 (Bit 24)                     */
#define ADC1_MMODE0_11_MMODE_D1_Msk       (0x3000000UL)             /*!< ADC1 MMODE0_11: MMODE_D1 (Bitfield-Mask: 0x03)        */
#define ADC1_MMODE0_11_MMODE_11_Pos       (22UL)                    /*!< ADC1 MMODE0_11: MMODE_11 (Bit 22)                     */
#define ADC1_MMODE0_11_MMODE_11_Msk       (0xc00000UL)              /*!< ADC1 MMODE0_11: MMODE_11 (Bitfield-Mask: 0x03)        */
#define ADC1_MMODE0_11_MMODE_10_Pos       (20UL)                    /*!< ADC1 MMODE0_11: MMODE_10 (Bit 20)                     */
#define ADC1_MMODE0_11_MMODE_10_Msk       (0x300000UL)              /*!< ADC1 MMODE0_11: MMODE_10 (Bitfield-Mask: 0x03)        */
#define ADC1_MMODE0_11_MMODE_9_Pos        (18UL)                    /*!< ADC1 MMODE0_11: MMODE_9 (Bit 18)                      */
#define ADC1_MMODE0_11_MMODE_9_Msk        (0xc0000UL)               /*!< ADC1 MMODE0_11: MMODE_9 (Bitfield-Mask: 0x03)         */
#define ADC1_MMODE0_11_MMODE_8_Pos        (16UL)                    /*!< ADC1 MMODE0_11: MMODE_8 (Bit 16)                      */
#define ADC1_MMODE0_11_MMODE_8_Msk        (0x30000UL)               /*!< ADC1 MMODE0_11: MMODE_8 (Bitfield-Mask: 0x03)         */
#define ADC1_MMODE0_11_MMODE_7_Pos        (14UL)                    /*!< ADC1 MMODE0_11: MMODE_7 (Bit 14)                      */
#define ADC1_MMODE0_11_MMODE_7_Msk        (0xc000UL)                /*!< ADC1 MMODE0_11: MMODE_7 (Bitfield-Mask: 0x03)         */
#define ADC1_MMODE0_11_MMODE_6_Pos        (12UL)                    /*!< ADC1 MMODE0_11: MMODE_6 (Bit 12)                      */
#define ADC1_MMODE0_11_MMODE_6_Msk        (0x3000UL)                /*!< ADC1 MMODE0_11: MMODE_6 (Bitfield-Mask: 0x03)         */
#define ADC1_MMODE0_11_MMODE_5_Pos        (10UL)                    /*!< ADC1 MMODE0_11: MMODE_5 (Bit 10)                      */
#define ADC1_MMODE0_11_MMODE_5_Msk        (0xc00UL)                 /*!< ADC1 MMODE0_11: MMODE_5 (Bitfield-Mask: 0x03)         */
#define ADC1_MMODE0_11_MMODE_4_Pos        (8UL)                     /*!< ADC1 MMODE0_11: MMODE_4 (Bit 8)                       */
#define ADC1_MMODE0_11_MMODE_4_Msk        (0x300UL)                 /*!< ADC1 MMODE0_11: MMODE_4 (Bitfield-Mask: 0x03)         */
#define ADC1_MMODE0_11_MMODE_3_Pos        (6UL)                     /*!< ADC1 MMODE0_11: MMODE_3 (Bit 6)                       */
#define ADC1_MMODE0_11_MMODE_3_Msk        (0xc0UL)                  /*!< ADC1 MMODE0_11: MMODE_3 (Bitfield-Mask: 0x03)         */
#define ADC1_MMODE0_11_MMODE_2_Pos        (4UL)                     /*!< ADC1 MMODE0_11: MMODE_2 (Bit 4)                       */
#define ADC1_MMODE0_11_MMODE_2_Msk        (0x30UL)                  /*!< ADC1 MMODE0_11: MMODE_2 (Bitfield-Mask: 0x03)         */
#define ADC1_MMODE0_11_MMODE_1_Pos        (2UL)                     /*!< ADC1 MMODE0_11: MMODE_1 (Bit 2)                       */
#define ADC1_MMODE0_11_MMODE_1_Msk        (0xcUL)                   /*!< ADC1 MMODE0_11: MMODE_1 (Bitfield-Mask: 0x03)         */
#define ADC1_MMODE0_11_MMODE_0_Pos        (0UL)                     /*!< ADC1 MMODE0_11: MMODE_0 (Bit 0)                       */
#define ADC1_MMODE0_11_MMODE_0_Msk        (0x3UL)                   /*!< ADC1 MMODE0_11: MMODE_0 (Bitfield-Mask: 0x03)         */
/* ======================================================  TH0_3_UPPER  ====================================================== */
#define ADC1_TH0_3_UPPER_CH3_UP_Pos       (24UL)                    /*!< ADC1 TH0_3_UPPER: CH3_UP (Bit 24)                     */
#define ADC1_TH0_3_UPPER_CH3_UP_Msk       (0xff000000UL)            /*!< ADC1 TH0_3_UPPER: CH3_UP (Bitfield-Mask: 0xff)        */
#define ADC1_TH0_3_UPPER_CH2_UP_Pos       (16UL)                    /*!< ADC1 TH0_3_UPPER: CH2_UP (Bit 16)                     */
#define ADC1_TH0_3_UPPER_CH2_UP_Msk       (0xff0000UL)              /*!< ADC1 TH0_3_UPPER: CH2_UP (Bitfield-Mask: 0xff)        */
#define ADC1_TH0_3_UPPER_CH1_UP_Pos       (8UL)                     /*!< ADC1 TH0_3_UPPER: CH1_UP (Bit 8)                      */
#define ADC1_TH0_3_UPPER_CH1_UP_Msk       (0xff00UL)                /*!< ADC1 TH0_3_UPPER: CH1_UP (Bitfield-Mask: 0xff)        */
#define ADC1_TH0_3_UPPER_CH0_UP_Pos       (0UL)                     /*!< ADC1 TH0_3_UPPER: CH0_UP (Bit 0)                      */
#define ADC1_TH0_3_UPPER_CH0_UP_Msk       (0xffUL)                  /*!< ADC1 TH0_3_UPPER: CH0_UP (Bitfield-Mask: 0xff)        */
/* ======================================================  TH4_7_UPPER  ====================================================== */
#define ADC1_TH4_7_UPPER_CH7_UP_Pos       (24UL)                    /*!< ADC1 TH4_7_UPPER: CH7_UP (Bit 24)                     */
#define ADC1_TH4_7_UPPER_CH7_UP_Msk       (0xff000000UL)            /*!< ADC1 TH4_7_UPPER: CH7_UP (Bitfield-Mask: 0xff)        */
#define ADC1_TH4_7_UPPER_CH6_UP_Pos       (16UL)                    /*!< ADC1 TH4_7_UPPER: CH6_UP (Bit 16)                     */
#define ADC1_TH4_7_UPPER_CH6_UP_Msk       (0xff0000UL)              /*!< ADC1 TH4_7_UPPER: CH6_UP (Bitfield-Mask: 0xff)        */
#define ADC1_TH4_7_UPPER_CH5_UP_Pos       (8UL)                     /*!< ADC1 TH4_7_UPPER: CH5_UP (Bit 8)                      */
#define ADC1_TH4_7_UPPER_CH5_UP_Msk       (0xff00UL)                /*!< ADC1 TH4_7_UPPER: CH5_UP (Bitfield-Mask: 0xff)        */
#define ADC1_TH4_7_UPPER_CH4_UP_Pos       (0UL)                     /*!< ADC1 TH4_7_UPPER: CH4_UP (Bit 0)                      */
#define ADC1_TH4_7_UPPER_CH4_UP_Msk       (0xffUL)                  /*!< ADC1 TH4_7_UPPER: CH4_UP (Bitfield-Mask: 0xff)        */
/* =====================================================  TH8_11_UPPER  ====================================================== */
#define ADC1_TH8_11_UPPER_CH11_UP_Pos     (24UL)                    /*!< ADC1 TH8_11_UPPER: CH11_UP (Bit 24)                   */
#define ADC1_TH8_11_UPPER_CH11_UP_Msk     (0xff000000UL)            /*!< ADC1 TH8_11_UPPER: CH11_UP (Bitfield-Mask: 0xff)      */
#define ADC1_TH8_11_UPPER_CH10_UP_Pos     (16UL)                    /*!< ADC1 TH8_11_UPPER: CH10_UP (Bit 16)                   */
#define ADC1_TH8_11_UPPER_CH10_UP_Msk     (0xff0000UL)              /*!< ADC1 TH8_11_UPPER: CH10_UP (Bitfield-Mask: 0xff)      */
#define ADC1_TH8_11_UPPER_CH9_UP_Pos      (8UL)                     /*!< ADC1 TH8_11_UPPER: CH9_UP (Bit 8)                     */
#define ADC1_TH8_11_UPPER_CH9_UP_Msk      (0xff00UL)                /*!< ADC1 TH8_11_UPPER: CH9_UP (Bitfield-Mask: 0xff)       */
#define ADC1_TH8_11_UPPER_CH8_UP_Pos      (0UL)                     /*!< ADC1 TH8_11_UPPER: CH8_UP (Bit 0)                     */
#define ADC1_TH8_11_UPPER_CH8_UP_Msk      (0xffUL)                  /*!< ADC1 TH8_11_UPPER: CH8_UP (Bitfield-Mask: 0xff)       */
/* ====================================================  DCHTH1_4_UPPER  ===================================================== */
#define ADC1_DCHTH1_4_UPPER_DCH4_UP_Pos   (24UL)                    /*!< ADC1 DCHTH1_4_UPPER: DCH4_UP (Bit 24)                 */
#define ADC1_DCHTH1_4_UPPER_DCH4_UP_Msk   (0xff000000UL)            /*!< ADC1 DCHTH1_4_UPPER: DCH4_UP (Bitfield-Mask: 0xff)    */
#define ADC1_DCHTH1_4_UPPER_DCH3_UP_Pos   (16UL)                    /*!< ADC1 DCHTH1_4_UPPER: DCH3_UP (Bit 16)                 */
#define ADC1_DCHTH1_4_UPPER_DCH3_UP_Msk   (0xff0000UL)              /*!< ADC1 DCHTH1_4_UPPER: DCH3_UP (Bitfield-Mask: 0xff)    */
#define ADC1_DCHTH1_4_UPPER_DCH2_UP_Pos   (8UL)                     /*!< ADC1 DCHTH1_4_UPPER: DCH2_UP (Bit 8)                  */
#define ADC1_DCHTH1_4_UPPER_DCH2_UP_Msk   (0xff00UL)                /*!< ADC1 DCHTH1_4_UPPER: DCH2_UP (Bitfield-Mask: 0xff)    */
#define ADC1_DCHTH1_4_UPPER_DCH1_UP_Pos   (0UL)                     /*!< ADC1 DCHTH1_4_UPPER: DCH1_UP (Bit 0)                  */
#define ADC1_DCHTH1_4_UPPER_DCH1_UP_Msk   (0xffUL)                  /*!< ADC1 DCHTH1_4_UPPER: DCH1_UP (Bitfield-Mask: 0xff)    */
/* =====================================================  CNT0_3_UPPER  ====================================================== */
#define ADC1_CNT0_3_UPPER_HYST_UP_CH3_Pos (27UL)                    /*!< ADC1 CNT0_3_UPPER: HYST_UP_CH3 (Bit 27)               */
#define ADC1_CNT0_3_UPPER_HYST_UP_CH3_Msk (0x18000000UL)            /*!< ADC1 CNT0_3_UPPER: HYST_UP_CH3 (Bitfield-Mask: 0x03)  */
#define ADC1_CNT0_3_UPPER_CNT_UP_CH3_Pos  (24UL)                    /*!< ADC1 CNT0_3_UPPER: CNT_UP_CH3 (Bit 24)                */
#define ADC1_CNT0_3_UPPER_CNT_UP_CH3_Msk  (0x7000000UL)             /*!< ADC1 CNT0_3_UPPER: CNT_UP_CH3 (Bitfield-Mask: 0x07)   */
#define ADC1_CNT0_3_UPPER_HYST_UP_CH2_Pos (19UL)                    /*!< ADC1 CNT0_3_UPPER: HYST_UP_CH2 (Bit 19)               */
#define ADC1_CNT0_3_UPPER_HYST_UP_CH2_Msk (0x180000UL)              /*!< ADC1 CNT0_3_UPPER: HYST_UP_CH2 (Bitfield-Mask: 0x03)  */
#define ADC1_CNT0_3_UPPER_CNT_UP_CH2_Pos  (16UL)                    /*!< ADC1 CNT0_3_UPPER: CNT_UP_CH2 (Bit 16)                */
#define ADC1_CNT0_3_UPPER_CNT_UP_CH2_Msk  (0x70000UL)               /*!< ADC1 CNT0_3_UPPER: CNT_UP_CH2 (Bitfield-Mask: 0x07)   */
#define ADC1_CNT0_3_UPPER_HYST_UP_CH1_Pos (11UL)                    /*!< ADC1 CNT0_3_UPPER: HYST_UP_CH1 (Bit 11)               */
#define ADC1_CNT0_3_UPPER_HYST_UP_CH1_Msk (0x1800UL)                /*!< ADC1 CNT0_3_UPPER: HYST_UP_CH1 (Bitfield-Mask: 0x03)  */
#define ADC1_CNT0_3_UPPER_CNT_UP_CH1_Pos  (8UL)                     /*!< ADC1 CNT0_3_UPPER: CNT_UP_CH1 (Bit 8)                 */
#define ADC1_CNT0_3_UPPER_CNT_UP_CH1_Msk  (0x700UL)                 /*!< ADC1 CNT0_3_UPPER: CNT_UP_CH1 (Bitfield-Mask: 0x07)   */
#define ADC1_CNT0_3_UPPER_HYST_UP_CH0_Pos (3UL)                     /*!< ADC1 CNT0_3_UPPER: HYST_UP_CH0 (Bit 3)                */
#define ADC1_CNT0_3_UPPER_HYST_UP_CH0_Msk (0x18UL)                  /*!< ADC1 CNT0_3_UPPER: HYST_UP_CH0 (Bitfield-Mask: 0x03)  */
#define ADC1_CNT0_3_UPPER_CNT_UP_CH0_Pos  (0UL)                     /*!< ADC1 CNT0_3_UPPER: CNT_UP_CH0 (Bit 0)                 */
#define ADC1_CNT0_3_UPPER_CNT_UP_CH0_Msk  (0x7UL)                   /*!< ADC1 CNT0_3_UPPER: CNT_UP_CH0 (Bitfield-Mask: 0x07)   */
/* =====================================================  CNT4_7_UPPER  ====================================================== */
#define ADC1_CNT4_7_UPPER_HYST_UP_CH7_Pos (27UL)                    /*!< ADC1 CNT4_7_UPPER: HYST_UP_CH7 (Bit 27)               */
#define ADC1_CNT4_7_UPPER_HYST_UP_CH7_Msk (0x18000000UL)            /*!< ADC1 CNT4_7_UPPER: HYST_UP_CH7 (Bitfield-Mask: 0x03)  */
#define ADC1_CNT4_7_UPPER_CNT_UP_CH7_Pos  (24UL)                    /*!< ADC1 CNT4_7_UPPER: CNT_UP_CH7 (Bit 24)                */
#define ADC1_CNT4_7_UPPER_CNT_UP_CH7_Msk  (0x7000000UL)             /*!< ADC1 CNT4_7_UPPER: CNT_UP_CH7 (Bitfield-Mask: 0x07)   */
#define ADC1_CNT4_7_UPPER_HYST_UP_CH6_Pos (19UL)                    /*!< ADC1 CNT4_7_UPPER: HYST_UP_CH6 (Bit 19)               */
#define ADC1_CNT4_7_UPPER_HYST_UP_CH6_Msk (0x180000UL)              /*!< ADC1 CNT4_7_UPPER: HYST_UP_CH6 (Bitfield-Mask: 0x03)  */
#define ADC1_CNT4_7_UPPER_CNT_UP_CH6_Pos  (16UL)                    /*!< ADC1 CNT4_7_UPPER: CNT_UP_CH6 (Bit 16)                */
#define ADC1_CNT4_7_UPPER_CNT_UP_CH6_Msk  (0x70000UL)               /*!< ADC1 CNT4_7_UPPER: CNT_UP_CH6 (Bitfield-Mask: 0x07)   */
#define ADC1_CNT4_7_UPPER_HYST_UP_CH5_Pos (11UL)                    /*!< ADC1 CNT4_7_UPPER: HYST_UP_CH5 (Bit 11)               */
#define ADC1_CNT4_7_UPPER_HYST_UP_CH5_Msk (0x1800UL)                /*!< ADC1 CNT4_7_UPPER: HYST_UP_CH5 (Bitfield-Mask: 0x03)  */
#define ADC1_CNT4_7_UPPER_CNT_UP_CH5_Pos  (8UL)                     /*!< ADC1 CNT4_7_UPPER: CNT_UP_CH5 (Bit 8)                 */
#define ADC1_CNT4_7_UPPER_CNT_UP_CH5_Msk  (0x700UL)                 /*!< ADC1 CNT4_7_UPPER: CNT_UP_CH5 (Bitfield-Mask: 0x07)   */
#define ADC1_CNT4_7_UPPER_HYST_UP_CH4_Pos (3UL)                     /*!< ADC1 CNT4_7_UPPER: HYST_UP_CH4 (Bit 3)                */
#define ADC1_CNT4_7_UPPER_HYST_UP_CH4_Msk (0x18UL)                  /*!< ADC1 CNT4_7_UPPER: HYST_UP_CH4 (Bitfield-Mask: 0x03)  */
#define ADC1_CNT4_7_UPPER_CNT_UP_CH4_Pos  (0UL)                     /*!< ADC1 CNT4_7_UPPER: CNT_UP_CH4 (Bit 0)                 */
#define ADC1_CNT4_7_UPPER_CNT_UP_CH4_Msk  (0x7UL)                   /*!< ADC1 CNT4_7_UPPER: CNT_UP_CH4 (Bitfield-Mask: 0x07)   */
/* =====================================================  CNT8_11_UPPER  ===================================================== */
#define ADC1_CNT8_11_UPPER_HYST_UP_CH11_Pos (27UL)                  /*!< ADC1 CNT8_11_UPPER: HYST_UP_CH11 (Bit 27)             */
#define ADC1_CNT8_11_UPPER_HYST_UP_CH11_Msk (0x18000000UL)          /*!< ADC1 CNT8_11_UPPER: HYST_UP_CH11 (Bitfield-Mask: 0x03) */
#define ADC1_CNT8_11_UPPER_CNT_UP_CH11_Pos (24UL)                   /*!< ADC1 CNT8_11_UPPER: CNT_UP_CH11 (Bit 24)              */
#define ADC1_CNT8_11_UPPER_CNT_UP_CH11_Msk (0x7000000UL)            /*!< ADC1 CNT8_11_UPPER: CNT_UP_CH11 (Bitfield-Mask: 0x07) */
#define ADC1_CNT8_11_UPPER_HYST_UP_CH10_Pos (19UL)                  /*!< ADC1 CNT8_11_UPPER: HYST_UP_CH10 (Bit 19)             */
#define ADC1_CNT8_11_UPPER_HYST_UP_CH10_Msk (0x180000UL)            /*!< ADC1 CNT8_11_UPPER: HYST_UP_CH10 (Bitfield-Mask: 0x03) */
#define ADC1_CNT8_11_UPPER_CNT_UP_CH10_Pos (16UL)                   /*!< ADC1 CNT8_11_UPPER: CNT_UP_CH10 (Bit 16)              */
#define ADC1_CNT8_11_UPPER_CNT_UP_CH10_Msk (0x70000UL)              /*!< ADC1 CNT8_11_UPPER: CNT_UP_CH10 (Bitfield-Mask: 0x07) */
#define ADC1_CNT8_11_UPPER_HYST_UP_CH9_Pos (11UL)                   /*!< ADC1 CNT8_11_UPPER: HYST_UP_CH9 (Bit 11)              */
#define ADC1_CNT8_11_UPPER_HYST_UP_CH9_Msk (0x1800UL)               /*!< ADC1 CNT8_11_UPPER: HYST_UP_CH9 (Bitfield-Mask: 0x03) */
#define ADC1_CNT8_11_UPPER_CNT_UP_CH9_Pos (8UL)                     /*!< ADC1 CNT8_11_UPPER: CNT_UP_CH9 (Bit 8)                */
#define ADC1_CNT8_11_UPPER_CNT_UP_CH9_Msk (0x700UL)                 /*!< ADC1 CNT8_11_UPPER: CNT_UP_CH9 (Bitfield-Mask: 0x07)  */
#define ADC1_CNT8_11_UPPER_HYST_UP_CH8_Pos (3UL)                    /*!< ADC1 CNT8_11_UPPER: HYST_UP_CH8 (Bit 3)               */
#define ADC1_CNT8_11_UPPER_HYST_UP_CH8_Msk (0x18UL)                 /*!< ADC1 CNT8_11_UPPER: HYST_UP_CH8 (Bitfield-Mask: 0x03) */
#define ADC1_CNT8_11_UPPER_CNT_UP_CH8_Pos (0UL)                     /*!< ADC1 CNT8_11_UPPER: CNT_UP_CH8 (Bit 0)                */
#define ADC1_CNT8_11_UPPER_CNT_UP_CH8_Msk (0x7UL)                   /*!< ADC1 CNT8_11_UPPER: CNT_UP_CH8 (Bitfield-Mask: 0x07)  */
/* ====================================================  DCHCNT1_4_UPPER  ==================================================== */
#define ADC1_DCHCNT1_4_UPPER_HYST_UP_DCH4_Pos (27UL)                /*!< ADC1 DCHCNT1_4_UPPER: HYST_UP_DCH4 (Bit 27)           */
#define ADC1_DCHCNT1_4_UPPER_HYST_UP_DCH4_Msk (0x18000000UL)        /*!< ADC1 DCHCNT1_4_UPPER: HYST_UP_DCH4 (Bitfield-Mask: 0x03) */
#define ADC1_DCHCNT1_4_UPPER_CNT_UP_DCH4_Pos (24UL)                 /*!< ADC1 DCHCNT1_4_UPPER: CNT_UP_DCH4 (Bit 24)            */
#define ADC1_DCHCNT1_4_UPPER_CNT_UP_DCH4_Msk (0x7000000UL)          /*!< ADC1 DCHCNT1_4_UPPER: CNT_UP_DCH4 (Bitfield-Mask: 0x07) */
#define ADC1_DCHCNT1_4_UPPER_HYST_UP_DCH3_Pos (19UL)                /*!< ADC1 DCHCNT1_4_UPPER: HYST_UP_DCH3 (Bit 19)           */
#define ADC1_DCHCNT1_4_UPPER_HYST_UP_DCH3_Msk (0x180000UL)          /*!< ADC1 DCHCNT1_4_UPPER: HYST_UP_DCH3 (Bitfield-Mask: 0x03) */
#define ADC1_DCHCNT1_4_UPPER_CNT_UP_DCH3_Pos (16UL)                 /*!< ADC1 DCHCNT1_4_UPPER: CNT_UP_DCH3 (Bit 16)            */
#define ADC1_DCHCNT1_4_UPPER_CNT_UP_DCH3_Msk (0x70000UL)            /*!< ADC1 DCHCNT1_4_UPPER: CNT_UP_DCH3 (Bitfield-Mask: 0x07) */
#define ADC1_DCHCNT1_4_UPPER_HYST_UP_DCH2_Pos (11UL)                /*!< ADC1 DCHCNT1_4_UPPER: HYST_UP_DCH2 (Bit 11)           */
#define ADC1_DCHCNT1_4_UPPER_HYST_UP_DCH2_Msk (0x1800UL)            /*!< ADC1 DCHCNT1_4_UPPER: HYST_UP_DCH2 (Bitfield-Mask: 0x03) */
#define ADC1_DCHCNT1_4_UPPER_CNT_UP_DCH2_Pos (8UL)                  /*!< ADC1 DCHCNT1_4_UPPER: CNT_UP_DCH2 (Bit 8)             */
#define ADC1_DCHCNT1_4_UPPER_CNT_UP_DCH2_Msk (0x700UL)              /*!< ADC1 DCHCNT1_4_UPPER: CNT_UP_DCH2 (Bitfield-Mask: 0x07) */
#define ADC1_DCHCNT1_4_UPPER_HYST_UP_DCH1_Pos (3UL)                 /*!< ADC1 DCHCNT1_4_UPPER: HYST_UP_DCH1 (Bit 3)            */
#define ADC1_DCHCNT1_4_UPPER_HYST_UP_DCH1_Msk (0x18UL)              /*!< ADC1 DCHCNT1_4_UPPER: HYST_UP_DCH1 (Bitfield-Mask: 0x03) */
#define ADC1_DCHCNT1_4_UPPER_CNT_UP_DCH1_Pos (0UL)                  /*!< ADC1 DCHCNT1_4_UPPER: CNT_UP_DCH1 (Bit 0)             */
#define ADC1_DCHCNT1_4_UPPER_CNT_UP_DCH1_Msk (0x7UL)                /*!< ADC1 DCHCNT1_4_UPPER: CNT_UP_DCH1 (Bitfield-Mask: 0x07) */
/* ======================================================  TH0_3_LOWER  ====================================================== */
#define ADC1_TH0_3_LOWER_CH3_LOW_Pos      (24UL)                    /*!< ADC1 TH0_3_LOWER: CH3_LOW (Bit 24)                    */
#define ADC1_TH0_3_LOWER_CH3_LOW_Msk      (0xff000000UL)            /*!< ADC1 TH0_3_LOWER: CH3_LOW (Bitfield-Mask: 0xff)       */
#define ADC1_TH0_3_LOWER_CH2_LOW_Pos      (16UL)                    /*!< ADC1 TH0_3_LOWER: CH2_LOW (Bit 16)                    */
#define ADC1_TH0_3_LOWER_CH2_LOW_Msk      (0xff0000UL)              /*!< ADC1 TH0_3_LOWER: CH2_LOW (Bitfield-Mask: 0xff)       */
#define ADC1_TH0_3_LOWER_CH1_LOW_Pos      (8UL)                     /*!< ADC1 TH0_3_LOWER: CH1_LOW (Bit 8)                     */
#define ADC1_TH0_3_LOWER_CH1_LOW_Msk      (0xff00UL)                /*!< ADC1 TH0_3_LOWER: CH1_LOW (Bitfield-Mask: 0xff)       */
#define ADC1_TH0_3_LOWER_CH0_LOW_Pos      (0UL)                     /*!< ADC1 TH0_3_LOWER: CH0_LOW (Bit 0)                     */
#define ADC1_TH0_3_LOWER_CH0_LOW_Msk      (0xffUL)                  /*!< ADC1 TH0_3_LOWER: CH0_LOW (Bitfield-Mask: 0xff)       */
/* ======================================================  TH4_7_LOWER  ====================================================== */
#define ADC1_TH4_7_LOWER_CH7_LOW_Pos      (24UL)                    /*!< ADC1 TH4_7_LOWER: CH7_LOW (Bit 24)                    */
#define ADC1_TH4_7_LOWER_CH7_LOW_Msk      (0xff000000UL)            /*!< ADC1 TH4_7_LOWER: CH7_LOW (Bitfield-Mask: 0xff)       */
#define ADC1_TH4_7_LOWER_CH6_LOW_Pos      (16UL)                    /*!< ADC1 TH4_7_LOWER: CH6_LOW (Bit 16)                    */
#define ADC1_TH4_7_LOWER_CH6_LOW_Msk      (0xff0000UL)              /*!< ADC1 TH4_7_LOWER: CH6_LOW (Bitfield-Mask: 0xff)       */
#define ADC1_TH4_7_LOWER_CH5_LOW_Pos      (8UL)                     /*!< ADC1 TH4_7_LOWER: CH5_LOW (Bit 8)                     */
#define ADC1_TH4_7_LOWER_CH5_LOW_Msk      (0xff00UL)                /*!< ADC1 TH4_7_LOWER: CH5_LOW (Bitfield-Mask: 0xff)       */
#define ADC1_TH4_7_LOWER_CH4_LOW_Pos      (0UL)                     /*!< ADC1 TH4_7_LOWER: CH4_LOW (Bit 0)                     */
#define ADC1_TH4_7_LOWER_CH4_LOW_Msk      (0xffUL)                  /*!< ADC1 TH4_7_LOWER: CH4_LOW (Bitfield-Mask: 0xff)       */
/* =====================================================  TH8_11_LOWER  ====================================================== */
#define ADC1_TH8_11_LOWER_CH11_LOW_Pos    (24UL)                    /*!< ADC1 TH8_11_LOWER: CH11_LOW (Bit 24)                  */
#define ADC1_TH8_11_LOWER_CH11_LOW_Msk    (0xff000000UL)            /*!< ADC1 TH8_11_LOWER: CH11_LOW (Bitfield-Mask: 0xff)     */
#define ADC1_TH8_11_LOWER_CH10_LOW_Pos    (16UL)                    /*!< ADC1 TH8_11_LOWER: CH10_LOW (Bit 16)                  */
#define ADC1_TH8_11_LOWER_CH10_LOW_Msk    (0xff0000UL)              /*!< ADC1 TH8_11_LOWER: CH10_LOW (Bitfield-Mask: 0xff)     */
#define ADC1_TH8_11_LOWER_CH9_LOW_Pos     (8UL)                     /*!< ADC1 TH8_11_LOWER: CH9_LOW (Bit 8)                    */
#define ADC1_TH8_11_LOWER_CH9_LOW_Msk     (0xff00UL)                /*!< ADC1 TH8_11_LOWER: CH9_LOW (Bitfield-Mask: 0xff)      */
#define ADC1_TH8_11_LOWER_CH8_LOW_Pos     (0UL)                     /*!< ADC1 TH8_11_LOWER: CH8_LOW (Bit 0)                    */
#define ADC1_TH8_11_LOWER_CH8_LOW_Msk     (0xffUL)                  /*!< ADC1 TH8_11_LOWER: CH8_LOW (Bitfield-Mask: 0xff)      */
/* ====================================================  DCHTH1_4_LOWER  ===================================================== */
#define ADC1_DCHTH1_4_LOWER_DCH4_LOW_Pos  (24UL)                    /*!< ADC1 DCHTH1_4_LOWER: DCH4_LOW (Bit 24)                */
#define ADC1_DCHTH1_4_LOWER_DCH4_LOW_Msk  (0xff000000UL)            /*!< ADC1 DCHTH1_4_LOWER: DCH4_LOW (Bitfield-Mask: 0xff)   */
#define ADC1_DCHTH1_4_LOWER_DCH3_LOW_Pos  (16UL)                    /*!< ADC1 DCHTH1_4_LOWER: DCH3_LOW (Bit 16)                */
#define ADC1_DCHTH1_4_LOWER_DCH3_LOW_Msk  (0xff0000UL)              /*!< ADC1 DCHTH1_4_LOWER: DCH3_LOW (Bitfield-Mask: 0xff)   */
#define ADC1_DCHTH1_4_LOWER_DCH2_LOW_Pos  (8UL)                     /*!< ADC1 DCHTH1_4_LOWER: DCH2_LOW (Bit 8)                 */
#define ADC1_DCHTH1_4_LOWER_DCH2_LOW_Msk  (0xff00UL)                /*!< ADC1 DCHTH1_4_LOWER: DCH2_LOW (Bitfield-Mask: 0xff)   */
#define ADC1_DCHTH1_4_LOWER_DCH1_LOW_Pos  (0UL)                     /*!< ADC1 DCHTH1_4_LOWER: DCH1_LOW (Bit 0)                 */
#define ADC1_DCHTH1_4_LOWER_DCH1_LOW_Msk  (0xffUL)                  /*!< ADC1 DCHTH1_4_LOWER: DCH1_LOW (Bitfield-Mask: 0xff)   */
/* =====================================================  CNT0_3_LOWER  ====================================================== */
#define ADC1_CNT0_3_LOWER_HYST_LO_CH3_Pos (27UL)                    /*!< ADC1 CNT0_3_LOWER: HYST_LO_CH3 (Bit 27)               */
#define ADC1_CNT0_3_LOWER_HYST_LO_CH3_Msk (0x18000000UL)            /*!< ADC1 CNT0_3_LOWER: HYST_LO_CH3 (Bitfield-Mask: 0x03)  */
#define ADC1_CNT0_3_LOWER_CNT_LO_CH3_Pos  (24UL)                    /*!< ADC1 CNT0_3_LOWER: CNT_LO_CH3 (Bit 24)                */
#define ADC1_CNT0_3_LOWER_CNT_LO_CH3_Msk  (0x7000000UL)             /*!< ADC1 CNT0_3_LOWER: CNT_LO_CH3 (Bitfield-Mask: 0x07)   */
#define ADC1_CNT0_3_LOWER_HYST_LO_CH2_Pos (19UL)                    /*!< ADC1 CNT0_3_LOWER: HYST_LO_CH2 (Bit 19)               */
#define ADC1_CNT0_3_LOWER_HYST_LO_CH2_Msk (0x180000UL)              /*!< ADC1 CNT0_3_LOWER: HYST_LO_CH2 (Bitfield-Mask: 0x03)  */
#define ADC1_CNT0_3_LOWER_CNT_LO_CH2_Pos  (16UL)                    /*!< ADC1 CNT0_3_LOWER: CNT_LO_CH2 (Bit 16)                */
#define ADC1_CNT0_3_LOWER_CNT_LO_CH2_Msk  (0x70000UL)               /*!< ADC1 CNT0_3_LOWER: CNT_LO_CH2 (Bitfield-Mask: 0x07)   */
#define ADC1_CNT0_3_LOWER_HYST_LO_CH1_Pos (11UL)                    /*!< ADC1 CNT0_3_LOWER: HYST_LO_CH1 (Bit 11)               */
#define ADC1_CNT0_3_LOWER_HYST_LO_CH1_Msk (0x1800UL)                /*!< ADC1 CNT0_3_LOWER: HYST_LO_CH1 (Bitfield-Mask: 0x03)  */
#define ADC1_CNT0_3_LOWER_CNT_LO_CH1_Pos  (8UL)                     /*!< ADC1 CNT0_3_LOWER: CNT_LO_CH1 (Bit 8)                 */
#define ADC1_CNT0_3_LOWER_CNT_LO_CH1_Msk  (0x700UL)                 /*!< ADC1 CNT0_3_LOWER: CNT_LO_CH1 (Bitfield-Mask: 0x07)   */
#define ADC1_CNT0_3_LOWER_HYST_LO_CH0_Pos (3UL)                     /*!< ADC1 CNT0_3_LOWER: HYST_LO_CH0 (Bit 3)                */
#define ADC1_CNT0_3_LOWER_HYST_LO_CH0_Msk (0x18UL)                  /*!< ADC1 CNT0_3_LOWER: HYST_LO_CH0 (Bitfield-Mask: 0x03)  */
#define ADC1_CNT0_3_LOWER_CNT_LO_CH0_Pos  (0UL)                     /*!< ADC1 CNT0_3_LOWER: CNT_LO_CH0 (Bit 0)                 */
#define ADC1_CNT0_3_LOWER_CNT_LO_CH0_Msk  (0x7UL)                   /*!< ADC1 CNT0_3_LOWER: CNT_LO_CH0 (Bitfield-Mask: 0x07)   */
/* =====================================================  CNT4_7_LOWER  ====================================================== */
#define ADC1_CNT4_7_LOWER_HYST_LO_CH7_Pos (27UL)                    /*!< ADC1 CNT4_7_LOWER: HYST_LO_CH7 (Bit 27)               */
#define ADC1_CNT4_7_LOWER_HYST_LO_CH7_Msk (0x18000000UL)            /*!< ADC1 CNT4_7_LOWER: HYST_LO_CH7 (Bitfield-Mask: 0x03)  */
#define ADC1_CNT4_7_LOWER_CNT_LO_CH7_Pos  (24UL)                    /*!< ADC1 CNT4_7_LOWER: CNT_LO_CH7 (Bit 24)                */
#define ADC1_CNT4_7_LOWER_CNT_LO_CH7_Msk  (0x7000000UL)             /*!< ADC1 CNT4_7_LOWER: CNT_LO_CH7 (Bitfield-Mask: 0x07)   */
#define ADC1_CNT4_7_LOWER_HYST_LO_CH6_Pos (19UL)                    /*!< ADC1 CNT4_7_LOWER: HYST_LO_CH6 (Bit 19)               */
#define ADC1_CNT4_7_LOWER_HYST_LO_CH6_Msk (0x180000UL)              /*!< ADC1 CNT4_7_LOWER: HYST_LO_CH6 (Bitfield-Mask: 0x03)  */
#define ADC1_CNT4_7_LOWER_CNT_LO_CH6_Pos  (16UL)                    /*!< ADC1 CNT4_7_LOWER: CNT_LO_CH6 (Bit 16)                */
#define ADC1_CNT4_7_LOWER_CNT_LO_CH6_Msk  (0x70000UL)               /*!< ADC1 CNT4_7_LOWER: CNT_LO_CH6 (Bitfield-Mask: 0x07)   */
#define ADC1_CNT4_7_LOWER_HYST_LO_CH5_Pos (11UL)                    /*!< ADC1 CNT4_7_LOWER: HYST_LO_CH5 (Bit 11)               */
#define ADC1_CNT4_7_LOWER_HYST_LO_CH5_Msk (0x1800UL)                /*!< ADC1 CNT4_7_LOWER: HYST_LO_CH5 (Bitfield-Mask: 0x03)  */
#define ADC1_CNT4_7_LOWER_CNT_LO_CH5_Pos  (8UL)                     /*!< ADC1 CNT4_7_LOWER: CNT_LO_CH5 (Bit 8)                 */
#define ADC1_CNT4_7_LOWER_CNT_LO_CH5_Msk  (0x700UL)                 /*!< ADC1 CNT4_7_LOWER: CNT_LO_CH5 (Bitfield-Mask: 0x07)   */
#define ADC1_CNT4_7_LOWER_HYST_LO_CH4_Pos (3UL)                     /*!< ADC1 CNT4_7_LOWER: HYST_LO_CH4 (Bit 3)                */
#define ADC1_CNT4_7_LOWER_HYST_LO_CH4_Msk (0x18UL)                  /*!< ADC1 CNT4_7_LOWER: HYST_LO_CH4 (Bitfield-Mask: 0x03)  */
#define ADC1_CNT4_7_LOWER_CNT_LO_CH4_Pos  (0UL)                     /*!< ADC1 CNT4_7_LOWER: CNT_LO_CH4 (Bit 0)                 */
#define ADC1_CNT4_7_LOWER_CNT_LO_CH4_Msk  (0x7UL)                   /*!< ADC1 CNT4_7_LOWER: CNT_LO_CH4 (Bitfield-Mask: 0x07)   */
/* =====================================================  CNT8_11_LOWER  ===================================================== */
#define ADC1_CNT8_11_LOWER_HYST_LO_CH11_Pos (27UL)                  /*!< ADC1 CNT8_11_LOWER: HYST_LO_CH11 (Bit 27)             */
#define ADC1_CNT8_11_LOWER_HYST_LO_CH11_Msk (0x18000000UL)          /*!< ADC1 CNT8_11_LOWER: HYST_LO_CH11 (Bitfield-Mask: 0x03) */
#define ADC1_CNT8_11_LOWER_CNT_LO_CH11_Pos (24UL)                   /*!< ADC1 CNT8_11_LOWER: CNT_LO_CH11 (Bit 24)              */
#define ADC1_CNT8_11_LOWER_CNT_LO_CH11_Msk (0x7000000UL)            /*!< ADC1 CNT8_11_LOWER: CNT_LO_CH11 (Bitfield-Mask: 0x07) */
#define ADC1_CNT8_11_LOWER_HYST_LO_CH10_Pos (19UL)                  /*!< ADC1 CNT8_11_LOWER: HYST_LO_CH10 (Bit 19)             */
#define ADC1_CNT8_11_LOWER_HYST_LO_CH10_Msk (0x180000UL)            /*!< ADC1 CNT8_11_LOWER: HYST_LO_CH10 (Bitfield-Mask: 0x03) */
#define ADC1_CNT8_11_LOWER_CNT_LO_CH10_Pos (16UL)                   /*!< ADC1 CNT8_11_LOWER: CNT_LO_CH10 (Bit 16)              */
#define ADC1_CNT8_11_LOWER_CNT_LO_CH10_Msk (0x70000UL)              /*!< ADC1 CNT8_11_LOWER: CNT_LO_CH10 (Bitfield-Mask: 0x07) */
#define ADC1_CNT8_11_LOWER_HYST_LO_CH9_Pos (11UL)                   /*!< ADC1 CNT8_11_LOWER: HYST_LO_CH9 (Bit 11)              */
#define ADC1_CNT8_11_LOWER_HYST_LO_CH9_Msk (0x1800UL)               /*!< ADC1 CNT8_11_LOWER: HYST_LO_CH9 (Bitfield-Mask: 0x03) */
#define ADC1_CNT8_11_LOWER_CNT_LO_CH9_Pos (8UL)                     /*!< ADC1 CNT8_11_LOWER: CNT_LO_CH9 (Bit 8)                */
#define ADC1_CNT8_11_LOWER_CNT_LO_CH9_Msk (0x700UL)                 /*!< ADC1 CNT8_11_LOWER: CNT_LO_CH9 (Bitfield-Mask: 0x07)  */
#define ADC1_CNT8_11_LOWER_HYST_LO_CH8_Pos (3UL)                    /*!< ADC1 CNT8_11_LOWER: HYST_LO_CH8 (Bit 3)               */
#define ADC1_CNT8_11_LOWER_HYST_LO_CH8_Msk (0x18UL)                 /*!< ADC1 CNT8_11_LOWER: HYST_LO_CH8 (Bitfield-Mask: 0x03) */
#define ADC1_CNT8_11_LOWER_CNT_LO_CH8_Pos (0UL)                     /*!< ADC1 CNT8_11_LOWER: CNT_LO_CH8 (Bit 0)                */
#define ADC1_CNT8_11_LOWER_CNT_LO_CH8_Msk (0x7UL)                   /*!< ADC1 CNT8_11_LOWER: CNT_LO_CH8 (Bitfield-Mask: 0x07)  */
/* ====================================================  DCHCNT1_4_LOWER  ==================================================== */
#define ADC1_DCHCNT1_4_LOWER_HYST_LO_DCH4_Pos (27UL)                /*!< ADC1 DCHCNT1_4_LOWER: HYST_LO_DCH4 (Bit 27)           */
#define ADC1_DCHCNT1_4_LOWER_HYST_LO_DCH4_Msk (0x18000000UL)        /*!< ADC1 DCHCNT1_4_LOWER: HYST_LO_DCH4 (Bitfield-Mask: 0x03) */
#define ADC1_DCHCNT1_4_LOWER_CNT_LO_DCH4_Pos (24UL)                 /*!< ADC1 DCHCNT1_4_LOWER: CNT_LO_DCH4 (Bit 24)            */
#define ADC1_DCHCNT1_4_LOWER_CNT_LO_DCH4_Msk (0x7000000UL)          /*!< ADC1 DCHCNT1_4_LOWER: CNT_LO_DCH4 (Bitfield-Mask: 0x07) */
#define ADC1_DCHCNT1_4_LOWER_HYST_LO_DCH3_Pos (19UL)                /*!< ADC1 DCHCNT1_4_LOWER: HYST_LO_DCH3 (Bit 19)           */
#define ADC1_DCHCNT1_4_LOWER_HYST_LO_DCH3_Msk (0x180000UL)          /*!< ADC1 DCHCNT1_4_LOWER: HYST_LO_DCH3 (Bitfield-Mask: 0x03) */
#define ADC1_DCHCNT1_4_LOWER_CNT_LO_DCH3_Pos (16UL)                 /*!< ADC1 DCHCNT1_4_LOWER: CNT_LO_DCH3 (Bit 16)            */
#define ADC1_DCHCNT1_4_LOWER_CNT_LO_DCH3_Msk (0x70000UL)            /*!< ADC1 DCHCNT1_4_LOWER: CNT_LO_DCH3 (Bitfield-Mask: 0x07) */
#define ADC1_DCHCNT1_4_LOWER_HYST_LO_DCH2_Pos (11UL)                /*!< ADC1 DCHCNT1_4_LOWER: HYST_LO_DCH2 (Bit 11)           */
#define ADC1_DCHCNT1_4_LOWER_HYST_LO_DCH2_Msk (0x1800UL)            /*!< ADC1 DCHCNT1_4_LOWER: HYST_LO_DCH2 (Bitfield-Mask: 0x03) */
#define ADC1_DCHCNT1_4_LOWER_CNT_LO_DCH2_Pos (8UL)                  /*!< ADC1 DCHCNT1_4_LOWER: CNT_LO_DCH2 (Bit 8)             */
#define ADC1_DCHCNT1_4_LOWER_CNT_LO_DCH2_Msk (0x700UL)              /*!< ADC1 DCHCNT1_4_LOWER: CNT_LO_DCH2 (Bitfield-Mask: 0x07) */
#define ADC1_DCHCNT1_4_LOWER_HYST_LO_DCH1_Pos (3UL)                 /*!< ADC1 DCHCNT1_4_LOWER: HYST_LO_DCH1 (Bit 3)            */
#define ADC1_DCHCNT1_4_LOWER_HYST_LO_DCH1_Msk (0x18UL)              /*!< ADC1 DCHCNT1_4_LOWER: HYST_LO_DCH1 (Bitfield-Mask: 0x03) */
#define ADC1_DCHCNT1_4_LOWER_CNT_LO_DCH1_Pos (0UL)                  /*!< ADC1 DCHCNT1_4_LOWER: CNT_LO_DCH1 (Bit 0)             */
#define ADC1_DCHCNT1_4_LOWER_CNT_LO_DCH1_Msk (0x7UL)                /*!< ADC1 DCHCNT1_4_LOWER: CNT_LO_DCH1 (Bitfield-Mask: 0x07) */
/* ========================================================  IRQS_1  ========================================================= */
#define ADC1_IRQS_1_DU4UP_IS_Pos          (31UL)                    /*!< ADC1 IRQS_1: DU4UP_IS (Bit 31)                        */
#define ADC1_IRQS_1_DU4UP_IS_Msk          (0x80000000UL)            /*!< ADC1 IRQS_1: DU4UP_IS (Bitfield-Mask: 0x01)           */
#define ADC1_IRQS_1_DU4LO_IS_Pos          (30UL)                    /*!< ADC1 IRQS_1: DU4LO_IS (Bit 30)                        */
#define ADC1_IRQS_1_DU4LO_IS_Msk          (0x40000000UL)            /*!< ADC1 IRQS_1: DU4LO_IS (Bitfield-Mask: 0x01)           */
#define ADC1_IRQS_1_DU3UP_IS_Pos          (29UL)                    /*!< ADC1 IRQS_1: DU3UP_IS (Bit 29)                        */
#define ADC1_IRQS_1_DU3UP_IS_Msk          (0x20000000UL)            /*!< ADC1 IRQS_1: DU3UP_IS (Bitfield-Mask: 0x01)           */
#define ADC1_IRQS_1_DU3LO_IS_Pos          (28UL)                    /*!< ADC1 IRQS_1: DU3LO_IS (Bit 28)                        */
#define ADC1_IRQS_1_DU3LO_IS_Msk          (0x10000000UL)            /*!< ADC1 IRQS_1: DU3LO_IS (Bitfield-Mask: 0x01)           */
#define ADC1_IRQS_1_DU2UP_IS_Pos          (27UL)                    /*!< ADC1 IRQS_1: DU2UP_IS (Bit 27)                        */
#define ADC1_IRQS_1_DU2UP_IS_Msk          (0x8000000UL)             /*!< ADC1 IRQS_1: DU2UP_IS (Bitfield-Mask: 0x01)           */
#define ADC1_IRQS_1_DU2LO_IS_Pos          (26UL)                    /*!< ADC1 IRQS_1: DU2LO_IS (Bit 26)                        */
#define ADC1_IRQS_1_DU2LO_IS_Msk          (0x4000000UL)             /*!< ADC1 IRQS_1: DU2LO_IS (Bitfield-Mask: 0x01)           */
#define ADC1_IRQS_1_DU1UP_IS_Pos          (25UL)                    /*!< ADC1 IRQS_1: DU1UP_IS (Bit 25)                        */
#define ADC1_IRQS_1_DU1UP_IS_Msk          (0x2000000UL)             /*!< ADC1 IRQS_1: DU1UP_IS (Bitfield-Mask: 0x01)           */
#define ADC1_IRQS_1_DU1LO_IS_Pos          (24UL)                    /*!< ADC1 IRQS_1: DU1LO_IS (Bit 24)                        */
#define ADC1_IRQS_1_DU1LO_IS_Msk          (0x1000000UL)             /*!< ADC1 IRQS_1: DU1LO_IS (Bitfield-Mask: 0x01)           */
#define ADC1_IRQS_1_ESM_IS_Pos            (17UL)                    /*!< ADC1 IRQS_1: ESM_IS (Bit 17)                          */
#define ADC1_IRQS_1_ESM_IS_Msk            (0x20000UL)               /*!< ADC1 IRQS_1: ESM_IS (Bitfield-Mask: 0x01)             */
#define ADC1_IRQS_1_EIM_IS_Pos            (16UL)                    /*!< ADC1 IRQS_1: EIM_IS (Bit 16)                          */
#define ADC1_IRQS_1_EIM_IS_Msk            (0x10000UL)               /*!< ADC1 IRQS_1: EIM_IS (Bitfield-Mask: 0x01)             */
#define ADC1_IRQS_1_P2_0_IS_Pos           (12UL)                    /*!< ADC1 IRQS_1: P2_0_IS (Bit 12)                         */
#define ADC1_IRQS_1_P2_0_IS_Msk           (0x1000UL)                /*!< ADC1 IRQS_1: P2_0_IS (Bitfield-Mask: 0x01)            */
#define ADC1_IRQS_1_P2_7_IS_Pos           (11UL)                    /*!< ADC1 IRQS_1: P2_7_IS (Bit 11)                         */
#define ADC1_IRQS_1_P2_7_IS_Msk           (0x800UL)                 /*!< ADC1 IRQS_1: P2_7_IS (Bitfield-Mask: 0x01)            */
#define ADC1_IRQS_1_P2_6_IS_Pos           (10UL)                    /*!< ADC1 IRQS_1: P2_6_IS (Bit 10)                         */
#define ADC1_IRQS_1_P2_6_IS_Msk           (0x400UL)                 /*!< ADC1 IRQS_1: P2_6_IS (Bitfield-Mask: 0x01)            */
#define ADC1_IRQS_1_P2_3_IS_Pos           (9UL)                     /*!< ADC1 IRQS_1: P2_3_IS (Bit 9)                          */
#define ADC1_IRQS_1_P2_3_IS_Msk           (0x200UL)                 /*!< ADC1 IRQS_1: P2_3_IS (Bitfield-Mask: 0x01)            */
#define ADC1_IRQS_1_P2_2_IS_Pos           (8UL)                     /*!< ADC1 IRQS_1: P2_2_IS (Bit 8)                          */
#define ADC1_IRQS_1_P2_2_IS_Msk           (0x100UL)                 /*!< ADC1 IRQS_1: P2_2_IS (Bitfield-Mask: 0x01)            */
#define ADC1_IRQS_1_P2_1_IS_Pos           (7UL)                     /*!< ADC1 IRQS_1: P2_1_IS (Bit 7)                          */
#define ADC1_IRQS_1_P2_1_IS_Msk           (0x80UL)                  /*!< ADC1 IRQS_1: P2_1_IS (Bitfield-Mask: 0x01)            */
#define ADC1_IRQS_1_MON5_IS_Pos           (6UL)                     /*!< ADC1 IRQS_1: MON5_IS (Bit 6)                          */
#define ADC1_IRQS_1_MON5_IS_Msk           (0x40UL)                  /*!< ADC1 IRQS_1: MON5_IS (Bitfield-Mask: 0x01)            */
#define ADC1_IRQS_1_MON4_IS_Pos           (5UL)                     /*!< ADC1 IRQS_1: MON4_IS (Bit 5)                          */
#define ADC1_IRQS_1_MON4_IS_Msk           (0x20UL)                  /*!< ADC1 IRQS_1: MON4_IS (Bitfield-Mask: 0x01)            */
#define ADC1_IRQS_1_MON3_IS_Pos           (4UL)                     /*!< ADC1 IRQS_1: MON3_IS (Bit 4)                          */
#define ADC1_IRQS_1_MON3_IS_Msk           (0x10UL)                  /*!< ADC1 IRQS_1: MON3_IS (Bitfield-Mask: 0x01)            */
#define ADC1_IRQS_1_MON2_IS_Pos           (3UL)                     /*!< ADC1 IRQS_1: MON2_IS (Bit 3)                          */
#define ADC1_IRQS_1_MON2_IS_Msk           (0x8UL)                   /*!< ADC1 IRQS_1: MON2_IS (Bitfield-Mask: 0x01)            */
#define ADC1_IRQS_1_MON1_IS_Pos           (2UL)                     /*!< ADC1 IRQS_1: MON1_IS (Bit 2)                          */
#define ADC1_IRQS_1_MON1_IS_Msk           (0x4UL)                   /*!< ADC1 IRQS_1: MON1_IS (Bitfield-Mask: 0x01)            */
#define ADC1_IRQS_1_VS_IS_Pos             (1UL)                     /*!< ADC1 IRQS_1: VS_IS (Bit 1)                            */
#define ADC1_IRQS_1_VS_IS_Msk             (0x2UL)                   /*!< ADC1 IRQS_1: VS_IS (Bitfield-Mask: 0x01)              */
#define ADC1_IRQS_1_VBATSEN_IS_Pos        (0UL)                     /*!< ADC1 IRQS_1: VBATSEN_IS (Bit 0)                       */
#define ADC1_IRQS_1_VBATSEN_IS_Msk        (0x1UL)                   /*!< ADC1 IRQS_1: VBATSEN_IS (Bitfield-Mask: 0x01)         */
/* ========================================================  IRQS_2  ========================================================= */
#define ADC1_IRQS_2_P2_7_UP_IS_Pos        (27UL)                    /*!< ADC1 IRQS_2: P2_7_UP_IS (Bit 27)                      */
#define ADC1_IRQS_2_P2_7_UP_IS_Msk        (0x8000000UL)             /*!< ADC1 IRQS_2: P2_7_UP_IS (Bitfield-Mask: 0x01)         */
#define ADC1_IRQS_2_P2_6_UP_IS_Pos        (26UL)                    /*!< ADC1 IRQS_2: P2_6_UP_IS (Bit 26)                      */
#define ADC1_IRQS_2_P2_6_UP_IS_Msk        (0x4000000UL)             /*!< ADC1 IRQS_2: P2_6_UP_IS (Bitfield-Mask: 0x01)         */
#define ADC1_IRQS_2_P2_3_UP_IS_Pos        (25UL)                    /*!< ADC1 IRQS_2: P2_3_UP_IS (Bit 25)                      */
#define ADC1_IRQS_2_P2_3_UP_IS_Msk        (0x2000000UL)             /*!< ADC1 IRQS_2: P2_3_UP_IS (Bitfield-Mask: 0x01)         */
#define ADC1_IRQS_2_P2_2_UP_IS_Pos        (24UL)                    /*!< ADC1 IRQS_2: P2_2_UP_IS (Bit 24)                      */
#define ADC1_IRQS_2_P2_2_UP_IS_Msk        (0x1000000UL)             /*!< ADC1 IRQS_2: P2_2_UP_IS (Bitfield-Mask: 0x01)         */
#define ADC1_IRQS_2_P2_1_UP_IS_Pos        (23UL)                    /*!< ADC1 IRQS_2: P2_1_UP_IS (Bit 23)                      */
#define ADC1_IRQS_2_P2_1_UP_IS_Msk        (0x800000UL)              /*!< ADC1 IRQS_2: P2_1_UP_IS (Bitfield-Mask: 0x01)         */
#define ADC1_IRQS_2_MON5_UP_IS_Pos        (22UL)                    /*!< ADC1 IRQS_2: MON5_UP_IS (Bit 22)                      */
#define ADC1_IRQS_2_MON5_UP_IS_Msk        (0x400000UL)              /*!< ADC1 IRQS_2: MON5_UP_IS (Bitfield-Mask: 0x01)         */
#define ADC1_IRQS_2_MON4_UP_IS_Pos        (21UL)                    /*!< ADC1 IRQS_2: MON4_UP_IS (Bit 21)                      */
#define ADC1_IRQS_2_MON4_UP_IS_Msk        (0x200000UL)              /*!< ADC1 IRQS_2: MON4_UP_IS (Bitfield-Mask: 0x01)         */
#define ADC1_IRQS_2_MON3_UP_IS_Pos        (20UL)                    /*!< ADC1 IRQS_2: MON3_UP_IS (Bit 20)                      */
#define ADC1_IRQS_2_MON3_UP_IS_Msk        (0x100000UL)              /*!< ADC1 IRQS_2: MON3_UP_IS (Bitfield-Mask: 0x01)         */
#define ADC1_IRQS_2_MON2_UP_IS_Pos        (19UL)                    /*!< ADC1 IRQS_2: MON2_UP_IS (Bit 19)                      */
#define ADC1_IRQS_2_MON2_UP_IS_Msk        (0x80000UL)               /*!< ADC1 IRQS_2: MON2_UP_IS (Bitfield-Mask: 0x01)         */
#define ADC1_IRQS_2_MON1_UP_IS_Pos        (18UL)                    /*!< ADC1 IRQS_2: MON1_UP_IS (Bit 18)                      */
#define ADC1_IRQS_2_MON1_UP_IS_Msk        (0x40000UL)               /*!< ADC1 IRQS_2: MON1_UP_IS (Bitfield-Mask: 0x01)         */
#define ADC1_IRQS_2_VS_UP_IS_Pos          (17UL)                    /*!< ADC1 IRQS_2: VS_UP_IS (Bit 17)                        */
#define ADC1_IRQS_2_VS_UP_IS_Msk          (0x20000UL)               /*!< ADC1 IRQS_2: VS_UP_IS (Bitfield-Mask: 0x01)           */
#define ADC1_IRQS_2_P2_7_LO_IS_Pos        (11UL)                    /*!< ADC1 IRQS_2: P2_7_LO_IS (Bit 11)                      */
#define ADC1_IRQS_2_P2_7_LO_IS_Msk        (0x800UL)                 /*!< ADC1 IRQS_2: P2_7_LO_IS (Bitfield-Mask: 0x01)         */
#define ADC1_IRQS_2_P2_6_LO_IS_Pos        (10UL)                    /*!< ADC1 IRQS_2: P2_6_LO_IS (Bit 10)                      */
#define ADC1_IRQS_2_P2_6_LO_IS_Msk        (0x400UL)                 /*!< ADC1 IRQS_2: P2_6_LO_IS (Bitfield-Mask: 0x01)         */
#define ADC1_IRQS_2_P2_3_LO_IS_Pos        (9UL)                     /*!< ADC1 IRQS_2: P2_3_LO_IS (Bit 9)                       */
#define ADC1_IRQS_2_P2_3_LO_IS_Msk        (0x200UL)                 /*!< ADC1 IRQS_2: P2_3_LO_IS (Bitfield-Mask: 0x01)         */
#define ADC1_IRQS_2_P2_2_LO_IS_Pos        (8UL)                     /*!< ADC1 IRQS_2: P2_2_LO_IS (Bit 8)                       */
#define ADC1_IRQS_2_P2_2_LO_IS_Msk        (0x100UL)                 /*!< ADC1 IRQS_2: P2_2_LO_IS (Bitfield-Mask: 0x01)         */
#define ADC1_IRQS_2_P2_1_LO_IS_Pos        (7UL)                     /*!< ADC1 IRQS_2: P2_1_LO_IS (Bit 7)                       */
#define ADC1_IRQS_2_P2_1_LO_IS_Msk        (0x80UL)                  /*!< ADC1 IRQS_2: P2_1_LO_IS (Bitfield-Mask: 0x01)         */
#define ADC1_IRQS_2_MON5_LO_IS_Pos        (6UL)                     /*!< ADC1 IRQS_2: MON5_LO_IS (Bit 6)                       */
#define ADC1_IRQS_2_MON5_LO_IS_Msk        (0x40UL)                  /*!< ADC1 IRQS_2: MON5_LO_IS (Bitfield-Mask: 0x01)         */
#define ADC1_IRQS_2_MON4_LO_IS_Pos        (5UL)                     /*!< ADC1 IRQS_2: MON4_LO_IS (Bit 5)                       */
#define ADC1_IRQS_2_MON4_LO_IS_Msk        (0x20UL)                  /*!< ADC1 IRQS_2: MON4_LO_IS (Bitfield-Mask: 0x01)         */
#define ADC1_IRQS_2_MON3_LO_IS_Pos        (4UL)                     /*!< ADC1 IRQS_2: MON3_LO_IS (Bit 4)                       */
#define ADC1_IRQS_2_MON3_LO_IS_Msk        (0x10UL)                  /*!< ADC1 IRQS_2: MON3_LO_IS (Bitfield-Mask: 0x01)         */
#define ADC1_IRQS_2_MON2_LO_IS_Pos        (3UL)                     /*!< ADC1 IRQS_2: MON2_LO_IS (Bit 3)                       */
#define ADC1_IRQS_2_MON2_LO_IS_Msk        (0x8UL)                   /*!< ADC1 IRQS_2: MON2_LO_IS (Bitfield-Mask: 0x01)         */
#define ADC1_IRQS_2_MON1_LO_IS_Pos        (2UL)                     /*!< ADC1 IRQS_2: MON1_LO_IS (Bit 2)                       */
#define ADC1_IRQS_2_MON1_LO_IS_Msk        (0x4UL)                   /*!< ADC1 IRQS_2: MON1_LO_IS (Bitfield-Mask: 0x01)         */
#define ADC1_IRQS_2_VS_LO_IS_Pos          (1UL)                     /*!< ADC1 IRQS_2: VS_LO_IS (Bit 1)                         */
#define ADC1_IRQS_2_VS_LO_IS_Msk          (0x2UL)                   /*!< ADC1 IRQS_2: VS_LO_IS (Bitfield-Mask: 0x01)           */
/* =========================================================  STS_1  ========================================================= */
#define ADC1_STS_1_DU4UP_STS_Pos          (31UL)                    /*!< ADC1 STS_1: DU4UP_STS (Bit 31)                        */
#define ADC1_STS_1_DU4UP_STS_Msk          (0x80000000UL)            /*!< ADC1 STS_1: DU4UP_STS (Bitfield-Mask: 0x01)           */
#define ADC1_STS_1_DU4LO_STS_Pos          (30UL)                    /*!< ADC1 STS_1: DU4LO_STS (Bit 30)                        */
#define ADC1_STS_1_DU4LO_STS_Msk          (0x40000000UL)            /*!< ADC1 STS_1: DU4LO_STS (Bitfield-Mask: 0x01)           */
#define ADC1_STS_1_DU3UP_STS_Pos          (29UL)                    /*!< ADC1 STS_1: DU3UP_STS (Bit 29)                        */
#define ADC1_STS_1_DU3UP_STS_Msk          (0x20000000UL)            /*!< ADC1 STS_1: DU3UP_STS (Bitfield-Mask: 0x01)           */
#define ADC1_STS_1_DU3LO_STS_Pos          (28UL)                    /*!< ADC1 STS_1: DU3LO_STS (Bit 28)                        */
#define ADC1_STS_1_DU3LO_STS_Msk          (0x10000000UL)            /*!< ADC1 STS_1: DU3LO_STS (Bitfield-Mask: 0x01)           */
#define ADC1_STS_1_DU2UP_STS_Pos          (27UL)                    /*!< ADC1 STS_1: DU2UP_STS (Bit 27)                        */
#define ADC1_STS_1_DU2UP_STS_Msk          (0x8000000UL)             /*!< ADC1 STS_1: DU2UP_STS (Bitfield-Mask: 0x01)           */
#define ADC1_STS_1_DU2LO_STS_Pos          (26UL)                    /*!< ADC1 STS_1: DU2LO_STS (Bit 26)                        */
#define ADC1_STS_1_DU2LO_STS_Msk          (0x4000000UL)             /*!< ADC1 STS_1: DU2LO_STS (Bitfield-Mask: 0x01)           */
#define ADC1_STS_1_DU1UP_STS_Pos          (25UL)                    /*!< ADC1 STS_1: DU1UP_STS (Bit 25)                        */
#define ADC1_STS_1_DU1UP_STS_Msk          (0x2000000UL)             /*!< ADC1 STS_1: DU1UP_STS (Bitfield-Mask: 0x01)           */
#define ADC1_STS_1_DU1LO_STS_Pos          (24UL)                    /*!< ADC1 STS_1: DU1LO_STS (Bit 24)                        */
#define ADC1_STS_1_DU1LO_STS_Msk          (0x1000000UL)             /*!< ADC1 STS_1: DU1LO_STS (Bitfield-Mask: 0x01)           */
/* =========================================================  STS_2  ========================================================= */
#define ADC1_STS_2_P2_7_UP_STS_Pos        (27UL)                    /*!< ADC1 STS_2: P2_7_UP_STS (Bit 27)                      */
#define ADC1_STS_2_P2_7_UP_STS_Msk        (0x8000000UL)             /*!< ADC1 STS_2: P2_7_UP_STS (Bitfield-Mask: 0x01)         */
#define ADC1_STS_2_P2_6_UP_STS_Pos        (26UL)                    /*!< ADC1 STS_2: P2_6_UP_STS (Bit 26)                      */
#define ADC1_STS_2_P2_6_UP_STS_Msk        (0x4000000UL)             /*!< ADC1 STS_2: P2_6_UP_STS (Bitfield-Mask: 0x01)         */
#define ADC1_STS_2_P2_3_UP_STS_Pos        (25UL)                    /*!< ADC1 STS_2: P2_3_UP_STS (Bit 25)                      */
#define ADC1_STS_2_P2_3_UP_STS_Msk        (0x2000000UL)             /*!< ADC1 STS_2: P2_3_UP_STS (Bitfield-Mask: 0x01)         */
#define ADC1_STS_2_P2_2_UP_STS_Pos        (24UL)                    /*!< ADC1 STS_2: P2_2_UP_STS (Bit 24)                      */
#define ADC1_STS_2_P2_2_UP_STS_Msk        (0x1000000UL)             /*!< ADC1 STS_2: P2_2_UP_STS (Bitfield-Mask: 0x01)         */
#define ADC1_STS_2_P2_1_UP_STS_Pos        (23UL)                    /*!< ADC1 STS_2: P2_1_UP_STS (Bit 23)                      */
#define ADC1_STS_2_P2_1_UP_STS_Msk        (0x800000UL)              /*!< ADC1 STS_2: P2_1_UP_STS (Bitfield-Mask: 0x01)         */
#define ADC1_STS_2_MON5_UP_STS_Pos        (22UL)                    /*!< ADC1 STS_2: MON5_UP_STS (Bit 22)                      */
#define ADC1_STS_2_MON5_UP_STS_Msk        (0x400000UL)              /*!< ADC1 STS_2: MON5_UP_STS (Bitfield-Mask: 0x01)         */
#define ADC1_STS_2_MON4_UP_STS_Pos        (21UL)                    /*!< ADC1 STS_2: MON4_UP_STS (Bit 21)                      */
#define ADC1_STS_2_MON4_UP_STS_Msk        (0x200000UL)              /*!< ADC1 STS_2: MON4_UP_STS (Bitfield-Mask: 0x01)         */
#define ADC1_STS_2_MON3_UP_STS_Pos        (20UL)                    /*!< ADC1 STS_2: MON3_UP_STS (Bit 20)                      */
#define ADC1_STS_2_MON3_UP_STS_Msk        (0x100000UL)              /*!< ADC1 STS_2: MON3_UP_STS (Bitfield-Mask: 0x01)         */
#define ADC1_STS_2_MON2_UP_STS_Pos        (19UL)                    /*!< ADC1 STS_2: MON2_UP_STS (Bit 19)                      */
#define ADC1_STS_2_MON2_UP_STS_Msk        (0x80000UL)               /*!< ADC1 STS_2: MON2_UP_STS (Bitfield-Mask: 0x01)         */
#define ADC1_STS_2_MON1_UP_STS_Pos        (18UL)                    /*!< ADC1 STS_2: MON1_UP_STS (Bit 18)                      */
#define ADC1_STS_2_MON1_UP_STS_Msk        (0x40000UL)               /*!< ADC1 STS_2: MON1_UP_STS (Bitfield-Mask: 0x01)         */
#define ADC1_STS_2_VS_UP_STS_Pos          (17UL)                    /*!< ADC1 STS_2: VS_UP_STS (Bit 17)                        */
#define ADC1_STS_2_VS_UP_STS_Msk          (0x20000UL)               /*!< ADC1 STS_2: VS_UP_STS (Bitfield-Mask: 0x01)           */
#define ADC1_STS_2_P2_7_LO_STS_Pos        (11UL)                    /*!< ADC1 STS_2: P2_7_LO_STS (Bit 11)                      */
#define ADC1_STS_2_P2_7_LO_STS_Msk        (0x800UL)                 /*!< ADC1 STS_2: P2_7_LO_STS (Bitfield-Mask: 0x01)         */
#define ADC1_STS_2_P2_6_LO_STS_Pos        (10UL)                    /*!< ADC1 STS_2: P2_6_LO_STS (Bit 10)                      */
#define ADC1_STS_2_P2_6_LO_STS_Msk        (0x400UL)                 /*!< ADC1 STS_2: P2_6_LO_STS (Bitfield-Mask: 0x01)         */
#define ADC1_STS_2_P2_3_LO_STS_Pos        (9UL)                     /*!< ADC1 STS_2: P2_3_LO_STS (Bit 9)                       */
#define ADC1_STS_2_P2_3_LO_STS_Msk        (0x200UL)                 /*!< ADC1 STS_2: P2_3_LO_STS (Bitfield-Mask: 0x01)         */
#define ADC1_STS_2_P2_2_LO_STS_Pos        (8UL)                     /*!< ADC1 STS_2: P2_2_LO_STS (Bit 8)                       */
#define ADC1_STS_2_P2_2_LO_STS_Msk        (0x100UL)                 /*!< ADC1 STS_2: P2_2_LO_STS (Bitfield-Mask: 0x01)         */
#define ADC1_STS_2_P2_1_LO_STS_Pos        (7UL)                     /*!< ADC1 STS_2: P2_1_LO_STS (Bit 7)                       */
#define ADC1_STS_2_P2_1_LO_STS_Msk        (0x80UL)                  /*!< ADC1 STS_2: P2_1_LO_STS (Bitfield-Mask: 0x01)         */
#define ADC1_STS_2_MON5_LO_STS_Pos        (6UL)                     /*!< ADC1 STS_2: MON5_LO_STS (Bit 6)                       */
#define ADC1_STS_2_MON5_LO_STS_Msk        (0x40UL)                  /*!< ADC1 STS_2: MON5_LO_STS (Bitfield-Mask: 0x01)         */
#define ADC1_STS_2_MON4_LO_STS_Pos        (5UL)                     /*!< ADC1 STS_2: MON4_LO_STS (Bit 5)                       */
#define ADC1_STS_2_MON4_LO_STS_Msk        (0x20UL)                  /*!< ADC1 STS_2: MON4_LO_STS (Bitfield-Mask: 0x01)         */
#define ADC1_STS_2_MON3_LO_STS_Pos        (4UL)                     /*!< ADC1 STS_2: MON3_LO_STS (Bit 4)                       */
#define ADC1_STS_2_MON3_LO_STS_Msk        (0x10UL)                  /*!< ADC1 STS_2: MON3_LO_STS (Bitfield-Mask: 0x01)         */
#define ADC1_STS_2_MON2_LO_STS_Pos        (3UL)                     /*!< ADC1 STS_2: MON2_LO_STS (Bit 3)                       */
#define ADC1_STS_2_MON2_LO_STS_Msk        (0x8UL)                   /*!< ADC1 STS_2: MON2_LO_STS (Bitfield-Mask: 0x01)         */
#define ADC1_STS_2_MON1_LO_STS_Pos        (2UL)                     /*!< ADC1 STS_2: MON1_LO_STS (Bit 2)                       */
#define ADC1_STS_2_MON1_LO_STS_Msk        (0x4UL)                   /*!< ADC1 STS_2: MON1_LO_STS (Bitfield-Mask: 0x01)         */
#define ADC1_STS_2_VS_LO_STS_Pos          (1UL)                     /*!< ADC1 STS_2: VS_LO_STS (Bit 1)                         */
#define ADC1_STS_2_VS_LO_STS_Msk          (0x2UL)                   /*!< ADC1 STS_2: VS_LO_STS (Bitfield-Mask: 0x01)           */
/* =======================================================  STSCLR_1  ======================================================== */
#define ADC1_STSCLR_1_DU4UP_SC_Pos        (31UL)                    /*!< ADC1 STSCLR_1: DU4UP_SC (Bit 31)                      */
#define ADC1_STSCLR_1_DU4UP_SC_Msk        (0x80000000UL)            /*!< ADC1 STSCLR_1: DU4UP_SC (Bitfield-Mask: 0x01)         */
#define ADC1_STSCLR_1_DU4LO_SC_Pos        (30UL)                    /*!< ADC1 STSCLR_1: DU4LO_SC (Bit 30)                      */
#define ADC1_STSCLR_1_DU4LO_SC_Msk        (0x40000000UL)            /*!< ADC1 STSCLR_1: DU4LO_SC (Bitfield-Mask: 0x01)         */
#define ADC1_STSCLR_1_DU3UP_SC_Pos        (29UL)                    /*!< ADC1 STSCLR_1: DU3UP_SC (Bit 29)                      */
#define ADC1_STSCLR_1_DU3UP_SC_Msk        (0x20000000UL)            /*!< ADC1 STSCLR_1: DU3UP_SC (Bitfield-Mask: 0x01)         */
#define ADC1_STSCLR_1_DU3LO_SC_Pos        (28UL)                    /*!< ADC1 STSCLR_1: DU3LO_SC (Bit 28)                      */
#define ADC1_STSCLR_1_DU3LO_SC_Msk        (0x10000000UL)            /*!< ADC1 STSCLR_1: DU3LO_SC (Bitfield-Mask: 0x01)         */
#define ADC1_STSCLR_1_DU2UP_SC_Pos        (27UL)                    /*!< ADC1 STSCLR_1: DU2UP_SC (Bit 27)                      */
#define ADC1_STSCLR_1_DU2UP_SC_Msk        (0x8000000UL)             /*!< ADC1 STSCLR_1: DU2UP_SC (Bitfield-Mask: 0x01)         */
#define ADC1_STSCLR_1_DU2LO_SC_Pos        (26UL)                    /*!< ADC1 STSCLR_1: DU2LO_SC (Bit 26)                      */
#define ADC1_STSCLR_1_DU2LO_SC_Msk        (0x4000000UL)             /*!< ADC1 STSCLR_1: DU2LO_SC (Bitfield-Mask: 0x01)         */
#define ADC1_STSCLR_1_DU1UP_SC_Pos        (25UL)                    /*!< ADC1 STSCLR_1: DU1UP_SC (Bit 25)                      */
#define ADC1_STSCLR_1_DU1UP_SC_Msk        (0x2000000UL)             /*!< ADC1 STSCLR_1: DU1UP_SC (Bitfield-Mask: 0x01)         */
#define ADC1_STSCLR_1_DU1LO_SC_Pos        (24UL)                    /*!< ADC1 STSCLR_1: DU1LO_SC (Bit 24)                      */
#define ADC1_STSCLR_1_DU1LO_SC_Msk        (0x1000000UL)             /*!< ADC1 STSCLR_1: DU1LO_SC (Bitfield-Mask: 0x01)         */
/* =======================================================  IRQCLR_1  ======================================================== */
#define ADC1_IRQCLR_1_DU4UP_ISC_Pos       (31UL)                    /*!< ADC1 IRQCLR_1: DU4UP_ISC (Bit 31)                     */
#define ADC1_IRQCLR_1_DU4UP_ISC_Msk       (0x80000000UL)            /*!< ADC1 IRQCLR_1: DU4UP_ISC (Bitfield-Mask: 0x01)        */
#define ADC1_IRQCLR_1_DU4LO_ISC_Pos       (30UL)                    /*!< ADC1 IRQCLR_1: DU4LO_ISC (Bit 30)                     */
#define ADC1_IRQCLR_1_DU4LO_ISC_Msk       (0x40000000UL)            /*!< ADC1 IRQCLR_1: DU4LO_ISC (Bitfield-Mask: 0x01)        */
#define ADC1_IRQCLR_1_DU3UP_ISC_Pos       (29UL)                    /*!< ADC1 IRQCLR_1: DU3UP_ISC (Bit 29)                     */
#define ADC1_IRQCLR_1_DU3UP_ISC_Msk       (0x20000000UL)            /*!< ADC1 IRQCLR_1: DU3UP_ISC (Bitfield-Mask: 0x01)        */
#define ADC1_IRQCLR_1_DU3LO_ISC_Pos       (28UL)                    /*!< ADC1 IRQCLR_1: DU3LO_ISC (Bit 28)                     */
#define ADC1_IRQCLR_1_DU3LO_ISC_Msk       (0x10000000UL)            /*!< ADC1 IRQCLR_1: DU3LO_ISC (Bitfield-Mask: 0x01)        */
#define ADC1_IRQCLR_1_DU2UP_ISC_Pos       (27UL)                    /*!< ADC1 IRQCLR_1: DU2UP_ISC (Bit 27)                     */
#define ADC1_IRQCLR_1_DU2UP_ISC_Msk       (0x8000000UL)             /*!< ADC1 IRQCLR_1: DU2UP_ISC (Bitfield-Mask: 0x01)        */
#define ADC1_IRQCLR_1_DU2LO_ISC_Pos       (26UL)                    /*!< ADC1 IRQCLR_1: DU2LO_ISC (Bit 26)                     */
#define ADC1_IRQCLR_1_DU2LO_ISC_Msk       (0x4000000UL)             /*!< ADC1 IRQCLR_1: DU2LO_ISC (Bitfield-Mask: 0x01)        */
#define ADC1_IRQCLR_1_DU1UP_ISC_Pos       (25UL)                    /*!< ADC1 IRQCLR_1: DU1UP_ISC (Bit 25)                     */
#define ADC1_IRQCLR_1_DU1UP_ISC_Msk       (0x2000000UL)             /*!< ADC1 IRQCLR_1: DU1UP_ISC (Bitfield-Mask: 0x01)        */
#define ADC1_IRQCLR_1_DU1LO_ISC_Pos       (24UL)                    /*!< ADC1 IRQCLR_1: DU1LO_ISC (Bit 24)                     */
#define ADC1_IRQCLR_1_DU1LO_ISC_Msk       (0x1000000UL)             /*!< ADC1 IRQCLR_1: DU1LO_ISC (Bitfield-Mask: 0x01)        */
#define ADC1_IRQCLR_1_ESM_ISC_Pos         (17UL)                    /*!< ADC1 IRQCLR_1: ESM_ISC (Bit 17)                       */
#define ADC1_IRQCLR_1_ESM_ISC_Msk         (0x20000UL)               /*!< ADC1 IRQCLR_1: ESM_ISC (Bitfield-Mask: 0x01)          */
#define ADC1_IRQCLR_1_EIM_ISC_Pos         (16UL)                    /*!< ADC1 IRQCLR_1: EIM_ISC (Bit 16)                       */
#define ADC1_IRQCLR_1_EIM_ISC_Msk         (0x10000UL)               /*!< ADC1 IRQCLR_1: EIM_ISC (Bitfield-Mask: 0x01)          */
#define ADC1_IRQCLR_1_P2_0_ISC_Pos        (12UL)                    /*!< ADC1 IRQCLR_1: P2_0_ISC (Bit 12)                      */
#define ADC1_IRQCLR_1_P2_0_ISC_Msk        (0x1000UL)                /*!< ADC1 IRQCLR_1: P2_0_ISC (Bitfield-Mask: 0x01)         */
#define ADC1_IRQCLR_1_P2_7_ISC_Pos        (11UL)                    /*!< ADC1 IRQCLR_1: P2_7_ISC (Bit 11)                      */
#define ADC1_IRQCLR_1_P2_7_ISC_Msk        (0x800UL)                 /*!< ADC1 IRQCLR_1: P2_7_ISC (Bitfield-Mask: 0x01)         */
#define ADC1_IRQCLR_1_P2_6_ISC_Pos        (10UL)                    /*!< ADC1 IRQCLR_1: P2_6_ISC (Bit 10)                      */
#define ADC1_IRQCLR_1_P2_6_ISC_Msk        (0x400UL)                 /*!< ADC1 IRQCLR_1: P2_6_ISC (Bitfield-Mask: 0x01)         */
#define ADC1_IRQCLR_1_P2_3_ISC_Pos        (9UL)                     /*!< ADC1 IRQCLR_1: P2_3_ISC (Bit 9)                       */
#define ADC1_IRQCLR_1_P2_3_ISC_Msk        (0x200UL)                 /*!< ADC1 IRQCLR_1: P2_3_ISC (Bitfield-Mask: 0x01)         */
#define ADC1_IRQCLR_1_P2_2_ISC_Pos        (8UL)                     /*!< ADC1 IRQCLR_1: P2_2_ISC (Bit 8)                       */
#define ADC1_IRQCLR_1_P2_2_ISC_Msk        (0x100UL)                 /*!< ADC1 IRQCLR_1: P2_2_ISC (Bitfield-Mask: 0x01)         */
#define ADC1_IRQCLR_1_P2_1_ISC_Pos        (7UL)                     /*!< ADC1 IRQCLR_1: P2_1_ISC (Bit 7)                       */
#define ADC1_IRQCLR_1_P2_1_ISC_Msk        (0x80UL)                  /*!< ADC1 IRQCLR_1: P2_1_ISC (Bitfield-Mask: 0x01)         */
#define ADC1_IRQCLR_1_MON5_ISC_Pos        (6UL)                     /*!< ADC1 IRQCLR_1: MON5_ISC (Bit 6)                       */
#define ADC1_IRQCLR_1_MON5_ISC_Msk        (0x40UL)                  /*!< ADC1 IRQCLR_1: MON5_ISC (Bitfield-Mask: 0x01)         */
#define ADC1_IRQCLR_1_MON4_ISC_Pos        (5UL)                     /*!< ADC1 IRQCLR_1: MON4_ISC (Bit 5)                       */
#define ADC1_IRQCLR_1_MON4_ISC_Msk        (0x20UL)                  /*!< ADC1 IRQCLR_1: MON4_ISC (Bitfield-Mask: 0x01)         */
#define ADC1_IRQCLR_1_MON3_ISC_Pos        (4UL)                     /*!< ADC1 IRQCLR_1: MON3_ISC (Bit 4)                       */
#define ADC1_IRQCLR_1_MON3_ISC_Msk        (0x10UL)                  /*!< ADC1 IRQCLR_1: MON3_ISC (Bitfield-Mask: 0x01)         */
#define ADC1_IRQCLR_1_MON2_ISC_Pos        (3UL)                     /*!< ADC1 IRQCLR_1: MON2_ISC (Bit 3)                       */
#define ADC1_IRQCLR_1_MON2_ISC_Msk        (0x8UL)                   /*!< ADC1 IRQCLR_1: MON2_ISC (Bitfield-Mask: 0x01)         */
#define ADC1_IRQCLR_1_MON1_ISC_Pos        (2UL)                     /*!< ADC1 IRQCLR_1: MON1_ISC (Bit 2)                       */
#define ADC1_IRQCLR_1_MON1_ISC_Msk        (0x4UL)                   /*!< ADC1 IRQCLR_1: MON1_ISC (Bitfield-Mask: 0x01)         */
#define ADC1_IRQCLR_1_VS_ISC_Pos          (1UL)                     /*!< ADC1 IRQCLR_1: VS_ISC (Bit 1)                         */
#define ADC1_IRQCLR_1_VS_ISC_Msk          (0x2UL)                   /*!< ADC1 IRQCLR_1: VS_ISC (Bitfield-Mask: 0x01)           */
#define ADC1_IRQCLR_1_VBATSEN_ISC_Pos     (0UL)                     /*!< ADC1 IRQCLR_1: VBATSEN_ISC (Bit 0)                    */
#define ADC1_IRQCLR_1_VBATSEN_ISC_Msk     (0x1UL)                   /*!< ADC1 IRQCLR_1: VBATSEN_ISC (Bitfield-Mask: 0x01)      */
/* =======================================================  IRQCLR_2  ======================================================== */
#define ADC1_IRQCLR_2_P2_7_UP_ISC_Pos     (27UL)                    /*!< ADC1 IRQCLR_2: P2_7_UP_ISC (Bit 27)                   */
#define ADC1_IRQCLR_2_P2_7_UP_ISC_Msk     (0x8000000UL)             /*!< ADC1 IRQCLR_2: P2_7_UP_ISC (Bitfield-Mask: 0x01)      */
#define ADC1_IRQCLR_2_P2_6_UP_ISC_Pos     (26UL)                    /*!< ADC1 IRQCLR_2: P2_6_UP_ISC (Bit 26)                   */
#define ADC1_IRQCLR_2_P2_6_UP_ISC_Msk     (0x4000000UL)             /*!< ADC1 IRQCLR_2: P2_6_UP_ISC (Bitfield-Mask: 0x01)      */
#define ADC1_IRQCLR_2_P2_3_UP_ISC_Pos     (25UL)                    /*!< ADC1 IRQCLR_2: P2_3_UP_ISC (Bit 25)                   */
#define ADC1_IRQCLR_2_P2_3_UP_ISC_Msk     (0x2000000UL)             /*!< ADC1 IRQCLR_2: P2_3_UP_ISC (Bitfield-Mask: 0x01)      */
#define ADC1_IRQCLR_2_P2_2_UP_ISC_Pos     (24UL)                    /*!< ADC1 IRQCLR_2: P2_2_UP_ISC (Bit 24)                   */
#define ADC1_IRQCLR_2_P2_2_UP_ISC_Msk     (0x1000000UL)             /*!< ADC1 IRQCLR_2: P2_2_UP_ISC (Bitfield-Mask: 0x01)      */
#define ADC1_IRQCLR_2_P2_1_UP_ISC_Pos     (23UL)                    /*!< ADC1 IRQCLR_2: P2_1_UP_ISC (Bit 23)                   */
#define ADC1_IRQCLR_2_P2_1_UP_ISC_Msk     (0x800000UL)              /*!< ADC1 IRQCLR_2: P2_1_UP_ISC (Bitfield-Mask: 0x01)      */
#define ADC1_IRQCLR_2_MON5_UP_ISC_Pos     (22UL)                    /*!< ADC1 IRQCLR_2: MON5_UP_ISC (Bit 22)                   */
#define ADC1_IRQCLR_2_MON5_UP_ISC_Msk     (0x400000UL)              /*!< ADC1 IRQCLR_2: MON5_UP_ISC (Bitfield-Mask: 0x01)      */
#define ADC1_IRQCLR_2_MON4_UP_ISC_Pos     (21UL)                    /*!< ADC1 IRQCLR_2: MON4_UP_ISC (Bit 21)                   */
#define ADC1_IRQCLR_2_MON4_UP_ISC_Msk     (0x200000UL)              /*!< ADC1 IRQCLR_2: MON4_UP_ISC (Bitfield-Mask: 0x01)      */
#define ADC1_IRQCLR_2_MON3_UP_ISC_Pos     (20UL)                    /*!< ADC1 IRQCLR_2: MON3_UP_ISC (Bit 20)                   */
#define ADC1_IRQCLR_2_MON3_UP_ISC_Msk     (0x100000UL)              /*!< ADC1 IRQCLR_2: MON3_UP_ISC (Bitfield-Mask: 0x01)      */
#define ADC1_IRQCLR_2_MON2_UP_ISC_Pos     (19UL)                    /*!< ADC1 IRQCLR_2: MON2_UP_ISC (Bit 19)                   */
#define ADC1_IRQCLR_2_MON2_UP_ISC_Msk     (0x80000UL)               /*!< ADC1 IRQCLR_2: MON2_UP_ISC (Bitfield-Mask: 0x01)      */
#define ADC1_IRQCLR_2_MON1_UP_ISC_Pos     (18UL)                    /*!< ADC1 IRQCLR_2: MON1_UP_ISC (Bit 18)                   */
#define ADC1_IRQCLR_2_MON1_UP_ISC_Msk     (0x40000UL)               /*!< ADC1 IRQCLR_2: MON1_UP_ISC (Bitfield-Mask: 0x01)      */
#define ADC1_IRQCLR_2_VS_UP_ISC_Pos       (17UL)                    /*!< ADC1 IRQCLR_2: VS_UP_ISC (Bit 17)                     */
#define ADC1_IRQCLR_2_VS_UP_ISC_Msk       (0x20000UL)               /*!< ADC1 IRQCLR_2: VS_UP_ISC (Bitfield-Mask: 0x01)        */
#define ADC1_IRQCLR_2_P2_7_LO_ISC_Pos     (11UL)                    /*!< ADC1 IRQCLR_2: P2_7_LO_ISC (Bit 11)                   */
#define ADC1_IRQCLR_2_P2_7_LO_ISC_Msk     (0x800UL)                 /*!< ADC1 IRQCLR_2: P2_7_LO_ISC (Bitfield-Mask: 0x01)      */
#define ADC1_IRQCLR_2_P2_6_LO_ISC_Pos     (10UL)                    /*!< ADC1 IRQCLR_2: P2_6_LO_ISC (Bit 10)                   */
#define ADC1_IRQCLR_2_P2_6_LO_ISC_Msk     (0x400UL)                 /*!< ADC1 IRQCLR_2: P2_6_LO_ISC (Bitfield-Mask: 0x01)      */
#define ADC1_IRQCLR_2_P2_3_LO_ISC_Pos     (9UL)                     /*!< ADC1 IRQCLR_2: P2_3_LO_ISC (Bit 9)                    */
#define ADC1_IRQCLR_2_P2_3_LO_ISC_Msk     (0x200UL)                 /*!< ADC1 IRQCLR_2: P2_3_LO_ISC (Bitfield-Mask: 0x01)      */
#define ADC1_IRQCLR_2_P2_2_LO_ISC_Pos     (8UL)                     /*!< ADC1 IRQCLR_2: P2_2_LO_ISC (Bit 8)                    */
#define ADC1_IRQCLR_2_P2_2_LO_ISC_Msk     (0x100UL)                 /*!< ADC1 IRQCLR_2: P2_2_LO_ISC (Bitfield-Mask: 0x01)      */
#define ADC1_IRQCLR_2_P2_1_LO_ISC_Pos     (7UL)                     /*!< ADC1 IRQCLR_2: P2_1_LO_ISC (Bit 7)                    */
#define ADC1_IRQCLR_2_P2_1_LO_ISC_Msk     (0x80UL)                  /*!< ADC1 IRQCLR_2: P2_1_LO_ISC (Bitfield-Mask: 0x01)      */
#define ADC1_IRQCLR_2_MON5_LO_ISC_Pos     (6UL)                     /*!< ADC1 IRQCLR_2: MON5_LO_ISC (Bit 6)                    */
#define ADC1_IRQCLR_2_MON5_LO_ISC_Msk     (0x40UL)                  /*!< ADC1 IRQCLR_2: MON5_LO_ISC (Bitfield-Mask: 0x01)      */
#define ADC1_IRQCLR_2_MON4_LO_ISC_Pos     (5UL)                     /*!< ADC1 IRQCLR_2: MON4_LO_ISC (Bit 5)                    */
#define ADC1_IRQCLR_2_MON4_LO_ISC_Msk     (0x20UL)                  /*!< ADC1 IRQCLR_2: MON4_LO_ISC (Bitfield-Mask: 0x01)      */
#define ADC1_IRQCLR_2_MON3_LO_ISC_Pos     (4UL)                     /*!< ADC1 IRQCLR_2: MON3_LO_ISC (Bit 4)                    */
#define ADC1_IRQCLR_2_MON3_LO_ISC_Msk     (0x10UL)                  /*!< ADC1 IRQCLR_2: MON3_LO_ISC (Bitfield-Mask: 0x01)      */
#define ADC1_IRQCLR_2_MON2_LO_ISC_Pos     (3UL)                     /*!< ADC1 IRQCLR_2: MON2_LO_ISC (Bit 3)                    */
#define ADC1_IRQCLR_2_MON2_LO_ISC_Msk     (0x8UL)                   /*!< ADC1 IRQCLR_2: MON2_LO_ISC (Bitfield-Mask: 0x01)      */
#define ADC1_IRQCLR_2_MON1_LO_ISC_Pos     (2UL)                     /*!< ADC1 IRQCLR_2: MON1_LO_ISC (Bit 2)                    */
#define ADC1_IRQCLR_2_MON1_LO_ISC_Msk     (0x4UL)                   /*!< ADC1 IRQCLR_2: MON1_LO_ISC (Bitfield-Mask: 0x01)      */
#define ADC1_IRQCLR_2_VS_LO_ISC_Pos       (1UL)                     /*!< ADC1 IRQCLR_2: VS_LO_ISC (Bit 1)                      */
#define ADC1_IRQCLR_2_VS_LO_ISC_Msk       (0x2UL)                   /*!< ADC1 IRQCLR_2: VS_LO_ISC (Bitfield-Mask: 0x01)        */
/* ========================================================  IRQEN_1  ======================================================== */
#define ADC1_IRQEN_1_DU4UP_IEN_Pos        (31UL)                    /*!< ADC1 IRQEN_1: DU4UP_IEN (Bit 31)                      */
#define ADC1_IRQEN_1_DU4UP_IEN_Msk        (0x80000000UL)            /*!< ADC1 IRQEN_1: DU4UP_IEN (Bitfield-Mask: 0x01)         */
#define ADC1_IRQEN_1_DU4LO_IEN_Pos        (30UL)                    /*!< ADC1 IRQEN_1: DU4LO_IEN (Bit 30)                      */
#define ADC1_IRQEN_1_DU4LO_IEN_Msk        (0x40000000UL)            /*!< ADC1 IRQEN_1: DU4LO_IEN (Bitfield-Mask: 0x01)         */
#define ADC1_IRQEN_1_DU3UP_IEN_Pos        (29UL)                    /*!< ADC1 IRQEN_1: DU3UP_IEN (Bit 29)                      */
#define ADC1_IRQEN_1_DU3UP_IEN_Msk        (0x20000000UL)            /*!< ADC1 IRQEN_1: DU3UP_IEN (Bitfield-Mask: 0x01)         */
#define ADC1_IRQEN_1_DU3LO_IEN_Pos        (28UL)                    /*!< ADC1 IRQEN_1: DU3LO_IEN (Bit 28)                      */
#define ADC1_IRQEN_1_DU3LO_IEN_Msk        (0x10000000UL)            /*!< ADC1 IRQEN_1: DU3LO_IEN (Bitfield-Mask: 0x01)         */
#define ADC1_IRQEN_1_DU2UP_IEN_Pos        (27UL)                    /*!< ADC1 IRQEN_1: DU2UP_IEN (Bit 27)                      */
#define ADC1_IRQEN_1_DU2UP_IEN_Msk        (0x8000000UL)             /*!< ADC1 IRQEN_1: DU2UP_IEN (Bitfield-Mask: 0x01)         */
#define ADC1_IRQEN_1_DU2LO_IEN_Pos        (26UL)                    /*!< ADC1 IRQEN_1: DU2LO_IEN (Bit 26)                      */
#define ADC1_IRQEN_1_DU2LO_IEN_Msk        (0x4000000UL)             /*!< ADC1 IRQEN_1: DU2LO_IEN (Bitfield-Mask: 0x01)         */
#define ADC1_IRQEN_1_DU1UP_IEN_Pos        (25UL)                    /*!< ADC1 IRQEN_1: DU1UP_IEN (Bit 25)                      */
#define ADC1_IRQEN_1_DU1UP_IEN_Msk        (0x2000000UL)             /*!< ADC1 IRQEN_1: DU1UP_IEN (Bitfield-Mask: 0x01)         */
#define ADC1_IRQEN_1_DU1LO_IEN_Pos        (24UL)                    /*!< ADC1 IRQEN_1: DU1LO_IEN (Bit 24)                      */
#define ADC1_IRQEN_1_DU1LO_IEN_Msk        (0x1000000UL)             /*!< ADC1 IRQEN_1: DU1LO_IEN (Bitfield-Mask: 0x01)         */
#define ADC1_IRQEN_1_ESM_IEN_Pos          (17UL)                    /*!< ADC1 IRQEN_1: ESM_IEN (Bit 17)                        */
#define ADC1_IRQEN_1_ESM_IEN_Msk          (0x20000UL)               /*!< ADC1 IRQEN_1: ESM_IEN (Bitfield-Mask: 0x01)           */
#define ADC1_IRQEN_1_EIM_IEN_Pos          (16UL)                    /*!< ADC1 IRQEN_1: EIM_IEN (Bit 16)                        */
#define ADC1_IRQEN_1_EIM_IEN_Msk          (0x10000UL)               /*!< ADC1 IRQEN_1: EIM_IEN (Bitfield-Mask: 0x01)           */
#define ADC1_IRQEN_1_P2_0_IEN_Pos         (12UL)                    /*!< ADC1 IRQEN_1: P2_0_IEN (Bit 12)                       */
#define ADC1_IRQEN_1_P2_0_IEN_Msk         (0x1000UL)                /*!< ADC1 IRQEN_1: P2_0_IEN (Bitfield-Mask: 0x01)          */
#define ADC1_IRQEN_1_P2_7_IEN_Pos         (11UL)                    /*!< ADC1 IRQEN_1: P2_7_IEN (Bit 11)                       */
#define ADC1_IRQEN_1_P2_7_IEN_Msk         (0x800UL)                 /*!< ADC1 IRQEN_1: P2_7_IEN (Bitfield-Mask: 0x01)          */
#define ADC1_IRQEN_1_P2_6_IEN_Pos         (10UL)                    /*!< ADC1 IRQEN_1: P2_6_IEN (Bit 10)                       */
#define ADC1_IRQEN_1_P2_6_IEN_Msk         (0x400UL)                 /*!< ADC1 IRQEN_1: P2_6_IEN (Bitfield-Mask: 0x01)          */
#define ADC1_IRQEN_1_P2_3_IEN_Pos         (9UL)                     /*!< ADC1 IRQEN_1: P2_3_IEN (Bit 9)                        */
#define ADC1_IRQEN_1_P2_3_IEN_Msk         (0x200UL)                 /*!< ADC1 IRQEN_1: P2_3_IEN (Bitfield-Mask: 0x01)          */
#define ADC1_IRQEN_1_P2_2_IEN_Pos         (8UL)                     /*!< ADC1 IRQEN_1: P2_2_IEN (Bit 8)                        */
#define ADC1_IRQEN_1_P2_2_IEN_Msk         (0x100UL)                 /*!< ADC1 IRQEN_1: P2_2_IEN (Bitfield-Mask: 0x01)          */
#define ADC1_IRQEN_1_P2_1_IEN_Pos         (7UL)                     /*!< ADC1 IRQEN_1: P2_1_IEN (Bit 7)                        */
#define ADC1_IRQEN_1_P2_1_IEN_Msk         (0x80UL)                  /*!< ADC1 IRQEN_1: P2_1_IEN (Bitfield-Mask: 0x01)          */
#define ADC1_IRQEN_1_MON5_IEN_Pos         (6UL)                     /*!< ADC1 IRQEN_1: MON5_IEN (Bit 6)                        */
#define ADC1_IRQEN_1_MON5_IEN_Msk         (0x40UL)                  /*!< ADC1 IRQEN_1: MON5_IEN (Bitfield-Mask: 0x01)          */
#define ADC1_IRQEN_1_MON4_IEN_Pos         (5UL)                     /*!< ADC1 IRQEN_1: MON4_IEN (Bit 5)                        */
#define ADC1_IRQEN_1_MON4_IEN_Msk         (0x20UL)                  /*!< ADC1 IRQEN_1: MON4_IEN (Bitfield-Mask: 0x01)          */
#define ADC1_IRQEN_1_MON3_IEN_Pos         (4UL)                     /*!< ADC1 IRQEN_1: MON3_IEN (Bit 4)                        */
#define ADC1_IRQEN_1_MON3_IEN_Msk         (0x10UL)                  /*!< ADC1 IRQEN_1: MON3_IEN (Bitfield-Mask: 0x01)          */
#define ADC1_IRQEN_1_MON2_IEN_Pos         (3UL)                     /*!< ADC1 IRQEN_1: MON2_IEN (Bit 3)                        */
#define ADC1_IRQEN_1_MON2_IEN_Msk         (0x8UL)                   /*!< ADC1 IRQEN_1: MON2_IEN (Bitfield-Mask: 0x01)          */
#define ADC1_IRQEN_1_MON1_IEN_Pos         (2UL)                     /*!< ADC1 IRQEN_1: MON1_IEN (Bit 2)                        */
#define ADC1_IRQEN_1_MON1_IEN_Msk         (0x4UL)                   /*!< ADC1 IRQEN_1: MON1_IEN (Bitfield-Mask: 0x01)          */
#define ADC1_IRQEN_1_VS_IEN_Pos           (1UL)                     /*!< ADC1 IRQEN_1: VS_IEN (Bit 1)                          */
#define ADC1_IRQEN_1_VS_IEN_Msk           (0x2UL)                   /*!< ADC1 IRQEN_1: VS_IEN (Bitfield-Mask: 0x01)            */
#define ADC1_IRQEN_1_VBATSEN_IEN_Pos      (0UL)                     /*!< ADC1 IRQEN_1: VBATSEN_IEN (Bit 0)                     */
#define ADC1_IRQEN_1_VBATSEN_IEN_Msk      (0x1UL)                   /*!< ADC1 IRQEN_1: VBATSEN_IEN (Bitfield-Mask: 0x01)       */
/* ========================================================  IRQEN_2  ======================================================== */
#define ADC1_IRQEN_2_P2_7_UP_IEN_Pos      (27UL)                    /*!< ADC1 IRQEN_2: P2_7_UP_IEN (Bit 27)                    */
#define ADC1_IRQEN_2_P2_7_UP_IEN_Msk      (0x8000000UL)             /*!< ADC1 IRQEN_2: P2_7_UP_IEN (Bitfield-Mask: 0x01)       */
#define ADC1_IRQEN_2_P2_6_UP_IEN_Pos      (26UL)                    /*!< ADC1 IRQEN_2: P2_6_UP_IEN (Bit 26)                    */
#define ADC1_IRQEN_2_P2_6_UP_IEN_Msk      (0x4000000UL)             /*!< ADC1 IRQEN_2: P2_6_UP_IEN (Bitfield-Mask: 0x01)       */
#define ADC1_IRQEN_2_P2_3_UP_IEN_Pos      (25UL)                    /*!< ADC1 IRQEN_2: P2_3_UP_IEN (Bit 25)                    */
#define ADC1_IRQEN_2_P2_3_UP_IEN_Msk      (0x2000000UL)             /*!< ADC1 IRQEN_2: P2_3_UP_IEN (Bitfield-Mask: 0x01)       */
#define ADC1_IRQEN_2_P2_2_UP_IEN_Pos      (24UL)                    /*!< ADC1 IRQEN_2: P2_2_UP_IEN (Bit 24)                    */
#define ADC1_IRQEN_2_P2_2_UP_IEN_Msk      (0x1000000UL)             /*!< ADC1 IRQEN_2: P2_2_UP_IEN (Bitfield-Mask: 0x01)       */
#define ADC1_IRQEN_2_P2_1_UP_IEN_Pos      (23UL)                    /*!< ADC1 IRQEN_2: P2_1_UP_IEN (Bit 23)                    */
#define ADC1_IRQEN_2_P2_1_UP_IEN_Msk      (0x800000UL)              /*!< ADC1 IRQEN_2: P2_1_UP_IEN (Bitfield-Mask: 0x01)       */
#define ADC1_IRQEN_2_MON5_UP_IEN_Pos      (22UL)                    /*!< ADC1 IRQEN_2: MON5_UP_IEN (Bit 22)                    */
#define ADC1_IRQEN_2_MON5_UP_IEN_Msk      (0x400000UL)              /*!< ADC1 IRQEN_2: MON5_UP_IEN (Bitfield-Mask: 0x01)       */
#define ADC1_IRQEN_2_MON4_UP_IEN_Pos      (21UL)                    /*!< ADC1 IRQEN_2: MON4_UP_IEN (Bit 21)                    */
#define ADC1_IRQEN_2_MON4_UP_IEN_Msk      (0x200000UL)              /*!< ADC1 IRQEN_2: MON4_UP_IEN (Bitfield-Mask: 0x01)       */
#define ADC1_IRQEN_2_MON3_UP_IEN_Pos      (20UL)                    /*!< ADC1 IRQEN_2: MON3_UP_IEN (Bit 20)                    */
#define ADC1_IRQEN_2_MON3_UP_IEN_Msk      (0x100000UL)              /*!< ADC1 IRQEN_2: MON3_UP_IEN (Bitfield-Mask: 0x01)       */
#define ADC1_IRQEN_2_MON2_UP_IEN_Pos      (19UL)                    /*!< ADC1 IRQEN_2: MON2_UP_IEN (Bit 19)                    */
#define ADC1_IRQEN_2_MON2_UP_IEN_Msk      (0x80000UL)               /*!< ADC1 IRQEN_2: MON2_UP_IEN (Bitfield-Mask: 0x01)       */
#define ADC1_IRQEN_2_MON1_UP_IEN_Pos      (18UL)                    /*!< ADC1 IRQEN_2: MON1_UP_IEN (Bit 18)                    */
#define ADC1_IRQEN_2_MON1_UP_IEN_Msk      (0x40000UL)               /*!< ADC1 IRQEN_2: MON1_UP_IEN (Bitfield-Mask: 0x01)       */
#define ADC1_IRQEN_2_VS_UP_IEN_Pos        (17UL)                    /*!< ADC1 IRQEN_2: VS_UP_IEN (Bit 17)                      */
#define ADC1_IRQEN_2_VS_UP_IEN_Msk        (0x20000UL)               /*!< ADC1 IRQEN_2: VS_UP_IEN (Bitfield-Mask: 0x01)         */
#define ADC1_IRQEN_2_P2_7_LO_IEN_Pos      (11UL)                    /*!< ADC1 IRQEN_2: P2_7_LO_IEN (Bit 11)                    */
#define ADC1_IRQEN_2_P2_7_LO_IEN_Msk      (0x800UL)                 /*!< ADC1 IRQEN_2: P2_7_LO_IEN (Bitfield-Mask: 0x01)       */
#define ADC1_IRQEN_2_P2_6_LO_IEN_Pos      (10UL)                    /*!< ADC1 IRQEN_2: P2_6_LO_IEN (Bit 10)                    */
#define ADC1_IRQEN_2_P2_6_LO_IEN_Msk      (0x400UL)                 /*!< ADC1 IRQEN_2: P2_6_LO_IEN (Bitfield-Mask: 0x01)       */
#define ADC1_IRQEN_2_P2_3_LO_IEN_Pos      (9UL)                     /*!< ADC1 IRQEN_2: P2_3_LO_IEN (Bit 9)                     */
#define ADC1_IRQEN_2_P2_3_LO_IEN_Msk      (0x200UL)                 /*!< ADC1 IRQEN_2: P2_3_LO_IEN (Bitfield-Mask: 0x01)       */
#define ADC1_IRQEN_2_P2_2_LO_IEN_Pos      (8UL)                     /*!< ADC1 IRQEN_2: P2_2_LO_IEN (Bit 8)                     */
#define ADC1_IRQEN_2_P2_2_LO_IEN_Msk      (0x100UL)                 /*!< ADC1 IRQEN_2: P2_2_LO_IEN (Bitfield-Mask: 0x01)       */
#define ADC1_IRQEN_2_P2_1_LO_IEN_Pos      (7UL)                     /*!< ADC1 IRQEN_2: P2_1_LO_IEN (Bit 7)                     */
#define ADC1_IRQEN_2_P2_1_LO_IEN_Msk      (0x80UL)                  /*!< ADC1 IRQEN_2: P2_1_LO_IEN (Bitfield-Mask: 0x01)       */
#define ADC1_IRQEN_2_MON5_LO_IEN_Pos      (6UL)                     /*!< ADC1 IRQEN_2: MON5_LO_IEN (Bit 6)                     */
#define ADC1_IRQEN_2_MON5_LO_IEN_Msk      (0x40UL)                  /*!< ADC1 IRQEN_2: MON5_LO_IEN (Bitfield-Mask: 0x01)       */
#define ADC1_IRQEN_2_MON4_LO_IEN_Pos      (5UL)                     /*!< ADC1 IRQEN_2: MON4_LO_IEN (Bit 5)                     */
#define ADC1_IRQEN_2_MON4_LO_IEN_Msk      (0x20UL)                  /*!< ADC1 IRQEN_2: MON4_LO_IEN (Bitfield-Mask: 0x01)       */
#define ADC1_IRQEN_2_MON3_LO_IEN_Pos      (4UL)                     /*!< ADC1 IRQEN_2: MON3_LO_IEN (Bit 4)                     */
#define ADC1_IRQEN_2_MON3_LO_IEN_Msk      (0x10UL)                  /*!< ADC1 IRQEN_2: MON3_LO_IEN (Bitfield-Mask: 0x01)       */
#define ADC1_IRQEN_2_MON2_LO_IEN_Pos      (3UL)                     /*!< ADC1 IRQEN_2: MON2_LO_IEN (Bit 3)                     */
#define ADC1_IRQEN_2_MON2_LO_IEN_Msk      (0x8UL)                   /*!< ADC1 IRQEN_2: MON2_LO_IEN (Bitfield-Mask: 0x01)       */
#define ADC1_IRQEN_2_MON1_LO_IEN_Pos      (2UL)                     /*!< ADC1 IRQEN_2: MON1_LO_IEN (Bit 2)                     */
#define ADC1_IRQEN_2_MON1_LO_IEN_Msk      (0x4UL)                   /*!< ADC1 IRQEN_2: MON1_LO_IEN (Bitfield-Mask: 0x01)       */
#define ADC1_IRQEN_2_VS_LO_IEN_Pos        (1UL)                     /*!< ADC1 IRQEN_2: VS_LO_IEN (Bit 1)                       */
#define ADC1_IRQEN_2_VS_LO_IEN_Msk        (0x2UL)                   /*!< ADC1 IRQEN_2: VS_LO_IEN (Bitfield-Mask: 0x01)         */
/* =======================================================  DUIN_SEL  ======================================================== */
#define ADC1_DUIN_SEL_DU4RES_NEG_Pos      (28UL)                    /*!< ADC1 DUIN_SEL: DU4RES_NEG (Bit 28)                    */
#define ADC1_DUIN_SEL_DU4RES_NEG_Msk      (0x10000000UL)            /*!< ADC1 DUIN_SEL: DU4RES_NEG (Bitfield-Mask: 0x01)       */
#define ADC1_DUIN_SEL_DU4_EN_Pos          (24UL)                    /*!< ADC1 DUIN_SEL: DU4_EN (Bit 24)                        */
#define ADC1_DUIN_SEL_DU4_EN_Msk          (0x1000000UL)             /*!< ADC1 DUIN_SEL: DU4_EN (Bitfield-Mask: 0x01)           */
#define ADC1_DUIN_SEL_DU3RES_NEG_Pos      (20UL)                    /*!< ADC1 DUIN_SEL: DU3RES_NEG (Bit 20)                    */
#define ADC1_DUIN_SEL_DU3RES_NEG_Msk      (0x100000UL)              /*!< ADC1 DUIN_SEL: DU3RES_NEG (Bitfield-Mask: 0x01)       */
#define ADC1_DUIN_SEL_DU3_EN_Pos          (16UL)                    /*!< ADC1 DUIN_SEL: DU3_EN (Bit 16)                        */
#define ADC1_DUIN_SEL_DU3_EN_Msk          (0x10000UL)               /*!< ADC1 DUIN_SEL: DU3_EN (Bitfield-Mask: 0x01)           */
#define ADC1_DUIN_SEL_DU2RES_NEG_Pos      (12UL)                    /*!< ADC1 DUIN_SEL: DU2RES_NEG (Bit 12)                    */
#define ADC1_DUIN_SEL_DU2RES_NEG_Msk      (0x1000UL)                /*!< ADC1 DUIN_SEL: DU2RES_NEG (Bitfield-Mask: 0x01)       */
#define ADC1_DUIN_SEL_DU2_EN_Pos          (8UL)                     /*!< ADC1 DUIN_SEL: DU2_EN (Bit 8)                         */
#define ADC1_DUIN_SEL_DU2_EN_Msk          (0x100UL)                 /*!< ADC1 DUIN_SEL: DU2_EN (Bitfield-Mask: 0x01)           */
#define ADC1_DUIN_SEL_DU1RES_NEG_Pos      (4UL)                     /*!< ADC1 DUIN_SEL: DU1RES_NEG (Bit 4)                     */
#define ADC1_DUIN_SEL_DU1RES_NEG_Msk      (0x10UL)                  /*!< ADC1 DUIN_SEL: DU1RES_NEG (Bitfield-Mask: 0x01)       */
#define ADC1_DUIN_SEL_DU1_EN_Pos          (0UL)                     /*!< ADC1 DUIN_SEL: DU1_EN (Bit 0)                         */
#define ADC1_DUIN_SEL_DU1_EN_Msk          (0x1UL)                   /*!< ADC1 DUIN_SEL: DU1_EN (Bitfield-Mask: 0x01)           */


/* =========================================================================================================================== */
/* ================                                           ADC2                                            ================ */
/* =========================================================================================================================== */

/* =======================================================  CTRL_STS  ======================================================== */
#define ADC2_CTRL_STS_IN_MUX_SEL_Pos      (8UL)                     /*!< ADC2 CTRL_STS: IN_MUX_SEL (Bit 8)                     */
#define ADC2_CTRL_STS_IN_MUX_SEL_Msk      (0xf00UL)                 /*!< ADC2 CTRL_STS: IN_MUX_SEL (Bitfield-Mask: 0x0f)       */
#define ADC2_CTRL_STS_EOC_Pos             (3UL)                     /*!< ADC2 CTRL_STS: EOC (Bit 3)                            */
#define ADC2_CTRL_STS_EOC_Msk             (0x8UL)                   /*!< ADC2 CTRL_STS: EOC (Bitfield-Mask: 0x01)              */
#define ADC2_CTRL_STS_SOS_Pos             (2UL)                     /*!< ADC2 CTRL_STS: SOS (Bit 2)                            */
#define ADC2_CTRL_STS_SOS_Msk             (0x4UL)                   /*!< ADC2 CTRL_STS: SOS (Bitfield-Mask: 0x01)              */
/* ========================================================  STATUS  ========================================================= */
#define ADC2_STATUS_READY_Pos             (1UL)                     /*!< ADC2 STATUS: READY (Bit 1)                            */
#define ADC2_STATUS_READY_Msk             (0x2UL)                   /*!< ADC2 STATUS: READY (Bitfield-Mask: 0x01)              */
/* =========================================================  CTRL1  ========================================================= */
#define ADC2_CTRL1_CALIB_EN_6_0_Pos       (0UL)                     /*!< ADC2 CTRL1: CALIB_EN_6_0 (Bit 0)                      */
#define ADC2_CTRL1_CALIB_EN_6_0_Msk       (0x7fUL)                  /*!< ADC2 CTRL1: CALIB_EN_6_0 (Bitfield-Mask: 0x7f)        */
/* =========================================================  CTRL2  ========================================================= */
#define ADC2_CTRL2_SAMPLE_TIME_int_Pos    (8UL)                     /*!< ADC2 CTRL2: SAMPLE_TIME_int (Bit 8)                   */
#define ADC2_CTRL2_SAMPLE_TIME_int_Msk    (0xf00UL)                 /*!< ADC2 CTRL2: SAMPLE_TIME_int (Bitfield-Mask: 0x0f)     */
#define ADC2_CTRL2_MCM_RDY_Pos            (7UL)                     /*!< ADC2 CTRL2: MCM_RDY (Bit 7)                           */
#define ADC2_CTRL2_MCM_RDY_Msk            (0x80UL)                  /*!< ADC2 CTRL2: MCM_RDY (Bitfield-Mask: 0x01)             */
#define ADC2_CTRL2_MCM_PD_N_Pos           (0UL)                     /*!< ADC2 CTRL2: MCM_PD_N (Bit 0)                          */
#define ADC2_CTRL2_MCM_PD_N_Msk           (0x1UL)                   /*!< ADC2 CTRL2: MCM_PD_N (Bitfield-Mask: 0x01)            */
/* =========================================================  CTRL4  ========================================================= */
#define ADC2_CTRL4_FILT_OUT_SEL_6_0_Pos   (0UL)                     /*!< ADC2 CTRL4: FILT_OUT_SEL_6_0 (Bit 0)                  */
#define ADC2_CTRL4_FILT_OUT_SEL_6_0_Msk   (0x7fUL)                  /*!< ADC2 CTRL4: FILT_OUT_SEL_6_0 (Bitfield-Mask: 0x7f)    */
/* =========================================================  SQ1_4  ========================================================= */
#define ADC2_SQ1_4_SQ4_Pos                (24UL)                    /*!< ADC2 SQ1_4: SQ4 (Bit 24)                              */
#define ADC2_SQ1_4_SQ4_Msk                (0x7f000000UL)            /*!< ADC2 SQ1_4: SQ4 (Bitfield-Mask: 0x7f)                 */
#define ADC2_SQ1_4_SQ3_Pos                (16UL)                    /*!< ADC2 SQ1_4: SQ3 (Bit 16)                              */
#define ADC2_SQ1_4_SQ3_Msk                (0x7f0000UL)              /*!< ADC2 SQ1_4: SQ3 (Bitfield-Mask: 0x7f)                 */
#define ADC2_SQ1_4_SQ2_Pos                (8UL)                     /*!< ADC2 SQ1_4: SQ2 (Bit 8)                               */
#define ADC2_SQ1_4_SQ2_Msk                (0x7f00UL)                /*!< ADC2 SQ1_4: SQ2 (Bitfield-Mask: 0x7f)                 */
#define ADC2_SQ1_4_SQ1_Pos                (0UL)                     /*!< ADC2 SQ1_4: SQ1 (Bit 0)                               */
#define ADC2_SQ1_4_SQ1_Msk                (0x7fUL)                  /*!< ADC2 SQ1_4: SQ1 (Bitfield-Mask: 0x7f)                 */
/* =========================================================  SQ5_8  ========================================================= */
#define ADC2_SQ5_8_SQ7_Pos                (16UL)                    /*!< ADC2 SQ5_8: SQ7 (Bit 16)                              */
#define ADC2_SQ5_8_SQ7_Msk                (0x7f0000UL)              /*!< ADC2 SQ5_8: SQ7 (Bitfield-Mask: 0x7f)                 */
#define ADC2_SQ5_8_SQ6_Pos                (8UL)                     /*!< ADC2 SQ5_8: SQ6 (Bit 8)                               */
#define ADC2_SQ5_8_SQ6_Msk                (0x7f00UL)                /*!< ADC2 SQ5_8: SQ6 (Bitfield-Mask: 0x7f)                 */
#define ADC2_SQ5_8_SQ5_Pos                (0UL)                     /*!< ADC2 SQ5_8: SQ5 (Bit 0)                               */
#define ADC2_SQ5_8_SQ5_Msk                (0x7fUL)                  /*!< ADC2 SQ5_8: SQ5 (Bitfield-Mask: 0x7f)                 */
/* =========================================================  SQ_FB  ========================================================= */
#define ADC2_SQ_FB_CHx_STS_Pos            (16UL)                    /*!< ADC2 SQ_FB: CHx_STS (Bit 16)                          */
#define ADC2_SQ_FB_CHx_STS_Msk            (0xf0000UL)               /*!< ADC2 SQ_FB: CHx_STS (Bitfield-Mask: 0x0f)             */
#define ADC2_SQ_FB_SQx_STS_Pos            (11UL)                    /*!< ADC2 SQ_FB: SQx_STS (Bit 11)                          */
#define ADC2_SQ_FB_SQx_STS_Msk            (0x3800UL)                /*!< ADC2 SQ_FB: SQx_STS (Bitfield-Mask: 0x07)             */
#define ADC2_SQ_FB_EIM_ACTIVE_Pos         (9UL)                     /*!< ADC2 SQ_FB: EIM_ACTIVE (Bit 9)                        */
#define ADC2_SQ_FB_EIM_ACTIVE_Msk         (0x200UL)                 /*!< ADC2 SQ_FB: EIM_ACTIVE (Bitfield-Mask: 0x01)          */
#define ADC2_SQ_FB_SQ_STOP_Pos            (8UL)                     /*!< ADC2 SQ_FB: SQ_STOP (Bit 8)                           */
#define ADC2_SQ_FB_SQ_STOP_Msk            (0x100UL)                 /*!< ADC2 SQ_FB: SQ_STOP (Bitfield-Mask: 0x01)             */
#define ADC2_SQ_FB_SQ_FB_Pos              (0UL)                     /*!< ADC2 SQ_FB: SQ_FB (Bit 0)                             */
#define ADC2_SQ_FB_SQ_FB_Msk              (0xfUL)                   /*!< ADC2 SQ_FB: SQ_FB (Bitfield-Mask: 0x0f)               */
/* ========================================================  CHx_EIM  ======================================================== */
#define ADC2_CHx_EIM_SEL_Pos              (12UL)                    /*!< ADC2 CHx_EIM: SEL (Bit 12)                            */
#define ADC2_CHx_EIM_SEL_Msk              (0x1000UL)                /*!< ADC2 CHx_EIM: SEL (Bitfield-Mask: 0x01)               */
#define ADC2_CHx_EIM_EN_Pos               (11UL)                    /*!< ADC2 CHx_EIM: EN (Bit 11)                             */
#define ADC2_CHx_EIM_EN_Msk               (0x800UL)                 /*!< ADC2 CHx_EIM: EN (Bitfield-Mask: 0x01)                */
#define ADC2_CHx_EIM_REP_Pos              (8UL)                     /*!< ADC2 CHx_EIM: REP (Bit 8)                             */
#define ADC2_CHx_EIM_REP_Msk              (0x700UL)                 /*!< ADC2 CHx_EIM: REP (Bitfield-Mask: 0x07)               */
#define ADC2_CHx_EIM_CHx_SEL_Pos          (0UL)                     /*!< ADC2 CHx_EIM: CHx_SEL (Bit 0)                         */
#define ADC2_CHx_EIM_CHx_SEL_Msk          (0x7UL)                   /*!< ADC2 CHx_EIM: CHx_SEL (Bitfield-Mask: 0x07)           */
/* =======================================================  MAX_TIME  ======================================================== */
#define ADC2_MAX_TIME_MAX_TIME_Pos        (0UL)                     /*!< ADC2 MAX_TIME: MAX_TIME (Bit 0)                       */
#define ADC2_MAX_TIME_MAX_TIME_Msk        (0xffUL)                  /*!< ADC2 MAX_TIME: MAX_TIME (Bitfield-Mask: 0xff)         */
/* =======================================================  CAL_CH0_1  ======================================================= */
#define ADC2_CAL_CH0_1_GAIN_CH1_Pos       (24UL)                    /*!< ADC2 CAL_CH0_1: GAIN_CH1 (Bit 24)                     */
#define ADC2_CAL_CH0_1_GAIN_CH1_Msk       (0xff000000UL)            /*!< ADC2 CAL_CH0_1: GAIN_CH1 (Bitfield-Mask: 0xff)        */
#define ADC2_CAL_CH0_1_OFFS_CH1_Pos       (16UL)                    /*!< ADC2 CAL_CH0_1: OFFS_CH1 (Bit 16)                     */
#define ADC2_CAL_CH0_1_OFFS_CH1_Msk       (0x1f0000UL)              /*!< ADC2 CAL_CH0_1: OFFS_CH1 (Bitfield-Mask: 0x1f)        */
#define ADC2_CAL_CH0_1_GAIN_CH0_Pos       (8UL)                     /*!< ADC2 CAL_CH0_1: GAIN_CH0 (Bit 8)                      */
#define ADC2_CAL_CH0_1_GAIN_CH0_Msk       (0xff00UL)                /*!< ADC2 CAL_CH0_1: GAIN_CH0 (Bitfield-Mask: 0xff)        */
#define ADC2_CAL_CH0_1_OFFS_CH0_Pos       (0UL)                     /*!< ADC2 CAL_CH0_1: OFFS_CH0 (Bit 0)                      */
#define ADC2_CAL_CH0_1_OFFS_CH0_Msk       (0x1fUL)                  /*!< ADC2 CAL_CH0_1: OFFS_CH0 (Bitfield-Mask: 0x1f)        */
/* =======================================================  CAL_CH2_3  ======================================================= */
#define ADC2_CAL_CH2_3_GAIN_CH3_Pos       (24UL)                    /*!< ADC2 CAL_CH2_3: GAIN_CH3 (Bit 24)                     */
#define ADC2_CAL_CH2_3_GAIN_CH3_Msk       (0xff000000UL)            /*!< ADC2 CAL_CH2_3: GAIN_CH3 (Bitfield-Mask: 0xff)        */
#define ADC2_CAL_CH2_3_OFFS_CH3_Pos       (16UL)                    /*!< ADC2 CAL_CH2_3: OFFS_CH3 (Bit 16)                     */
#define ADC2_CAL_CH2_3_OFFS_CH3_Msk       (0x1f0000UL)              /*!< ADC2 CAL_CH2_3: OFFS_CH3 (Bitfield-Mask: 0x1f)        */
#define ADC2_CAL_CH2_3_GAIN_CH2_Pos       (8UL)                     /*!< ADC2 CAL_CH2_3: GAIN_CH2 (Bit 8)                      */
#define ADC2_CAL_CH2_3_GAIN_CH2_Msk       (0xff00UL)                /*!< ADC2 CAL_CH2_3: GAIN_CH2 (Bitfield-Mask: 0xff)        */
#define ADC2_CAL_CH2_3_OFFS_CH2_Pos       (0UL)                     /*!< ADC2 CAL_CH2_3: OFFS_CH2 (Bit 0)                      */
#define ADC2_CAL_CH2_3_OFFS_CH2_Msk       (0x1fUL)                  /*!< ADC2 CAL_CH2_3: OFFS_CH2 (Bitfield-Mask: 0x1f)        */
/* =======================================================  CAL_CH4_5  ======================================================= */
#define ADC2_CAL_CH4_5_GAIN_CH5_Pos       (24UL)                    /*!< ADC2 CAL_CH4_5: GAIN_CH5 (Bit 24)                     */
#define ADC2_CAL_CH4_5_GAIN_CH5_Msk       (0xff000000UL)            /*!< ADC2 CAL_CH4_5: GAIN_CH5 (Bitfield-Mask: 0xff)        */
#define ADC2_CAL_CH4_5_OFFS_CH5_Pos       (16UL)                    /*!< ADC2 CAL_CH4_5: OFFS_CH5 (Bit 16)                     */
#define ADC2_CAL_CH4_5_OFFS_CH5_Msk       (0x1f0000UL)              /*!< ADC2 CAL_CH4_5: OFFS_CH5 (Bitfield-Mask: 0x1f)        */
#define ADC2_CAL_CH4_5_GAIN_CH4_Pos       (8UL)                     /*!< ADC2 CAL_CH4_5: GAIN_CH4 (Bit 8)                      */
#define ADC2_CAL_CH4_5_GAIN_CH4_Msk       (0xff00UL)                /*!< ADC2 CAL_CH4_5: GAIN_CH4 (Bitfield-Mask: 0xff)        */
#define ADC2_CAL_CH4_5_OFFS_CH4_Pos       (0UL)                     /*!< ADC2 CAL_CH4_5: OFFS_CH4 (Bit 0)                      */
#define ADC2_CAL_CH4_5_OFFS_CH4_Msk       (0x1fUL)                  /*!< ADC2 CAL_CH4_5: OFFS_CH4 (Bitfield-Mask: 0x1f)        */
/* =======================================================  CAL_CH6_7  ======================================================= */
#define ADC2_CAL_CH6_7_GAIN_CH6_Pos       (8UL)                     /*!< ADC2 CAL_CH6_7: GAIN_CH6 (Bit 8)                      */
#define ADC2_CAL_CH6_7_GAIN_CH6_Msk       (0xff00UL)                /*!< ADC2 CAL_CH6_7: GAIN_CH6 (Bitfield-Mask: 0xff)        */
#define ADC2_CAL_CH6_7_OFFS_CH6_Pos       (0UL)                     /*!< ADC2 CAL_CH6_7: OFFS_CH6 (Bit 0)                      */
#define ADC2_CAL_CH6_7_OFFS_CH6_Msk       (0x1fUL)                  /*!< ADC2 CAL_CH6_7: OFFS_CH6 (Bitfield-Mask: 0x1f)        */
/* =====================================================  FILTCOEFF0_7  ====================================================== */
#define ADC2_FILTCOEFF0_7_A_CH7_Pos       (14UL)                    /*!< ADC2 FILTCOEFF0_7: A_CH7 (Bit 14)                     */
#define ADC2_FILTCOEFF0_7_A_CH7_Msk       (0xc000UL)                /*!< ADC2 FILTCOEFF0_7: A_CH7 (Bitfield-Mask: 0x03)        */
#define ADC2_FILTCOEFF0_7_A_CH6_Pos       (12UL)                    /*!< ADC2 FILTCOEFF0_7: A_CH6 (Bit 12)                     */
#define ADC2_FILTCOEFF0_7_A_CH6_Msk       (0x3000UL)                /*!< ADC2 FILTCOEFF0_7: A_CH6 (Bitfield-Mask: 0x03)        */
#define ADC2_FILTCOEFF0_7_A_CH5_Pos       (10UL)                    /*!< ADC2 FILTCOEFF0_7: A_CH5 (Bit 10)                     */
#define ADC2_FILTCOEFF0_7_A_CH5_Msk       (0xc00UL)                 /*!< ADC2 FILTCOEFF0_7: A_CH5 (Bitfield-Mask: 0x03)        */
#define ADC2_FILTCOEFF0_7_A_CH4_Pos       (8UL)                     /*!< ADC2 FILTCOEFF0_7: A_CH4 (Bit 8)                      */
#define ADC2_FILTCOEFF0_7_A_CH4_Msk       (0x300UL)                 /*!< ADC2 FILTCOEFF0_7: A_CH4 (Bitfield-Mask: 0x03)        */
#define ADC2_FILTCOEFF0_7_A_CH3_Pos       (6UL)                     /*!< ADC2 FILTCOEFF0_7: A_CH3 (Bit 6)                      */
#define ADC2_FILTCOEFF0_7_A_CH3_Msk       (0xc0UL)                  /*!< ADC2 FILTCOEFF0_7: A_CH3 (Bitfield-Mask: 0x03)        */
#define ADC2_FILTCOEFF0_7_A_CH2_Pos       (4UL)                     /*!< ADC2 FILTCOEFF0_7: A_CH2 (Bit 4)                      */
#define ADC2_FILTCOEFF0_7_A_CH2_Msk       (0x30UL)                  /*!< ADC2 FILTCOEFF0_7: A_CH2 (Bitfield-Mask: 0x03)        */
#define ADC2_FILTCOEFF0_7_A_CH1_Pos       (2UL)                     /*!< ADC2 FILTCOEFF0_7: A_CH1 (Bit 2)                      */
#define ADC2_FILTCOEFF0_7_A_CH1_Msk       (0xcUL)                   /*!< ADC2 FILTCOEFF0_7: A_CH1 (Bitfield-Mask: 0x03)        */
#define ADC2_FILTCOEFF0_7_A_CH0_Pos       (0UL)                     /*!< ADC2 FILTCOEFF0_7: A_CH0 (Bit 0)                      */
#define ADC2_FILTCOEFF0_7_A_CH0_Msk       (0x3UL)                   /*!< ADC2 FILTCOEFF0_7: A_CH0 (Bitfield-Mask: 0x03)        */
/* =======================================================  FILT_OUT0  ======================================================= */
#define ADC2_FILT_OUT0_OUT_CH0_Pos        (0UL)                     /*!< ADC2 FILT_OUT0: OUT_CH0 (Bit 0)                       */
#define ADC2_FILT_OUT0_OUT_CH0_Msk        (0x3ffUL)                 /*!< ADC2 FILT_OUT0: OUT_CH0 (Bitfield-Mask: 0x3ff)        */
/* =======================================================  FILT_OUT1  ======================================================= */
#define ADC2_FILT_OUT1_OUT_CH1_Pos        (0UL)                     /*!< ADC2 FILT_OUT1: OUT_CH1 (Bit 0)                       */
#define ADC2_FILT_OUT1_OUT_CH1_Msk        (0x3ffUL)                 /*!< ADC2 FILT_OUT1: OUT_CH1 (Bitfield-Mask: 0x3ff)        */
/* =======================================================  FILT_OUT2  ======================================================= */
#define ADC2_FILT_OUT2_OUT_CH2_Pos        (0UL)                     /*!< ADC2 FILT_OUT2: OUT_CH2 (Bit 0)                       */
#define ADC2_FILT_OUT2_OUT_CH2_Msk        (0x3ffUL)                 /*!< ADC2 FILT_OUT2: OUT_CH2 (Bitfield-Mask: 0x3ff)        */
/* =======================================================  FILT_OUT3  ======================================================= */
#define ADC2_FILT_OUT3_OUT_CH3_Pos        (0UL)                     /*!< ADC2 FILT_OUT3: OUT_CH3 (Bit 0)                       */
#define ADC2_FILT_OUT3_OUT_CH3_Msk        (0x3ffUL)                 /*!< ADC2 FILT_OUT3: OUT_CH3 (Bitfield-Mask: 0x3ff)        */
/* =======================================================  FILT_OUT4  ======================================================= */
#define ADC2_FILT_OUT4_OUT_CH4_Pos        (0UL)                     /*!< ADC2 FILT_OUT4: OUT_CH4 (Bit 0)                       */
#define ADC2_FILT_OUT4_OUT_CH4_Msk        (0x3ffUL)                 /*!< ADC2 FILT_OUT4: OUT_CH4 (Bitfield-Mask: 0x3ff)        */
/* =======================================================  FILT_OUT5  ======================================================= */
#define ADC2_FILT_OUT5_OUT_CH5_Pos        (0UL)                     /*!< ADC2 FILT_OUT5: OUT_CH5 (Bit 0)                       */
#define ADC2_FILT_OUT5_OUT_CH5_Msk        (0x3ffUL)                 /*!< ADC2 FILT_OUT5: OUT_CH5 (Bitfield-Mask: 0x3ff)        */
/* =======================================================  FILT_OUT6  ======================================================= */
#define ADC2_FILT_OUT6_OUT_CH6_Pos        (0UL)                     /*!< ADC2 FILT_OUT6: OUT_CH6 (Bit 0)                       */
#define ADC2_FILT_OUT6_OUT_CH6_Msk        (0x3ffUL)                 /*!< ADC2 FILT_OUT6: OUT_CH6 (Bitfield-Mask: 0x3ff)        */
/* =====================================================  FILT_UP_CTRL  ====================================================== */
#define ADC2_FILT_UP_CTRL_UPEN_Ch6_Pos    (6UL)                     /*!< ADC2 FILT_UP_CTRL: UPEN_Ch6 (Bit 6)                   */
#define ADC2_FILT_UP_CTRL_UPEN_Ch6_Msk    (0x40UL)                  /*!< ADC2 FILT_UP_CTRL: UPEN_Ch6 (Bitfield-Mask: 0x01)     */
#define ADC2_FILT_UP_CTRL_UPEN_Ch5_Pos    (5UL)                     /*!< ADC2 FILT_UP_CTRL: UPEN_Ch5 (Bit 5)                   */
#define ADC2_FILT_UP_CTRL_UPEN_Ch5_Msk    (0x20UL)                  /*!< ADC2 FILT_UP_CTRL: UPEN_Ch5 (Bitfield-Mask: 0x01)     */
#define ADC2_FILT_UP_CTRL_UPEN_Ch4_Pos    (4UL)                     /*!< ADC2 FILT_UP_CTRL: UPEN_Ch4 (Bit 4)                   */
#define ADC2_FILT_UP_CTRL_UPEN_Ch4_Msk    (0x10UL)                  /*!< ADC2 FILT_UP_CTRL: UPEN_Ch4 (Bitfield-Mask: 0x01)     */
#define ADC2_FILT_UP_CTRL_UPEN_Ch3_Pos    (3UL)                     /*!< ADC2 FILT_UP_CTRL: UPEN_Ch3 (Bit 3)                   */
#define ADC2_FILT_UP_CTRL_UPEN_Ch3_Msk    (0x8UL)                   /*!< ADC2 FILT_UP_CTRL: UPEN_Ch3 (Bitfield-Mask: 0x01)     */
#define ADC2_FILT_UP_CTRL_UPEN_Ch2_Pos    (2UL)                     /*!< ADC2 FILT_UP_CTRL: UPEN_Ch2 (Bit 2)                   */
#define ADC2_FILT_UP_CTRL_UPEN_Ch2_Msk    (0x4UL)                   /*!< ADC2 FILT_UP_CTRL: UPEN_Ch2 (Bitfield-Mask: 0x01)     */
#define ADC2_FILT_UP_CTRL_UPEN_Ch1_Pos    (1UL)                     /*!< ADC2 FILT_UP_CTRL: UPEN_Ch1 (Bit 1)                   */
#define ADC2_FILT_UP_CTRL_UPEN_Ch1_Msk    (0x2UL)                   /*!< ADC2 FILT_UP_CTRL: UPEN_Ch1 (Bitfield-Mask: 0x01)     */
#define ADC2_FILT_UP_CTRL_UPEN_Ch0_Pos    (0UL)                     /*!< ADC2 FILT_UP_CTRL: UPEN_Ch0 (Bit 0)                   */
#define ADC2_FILT_UP_CTRL_UPEN_Ch0_Msk    (0x1UL)                   /*!< ADC2 FILT_UP_CTRL: UPEN_Ch0 (Bitfield-Mask: 0x01)     */
/* =====================================================  FILT_LO_CTRL  ====================================================== */
#define ADC2_FILT_LO_CTRL_LOEN_Ch6_Pos    (6UL)                     /*!< ADC2 FILT_LO_CTRL: LOEN_Ch6 (Bit 6)                   */
#define ADC2_FILT_LO_CTRL_LOEN_Ch6_Msk    (0x40UL)                  /*!< ADC2 FILT_LO_CTRL: LOEN_Ch6 (Bitfield-Mask: 0x01)     */
#define ADC2_FILT_LO_CTRL_LOEN_Ch5_Pos    (5UL)                     /*!< ADC2 FILT_LO_CTRL: LOEN_Ch5 (Bit 5)                   */
#define ADC2_FILT_LO_CTRL_LOEN_Ch5_Msk    (0x20UL)                  /*!< ADC2 FILT_LO_CTRL: LOEN_Ch5 (Bitfield-Mask: 0x01)     */
#define ADC2_FILT_LO_CTRL_LOEN_Ch4_Pos    (4UL)                     /*!< ADC2 FILT_LO_CTRL: LOEN_Ch4 (Bit 4)                   */
#define ADC2_FILT_LO_CTRL_LOEN_Ch4_Msk    (0x10UL)                  /*!< ADC2 FILT_LO_CTRL: LOEN_Ch4 (Bitfield-Mask: 0x01)     */
#define ADC2_FILT_LO_CTRL_LOEN_Ch3_Pos    (3UL)                     /*!< ADC2 FILT_LO_CTRL: LOEN_Ch3 (Bit 3)                   */
#define ADC2_FILT_LO_CTRL_LOEN_Ch3_Msk    (0x8UL)                   /*!< ADC2 FILT_LO_CTRL: LOEN_Ch3 (Bitfield-Mask: 0x01)     */
#define ADC2_FILT_LO_CTRL_LOEN_Ch2_Pos    (2UL)                     /*!< ADC2 FILT_LO_CTRL: LOEN_Ch2 (Bit 2)                   */
#define ADC2_FILT_LO_CTRL_LOEN_Ch2_Msk    (0x4UL)                   /*!< ADC2 FILT_LO_CTRL: LOEN_Ch2 (Bitfield-Mask: 0x01)     */
#define ADC2_FILT_LO_CTRL_LOEN_Ch1_Pos    (1UL)                     /*!< ADC2 FILT_LO_CTRL: LOEN_Ch1 (Bit 1)                   */
#define ADC2_FILT_LO_CTRL_LOEN_Ch1_Msk    (0x2UL)                   /*!< ADC2 FILT_LO_CTRL: LOEN_Ch1 (Bitfield-Mask: 0x01)     */
#define ADC2_FILT_LO_CTRL_LOEN_Ch0_Pos    (0UL)                     /*!< ADC2 FILT_LO_CTRL: LOEN_Ch0 (Bit 0)                   */
#define ADC2_FILT_LO_CTRL_LOEN_Ch0_Msk    (0x1UL)                   /*!< ADC2 FILT_LO_CTRL: LOEN_Ch0 (Bitfield-Mask: 0x01)     */
/* =======================================================  MMODE0_7  ======================================================== */
#define ADC2_MMODE0_7_MSEL_Ch7_Pos        (14UL)                    /*!< ADC2 MMODE0_7: MSEL_Ch7 (Bit 14)                      */
#define ADC2_MMODE0_7_MSEL_Ch7_Msk        (0xc000UL)                /*!< ADC2 MMODE0_7: MSEL_Ch7 (Bitfield-Mask: 0x03)         */
#define ADC2_MMODE0_7_MSEL_Ch6_Pos        (12UL)                    /*!< ADC2 MMODE0_7: MSEL_Ch6 (Bit 12)                      */
#define ADC2_MMODE0_7_MSEL_Ch6_Msk        (0x3000UL)                /*!< ADC2 MMODE0_7: MSEL_Ch6 (Bitfield-Mask: 0x03)         */
#define ADC2_MMODE0_7_MSEL_Ch5_Pos        (10UL)                    /*!< ADC2 MMODE0_7: MSEL_Ch5 (Bit 10)                      */
#define ADC2_MMODE0_7_MSEL_Ch5_Msk        (0xc00UL)                 /*!< ADC2 MMODE0_7: MSEL_Ch5 (Bitfield-Mask: 0x03)         */
#define ADC2_MMODE0_7_MSEL_Ch4_Pos        (8UL)                     /*!< ADC2 MMODE0_7: MSEL_Ch4 (Bit 8)                       */
#define ADC2_MMODE0_7_MSEL_Ch4_Msk        (0x300UL)                 /*!< ADC2 MMODE0_7: MSEL_Ch4 (Bitfield-Mask: 0x03)         */
#define ADC2_MMODE0_7_MSEL_Ch3_Pos        (6UL)                     /*!< ADC2 MMODE0_7: MSEL_Ch3 (Bit 6)                       */
#define ADC2_MMODE0_7_MSEL_Ch3_Msk        (0xc0UL)                  /*!< ADC2 MMODE0_7: MSEL_Ch3 (Bitfield-Mask: 0x03)         */
#define ADC2_MMODE0_7_MSEL_Ch2_Pos        (4UL)                     /*!< ADC2 MMODE0_7: MSEL_Ch2 (Bit 4)                       */
#define ADC2_MMODE0_7_MSEL_Ch2_Msk        (0x30UL)                  /*!< ADC2 MMODE0_7: MSEL_Ch2 (Bitfield-Mask: 0x03)         */
#define ADC2_MMODE0_7_MSEL_Ch1_Pos        (2UL)                     /*!< ADC2 MMODE0_7: MSEL_Ch1 (Bit 2)                       */
#define ADC2_MMODE0_7_MSEL_Ch1_Msk        (0xcUL)                   /*!< ADC2 MMODE0_7: MSEL_Ch1 (Bitfield-Mask: 0x03)         */
#define ADC2_MMODE0_7_MSEL_Ch0_Pos        (0UL)                     /*!< ADC2 MMODE0_7: MSEL_Ch0 (Bit 0)                       */
#define ADC2_MMODE0_7_MSEL_Ch0_Msk        (0x3UL)                   /*!< ADC2 MMODE0_7: MSEL_Ch0 (Bitfield-Mask: 0x03)         */
/* ======================================================  TH0_3_UPPER  ====================================================== */
#define ADC2_TH0_3_UPPER_THUP_CH3_Pos     (24UL)                    /*!< ADC2 TH0_3_UPPER: THUP_CH3 (Bit 24)                   */
#define ADC2_TH0_3_UPPER_THUP_CH3_Msk     (0xff000000UL)            /*!< ADC2 TH0_3_UPPER: THUP_CH3 (Bitfield-Mask: 0xff)      */
#define ADC2_TH0_3_UPPER_THUP_CH2_Pos     (16UL)                    /*!< ADC2 TH0_3_UPPER: THUP_CH2 (Bit 16)                   */
#define ADC2_TH0_3_UPPER_THUP_CH2_Msk     (0xff0000UL)              /*!< ADC2 TH0_3_UPPER: THUP_CH2 (Bitfield-Mask: 0xff)      */
#define ADC2_TH0_3_UPPER_THUP_CH1_Pos     (8UL)                     /*!< ADC2 TH0_3_UPPER: THUP_CH1 (Bit 8)                    */
#define ADC2_TH0_3_UPPER_THUP_CH1_Msk     (0xff00UL)                /*!< ADC2 TH0_3_UPPER: THUP_CH1 (Bitfield-Mask: 0xff)      */
#define ADC2_TH0_3_UPPER_THUP_CH0_Pos     (0UL)                     /*!< ADC2 TH0_3_UPPER: THUP_CH0 (Bit 0)                    */
#define ADC2_TH0_3_UPPER_THUP_CH0_Msk     (0xffUL)                  /*!< ADC2 TH0_3_UPPER: THUP_CH0 (Bitfield-Mask: 0xff)      */
/* ======================================================  TH4_7_UPPER  ====================================================== */
#define ADC2_TH4_7_UPPER_THUP_CH7_Pos     (24UL)                    /*!< ADC2 TH4_7_UPPER: THUP_CH7 (Bit 24)                   */
#define ADC2_TH4_7_UPPER_THUP_CH7_Msk     (0xff000000UL)            /*!< ADC2 TH4_7_UPPER: THUP_CH7 (Bitfield-Mask: 0xff)      */
#define ADC2_TH4_7_UPPER_THUP_CH6_Pos     (16UL)                    /*!< ADC2 TH4_7_UPPER: THUP_CH6 (Bit 16)                   */
#define ADC2_TH4_7_UPPER_THUP_CH6_Msk     (0xff0000UL)              /*!< ADC2 TH4_7_UPPER: THUP_CH6 (Bitfield-Mask: 0xff)      */
#define ADC2_TH4_7_UPPER_THUP_CH5_Pos     (8UL)                     /*!< ADC2 TH4_7_UPPER: THUP_CH5 (Bit 8)                    */
#define ADC2_TH4_7_UPPER_THUP_CH5_Msk     (0xff00UL)                /*!< ADC2 TH4_7_UPPER: THUP_CH5 (Bitfield-Mask: 0xff)      */
#define ADC2_TH4_7_UPPER_THUP_CH4_Pos     (0UL)                     /*!< ADC2 TH4_7_UPPER: THUP_CH4 (Bit 0)                    */
#define ADC2_TH4_7_UPPER_THUP_CH4_Msk     (0xffUL)                  /*!< ADC2 TH4_7_UPPER: THUP_CH4 (Bitfield-Mask: 0xff)      */
/* =====================================================  CNT0_3_UPPER  ====================================================== */
#define ADC2_CNT0_3_UPPER_HYST_UP_CH3_Pos (27UL)                    /*!< ADC2 CNT0_3_UPPER: HYST_UP_CH3 (Bit 27)               */
#define ADC2_CNT0_3_UPPER_HYST_UP_CH3_Msk (0x18000000UL)            /*!< ADC2 CNT0_3_UPPER: HYST_UP_CH3 (Bitfield-Mask: 0x03)  */
#define ADC2_CNT0_3_UPPER_CNT_UP_CH3_Pos  (24UL)                    /*!< ADC2 CNT0_3_UPPER: CNT_UP_CH3 (Bit 24)                */
#define ADC2_CNT0_3_UPPER_CNT_UP_CH3_Msk  (0x7000000UL)             /*!< ADC2 CNT0_3_UPPER: CNT_UP_CH3 (Bitfield-Mask: 0x07)   */
#define ADC2_CNT0_3_UPPER_HYST_UP_CH2_Pos (19UL)                    /*!< ADC2 CNT0_3_UPPER: HYST_UP_CH2 (Bit 19)               */
#define ADC2_CNT0_3_UPPER_HYST_UP_CH2_Msk (0x180000UL)              /*!< ADC2 CNT0_3_UPPER: HYST_UP_CH2 (Bitfield-Mask: 0x03)  */
#define ADC2_CNT0_3_UPPER_CNT_UP_CH2_Pos  (16UL)                    /*!< ADC2 CNT0_3_UPPER: CNT_UP_CH2 (Bit 16)                */
#define ADC2_CNT0_3_UPPER_CNT_UP_CH2_Msk  (0x70000UL)               /*!< ADC2 CNT0_3_UPPER: CNT_UP_CH2 (Bitfield-Mask: 0x07)   */
#define ADC2_CNT0_3_UPPER_HYST_UP_CH1_Pos (11UL)                    /*!< ADC2 CNT0_3_UPPER: HYST_UP_CH1 (Bit 11)               */
#define ADC2_CNT0_3_UPPER_HYST_UP_CH1_Msk (0x1800UL)                /*!< ADC2 CNT0_3_UPPER: HYST_UP_CH1 (Bitfield-Mask: 0x03)  */
#define ADC2_CNT0_3_UPPER_CNT_UP_CH1_Pos  (8UL)                     /*!< ADC2 CNT0_3_UPPER: CNT_UP_CH1 (Bit 8)                 */
#define ADC2_CNT0_3_UPPER_CNT_UP_CH1_Msk  (0x700UL)                 /*!< ADC2 CNT0_3_UPPER: CNT_UP_CH1 (Bitfield-Mask: 0x07)   */
#define ADC2_CNT0_3_UPPER_HYST_UP_CH0_Pos (3UL)                     /*!< ADC2 CNT0_3_UPPER: HYST_UP_CH0 (Bit 3)                */
#define ADC2_CNT0_3_UPPER_HYST_UP_CH0_Msk (0x18UL)                  /*!< ADC2 CNT0_3_UPPER: HYST_UP_CH0 (Bitfield-Mask: 0x03)  */
#define ADC2_CNT0_3_UPPER_CNT_UP_CH0_Pos  (0UL)                     /*!< ADC2 CNT0_3_UPPER: CNT_UP_CH0 (Bit 0)                 */
#define ADC2_CNT0_3_UPPER_CNT_UP_CH0_Msk  (0x7UL)                   /*!< ADC2 CNT0_3_UPPER: CNT_UP_CH0 (Bitfield-Mask: 0x07)   */
/* =====================================================  CNT4_7_UPPER  ====================================================== */
#define ADC2_CNT4_7_UPPER_HYST_UP_CH7_Pos (27UL)                    /*!< ADC2 CNT4_7_UPPER: HYST_UP_CH7 (Bit 27)               */
#define ADC2_CNT4_7_UPPER_HYST_UP_CH7_Msk (0x18000000UL)            /*!< ADC2 CNT4_7_UPPER: HYST_UP_CH7 (Bitfield-Mask: 0x03)  */
#define ADC2_CNT4_7_UPPER_CNT_UP_CH7_Pos  (24UL)                    /*!< ADC2 CNT4_7_UPPER: CNT_UP_CH7 (Bit 24)                */
#define ADC2_CNT4_7_UPPER_CNT_UP_CH7_Msk  (0x7000000UL)             /*!< ADC2 CNT4_7_UPPER: CNT_UP_CH7 (Bitfield-Mask: 0x07)   */
#define ADC2_CNT4_7_UPPER_HYST_UP_CH6_Pos (19UL)                    /*!< ADC2 CNT4_7_UPPER: HYST_UP_CH6 (Bit 19)               */
#define ADC2_CNT4_7_UPPER_HYST_UP_CH6_Msk (0x180000UL)              /*!< ADC2 CNT4_7_UPPER: HYST_UP_CH6 (Bitfield-Mask: 0x03)  */
#define ADC2_CNT4_7_UPPER_CNT_UP_CH6_Pos  (16UL)                    /*!< ADC2 CNT4_7_UPPER: CNT_UP_CH6 (Bit 16)                */
#define ADC2_CNT4_7_UPPER_CNT_UP_CH6_Msk  (0x70000UL)               /*!< ADC2 CNT4_7_UPPER: CNT_UP_CH6 (Bitfield-Mask: 0x07)   */
#define ADC2_CNT4_7_UPPER_HYST_UP_CH5_Pos (11UL)                    /*!< ADC2 CNT4_7_UPPER: HYST_UP_CH5 (Bit 11)               */
#define ADC2_CNT4_7_UPPER_HYST_UP_CH5_Msk (0x1800UL)                /*!< ADC2 CNT4_7_UPPER: HYST_UP_CH5 (Bitfield-Mask: 0x03)  */
#define ADC2_CNT4_7_UPPER_CNT_UP_CH5_Pos  (8UL)                     /*!< ADC2 CNT4_7_UPPER: CNT_UP_CH5 (Bit 8)                 */
#define ADC2_CNT4_7_UPPER_CNT_UP_CH5_Msk  (0x700UL)                 /*!< ADC2 CNT4_7_UPPER: CNT_UP_CH5 (Bitfield-Mask: 0x07)   */
#define ADC2_CNT4_7_UPPER_HYST_UP_CH4_Pos (3UL)                     /*!< ADC2 CNT4_7_UPPER: HYST_UP_CH4 (Bit 3)                */
#define ADC2_CNT4_7_UPPER_HYST_UP_CH4_Msk (0x18UL)                  /*!< ADC2 CNT4_7_UPPER: HYST_UP_CH4 (Bitfield-Mask: 0x03)  */
#define ADC2_CNT4_7_UPPER_CNT_UP_CH4_Pos  (0UL)                     /*!< ADC2 CNT4_7_UPPER: CNT_UP_CH4 (Bit 0)                 */
#define ADC2_CNT4_7_UPPER_CNT_UP_CH4_Msk  (0x7UL)                   /*!< ADC2 CNT4_7_UPPER: CNT_UP_CH4 (Bitfield-Mask: 0x07)   */
/* ======================================================  TH0_3_LOWER  ====================================================== */
#define ADC2_TH0_3_LOWER_THLO_CH3_Pos     (24UL)                    /*!< ADC2 TH0_3_LOWER: THLO_CH3 (Bit 24)                   */
#define ADC2_TH0_3_LOWER_THLO_CH3_Msk     (0xff000000UL)            /*!< ADC2 TH0_3_LOWER: THLO_CH3 (Bitfield-Mask: 0xff)      */
#define ADC2_TH0_3_LOWER_THLO_CH2_Pos     (16UL)                    /*!< ADC2 TH0_3_LOWER: THLO_CH2 (Bit 16)                   */
#define ADC2_TH0_3_LOWER_THLO_CH2_Msk     (0xff0000UL)              /*!< ADC2 TH0_3_LOWER: THLO_CH2 (Bitfield-Mask: 0xff)      */
#define ADC2_TH0_3_LOWER_THLO_CH1_Pos     (8UL)                     /*!< ADC2 TH0_3_LOWER: THLO_CH1 (Bit 8)                    */
#define ADC2_TH0_3_LOWER_THLO_CH1_Msk     (0xff00UL)                /*!< ADC2 TH0_3_LOWER: THLO_CH1 (Bitfield-Mask: 0xff)      */
#define ADC2_TH0_3_LOWER_THLO_CH0_Pos     (0UL)                     /*!< ADC2 TH0_3_LOWER: THLO_CH0 (Bit 0)                    */
#define ADC2_TH0_3_LOWER_THLO_CH0_Msk     (0xffUL)                  /*!< ADC2 TH0_3_LOWER: THLO_CH0 (Bitfield-Mask: 0xff)      */
/* ======================================================  TH4_7_LOWER  ====================================================== */
#define ADC2_TH4_7_LOWER_THLO_CH7_Pos     (24UL)                    /*!< ADC2 TH4_7_LOWER: THLO_CH7 (Bit 24)                   */
#define ADC2_TH4_7_LOWER_THLO_CH7_Msk     (0xff000000UL)            /*!< ADC2 TH4_7_LOWER: THLO_CH7 (Bitfield-Mask: 0xff)      */
#define ADC2_TH4_7_LOWER_THLO_CH6_Pos     (16UL)                    /*!< ADC2 TH4_7_LOWER: THLO_CH6 (Bit 16)                   */
#define ADC2_TH4_7_LOWER_THLO_CH6_Msk     (0xff0000UL)              /*!< ADC2 TH4_7_LOWER: THLO_CH6 (Bitfield-Mask: 0xff)      */
#define ADC2_TH4_7_LOWER_THLO_CH5_Pos     (8UL)                     /*!< ADC2 TH4_7_LOWER: THLO_CH5 (Bit 8)                    */
#define ADC2_TH4_7_LOWER_THLO_CH5_Msk     (0xff00UL)                /*!< ADC2 TH4_7_LOWER: THLO_CH5 (Bitfield-Mask: 0xff)      */
#define ADC2_TH4_7_LOWER_THLO_CH4_Pos     (0UL)                     /*!< ADC2 TH4_7_LOWER: THLO_CH4 (Bit 0)                    */
#define ADC2_TH4_7_LOWER_THLO_CH4_Msk     (0xffUL)                  /*!< ADC2 TH4_7_LOWER: THLO_CH4 (Bitfield-Mask: 0xff)      */
/* =====================================================  CNT0_3_LOWER  ====================================================== */
#define ADC2_CNT0_3_LOWER_HYST_LO_CH3_Pos (27UL)                    /*!< ADC2 CNT0_3_LOWER: HYST_LO_CH3 (Bit 27)               */
#define ADC2_CNT0_3_LOWER_HYST_LO_CH3_Msk (0x18000000UL)            /*!< ADC2 CNT0_3_LOWER: HYST_LO_CH3 (Bitfield-Mask: 0x03)  */
#define ADC2_CNT0_3_LOWER_CNT_LO_CH3_Pos  (24UL)                    /*!< ADC2 CNT0_3_LOWER: CNT_LO_CH3 (Bit 24)                */
#define ADC2_CNT0_3_LOWER_CNT_LO_CH3_Msk  (0x7000000UL)             /*!< ADC2 CNT0_3_LOWER: CNT_LO_CH3 (Bitfield-Mask: 0x07)   */
#define ADC2_CNT0_3_LOWER_HYST_LO_CH2_Pos (19UL)                    /*!< ADC2 CNT0_3_LOWER: HYST_LO_CH2 (Bit 19)               */
#define ADC2_CNT0_3_LOWER_HYST_LO_CH2_Msk (0x180000UL)              /*!< ADC2 CNT0_3_LOWER: HYST_LO_CH2 (Bitfield-Mask: 0x03)  */
#define ADC2_CNT0_3_LOWER_CNT_LO_CH2_Pos  (16UL)                    /*!< ADC2 CNT0_3_LOWER: CNT_LO_CH2 (Bit 16)                */
#define ADC2_CNT0_3_LOWER_CNT_LO_CH2_Msk  (0x70000UL)               /*!< ADC2 CNT0_3_LOWER: CNT_LO_CH2 (Bitfield-Mask: 0x07)   */
#define ADC2_CNT0_3_LOWER_HYST_LO_CH1_Pos (11UL)                    /*!< ADC2 CNT0_3_LOWER: HYST_LO_CH1 (Bit 11)               */
#define ADC2_CNT0_3_LOWER_HYST_LO_CH1_Msk (0x1800UL)                /*!< ADC2 CNT0_3_LOWER: HYST_LO_CH1 (Bitfield-Mask: 0x03)  */
#define ADC2_CNT0_3_LOWER_CNT_LO_CH1_Pos  (8UL)                     /*!< ADC2 CNT0_3_LOWER: CNT_LO_CH1 (Bit 8)                 */
#define ADC2_CNT0_3_LOWER_CNT_LO_CH1_Msk  (0x700UL)                 /*!< ADC2 CNT0_3_LOWER: CNT_LO_CH1 (Bitfield-Mask: 0x07)   */
#define ADC2_CNT0_3_LOWER_HYST_LO_CH0_Pos (3UL)                     /*!< ADC2 CNT0_3_LOWER: HYST_LO_CH0 (Bit 3)                */
#define ADC2_CNT0_3_LOWER_HYST_LO_CH0_Msk (0x18UL)                  /*!< ADC2 CNT0_3_LOWER: HYST_LO_CH0 (Bitfield-Mask: 0x03)  */
#define ADC2_CNT0_3_LOWER_CNT_LO_CH0_Pos  (0UL)                     /*!< ADC2 CNT0_3_LOWER: CNT_LO_CH0 (Bit 0)                 */
#define ADC2_CNT0_3_LOWER_CNT_LO_CH0_Msk  (0x7UL)                   /*!< ADC2 CNT0_3_LOWER: CNT_LO_CH0 (Bitfield-Mask: 0x07)   */
/* =====================================================  CNT4_7_LOWER  ====================================================== */
#define ADC2_CNT4_7_LOWER_HYST_LO_CH7_Pos (27UL)                    /*!< ADC2 CNT4_7_LOWER: HYST_LO_CH7 (Bit 27)               */
#define ADC2_CNT4_7_LOWER_HYST_LO_CH7_Msk (0x18000000UL)            /*!< ADC2 CNT4_7_LOWER: HYST_LO_CH7 (Bitfield-Mask: 0x03)  */
#define ADC2_CNT4_7_LOWER_CNT_LO_CH7_Pos  (24UL)                    /*!< ADC2 CNT4_7_LOWER: CNT_LO_CH7 (Bit 24)                */
#define ADC2_CNT4_7_LOWER_CNT_LO_CH7_Msk  (0x7000000UL)             /*!< ADC2 CNT4_7_LOWER: CNT_LO_CH7 (Bitfield-Mask: 0x07)   */
#define ADC2_CNT4_7_LOWER_HYST_LO_CH6_Pos (19UL)                    /*!< ADC2 CNT4_7_LOWER: HYST_LO_CH6 (Bit 19)               */
#define ADC2_CNT4_7_LOWER_HYST_LO_CH6_Msk (0x180000UL)              /*!< ADC2 CNT4_7_LOWER: HYST_LO_CH6 (Bitfield-Mask: 0x03)  */
#define ADC2_CNT4_7_LOWER_CNT_LO_CH6_Pos  (16UL)                    /*!< ADC2 CNT4_7_LOWER: CNT_LO_CH6 (Bit 16)                */
#define ADC2_CNT4_7_LOWER_CNT_LO_CH6_Msk  (0x70000UL)               /*!< ADC2 CNT4_7_LOWER: CNT_LO_CH6 (Bitfield-Mask: 0x07)   */
#define ADC2_CNT4_7_LOWER_HYST_LO_CH5_Pos (11UL)                    /*!< ADC2 CNT4_7_LOWER: HYST_LO_CH5 (Bit 11)               */
#define ADC2_CNT4_7_LOWER_HYST_LO_CH5_Msk (0x1800UL)                /*!< ADC2 CNT4_7_LOWER: HYST_LO_CH5 (Bitfield-Mask: 0x03)  */
#define ADC2_CNT4_7_LOWER_CNT_LO_CH5_Pos  (8UL)                     /*!< ADC2 CNT4_7_LOWER: CNT_LO_CH5 (Bit 8)                 */
#define ADC2_CNT4_7_LOWER_CNT_LO_CH5_Msk  (0x700UL)                 /*!< ADC2 CNT4_7_LOWER: CNT_LO_CH5 (Bitfield-Mask: 0x07)   */
#define ADC2_CNT4_7_LOWER_HYST_LO_CH4_Pos (3UL)                     /*!< ADC2 CNT4_7_LOWER: HYST_LO_CH4 (Bit 3)                */
#define ADC2_CNT4_7_LOWER_HYST_LO_CH4_Msk (0x18UL)                  /*!< ADC2 CNT4_7_LOWER: HYST_LO_CH4 (Bitfield-Mask: 0x03)  */
#define ADC2_CNT4_7_LOWER_CNT_LO_CH4_Pos  (0UL)                     /*!< ADC2 CNT4_7_LOWER: CNT_LO_CH4 (Bit 0)                 */
#define ADC2_CNT4_7_LOWER_CNT_LO_CH4_Msk  (0x7UL)                   /*!< ADC2 CNT4_7_LOWER: CNT_LO_CH4 (Bitfield-Mask: 0x07)   */


/* =========================================================================================================================== */
/* ================                                           CCU6                                            ================ */
/* =========================================================================================================================== */

/* ========================================================  PISEL0  ========================================================= */
#define CCU6_PISEL0_IST12HR_Pos           (14UL)                    /*!< CCU6 PISEL0: IST12HR (Bit 14)                         */
#define CCU6_PISEL0_IST12HR_Msk           (0xc000UL)                /*!< CCU6 PISEL0: IST12HR (Bitfield-Mask: 0x03)            */
#define CCU6_PISEL0_ISPOS2_Pos            (12UL)                    /*!< CCU6 PISEL0: ISPOS2 (Bit 12)                          */
#define CCU6_PISEL0_ISPOS2_Msk            (0x3000UL)                /*!< CCU6 PISEL0: ISPOS2 (Bitfield-Mask: 0x03)             */
#define CCU6_PISEL0_ISPOS1_Pos            (10UL)                    /*!< CCU6 PISEL0: ISPOS1 (Bit 10)                          */
#define CCU6_PISEL0_ISPOS1_Msk            (0xc00UL)                 /*!< CCU6 PISEL0: ISPOS1 (Bitfield-Mask: 0x03)             */
#define CCU6_PISEL0_ISPOS0_Pos            (8UL)                     /*!< CCU6 PISEL0: ISPOS0 (Bit 8)                           */
#define CCU6_PISEL0_ISPOS0_Msk            (0x300UL)                 /*!< CCU6 PISEL0: ISPOS0 (Bitfield-Mask: 0x03)             */
#define CCU6_PISEL0_ISTRP_Pos             (6UL)                     /*!< CCU6 PISEL0: ISTRP (Bit 6)                            */
#define CCU6_PISEL0_ISTRP_Msk             (0xc0UL)                  /*!< CCU6 PISEL0: ISTRP (Bitfield-Mask: 0x03)              */
#define CCU6_PISEL0_ISCC62_Pos            (4UL)                     /*!< CCU6 PISEL0: ISCC62 (Bit 4)                           */
#define CCU6_PISEL0_ISCC62_Msk            (0x30UL)                  /*!< CCU6 PISEL0: ISCC62 (Bitfield-Mask: 0x03)             */
#define CCU6_PISEL0_ISCC61_Pos            (2UL)                     /*!< CCU6 PISEL0: ISCC61 (Bit 2)                           */
#define CCU6_PISEL0_ISCC61_Msk            (0xcUL)                   /*!< CCU6 PISEL0: ISCC61 (Bitfield-Mask: 0x03)             */
#define CCU6_PISEL0_ISCC60_Pos            (0UL)                     /*!< CCU6 PISEL0: ISCC60 (Bit 0)                           */
#define CCU6_PISEL0_ISCC60_Msk            (0x3UL)                   /*!< CCU6 PISEL0: ISCC60 (Bitfield-Mask: 0x03)             */
/* ========================================================  PISEL2  ========================================================= */
#define CCU6_PISEL2_T13EXT_Pos            (7UL)                     /*!< CCU6 PISEL2: T13EXT (Bit 7)                           */
#define CCU6_PISEL2_T13EXT_Msk            (0x80UL)                  /*!< CCU6 PISEL2: T13EXT (Bitfield-Mask: 0x01)             */
#define CCU6_PISEL2_T12EXT_Pos            (6UL)                     /*!< CCU6 PISEL2: T12EXT (Bit 6)                           */
#define CCU6_PISEL2_T12EXT_Msk            (0x40UL)                  /*!< CCU6 PISEL2: T12EXT (Bitfield-Mask: 0x01)             */
#define CCU6_PISEL2_ISCNT13_Pos           (4UL)                     /*!< CCU6 PISEL2: ISCNT13 (Bit 4)                          */
#define CCU6_PISEL2_ISCNT13_Msk           (0x30UL)                  /*!< CCU6 PISEL2: ISCNT13 (Bitfield-Mask: 0x03)            */
#define CCU6_PISEL2_ISCNT12_Pos           (2UL)                     /*!< CCU6 PISEL2: ISCNT12 (Bit 2)                          */
#define CCU6_PISEL2_ISCNT12_Msk           (0xcUL)                   /*!< CCU6 PISEL2: ISCNT12 (Bitfield-Mask: 0x03)            */
#define CCU6_PISEL2_IST13HR_Pos           (0UL)                     /*!< CCU6 PISEL2: IST13HR (Bit 0)                          */
#define CCU6_PISEL2_IST13HR_Msk           (0x3UL)                   /*!< CCU6 PISEL2: IST13HR (Bitfield-Mask: 0x03)            */
/* ========================================================  T12MSEL  ======================================================== */
#define CCU6_T12MSEL_DBYP_Pos             (15UL)                    /*!< CCU6 T12MSEL: DBYP (Bit 15)                           */
#define CCU6_T12MSEL_DBYP_Msk             (0x8000UL)                /*!< CCU6 T12MSEL: DBYP (Bitfield-Mask: 0x01)              */
#define CCU6_T12MSEL_HSYNC_Pos            (12UL)                    /*!< CCU6 T12MSEL: HSYNC (Bit 12)                          */
#define CCU6_T12MSEL_HSYNC_Msk            (0x7000UL)                /*!< CCU6 T12MSEL: HSYNC (Bitfield-Mask: 0x07)             */
#define CCU6_T12MSEL_MSEL62_Pos           (8UL)                     /*!< CCU6 T12MSEL: MSEL62 (Bit 8)                          */
#define CCU6_T12MSEL_MSEL62_Msk           (0xf00UL)                 /*!< CCU6 T12MSEL: MSEL62 (Bitfield-Mask: 0x0f)            */
#define CCU6_T12MSEL_MSEL61_Pos           (4UL)                     /*!< CCU6 T12MSEL: MSEL61 (Bit 4)                          */
#define CCU6_T12MSEL_MSEL61_Msk           (0xf0UL)                  /*!< CCU6 T12MSEL: MSEL61 (Bitfield-Mask: 0x0f)            */
#define CCU6_T12MSEL_MSEL60_Pos           (0UL)                     /*!< CCU6 T12MSEL: MSEL60 (Bit 0)                          */
#define CCU6_T12MSEL_MSEL60_Msk           (0xfUL)                   /*!< CCU6 T12MSEL: MSEL60 (Bitfield-Mask: 0x0f)            */
/* ==========================================================  T12  ========================================================== */
#define CCU6_T12_T12CV_Pos                (0UL)                     /*!< CCU6 T12: T12CV (Bit 0)                               */
#define CCU6_T12_T12CV_Msk                (0xffffUL)                /*!< CCU6 T12: T12CV (Bitfield-Mask: 0xffff)               */
/* =========================================================  T12PR  ========================================================= */
#define CCU6_T12PR_T12PV_Pos              (0UL)                     /*!< CCU6 T12PR: T12PV (Bit 0)                             */
#define CCU6_T12PR_T12PV_Msk              (0xffffUL)                /*!< CCU6 T12PR: T12PV (Bitfield-Mask: 0xffff)             */
/* =========================================================  CC60R  ========================================================= */
#define CCU6_CC60R_CCV_Pos                (0UL)                     /*!< CCU6 CC60R: CCV (Bit 0)                               */
#define CCU6_CC60R_CCV_Msk                (0xffffUL)                /*!< CCU6 CC60R: CCV (Bitfield-Mask: 0xffff)               */
/* =========================================================  CC61R  ========================================================= */
#define CCU6_CC61R_CCV_Pos                (0UL)                     /*!< CCU6 CC61R: CCV (Bit 0)                               */
#define CCU6_CC61R_CCV_Msk                (0xffffUL)                /*!< CCU6 CC61R: CCV (Bitfield-Mask: 0xffff)               */
/* =========================================================  CC62R  ========================================================= */
#define CCU6_CC62R_CCV_Pos                (0UL)                     /*!< CCU6 CC62R: CCV (Bit 0)                               */
#define CCU6_CC62R_CCV_Msk                (0xffffUL)                /*!< CCU6 CC62R: CCV (Bitfield-Mask: 0xffff)               */
/* ========================================================  CC60SR  ========================================================= */
#define CCU6_CC60SR_CCS_Pos               (0UL)                     /*!< CCU6 CC60SR: CCS (Bit 0)                              */
#define CCU6_CC60SR_CCS_Msk               (0xffffUL)                /*!< CCU6 CC60SR: CCS (Bitfield-Mask: 0xffff)              */
/* ========================================================  CC61SR  ========================================================= */
#define CCU6_CC61SR_CCS_Pos               (0UL)                     /*!< CCU6 CC61SR: CCS (Bit 0)                              */
#define CCU6_CC61SR_CCS_Msk               (0xffffUL)                /*!< CCU6 CC61SR: CCS (Bitfield-Mask: 0xffff)              */
/* ========================================================  CC62SR  ========================================================= */
#define CCU6_CC62SR_CCS_Pos               (0UL)                     /*!< CCU6 CC62SR: CCS (Bit 0)                              */
#define CCU6_CC62SR_CCS_Msk               (0xffffUL)                /*!< CCU6 CC62SR: CCS (Bitfield-Mask: 0xffff)              */
/* ========================================================  T12DTC  ========================================================= */
#define CCU6_T12DTC_DTR2_Pos              (14UL)                    /*!< CCU6 T12DTC: DTR2 (Bit 14)                            */
#define CCU6_T12DTC_DTR2_Msk              (0x4000UL)                /*!< CCU6 T12DTC: DTR2 (Bitfield-Mask: 0x01)               */
#define CCU6_T12DTC_DTR1_Pos              (13UL)                    /*!< CCU6 T12DTC: DTR1 (Bit 13)                            */
#define CCU6_T12DTC_DTR1_Msk              (0x2000UL)                /*!< CCU6 T12DTC: DTR1 (Bitfield-Mask: 0x01)               */
#define CCU6_T12DTC_DTR0_Pos              (12UL)                    /*!< CCU6 T12DTC: DTR0 (Bit 12)                            */
#define CCU6_T12DTC_DTR0_Msk              (0x1000UL)                /*!< CCU6 T12DTC: DTR0 (Bitfield-Mask: 0x01)               */
#define CCU6_T12DTC_DTE2_Pos              (10UL)                    /*!< CCU6 T12DTC: DTE2 (Bit 10)                            */
#define CCU6_T12DTC_DTE2_Msk              (0x400UL)                 /*!< CCU6 T12DTC: DTE2 (Bitfield-Mask: 0x01)               */
#define CCU6_T12DTC_DTE1_Pos              (9UL)                     /*!< CCU6 T12DTC: DTE1 (Bit 9)                             */
#define CCU6_T12DTC_DTE1_Msk              (0x200UL)                 /*!< CCU6 T12DTC: DTE1 (Bitfield-Mask: 0x01)               */
#define CCU6_T12DTC_DTE0_Pos              (8UL)                     /*!< CCU6 T12DTC: DTE0 (Bit 8)                             */
#define CCU6_T12DTC_DTE0_Msk              (0x100UL)                 /*!< CCU6 T12DTC: DTE0 (Bitfield-Mask: 0x01)               */
#define CCU6_T12DTC_DTM_Pos               (0UL)                     /*!< CCU6 T12DTC: DTM (Bit 0)                              */
#define CCU6_T12DTC_DTM_Msk               (0xffUL)                  /*!< CCU6 T12DTC: DTM (Bitfield-Mask: 0xff)                */
/* ==========================================================  T13  ========================================================== */
#define CCU6_T13_T13CV_Pos                (0UL)                     /*!< CCU6 T13: T13CV (Bit 0)                               */
#define CCU6_T13_T13CV_Msk                (0xffffUL)                /*!< CCU6 T13: T13CV (Bitfield-Mask: 0xffff)               */
/* =========================================================  T13PR  ========================================================= */
#define CCU6_T13PR_T13PV_Pos              (0UL)                     /*!< CCU6 T13PR: T13PV (Bit 0)                             */
#define CCU6_T13PR_T13PV_Msk              (0xffffUL)                /*!< CCU6 T13PR: T13PV (Bitfield-Mask: 0xffff)             */
/* =========================================================  CC63R  ========================================================= */
#define CCU6_CC63R_CCV_Pos                (0UL)                     /*!< CCU6 CC63R: CCV (Bit 0)                               */
#define CCU6_CC63R_CCV_Msk                (0xffffUL)                /*!< CCU6 CC63R: CCV (Bitfield-Mask: 0xffff)               */
/* ========================================================  CC63SR  ========================================================= */
#define CCU6_CC63SR_CCS_Pos               (0UL)                     /*!< CCU6 CC63SR: CCS (Bit 0)                              */
#define CCU6_CC63SR_CCS_Msk               (0xffffUL)                /*!< CCU6 CC63SR: CCS (Bitfield-Mask: 0xffff)              */
/* ========================================================  CMPSTAT  ======================================================== */
#define CCU6_CMPSTAT_T13IM_Pos            (15UL)                    /*!< CCU6 CMPSTAT: T13IM (Bit 15)                          */
#define CCU6_CMPSTAT_T13IM_Msk            (0x8000UL)                /*!< CCU6 CMPSTAT: T13IM (Bitfield-Mask: 0x01)             */
#define CCU6_CMPSTAT_COUT63PS_Pos         (14UL)                    /*!< CCU6 CMPSTAT: COUT63PS (Bit 14)                       */
#define CCU6_CMPSTAT_COUT63PS_Msk         (0x4000UL)                /*!< CCU6 CMPSTAT: COUT63PS (Bitfield-Mask: 0x01)          */
#define CCU6_CMPSTAT_COUT62PS_Pos         (13UL)                    /*!< CCU6 CMPSTAT: COUT62PS (Bit 13)                       */
#define CCU6_CMPSTAT_COUT62PS_Msk         (0x2000UL)                /*!< CCU6 CMPSTAT: COUT62PS (Bitfield-Mask: 0x01)          */
#define CCU6_CMPSTAT_CC62PS_Pos           (12UL)                    /*!< CCU6 CMPSTAT: CC62PS (Bit 12)                         */
#define CCU6_CMPSTAT_CC62PS_Msk           (0x1000UL)                /*!< CCU6 CMPSTAT: CC62PS (Bitfield-Mask: 0x01)            */
#define CCU6_CMPSTAT_COUT61PS_Pos         (11UL)                    /*!< CCU6 CMPSTAT: COUT61PS (Bit 11)                       */
#define CCU6_CMPSTAT_COUT61PS_Msk         (0x800UL)                 /*!< CCU6 CMPSTAT: COUT61PS (Bitfield-Mask: 0x01)          */
#define CCU6_CMPSTAT_CC61PS_Pos           (10UL)                    /*!< CCU6 CMPSTAT: CC61PS (Bit 10)                         */
#define CCU6_CMPSTAT_CC61PS_Msk           (0x400UL)                 /*!< CCU6 CMPSTAT: CC61PS (Bitfield-Mask: 0x01)            */
#define CCU6_CMPSTAT_COUT60PS_Pos         (9UL)                     /*!< CCU6 CMPSTAT: COUT60PS (Bit 9)                        */
#define CCU6_CMPSTAT_COUT60PS_Msk         (0x200UL)                 /*!< CCU6 CMPSTAT: COUT60PS (Bitfield-Mask: 0x01)          */
#define CCU6_CMPSTAT_CC60PS_Pos           (8UL)                     /*!< CCU6 CMPSTAT: CC60PS (Bit 8)                          */
#define CCU6_CMPSTAT_CC60PS_Msk           (0x100UL)                 /*!< CCU6 CMPSTAT: CC60PS (Bitfield-Mask: 0x01)            */
#define CCU6_CMPSTAT_CC63ST_Pos           (6UL)                     /*!< CCU6 CMPSTAT: CC63ST (Bit 6)                          */
#define CCU6_CMPSTAT_CC63ST_Msk           (0x40UL)                  /*!< CCU6 CMPSTAT: CC63ST (Bitfield-Mask: 0x01)            */
#define CCU6_CMPSTAT_CCPOS2_Pos           (5UL)                     /*!< CCU6 CMPSTAT: CCPOS2 (Bit 5)                          */
#define CCU6_CMPSTAT_CCPOS2_Msk           (0x20UL)                  /*!< CCU6 CMPSTAT: CCPOS2 (Bitfield-Mask: 0x01)            */
#define CCU6_CMPSTAT_CCPOS1_Pos           (4UL)                     /*!< CCU6 CMPSTAT: CCPOS1 (Bit 4)                          */
#define CCU6_CMPSTAT_CCPOS1_Msk           (0x10UL)                  /*!< CCU6 CMPSTAT: CCPOS1 (Bitfield-Mask: 0x01)            */
#define CCU6_CMPSTAT_CCPOS0_Pos           (3UL)                     /*!< CCU6 CMPSTAT: CCPOS0 (Bit 3)                          */
#define CCU6_CMPSTAT_CCPOS0_Msk           (0x8UL)                   /*!< CCU6 CMPSTAT: CCPOS0 (Bitfield-Mask: 0x01)            */
#define CCU6_CMPSTAT_CC62ST_Pos           (2UL)                     /*!< CCU6 CMPSTAT: CC62ST (Bit 2)                          */
#define CCU6_CMPSTAT_CC62ST_Msk           (0x4UL)                   /*!< CCU6 CMPSTAT: CC62ST (Bitfield-Mask: 0x01)            */
#define CCU6_CMPSTAT_CC61ST_Pos           (1UL)                     /*!< CCU6 CMPSTAT: CC61ST (Bit 1)                          */
#define CCU6_CMPSTAT_CC61ST_Msk           (0x2UL)                   /*!< CCU6 CMPSTAT: CC61ST (Bitfield-Mask: 0x01)            */
#define CCU6_CMPSTAT_CC60ST_Pos           (0UL)                     /*!< CCU6 CMPSTAT: CC60ST (Bit 0)                          */
#define CCU6_CMPSTAT_CC60ST_Msk           (0x1UL)                   /*!< CCU6 CMPSTAT: CC60ST (Bitfield-Mask: 0x01)            */
/* =======================================================  CMPMODIF  ======================================================== */
#define CCU6_CMPMODIF_MCC63R_Pos          (14UL)                    /*!< CCU6 CMPMODIF: MCC63R (Bit 14)                        */
#define CCU6_CMPMODIF_MCC63R_Msk          (0x4000UL)                /*!< CCU6 CMPMODIF: MCC63R (Bitfield-Mask: 0x01)           */
#define CCU6_CMPMODIF_MCC62R_Pos          (10UL)                    /*!< CCU6 CMPMODIF: MCC62R (Bit 10)                        */
#define CCU6_CMPMODIF_MCC62R_Msk          (0x400UL)                 /*!< CCU6 CMPMODIF: MCC62R (Bitfield-Mask: 0x01)           */
#define CCU6_CMPMODIF_MCC61R_Pos          (9UL)                     /*!< CCU6 CMPMODIF: MCC61R (Bit 9)                         */
#define CCU6_CMPMODIF_MCC61R_Msk          (0x200UL)                 /*!< CCU6 CMPMODIF: MCC61R (Bitfield-Mask: 0x01)           */
#define CCU6_CMPMODIF_MCC60R_Pos          (8UL)                     /*!< CCU6 CMPMODIF: MCC60R (Bit 8)                         */
#define CCU6_CMPMODIF_MCC60R_Msk          (0x100UL)                 /*!< CCU6 CMPMODIF: MCC60R (Bitfield-Mask: 0x01)           */
#define CCU6_CMPMODIF_MCC63S_Pos          (6UL)                     /*!< CCU6 CMPMODIF: MCC63S (Bit 6)                         */
#define CCU6_CMPMODIF_MCC63S_Msk          (0x40UL)                  /*!< CCU6 CMPMODIF: MCC63S (Bitfield-Mask: 0x01)           */
#define CCU6_CMPMODIF_MCC62S_Pos          (2UL)                     /*!< CCU6 CMPMODIF: MCC62S (Bit 2)                         */
#define CCU6_CMPMODIF_MCC62S_Msk          (0x4UL)                   /*!< CCU6 CMPMODIF: MCC62S (Bitfield-Mask: 0x01)           */
#define CCU6_CMPMODIF_MCC61S_Pos          (1UL)                     /*!< CCU6 CMPMODIF: MCC61S (Bit 1)                         */
#define CCU6_CMPMODIF_MCC61S_Msk          (0x2UL)                   /*!< CCU6 CMPMODIF: MCC61S (Bitfield-Mask: 0x01)           */
#define CCU6_CMPMODIF_MCC60S_Pos          (0UL)                     /*!< CCU6 CMPMODIF: MCC60S (Bit 0)                         */
#define CCU6_CMPMODIF_MCC60S_Msk          (0x1UL)                   /*!< CCU6 CMPMODIF: MCC60S (Bitfield-Mask: 0x01)           */
/* =========================================================  TCTR0  ========================================================= */
#define CCU6_TCTR0_STE13_Pos              (13UL)                    /*!< CCU6 TCTR0: STE13 (Bit 13)                            */
#define CCU6_TCTR0_STE13_Msk              (0x2000UL)                /*!< CCU6 TCTR0: STE13 (Bitfield-Mask: 0x01)               */
#define CCU6_TCTR0_T13R_Pos               (12UL)                    /*!< CCU6 TCTR0: T13R (Bit 12)                             */
#define CCU6_TCTR0_T13R_Msk               (0x1000UL)                /*!< CCU6 TCTR0: T13R (Bitfield-Mask: 0x01)                */
#define CCU6_TCTR0_T13PRE_Pos             (11UL)                    /*!< CCU6 TCTR0: T13PRE (Bit 11)                           */
#define CCU6_TCTR0_T13PRE_Msk             (0x800UL)                 /*!< CCU6 TCTR0: T13PRE (Bitfield-Mask: 0x01)              */
#define CCU6_TCTR0_T13CLK_Pos             (8UL)                     /*!< CCU6 TCTR0: T13CLK (Bit 8)                            */
#define CCU6_TCTR0_T13CLK_Msk             (0x700UL)                 /*!< CCU6 TCTR0: T13CLK (Bitfield-Mask: 0x07)              */
#define CCU6_TCTR0_CTM_Pos                (7UL)                     /*!< CCU6 TCTR0: CTM (Bit 7)                               */
#define CCU6_TCTR0_CTM_Msk                (0x80UL)                  /*!< CCU6 TCTR0: CTM (Bitfield-Mask: 0x01)                 */
#define CCU6_TCTR0_CDIR_Pos               (6UL)                     /*!< CCU6 TCTR0: CDIR (Bit 6)                              */
#define CCU6_TCTR0_CDIR_Msk               (0x40UL)                  /*!< CCU6 TCTR0: CDIR (Bitfield-Mask: 0x01)                */
#define CCU6_TCTR0_STE12_Pos              (5UL)                     /*!< CCU6 TCTR0: STE12 (Bit 5)                             */
#define CCU6_TCTR0_STE12_Msk              (0x20UL)                  /*!< CCU6 TCTR0: STE12 (Bitfield-Mask: 0x01)               */
#define CCU6_TCTR0_T12R_Pos               (4UL)                     /*!< CCU6 TCTR0: T12R (Bit 4)                              */
#define CCU6_TCTR0_T12R_Msk               (0x10UL)                  /*!< CCU6 TCTR0: T12R (Bitfield-Mask: 0x01)                */
#define CCU6_TCTR0_T12PRE_Pos             (3UL)                     /*!< CCU6 TCTR0: T12PRE (Bit 3)                            */
#define CCU6_TCTR0_T12PRE_Msk             (0x8UL)                   /*!< CCU6 TCTR0: T12PRE (Bitfield-Mask: 0x01)              */
#define CCU6_TCTR0_T12CLK_Pos             (0UL)                     /*!< CCU6 TCTR0: T12CLK (Bit 0)                            */
#define CCU6_TCTR0_T12CLK_Msk             (0x7UL)                   /*!< CCU6 TCTR0: T12CLK (Bitfield-Mask: 0x07)              */
/* =========================================================  TCTR2  ========================================================= */
#define CCU6_TCTR2_T13RSEL_Pos            (10UL)                    /*!< CCU6 TCTR2: T13RSEL (Bit 10)                          */
#define CCU6_TCTR2_T13RSEL_Msk            (0xc00UL)                 /*!< CCU6 TCTR2: T13RSEL (Bitfield-Mask: 0x03)             */
#define CCU6_TCTR2_T12RSEL_Pos            (8UL)                     /*!< CCU6 TCTR2: T12RSEL (Bit 8)                           */
#define CCU6_TCTR2_T12RSEL_Msk            (0x300UL)                 /*!< CCU6 TCTR2: T12RSEL (Bitfield-Mask: 0x03)             */
#define CCU6_TCTR2_T13TED_Pos             (5UL)                     /*!< CCU6 TCTR2: T13TED (Bit 5)                            */
#define CCU6_TCTR2_T13TED_Msk             (0x60UL)                  /*!< CCU6 TCTR2: T13TED (Bitfield-Mask: 0x03)              */
#define CCU6_TCTR2_T13TEC_Pos             (2UL)                     /*!< CCU6 TCTR2: T13TEC (Bit 2)                            */
#define CCU6_TCTR2_T13TEC_Msk             (0x1cUL)                  /*!< CCU6 TCTR2: T13TEC (Bitfield-Mask: 0x07)              */
#define CCU6_TCTR2_T13SSC_Pos             (1UL)                     /*!< CCU6 TCTR2: T13SSC (Bit 1)                            */
#define CCU6_TCTR2_T13SSC_Msk             (0x2UL)                   /*!< CCU6 TCTR2: T13SSC (Bitfield-Mask: 0x01)              */
#define CCU6_TCTR2_T12SSC_Pos             (0UL)                     /*!< CCU6 TCTR2: T12SSC (Bit 0)                            */
#define CCU6_TCTR2_T12SSC_Msk             (0x1UL)                   /*!< CCU6 TCTR2: T12SSC (Bitfield-Mask: 0x01)              */
/* =========================================================  TCTR4  ========================================================= */
#define CCU6_TCTR4_T13STD_Pos             (15UL)                    /*!< CCU6 TCTR4: T13STD (Bit 15)                           */
#define CCU6_TCTR4_T13STD_Msk             (0x8000UL)                /*!< CCU6 TCTR4: T13STD (Bitfield-Mask: 0x01)              */
#define CCU6_TCTR4_T13STR_Pos             (14UL)                    /*!< CCU6 TCTR4: T13STR (Bit 14)                           */
#define CCU6_TCTR4_T13STR_Msk             (0x4000UL)                /*!< CCU6 TCTR4: T13STR (Bitfield-Mask: 0x01)              */
#define CCU6_TCTR4_T13CNT_Pos             (13UL)                    /*!< CCU6 TCTR4: T13CNT (Bit 13)                           */
#define CCU6_TCTR4_T13CNT_Msk             (0x2000UL)                /*!< CCU6 TCTR4: T13CNT (Bitfield-Mask: 0x01)              */
#define CCU6_TCTR4_T13RES_Pos             (10UL)                    /*!< CCU6 TCTR4: T13RES (Bit 10)                           */
#define CCU6_TCTR4_T13RES_Msk             (0x400UL)                 /*!< CCU6 TCTR4: T13RES (Bitfield-Mask: 0x01)              */
#define CCU6_TCTR4_T13RS_Pos              (9UL)                     /*!< CCU6 TCTR4: T13RS (Bit 9)                             */
#define CCU6_TCTR4_T13RS_Msk              (0x200UL)                 /*!< CCU6 TCTR4: T13RS (Bitfield-Mask: 0x01)               */
#define CCU6_TCTR4_T13RR_Pos              (8UL)                     /*!< CCU6 TCTR4: T13RR (Bit 8)                             */
#define CCU6_TCTR4_T13RR_Msk              (0x100UL)                 /*!< CCU6 TCTR4: T13RR (Bitfield-Mask: 0x01)               */
#define CCU6_TCTR4_T12STD_Pos             (7UL)                     /*!< CCU6 TCTR4: T12STD (Bit 7)                            */
#define CCU6_TCTR4_T12STD_Msk             (0x80UL)                  /*!< CCU6 TCTR4: T12STD (Bitfield-Mask: 0x01)              */
#define CCU6_TCTR4_T12STR_Pos             (6UL)                     /*!< CCU6 TCTR4: T12STR (Bit 6)                            */
#define CCU6_TCTR4_T12STR_Msk             (0x40UL)                  /*!< CCU6 TCTR4: T12STR (Bitfield-Mask: 0x01)              */
#define CCU6_TCTR4_T12CNT_Pos             (5UL)                     /*!< CCU6 TCTR4: T12CNT (Bit 5)                            */
#define CCU6_TCTR4_T12CNT_Msk             (0x20UL)                  /*!< CCU6 TCTR4: T12CNT (Bitfield-Mask: 0x01)              */
#define CCU6_TCTR4_DTRES_Pos              (3UL)                     /*!< CCU6 TCTR4: DTRES (Bit 3)                             */
#define CCU6_TCTR4_DTRES_Msk              (0x8UL)                   /*!< CCU6 TCTR4: DTRES (Bitfield-Mask: 0x01)               */
#define CCU6_TCTR4_T12RES_Pos             (2UL)                     /*!< CCU6 TCTR4: T12RES (Bit 2)                            */
#define CCU6_TCTR4_T12RES_Msk             (0x4UL)                   /*!< CCU6 TCTR4: T12RES (Bitfield-Mask: 0x01)              */
#define CCU6_TCTR4_T12RS_Pos              (1UL)                     /*!< CCU6 TCTR4: T12RS (Bit 1)                             */
#define CCU6_TCTR4_T12RS_Msk              (0x2UL)                   /*!< CCU6 TCTR4: T12RS (Bitfield-Mask: 0x01)               */
#define CCU6_TCTR4_T12RR_Pos              (0UL)                     /*!< CCU6 TCTR4: T12RR (Bit 0)                             */
#define CCU6_TCTR4_T12RR_Msk              (0x1UL)                   /*!< CCU6 TCTR4: T12RR (Bitfield-Mask: 0x01)               */
/* ========================================================  MODCTR  ========================================================= */
#define CCU6_MODCTR_ECT13O_Pos            (15UL)                    /*!< CCU6 MODCTR: ECT13O (Bit 15)                          */
#define CCU6_MODCTR_ECT13O_Msk            (0x8000UL)                /*!< CCU6 MODCTR: ECT13O (Bitfield-Mask: 0x01)             */
#define CCU6_MODCTR_T13MODEN_Pos          (8UL)                     /*!< CCU6 MODCTR: T13MODEN (Bit 8)                         */
#define CCU6_MODCTR_T13MODEN_Msk          (0x3f00UL)                /*!< CCU6 MODCTR: T13MODEN (Bitfield-Mask: 0x3f)           */
#define CCU6_MODCTR_MCMEN_Pos             (7UL)                     /*!< CCU6 MODCTR: MCMEN (Bit 7)                            */
#define CCU6_MODCTR_MCMEN_Msk             (0x80UL)                  /*!< CCU6 MODCTR: MCMEN (Bitfield-Mask: 0x01)              */
#define CCU6_MODCTR_T12MODEN_Pos          (0UL)                     /*!< CCU6 MODCTR: T12MODEN (Bit 0)                         */
#define CCU6_MODCTR_T12MODEN_Msk          (0x3fUL)                  /*!< CCU6 MODCTR: T12MODEN (Bitfield-Mask: 0x3f)           */
/* ========================================================  TRPCTR  ========================================================= */
#define CCU6_TRPCTR_TRPPEN_Pos            (15UL)                    /*!< CCU6 TRPCTR: TRPPEN (Bit 15)                          */
#define CCU6_TRPCTR_TRPPEN_Msk            (0x8000UL)                /*!< CCU6 TRPCTR: TRPPEN (Bitfield-Mask: 0x01)             */
#define CCU6_TRPCTR_TRPEN13_Pos           (14UL)                    /*!< CCU6 TRPCTR: TRPEN13 (Bit 14)                         */
#define CCU6_TRPCTR_TRPEN13_Msk           (0x4000UL)                /*!< CCU6 TRPCTR: TRPEN13 (Bitfield-Mask: 0x01)            */
#define CCU6_TRPCTR_TRPEN_Pos             (8UL)                     /*!< CCU6 TRPCTR: TRPEN (Bit 8)                            */
#define CCU6_TRPCTR_TRPEN_Msk             (0x3f00UL)                /*!< CCU6 TRPCTR: TRPEN (Bitfield-Mask: 0x3f)              */
#define CCU6_TRPCTR_TRPM2_Pos             (2UL)                     /*!< CCU6 TRPCTR: TRPM2 (Bit 2)                            */
#define CCU6_TRPCTR_TRPM2_Msk             (0x4UL)                   /*!< CCU6 TRPCTR: TRPM2 (Bitfield-Mask: 0x01)              */
#define CCU6_TRPCTR_TRPM10_Pos            (0UL)                     /*!< CCU6 TRPCTR: TRPM10 (Bit 0)                           */
#define CCU6_TRPCTR_TRPM10_Msk            (0x3UL)                   /*!< CCU6 TRPCTR: TRPM10 (Bitfield-Mask: 0x03)             */
/* =========================================================  PSLR  ========================================================== */
#define CCU6_PSLR_PSL63_Pos               (7UL)                     /*!< CCU6 PSLR: PSL63 (Bit 7)                              */
#define CCU6_PSLR_PSL63_Msk               (0x80UL)                  /*!< CCU6 PSLR: PSL63 (Bitfield-Mask: 0x01)                */
#define CCU6_PSLR_PSL_Pos                 (0UL)                     /*!< CCU6 PSLR: PSL (Bit 0)                                */
#define CCU6_PSLR_PSL_Msk                 (0x3fUL)                  /*!< CCU6 PSLR: PSL (Bitfield-Mask: 0x3f)                  */
/* ========================================================  MCMOUTS  ======================================================== */
#define CCU6_MCMOUTS_STRHP_Pos            (15UL)                    /*!< CCU6 MCMOUTS: STRHP (Bit 15)                          */
#define CCU6_MCMOUTS_STRHP_Msk            (0x8000UL)                /*!< CCU6 MCMOUTS: STRHP (Bitfield-Mask: 0x01)             */
#define CCU6_MCMOUTS_CURHS_Pos            (11UL)                    /*!< CCU6 MCMOUTS: CURHS (Bit 11)                          */
#define CCU6_MCMOUTS_CURHS_Msk            (0x3800UL)                /*!< CCU6 MCMOUTS: CURHS (Bitfield-Mask: 0x07)             */
#define CCU6_MCMOUTS_EXPHS_Pos            (8UL)                     /*!< CCU6 MCMOUTS: EXPHS (Bit 8)                           */
#define CCU6_MCMOUTS_EXPHS_Msk            (0x700UL)                 /*!< CCU6 MCMOUTS: EXPHS (Bitfield-Mask: 0x07)             */
#define CCU6_MCMOUTS_STRMCM_Pos           (7UL)                     /*!< CCU6 MCMOUTS: STRMCM (Bit 7)                          */
#define CCU6_MCMOUTS_STRMCM_Msk           (0x80UL)                  /*!< CCU6 MCMOUTS: STRMCM (Bitfield-Mask: 0x01)            */
#define CCU6_MCMOUTS_MCMPS_Pos            (0UL)                     /*!< CCU6 MCMOUTS: MCMPS (Bit 0)                           */
#define CCU6_MCMOUTS_MCMPS_Msk            (0x3fUL)                  /*!< CCU6 MCMOUTS: MCMPS (Bitfield-Mask: 0x3f)             */
/* ========================================================  MCMOUT  ========================================================= */
#define CCU6_MCMOUT_CURH_Pos              (11UL)                    /*!< CCU6 MCMOUT: CURH (Bit 11)                            */
#define CCU6_MCMOUT_CURH_Msk              (0x3800UL)                /*!< CCU6 MCMOUT: CURH (Bitfield-Mask: 0x07)               */
#define CCU6_MCMOUT_EXPH_Pos              (8UL)                     /*!< CCU6 MCMOUT: EXPH (Bit 8)                             */
#define CCU6_MCMOUT_EXPH_Msk              (0x700UL)                 /*!< CCU6 MCMOUT: EXPH (Bitfield-Mask: 0x07)               */
#define CCU6_MCMOUT_R_Pos                 (6UL)                     /*!< CCU6 MCMOUT: R (Bit 6)                                */
#define CCU6_MCMOUT_R_Msk                 (0x40UL)                  /*!< CCU6 MCMOUT: R (Bitfield-Mask: 0x01)                  */
#define CCU6_MCMOUT_MCMP_Pos              (0UL)                     /*!< CCU6 MCMOUT: MCMP (Bit 0)                             */
#define CCU6_MCMOUT_MCMP_Msk              (0x3fUL)                  /*!< CCU6 MCMOUT: MCMP (Bitfield-Mask: 0x3f)               */
/* ========================================================  MCMCTR  ========================================================= */
#define CCU6_MCMCTR_STE13U_Pos            (10UL)                    /*!< CCU6 MCMCTR: STE13U (Bit 10)                          */
#define CCU6_MCMCTR_STE13U_Msk            (0x400UL)                 /*!< CCU6 MCMCTR: STE13U (Bitfield-Mask: 0x01)             */
#define CCU6_MCMCTR_STE12D_Pos            (9UL)                     /*!< CCU6 MCMCTR: STE12D (Bit 9)                           */
#define CCU6_MCMCTR_STE12D_Msk            (0x200UL)                 /*!< CCU6 MCMCTR: STE12D (Bitfield-Mask: 0x01)             */
#define CCU6_MCMCTR_STE12U_Pos            (8UL)                     /*!< CCU6 MCMCTR: STE12U (Bit 8)                           */
#define CCU6_MCMCTR_STE12U_Msk            (0x100UL)                 /*!< CCU6 MCMCTR: STE12U (Bitfield-Mask: 0x01)             */
#define CCU6_MCMCTR_SWSYN_Pos             (4UL)                     /*!< CCU6 MCMCTR: SWSYN (Bit 4)                            */
#define CCU6_MCMCTR_SWSYN_Msk             (0x30UL)                  /*!< CCU6 MCMCTR: SWSYN (Bitfield-Mask: 0x03)              */
#define CCU6_MCMCTR_SWSEL_Pos             (0UL)                     /*!< CCU6 MCMCTR: SWSEL (Bit 0)                            */
#define CCU6_MCMCTR_SWSEL_Msk             (0x7UL)                   /*!< CCU6 MCMCTR: SWSEL (Bitfield-Mask: 0x07)              */
/* ==========================================================  IS  =========================================================== */
#define CCU6_IS_STR_Pos                   (15UL)                    /*!< CCU6 IS: STR (Bit 15)                                 */
#define CCU6_IS_STR_Msk                   (0x8000UL)                /*!< CCU6 IS: STR (Bitfield-Mask: 0x01)                    */
#define CCU6_IS_IDLE_Pos                  (14UL)                    /*!< CCU6 IS: IDLE (Bit 14)                                */
#define CCU6_IS_IDLE_Msk                  (0x4000UL)                /*!< CCU6 IS: IDLE (Bitfield-Mask: 0x01)                   */
#define CCU6_IS_WHE_Pos                   (13UL)                    /*!< CCU6 IS: WHE (Bit 13)                                 */
#define CCU6_IS_WHE_Msk                   (0x2000UL)                /*!< CCU6 IS: WHE (Bitfield-Mask: 0x01)                    */
#define CCU6_IS_CHE_Pos                   (12UL)                    /*!< CCU6 IS: CHE (Bit 12)                                 */
#define CCU6_IS_CHE_Msk                   (0x1000UL)                /*!< CCU6 IS: CHE (Bitfield-Mask: 0x01)                    */
#define CCU6_IS_TRPS_Pos                  (11UL)                    /*!< CCU6 IS: TRPS (Bit 11)                                */
#define CCU6_IS_TRPS_Msk                  (0x800UL)                 /*!< CCU6 IS: TRPS (Bitfield-Mask: 0x01)                   */
#define CCU6_IS_TRPF_Pos                  (10UL)                    /*!< CCU6 IS: TRPF (Bit 10)                                */
#define CCU6_IS_TRPF_Msk                  (0x400UL)                 /*!< CCU6 IS: TRPF (Bitfield-Mask: 0x01)                   */
#define CCU6_IS_T13PM_Pos                 (9UL)                     /*!< CCU6 IS: T13PM (Bit 9)                                */
#define CCU6_IS_T13PM_Msk                 (0x200UL)                 /*!< CCU6 IS: T13PM (Bitfield-Mask: 0x01)                  */
#define CCU6_IS_T13CM_Pos                 (8UL)                     /*!< CCU6 IS: T13CM (Bit 8)                                */
#define CCU6_IS_T13CM_Msk                 (0x100UL)                 /*!< CCU6 IS: T13CM (Bitfield-Mask: 0x01)                  */
#define CCU6_IS_T12PM_Pos                 (7UL)                     /*!< CCU6 IS: T12PM (Bit 7)                                */
#define CCU6_IS_T12PM_Msk                 (0x80UL)                  /*!< CCU6 IS: T12PM (Bitfield-Mask: 0x01)                  */
#define CCU6_IS_T12OM_Pos                 (6UL)                     /*!< CCU6 IS: T12OM (Bit 6)                                */
#define CCU6_IS_T12OM_Msk                 (0x40UL)                  /*!< CCU6 IS: T12OM (Bitfield-Mask: 0x01)                  */
#define CCU6_IS_ICC62F_Pos                (5UL)                     /*!< CCU6 IS: ICC62F (Bit 5)                               */
#define CCU6_IS_ICC62F_Msk                (0x20UL)                  /*!< CCU6 IS: ICC62F (Bitfield-Mask: 0x01)                 */
#define CCU6_IS_ICC62R_Pos                (4UL)                     /*!< CCU6 IS: ICC62R (Bit 4)                               */
#define CCU6_IS_ICC62R_Msk                (0x10UL)                  /*!< CCU6 IS: ICC62R (Bitfield-Mask: 0x01)                 */
#define CCU6_IS_ICC61F_Pos                (3UL)                     /*!< CCU6 IS: ICC61F (Bit 3)                               */
#define CCU6_IS_ICC61F_Msk                (0x8UL)                   /*!< CCU6 IS: ICC61F (Bitfield-Mask: 0x01)                 */
#define CCU6_IS_ICC61R_Pos                (2UL)                     /*!< CCU6 IS: ICC61R (Bit 2)                               */
#define CCU6_IS_ICC61R_Msk                (0x4UL)                   /*!< CCU6 IS: ICC61R (Bitfield-Mask: 0x01)                 */
#define CCU6_IS_ICC60F_Pos                (1UL)                     /*!< CCU6 IS: ICC60F (Bit 1)                               */
#define CCU6_IS_ICC60F_Msk                (0x2UL)                   /*!< CCU6 IS: ICC60F (Bitfield-Mask: 0x01)                 */
#define CCU6_IS_ICC60R_Pos                (0UL)                     /*!< CCU6 IS: ICC60R (Bit 0)                               */
#define CCU6_IS_ICC60R_Msk                (0x1UL)                   /*!< CCU6 IS: ICC60R (Bitfield-Mask: 0x01)                 */
/* ==========================================================  ISS  ========================================================== */
#define CCU6_ISS_SSTR_Pos                 (15UL)                    /*!< CCU6 ISS: SSTR (Bit 15)                               */
#define CCU6_ISS_SSTR_Msk                 (0x8000UL)                /*!< CCU6 ISS: SSTR (Bitfield-Mask: 0x01)                  */
#define CCU6_ISS_SIDLE_Pos                (14UL)                    /*!< CCU6 ISS: SIDLE (Bit 14)                              */
#define CCU6_ISS_SIDLE_Msk                (0x4000UL)                /*!< CCU6 ISS: SIDLE (Bitfield-Mask: 0x01)                 */
#define CCU6_ISS_SWHE_Pos                 (13UL)                    /*!< CCU6 ISS: SWHE (Bit 13)                               */
#define CCU6_ISS_SWHE_Msk                 (0x2000UL)                /*!< CCU6 ISS: SWHE (Bitfield-Mask: 0x01)                  */
#define CCU6_ISS_SCHE_Pos                 (12UL)                    /*!< CCU6 ISS: SCHE (Bit 12)                               */
#define CCU6_ISS_SCHE_Msk                 (0x1000UL)                /*!< CCU6 ISS: SCHE (Bitfield-Mask: 0x01)                  */
#define CCU6_ISS_SWHC_Pos                 (11UL)                    /*!< CCU6 ISS: SWHC (Bit 11)                               */
#define CCU6_ISS_SWHC_Msk                 (0x800UL)                 /*!< CCU6 ISS: SWHC (Bitfield-Mask: 0x01)                  */
#define CCU6_ISS_STRPF_Pos                (10UL)                    /*!< CCU6 ISS: STRPF (Bit 10)                              */
#define CCU6_ISS_STRPF_Msk                (0x400UL)                 /*!< CCU6 ISS: STRPF (Bitfield-Mask: 0x01)                 */
#define CCU6_ISS_ST13PM_Pos               (9UL)                     /*!< CCU6 ISS: ST13PM (Bit 9)                              */
#define CCU6_ISS_ST13PM_Msk               (0x200UL)                 /*!< CCU6 ISS: ST13PM (Bitfield-Mask: 0x01)                */
#define CCU6_ISS_ST13CM_Pos               (8UL)                     /*!< CCU6 ISS: ST13CM (Bit 8)                              */
#define CCU6_ISS_ST13CM_Msk               (0x100UL)                 /*!< CCU6 ISS: ST13CM (Bitfield-Mask: 0x01)                */
#define CCU6_ISS_ST12PM_Pos               (7UL)                     /*!< CCU6 ISS: ST12PM (Bit 7)                              */
#define CCU6_ISS_ST12PM_Msk               (0x80UL)                  /*!< CCU6 ISS: ST12PM (Bitfield-Mask: 0x01)                */
#define CCU6_ISS_ST12OM_Pos               (6UL)                     /*!< CCU6 ISS: ST12OM (Bit 6)                              */
#define CCU6_ISS_ST12OM_Msk               (0x40UL)                  /*!< CCU6 ISS: ST12OM (Bitfield-Mask: 0x01)                */
#define CCU6_ISS_SCC62F_Pos               (5UL)                     /*!< CCU6 ISS: SCC62F (Bit 5)                              */
#define CCU6_ISS_SCC62F_Msk               (0x20UL)                  /*!< CCU6 ISS: SCC62F (Bitfield-Mask: 0x01)                */
#define CCU6_ISS_SCC62R_Pos               (4UL)                     /*!< CCU6 ISS: SCC62R (Bit 4)                              */
#define CCU6_ISS_SCC62R_Msk               (0x10UL)                  /*!< CCU6 ISS: SCC62R (Bitfield-Mask: 0x01)                */
#define CCU6_ISS_SCC61F_Pos               (3UL)                     /*!< CCU6 ISS: SCC61F (Bit 3)                              */
#define CCU6_ISS_SCC61F_Msk               (0x8UL)                   /*!< CCU6 ISS: SCC61F (Bitfield-Mask: 0x01)                */
#define CCU6_ISS_SCC61R_Pos               (2UL)                     /*!< CCU6 ISS: SCC61R (Bit 2)                              */
#define CCU6_ISS_SCC61R_Msk               (0x4UL)                   /*!< CCU6 ISS: SCC61R (Bitfield-Mask: 0x01)                */
#define CCU6_ISS_SCC60F_Pos               (1UL)                     /*!< CCU6 ISS: SCC60F (Bit 1)                              */
#define CCU6_ISS_SCC60F_Msk               (0x2UL)                   /*!< CCU6 ISS: SCC60F (Bitfield-Mask: 0x01)                */
#define CCU6_ISS_SCC60R_Pos               (0UL)                     /*!< CCU6 ISS: SCC60R (Bit 0)                              */
#define CCU6_ISS_SCC60R_Msk               (0x1UL)                   /*!< CCU6 ISS: SCC60R (Bitfield-Mask: 0x01)                */
/* ==========================================================  ISR  ========================================================== */
#define CCU6_ISR_RSTR_Pos                 (15UL)                    /*!< CCU6 ISR: RSTR (Bit 15)                               */
#define CCU6_ISR_RSTR_Msk                 (0x8000UL)                /*!< CCU6 ISR: RSTR (Bitfield-Mask: 0x01)                  */
#define CCU6_ISR_RIDLE_Pos                (14UL)                    /*!< CCU6 ISR: RIDLE (Bit 14)                              */
#define CCU6_ISR_RIDLE_Msk                (0x4000UL)                /*!< CCU6 ISR: RIDLE (Bitfield-Mask: 0x01)                 */
#define CCU6_ISR_RWHE_Pos                 (13UL)                    /*!< CCU6 ISR: RWHE (Bit 13)                               */
#define CCU6_ISR_RWHE_Msk                 (0x2000UL)                /*!< CCU6 ISR: RWHE (Bitfield-Mask: 0x01)                  */
#define CCU6_ISR_RCHE_Pos                 (12UL)                    /*!< CCU6 ISR: RCHE (Bit 12)                               */
#define CCU6_ISR_RCHE_Msk                 (0x1000UL)                /*!< CCU6 ISR: RCHE (Bitfield-Mask: 0x01)                  */
#define CCU6_ISR_RTRPF_Pos                (10UL)                    /*!< CCU6 ISR: RTRPF (Bit 10)                              */
#define CCU6_ISR_RTRPF_Msk                (0x400UL)                 /*!< CCU6 ISR: RTRPF (Bitfield-Mask: 0x01)                 */
#define CCU6_ISR_RT13PM_Pos               (9UL)                     /*!< CCU6 ISR: RT13PM (Bit 9)                              */
#define CCU6_ISR_RT13PM_Msk               (0x200UL)                 /*!< CCU6 ISR: RT13PM (Bitfield-Mask: 0x01)                */
#define CCU6_ISR_RT13CM_Pos               (8UL)                     /*!< CCU6 ISR: RT13CM (Bit 8)                              */
#define CCU6_ISR_RT13CM_Msk               (0x100UL)                 /*!< CCU6 ISR: RT13CM (Bitfield-Mask: 0x01)                */
#define CCU6_ISR_RT12PM_Pos               (7UL)                     /*!< CCU6 ISR: RT12PM (Bit 7)                              */
#define CCU6_ISR_RT12PM_Msk               (0x80UL)                  /*!< CCU6 ISR: RT12PM (Bitfield-Mask: 0x01)                */
#define CCU6_ISR_RT12OM_Pos               (6UL)                     /*!< CCU6 ISR: RT12OM (Bit 6)                              */
#define CCU6_ISR_RT12OM_Msk               (0x40UL)                  /*!< CCU6 ISR: RT12OM (Bitfield-Mask: 0x01)                */
#define CCU6_ISR_RCC62F_Pos               (5UL)                     /*!< CCU6 ISR: RCC62F (Bit 5)                              */
#define CCU6_ISR_RCC62F_Msk               (0x20UL)                  /*!< CCU6 ISR: RCC62F (Bitfield-Mask: 0x01)                */
#define CCU6_ISR_RCC62R_Pos               (4UL)                     /*!< CCU6 ISR: RCC62R (Bit 4)                              */
#define CCU6_ISR_RCC62R_Msk               (0x10UL)                  /*!< CCU6 ISR: RCC62R (Bitfield-Mask: 0x01)                */
#define CCU6_ISR_RCC61F_Pos               (3UL)                     /*!< CCU6 ISR: RCC61F (Bit 3)                              */
#define CCU6_ISR_RCC61F_Msk               (0x8UL)                   /*!< CCU6 ISR: RCC61F (Bitfield-Mask: 0x01)                */
#define CCU6_ISR_RCC61R_Pos               (2UL)                     /*!< CCU6 ISR: RCC61R (Bit 2)                              */
#define CCU6_ISR_RCC61R_Msk               (0x4UL)                   /*!< CCU6 ISR: RCC61R (Bitfield-Mask: 0x01)                */
#define CCU6_ISR_RCC60F_Pos               (1UL)                     /*!< CCU6 ISR: RCC60F (Bit 1)                              */
#define CCU6_ISR_RCC60F_Msk               (0x2UL)                   /*!< CCU6 ISR: RCC60F (Bitfield-Mask: 0x01)                */
#define CCU6_ISR_RCC60R_Pos               (0UL)                     /*!< CCU6 ISR: RCC60R (Bit 0)                              */
#define CCU6_ISR_RCC60R_Msk               (0x1UL)                   /*!< CCU6 ISR: RCC60R (Bitfield-Mask: 0x01)                */
/* ==========================================================  IEN  ========================================================== */
#define CCU6_IEN_ENSTR_Pos                (15UL)                    /*!< CCU6 IEN: ENSTR (Bit 15)                              */
#define CCU6_IEN_ENSTR_Msk                (0x8000UL)                /*!< CCU6 IEN: ENSTR (Bitfield-Mask: 0x01)                 */
#define CCU6_IEN_ENIDLE_Pos               (14UL)                    /*!< CCU6 IEN: ENIDLE (Bit 14)                             */
#define CCU6_IEN_ENIDLE_Msk               (0x4000UL)                /*!< CCU6 IEN: ENIDLE (Bitfield-Mask: 0x01)                */
#define CCU6_IEN_ENWHE_Pos                (13UL)                    /*!< CCU6 IEN: ENWHE (Bit 13)                              */
#define CCU6_IEN_ENWHE_Msk                (0x2000UL)                /*!< CCU6 IEN: ENWHE (Bitfield-Mask: 0x01)                 */
#define CCU6_IEN_ENCHE_Pos                (12UL)                    /*!< CCU6 IEN: ENCHE (Bit 12)                              */
#define CCU6_IEN_ENCHE_Msk                (0x1000UL)                /*!< CCU6 IEN: ENCHE (Bitfield-Mask: 0x01)                 */
#define CCU6_IEN_ENTRPF_Pos               (10UL)                    /*!< CCU6 IEN: ENTRPF (Bit 10)                             */
#define CCU6_IEN_ENTRPF_Msk               (0x400UL)                 /*!< CCU6 IEN: ENTRPF (Bitfield-Mask: 0x01)                */
#define CCU6_IEN_ENT13PM_Pos              (9UL)                     /*!< CCU6 IEN: ENT13PM (Bit 9)                             */
#define CCU6_IEN_ENT13PM_Msk              (0x200UL)                 /*!< CCU6 IEN: ENT13PM (Bitfield-Mask: 0x01)               */
#define CCU6_IEN_ENT13CM_Pos              (8UL)                     /*!< CCU6 IEN: ENT13CM (Bit 8)                             */
#define CCU6_IEN_ENT13CM_Msk              (0x100UL)                 /*!< CCU6 IEN: ENT13CM (Bitfield-Mask: 0x01)               */
#define CCU6_IEN_ENT12PM_Pos              (7UL)                     /*!< CCU6 IEN: ENT12PM (Bit 7)                             */
#define CCU6_IEN_ENT12PM_Msk              (0x80UL)                  /*!< CCU6 IEN: ENT12PM (Bitfield-Mask: 0x01)               */
#define CCU6_IEN_ENT12OM_Pos              (6UL)                     /*!< CCU6 IEN: ENT12OM (Bit 6)                             */
#define CCU6_IEN_ENT12OM_Msk              (0x40UL)                  /*!< CCU6 IEN: ENT12OM (Bitfield-Mask: 0x01)               */
#define CCU6_IEN_ENCC62F_Pos              (5UL)                     /*!< CCU6 IEN: ENCC62F (Bit 5)                             */
#define CCU6_IEN_ENCC62F_Msk              (0x20UL)                  /*!< CCU6 IEN: ENCC62F (Bitfield-Mask: 0x01)               */
#define CCU6_IEN_ENCC62R_Pos              (4UL)                     /*!< CCU6 IEN: ENCC62R (Bit 4)                             */
#define CCU6_IEN_ENCC62R_Msk              (0x10UL)                  /*!< CCU6 IEN: ENCC62R (Bitfield-Mask: 0x01)               */
#define CCU6_IEN_ENCC61F_Pos              (3UL)                     /*!< CCU6 IEN: ENCC61F (Bit 3)                             */
#define CCU6_IEN_ENCC61F_Msk              (0x8UL)                   /*!< CCU6 IEN: ENCC61F (Bitfield-Mask: 0x01)               */
#define CCU6_IEN_ENCC61R_Pos              (2UL)                     /*!< CCU6 IEN: ENCC61R (Bit 2)                             */
#define CCU6_IEN_ENCC61R_Msk              (0x4UL)                   /*!< CCU6 IEN: ENCC61R (Bitfield-Mask: 0x01)               */
#define CCU6_IEN_ENCC60F_Pos              (1UL)                     /*!< CCU6 IEN: ENCC60F (Bit 1)                             */
#define CCU6_IEN_ENCC60F_Msk              (0x2UL)                   /*!< CCU6 IEN: ENCC60F (Bitfield-Mask: 0x01)               */
#define CCU6_IEN_ENCC60R_Pos              (0UL)                     /*!< CCU6 IEN: ENCC60R (Bit 0)                             */
#define CCU6_IEN_ENCC60R_Msk              (0x1UL)                   /*!< CCU6 IEN: ENCC60R (Bitfield-Mask: 0x01)               */
/* ==========================================================  INP  ========================================================== */
#define CCU6_INP_INPT13_Pos               (12UL)                    /*!< CCU6 INP: INPT13 (Bit 12)                             */
#define CCU6_INP_INPT13_Msk               (0x3000UL)                /*!< CCU6 INP: INPT13 (Bitfield-Mask: 0x03)                */
#define CCU6_INP_INPT12_Pos               (10UL)                    /*!< CCU6 INP: INPT12 (Bit 10)                             */
#define CCU6_INP_INPT12_Msk               (0xc00UL)                 /*!< CCU6 INP: INPT12 (Bitfield-Mask: 0x03)                */
#define CCU6_INP_INPERR_Pos               (8UL)                     /*!< CCU6 INP: INPERR (Bit 8)                              */
#define CCU6_INP_INPERR_Msk               (0x300UL)                 /*!< CCU6 INP: INPERR (Bitfield-Mask: 0x03)                */
#define CCU6_INP_INPCHE_Pos               (6UL)                     /*!< CCU6 INP: INPCHE (Bit 6)                              */
#define CCU6_INP_INPCHE_Msk               (0xc0UL)                  /*!< CCU6 INP: INPCHE (Bitfield-Mask: 0x03)                */
#define CCU6_INP_INPCC62_Pos              (4UL)                     /*!< CCU6 INP: INPCC62 (Bit 4)                             */
#define CCU6_INP_INPCC62_Msk              (0x30UL)                  /*!< CCU6 INP: INPCC62 (Bitfield-Mask: 0x03)               */
#define CCU6_INP_INPCC61_Pos              (2UL)                     /*!< CCU6 INP: INPCC61 (Bit 2)                             */
#define CCU6_INP_INPCC61_Msk              (0xcUL)                   /*!< CCU6 INP: INPCC61 (Bitfield-Mask: 0x03)               */
#define CCU6_INP_INPCC60_Pos              (0UL)                     /*!< CCU6 INP: INPCC60 (Bit 0)                             */
#define CCU6_INP_INPCC60_Msk              (0x3UL)                   /*!< CCU6 INP: INPCC60 (Bitfield-Mask: 0x03)               */


/* =========================================================================================================================== */
/* ================                                            CPU                                            ================ */
/* =========================================================================================================================== */

/* ======================================================  SYSTICK_CSR  ====================================================== */
#define CPU_SYSTICK_CSR_COUNTFLAG_Pos     (16UL)                    /*!< CPU SYSTICK_CSR: COUNTFLAG (Bit 16)                   */
#define CPU_SYSTICK_CSR_COUNTFLAG_Msk     (0x10000UL)               /*!< CPU SYSTICK_CSR: COUNTFLAG (Bitfield-Mask: 0x01)      */
#define CPU_SYSTICK_CSR_CLKSOURCE_Pos     (2UL)                     /*!< CPU SYSTICK_CSR: CLKSOURCE (Bit 2)                    */
#define CPU_SYSTICK_CSR_CLKSOURCE_Msk     (0x4UL)                   /*!< CPU SYSTICK_CSR: CLKSOURCE (Bitfield-Mask: 0x01)      */
#define CPU_SYSTICK_CSR_TICKINT_Pos       (1UL)                     /*!< CPU SYSTICK_CSR: TICKINT (Bit 1)                      */
#define CPU_SYSTICK_CSR_TICKINT_Msk       (0x2UL)                   /*!< CPU SYSTICK_CSR: TICKINT (Bitfield-Mask: 0x01)        */
#define CPU_SYSTICK_CSR_ENABLE_Pos        (0UL)                     /*!< CPU SYSTICK_CSR: ENABLE (Bit 0)                       */
#define CPU_SYSTICK_CSR_ENABLE_Msk        (0x1UL)                   /*!< CPU SYSTICK_CSR: ENABLE (Bitfield-Mask: 0x01)         */
/* ======================================================  SYSTICK_RVR  ====================================================== */
#define CPU_SYSTICK_RVR_RELOAD_Pos        (0UL)                     /*!< CPU SYSTICK_RVR: RELOAD (Bit 0)                       */
#define CPU_SYSTICK_RVR_RELOAD_Msk        (0xffffffUL)              /*!< CPU SYSTICK_RVR: RELOAD (Bitfield-Mask: 0xffffff)     */
/* ======================================================  SYSTICK_CVR  ====================================================== */
#define CPU_SYSTICK_CVR_CURRENT_Pos       (0UL)                     /*!< CPU SYSTICK_CVR: CURRENT (Bit 0)                      */
#define CPU_SYSTICK_CVR_CURRENT_Msk       (0xffffffUL)              /*!< CPU SYSTICK_CVR: CURRENT (Bitfield-Mask: 0xffffff)    */
/* =====================================================  SYSTICK_CALIB  ===================================================== */
#define CPU_SYSTICK_CALIB_NOREF_Pos       (31UL)                    /*!< CPU SYSTICK_CALIB: NOREF (Bit 31)                     */
#define CPU_SYSTICK_CALIB_NOREF_Msk       (0x80000000UL)            /*!< CPU SYSTICK_CALIB: NOREF (Bitfield-Mask: 0x01)        */
#define CPU_SYSTICK_CALIB_SKEW_Pos        (30UL)                    /*!< CPU SYSTICK_CALIB: SKEW (Bit 30)                      */
#define CPU_SYSTICK_CALIB_SKEW_Msk        (0x40000000UL)            /*!< CPU SYSTICK_CALIB: SKEW (Bitfield-Mask: 0x01)         */
#define CPU_SYSTICK_CALIB_TENMS_Pos       (0UL)                     /*!< CPU SYSTICK_CALIB: TENMS (Bit 0)                      */
#define CPU_SYSTICK_CALIB_TENMS_Msk       (0xffffffUL)              /*!< CPU SYSTICK_CALIB: TENMS (Bitfield-Mask: 0xffffff)    */
/* =======================================================  NVIC_ISER  ======================================================= */
#define CPU_NVIC_ISER_Int_PORT2_Pos       (23UL)                    /*!< CPU NVIC_ISER: Int_PORT2 (Bit 23)                     */
#define CPU_NVIC_ISER_Int_PORT2_Msk       (0x800000UL)              /*!< CPU NVIC_ISER: Int_PORT2 (Bitfield-Mask: 0x01)        */
#define CPU_NVIC_ISER_Int_MON_Pos         (22UL)                    /*!< CPU NVIC_ISER: Int_MON (Bit 22)                       */
#define CPU_NVIC_ISER_Int_MON_Msk         (0x400000UL)              /*!< CPU NVIC_ISER: Int_MON (Bitfield-Mask: 0x01)          */
#define CPU_NVIC_ISER_Int_DU_Pos          (21UL)                    /*!< CPU NVIC_ISER: Int_DU (Bit 21)                        */
#define CPU_NVIC_ISER_Int_DU_Msk          (0x200000UL)              /*!< CPU NVIC_ISER: Int_DU (Bitfield-Mask: 0x01)           */
#define CPU_NVIC_ISER_Int_HS2_Pos         (20UL)                    /*!< CPU NVIC_ISER: Int_HS2 (Bit 20)                       */
#define CPU_NVIC_ISER_Int_HS2_Msk         (0x100000UL)              /*!< CPU NVIC_ISER: Int_HS2 (Bitfield-Mask: 0x01)          */
#define CPU_NVIC_ISER_Int_HS1_Pos         (19UL)                    /*!< CPU NVIC_ISER: Int_HS1 (Bit 19)                       */
#define CPU_NVIC_ISER_Int_HS1_Msk         (0x80000UL)               /*!< CPU NVIC_ISER: Int_HS1 (Bitfield-Mask: 0x01)          */
#define CPU_NVIC_ISER_Int_LS2_Pos         (18UL)                    /*!< CPU NVIC_ISER: Int_LS2 (Bit 18)                       */
#define CPU_NVIC_ISER_Int_LS2_Msk         (0x40000UL)               /*!< CPU NVIC_ISER: Int_LS2 (Bitfield-Mask: 0x01)          */
#define CPU_NVIC_ISER_Int_LS1_Pos         (17UL)                    /*!< CPU NVIC_ISER: Int_LS1 (Bit 17)                       */
#define CPU_NVIC_ISER_Int_LS1_Msk         (0x20000UL)               /*!< CPU NVIC_ISER: Int_LS1 (Bitfield-Mask: 0x01)          */
#define CPU_NVIC_ISER_Int_WAKEUP_Pos      (14UL)                    /*!< CPU NVIC_ISER: Int_WAKEUP (Bit 14)                    */
#define CPU_NVIC_ISER_Int_WAKEUP_Msk      (0x4000UL)                /*!< CPU NVIC_ISER: Int_WAKEUP (Bitfield-Mask: 0x01)       */
#define CPU_NVIC_ISER_Int_EXINT1_Pos      (13UL)                    /*!< CPU NVIC_ISER: Int_EXINT1 (Bit 13)                    */
#define CPU_NVIC_ISER_Int_EXINT1_Msk      (0x2000UL)                /*!< CPU NVIC_ISER: Int_EXINT1 (Bitfield-Mask: 0x01)       */
#define CPU_NVIC_ISER_Int_EXINT0_Pos      (12UL)                    /*!< CPU NVIC_ISER: Int_EXINT0 (Bit 12)                    */
#define CPU_NVIC_ISER_Int_EXINT0_Msk      (0x1000UL)                /*!< CPU NVIC_ISER: Int_EXINT0 (Bitfield-Mask: 0x01)       */
#define CPU_NVIC_ISER_Int_UART2_Pos       (11UL)                    /*!< CPU NVIC_ISER: Int_UART2 (Bit 11)                     */
#define CPU_NVIC_ISER_Int_UART2_Msk       (0x800UL)                 /*!< CPU NVIC_ISER: Int_UART2 (Bitfield-Mask: 0x01)        */
#define CPU_NVIC_ISER_Int_UART1_Pos       (10UL)                    /*!< CPU NVIC_ISER: Int_UART1 (Bit 10)                     */
#define CPU_NVIC_ISER_Int_UART1_Msk       (0x400UL)                 /*!< CPU NVIC_ISER: Int_UART1 (Bitfield-Mask: 0x01)        */
#define CPU_NVIC_ISER_Int_SSC2_Pos        (9UL)                     /*!< CPU NVIC_ISER: Int_SSC2 (Bit 9)                       */
#define CPU_NVIC_ISER_Int_SSC2_Msk        (0x200UL)                 /*!< CPU NVIC_ISER: Int_SSC2 (Bitfield-Mask: 0x01)         */
#define CPU_NVIC_ISER_Int_SSC1_Pos        (8UL)                     /*!< CPU NVIC_ISER: Int_SSC1 (Bit 8)                       */
#define CPU_NVIC_ISER_Int_SSC1_Msk        (0x100UL)                 /*!< CPU NVIC_ISER: Int_SSC1 (Bitfield-Mask: 0x01)         */
#define CPU_NVIC_ISER_Int_CCU6SR3_Pos     (7UL)                     /*!< CPU NVIC_ISER: Int_CCU6SR3 (Bit 7)                    */
#define CPU_NVIC_ISER_Int_CCU6SR3_Msk     (0x80UL)                  /*!< CPU NVIC_ISER: Int_CCU6SR3 (Bitfield-Mask: 0x01)      */
#define CPU_NVIC_ISER_Int_CCU6SR2_Pos     (6UL)                     /*!< CPU NVIC_ISER: Int_CCU6SR2 (Bit 6)                    */
#define CPU_NVIC_ISER_Int_CCU6SR2_Msk     (0x40UL)                  /*!< CPU NVIC_ISER: Int_CCU6SR2 (Bitfield-Mask: 0x01)      */
#define CPU_NVIC_ISER_Int_CCU6SR1_Pos     (5UL)                     /*!< CPU NVIC_ISER: Int_CCU6SR1 (Bit 5)                    */
#define CPU_NVIC_ISER_Int_CCU6SR1_Msk     (0x20UL)                  /*!< CPU NVIC_ISER: Int_CCU6SR1 (Bitfield-Mask: 0x01)      */
#define CPU_NVIC_ISER_Int_CCU6SR0_Pos     (4UL)                     /*!< CPU NVIC_ISER: Int_CCU6SR0 (Bit 4)                    */
#define CPU_NVIC_ISER_Int_CCU6SR0_Msk     (0x10UL)                  /*!< CPU NVIC_ISER: Int_CCU6SR0 (Bitfield-Mask: 0x01)      */
#define CPU_NVIC_ISER_Int_ADC1_Pos        (3UL)                     /*!< CPU NVIC_ISER: Int_ADC1 (Bit 3)                       */
#define CPU_NVIC_ISER_Int_ADC1_Msk        (0x8UL)                   /*!< CPU NVIC_ISER: Int_ADC1 (Bitfield-Mask: 0x01)         */
#define CPU_NVIC_ISER_Int_ADC2_Pos        (2UL)                     /*!< CPU NVIC_ISER: Int_ADC2 (Bit 2)                       */
#define CPU_NVIC_ISER_Int_ADC2_Msk        (0x4UL)                   /*!< CPU NVIC_ISER: Int_ADC2 (Bitfield-Mask: 0x01)         */
#define CPU_NVIC_ISER_Int_GPT2_Pos        (1UL)                     /*!< CPU NVIC_ISER: Int_GPT2 (Bit 1)                       */
#define CPU_NVIC_ISER_Int_GPT2_Msk        (0x2UL)                   /*!< CPU NVIC_ISER: Int_GPT2 (Bitfield-Mask: 0x01)         */
#define CPU_NVIC_ISER_Int_GPT1_Pos        (0UL)                     /*!< CPU NVIC_ISER: Int_GPT1 (Bit 0)                       */
#define CPU_NVIC_ISER_Int_GPT1_Msk        (0x1UL)                   /*!< CPU NVIC_ISER: Int_GPT1 (Bitfield-Mask: 0x01)         */
/* =======================================================  NVIC_ICER  ======================================================= */
#define CPU_NVIC_ICER_Int_PORT2_Pos       (23UL)                    /*!< CPU NVIC_ICER: Int_PORT2 (Bit 23)                     */
#define CPU_NVIC_ICER_Int_PORT2_Msk       (0x800000UL)              /*!< CPU NVIC_ICER: Int_PORT2 (Bitfield-Mask: 0x01)        */
#define CPU_NVIC_ICER_Int_MON_Pos         (22UL)                    /*!< CPU NVIC_ICER: Int_MON (Bit 22)                       */
#define CPU_NVIC_ICER_Int_MON_Msk         (0x400000UL)              /*!< CPU NVIC_ICER: Int_MON (Bitfield-Mask: 0x01)          */
#define CPU_NVIC_ICER_Int_DU_Pos          (21UL)                    /*!< CPU NVIC_ICER: Int_DU (Bit 21)                        */
#define CPU_NVIC_ICER_Int_DU_Msk          (0x200000UL)              /*!< CPU NVIC_ICER: Int_DU (Bitfield-Mask: 0x01)           */
#define CPU_NVIC_ICER_Int_HS2_Pos         (20UL)                    /*!< CPU NVIC_ICER: Int_HS2 (Bit 20)                       */
#define CPU_NVIC_ICER_Int_HS2_Msk         (0x100000UL)              /*!< CPU NVIC_ICER: Int_HS2 (Bitfield-Mask: 0x01)          */
#define CPU_NVIC_ICER_Int_HS1_Pos         (19UL)                    /*!< CPU NVIC_ICER: Int_HS1 (Bit 19)                       */
#define CPU_NVIC_ICER_Int_HS1_Msk         (0x80000UL)               /*!< CPU NVIC_ICER: Int_HS1 (Bitfield-Mask: 0x01)          */
#define CPU_NVIC_ICER_Int_LS2_Pos         (18UL)                    /*!< CPU NVIC_ICER: Int_LS2 (Bit 18)                       */
#define CPU_NVIC_ICER_Int_LS2_Msk         (0x40000UL)               /*!< CPU NVIC_ICER: Int_LS2 (Bitfield-Mask: 0x01)          */
#define CPU_NVIC_ICER_Int_LS1_Pos         (17UL)                    /*!< CPU NVIC_ICER: Int_LS1 (Bit 17)                       */
#define CPU_NVIC_ICER_Int_LS1_Msk         (0x20000UL)               /*!< CPU NVIC_ICER: Int_LS1 (Bitfield-Mask: 0x01)          */
#define CPU_NVIC_ICER_Int_WAKEUP_Pos      (14UL)                    /*!< CPU NVIC_ICER: Int_WAKEUP (Bit 14)                    */
#define CPU_NVIC_ICER_Int_WAKEUP_Msk      (0x4000UL)                /*!< CPU NVIC_ICER: Int_WAKEUP (Bitfield-Mask: 0x01)       */
#define CPU_NVIC_ICER_Int_EXINT1_Pos      (13UL)                    /*!< CPU NVIC_ICER: Int_EXINT1 (Bit 13)                    */
#define CPU_NVIC_ICER_Int_EXINT1_Msk      (0x2000UL)                /*!< CPU NVIC_ICER: Int_EXINT1 (Bitfield-Mask: 0x01)       */
#define CPU_NVIC_ICER_Int_EXINT0_Pos      (12UL)                    /*!< CPU NVIC_ICER: Int_EXINT0 (Bit 12)                    */
#define CPU_NVIC_ICER_Int_EXINT0_Msk      (0x1000UL)                /*!< CPU NVIC_ICER: Int_EXINT0 (Bitfield-Mask: 0x01)       */
#define CPU_NVIC_ICER_Int_UART2_Pos       (11UL)                    /*!< CPU NVIC_ICER: Int_UART2 (Bit 11)                     */
#define CPU_NVIC_ICER_Int_UART2_Msk       (0x800UL)                 /*!< CPU NVIC_ICER: Int_UART2 (Bitfield-Mask: 0x01)        */
#define CPU_NVIC_ICER_Int_UART1_Pos       (10UL)                    /*!< CPU NVIC_ICER: Int_UART1 (Bit 10)                     */
#define CPU_NVIC_ICER_Int_UART1_Msk       (0x400UL)                 /*!< CPU NVIC_ICER: Int_UART1 (Bitfield-Mask: 0x01)        */
#define CPU_NVIC_ICER_Int_SSC2_Pos        (9UL)                     /*!< CPU NVIC_ICER: Int_SSC2 (Bit 9)                       */
#define CPU_NVIC_ICER_Int_SSC2_Msk        (0x200UL)                 /*!< CPU NVIC_ICER: Int_SSC2 (Bitfield-Mask: 0x01)         */
#define CPU_NVIC_ICER_Int_SSC1_Pos        (8UL)                     /*!< CPU NVIC_ICER: Int_SSC1 (Bit 8)                       */
#define CPU_NVIC_ICER_Int_SSC1_Msk        (0x100UL)                 /*!< CPU NVIC_ICER: Int_SSC1 (Bitfield-Mask: 0x01)         */
#define CPU_NVIC_ICER_Int_CCU6SR3_Pos     (7UL)                     /*!< CPU NVIC_ICER: Int_CCU6SR3 (Bit 7)                    */
#define CPU_NVIC_ICER_Int_CCU6SR3_Msk     (0x80UL)                  /*!< CPU NVIC_ICER: Int_CCU6SR3 (Bitfield-Mask: 0x01)      */
#define CPU_NVIC_ICER_Int_CCU6SR2_Pos     (6UL)                     /*!< CPU NVIC_ICER: Int_CCU6SR2 (Bit 6)                    */
#define CPU_NVIC_ICER_Int_CCU6SR2_Msk     (0x40UL)                  /*!< CPU NVIC_ICER: Int_CCU6SR2 (Bitfield-Mask: 0x01)      */
#define CPU_NVIC_ICER_Int_CCU6SR1_Pos     (5UL)                     /*!< CPU NVIC_ICER: Int_CCU6SR1 (Bit 5)                    */
#define CPU_NVIC_ICER_Int_CCU6SR1_Msk     (0x20UL)                  /*!< CPU NVIC_ICER: Int_CCU6SR1 (Bitfield-Mask: 0x01)      */
#define CPU_NVIC_ICER_Int_CCU6SR0_Pos     (4UL)                     /*!< CPU NVIC_ICER: Int_CCU6SR0 (Bit 4)                    */
#define CPU_NVIC_ICER_Int_CCU6SR0_Msk     (0x10UL)                  /*!< CPU NVIC_ICER: Int_CCU6SR0 (Bitfield-Mask: 0x01)      */
#define CPU_NVIC_ICER_Int_ADC1_Pos        (3UL)                     /*!< CPU NVIC_ICER: Int_ADC1 (Bit 3)                       */
#define CPU_NVIC_ICER_Int_ADC1_Msk        (0x8UL)                   /*!< CPU NVIC_ICER: Int_ADC1 (Bitfield-Mask: 0x01)         */
#define CPU_NVIC_ICER_Int_ADC2_Pos        (2UL)                     /*!< CPU NVIC_ICER: Int_ADC2 (Bit 2)                       */
#define CPU_NVIC_ICER_Int_ADC2_Msk        (0x4UL)                   /*!< CPU NVIC_ICER: Int_ADC2 (Bitfield-Mask: 0x01)         */
#define CPU_NVIC_ICER_Int_GPT2_Pos        (1UL)                     /*!< CPU NVIC_ICER: Int_GPT2 (Bit 1)                       */
#define CPU_NVIC_ICER_Int_GPT2_Msk        (0x2UL)                   /*!< CPU NVIC_ICER: Int_GPT2 (Bitfield-Mask: 0x01)         */
#define CPU_NVIC_ICER_Int_GPT1_Pos        (0UL)                     /*!< CPU NVIC_ICER: Int_GPT1 (Bit 0)                       */
#define CPU_NVIC_ICER_Int_GPT1_Msk        (0x1UL)                   /*!< CPU NVIC_ICER: Int_GPT1 (Bitfield-Mask: 0x01)         */
/* =======================================================  NVIC_ISPR  ======================================================= */
#define CPU_NVIC_ISPR_Int_PORT2_Pos       (23UL)                    /*!< CPU NVIC_ISPR: Int_PORT2 (Bit 23)                     */
#define CPU_NVIC_ISPR_Int_PORT2_Msk       (0x800000UL)              /*!< CPU NVIC_ISPR: Int_PORT2 (Bitfield-Mask: 0x01)        */
#define CPU_NVIC_ISPR_Int_MON_Pos         (22UL)                    /*!< CPU NVIC_ISPR: Int_MON (Bit 22)                       */
#define CPU_NVIC_ISPR_Int_MON_Msk         (0x400000UL)              /*!< CPU NVIC_ISPR: Int_MON (Bitfield-Mask: 0x01)          */
#define CPU_NVIC_ISPR_Int_DU_Pos          (21UL)                    /*!< CPU NVIC_ISPR: Int_DU (Bit 21)                        */
#define CPU_NVIC_ISPR_Int_DU_Msk          (0x200000UL)              /*!< CPU NVIC_ISPR: Int_DU (Bitfield-Mask: 0x01)           */
#define CPU_NVIC_ISPR_Int_HS2_Pos         (20UL)                    /*!< CPU NVIC_ISPR: Int_HS2 (Bit 20)                       */
#define CPU_NVIC_ISPR_Int_HS2_Msk         (0x100000UL)              /*!< CPU NVIC_ISPR: Int_HS2 (Bitfield-Mask: 0x01)          */
#define CPU_NVIC_ISPR_Int_HS1_Pos         (19UL)                    /*!< CPU NVIC_ISPR: Int_HS1 (Bit 19)                       */
#define CPU_NVIC_ISPR_Int_HS1_Msk         (0x80000UL)               /*!< CPU NVIC_ISPR: Int_HS1 (Bitfield-Mask: 0x01)          */
#define CPU_NVIC_ISPR_Int_LS2_Pos         (18UL)                    /*!< CPU NVIC_ISPR: Int_LS2 (Bit 18)                       */
#define CPU_NVIC_ISPR_Int_LS2_Msk         (0x40000UL)               /*!< CPU NVIC_ISPR: Int_LS2 (Bitfield-Mask: 0x01)          */
#define CPU_NVIC_ISPR_Int_LS1_Pos         (17UL)                    /*!< CPU NVIC_ISPR: Int_LS1 (Bit 17)                       */
#define CPU_NVIC_ISPR_Int_LS1_Msk         (0x20000UL)               /*!< CPU NVIC_ISPR: Int_LS1 (Bitfield-Mask: 0x01)          */
#define CPU_NVIC_ISPR_Int_WAKEUP_Pos      (14UL)                    /*!< CPU NVIC_ISPR: Int_WAKEUP (Bit 14)                    */
#define CPU_NVIC_ISPR_Int_WAKEUP_Msk      (0x4000UL)                /*!< CPU NVIC_ISPR: Int_WAKEUP (Bitfield-Mask: 0x01)       */
#define CPU_NVIC_ISPR_Int_EXINT1_Pos      (13UL)                    /*!< CPU NVIC_ISPR: Int_EXINT1 (Bit 13)                    */
#define CPU_NVIC_ISPR_Int_EXINT1_Msk      (0x2000UL)                /*!< CPU NVIC_ISPR: Int_EXINT1 (Bitfield-Mask: 0x01)       */
#define CPU_NVIC_ISPR_Int_EXINT0_Pos      (12UL)                    /*!< CPU NVIC_ISPR: Int_EXINT0 (Bit 12)                    */
#define CPU_NVIC_ISPR_Int_EXINT0_Msk      (0x1000UL)                /*!< CPU NVIC_ISPR: Int_EXINT0 (Bitfield-Mask: 0x01)       */
#define CPU_NVIC_ISPR_Int_UART2_Pos       (11UL)                    /*!< CPU NVIC_ISPR: Int_UART2 (Bit 11)                     */
#define CPU_NVIC_ISPR_Int_UART2_Msk       (0x800UL)                 /*!< CPU NVIC_ISPR: Int_UART2 (Bitfield-Mask: 0x01)        */
#define CPU_NVIC_ISPR_Int_UART1_Pos       (10UL)                    /*!< CPU NVIC_ISPR: Int_UART1 (Bit 10)                     */
#define CPU_NVIC_ISPR_Int_UART1_Msk       (0x400UL)                 /*!< CPU NVIC_ISPR: Int_UART1 (Bitfield-Mask: 0x01)        */
#define CPU_NVIC_ISPR_Int_SSC2_Pos        (9UL)                     /*!< CPU NVIC_ISPR: Int_SSC2 (Bit 9)                       */
#define CPU_NVIC_ISPR_Int_SSC2_Msk        (0x200UL)                 /*!< CPU NVIC_ISPR: Int_SSC2 (Bitfield-Mask: 0x01)         */
#define CPU_NVIC_ISPR_Int_SSC1_Pos        (8UL)                     /*!< CPU NVIC_ISPR: Int_SSC1 (Bit 8)                       */
#define CPU_NVIC_ISPR_Int_SSC1_Msk        (0x100UL)                 /*!< CPU NVIC_ISPR: Int_SSC1 (Bitfield-Mask: 0x01)         */
#define CPU_NVIC_ISPR_Int_CCU6SR3_Pos     (7UL)                     /*!< CPU NVIC_ISPR: Int_CCU6SR3 (Bit 7)                    */
#define CPU_NVIC_ISPR_Int_CCU6SR3_Msk     (0x80UL)                  /*!< CPU NVIC_ISPR: Int_CCU6SR3 (Bitfield-Mask: 0x01)      */
#define CPU_NVIC_ISPR_Int_CCU6SR2_Pos     (6UL)                     /*!< CPU NVIC_ISPR: Int_CCU6SR2 (Bit 6)                    */
#define CPU_NVIC_ISPR_Int_CCU6SR2_Msk     (0x40UL)                  /*!< CPU NVIC_ISPR: Int_CCU6SR2 (Bitfield-Mask: 0x01)      */
#define CPU_NVIC_ISPR_Int_CCU6SR1_Pos     (5UL)                     /*!< CPU NVIC_ISPR: Int_CCU6SR1 (Bit 5)                    */
#define CPU_NVIC_ISPR_Int_CCU6SR1_Msk     (0x20UL)                  /*!< CPU NVIC_ISPR: Int_CCU6SR1 (Bitfield-Mask: 0x01)      */
#define CPU_NVIC_ISPR_Int_CCU6SR0_Pos     (4UL)                     /*!< CPU NVIC_ISPR: Int_CCU6SR0 (Bit 4)                    */
#define CPU_NVIC_ISPR_Int_CCU6SR0_Msk     (0x10UL)                  /*!< CPU NVIC_ISPR: Int_CCU6SR0 (Bitfield-Mask: 0x01)      */
#define CPU_NVIC_ISPR_Int_ADC1_Pos        (3UL)                     /*!< CPU NVIC_ISPR: Int_ADC1 (Bit 3)                       */
#define CPU_NVIC_ISPR_Int_ADC1_Msk        (0x8UL)                   /*!< CPU NVIC_ISPR: Int_ADC1 (Bitfield-Mask: 0x01)         */
#define CPU_NVIC_ISPR_Int_ADC2_Pos        (2UL)                     /*!< CPU NVIC_ISPR: Int_ADC2 (Bit 2)                       */
#define CPU_NVIC_ISPR_Int_ADC2_Msk        (0x4UL)                   /*!< CPU NVIC_ISPR: Int_ADC2 (Bitfield-Mask: 0x01)         */
#define CPU_NVIC_ISPR_Int_GPT2_Pos        (1UL)                     /*!< CPU NVIC_ISPR: Int_GPT2 (Bit 1)                       */
#define CPU_NVIC_ISPR_Int_GPT2_Msk        (0x2UL)                   /*!< CPU NVIC_ISPR: Int_GPT2 (Bitfield-Mask: 0x01)         */
#define CPU_NVIC_ISPR_Int_GPT1_Pos        (0UL)                     /*!< CPU NVIC_ISPR: Int_GPT1 (Bit 0)                       */
#define CPU_NVIC_ISPR_Int_GPT1_Msk        (0x1UL)                   /*!< CPU NVIC_ISPR: Int_GPT1 (Bitfield-Mask: 0x01)         */
/* =======================================================  NVIC_ICPR  ======================================================= */
#define CPU_NVIC_ICPR_Int_PORT2_Pos       (23UL)                    /*!< CPU NVIC_ICPR: Int_PORT2 (Bit 23)                     */
#define CPU_NVIC_ICPR_Int_PORT2_Msk       (0x800000UL)              /*!< CPU NVIC_ICPR: Int_PORT2 (Bitfield-Mask: 0x01)        */
#define CPU_NVIC_ICPR_Int_MON_Pos         (22UL)                    /*!< CPU NVIC_ICPR: Int_MON (Bit 22)                       */
#define CPU_NVIC_ICPR_Int_MON_Msk         (0x400000UL)              /*!< CPU NVIC_ICPR: Int_MON (Bitfield-Mask: 0x01)          */
#define CPU_NVIC_ICPR_Int_DU_Pos          (21UL)                    /*!< CPU NVIC_ICPR: Int_DU (Bit 21)                        */
#define CPU_NVIC_ICPR_Int_DU_Msk          (0x200000UL)              /*!< CPU NVIC_ICPR: Int_DU (Bitfield-Mask: 0x01)           */
#define CPU_NVIC_ICPR_Int_HS2_Pos         (20UL)                    /*!< CPU NVIC_ICPR: Int_HS2 (Bit 20)                       */
#define CPU_NVIC_ICPR_Int_HS2_Msk         (0x100000UL)              /*!< CPU NVIC_ICPR: Int_HS2 (Bitfield-Mask: 0x01)          */
#define CPU_NVIC_ICPR_Int_HS1_Pos         (19UL)                    /*!< CPU NVIC_ICPR: Int_HS1 (Bit 19)                       */
#define CPU_NVIC_ICPR_Int_HS1_Msk         (0x80000UL)               /*!< CPU NVIC_ICPR: Int_HS1 (Bitfield-Mask: 0x01)          */
#define CPU_NVIC_ICPR_Int_LS2_Pos         (18UL)                    /*!< CPU NVIC_ICPR: Int_LS2 (Bit 18)                       */
#define CPU_NVIC_ICPR_Int_LS2_Msk         (0x40000UL)               /*!< CPU NVIC_ICPR: Int_LS2 (Bitfield-Mask: 0x01)          */
#define CPU_NVIC_ICPR_Int_LS1_Pos         (17UL)                    /*!< CPU NVIC_ICPR: Int_LS1 (Bit 17)                       */
#define CPU_NVIC_ICPR_Int_LS1_Msk         (0x20000UL)               /*!< CPU NVIC_ICPR: Int_LS1 (Bitfield-Mask: 0x01)          */
#define CPU_NVIC_ICPR_Int_WAKEUP_Pos      (14UL)                    /*!< CPU NVIC_ICPR: Int_WAKEUP (Bit 14)                    */
#define CPU_NVIC_ICPR_Int_WAKEUP_Msk      (0x4000UL)                /*!< CPU NVIC_ICPR: Int_WAKEUP (Bitfield-Mask: 0x01)       */
#define CPU_NVIC_ICPR_Int_EXINT1_Pos      (13UL)                    /*!< CPU NVIC_ICPR: Int_EXINT1 (Bit 13)                    */
#define CPU_NVIC_ICPR_Int_EXINT1_Msk      (0x2000UL)                /*!< CPU NVIC_ICPR: Int_EXINT1 (Bitfield-Mask: 0x01)       */
#define CPU_NVIC_ICPR_Int_EXINT0_Pos      (12UL)                    /*!< CPU NVIC_ICPR: Int_EXINT0 (Bit 12)                    */
#define CPU_NVIC_ICPR_Int_EXINT0_Msk      (0x1000UL)                /*!< CPU NVIC_ICPR: Int_EXINT0 (Bitfield-Mask: 0x01)       */
#define CPU_NVIC_ICPR_Int_UART2_Pos       (11UL)                    /*!< CPU NVIC_ICPR: Int_UART2 (Bit 11)                     */
#define CPU_NVIC_ICPR_Int_UART2_Msk       (0x800UL)                 /*!< CPU NVIC_ICPR: Int_UART2 (Bitfield-Mask: 0x01)        */
#define CPU_NVIC_ICPR_Int_UART1_Pos       (10UL)                    /*!< CPU NVIC_ICPR: Int_UART1 (Bit 10)                     */
#define CPU_NVIC_ICPR_Int_UART1_Msk       (0x400UL)                 /*!< CPU NVIC_ICPR: Int_UART1 (Bitfield-Mask: 0x01)        */
#define CPU_NVIC_ICPR_Int_SSC2_Pos        (9UL)                     /*!< CPU NVIC_ICPR: Int_SSC2 (Bit 9)                       */
#define CPU_NVIC_ICPR_Int_SSC2_Msk        (0x200UL)                 /*!< CPU NVIC_ICPR: Int_SSC2 (Bitfield-Mask: 0x01)         */
#define CPU_NVIC_ICPR_Int_SSC1_Pos        (8UL)                     /*!< CPU NVIC_ICPR: Int_SSC1 (Bit 8)                       */
#define CPU_NVIC_ICPR_Int_SSC1_Msk        (0x100UL)                 /*!< CPU NVIC_ICPR: Int_SSC1 (Bitfield-Mask: 0x01)         */
#define CPU_NVIC_ICPR_Int_CCU6SR3_Pos     (7UL)                     /*!< CPU NVIC_ICPR: Int_CCU6SR3 (Bit 7)                    */
#define CPU_NVIC_ICPR_Int_CCU6SR3_Msk     (0x80UL)                  /*!< CPU NVIC_ICPR: Int_CCU6SR3 (Bitfield-Mask: 0x01)      */
#define CPU_NVIC_ICPR_Int_CCU6SR2_Pos     (6UL)                     /*!< CPU NVIC_ICPR: Int_CCU6SR2 (Bit 6)                    */
#define CPU_NVIC_ICPR_Int_CCU6SR2_Msk     (0x40UL)                  /*!< CPU NVIC_ICPR: Int_CCU6SR2 (Bitfield-Mask: 0x01)      */
#define CPU_NVIC_ICPR_Int_CCU6SR1_Pos     (5UL)                     /*!< CPU NVIC_ICPR: Int_CCU6SR1 (Bit 5)                    */
#define CPU_NVIC_ICPR_Int_CCU6SR1_Msk     (0x20UL)                  /*!< CPU NVIC_ICPR: Int_CCU6SR1 (Bitfield-Mask: 0x01)      */
#define CPU_NVIC_ICPR_Int_CCU6SR0_Pos     (4UL)                     /*!< CPU NVIC_ICPR: Int_CCU6SR0 (Bit 4)                    */
#define CPU_NVIC_ICPR_Int_CCU6SR0_Msk     (0x10UL)                  /*!< CPU NVIC_ICPR: Int_CCU6SR0 (Bitfield-Mask: 0x01)      */
#define CPU_NVIC_ICPR_Int_ADC1_Pos        (3UL)                     /*!< CPU NVIC_ICPR: Int_ADC1 (Bit 3)                       */
#define CPU_NVIC_ICPR_Int_ADC1_Msk        (0x8UL)                   /*!< CPU NVIC_ICPR: Int_ADC1 (Bitfield-Mask: 0x01)         */
#define CPU_NVIC_ICPR_Int_ADC2_Pos        (2UL)                     /*!< CPU NVIC_ICPR: Int_ADC2 (Bit 2)                       */
#define CPU_NVIC_ICPR_Int_ADC2_Msk        (0x4UL)                   /*!< CPU NVIC_ICPR: Int_ADC2 (Bitfield-Mask: 0x01)         */
#define CPU_NVIC_ICPR_Int_GPT2_Pos        (1UL)                     /*!< CPU NVIC_ICPR: Int_GPT2 (Bit 1)                       */
#define CPU_NVIC_ICPR_Int_GPT2_Msk        (0x2UL)                   /*!< CPU NVIC_ICPR: Int_GPT2 (Bitfield-Mask: 0x01)         */
#define CPU_NVIC_ICPR_Int_GPT1_Pos        (0UL)                     /*!< CPU NVIC_ICPR: Int_GPT1 (Bit 0)                       */
#define CPU_NVIC_ICPR_Int_GPT1_Msk        (0x1UL)                   /*!< CPU NVIC_ICPR: Int_GPT1 (Bitfield-Mask: 0x01)         */
/* =======================================================  NVIC_IPR0  ======================================================= */
#define CPU_NVIC_IPR0_PRI_ADC1_Pos        (24UL)                    /*!< CPU NVIC_IPR0: PRI_ADC1 (Bit 24)                      */
#define CPU_NVIC_IPR0_PRI_ADC1_Msk        (0xff000000UL)            /*!< CPU NVIC_IPR0: PRI_ADC1 (Bitfield-Mask: 0xff)         */
#define CPU_NVIC_IPR0_PRI_ADC2_Pos        (16UL)                    /*!< CPU NVIC_IPR0: PRI_ADC2 (Bit 16)                      */
#define CPU_NVIC_IPR0_PRI_ADC2_Msk        (0xff0000UL)              /*!< CPU NVIC_IPR0: PRI_ADC2 (Bitfield-Mask: 0xff)         */
#define CPU_NVIC_IPR0_PRI_GPT2_Pos        (8UL)                     /*!< CPU NVIC_IPR0: PRI_GPT2 (Bit 8)                       */
#define CPU_NVIC_IPR0_PRI_GPT2_Msk        (0xff00UL)                /*!< CPU NVIC_IPR0: PRI_GPT2 (Bitfield-Mask: 0xff)         */
#define CPU_NVIC_IPR0_PRI_GPT1_Pos        (0UL)                     /*!< CPU NVIC_IPR0: PRI_GPT1 (Bit 0)                       */
#define CPU_NVIC_IPR0_PRI_GPT1_Msk        (0xffUL)                  /*!< CPU NVIC_IPR0: PRI_GPT1 (Bitfield-Mask: 0xff)         */
/* =======================================================  NVIC_IPR1  ======================================================= */
#define CPU_NVIC_IPR1_PRI_CCU6SR3_Pos     (24UL)                    /*!< CPU NVIC_IPR1: PRI_CCU6SR3 (Bit 24)                   */
#define CPU_NVIC_IPR1_PRI_CCU6SR3_Msk     (0xff000000UL)            /*!< CPU NVIC_IPR1: PRI_CCU6SR3 (Bitfield-Mask: 0xff)      */
#define CPU_NVIC_IPR1_PRI_CCU6SR2_Pos     (16UL)                    /*!< CPU NVIC_IPR1: PRI_CCU6SR2 (Bit 16)                   */
#define CPU_NVIC_IPR1_PRI_CCU6SR2_Msk     (0xff0000UL)              /*!< CPU NVIC_IPR1: PRI_CCU6SR2 (Bitfield-Mask: 0xff)      */
#define CPU_NVIC_IPR1_PRI_CCU6SR1_Pos     (8UL)                     /*!< CPU NVIC_IPR1: PRI_CCU6SR1 (Bit 8)                    */
#define CPU_NVIC_IPR1_PRI_CCU6SR1_Msk     (0xff00UL)                /*!< CPU NVIC_IPR1: PRI_CCU6SR1 (Bitfield-Mask: 0xff)      */
#define CPU_NVIC_IPR1_PRI_CCU6SR0_Pos     (0UL)                     /*!< CPU NVIC_IPR1: PRI_CCU6SR0 (Bit 0)                    */
#define CPU_NVIC_IPR1_PRI_CCU6SR0_Msk     (0xffUL)                  /*!< CPU NVIC_IPR1: PRI_CCU6SR0 (Bitfield-Mask: 0xff)      */
/* =======================================================  NVIC_IPR2  ======================================================= */
#define CPU_NVIC_IPR2_PRI_UART2_Pos       (24UL)                    /*!< CPU NVIC_IPR2: PRI_UART2 (Bit 24)                     */
#define CPU_NVIC_IPR2_PRI_UART2_Msk       (0xff000000UL)            /*!< CPU NVIC_IPR2: PRI_UART2 (Bitfield-Mask: 0xff)        */
#define CPU_NVIC_IPR2_PRI_UART1_Pos       (16UL)                    /*!< CPU NVIC_IPR2: PRI_UART1 (Bit 16)                     */
#define CPU_NVIC_IPR2_PRI_UART1_Msk       (0xff0000UL)              /*!< CPU NVIC_IPR2: PRI_UART1 (Bitfield-Mask: 0xff)        */
#define CPU_NVIC_IPR2_PRI_SSC2_Pos        (8UL)                     /*!< CPU NVIC_IPR2: PRI_SSC2 (Bit 8)                       */
#define CPU_NVIC_IPR2_PRI_SSC2_Msk        (0xff00UL)                /*!< CPU NVIC_IPR2: PRI_SSC2 (Bitfield-Mask: 0xff)         */
#define CPU_NVIC_IPR2_PRI_SSC1_Pos        (0UL)                     /*!< CPU NVIC_IPR2: PRI_SSC1 (Bit 0)                       */
#define CPU_NVIC_IPR2_PRI_SSC1_Msk        (0xffUL)                  /*!< CPU NVIC_IPR2: PRI_SSC1 (Bitfield-Mask: 0xff)         */
/* =======================================================  NVIC_IPR3  ======================================================= */
#define CPU_NVIC_IPR3_PRI_WAKEUP_Pos      (16UL)                    /*!< CPU NVIC_IPR3: PRI_WAKEUP (Bit 16)                    */
#define CPU_NVIC_IPR3_PRI_WAKEUP_Msk      (0xff0000UL)              /*!< CPU NVIC_IPR3: PRI_WAKEUP (Bitfield-Mask: 0xff)       */
#define CPU_NVIC_IPR3_PRI_EXINT1_Pos      (8UL)                     /*!< CPU NVIC_IPR3: PRI_EXINT1 (Bit 8)                     */
#define CPU_NVIC_IPR3_PRI_EXINT1_Msk      (0xff00UL)                /*!< CPU NVIC_IPR3: PRI_EXINT1 (Bitfield-Mask: 0xff)       */
#define CPU_NVIC_IPR3_PRI_EXINT0_Pos      (0UL)                     /*!< CPU NVIC_IPR3: PRI_EXINT0 (Bit 0)                     */
#define CPU_NVIC_IPR3_PRI_EXINT0_Msk      (0xffUL)                  /*!< CPU NVIC_IPR3: PRI_EXINT0 (Bitfield-Mask: 0xff)       */
/* =======================================================  NVIC_IPR4  ======================================================= */
#define CPU_NVIC_IPR4_PRI_HS1_Pos         (24UL)                    /*!< CPU NVIC_IPR4: PRI_HS1 (Bit 24)                       */
#define CPU_NVIC_IPR4_PRI_HS1_Msk         (0xff000000UL)            /*!< CPU NVIC_IPR4: PRI_HS1 (Bitfield-Mask: 0xff)          */
#define CPU_NVIC_IPR4_PRI_LS2_Pos         (16UL)                    /*!< CPU NVIC_IPR4: PRI_LS2 (Bit 16)                       */
#define CPU_NVIC_IPR4_PRI_LS2_Msk         (0xff0000UL)              /*!< CPU NVIC_IPR4: PRI_LS2 (Bitfield-Mask: 0xff)          */
#define CPU_NVIC_IPR4_PRI_LS1_Pos         (8UL)                     /*!< CPU NVIC_IPR4: PRI_LS1 (Bit 8)                        */
#define CPU_NVIC_IPR4_PRI_LS1_Msk         (0xff00UL)                /*!< CPU NVIC_IPR4: PRI_LS1 (Bitfield-Mask: 0xff)          */
/* =======================================================  NVIC_IPR5  ======================================================= */
#define CPU_NVIC_IPR5_PRI_PORT2_Pos       (24UL)                    /*!< CPU NVIC_IPR5: PRI_PORT2 (Bit 24)                     */
#define CPU_NVIC_IPR5_PRI_PORT2_Msk       (0xff000000UL)            /*!< CPU NVIC_IPR5: PRI_PORT2 (Bitfield-Mask: 0xff)        */
#define CPU_NVIC_IPR5_PRI_MON_Pos         (16UL)                    /*!< CPU NVIC_IPR5: PRI_MON (Bit 16)                       */
#define CPU_NVIC_IPR5_PRI_MON_Msk         (0xff0000UL)              /*!< CPU NVIC_IPR5: PRI_MON (Bitfield-Mask: 0xff)          */
#define CPU_NVIC_IPR5_PRI_DU_Pos          (8UL)                     /*!< CPU NVIC_IPR5: PRI_DU (Bit 8)                         */
#define CPU_NVIC_IPR5_PRI_DU_Msk          (0xff00UL)                /*!< CPU NVIC_IPR5: PRI_DU (Bitfield-Mask: 0xff)           */
#define CPU_NVIC_IPR5_PRI_HS2_Pos         (0UL)                     /*!< CPU NVIC_IPR5: PRI_HS2 (Bit 0)                        */
#define CPU_NVIC_IPR5_PRI_HS2_Msk         (0xffUL)                  /*!< CPU NVIC_IPR5: PRI_HS2 (Bitfield-Mask: 0xff)          */
/* =========================================================  CPUID  ========================================================= */
#define CPU_CPUID_IMPLEMENTER_Pos         (24UL)                    /*!< CPU CPUID: IMPLEMENTER (Bit 24)                       */
#define CPU_CPUID_IMPLEMENTER_Msk         (0xff000000UL)            /*!< CPU CPUID: IMPLEMENTER (Bitfield-Mask: 0xff)          */
#define CPU_CPUID_VARIANT_Pos             (20UL)                    /*!< CPU CPUID: VARIANT (Bit 20)                           */
#define CPU_CPUID_VARIANT_Msk             (0xf00000UL)              /*!< CPU CPUID: VARIANT (Bitfield-Mask: 0x0f)              */
#define CPU_CPUID_CONSTANT_Pos            (16UL)                    /*!< CPU CPUID: CONSTANT (Bit 16)                          */
#define CPU_CPUID_CONSTANT_Msk            (0xf0000UL)               /*!< CPU CPUID: CONSTANT (Bitfield-Mask: 0x0f)             */
#define CPU_CPUID_PARTNO_Pos              (4UL)                     /*!< CPU CPUID: PARTNO (Bit 4)                             */
#define CPU_CPUID_PARTNO_Msk              (0xfff0UL)                /*!< CPU CPUID: PARTNO (Bitfield-Mask: 0xfff)              */
#define CPU_CPUID_REVISION_Pos            (0UL)                     /*!< CPU CPUID: REVISION (Bit 0)                           */
#define CPU_CPUID_REVISION_Msk            (0xfUL)                   /*!< CPU CPUID: REVISION (Bitfield-Mask: 0x0f)             */
/* =========================================================  ICSR  ========================================================== */
#define CPU_ICSR_NMIPENDSET_Pos           (31UL)                    /*!< CPU ICSR: NMIPENDSET (Bit 31)                         */
#define CPU_ICSR_NMIPENDSET_Msk           (0x80000000UL)            /*!< CPU ICSR: NMIPENDSET (Bitfield-Mask: 0x01)            */
#define CPU_ICSR_PENDSVSET_Pos            (28UL)                    /*!< CPU ICSR: PENDSVSET (Bit 28)                          */
#define CPU_ICSR_PENDSVSET_Msk            (0x10000000UL)            /*!< CPU ICSR: PENDSVSET (Bitfield-Mask: 0x01)             */
#define CPU_ICSR_PENDSVCLR_Pos            (27UL)                    /*!< CPU ICSR: PENDSVCLR (Bit 27)                          */
#define CPU_ICSR_PENDSVCLR_Msk            (0x8000000UL)             /*!< CPU ICSR: PENDSVCLR (Bitfield-Mask: 0x01)             */
#define CPU_ICSR_PENDSTSET_Pos            (26UL)                    /*!< CPU ICSR: PENDSTSET (Bit 26)                          */
#define CPU_ICSR_PENDSTSET_Msk            (0x4000000UL)             /*!< CPU ICSR: PENDSTSET (Bitfield-Mask: 0x01)             */
#define CPU_ICSR_PENDSTCLR_Pos            (25UL)                    /*!< CPU ICSR: PENDSTCLR (Bit 25)                          */
#define CPU_ICSR_PENDSTCLR_Msk            (0x2000000UL)             /*!< CPU ICSR: PENDSTCLR (Bitfield-Mask: 0x01)             */
#define CPU_ICSR_ISRPENDING_Pos           (22UL)                    /*!< CPU ICSR: ISRPENDING (Bit 22)                         */
#define CPU_ICSR_ISRPENDING_Msk           (0x400000UL)              /*!< CPU ICSR: ISRPENDING (Bitfield-Mask: 0x01)            */
#define CPU_ICSR_VECTPENDING_Pos          (12UL)                    /*!< CPU ICSR: VECTPENDING (Bit 12)                        */
#define CPU_ICSR_VECTPENDING_Msk          (0x3f000UL)               /*!< CPU ICSR: VECTPENDING (Bitfield-Mask: 0x3f)           */
#define CPU_ICSR_VECTACTIVE_Pos           (0UL)                     /*!< CPU ICSR: VECTACTIVE (Bit 0)                          */
#define CPU_ICSR_VECTACTIVE_Msk           (0x3fUL)                  /*!< CPU ICSR: VECTACTIVE (Bitfield-Mask: 0x3f)            */
/* =========================================================  AIRCR  ========================================================= */
#define CPU_AIRCR_VECTKEY_Pos             (16UL)                    /*!< CPU AIRCR: VECTKEY (Bit 16)                           */
#define CPU_AIRCR_VECTKEY_Msk             (0xffff0000UL)            /*!< CPU AIRCR: VECTKEY (Bitfield-Mask: 0xffff)            */
#define CPU_AIRCR_ENDIANNESS_Pos          (15UL)                    /*!< CPU AIRCR: ENDIANNESS (Bit 15)                        */
#define CPU_AIRCR_ENDIANNESS_Msk          (0x8000UL)                /*!< CPU AIRCR: ENDIANNESS (Bitfield-Mask: 0x01)           */
#define CPU_AIRCR_SYSRESETREQ_Pos         (2UL)                     /*!< CPU AIRCR: SYSRESETREQ (Bit 2)                        */
#define CPU_AIRCR_SYSRESETREQ_Msk         (0x4UL)                   /*!< CPU AIRCR: SYSRESETREQ (Bitfield-Mask: 0x01)          */
#define CPU_AIRCR_VECTCLRACTIVE_Pos       (1UL)                     /*!< CPU AIRCR: VECTCLRACTIVE (Bit 1)                      */
#define CPU_AIRCR_VECTCLRACTIVE_Msk       (0x2UL)                   /*!< CPU AIRCR: VECTCLRACTIVE (Bitfield-Mask: 0x01)        */
/* ==========================================================  SCR  ========================================================== */
#define CPU_SCR_SEVONPEND_Pos             (4UL)                     /*!< CPU SCR: SEVONPEND (Bit 4)                            */
#define CPU_SCR_SEVONPEND_Msk             (0x10UL)                  /*!< CPU SCR: SEVONPEND (Bitfield-Mask: 0x01)              */
#define CPU_SCR_SLEEPDEEP_Pos             (2UL)                     /*!< CPU SCR: SLEEPDEEP (Bit 2)                            */
#define CPU_SCR_SLEEPDEEP_Msk             (0x4UL)                   /*!< CPU SCR: SLEEPDEEP (Bitfield-Mask: 0x01)              */
#define CPU_SCR_SLEEPONEXIT_Pos           (1UL)                     /*!< CPU SCR: SLEEPONEXIT (Bit 1)                          */
#define CPU_SCR_SLEEPONEXIT_Msk           (0x2UL)                   /*!< CPU SCR: SLEEPONEXIT (Bitfield-Mask: 0x01)            */
/* ==========================================================  CCR  ========================================================== */
#define CPU_CCR_STKALIGN_Pos              (9UL)                     /*!< CPU CCR: STKALIGN (Bit 9)                             */
#define CPU_CCR_STKALIGN_Msk              (0x200UL)                 /*!< CPU CCR: STKALIGN (Bitfield-Mask: 0x01)               */
#define CPU_CCR_UNALIGN_TRP_Pos           (3UL)                     /*!< CPU CCR: UNALIGN_TRP (Bit 3)                          */
#define CPU_CCR_UNALIGN_TRP_Msk           (0x8UL)                   /*!< CPU CCR: UNALIGN_TRP (Bitfield-Mask: 0x01)            */
/* =========================================================  SHPR2  ========================================================= */
#define CPU_SHPR2_PRI_11_Pos              (24UL)                    /*!< CPU SHPR2: PRI_11 (Bit 24)                            */
#define CPU_SHPR2_PRI_11_Msk              (0xff000000UL)            /*!< CPU SHPR2: PRI_11 (Bitfield-Mask: 0xff)               */
/* =========================================================  SHPR3  ========================================================= */
#define CPU_SHPR3_PRI_15_Pos              (24UL)                    /*!< CPU SHPR3: PRI_15 (Bit 24)                            */
#define CPU_SHPR3_PRI_15_Msk              (0xff000000UL)            /*!< CPU SHPR3: PRI_15 (Bitfield-Mask: 0xff)               */
#define CPU_SHPR3_PRI_14_Pos              (16UL)                    /*!< CPU SHPR3: PRI_14 (Bit 16)                            */
#define CPU_SHPR3_PRI_14_Msk              (0xff0000UL)              /*!< CPU SHPR3: PRI_14 (Bitfield-Mask: 0xff)               */


/* =========================================================================================================================== */
/* ================                                          GPT12E                                           ================ */
/* =========================================================================================================================== */

/* ==========================================================  T2  =========================================================== */
#define GPT12E_T2_T2_Pos                  (0UL)                     /*!< GPT12E T2: T2 (Bit 0)                                 */
#define GPT12E_T2_T2_Msk                  (0xffffUL)                /*!< GPT12E T2: T2 (Bitfield-Mask: 0xffff)                 */
/* ==========================================================  T3  =========================================================== */
#define GPT12E_T3_T3_Pos                  (0UL)                     /*!< GPT12E T3: T3 (Bit 0)                                 */
#define GPT12E_T3_T3_Msk                  (0xffffUL)                /*!< GPT12E T3: T3 (Bitfield-Mask: 0xffff)                 */
/* ==========================================================  T4  =========================================================== */
#define GPT12E_T4_T4_Pos                  (0UL)                     /*!< GPT12E T4: T4 (Bit 0)                                 */
#define GPT12E_T4_T4_Msk                  (0xffffUL)                /*!< GPT12E T4: T4 (Bitfield-Mask: 0xffff)                 */
/* =========================================================  T3CON  ========================================================= */
#define GPT12E_T3CON_T3DIR_Pos            (15UL)                    /*!< GPT12E T3CON: T3DIR (Bit 15)                          */
#define GPT12E_T3CON_T3DIR_Msk            (0x8000UL)                /*!< GPT12E T3CON: T3DIR (Bitfield-Mask: 0x01)             */
#define GPT12E_T3CON_T3CHDIR_Pos          (14UL)                    /*!< GPT12E T3CON: T3CHDIR (Bit 14)                        */
#define GPT12E_T3CON_T3CHDIR_Msk          (0x4000UL)                /*!< GPT12E T3CON: T3CHDIR (Bitfield-Mask: 0x01)           */
#define GPT12E_T3CON_T3EDGE_Pos           (13UL)                    /*!< GPT12E T3CON: T3EDGE (Bit 13)                         */
#define GPT12E_T3CON_T3EDGE_Msk           (0x2000UL)                /*!< GPT12E T3CON: T3EDGE (Bitfield-Mask: 0x01)            */
#define GPT12E_T3CON_BPS1_Pos             (11UL)                    /*!< GPT12E T3CON: BPS1 (Bit 11)                           */
#define GPT12E_T3CON_BPS1_Msk             (0x1800UL)                /*!< GPT12E T3CON: BPS1 (Bitfield-Mask: 0x03)              */
#define GPT12E_T3CON_T3OTL_Pos            (10UL)                    /*!< GPT12E T3CON: T3OTL (Bit 10)                          */
#define GPT12E_T3CON_T3OTL_Msk            (0x400UL)                 /*!< GPT12E T3CON: T3OTL (Bitfield-Mask: 0x01)             */
#define GPT12E_T3CON_T3OE_Pos             (9UL)                     /*!< GPT12E T3CON: T3OE (Bit 9)                            */
#define GPT12E_T3CON_T3OE_Msk             (0x200UL)                 /*!< GPT12E T3CON: T3OE (Bitfield-Mask: 0x01)              */
#define GPT12E_T3CON_T3UDE_Pos            (8UL)                     /*!< GPT12E T3CON: T3UDE (Bit 8)                           */
#define GPT12E_T3CON_T3UDE_Msk            (0x100UL)                 /*!< GPT12E T3CON: T3UDE (Bitfield-Mask: 0x01)             */
#define GPT12E_T3CON_T3UD_Pos             (7UL)                     /*!< GPT12E T3CON: T3UD (Bit 7)                            */
#define GPT12E_T3CON_T3UD_Msk             (0x80UL)                  /*!< GPT12E T3CON: T3UD (Bitfield-Mask: 0x01)              */
#define GPT12E_T3CON_T3R_Pos              (6UL)                     /*!< GPT12E T3CON: T3R (Bit 6)                             */
#define GPT12E_T3CON_T3R_Msk              (0x40UL)                  /*!< GPT12E T3CON: T3R (Bitfield-Mask: 0x01)               */
#define GPT12E_T3CON_T3M_Pos              (3UL)                     /*!< GPT12E T3CON: T3M (Bit 3)                             */
#define GPT12E_T3CON_T3M_Msk              (0x38UL)                  /*!< GPT12E T3CON: T3M (Bitfield-Mask: 0x07)               */
#define GPT12E_T3CON_T3I_Pos              (0UL)                     /*!< GPT12E T3CON: T3I (Bit 0)                             */
#define GPT12E_T3CON_T3I_Msk              (0x7UL)                   /*!< GPT12E T3CON: T3I (Bitfield-Mask: 0x07)               */
/* =========================================================  T2CON  ========================================================= */
#define GPT12E_T2CON_T2DIR_Pos            (15UL)                    /*!< GPT12E T2CON: T2DIR (Bit 15)                          */
#define GPT12E_T2CON_T2DIR_Msk            (0x8000UL)                /*!< GPT12E T2CON: T2DIR (Bitfield-Mask: 0x01)             */
#define GPT12E_T2CON_T2CHDIR_Pos          (14UL)                    /*!< GPT12E T2CON: T2CHDIR (Bit 14)                        */
#define GPT12E_T2CON_T2CHDIR_Msk          (0x4000UL)                /*!< GPT12E T2CON: T2CHDIR (Bitfield-Mask: 0x01)           */
#define GPT12E_T2CON_T2EDGE_Pos           (13UL)                    /*!< GPT12E T2CON: T2EDGE (Bit 13)                         */
#define GPT12E_T2CON_T2EDGE_Msk           (0x2000UL)                /*!< GPT12E T2CON: T2EDGE (Bitfield-Mask: 0x01)            */
#define GPT12E_T2CON_T2IRIDIS_Pos         (12UL)                    /*!< GPT12E T2CON: T2IRIDIS (Bit 12)                       */
#define GPT12E_T2CON_T2IRIDIS_Msk         (0x1000UL)                /*!< GPT12E T2CON: T2IRIDIS (Bitfield-Mask: 0x01)          */
#define GPT12E_T2CON_T2RC_Pos             (9UL)                     /*!< GPT12E T2CON: T2RC (Bit 9)                            */
#define GPT12E_T2CON_T2RC_Msk             (0x200UL)                 /*!< GPT12E T2CON: T2RC (Bitfield-Mask: 0x01)              */
#define GPT12E_T2CON_T2UDE_Pos            (8UL)                     /*!< GPT12E T2CON: T2UDE (Bit 8)                           */
#define GPT12E_T2CON_T2UDE_Msk            (0x100UL)                 /*!< GPT12E T2CON: T2UDE (Bitfield-Mask: 0x01)             */
#define GPT12E_T2CON_T2UD_Pos             (7UL)                     /*!< GPT12E T2CON: T2UD (Bit 7)                            */
#define GPT12E_T2CON_T2UD_Msk             (0x80UL)                  /*!< GPT12E T2CON: T2UD (Bitfield-Mask: 0x01)              */
#define GPT12E_T2CON_T2R_Pos              (6UL)                     /*!< GPT12E T2CON: T2R (Bit 6)                             */
#define GPT12E_T2CON_T2R_Msk              (0x40UL)                  /*!< GPT12E T2CON: T2R (Bitfield-Mask: 0x01)               */
#define GPT12E_T2CON_T2M_Pos              (3UL)                     /*!< GPT12E T2CON: T2M (Bit 3)                             */
#define GPT12E_T2CON_T2M_Msk              (0x38UL)                  /*!< GPT12E T2CON: T2M (Bitfield-Mask: 0x07)               */
#define GPT12E_T2CON_T2I_Pos              (0UL)                     /*!< GPT12E T2CON: T2I (Bit 0)                             */
#define GPT12E_T2CON_T2I_Msk              (0x7UL)                   /*!< GPT12E T2CON: T2I (Bitfield-Mask: 0x07)               */
/* =========================================================  T4CON  ========================================================= */
#define GPT12E_T4CON_T4RDIR_Pos           (15UL)                    /*!< GPT12E T4CON: T4RDIR (Bit 15)                         */
#define GPT12E_T4CON_T4RDIR_Msk           (0x8000UL)                /*!< GPT12E T4CON: T4RDIR (Bitfield-Mask: 0x01)            */
#define GPT12E_T4CON_T4CHDIR_Pos          (14UL)                    /*!< GPT12E T4CON: T4CHDIR (Bit 14)                        */
#define GPT12E_T4CON_T4CHDIR_Msk          (0x4000UL)                /*!< GPT12E T4CON: T4CHDIR (Bitfield-Mask: 0x01)           */
#define GPT12E_T4CON_T4EDGE_Pos           (13UL)                    /*!< GPT12E T4CON: T4EDGE (Bit 13)                         */
#define GPT12E_T4CON_T4EDGE_Msk           (0x2000UL)                /*!< GPT12E T4CON: T4EDGE (Bitfield-Mask: 0x01)            */
#define GPT12E_T4CON_T4IRDIS_Pos          (12UL)                    /*!< GPT12E T4CON: T4IRDIS (Bit 12)                        */
#define GPT12E_T4CON_T4IRDIS_Msk          (0x1000UL)                /*!< GPT12E T4CON: T4IRDIS (Bitfield-Mask: 0x01)           */
#define GPT12E_T4CON_CLRT3EN_Pos          (11UL)                    /*!< GPT12E T4CON: CLRT3EN (Bit 11)                        */
#define GPT12E_T4CON_CLRT3EN_Msk          (0x800UL)                 /*!< GPT12E T4CON: CLRT3EN (Bitfield-Mask: 0x01)           */
#define GPT12E_T4CON_CLRT2EN_Pos          (10UL)                    /*!< GPT12E T4CON: CLRT2EN (Bit 10)                        */
#define GPT12E_T4CON_CLRT2EN_Msk          (0x400UL)                 /*!< GPT12E T4CON: CLRT2EN (Bitfield-Mask: 0x01)           */
#define GPT12E_T4CON_T4RC_Pos             (9UL)                     /*!< GPT12E T4CON: T4RC (Bit 9)                            */
#define GPT12E_T4CON_T4RC_Msk             (0x200UL)                 /*!< GPT12E T4CON: T4RC (Bitfield-Mask: 0x01)              */
#define GPT12E_T4CON_T4UDE_Pos            (8UL)                     /*!< GPT12E T4CON: T4UDE (Bit 8)                           */
#define GPT12E_T4CON_T4UDE_Msk            (0x100UL)                 /*!< GPT12E T4CON: T4UDE (Bitfield-Mask: 0x01)             */
#define GPT12E_T4CON_T4UD_Pos             (7UL)                     /*!< GPT12E T4CON: T4UD (Bit 7)                            */
#define GPT12E_T4CON_T4UD_Msk             (0x80UL)                  /*!< GPT12E T4CON: T4UD (Bitfield-Mask: 0x01)              */
#define GPT12E_T4CON_T4R_Pos              (6UL)                     /*!< GPT12E T4CON: T4R (Bit 6)                             */
#define GPT12E_T4CON_T4R_Msk              (0x40UL)                  /*!< GPT12E T4CON: T4R (Bitfield-Mask: 0x01)               */
#define GPT12E_T4CON_T4M_Pos              (3UL)                     /*!< GPT12E T4CON: T4M (Bit 3)                             */
#define GPT12E_T4CON_T4M_Msk              (0x38UL)                  /*!< GPT12E T4CON: T4M (Bitfield-Mask: 0x07)               */
#define GPT12E_T4CON_T4I_Pos              (0UL)                     /*!< GPT12E T4CON: T4I (Bit 0)                             */
#define GPT12E_T4CON_T4I_Msk              (0x7UL)                   /*!< GPT12E T4CON: T4I (Bitfield-Mask: 0x07)               */
/* ==========================================================  T5  =========================================================== */
#define GPT12E_T5_T5_Pos                  (0UL)                     /*!< GPT12E T5: T5 (Bit 0)                                 */
#define GPT12E_T5_T5_Msk                  (0xffffUL)                /*!< GPT12E T5: T5 (Bitfield-Mask: 0xffff)                 */
/* ==========================================================  T6  =========================================================== */
#define GPT12E_T6_T6_Pos                  (0UL)                     /*!< GPT12E T6: T6 (Bit 0)                                 */
#define GPT12E_T6_T6_Msk                  (0xffffUL)                /*!< GPT12E T6: T6 (Bitfield-Mask: 0xffff)                 */
/* ========================================================  CAPREL  ========================================================= */
#define GPT12E_CAPREL_CAPREL_Pos          (0UL)                     /*!< GPT12E CAPREL: CAPREL (Bit 0)                         */
#define GPT12E_CAPREL_CAPREL_Msk          (0xffffUL)                /*!< GPT12E CAPREL: CAPREL (Bitfield-Mask: 0xffff)         */
/* =========================================================  T6CON  ========================================================= */
#define GPT12E_T6CON_T6SR_Pos             (15UL)                    /*!< GPT12E T6CON: T6SR (Bit 15)                           */
#define GPT12E_T6CON_T6SR_Msk             (0x8000UL)                /*!< GPT12E T6CON: T6SR (Bitfield-Mask: 0x01)              */
#define GPT12E_T6CON_T6CLR_Pos            (14UL)                    /*!< GPT12E T6CON: T6CLR (Bit 14)                          */
#define GPT12E_T6CON_T6CLR_Msk            (0x4000UL)                /*!< GPT12E T6CON: T6CLR (Bitfield-Mask: 0x01)             */
#define GPT12E_T6CON_BPS2_Pos             (11UL)                    /*!< GPT12E T6CON: BPS2 (Bit 11)                           */
#define GPT12E_T6CON_BPS2_Msk             (0x1800UL)                /*!< GPT12E T6CON: BPS2 (Bitfield-Mask: 0x03)              */
#define GPT12E_T6CON_T6OTL_Pos            (10UL)                    /*!< GPT12E T6CON: T6OTL (Bit 10)                          */
#define GPT12E_T6CON_T6OTL_Msk            (0x400UL)                 /*!< GPT12E T6CON: T6OTL (Bitfield-Mask: 0x01)             */
#define GPT12E_T6CON_T6OE_Pos             (9UL)                     /*!< GPT12E T6CON: T6OE (Bit 9)                            */
#define GPT12E_T6CON_T6OE_Msk             (0x200UL)                 /*!< GPT12E T6CON: T6OE (Bitfield-Mask: 0x01)              */
#define GPT12E_T6CON_T6UDE_Pos            (8UL)                     /*!< GPT12E T6CON: T6UDE (Bit 8)                           */
#define GPT12E_T6CON_T6UDE_Msk            (0x100UL)                 /*!< GPT12E T6CON: T6UDE (Bitfield-Mask: 0x01)             */
#define GPT12E_T6CON_T6UD_Pos             (7UL)                     /*!< GPT12E T6CON: T6UD (Bit 7)                            */
#define GPT12E_T6CON_T6UD_Msk             (0x80UL)                  /*!< GPT12E T6CON: T6UD (Bitfield-Mask: 0x01)              */
#define GPT12E_T6CON_T6R_Pos              (6UL)                     /*!< GPT12E T6CON: T6R (Bit 6)                             */
#define GPT12E_T6CON_T6R_Msk              (0x40UL)                  /*!< GPT12E T6CON: T6R (Bitfield-Mask: 0x01)               */
#define GPT12E_T6CON_T6M_Pos              (3UL)                     /*!< GPT12E T6CON: T6M (Bit 3)                             */
#define GPT12E_T6CON_T6M_Msk              (0x38UL)                  /*!< GPT12E T6CON: T6M (Bitfield-Mask: 0x07)               */
#define GPT12E_T6CON_T6I_Pos              (0UL)                     /*!< GPT12E T6CON: T6I (Bit 0)                             */
#define GPT12E_T6CON_T6I_Msk              (0x7UL)                   /*!< GPT12E T6CON: T6I (Bitfield-Mask: 0x07)               */
/* =========================================================  T5CON  ========================================================= */
#define GPT12E_T5CON_T5SC_Pos             (15UL)                    /*!< GPT12E T5CON: T5SC (Bit 15)                           */
#define GPT12E_T5CON_T5SC_Msk             (0x8000UL)                /*!< GPT12E T5CON: T5SC (Bitfield-Mask: 0x01)              */
#define GPT12E_T5CON_T5CLR_Pos            (14UL)                    /*!< GPT12E T5CON: T5CLR (Bit 14)                          */
#define GPT12E_T5CON_T5CLR_Msk            (0x4000UL)                /*!< GPT12E T5CON: T5CLR (Bitfield-Mask: 0x01)             */
#define GPT12E_T5CON_CI_Pos               (12UL)                    /*!< GPT12E T5CON: CI (Bit 12)                             */
#define GPT12E_T5CON_CI_Msk               (0x3000UL)                /*!< GPT12E T5CON: CI (Bitfield-Mask: 0x03)                */
#define GPT12E_T5CON_CT3_Pos              (10UL)                    /*!< GPT12E T5CON: CT3 (Bit 10)                            */
#define GPT12E_T5CON_CT3_Msk              (0x400UL)                 /*!< GPT12E T5CON: CT3 (Bitfield-Mask: 0x01)               */
#define GPT12E_T5CON_T5RC_Pos             (9UL)                     /*!< GPT12E T5CON: T5RC (Bit 9)                            */
#define GPT12E_T5CON_T5RC_Msk             (0x200UL)                 /*!< GPT12E T5CON: T5RC (Bitfield-Mask: 0x01)              */
#define GPT12E_T5CON_T5UDE_Pos            (8UL)                     /*!< GPT12E T5CON: T5UDE (Bit 8)                           */
#define GPT12E_T5CON_T5UDE_Msk            (0x100UL)                 /*!< GPT12E T5CON: T5UDE (Bitfield-Mask: 0x01)             */
#define GPT12E_T5CON_T5UD_Pos             (7UL)                     /*!< GPT12E T5CON: T5UD (Bit 7)                            */
#define GPT12E_T5CON_T5UD_Msk             (0x80UL)                  /*!< GPT12E T5CON: T5UD (Bitfield-Mask: 0x01)              */
#define GPT12E_T5CON_T5R_Pos              (6UL)                     /*!< GPT12E T5CON: T5R (Bit 6)                             */
#define GPT12E_T5CON_T5R_Msk              (0x40UL)                  /*!< GPT12E T5CON: T5R (Bitfield-Mask: 0x01)               */
#define GPT12E_T5CON_T5M_Pos              (3UL)                     /*!< GPT12E T5CON: T5M (Bit 3)                             */
#define GPT12E_T5CON_T5M_Msk              (0x18UL)                  /*!< GPT12E T5CON: T5M (Bitfield-Mask: 0x03)               */
#define GPT12E_T5CON_T5I_Pos              (0UL)                     /*!< GPT12E T5CON: T5I (Bit 0)                             */
#define GPT12E_T5CON_T5I_Msk              (0x7UL)                   /*!< GPT12E T5CON: T5I (Bitfield-Mask: 0x07)               */
/* =========================================================  PISEL  ========================================================= */
#define GPT12E_PISEL_ISCAPIN_Pos          (14UL)                    /*!< GPT12E PISEL: ISCAPIN (Bit 14)                        */
#define GPT12E_PISEL_ISCAPIN_Msk          (0xc000UL)                /*!< GPT12E PISEL: ISCAPIN (Bitfield-Mask: 0x03)           */
#define GPT12E_PISEL_IST6EUD_Pos          (13UL)                    /*!< GPT12E PISEL: IST6EUD (Bit 13)                        */
#define GPT12E_PISEL_IST6EUD_Msk          (0x2000UL)                /*!< GPT12E PISEL: IST6EUD (Bitfield-Mask: 0x01)           */
#define GPT12E_PISEL_IST6IN_Pos           (12UL)                    /*!< GPT12E PISEL: IST6IN (Bit 12)                         */
#define GPT12E_PISEL_IST6IN_Msk           (0x1000UL)                /*!< GPT12E PISEL: IST6IN (Bitfield-Mask: 0x01)            */
#define GPT12E_PISEL_IST5EUD_Pos          (11UL)                    /*!< GPT12E PISEL: IST5EUD (Bit 11)                        */
#define GPT12E_PISEL_IST5EUD_Msk          (0x800UL)                 /*!< GPT12E PISEL: IST5EUD (Bitfield-Mask: 0x01)           */
#define GPT12E_PISEL_IST5IN_Pos           (10UL)                    /*!< GPT12E PISEL: IST5IN (Bit 10)                         */
#define GPT12E_PISEL_IST5IN_Msk           (0x400UL)                 /*!< GPT12E PISEL: IST5IN (Bitfield-Mask: 0x01)            */
#define GPT12E_PISEL_IST4EUD_Pos          (8UL)                     /*!< GPT12E PISEL: IST4EUD (Bit 8)                         */
#define GPT12E_PISEL_IST4EUD_Msk          (0x300UL)                 /*!< GPT12E PISEL: IST4EUD (Bitfield-Mask: 0x03)           */
#define GPT12E_PISEL_IST4IN_Pos           (6UL)                     /*!< GPT12E PISEL: IST4IN (Bit 6)                          */
#define GPT12E_PISEL_IST4IN_Msk           (0xc0UL)                  /*!< GPT12E PISEL: IST4IN (Bitfield-Mask: 0x03)            */
#define GPT12E_PISEL_IST3EUD_Pos          (4UL)                     /*!< GPT12E PISEL: IST3EUD (Bit 4)                         */
#define GPT12E_PISEL_IST3EUD_Msk          (0x30UL)                  /*!< GPT12E PISEL: IST3EUD (Bitfield-Mask: 0x03)           */
#define GPT12E_PISEL_IST3IN_Pos           (2UL)                     /*!< GPT12E PISEL: IST3IN (Bit 2)                          */
#define GPT12E_PISEL_IST3IN_Msk           (0xcUL)                   /*!< GPT12E PISEL: IST3IN (Bitfield-Mask: 0x03)            */
#define GPT12E_PISEL_IST2EUD_Pos          (1UL)                     /*!< GPT12E PISEL: IST2EUD (Bit 1)                         */
#define GPT12E_PISEL_IST2EUD_Msk          (0x2UL)                   /*!< GPT12E PISEL: IST2EUD (Bitfield-Mask: 0x01)           */
#define GPT12E_PISEL_IST2IN_Pos           (0UL)                     /*!< GPT12E PISEL: IST2IN (Bit 0)                          */
#define GPT12E_PISEL_IST2IN_Msk           (0x1UL)                   /*!< GPT12E PISEL: IST2IN (Bitfield-Mask: 0x01)            */
/* ==========================================================  ID  =========================================================== */
#define GPT12E_ID_MOD_TYPE_Pos            (8UL)                     /*!< GPT12E ID: MOD_TYPE (Bit 8)                           */
#define GPT12E_ID_MOD_TYPE_Msk            (0xff00UL)                /*!< GPT12E ID: MOD_TYPE (Bitfield-Mask: 0xff)             */
#define GPT12E_ID_MOD_REV_Pos             (0UL)                     /*!< GPT12E ID: MOD_REV (Bit 0)                            */
#define GPT12E_ID_MOD_REV_Msk             (0xffUL)                  /*!< GPT12E ID: MOD_REV (Bitfield-Mask: 0xff)              */


/* =========================================================================================================================== */
/* ================                                            HS                                             ================ */
/* =========================================================================================================================== */

/* =========================================================  CTRL  ========================================================== */
#define HS_CTRL_HS2_OC_SEL_Pos            (28UL)                    /*!< HS CTRL: HS2_OC_SEL (Bit 28)                          */
#define HS_CTRL_HS2_OC_SEL_Msk            (0x30000000UL)            /*!< HS CTRL: HS2_OC_SEL (Bitfield-Mask: 0x03)             */
#define HS_CTRL_HS2_SRCTL_SEL_Pos         (24UL)                    /*!< HS CTRL: HS2_SRCTL_SEL (Bit 24)                       */
#define HS_CTRL_HS2_SRCTL_SEL_Msk         (0x1000000UL)             /*!< HS CTRL: HS2_SRCTL_SEL (Bitfield-Mask: 0x01)          */
#define HS_CTRL_HS2_CYC_ON_ACTIVE_Pos     (23UL)                    /*!< HS CTRL: HS2_CYC_ON_ACTIVE (Bit 23)                   */
#define HS_CTRL_HS2_CYC_ON_ACTIVE_Msk     (0x800000UL)              /*!< HS CTRL: HS2_CYC_ON_ACTIVE (Bitfield-Mask: 0x01)      */
#define HS_CTRL_HS2_OL_EN_Pos             (19UL)                    /*!< HS CTRL: HS2_OL_EN (Bit 19)                           */
#define HS_CTRL_HS2_OL_EN_Msk             (0x80000UL)               /*!< HS CTRL: HS2_OL_EN (Bitfield-Mask: 0x01)              */
#define HS_CTRL_HS2_ON_Pos                (18UL)                    /*!< HS CTRL: HS2_ON (Bit 18)                              */
#define HS_CTRL_HS2_ON_Msk                (0x40000UL)               /*!< HS CTRL: HS2_ON (Bitfield-Mask: 0x01)                 */
#define HS_CTRL_HS2_PWM_Pos               (17UL)                    /*!< HS CTRL: HS2_PWM (Bit 17)                             */
#define HS_CTRL_HS2_PWM_Msk               (0x20000UL)               /*!< HS CTRL: HS2_PWM (Bitfield-Mask: 0x01)                */
#define HS_CTRL_HS2_EN_Pos                (16UL)                    /*!< HS CTRL: HS2_EN (Bit 16)                              */
#define HS_CTRL_HS2_EN_Msk                (0x10000UL)               /*!< HS CTRL: HS2_EN (Bitfield-Mask: 0x01)                 */
#define HS_CTRL_HS1_OC_SEL_Pos            (12UL)                    /*!< HS CTRL: HS1_OC_SEL (Bit 12)                          */
#define HS_CTRL_HS1_OC_SEL_Msk            (0x3000UL)                /*!< HS CTRL: HS1_OC_SEL (Bitfield-Mask: 0x03)             */
#define HS_CTRL_HS1_SRCTL_SEL_Pos         (8UL)                     /*!< HS CTRL: HS1_SRCTL_SEL (Bit 8)                        */
#define HS_CTRL_HS1_SRCTL_SEL_Msk         (0x100UL)                 /*!< HS CTRL: HS1_SRCTL_SEL (Bitfield-Mask: 0x01)          */
#define HS_CTRL_HS1_CYC_ON_ACTIVE_Pos     (7UL)                     /*!< HS CTRL: HS1_CYC_ON_ACTIVE (Bit 7)                    */
#define HS_CTRL_HS1_CYC_ON_ACTIVE_Msk     (0x80UL)                  /*!< HS CTRL: HS1_CYC_ON_ACTIVE (Bitfield-Mask: 0x01)      */
#define HS_CTRL_HS1_OL_EN_Pos             (3UL)                     /*!< HS CTRL: HS1_OL_EN (Bit 3)                            */
#define HS_CTRL_HS1_OL_EN_Msk             (0x8UL)                   /*!< HS CTRL: HS1_OL_EN (Bitfield-Mask: 0x01)              */
#define HS_CTRL_HS1_ON_Pos                (2UL)                     /*!< HS CTRL: HS1_ON (Bit 2)                               */
#define HS_CTRL_HS1_ON_Msk                (0x4UL)                   /*!< HS CTRL: HS1_ON (Bitfield-Mask: 0x01)                 */
#define HS_CTRL_HS1_PWM_Pos               (1UL)                     /*!< HS CTRL: HS1_PWM (Bit 1)                              */
#define HS_CTRL_HS1_PWM_Msk               (0x2UL)                   /*!< HS CTRL: HS1_PWM (Bitfield-Mask: 0x01)                */
#define HS_CTRL_HS1_EN_Pos                (0UL)                     /*!< HS CTRL: HS1_EN (Bit 0)                               */
#define HS_CTRL_HS1_EN_Msk                (0x1UL)                   /*!< HS CTRL: HS1_EN (Bitfield-Mask: 0x01)                 */
/* =========================================================  IRQS  ========================================================== */
#define HS_IRQS_HS2_OL_STS_Pos            (30UL)                    /*!< HS IRQS: HS2_OL_STS (Bit 30)                          */
#define HS_IRQS_HS2_OL_STS_Msk            (0x40000000UL)            /*!< HS IRQS: HS2_OL_STS (Bitfield-Mask: 0x01)             */
#define HS_IRQS_HS2_OT_STS_Pos            (29UL)                    /*!< HS IRQS: HS2_OT_STS (Bit 29)                          */
#define HS_IRQS_HS2_OT_STS_Msk            (0x20000000UL)            /*!< HS IRQS: HS2_OT_STS (Bitfield-Mask: 0x01)             */
#define HS_IRQS_HS2_OC_IS_Pos             (23UL)                    /*!< HS IRQS: HS2_OC_IS (Bit 23)                           */
#define HS_IRQS_HS2_OC_IS_Msk             (0x800000UL)              /*!< HS IRQS: HS2_OC_IS (Bitfield-Mask: 0x01)              */
#define HS_IRQS_HS2_OL_IS_Pos             (22UL)                    /*!< HS IRQS: HS2_OL_IS (Bit 22)                           */
#define HS_IRQS_HS2_OL_IS_Msk             (0x400000UL)              /*!< HS IRQS: HS2_OL_IS (Bitfield-Mask: 0x01)              */
#define HS_IRQS_HS2_OT_IS_Pos             (21UL)                    /*!< HS IRQS: HS2_OT_IS (Bit 21)                           */
#define HS_IRQS_HS2_OT_IS_Msk             (0x200000UL)              /*!< HS IRQS: HS2_OT_IS (Bitfield-Mask: 0x01)              */
#define HS_IRQS_HS1_OL_STS_Pos            (14UL)                    /*!< HS IRQS: HS1_OL_STS (Bit 14)                          */
#define HS_IRQS_HS1_OL_STS_Msk            (0x4000UL)                /*!< HS IRQS: HS1_OL_STS (Bitfield-Mask: 0x01)             */
#define HS_IRQS_HS1_OT_STS_Pos            (13UL)                    /*!< HS IRQS: HS1_OT_STS (Bit 13)                          */
#define HS_IRQS_HS1_OT_STS_Msk            (0x2000UL)                /*!< HS IRQS: HS1_OT_STS (Bitfield-Mask: 0x01)             */
#define HS_IRQS_HS1_OC_IS_Pos             (7UL)                     /*!< HS IRQS: HS1_OC_IS (Bit 7)                            */
#define HS_IRQS_HS1_OC_IS_Msk             (0x80UL)                  /*!< HS IRQS: HS1_OC_IS (Bitfield-Mask: 0x01)              */
#define HS_IRQS_HS1_OL_IS_Pos             (6UL)                     /*!< HS IRQS: HS1_OL_IS (Bit 6)                            */
#define HS_IRQS_HS1_OL_IS_Msk             (0x40UL)                  /*!< HS IRQS: HS1_OL_IS (Bitfield-Mask: 0x01)              */
#define HS_IRQS_HS1_OT_IS_Pos             (5UL)                     /*!< HS IRQS: HS1_OT_IS (Bit 5)                            */
#define HS_IRQS_HS1_OT_IS_Msk             (0x20UL)                  /*!< HS IRQS: HS1_OT_IS (Bitfield-Mask: 0x01)              */
/* ========================================================  IRQCLR  ========================================================= */
#define HS_IRQCLR_HS2_OL_SC_Pos           (30UL)                    /*!< HS IRQCLR: HS2_OL_SC (Bit 30)                         */
#define HS_IRQCLR_HS2_OL_SC_Msk           (0x40000000UL)            /*!< HS IRQCLR: HS2_OL_SC (Bitfield-Mask: 0x01)            */
#define HS_IRQCLR_HS2_OT_SC_Pos           (29UL)                    /*!< HS IRQCLR: HS2_OT_SC (Bit 29)                         */
#define HS_IRQCLR_HS2_OT_SC_Msk           (0x20000000UL)            /*!< HS IRQCLR: HS2_OT_SC (Bitfield-Mask: 0x01)            */
#define HS_IRQCLR_HS2_OC_ISC_Pos          (23UL)                    /*!< HS IRQCLR: HS2_OC_ISC (Bit 23)                        */
#define HS_IRQCLR_HS2_OC_ISC_Msk          (0x800000UL)              /*!< HS IRQCLR: HS2_OC_ISC (Bitfield-Mask: 0x01)           */
#define HS_IRQCLR_HS2_OL_ISC_Pos          (22UL)                    /*!< HS IRQCLR: HS2_OL_ISC (Bit 22)                        */
#define HS_IRQCLR_HS2_OL_ISC_Msk          (0x400000UL)              /*!< HS IRQCLR: HS2_OL_ISC (Bitfield-Mask: 0x01)           */
#define HS_IRQCLR_HS2_OT_ISC_Pos          (21UL)                    /*!< HS IRQCLR: HS2_OT_ISC (Bit 21)                        */
#define HS_IRQCLR_HS2_OT_ISC_Msk          (0x200000UL)              /*!< HS IRQCLR: HS2_OT_ISC (Bitfield-Mask: 0x01)           */
#define HS_IRQCLR_HS1_OL_SC_Pos           (14UL)                    /*!< HS IRQCLR: HS1_OL_SC (Bit 14)                         */
#define HS_IRQCLR_HS1_OL_SC_Msk           (0x4000UL)                /*!< HS IRQCLR: HS1_OL_SC (Bitfield-Mask: 0x01)            */
#define HS_IRQCLR_HS1_OT_SC_Pos           (13UL)                    /*!< HS IRQCLR: HS1_OT_SC (Bit 13)                         */
#define HS_IRQCLR_HS1_OT_SC_Msk           (0x2000UL)                /*!< HS IRQCLR: HS1_OT_SC (Bitfield-Mask: 0x01)            */
#define HS_IRQCLR_HS1_OC_ISC_Pos          (7UL)                     /*!< HS IRQCLR: HS1_OC_ISC (Bit 7)                         */
#define HS_IRQCLR_HS1_OC_ISC_Msk          (0x80UL)                  /*!< HS IRQCLR: HS1_OC_ISC (Bitfield-Mask: 0x01)           */
#define HS_IRQCLR_HS1_OL_ISC_Pos          (6UL)                     /*!< HS IRQCLR: HS1_OL_ISC (Bit 6)                         */
#define HS_IRQCLR_HS1_OL_ISC_Msk          (0x40UL)                  /*!< HS IRQCLR: HS1_OL_ISC (Bitfield-Mask: 0x01)           */
#define HS_IRQCLR_HS1_OT_ISC_Pos          (5UL)                     /*!< HS IRQCLR: HS1_OT_ISC (Bit 5)                         */
#define HS_IRQCLR_HS1_OT_ISC_Msk          (0x20UL)                  /*!< HS IRQCLR: HS1_OT_ISC (Bitfield-Mask: 0x01)           */
/* =========================================================  IRQEN  ========================================================= */
#define HS_IRQEN_HS2_OC_IEN_Pos           (23UL)                    /*!< HS IRQEN: HS2_OC_IEN (Bit 23)                         */
#define HS_IRQEN_HS2_OC_IEN_Msk           (0x800000UL)              /*!< HS IRQEN: HS2_OC_IEN (Bitfield-Mask: 0x01)            */
#define HS_IRQEN_HS2_OL_IEN_Pos           (22UL)                    /*!< HS IRQEN: HS2_OL_IEN (Bit 22)                         */
#define HS_IRQEN_HS2_OL_IEN_Msk           (0x400000UL)              /*!< HS IRQEN: HS2_OL_IEN (Bitfield-Mask: 0x01)            */
#define HS_IRQEN_HS2_OT_IEN_Pos           (21UL)                    /*!< HS IRQEN: HS2_OT_IEN (Bit 21)                         */
#define HS_IRQEN_HS2_OT_IEN_Msk           (0x200000UL)              /*!< HS IRQEN: HS2_OT_IEN (Bitfield-Mask: 0x01)            */
#define HS_IRQEN_HS1_OC_IEN_Pos           (7UL)                     /*!< HS IRQEN: HS1_OC_IEN (Bit 7)                          */
#define HS_IRQEN_HS1_OC_IEN_Msk           (0x80UL)                  /*!< HS IRQEN: HS1_OC_IEN (Bitfield-Mask: 0x01)            */
#define HS_IRQEN_HS1_OL_IEN_Pos           (6UL)                     /*!< HS IRQEN: HS1_OL_IEN (Bit 6)                          */
#define HS_IRQEN_HS1_OL_IEN_Msk           (0x40UL)                  /*!< HS IRQEN: HS1_OL_IEN (Bitfield-Mask: 0x01)            */
#define HS_IRQEN_HS1_OT_IEN_Pos           (5UL)                     /*!< HS IRQEN: HS1_OT_IEN (Bit 5)                          */
#define HS_IRQEN_HS1_OT_IEN_Msk           (0x20UL)                  /*!< HS IRQEN: HS1_OT_IEN (Bitfield-Mask: 0x01)            */
/* =======================================================  PWMSRCSEL  ======================================================= */
#define HS_PWMSRCSEL_HS1_SRC_SEL_Pos      (3UL)                     /*!< HS PWMSRCSEL: HS1_SRC_SEL (Bit 3)                     */
#define HS_PWMSRCSEL_HS1_SRC_SEL_Msk      (0x38UL)                  /*!< HS PWMSRCSEL: HS1_SRC_SEL (Bitfield-Mask: 0x07)       */
#define HS_PWMSRCSEL_HS2_SRC_SEL_Pos      (0UL)                     /*!< HS PWMSRCSEL: HS2_SRC_SEL (Bit 0)                     */
#define HS_PWMSRCSEL_HS2_SRC_SEL_Msk      (0x7UL)                   /*!< HS PWMSRCSEL: HS2_SRC_SEL (Bitfield-Mask: 0x07)       */
/* =======================================================  HS1_TRIM  ======================================================== */
#define HS_HS1_TRIM_HS1_OC_OT_BTFILT_SEL_Pos (8UL)                  /*!< HS HS1_TRIM: HS1_OC_OT_BTFILT_SEL (Bit 8)             */
#define HS_HS1_TRIM_HS1_OC_OT_BTFILT_SEL_Msk (0x300UL)              /*!< HS HS1_TRIM: HS1_OC_OT_BTFILT_SEL (Bitfield-Mask: 0x03) */
#define HS_HS1_TRIM_HS1_OL_BTFILT_SEL_Pos (0UL)                     /*!< HS HS1_TRIM: HS1_OL_BTFILT_SEL (Bit 0)                */
#define HS_HS1_TRIM_HS1_OL_BTFILT_SEL_Msk (0x3UL)                   /*!< HS HS1_TRIM: HS1_OL_BTFILT_SEL (Bitfield-Mask: 0x03)  */
/* =======================================================  HS2_TRIM  ======================================================== */
#define HS_HS2_TRIM_HS2_OC_OT_BTFILT_SEL_Pos (8UL)                  /*!< HS HS2_TRIM: HS2_OC_OT_BTFILT_SEL (Bit 8)             */
#define HS_HS2_TRIM_HS2_OC_OT_BTFILT_SEL_Msk (0x300UL)              /*!< HS HS2_TRIM: HS2_OC_OT_BTFILT_SEL (Bitfield-Mask: 0x03) */
#define HS_HS2_TRIM_HS2_OL_BTFILT_SEL_Pos (0UL)                     /*!< HS HS2_TRIM: HS2_OL_BTFILT_SEL (Bit 0)                */
#define HS_HS2_TRIM_HS2_OL_BTFILT_SEL_Msk (0x3UL)                   /*!< HS HS2_TRIM: HS2_OL_BTFILT_SEL (Bitfield-Mask: 0x03)  */


/* =========================================================================================================================== */
/* ================                                            LIN                                            ================ */
/* =========================================================================================================================== */

/* =========================================================  CTRL  ========================================================== */
#define LIN_CTRL_HV_MODE_Pos              (21UL)                    /*!< LIN CTRL: HV_MODE (Bit 21)                            */
#define LIN_CTRL_HV_MODE_Msk              (0x200000UL)              /*!< LIN CTRL: HV_MODE (Bitfield-Mask: 0x01)               */
#define LIN_CTRL_FB_SM3_Pos               (15UL)                    /*!< LIN CTRL: FB_SM3 (Bit 15)                             */
#define LIN_CTRL_FB_SM3_Msk               (0x8000UL)                /*!< LIN CTRL: FB_SM3 (Bitfield-Mask: 0x01)                */
#define LIN_CTRL_FB_SM2_Pos               (14UL)                    /*!< LIN CTRL: FB_SM2 (Bit 14)                             */
#define LIN_CTRL_FB_SM2_Msk               (0x4000UL)                /*!< LIN CTRL: FB_SM2 (Bitfield-Mask: 0x01)                */
#define LIN_CTRL_FB_SM1_Pos               (13UL)                    /*!< LIN CTRL: FB_SM1 (Bit 13)                             */
#define LIN_CTRL_FB_SM1_Msk               (0x2000UL)                /*!< LIN CTRL: FB_SM1 (Bitfield-Mask: 0x01)                */
#define LIN_CTRL_SM_Pos                   (11UL)                    /*!< LIN CTRL: SM (Bit 11)                                 */
#define LIN_CTRL_SM_Msk                   (0x1800UL)                /*!< LIN CTRL: SM (Bitfield-Mask: 0x03)                    */
#define LIN_CTRL_RXD_Pos                  (10UL)                    /*!< LIN CTRL: RXD (Bit 10)                                */
#define LIN_CTRL_RXD_Msk                  (0x400UL)                 /*!< LIN CTRL: RXD (Bitfield-Mask: 0x01)                   */
#define LIN_CTRL_TXD_Pos                  (9UL)                     /*!< LIN CTRL: TXD (Bit 9)                                 */
#define LIN_CTRL_TXD_Msk                  (0x200UL)                 /*!< LIN CTRL: TXD (Bitfield-Mask: 0x01)                   */
#define LIN_CTRL_MODE_FB_Pos              (4UL)                     /*!< LIN CTRL: MODE_FB (Bit 4)                             */
#define LIN_CTRL_MODE_FB_Msk              (0x70UL)                  /*!< LIN CTRL: MODE_FB (Bitfield-Mask: 0x07)               */
#define LIN_CTRL_MODE_Pos                 (1UL)                     /*!< LIN CTRL: MODE (Bit 1)                                */
#define LIN_CTRL_MODE_Msk                 (0x6UL)                   /*!< LIN CTRL: MODE (Bitfield-Mask: 0x03)                  */
/* =========================================================  IRQS  ========================================================== */
#define LIN_IRQS_TXD_TMOUT_STS_Pos        (11UL)                    /*!< LIN IRQS: TXD_TMOUT_STS (Bit 11)                      */
#define LIN_IRQS_TXD_TMOUT_STS_Msk        (0x800UL)                 /*!< LIN IRQS: TXD_TMOUT_STS (Bitfield-Mask: 0x01)         */
#define LIN_IRQS_OT_STS_Pos               (9UL)                     /*!< LIN IRQS: OT_STS (Bit 9)                              */
#define LIN_IRQS_OT_STS_Msk               (0x200UL)                 /*!< LIN IRQS: OT_STS (Bitfield-Mask: 0x01)                */
#define LIN_IRQS_M_SM_ERR_STS_Pos         (8UL)                     /*!< LIN IRQS: M_SM_ERR_STS (Bit 8)                        */
#define LIN_IRQS_M_SM_ERR_STS_Msk         (0x100UL)                 /*!< LIN IRQS: M_SM_ERR_STS (Bitfield-Mask: 0x01)          */
#define LIN_IRQS_TXD_TMOUT_IS_Pos         (6UL)                     /*!< LIN IRQS: TXD_TMOUT_IS (Bit 6)                        */
#define LIN_IRQS_TXD_TMOUT_IS_Msk         (0x40UL)                  /*!< LIN IRQS: TXD_TMOUT_IS (Bitfield-Mask: 0x01)          */
#define LIN_IRQS_OC_IS_Pos                (5UL)                     /*!< LIN IRQS: OC_IS (Bit 5)                               */
#define LIN_IRQS_OC_IS_Msk                (0x20UL)                  /*!< LIN IRQS: OC_IS (Bitfield-Mask: 0x01)                 */
#define LIN_IRQS_OT_IS_Pos                (4UL)                     /*!< LIN IRQS: OT_IS (Bit 4)                               */
#define LIN_IRQS_OT_IS_Msk                (0x10UL)                  /*!< LIN IRQS: OT_IS (Bitfield-Mask: 0x01)                 */
#define LIN_IRQS_M_SM_ERR_IS_Pos          (3UL)                     /*!< LIN IRQS: M_SM_ERR_IS (Bit 3)                         */
#define LIN_IRQS_M_SM_ERR_IS_Msk          (0x8UL)                   /*!< LIN IRQS: M_SM_ERR_IS (Bitfield-Mask: 0x01)           */
/* ========================================================  IRQCLR  ========================================================= */
#define LIN_IRQCLR_TXD_TMOUT_SC_Pos       (11UL)                    /*!< LIN IRQCLR: TXD_TMOUT_SC (Bit 11)                     */
#define LIN_IRQCLR_TXD_TMOUT_SC_Msk       (0x800UL)                 /*!< LIN IRQCLR: TXD_TMOUT_SC (Bitfield-Mask: 0x01)        */
#define LIN_IRQCLR_OT_SC_Pos              (9UL)                     /*!< LIN IRQCLR: OT_SC (Bit 9)                             */
#define LIN_IRQCLR_OT_SC_Msk              (0x200UL)                 /*!< LIN IRQCLR: OT_SC (Bitfield-Mask: 0x01)               */
#define LIN_IRQCLR_M_SM_ERR_SC_Pos        (8UL)                     /*!< LIN IRQCLR: M_SM_ERR_SC (Bit 8)                       */
#define LIN_IRQCLR_M_SM_ERR_SC_Msk        (0x100UL)                 /*!< LIN IRQCLR: M_SM_ERR_SC (Bitfield-Mask: 0x01)         */
#define LIN_IRQCLR_TXD_TMOUT_ISC_Pos      (6UL)                     /*!< LIN IRQCLR: TXD_TMOUT_ISC (Bit 6)                     */
#define LIN_IRQCLR_TXD_TMOUT_ISC_Msk      (0x40UL)                  /*!< LIN IRQCLR: TXD_TMOUT_ISC (Bitfield-Mask: 0x01)       */
#define LIN_IRQCLR_OC_ISC_Pos             (5UL)                     /*!< LIN IRQCLR: OC_ISC (Bit 5)                            */
#define LIN_IRQCLR_OC_ISC_Msk             (0x20UL)                  /*!< LIN IRQCLR: OC_ISC (Bitfield-Mask: 0x01)              */
#define LIN_IRQCLR_OT_ISC_Pos             (4UL)                     /*!< LIN IRQCLR: OT_ISC (Bit 4)                            */
#define LIN_IRQCLR_OT_ISC_Msk             (0x10UL)                  /*!< LIN IRQCLR: OT_ISC (Bitfield-Mask: 0x01)              */
#define LIN_IRQCLR_M_SM_ERR_ISC_Pos       (3UL)                     /*!< LIN IRQCLR: M_SM_ERR_ISC (Bit 3)                      */
#define LIN_IRQCLR_M_SM_ERR_ISC_Msk       (0x8UL)                   /*!< LIN IRQCLR: M_SM_ERR_ISC (Bitfield-Mask: 0x01)        */
/* =========================================================  IRQEN  ========================================================= */
#define LIN_IRQEN_TXD_TMOUT_IEN_Pos       (6UL)                     /*!< LIN IRQEN: TXD_TMOUT_IEN (Bit 6)                      */
#define LIN_IRQEN_TXD_TMOUT_IEN_Msk       (0x40UL)                  /*!< LIN IRQEN: TXD_TMOUT_IEN (Bitfield-Mask: 0x01)        */
#define LIN_IRQEN_OC_IEN_Pos              (5UL)                     /*!< LIN IRQEN: OC_IEN (Bit 5)                             */
#define LIN_IRQEN_OC_IEN_Msk              (0x20UL)                  /*!< LIN IRQEN: OC_IEN (Bitfield-Mask: 0x01)               */
#define LIN_IRQEN_OT_IEN_Pos              (4UL)                     /*!< LIN IRQEN: OT_IEN (Bit 4)                             */
#define LIN_IRQEN_OT_IEN_Msk              (0x10UL)                  /*!< LIN IRQEN: OT_IEN (Bitfield-Mask: 0x01)               */
#define LIN_IRQEN_M_SM_ERR_IEN_Pos        (3UL)                     /*!< LIN IRQEN: M_SM_ERR_IEN (Bit 3)                       */
#define LIN_IRQEN_M_SM_ERR_IEN_Msk        (0x8UL)                   /*!< LIN IRQEN: M_SM_ERR_IEN (Bitfield-Mask: 0x01)         */


/* =========================================================================================================================== */
/* ================                                            LS                                             ================ */
/* =========================================================================================================================== */

/* =========================================================  CTRL  ========================================================== */
#define LS_CTRL_LS2_SRCTL_SEL_Pos         (24UL)                    /*!< LS CTRL: LS2_SRCTL_SEL (Bit 24)                       */
#define LS_CTRL_LS2_SRCTL_SEL_Msk         (0x1000000UL)             /*!< LS CTRL: LS2_SRCTL_SEL (Bitfield-Mask: 0x01)          */
#define LS_CTRL_LS2_OL_EN_Pos             (19UL)                    /*!< LS CTRL: LS2_OL_EN (Bit 19)                           */
#define LS_CTRL_LS2_OL_EN_Msk             (0x80000UL)               /*!< LS CTRL: LS2_OL_EN (Bitfield-Mask: 0x01)              */
#define LS_CTRL_LS2_ON_Pos                (18UL)                    /*!< LS CTRL: LS2_ON (Bit 18)                              */
#define LS_CTRL_LS2_ON_Msk                (0x40000UL)               /*!< LS CTRL: LS2_ON (Bitfield-Mask: 0x01)                 */
#define LS_CTRL_LS2_PWM_Pos               (17UL)                    /*!< LS CTRL: LS2_PWM (Bit 17)                             */
#define LS_CTRL_LS2_PWM_Msk               (0x20000UL)               /*!< LS CTRL: LS2_PWM (Bitfield-Mask: 0x01)                */
#define LS_CTRL_LS2_EN_Pos                (16UL)                    /*!< LS CTRL: LS2_EN (Bit 16)                              */
#define LS_CTRL_LS2_EN_Msk                (0x10000UL)               /*!< LS CTRL: LS2_EN (Bitfield-Mask: 0x01)                 */
#define LS_CTRL_LS1_SRCTL_SEL_Pos         (8UL)                     /*!< LS CTRL: LS1_SRCTL_SEL (Bit 8)                        */
#define LS_CTRL_LS1_SRCTL_SEL_Msk         (0x100UL)                 /*!< LS CTRL: LS1_SRCTL_SEL (Bitfield-Mask: 0x01)          */
#define LS_CTRL_LS1_OL_EN_Pos             (3UL)                     /*!< LS CTRL: LS1_OL_EN (Bit 3)                            */
#define LS_CTRL_LS1_OL_EN_Msk             (0x8UL)                   /*!< LS CTRL: LS1_OL_EN (Bitfield-Mask: 0x01)              */
#define LS_CTRL_LS1_ON_Pos                (2UL)                     /*!< LS CTRL: LS1_ON (Bit 2)                               */
#define LS_CTRL_LS1_ON_Msk                (0x4UL)                   /*!< LS CTRL: LS1_ON (Bitfield-Mask: 0x01)                 */
#define LS_CTRL_LS1_PWM_Pos               (1UL)                     /*!< LS CTRL: LS1_PWM (Bit 1)                              */
#define LS_CTRL_LS1_PWM_Msk               (0x2UL)                   /*!< LS CTRL: LS1_PWM (Bitfield-Mask: 0x01)                */
#define LS_CTRL_LS1_EN_Pos                (0UL)                     /*!< LS CTRL: LS1_EN (Bit 0)                               */
#define LS_CTRL_LS1_EN_Msk                (0x1UL)                   /*!< LS CTRL: LS1_EN (Bitfield-Mask: 0x01)                 */
/* =========================================================  IRQS  ========================================================== */
#define LS_IRQS_LS2_OL_STS_Pos            (30UL)                    /*!< LS IRQS: LS2_OL_STS (Bit 30)                          */
#define LS_IRQS_LS2_OL_STS_Msk            (0x40000000UL)            /*!< LS IRQS: LS2_OL_STS (Bitfield-Mask: 0x01)             */
#define LS_IRQS_LS2_OT_STS_Pos            (29UL)                    /*!< LS IRQS: LS2_OT_STS (Bit 29)                          */
#define LS_IRQS_LS2_OT_STS_Msk            (0x20000000UL)            /*!< LS IRQS: LS2_OT_STS (Bitfield-Mask: 0x01)             */
#define LS_IRQS_LS2_OT_PREWARN_STS_Pos    (28UL)                    /*!< LS IRQS: LS2_OT_PREWARN_STS (Bit 28)                  */
#define LS_IRQS_LS2_OT_PREWARN_STS_Msk    (0x10000000UL)            /*!< LS IRQS: LS2_OT_PREWARN_STS (Bitfield-Mask: 0x01)     */
#define LS_IRQS_LS2_OC_IS_Pos             (23UL)                    /*!< LS IRQS: LS2_OC_IS (Bit 23)                           */
#define LS_IRQS_LS2_OC_IS_Msk             (0x800000UL)              /*!< LS IRQS: LS2_OC_IS (Bitfield-Mask: 0x01)              */
#define LS_IRQS_LS2_OL_IS_Pos             (22UL)                    /*!< LS IRQS: LS2_OL_IS (Bit 22)                           */
#define LS_IRQS_LS2_OL_IS_Msk             (0x400000UL)              /*!< LS IRQS: LS2_OL_IS (Bitfield-Mask: 0x01)              */
#define LS_IRQS_LS2_OT_IS_Pos             (21UL)                    /*!< LS IRQS: LS2_OT_IS (Bit 21)                           */
#define LS_IRQS_LS2_OT_IS_Msk             (0x200000UL)              /*!< LS IRQS: LS2_OT_IS (Bitfield-Mask: 0x01)              */
#define LS_IRQS_LS2_OT_PREWARN_IS_Pos     (20UL)                    /*!< LS IRQS: LS2_OT_PREWARN_IS (Bit 20)                   */
#define LS_IRQS_LS2_OT_PREWARN_IS_Msk     (0x100000UL)              /*!< LS IRQS: LS2_OT_PREWARN_IS (Bitfield-Mask: 0x01)      */
#define LS_IRQS_LS1_OL_STS_Pos            (14UL)                    /*!< LS IRQS: LS1_OL_STS (Bit 14)                          */
#define LS_IRQS_LS1_OL_STS_Msk            (0x4000UL)                /*!< LS IRQS: LS1_OL_STS (Bitfield-Mask: 0x01)             */
#define LS_IRQS_LS1_OT_STS_Pos            (13UL)                    /*!< LS IRQS: LS1_OT_STS (Bit 13)                          */
#define LS_IRQS_LS1_OT_STS_Msk            (0x2000UL)                /*!< LS IRQS: LS1_OT_STS (Bitfield-Mask: 0x01)             */
#define LS_IRQS_LS1_OT_PREWARN_STS_Pos    (12UL)                    /*!< LS IRQS: LS1_OT_PREWARN_STS (Bit 12)                  */
#define LS_IRQS_LS1_OT_PREWARN_STS_Msk    (0x1000UL)                /*!< LS IRQS: LS1_OT_PREWARN_STS (Bitfield-Mask: 0x01)     */
#define LS_IRQS_LS1_OC_IS_Pos             (7UL)                     /*!< LS IRQS: LS1_OC_IS (Bit 7)                            */
#define LS_IRQS_LS1_OC_IS_Msk             (0x80UL)                  /*!< LS IRQS: LS1_OC_IS (Bitfield-Mask: 0x01)              */
#define LS_IRQS_LS1_OL_IS_Pos             (6UL)                     /*!< LS IRQS: LS1_OL_IS (Bit 6)                            */
#define LS_IRQS_LS1_OL_IS_Msk             (0x40UL)                  /*!< LS IRQS: LS1_OL_IS (Bitfield-Mask: 0x01)              */
#define LS_IRQS_LS1_OT_IS_Pos             (5UL)                     /*!< LS IRQS: LS1_OT_IS (Bit 5)                            */
#define LS_IRQS_LS1_OT_IS_Msk             (0x20UL)                  /*!< LS IRQS: LS1_OT_IS (Bitfield-Mask: 0x01)              */
#define LS_IRQS_LS1_OT_PREWARN_IS_Pos     (4UL)                     /*!< LS IRQS: LS1_OT_PREWARN_IS (Bit 4)                    */
#define LS_IRQS_LS1_OT_PREWARN_IS_Msk     (0x10UL)                  /*!< LS IRQS: LS1_OT_PREWARN_IS (Bitfield-Mask: 0x01)      */
/* ========================================================  IRQCLR  ========================================================= */
#define LS_IRQCLR_LS2_OL_SC_Pos           (30UL)                    /*!< LS IRQCLR: LS2_OL_SC (Bit 30)                         */
#define LS_IRQCLR_LS2_OL_SC_Msk           (0x40000000UL)            /*!< LS IRQCLR: LS2_OL_SC (Bitfield-Mask: 0x01)            */
#define LS_IRQCLR_LS2_OT_SC_Pos           (29UL)                    /*!< LS IRQCLR: LS2_OT_SC (Bit 29)                         */
#define LS_IRQCLR_LS2_OT_SC_Msk           (0x20000000UL)            /*!< LS IRQCLR: LS2_OT_SC (Bitfield-Mask: 0x01)            */
#define LS_IRQCLR_LS2_OT_PREWARN_SC_Pos   (28UL)                    /*!< LS IRQCLR: LS2_OT_PREWARN_SC (Bit 28)                 */
#define LS_IRQCLR_LS2_OT_PREWARN_SC_Msk   (0x10000000UL)            /*!< LS IRQCLR: LS2_OT_PREWARN_SC (Bitfield-Mask: 0x01)    */
#define LS_IRQCLR_LS2_OC_ISC_Pos          (23UL)                    /*!< LS IRQCLR: LS2_OC_ISC (Bit 23)                        */
#define LS_IRQCLR_LS2_OC_ISC_Msk          (0x800000UL)              /*!< LS IRQCLR: LS2_OC_ISC (Bitfield-Mask: 0x01)           */
#define LS_IRQCLR_LS2_OL_ISC_Pos          (22UL)                    /*!< LS IRQCLR: LS2_OL_ISC (Bit 22)                        */
#define LS_IRQCLR_LS2_OL_ISC_Msk          (0x400000UL)              /*!< LS IRQCLR: LS2_OL_ISC (Bitfield-Mask: 0x01)           */
#define LS_IRQCLR_LS2_OT_ISC_Pos          (21UL)                    /*!< LS IRQCLR: LS2_OT_ISC (Bit 21)                        */
#define LS_IRQCLR_LS2_OT_ISC_Msk          (0x200000UL)              /*!< LS IRQCLR: LS2_OT_ISC (Bitfield-Mask: 0x01)           */
#define LS_IRQCLR_LS2_OT_PREWARN_ISC_Pos  (20UL)                    /*!< LS IRQCLR: LS2_OT_PREWARN_ISC (Bit 20)                */
#define LS_IRQCLR_LS2_OT_PREWARN_ISC_Msk  (0x100000UL)              /*!< LS IRQCLR: LS2_OT_PREWARN_ISC (Bitfield-Mask: 0x01)   */
#define LS_IRQCLR_LS1_OL_SC_Pos           (14UL)                    /*!< LS IRQCLR: LS1_OL_SC (Bit 14)                         */
#define LS_IRQCLR_LS1_OL_SC_Msk           (0x4000UL)                /*!< LS IRQCLR: LS1_OL_SC (Bitfield-Mask: 0x01)            */
#define LS_IRQCLR_LS1_OT_SC_Pos           (13UL)                    /*!< LS IRQCLR: LS1_OT_SC (Bit 13)                         */
#define LS_IRQCLR_LS1_OT_SC_Msk           (0x2000UL)                /*!< LS IRQCLR: LS1_OT_SC (Bitfield-Mask: 0x01)            */
#define LS_IRQCLR_LS1_OT_PREWARN_SC_Pos   (12UL)                    /*!< LS IRQCLR: LS1_OT_PREWARN_SC (Bit 12)                 */
#define LS_IRQCLR_LS1_OT_PREWARN_SC_Msk   (0x1000UL)                /*!< LS IRQCLR: LS1_OT_PREWARN_SC (Bitfield-Mask: 0x01)    */
#define LS_IRQCLR_LS1_OC_ISC_Pos          (7UL)                     /*!< LS IRQCLR: LS1_OC_ISC (Bit 7)                         */
#define LS_IRQCLR_LS1_OC_ISC_Msk          (0x80UL)                  /*!< LS IRQCLR: LS1_OC_ISC (Bitfield-Mask: 0x01)           */
#define LS_IRQCLR_LS1_OL_ISC_Pos          (6UL)                     /*!< LS IRQCLR: LS1_OL_ISC (Bit 6)                         */
#define LS_IRQCLR_LS1_OL_ISC_Msk          (0x40UL)                  /*!< LS IRQCLR: LS1_OL_ISC (Bitfield-Mask: 0x01)           */
#define LS_IRQCLR_LS1_OT_ISC_Pos          (5UL)                     /*!< LS IRQCLR: LS1_OT_ISC (Bit 5)                         */
#define LS_IRQCLR_LS1_OT_ISC_Msk          (0x20UL)                  /*!< LS IRQCLR: LS1_OT_ISC (Bitfield-Mask: 0x01)           */
#define LS_IRQCLR_LS1_OT_PREWARN_ISC_Pos  (4UL)                     /*!< LS IRQCLR: LS1_OT_PREWARN_ISC (Bit 4)                 */
#define LS_IRQCLR_LS1_OT_PREWARN_ISC_Msk  (0x10UL)                  /*!< LS IRQCLR: LS1_OT_PREWARN_ISC (Bitfield-Mask: 0x01)   */
/* =========================================================  IRQEN  ========================================================= */
#define LS_IRQEN_LS2_OC_IEN_Pos           (23UL)                    /*!< LS IRQEN: LS2_OC_IEN (Bit 23)                         */
#define LS_IRQEN_LS2_OC_IEN_Msk           (0x800000UL)              /*!< LS IRQEN: LS2_OC_IEN (Bitfield-Mask: 0x01)            */
#define LS_IRQEN_LS2_OL_IEN_Pos           (22UL)                    /*!< LS IRQEN: LS2_OL_IEN (Bit 22)                         */
#define LS_IRQEN_LS2_OL_IEN_Msk           (0x400000UL)              /*!< LS IRQEN: LS2_OL_IEN (Bitfield-Mask: 0x01)            */
#define LS_IRQEN_LS2_OT_IEN_Pos           (21UL)                    /*!< LS IRQEN: LS2_OT_IEN (Bit 21)                         */
#define LS_IRQEN_LS2_OT_IEN_Msk           (0x200000UL)              /*!< LS IRQEN: LS2_OT_IEN (Bitfield-Mask: 0x01)            */
#define LS_IRQEN_LS2_OT_PREWARN_IEN_Pos   (20UL)                    /*!< LS IRQEN: LS2_OT_PREWARN_IEN (Bit 20)                 */
#define LS_IRQEN_LS2_OT_PREWARN_IEN_Msk   (0x100000UL)              /*!< LS IRQEN: LS2_OT_PREWARN_IEN (Bitfield-Mask: 0x01)    */
#define LS_IRQEN_LS1_OC_IEN_Pos           (7UL)                     /*!< LS IRQEN: LS1_OC_IEN (Bit 7)                          */
#define LS_IRQEN_LS1_OC_IEN_Msk           (0x80UL)                  /*!< LS IRQEN: LS1_OC_IEN (Bitfield-Mask: 0x01)            */
#define LS_IRQEN_LS1_OL_IEN_Pos           (6UL)                     /*!< LS IRQEN: LS1_OL_IEN (Bit 6)                          */
#define LS_IRQEN_LS1_OL_IEN_Msk           (0x40UL)                  /*!< LS IRQEN: LS1_OL_IEN (Bitfield-Mask: 0x01)            */
#define LS_IRQEN_LS1_OT_IEN_Pos           (5UL)                     /*!< LS IRQEN: LS1_OT_IEN (Bit 5)                          */
#define LS_IRQEN_LS1_OT_IEN_Msk           (0x20UL)                  /*!< LS IRQEN: LS1_OT_IEN (Bitfield-Mask: 0x01)            */
#define LS_IRQEN_LS1_OT_PREWARN_IEN_Pos   (4UL)                     /*!< LS IRQEN: LS1_OT_PREWARN_IEN (Bit 4)                  */
#define LS_IRQEN_LS1_OT_PREWARN_IEN_Msk   (0x10UL)                  /*!< LS IRQEN: LS1_OT_PREWARN_IEN (Bitfield-Mask: 0x01)    */
/* =======================================================  PWMSRCSEL  ======================================================= */
#define LS_PWMSRCSEL_LS1_SRC_SEL_Pos      (3UL)                     /*!< LS PWMSRCSEL: LS1_SRC_SEL (Bit 3)                     */
#define LS_PWMSRCSEL_LS1_SRC_SEL_Msk      (0x38UL)                  /*!< LS PWMSRCSEL: LS1_SRC_SEL (Bitfield-Mask: 0x07)       */
#define LS_PWMSRCSEL_LS2_SRC_SEL_Pos      (0UL)                     /*!< LS PWMSRCSEL: LS2_SRC_SEL (Bit 0)                     */
#define LS_PWMSRCSEL_LS2_SRC_SEL_Msk      (0x7UL)                   /*!< LS PWMSRCSEL: LS2_SRC_SEL (Bitfield-Mask: 0x07)       */
/* =======================================================  LS1_TRIM  ======================================================== */
#define LS_LS1_TRIM_LS1_OC_BTFILT_SEL_Pos (8UL)                     /*!< LS LS1_TRIM: LS1_OC_BTFILT_SEL (Bit 8)                */
#define LS_LS1_TRIM_LS1_OC_BTFILT_SEL_Msk (0x300UL)                 /*!< LS LS1_TRIM: LS1_OC_BTFILT_SEL (Bitfield-Mask: 0x03)  */
#define LS_LS1_TRIM_LS1_OL_BTFILT_SEL_Pos (0UL)                     /*!< LS LS1_TRIM: LS1_OL_BTFILT_SEL (Bit 0)                */
#define LS_LS1_TRIM_LS1_OL_BTFILT_SEL_Msk (0x3UL)                   /*!< LS LS1_TRIM: LS1_OL_BTFILT_SEL (Bitfield-Mask: 0x03)  */
/* =======================================================  LS2_TRIM  ======================================================== */
#define LS_LS2_TRIM_LS2_OC_BTFILT_SEL_Pos (8UL)                     /*!< LS LS2_TRIM: LS2_OC_BTFILT_SEL (Bit 8)                */
#define LS_LS2_TRIM_LS2_OC_BTFILT_SEL_Msk (0x300UL)                 /*!< LS LS2_TRIM: LS2_OC_BTFILT_SEL (Bitfield-Mask: 0x03)  */
#define LS_LS2_TRIM_LS2_OL_BTFILT_SEL_Pos (0UL)                     /*!< LS LS2_TRIM: LS2_OL_BTFILT_SEL (Bit 0)                */
#define LS_LS2_TRIM_LS2_OL_BTFILT_SEL_Msk (0x3UL)                   /*!< LS LS2_TRIM: LS2_OL_BTFILT_SEL (Bitfield-Mask: 0x03)  */


/* =========================================================================================================================== */
/* ================                                            MF                                             ================ */
/* =========================================================================================================================== */

/* ====================================================  TEMPSENSE_CTRL  ===================================================== */
#define MF_TEMPSENSE_CTRL_SYS_OT_STS_Pos  (7UL)                     /*!< MF TEMPSENSE_CTRL: SYS_OT_STS (Bit 7)                 */
#define MF_TEMPSENSE_CTRL_SYS_OT_STS_Msk  (0x80UL)                  /*!< MF TEMPSENSE_CTRL: SYS_OT_STS (Bitfield-Mask: 0x01)   */
#define MF_TEMPSENSE_CTRL_SYS_OTWARN_STS_Pos (6UL)                  /*!< MF TEMPSENSE_CTRL: SYS_OTWARN_STS (Bit 6)             */
#define MF_TEMPSENSE_CTRL_SYS_OTWARN_STS_Msk (0x40UL)               /*!< MF TEMPSENSE_CTRL: SYS_OTWARN_STS (Bitfield-Mask: 0x01) */
#define MF_TEMPSENSE_CTRL_LS_OT_STS_Pos   (5UL)                     /*!< MF TEMPSENSE_CTRL: LS_OT_STS (Bit 5)                  */
#define MF_TEMPSENSE_CTRL_LS_OT_STS_Msk   (0x20UL)                  /*!< MF TEMPSENSE_CTRL: LS_OT_STS (Bitfield-Mask: 0x01)    */
#define MF_TEMPSENSE_CTRL_LS_OTWARN_STS_Pos (4UL)                   /*!< MF TEMPSENSE_CTRL: LS_OTWARN_STS (Bit 4)              */
#define MF_TEMPSENSE_CTRL_LS_OTWARN_STS_Msk (0x10UL)                /*!< MF TEMPSENSE_CTRL: LS_OTWARN_STS (Bitfield-Mask: 0x01) */
/* =======================================================  REF1_STS  ======================================================== */
#define MF_REF1_STS_REFBG_UPTHWARN_STS_Pos (5UL)                    /*!< MF REF1_STS: REFBG_UPTHWARN_STS (Bit 5)               */
#define MF_REF1_STS_REFBG_UPTHWARN_STS_Msk (0x20UL)                 /*!< MF REF1_STS: REFBG_UPTHWARN_STS (Bitfield-Mask: 0x01) */
#define MF_REF1_STS_REFBG_LOTHWARN_STS_Pos (4UL)                    /*!< MF REF1_STS: REFBG_LOTHWARN_STS (Bit 4)               */
#define MF_REF1_STS_REFBG_LOTHWARN_STS_Msk (0x10UL)                 /*!< MF REF1_STS: REFBG_LOTHWARN_STS (Bitfield-Mask: 0x01) */


/* =========================================================================================================================== */
/* ================                                            PMU                                            ================ */
/* =========================================================================================================================== */

/* ======================================================  SUPPLY_STS  ======================================================= */
#define PMU_SUPPLY_STS_PMU_5V_FAIL_EN_Pos (6UL)                     /*!< PMU SUPPLY_STS: PMU_5V_FAIL_EN (Bit 6)                */
#define PMU_SUPPLY_STS_PMU_5V_FAIL_EN_Msk (0x40UL)                  /*!< PMU SUPPLY_STS: PMU_5V_FAIL_EN (Bitfield-Mask: 0x01)  */
#define PMU_SUPPLY_STS_PMU_5V_OVERLOAD_Pos (5UL)                    /*!< PMU SUPPLY_STS: PMU_5V_OVERLOAD (Bit 5)               */
#define PMU_SUPPLY_STS_PMU_5V_OVERLOAD_Msk (0x20UL)                 /*!< PMU SUPPLY_STS: PMU_5V_OVERLOAD (Bitfield-Mask: 0x01) */
#define PMU_SUPPLY_STS_PMU_5V_OVERVOLT_Pos (4UL)                    /*!< PMU SUPPLY_STS: PMU_5V_OVERVOLT (Bit 4)               */
#define PMU_SUPPLY_STS_PMU_5V_OVERVOLT_Msk (0x10UL)                 /*!< PMU SUPPLY_STS: PMU_5V_OVERVOLT (Bitfield-Mask: 0x01) */
#define PMU_SUPPLY_STS_PMU_1V5_FAIL_EN_Pos (2UL)                    /*!< PMU SUPPLY_STS: PMU_1V5_FAIL_EN (Bit 2)               */
#define PMU_SUPPLY_STS_PMU_1V5_FAIL_EN_Msk (0x4UL)                  /*!< PMU SUPPLY_STS: PMU_1V5_FAIL_EN (Bitfield-Mask: 0x01) */
#define PMU_SUPPLY_STS_PMU_1V5_OVERLOAD_Pos (1UL)                   /*!< PMU SUPPLY_STS: PMU_1V5_OVERLOAD (Bit 1)              */
#define PMU_SUPPLY_STS_PMU_1V5_OVERLOAD_Msk (0x2UL)                 /*!< PMU SUPPLY_STS: PMU_1V5_OVERLOAD (Bitfield-Mask: 0x01) */
#define PMU_SUPPLY_STS_PMU_1V5_OVERVOLT_Pos (0UL)                   /*!< PMU SUPPLY_STS: PMU_1V5_OVERVOLT (Bit 0)              */
#define PMU_SUPPLY_STS_PMU_1V5_OVERVOLT_Msk (0x1UL)                 /*!< PMU SUPPLY_STS: PMU_1V5_OVERVOLT (Bitfield-Mask: 0x01) */
/* ======================================================  VDDEXT_CTRL  ====================================================== */
#define PMU_VDDEXT_CTRL_VDDEXT_OT_SC_Pos  (13UL)                    /*!< PMU VDDEXT_CTRL: VDDEXT_OT_SC (Bit 13)                */
#define PMU_VDDEXT_CTRL_VDDEXT_OT_SC_Msk  (0x2000UL)                /*!< PMU VDDEXT_CTRL: VDDEXT_OT_SC (Bitfield-Mask: 0x01)   */
#define PMU_VDDEXT_CTRL_VDDEXT_UV_ISC_Pos (12UL)                    /*!< PMU VDDEXT_CTRL: VDDEXT_UV_ISC (Bit 12)               */
#define PMU_VDDEXT_CTRL_VDDEXT_UV_ISC_Msk (0x1000UL)                /*!< PMU VDDEXT_CTRL: VDDEXT_UV_ISC (Bitfield-Mask: 0x01)  */
#define PMU_VDDEXT_CTRL_VDDEXT_OT_ISC_Pos (11UL)                    /*!< PMU VDDEXT_CTRL: VDDEXT_OT_ISC (Bit 11)               */
#define PMU_VDDEXT_CTRL_VDDEXT_OT_ISC_Msk (0x800UL)                 /*!< PMU VDDEXT_CTRL: VDDEXT_OT_ISC (Bitfield-Mask: 0x01)  */
#define PMU_VDDEXT_CTRL_VDDEXT_STABLE_Pos (7UL)                     /*!< PMU VDDEXT_CTRL: VDDEXT_STABLE (Bit 7)                */
#define PMU_VDDEXT_CTRL_VDDEXT_STABLE_Msk (0x80UL)                  /*!< PMU VDDEXT_CTRL: VDDEXT_STABLE (Bitfield-Mask: 0x01)  */
#define PMU_VDDEXT_CTRL_VDDEXT_OT_Pos     (6UL)                     /*!< PMU VDDEXT_CTRL: VDDEXT_OT (Bit 6)                    */
#define PMU_VDDEXT_CTRL_VDDEXT_OT_Msk     (0x40UL)                  /*!< PMU VDDEXT_CTRL: VDDEXT_OT (Bitfield-Mask: 0x01)      */
#define PMU_VDDEXT_CTRL_VDDEXT_OT_STS_Pos (5UL)                     /*!< PMU VDDEXT_CTRL: VDDEXT_OT_STS (Bit 5)                */
#define PMU_VDDEXT_CTRL_VDDEXT_OT_STS_Msk (0x20UL)                  /*!< PMU VDDEXT_CTRL: VDDEXT_OT_STS (Bitfield-Mask: 0x01)  */
#define PMU_VDDEXT_CTRL_VDDEXT_UV_IS_Pos  (4UL)                     /*!< PMU VDDEXT_CTRL: VDDEXT_UV_IS (Bit 4)                 */
#define PMU_VDDEXT_CTRL_VDDEXT_UV_IS_Msk  (0x10UL)                  /*!< PMU VDDEXT_CTRL: VDDEXT_UV_IS (Bitfield-Mask: 0x01)   */
#define PMU_VDDEXT_CTRL_VDDEXT_OT_IS_Pos  (3UL)                     /*!< PMU VDDEXT_CTRL: VDDEXT_OT_IS (Bit 3)                 */
#define PMU_VDDEXT_CTRL_VDDEXT_OT_IS_Msk  (0x8UL)                   /*!< PMU VDDEXT_CTRL: VDDEXT_OT_IS (Bitfield-Mask: 0x01)   */
#define PMU_VDDEXT_CTRL_VDDEXT_FAIL_EN_Pos (2UL)                    /*!< PMU VDDEXT_CTRL: VDDEXT_FAIL_EN (Bit 2)               */
#define PMU_VDDEXT_CTRL_VDDEXT_FAIL_EN_Msk (0x4UL)                  /*!< PMU VDDEXT_CTRL: VDDEXT_FAIL_EN (Bitfield-Mask: 0x01) */
#define PMU_VDDEXT_CTRL_VDDEXT_CYC_EN_Pos (1UL)                     /*!< PMU VDDEXT_CTRL: VDDEXT_CYC_EN (Bit 1)                */
#define PMU_VDDEXT_CTRL_VDDEXT_CYC_EN_Msk (0x2UL)                   /*!< PMU VDDEXT_CTRL: VDDEXT_CYC_EN (Bitfield-Mask: 0x01)  */
#define PMU_VDDEXT_CTRL_VDDEXT_ENABLE_Pos (0UL)                     /*!< PMU VDDEXT_CTRL: VDDEXT_ENABLE (Bit 0)                */
#define PMU_VDDEXT_CTRL_VDDEXT_ENABLE_Msk (0x1UL)                   /*!< PMU VDDEXT_CTRL: VDDEXT_ENABLE (Bitfield-Mask: 0x01)  */
/* ==========================================================  WFS  ========================================================== */
#define PMU_WFS_LP_CLKWD_Pos              (7UL)                     /*!< PMU WFS: LP_CLKWD (Bit 7)                             */
#define PMU_WFS_LP_CLKWD_Msk              (0x80UL)                  /*!< PMU WFS: LP_CLKWD (Bitfield-Mask: 0x01)               */
#define PMU_WFS_WDT1_SEQ_FAIL_Pos         (6UL)                     /*!< PMU WFS: WDT1_SEQ_FAIL (Bit 6)                        */
#define PMU_WFS_WDT1_SEQ_FAIL_Msk         (0x40UL)                  /*!< PMU WFS: WDT1_SEQ_FAIL (Bitfield-Mask: 0x01)          */
#define PMU_WFS_SYS_OT_Pos                (5UL)                     /*!< PMU WFS: SYS_OT (Bit 5)                               */
#define PMU_WFS_SYS_OT_Msk                (0x20UL)                  /*!< PMU WFS: SYS_OT (Bitfield-Mask: 0x01)                 */
#define PMU_WFS_SYS_CLK_WDT_Pos           (4UL)                     /*!< PMU WFS: SYS_CLK_WDT (Bit 4)                          */
#define PMU_WFS_SYS_CLK_WDT_Msk           (0x10UL)                  /*!< PMU WFS: SYS_CLK_WDT (Bitfield-Mask: 0x01)            */
#define PMU_WFS_PMU_5V_OVL_Pos            (3UL)                     /*!< PMU WFS: PMU_5V_OVL (Bit 3)                           */
#define PMU_WFS_PMU_5V_OVL_Msk            (0x8UL)                   /*!< PMU WFS: PMU_5V_OVL (Bitfield-Mask: 0x01)             */
#define PMU_WFS_PMU_1V5_OVL_Pos           (2UL)                     /*!< PMU WFS: PMU_1V5_OVL (Bit 2)                          */
#define PMU_WFS_PMU_1V5_OVL_Msk           (0x4UL)                   /*!< PMU WFS: PMU_1V5_OVL (Bitfield-Mask: 0x01)            */
#define PMU_WFS_SUPP_TMOUT_Pos            (1UL)                     /*!< PMU WFS: SUPP_TMOUT (Bit 1)                           */
#define PMU_WFS_SUPP_TMOUT_Msk            (0x2UL)                   /*!< PMU WFS: SUPP_TMOUT (Bitfield-Mask: 0x01)             */
#define PMU_WFS_SUPP_SHORT_Pos            (0UL)                     /*!< PMU WFS: SUPP_SHORT (Bit 0)                           */
#define PMU_WFS_SUPP_SHORT_Msk            (0x1UL)                   /*!< PMU WFS: SUPP_SHORT (Bitfield-Mask: 0x01)             */
/* =====================================================  HIGHSIDE_CTRL  ===================================================== */
#define PMU_HIGHSIDE_CTRL_HS2_CYC_EN_Pos  (10UL)                    /*!< PMU HIGHSIDE_CTRL: HS2_CYC_EN (Bit 10)                */
#define PMU_HIGHSIDE_CTRL_HS2_CYC_EN_Msk  (0x400UL)                 /*!< PMU HIGHSIDE_CTRL: HS2_CYC_EN (Bitfield-Mask: 0x01)   */
#define PMU_HIGHSIDE_CTRL_HS1_CYC_EN_Pos  (2UL)                     /*!< PMU HIGHSIDE_CTRL: HS1_CYC_EN (Bit 2)                 */
#define PMU_HIGHSIDE_CTRL_HS1_CYC_EN_Msk  (0x4UL)                   /*!< PMU HIGHSIDE_CTRL: HS1_CYC_EN (Bitfield-Mask: 0x01)   */
/* =======================================================  CPREG_CNF  ======================================================= */
#define PMU_CPREG_CNF_SEL_GPIO_Pos        (0UL)                     /*!< PMU CPREG_CNF: SEL_GPIO (Bit 0)                       */
#define PMU_CPREG_CNF_SEL_GPIO_Msk        (0x1UL)                   /*!< PMU CPREG_CNF: SEL_GPIO (Bitfield-Mask: 0x01)         */
/* ====================================================  WAKE_CNF_GPIO1  ===================================================== */
#define PMU_WAKE_CNF_GPIO1_CYC_4_Pos      (20UL)                    /*!< PMU WAKE_CNF_GPIO1: CYC_4 (Bit 20)                    */
#define PMU_WAKE_CNF_GPIO1_CYC_4_Msk      (0x100000UL)              /*!< PMU WAKE_CNF_GPIO1: CYC_4 (Bitfield-Mask: 0x01)       */
#define PMU_WAKE_CNF_GPIO1_CYC_3_Pos      (19UL)                    /*!< PMU WAKE_CNF_GPIO1: CYC_3 (Bit 19)                    */
#define PMU_WAKE_CNF_GPIO1_CYC_3_Msk      (0x80000UL)               /*!< PMU WAKE_CNF_GPIO1: CYC_3 (Bitfield-Mask: 0x01)       */
#define PMU_WAKE_CNF_GPIO1_CYC_2_Pos      (18UL)                    /*!< PMU WAKE_CNF_GPIO1: CYC_2 (Bit 18)                    */
#define PMU_WAKE_CNF_GPIO1_CYC_2_Msk      (0x40000UL)               /*!< PMU WAKE_CNF_GPIO1: CYC_2 (Bitfield-Mask: 0x01)       */
#define PMU_WAKE_CNF_GPIO1_CYC_1_Pos      (17UL)                    /*!< PMU WAKE_CNF_GPIO1: CYC_1 (Bit 17)                    */
#define PMU_WAKE_CNF_GPIO1_CYC_1_Msk      (0x20000UL)               /*!< PMU WAKE_CNF_GPIO1: CYC_1 (Bitfield-Mask: 0x01)       */
#define PMU_WAKE_CNF_GPIO1_CYC_0_Pos      (16UL)                    /*!< PMU WAKE_CNF_GPIO1: CYC_0 (Bit 16)                    */
#define PMU_WAKE_CNF_GPIO1_CYC_0_Msk      (0x10000UL)               /*!< PMU WAKE_CNF_GPIO1: CYC_0 (Bitfield-Mask: 0x01)       */
#define PMU_WAKE_CNF_GPIO1_FA_4_Pos       (12UL)                    /*!< PMU WAKE_CNF_GPIO1: FA_4 (Bit 12)                     */
#define PMU_WAKE_CNF_GPIO1_FA_4_Msk       (0x1000UL)                /*!< PMU WAKE_CNF_GPIO1: FA_4 (Bitfield-Mask: 0x01)        */
#define PMU_WAKE_CNF_GPIO1_FA_3_Pos       (11UL)                    /*!< PMU WAKE_CNF_GPIO1: FA_3 (Bit 11)                     */
#define PMU_WAKE_CNF_GPIO1_FA_3_Msk       (0x800UL)                 /*!< PMU WAKE_CNF_GPIO1: FA_3 (Bitfield-Mask: 0x01)        */
#define PMU_WAKE_CNF_GPIO1_FA_2_Pos       (10UL)                    /*!< PMU WAKE_CNF_GPIO1: FA_2 (Bit 10)                     */
#define PMU_WAKE_CNF_GPIO1_FA_2_Msk       (0x400UL)                 /*!< PMU WAKE_CNF_GPIO1: FA_2 (Bitfield-Mask: 0x01)        */
#define PMU_WAKE_CNF_GPIO1_FA_1_Pos       (9UL)                     /*!< PMU WAKE_CNF_GPIO1: FA_1 (Bit 9)                      */
#define PMU_WAKE_CNF_GPIO1_FA_1_Msk       (0x200UL)                 /*!< PMU WAKE_CNF_GPIO1: FA_1 (Bitfield-Mask: 0x01)        */
#define PMU_WAKE_CNF_GPIO1_FA_0_Pos       (8UL)                     /*!< PMU WAKE_CNF_GPIO1: FA_0 (Bit 8)                      */
#define PMU_WAKE_CNF_GPIO1_FA_0_Msk       (0x100UL)                 /*!< PMU WAKE_CNF_GPIO1: FA_0 (Bitfield-Mask: 0x01)        */
#define PMU_WAKE_CNF_GPIO1_RI_4_Pos       (4UL)                     /*!< PMU WAKE_CNF_GPIO1: RI_4 (Bit 4)                      */
#define PMU_WAKE_CNF_GPIO1_RI_4_Msk       (0x10UL)                  /*!< PMU WAKE_CNF_GPIO1: RI_4 (Bitfield-Mask: 0x01)        */
#define PMU_WAKE_CNF_GPIO1_RI_3_Pos       (3UL)                     /*!< PMU WAKE_CNF_GPIO1: RI_3 (Bit 3)                      */
#define PMU_WAKE_CNF_GPIO1_RI_3_Msk       (0x8UL)                   /*!< PMU WAKE_CNF_GPIO1: RI_3 (Bitfield-Mask: 0x01)        */
#define PMU_WAKE_CNF_GPIO1_RI_2_Pos       (2UL)                     /*!< PMU WAKE_CNF_GPIO1: RI_2 (Bit 2)                      */
#define PMU_WAKE_CNF_GPIO1_RI_2_Msk       (0x4UL)                   /*!< PMU WAKE_CNF_GPIO1: RI_2 (Bitfield-Mask: 0x01)        */
#define PMU_WAKE_CNF_GPIO1_RI_1_Pos       (1UL)                     /*!< PMU WAKE_CNF_GPIO1: RI_1 (Bit 1)                      */
#define PMU_WAKE_CNF_GPIO1_RI_1_Msk       (0x2UL)                   /*!< PMU WAKE_CNF_GPIO1: RI_1 (Bitfield-Mask: 0x01)        */
#define PMU_WAKE_CNF_GPIO1_RI_0_Pos       (0UL)                     /*!< PMU WAKE_CNF_GPIO1: RI_0 (Bit 0)                      */
#define PMU_WAKE_CNF_GPIO1_RI_0_Msk       (0x1UL)                   /*!< PMU WAKE_CNF_GPIO1: RI_0 (Bitfield-Mask: 0x01)        */
/* ====================================================  CNF_WAKE_FILTER  ==================================================== */
#define PMU_CNF_WAKE_FILTER_CNF_GPIO_FT_Pos (2UL)                   /*!< PMU CNF_WAKE_FILTER: CNF_GPIO_FT (Bit 2)              */
#define PMU_CNF_WAKE_FILTER_CNF_GPIO_FT_Msk (0xcUL)                 /*!< PMU CNF_WAKE_FILTER: CNF_GPIO_FT (Bitfield-Mask: 0x03) */
#define PMU_CNF_WAKE_FILTER_CNF_MON_FT_Pos (1UL)                    /*!< PMU CNF_WAKE_FILTER: CNF_MON_FT (Bit 1)               */
#define PMU_CNF_WAKE_FILTER_CNF_MON_FT_Msk (0x2UL)                  /*!< PMU CNF_WAKE_FILTER: CNF_MON_FT (Bitfield-Mask: 0x01) */
#define PMU_CNF_WAKE_FILTER_CNF_LIN_FT_Pos (0UL)                    /*!< PMU CNF_WAKE_FILTER: CNF_LIN_FT (Bit 0)               */
#define PMU_CNF_WAKE_FILTER_CNF_LIN_FT_Msk (0x1UL)                  /*!< PMU CNF_WAKE_FILTER: CNF_LIN_FT (Bitfield-Mask: 0x01) */
/* ======================================================  LIN_WAKE_EN  ====================================================== */
#define PMU_LIN_WAKE_EN_LIN_EN_Pos        (7UL)                     /*!< PMU LIN_WAKE_EN: LIN_EN (Bit 7)                       */
#define PMU_LIN_WAKE_EN_LIN_EN_Msk        (0x80UL)                  /*!< PMU LIN_WAKE_EN: LIN_EN (Bitfield-Mask: 0x01)         */
/* ======================================================  WAKE_STATUS  ====================================================== */
#define PMU_WAKE_STATUS_VDDEXT_UV_Pos     (18UL)                    /*!< PMU WAKE_STATUS: VDDEXT_UV (Bit 18)                   */
#define PMU_WAKE_STATUS_VDDEXT_UV_Msk     (0x40000UL)               /*!< PMU WAKE_STATUS: VDDEXT_UV (Bitfield-Mask: 0x01)      */
#define PMU_WAKE_STATUS_VDDEXT_OT_Pos     (17UL)                    /*!< PMU WAKE_STATUS: VDDEXT_OT (Bit 17)                   */
#define PMU_WAKE_STATUS_VDDEXT_OT_Msk     (0x20000UL)               /*!< PMU WAKE_STATUS: VDDEXT_OT (Bitfield-Mask: 0x01)      */
#define PMU_WAKE_STATUS_MON5_WAKE_STS_Pos (12UL)                    /*!< PMU WAKE_STATUS: MON5_WAKE_STS (Bit 12)               */
#define PMU_WAKE_STATUS_MON5_WAKE_STS_Msk (0x1000UL)                /*!< PMU WAKE_STATUS: MON5_WAKE_STS (Bitfield-Mask: 0x01)  */
#define PMU_WAKE_STATUS_MON4_WAKE_STS_Pos (11UL)                    /*!< PMU WAKE_STATUS: MON4_WAKE_STS (Bit 11)               */
#define PMU_WAKE_STATUS_MON4_WAKE_STS_Msk (0x800UL)                 /*!< PMU WAKE_STATUS: MON4_WAKE_STS (Bitfield-Mask: 0x01)  */
#define PMU_WAKE_STATUS_MON3_WAKE_STS_Pos (10UL)                    /*!< PMU WAKE_STATUS: MON3_WAKE_STS (Bit 10)               */
#define PMU_WAKE_STATUS_MON3_WAKE_STS_Msk (0x400UL)                 /*!< PMU WAKE_STATUS: MON3_WAKE_STS (Bitfield-Mask: 0x01)  */
#define PMU_WAKE_STATUS_MON2_WAKE_STS_Pos (9UL)                     /*!< PMU WAKE_STATUS: MON2_WAKE_STS (Bit 9)                */
#define PMU_WAKE_STATUS_MON2_WAKE_STS_Msk (0x200UL)                 /*!< PMU WAKE_STATUS: MON2_WAKE_STS (Bitfield-Mask: 0x01)  */
#define PMU_WAKE_STATUS_MON1_WAKE_STS_Pos (8UL)                     /*!< PMU WAKE_STATUS: MON1_WAKE_STS (Bit 8)                */
#define PMU_WAKE_STATUS_MON1_WAKE_STS_Msk (0x100UL)                 /*!< PMU WAKE_STATUS: MON1_WAKE_STS (Bitfield-Mask: 0x01)  */
#define PMU_WAKE_STATUS_GPIO2_Pos         (6UL)                     /*!< PMU WAKE_STATUS: GPIO2 (Bit 6)                        */
#define PMU_WAKE_STATUS_GPIO2_Msk         (0x40UL)                  /*!< PMU WAKE_STATUS: GPIO2 (Bitfield-Mask: 0x01)          */
#define PMU_WAKE_STATUS_FAIL_Pos          (5UL)                     /*!< PMU WAKE_STATUS: FAIL (Bit 5)                         */
#define PMU_WAKE_STATUS_FAIL_Msk          (0x20UL)                  /*!< PMU WAKE_STATUS: FAIL (Bitfield-Mask: 0x01)           */
#define PMU_WAKE_STATUS_CYC_WAKE_Pos      (4UL)                     /*!< PMU WAKE_STATUS: CYC_WAKE (Bit 4)                     */
#define PMU_WAKE_STATUS_CYC_WAKE_Msk      (0x10UL)                  /*!< PMU WAKE_STATUS: CYC_WAKE (Bitfield-Mask: 0x01)       */
#define PMU_WAKE_STATUS_GPIO1_Pos         (3UL)                     /*!< PMU WAKE_STATUS: GPIO1 (Bit 3)                        */
#define PMU_WAKE_STATUS_GPIO1_Msk         (0x8UL)                   /*!< PMU WAKE_STATUS: GPIO1 (Bitfield-Mask: 0x01)          */
#define PMU_WAKE_STATUS_GPIO0_Pos         (2UL)                     /*!< PMU WAKE_STATUS: GPIO0 (Bit 2)                        */
#define PMU_WAKE_STATUS_GPIO0_Msk         (0x4UL)                   /*!< PMU WAKE_STATUS: GPIO0 (Bitfield-Mask: 0x01)          */
#define PMU_WAKE_STATUS_MON_Pos           (1UL)                     /*!< PMU WAKE_STATUS: MON (Bit 1)                          */
#define PMU_WAKE_STATUS_MON_Msk           (0x2UL)                   /*!< PMU WAKE_STATUS: MON (Bitfield-Mask: 0x01)            */
#define PMU_WAKE_STATUS_LIN_WAKE_Pos      (0UL)                     /*!< PMU WAKE_STATUS: LIN_WAKE (Bit 0)                     */
#define PMU_WAKE_STATUS_LIN_WAKE_Msk      (0x1UL)                   /*!< PMU WAKE_STATUS: LIN_WAKE (Bitfield-Mask: 0x01)       */
/* ===================================================  GPIO_WAKE_STATUS  ==================================================== */
#define PMU_GPIO_WAKE_STATUS_GPIO1_STS_4_Pos (12UL)                 /*!< PMU GPIO_WAKE_STATUS: GPIO1_STS_4 (Bit 12)            */
#define PMU_GPIO_WAKE_STATUS_GPIO1_STS_4_Msk (0x1000UL)             /*!< PMU GPIO_WAKE_STATUS: GPIO1_STS_4 (Bitfield-Mask: 0x01) */
#define PMU_GPIO_WAKE_STATUS_GPIO1_STS_2_Pos (10UL)                 /*!< PMU GPIO_WAKE_STATUS: GPIO1_STS_2 (Bit 10)            */
#define PMU_GPIO_WAKE_STATUS_GPIO1_STS_2_Msk (0x400UL)              /*!< PMU GPIO_WAKE_STATUS: GPIO1_STS_2 (Bitfield-Mask: 0x01) */
#define PMU_GPIO_WAKE_STATUS_GPIO1_STS_1_Pos (9UL)                  /*!< PMU GPIO_WAKE_STATUS: GPIO1_STS_1 (Bit 9)             */
#define PMU_GPIO_WAKE_STATUS_GPIO1_STS_1_Msk (0x200UL)              /*!< PMU GPIO_WAKE_STATUS: GPIO1_STS_1 (Bitfield-Mask: 0x01) */
#define PMU_GPIO_WAKE_STATUS_GPIO1_STS_0_Pos (8UL)                  /*!< PMU GPIO_WAKE_STATUS: GPIO1_STS_0 (Bit 8)             */
#define PMU_GPIO_WAKE_STATUS_GPIO1_STS_0_Msk (0x100UL)              /*!< PMU GPIO_WAKE_STATUS: GPIO1_STS_0 (Bitfield-Mask: 0x01) */
#define PMU_GPIO_WAKE_STATUS_GPIO0_STS_4_Pos (4UL)                  /*!< PMU GPIO_WAKE_STATUS: GPIO0_STS_4 (Bit 4)             */
#define PMU_GPIO_WAKE_STATUS_GPIO0_STS_4_Msk (0x10UL)               /*!< PMU GPIO_WAKE_STATUS: GPIO0_STS_4 (Bitfield-Mask: 0x01) */
#define PMU_GPIO_WAKE_STATUS_GPIO0_STS_3_Pos (3UL)                  /*!< PMU GPIO_WAKE_STATUS: GPIO0_STS_3 (Bit 3)             */
#define PMU_GPIO_WAKE_STATUS_GPIO0_STS_3_Msk (0x8UL)                /*!< PMU GPIO_WAKE_STATUS: GPIO0_STS_3 (Bitfield-Mask: 0x01) */
#define PMU_GPIO_WAKE_STATUS_GPIO0_STS_2_Pos (2UL)                  /*!< PMU GPIO_WAKE_STATUS: GPIO0_STS_2 (Bit 2)             */
#define PMU_GPIO_WAKE_STATUS_GPIO0_STS_2_Msk (0x4UL)                /*!< PMU GPIO_WAKE_STATUS: GPIO0_STS_2 (Bitfield-Mask: 0x01) */
#define PMU_GPIO_WAKE_STATUS_GPIO0_STS_1_Pos (1UL)                  /*!< PMU GPIO_WAKE_STATUS: GPIO0_STS_1 (Bit 1)             */
#define PMU_GPIO_WAKE_STATUS_GPIO0_STS_1_Msk (0x2UL)                /*!< PMU GPIO_WAKE_STATUS: GPIO0_STS_1 (Bitfield-Mask: 0x01) */
#define PMU_GPIO_WAKE_STATUS_GPIO0_STS_0_Pos (0UL)                  /*!< PMU GPIO_WAKE_STATUS: GPIO0_STS_0 (Bit 0)             */
#define PMU_GPIO_WAKE_STATUS_GPIO0_STS_0_Msk (0x1UL)                /*!< PMU GPIO_WAKE_STATUS: GPIO0_STS_0 (Bitfield-Mask: 0x01) */
/* =========================================================  SLEEP  ========================================================= */
#define PMU_SLEEP_CYC_SENSE_S_DEL_Pos     (24UL)                    /*!< PMU SLEEP: CYC_SENSE_S_DEL (Bit 24)                   */
#define PMU_SLEEP_CYC_SENSE_S_DEL_Msk     (0x7000000UL)             /*!< PMU SLEEP: CYC_SENSE_S_DEL (Bitfield-Mask: 0x07)      */
#define PMU_SLEEP_CYC_WAKE_E01_Pos        (20UL)                    /*!< PMU SLEEP: CYC_WAKE_E01 (Bit 20)                      */
#define PMU_SLEEP_CYC_WAKE_E01_Msk        (0x300000UL)              /*!< PMU SLEEP: CYC_WAKE_E01 (Bitfield-Mask: 0x03)         */
#define PMU_SLEEP_CYC_WAKE_M03_Pos        (16UL)                    /*!< PMU SLEEP: CYC_WAKE_M03 (Bit 16)                      */
#define PMU_SLEEP_CYC_WAKE_M03_Msk        (0xf0000UL)               /*!< PMU SLEEP: CYC_WAKE_M03 (Bitfield-Mask: 0x0f)         */
#define PMU_SLEEP_CYC_SENSE_E01_Pos       (12UL)                    /*!< PMU SLEEP: CYC_SENSE_E01 (Bit 12)                     */
#define PMU_SLEEP_CYC_SENSE_E01_Msk       (0x3000UL)                /*!< PMU SLEEP: CYC_SENSE_E01 (Bitfield-Mask: 0x03)        */
#define PMU_SLEEP_CYC_SENSE_M03_Pos       (8UL)                     /*!< PMU SLEEP: CYC_SENSE_M03 (Bit 8)                      */
#define PMU_SLEEP_CYC_SENSE_M03_Msk       (0xf00UL)                 /*!< PMU SLEEP: CYC_SENSE_M03 (Bitfield-Mask: 0x0f)        */
#define PMU_SLEEP_RFU_Pos                 (4UL)                     /*!< PMU SLEEP: RFU (Bit 4)                                */
#define PMU_SLEEP_RFU_Msk                 (0x10UL)                  /*!< PMU SLEEP: RFU (Bitfield-Mask: 0x01)                  */
#define PMU_SLEEP_CYC_SENSE_EN_Pos        (3UL)                     /*!< PMU SLEEP: CYC_SENSE_EN (Bit 3)                       */
#define PMU_SLEEP_CYC_SENSE_EN_Msk        (0x8UL)                   /*!< PMU SLEEP: CYC_SENSE_EN (Bitfield-Mask: 0x01)         */
#define PMU_SLEEP_CYC_WAKE_EN_Pos         (2UL)                     /*!< PMU SLEEP: CYC_WAKE_EN (Bit 2)                        */
#define PMU_SLEEP_CYC_WAKE_EN_Msk         (0x4UL)                   /*!< PMU SLEEP: CYC_WAKE_EN (Bitfield-Mask: 0x01)          */
#define PMU_SLEEP_EN_0V9_N_Pos            (1UL)                     /*!< PMU SLEEP: EN_0V9_N (Bit 1)                           */
#define PMU_SLEEP_EN_0V9_N_Msk            (0x2UL)                   /*!< PMU SLEEP: EN_0V9_N (Bitfield-Mask: 0x01)             */
#define PMU_SLEEP_WAKE_W_RST_Pos          (0UL)                     /*!< PMU SLEEP: WAKE_W_RST (Bit 0)                         */
#define PMU_SLEEP_WAKE_W_RST_Msk          (0x1UL)                   /*!< PMU SLEEP: WAKE_W_RST (Bitfield-Mask: 0x01)           */
/* ======================================================  CNF_RST_TFB  ====================================================== */
#define PMU_CNF_RST_TFB_RST_TFB_Pos       (0UL)                     /*!< PMU CNF_RST_TFB: RST_TFB (Bit 0)                      */
#define PMU_CNF_RST_TFB_RST_TFB_Msk       (0x3UL)                   /*!< PMU CNF_RST_TFB: RST_TFB (Bitfield-Mask: 0x03)        */
/* =======================================================  RESET_STS  ======================================================= */
#define PMU_RESET_STS_LOCKUP_Pos          (10UL)                    /*!< PMU RESET_STS: LOCKUP (Bit 10)                        */
#define PMU_RESET_STS_LOCKUP_Msk          (0x400UL)                 /*!< PMU RESET_STS: LOCKUP (Bitfield-Mask: 0x01)           */
#define PMU_RESET_STS_PMU_SOFT_Pos        (9UL)                     /*!< PMU RESET_STS: PMU_SOFT (Bit 9)                       */
#define PMU_RESET_STS_PMU_SOFT_Msk        (0x200UL)                 /*!< PMU RESET_STS: PMU_SOFT (Bitfield-Mask: 0x01)         */
#define PMU_RESET_STS_PMU_VS_POR_Pos      (7UL)                     /*!< PMU RESET_STS: PMU_VS_POR (Bit 7)                     */
#define PMU_RESET_STS_PMU_VS_POR_Msk      (0x80UL)                  /*!< PMU RESET_STS: PMU_VS_POR (Bitfield-Mask: 0x01)       */
#define PMU_RESET_STS_PMU_PIN_Pos         (6UL)                     /*!< PMU RESET_STS: PMU_PIN (Bit 6)                        */
#define PMU_RESET_STS_PMU_PIN_Msk         (0x40UL)                  /*!< PMU RESET_STS: PMU_PIN (Bitfield-Mask: 0x01)          */
#define PMU_RESET_STS_PMU_ExtWDT_Pos      (5UL)                     /*!< PMU RESET_STS: PMU_ExtWDT (Bit 5)                     */
#define PMU_RESET_STS_PMU_ExtWDT_Msk      (0x20UL)                  /*!< PMU RESET_STS: PMU_ExtWDT (Bitfield-Mask: 0x01)       */
#define PMU_RESET_STS_PMU_ClkWDT_Pos      (4UL)                     /*!< PMU RESET_STS: PMU_ClkWDT (Bit 4)                     */
#define PMU_RESET_STS_PMU_ClkWDT_Msk      (0x10UL)                  /*!< PMU RESET_STS: PMU_ClkWDT (Bitfield-Mask: 0x01)       */
#define PMU_RESET_STS_PMU_LPR_Pos         (3UL)                     /*!< PMU RESET_STS: PMU_LPR (Bit 3)                        */
#define PMU_RESET_STS_PMU_LPR_Msk         (0x8UL)                   /*!< PMU RESET_STS: PMU_LPR (Bitfield-Mask: 0x01)          */
#define PMU_RESET_STS_PMU_SleepEX_Pos     (2UL)                     /*!< PMU RESET_STS: PMU_SleepEX (Bit 2)                    */
#define PMU_RESET_STS_PMU_SleepEX_Msk     (0x4UL)                   /*!< PMU RESET_STS: PMU_SleepEX (Bitfield-Mask: 0x01)      */
#define PMU_RESET_STS_PMU_WAKE_Pos        (1UL)                     /*!< PMU RESET_STS: PMU_WAKE (Bit 1)                       */
#define PMU_RESET_STS_PMU_WAKE_Msk        (0x2UL)                   /*!< PMU RESET_STS: PMU_WAKE (Bitfield-Mask: 0x01)         */
#define PMU_RESET_STS_SYS_FAIL_Pos        (0UL)                     /*!< PMU RESET_STS: SYS_FAIL (Bit 0)                       */
#define PMU_RESET_STS_SYS_FAIL_Msk        (0x1UL)                   /*!< PMU RESET_STS: SYS_FAIL (Bitfield-Mask: 0x01)         */
/* ======================================================  GPUDATA0to3  ====================================================== */
#define PMU_GPUDATA0to3_DATA3_Pos         (24UL)                    /*!< PMU GPUDATA0to3: DATA3 (Bit 24)                       */
#define PMU_GPUDATA0to3_DATA3_Msk         (0xff000000UL)            /*!< PMU GPUDATA0to3: DATA3 (Bitfield-Mask: 0xff)          */
#define PMU_GPUDATA0to3_DATA2_Pos         (16UL)                    /*!< PMU GPUDATA0to3: DATA2 (Bit 16)                       */
#define PMU_GPUDATA0to3_DATA2_Msk         (0xff0000UL)              /*!< PMU GPUDATA0to3: DATA2 (Bitfield-Mask: 0xff)          */
#define PMU_GPUDATA0to3_DATA1_Pos         (8UL)                     /*!< PMU GPUDATA0to3: DATA1 (Bit 8)                        */
#define PMU_GPUDATA0to3_DATA1_Msk         (0xff00UL)                /*!< PMU GPUDATA0to3: DATA1 (Bitfield-Mask: 0xff)          */
#define PMU_GPUDATA0to3_DATA0_Pos         (0UL)                     /*!< PMU GPUDATA0to3: DATA0 (Bit 0)                        */
#define PMU_GPUDATA0to3_DATA0_Msk         (0xffUL)                  /*!< PMU GPUDATA0to3: DATA0 (Bitfield-Mask: 0xff)          */
/* ======================================================  GPUDATA4to7  ====================================================== */
#define PMU_GPUDATA4to7_DATA7_Pos         (24UL)                    /*!< PMU GPUDATA4to7: DATA7 (Bit 24)                       */
#define PMU_GPUDATA4to7_DATA7_Msk         (0xff000000UL)            /*!< PMU GPUDATA4to7: DATA7 (Bitfield-Mask: 0xff)          */
#define PMU_GPUDATA4to7_DATA6_Pos         (16UL)                    /*!< PMU GPUDATA4to7: DATA6 (Bit 16)                       */
#define PMU_GPUDATA4to7_DATA6_Msk         (0xff0000UL)              /*!< PMU GPUDATA4to7: DATA6 (Bitfield-Mask: 0xff)          */
#define PMU_GPUDATA4to7_DATA5_Pos         (8UL)                     /*!< PMU GPUDATA4to7: DATA5 (Bit 8)                        */
#define PMU_GPUDATA4to7_DATA5_Msk         (0xff00UL)                /*!< PMU GPUDATA4to7: DATA5 (Bitfield-Mask: 0xff)          */
#define PMU_GPUDATA4to7_DATA4_Pos         (0UL)                     /*!< PMU GPUDATA4to7: DATA4 (Bit 0)                        */
#define PMU_GPUDATA4to7_DATA4_Msk         (0xffUL)                  /*!< PMU GPUDATA4to7: DATA4 (Bitfield-Mask: 0xff)          */
/* =====================================================  GPUDATA8to11  ====================================================== */
#define PMU_GPUDATA8to11_DATA11_Pos       (24UL)                    /*!< PMU GPUDATA8to11: DATA11 (Bit 24)                     */
#define PMU_GPUDATA8to11_DATA11_Msk       (0xff000000UL)            /*!< PMU GPUDATA8to11: DATA11 (Bitfield-Mask: 0xff)        */
#define PMU_GPUDATA8to11_DATA10_Pos       (16UL)                    /*!< PMU GPUDATA8to11: DATA10 (Bit 16)                     */
#define PMU_GPUDATA8to11_DATA10_Msk       (0xff0000UL)              /*!< PMU GPUDATA8to11: DATA10 (Bitfield-Mask: 0xff)        */
#define PMU_GPUDATA8to11_DATA9_Pos        (8UL)                     /*!< PMU GPUDATA8to11: DATA9 (Bit 8)                       */
#define PMU_GPUDATA8to11_DATA9_Msk        (0xff00UL)                /*!< PMU GPUDATA8to11: DATA9 (Bitfield-Mask: 0xff)         */
#define PMU_GPUDATA8to11_DATA8_Pos        (0UL)                     /*!< PMU GPUDATA8to11: DATA8 (Bit 0)                       */
#define PMU_GPUDATA8to11_DATA8_Msk        (0xffUL)                  /*!< PMU GPUDATA8to11: DATA8 (Bitfield-Mask: 0xff)         */
/* =======================================================  MON_CNF1  ======================================================== */
#define PMU_MON_CNF1_MON4_STS_Pos         (31UL)                    /*!< PMU MON_CNF1: MON4_STS (Bit 31)                       */
#define PMU_MON_CNF1_MON4_STS_Msk         (0x80000000UL)            /*!< PMU MON_CNF1: MON4_STS (Bitfield-Mask: 0x01)          */
#define PMU_MON_CNF1_MON4_PU_Pos          (29UL)                    /*!< PMU MON_CNF1: MON4_PU (Bit 29)                        */
#define PMU_MON_CNF1_MON4_PU_Msk          (0x20000000UL)            /*!< PMU MON_CNF1: MON4_PU (Bitfield-Mask: 0x01)           */
#define PMU_MON_CNF1_MON4_PD_Pos          (28UL)                    /*!< PMU MON_CNF1: MON4_PD (Bit 28)                        */
#define PMU_MON_CNF1_MON4_PD_Msk          (0x10000000UL)            /*!< PMU MON_CNF1: MON4_PD (Bitfield-Mask: 0x01)           */
#define PMU_MON_CNF1_MON4_CYC_Pos         (27UL)                    /*!< PMU MON_CNF1: MON4_CYC (Bit 27)                       */
#define PMU_MON_CNF1_MON4_CYC_Msk         (0x8000000UL)             /*!< PMU MON_CNF1: MON4_CYC (Bitfield-Mask: 0x01)          */
#define PMU_MON_CNF1_MON4_RISE_Pos        (26UL)                    /*!< PMU MON_CNF1: MON4_RISE (Bit 26)                      */
#define PMU_MON_CNF1_MON4_RISE_Msk        (0x4000000UL)             /*!< PMU MON_CNF1: MON4_RISE (Bitfield-Mask: 0x01)         */
#define PMU_MON_CNF1_MON4_FALL_Pos        (25UL)                    /*!< PMU MON_CNF1: MON4_FALL (Bit 25)                      */
#define PMU_MON_CNF1_MON4_FALL_Msk        (0x2000000UL)             /*!< PMU MON_CNF1: MON4_FALL (Bitfield-Mask: 0x01)         */
#define PMU_MON_CNF1_MON4_EN_Pos          (24UL)                    /*!< PMU MON_CNF1: MON4_EN (Bit 24)                        */
#define PMU_MON_CNF1_MON4_EN_Msk          (0x1000000UL)             /*!< PMU MON_CNF1: MON4_EN (Bitfield-Mask: 0x01)           */
#define PMU_MON_CNF1_MON3_STS_Pos         (23UL)                    /*!< PMU MON_CNF1: MON3_STS (Bit 23)                       */
#define PMU_MON_CNF1_MON3_STS_Msk         (0x800000UL)              /*!< PMU MON_CNF1: MON3_STS (Bitfield-Mask: 0x01)          */
#define PMU_MON_CNF1_MON3_PU_Pos          (21UL)                    /*!< PMU MON_CNF1: MON3_PU (Bit 21)                        */
#define PMU_MON_CNF1_MON3_PU_Msk          (0x200000UL)              /*!< PMU MON_CNF1: MON3_PU (Bitfield-Mask: 0x01)           */
#define PMU_MON_CNF1_MON3_PD_Pos          (20UL)                    /*!< PMU MON_CNF1: MON3_PD (Bit 20)                        */
#define PMU_MON_CNF1_MON3_PD_Msk          (0x100000UL)              /*!< PMU MON_CNF1: MON3_PD (Bitfield-Mask: 0x01)           */
#define PMU_MON_CNF1_MON3_CYC_Pos         (19UL)                    /*!< PMU MON_CNF1: MON3_CYC (Bit 19)                       */
#define PMU_MON_CNF1_MON3_CYC_Msk         (0x80000UL)               /*!< PMU MON_CNF1: MON3_CYC (Bitfield-Mask: 0x01)          */
#define PMU_MON_CNF1_MON3_RISE_Pos        (18UL)                    /*!< PMU MON_CNF1: MON3_RISE (Bit 18)                      */
#define PMU_MON_CNF1_MON3_RISE_Msk        (0x40000UL)               /*!< PMU MON_CNF1: MON3_RISE (Bitfield-Mask: 0x01)         */
#define PMU_MON_CNF1_MON3_FALL_Pos        (17UL)                    /*!< PMU MON_CNF1: MON3_FALL (Bit 17)                      */
#define PMU_MON_CNF1_MON3_FALL_Msk        (0x20000UL)               /*!< PMU MON_CNF1: MON3_FALL (Bitfield-Mask: 0x01)         */
#define PMU_MON_CNF1_MON3_EN_Pos          (16UL)                    /*!< PMU MON_CNF1: MON3_EN (Bit 16)                        */
#define PMU_MON_CNF1_MON3_EN_Msk          (0x10000UL)               /*!< PMU MON_CNF1: MON3_EN (Bitfield-Mask: 0x01)           */
#define PMU_MON_CNF1_MON2_STS_Pos         (15UL)                    /*!< PMU MON_CNF1: MON2_STS (Bit 15)                       */
#define PMU_MON_CNF1_MON2_STS_Msk         (0x8000UL)                /*!< PMU MON_CNF1: MON2_STS (Bitfield-Mask: 0x01)          */
#define PMU_MON_CNF1_MON2_PU_Pos          (13UL)                    /*!< PMU MON_CNF1: MON2_PU (Bit 13)                        */
#define PMU_MON_CNF1_MON2_PU_Msk          (0x2000UL)                /*!< PMU MON_CNF1: MON2_PU (Bitfield-Mask: 0x01)           */
#define PMU_MON_CNF1_MON2_PD_Pos          (12UL)                    /*!< PMU MON_CNF1: MON2_PD (Bit 12)                        */
#define PMU_MON_CNF1_MON2_PD_Msk          (0x1000UL)                /*!< PMU MON_CNF1: MON2_PD (Bitfield-Mask: 0x01)           */
#define PMU_MON_CNF1_MON2_CYC_Pos         (11UL)                    /*!< PMU MON_CNF1: MON2_CYC (Bit 11)                       */
#define PMU_MON_CNF1_MON2_CYC_Msk         (0x800UL)                 /*!< PMU MON_CNF1: MON2_CYC (Bitfield-Mask: 0x01)          */
#define PMU_MON_CNF1_MON2_RISE_Pos        (10UL)                    /*!< PMU MON_CNF1: MON2_RISE (Bit 10)                      */
#define PMU_MON_CNF1_MON2_RISE_Msk        (0x400UL)                 /*!< PMU MON_CNF1: MON2_RISE (Bitfield-Mask: 0x01)         */
#define PMU_MON_CNF1_MON2_FALL_Pos        (9UL)                     /*!< PMU MON_CNF1: MON2_FALL (Bit 9)                       */
#define PMU_MON_CNF1_MON2_FALL_Msk        (0x200UL)                 /*!< PMU MON_CNF1: MON2_FALL (Bitfield-Mask: 0x01)         */
#define PMU_MON_CNF1_MON2_EN_Pos          (8UL)                     /*!< PMU MON_CNF1: MON2_EN (Bit 8)                         */
#define PMU_MON_CNF1_MON2_EN_Msk          (0x100UL)                 /*!< PMU MON_CNF1: MON2_EN (Bitfield-Mask: 0x01)           */
#define PMU_MON_CNF1_MON1_STS_Pos         (7UL)                     /*!< PMU MON_CNF1: MON1_STS (Bit 7)                        */
#define PMU_MON_CNF1_MON1_STS_Msk         (0x80UL)                  /*!< PMU MON_CNF1: MON1_STS (Bitfield-Mask: 0x01)          */
#define PMU_MON_CNF1_MON1_PU_Pos          (5UL)                     /*!< PMU MON_CNF1: MON1_PU (Bit 5)                         */
#define PMU_MON_CNF1_MON1_PU_Msk          (0x20UL)                  /*!< PMU MON_CNF1: MON1_PU (Bitfield-Mask: 0x01)           */
#define PMU_MON_CNF1_MON1_PD_Pos          (4UL)                     /*!< PMU MON_CNF1: MON1_PD (Bit 4)                         */
#define PMU_MON_CNF1_MON1_PD_Msk          (0x10UL)                  /*!< PMU MON_CNF1: MON1_PD (Bitfield-Mask: 0x01)           */
#define PMU_MON_CNF1_MON1_CYC_Pos         (3UL)                     /*!< PMU MON_CNF1: MON1_CYC (Bit 3)                        */
#define PMU_MON_CNF1_MON1_CYC_Msk         (0x8UL)                   /*!< PMU MON_CNF1: MON1_CYC (Bitfield-Mask: 0x01)          */
#define PMU_MON_CNF1_MON1_RISE_Pos        (2UL)                     /*!< PMU MON_CNF1: MON1_RISE (Bit 2)                       */
#define PMU_MON_CNF1_MON1_RISE_Msk        (0x4UL)                   /*!< PMU MON_CNF1: MON1_RISE (Bitfield-Mask: 0x01)         */
#define PMU_MON_CNF1_MON1_FALL_Pos        (1UL)                     /*!< PMU MON_CNF1: MON1_FALL (Bit 1)                       */
#define PMU_MON_CNF1_MON1_FALL_Msk        (0x2UL)                   /*!< PMU MON_CNF1: MON1_FALL (Bitfield-Mask: 0x01)         */
#define PMU_MON_CNF1_MON1_EN_Pos          (0UL)                     /*!< PMU MON_CNF1: MON1_EN (Bit 0)                         */
#define PMU_MON_CNF1_MON1_EN_Msk          (0x1UL)                   /*!< PMU MON_CNF1: MON1_EN (Bitfield-Mask: 0x01)           */
/* =======================================================  MON_CNF2  ======================================================== */
#define PMU_MON_CNF2_MON5_STS_Pos         (7UL)                     /*!< PMU MON_CNF2: MON5_STS (Bit 7)                        */
#define PMU_MON_CNF2_MON5_STS_Msk         (0x80UL)                  /*!< PMU MON_CNF2: MON5_STS (Bitfield-Mask: 0x01)          */
#define PMU_MON_CNF2_MON5_PU_Pos          (5UL)                     /*!< PMU MON_CNF2: MON5_PU (Bit 5)                         */
#define PMU_MON_CNF2_MON5_PU_Msk          (0x20UL)                  /*!< PMU MON_CNF2: MON5_PU (Bitfield-Mask: 0x01)           */
#define PMU_MON_CNF2_MON5_PD_Pos          (4UL)                     /*!< PMU MON_CNF2: MON5_PD (Bit 4)                         */
#define PMU_MON_CNF2_MON5_PD_Msk          (0x10UL)                  /*!< PMU MON_CNF2: MON5_PD (Bitfield-Mask: 0x01)           */
#define PMU_MON_CNF2_MON5_CYC_Pos         (3UL)                     /*!< PMU MON_CNF2: MON5_CYC (Bit 3)                        */
#define PMU_MON_CNF2_MON5_CYC_Msk         (0x8UL)                   /*!< PMU MON_CNF2: MON5_CYC (Bitfield-Mask: 0x01)          */
#define PMU_MON_CNF2_MON5_RISE_Pos        (2UL)                     /*!< PMU MON_CNF2: MON5_RISE (Bit 2)                       */
#define PMU_MON_CNF2_MON5_RISE_Msk        (0x4UL)                   /*!< PMU MON_CNF2: MON5_RISE (Bitfield-Mask: 0x01)         */
#define PMU_MON_CNF2_MON5_FALL_Pos        (1UL)                     /*!< PMU MON_CNF2: MON5_FALL (Bit 1)                       */
#define PMU_MON_CNF2_MON5_FALL_Msk        (0x2UL)                   /*!< PMU MON_CNF2: MON5_FALL (Bitfield-Mask: 0x01)         */
#define PMU_MON_CNF2_MON5_EN_Pos          (0UL)                     /*!< PMU MON_CNF2: MON5_EN (Bit 0)                         */
#define PMU_MON_CNF2_MON5_EN_Msk          (0x1UL)                   /*!< PMU MON_CNF2: MON5_EN (Bitfield-Mask: 0x01)           */


/* =========================================================================================================================== */
/* ================                                           PORT                                            ================ */
/* =========================================================================================================================== */

/* ========================================================  P0_DATA  ======================================================== */
#define PORT_P0_DATA_PP5_STS_Pos          (21UL)                    /*!< PORT P0_DATA: PP5_STS (Bit 21)                        */
#define PORT_P0_DATA_PP5_STS_Msk          (0x200000UL)              /*!< PORT P0_DATA: PP5_STS (Bitfield-Mask: 0x01)           */
#define PORT_P0_DATA_PP4_STS_Pos          (20UL)                    /*!< PORT P0_DATA: PP4_STS (Bit 20)                        */
#define PORT_P0_DATA_PP4_STS_Msk          (0x100000UL)              /*!< PORT P0_DATA: PP4_STS (Bitfield-Mask: 0x01)           */
#define PORT_P0_DATA_PP3_STS_Pos          (19UL)                    /*!< PORT P0_DATA: PP3_STS (Bit 19)                        */
#define PORT_P0_DATA_PP3_STS_Msk          (0x80000UL)               /*!< PORT P0_DATA: PP3_STS (Bitfield-Mask: 0x01)           */
#define PORT_P0_DATA_PP2_STS_Pos          (18UL)                    /*!< PORT P0_DATA: PP2_STS (Bit 18)                        */
#define PORT_P0_DATA_PP2_STS_Msk          (0x40000UL)               /*!< PORT P0_DATA: PP2_STS (Bitfield-Mask: 0x01)           */
#define PORT_P0_DATA_PP1_STS_Pos          (17UL)                    /*!< PORT P0_DATA: PP1_STS (Bit 17)                        */
#define PORT_P0_DATA_PP1_STS_Msk          (0x20000UL)               /*!< PORT P0_DATA: PP1_STS (Bitfield-Mask: 0x01)           */
#define PORT_P0_DATA_PP0_STS_Pos          (16UL)                    /*!< PORT P0_DATA: PP0_STS (Bit 16)                        */
#define PORT_P0_DATA_PP0_STS_Msk          (0x10000UL)               /*!< PORT P0_DATA: PP0_STS (Bitfield-Mask: 0x01)           */
#define PORT_P0_DATA_PP5_Pos              (5UL)                     /*!< PORT P0_DATA: PP5 (Bit 5)                             */
#define PORT_P0_DATA_PP5_Msk              (0x20UL)                  /*!< PORT P0_DATA: PP5 (Bitfield-Mask: 0x01)               */
#define PORT_P0_DATA_PP4_Pos              (4UL)                     /*!< PORT P0_DATA: PP4 (Bit 4)                             */
#define PORT_P0_DATA_PP4_Msk              (0x10UL)                  /*!< PORT P0_DATA: PP4 (Bitfield-Mask: 0x01)               */
#define PORT_P0_DATA_PP3_Pos              (3UL)                     /*!< PORT P0_DATA: PP3 (Bit 3)                             */
#define PORT_P0_DATA_PP3_Msk              (0x8UL)                   /*!< PORT P0_DATA: PP3 (Bitfield-Mask: 0x01)               */
#define PORT_P0_DATA_PP2_Pos              (2UL)                     /*!< PORT P0_DATA: PP2 (Bit 2)                             */
#define PORT_P0_DATA_PP2_Msk              (0x4UL)                   /*!< PORT P0_DATA: PP2 (Bitfield-Mask: 0x01)               */
#define PORT_P0_DATA_PP1_Pos              (1UL)                     /*!< PORT P0_DATA: PP1 (Bit 1)                             */
#define PORT_P0_DATA_PP1_Msk              (0x2UL)                   /*!< PORT P0_DATA: PP1 (Bitfield-Mask: 0x01)               */
#define PORT_P0_DATA_PP0_Pos              (0UL)                     /*!< PORT P0_DATA: PP0 (Bit 0)                             */
#define PORT_P0_DATA_PP0_Msk              (0x1UL)                   /*!< PORT P0_DATA: PP0 (Bitfield-Mask: 0x01)               */
/* ========================================================  P0_DIR  ========================================================= */
#define PORT_P0_DIR_PP5_INEN_Pos          (21UL)                    /*!< PORT P0_DIR: PP5_INEN (Bit 21)                        */
#define PORT_P0_DIR_PP5_INEN_Msk          (0x200000UL)              /*!< PORT P0_DIR: PP5_INEN (Bitfield-Mask: 0x01)           */
#define PORT_P0_DIR_PP4_INEN_Pos          (20UL)                    /*!< PORT P0_DIR: PP4_INEN (Bit 20)                        */
#define PORT_P0_DIR_PP4_INEN_Msk          (0x100000UL)              /*!< PORT P0_DIR: PP4_INEN (Bitfield-Mask: 0x01)           */
#define PORT_P0_DIR_PP3_INEN_Pos          (19UL)                    /*!< PORT P0_DIR: PP3_INEN (Bit 19)                        */
#define PORT_P0_DIR_PP3_INEN_Msk          (0x80000UL)               /*!< PORT P0_DIR: PP3_INEN (Bitfield-Mask: 0x01)           */
#define PORT_P0_DIR_PP2_INEN_Pos          (18UL)                    /*!< PORT P0_DIR: PP2_INEN (Bit 18)                        */
#define PORT_P0_DIR_PP2_INEN_Msk          (0x40000UL)               /*!< PORT P0_DIR: PP2_INEN (Bitfield-Mask: 0x01)           */
#define PORT_P0_DIR_PP1_INEN_Pos          (17UL)                    /*!< PORT P0_DIR: PP1_INEN (Bit 17)                        */
#define PORT_P0_DIR_PP1_INEN_Msk          (0x20000UL)               /*!< PORT P0_DIR: PP1_INEN (Bitfield-Mask: 0x01)           */
#define PORT_P0_DIR_PP0_INEN_Pos          (16UL)                    /*!< PORT P0_DIR: PP0_INEN (Bit 16)                        */
#define PORT_P0_DIR_PP0_INEN_Msk          (0x10000UL)               /*!< PORT P0_DIR: PP0_INEN (Bitfield-Mask: 0x01)           */
#define PORT_P0_DIR_PP5_Pos               (5UL)                     /*!< PORT P0_DIR: PP5 (Bit 5)                              */
#define PORT_P0_DIR_PP5_Msk               (0x20UL)                  /*!< PORT P0_DIR: PP5 (Bitfield-Mask: 0x01)                */
#define PORT_P0_DIR_PP4_Pos               (4UL)                     /*!< PORT P0_DIR: PP4 (Bit 4)                              */
#define PORT_P0_DIR_PP4_Msk               (0x10UL)                  /*!< PORT P0_DIR: PP4 (Bitfield-Mask: 0x01)                */
#define PORT_P0_DIR_PP3_Pos               (3UL)                     /*!< PORT P0_DIR: PP3 (Bit 3)                              */
#define PORT_P0_DIR_PP3_Msk               (0x8UL)                   /*!< PORT P0_DIR: PP3 (Bitfield-Mask: 0x01)                */
#define PORT_P0_DIR_PP2_Pos               (2UL)                     /*!< PORT P0_DIR: PP2 (Bit 2)                              */
#define PORT_P0_DIR_PP2_Msk               (0x4UL)                   /*!< PORT P0_DIR: PP2 (Bitfield-Mask: 0x01)                */
#define PORT_P0_DIR_PP1_Pos               (1UL)                     /*!< PORT P0_DIR: PP1 (Bit 1)                              */
#define PORT_P0_DIR_PP1_Msk               (0x2UL)                   /*!< PORT P0_DIR: PP1 (Bitfield-Mask: 0x01)                */
#define PORT_P0_DIR_PP0_Pos               (0UL)                     /*!< PORT P0_DIR: PP0 (Bit 0)                              */
#define PORT_P0_DIR_PP0_Msk               (0x1UL)                   /*!< PORT P0_DIR: PP0 (Bitfield-Mask: 0x01)                */
/* =========================================================  P0_OD  ========================================================= */
#define PORT_P0_OD_PP5_Pos                (5UL)                     /*!< PORT P0_OD: PP5 (Bit 5)                               */
#define PORT_P0_OD_PP5_Msk                (0x20UL)                  /*!< PORT P0_OD: PP5 (Bitfield-Mask: 0x01)                 */
#define PORT_P0_OD_PP4_Pos                (4UL)                     /*!< PORT P0_OD: PP4 (Bit 4)                               */
#define PORT_P0_OD_PP4_Msk                (0x10UL)                  /*!< PORT P0_OD: PP4 (Bitfield-Mask: 0x01)                 */
#define PORT_P0_OD_PP3_Pos                (3UL)                     /*!< PORT P0_OD: PP3 (Bit 3)                               */
#define PORT_P0_OD_PP3_Msk                (0x8UL)                   /*!< PORT P0_OD: PP3 (Bitfield-Mask: 0x01)                 */
#define PORT_P0_OD_PP2_Pos                (2UL)                     /*!< PORT P0_OD: PP2 (Bit 2)                               */
#define PORT_P0_OD_PP2_Msk                (0x4UL)                   /*!< PORT P0_OD: PP2 (Bitfield-Mask: 0x01)                 */
#define PORT_P0_OD_PP1_Pos                (1UL)                     /*!< PORT P0_OD: PP1 (Bit 1)                               */
#define PORT_P0_OD_PP1_Msk                (0x2UL)                   /*!< PORT P0_OD: PP1 (Bitfield-Mask: 0x01)                 */
#define PORT_P0_OD_PP0_Pos                (0UL)                     /*!< PORT P0_OD: PP0 (Bit 0)                               */
#define PORT_P0_OD_PP0_Msk                (0x1UL)                   /*!< PORT P0_OD: PP0 (Bitfield-Mask: 0x01)                 */
/* =======================================================  P0_PUDSEL  ======================================================= */
#define PORT_P0_PUDSEL_PP5_Pos            (5UL)                     /*!< PORT P0_PUDSEL: PP5 (Bit 5)                           */
#define PORT_P0_PUDSEL_PP5_Msk            (0x20UL)                  /*!< PORT P0_PUDSEL: PP5 (Bitfield-Mask: 0x01)             */
#define PORT_P0_PUDSEL_PP4_Pos            (4UL)                     /*!< PORT P0_PUDSEL: PP4 (Bit 4)                           */
#define PORT_P0_PUDSEL_PP4_Msk            (0x10UL)                  /*!< PORT P0_PUDSEL: PP4 (Bitfield-Mask: 0x01)             */
#define PORT_P0_PUDSEL_PP3_Pos            (3UL)                     /*!< PORT P0_PUDSEL: PP3 (Bit 3)                           */
#define PORT_P0_PUDSEL_PP3_Msk            (0x8UL)                   /*!< PORT P0_PUDSEL: PP3 (Bitfield-Mask: 0x01)             */
#define PORT_P0_PUDSEL_PP2_Pos            (2UL)                     /*!< PORT P0_PUDSEL: PP2 (Bit 2)                           */
#define PORT_P0_PUDSEL_PP2_Msk            (0x4UL)                   /*!< PORT P0_PUDSEL: PP2 (Bitfield-Mask: 0x01)             */
#define PORT_P0_PUDSEL_PP1_Pos            (1UL)                     /*!< PORT P0_PUDSEL: PP1 (Bit 1)                           */
#define PORT_P0_PUDSEL_PP1_Msk            (0x2UL)                   /*!< PORT P0_PUDSEL: PP1 (Bitfield-Mask: 0x01)             */
#define PORT_P0_PUDSEL_PP0_Pos            (0UL)                     /*!< PORT P0_PUDSEL: PP0 (Bit 0)                           */
#define PORT_P0_PUDSEL_PP0_Msk            (0x1UL)                   /*!< PORT P0_PUDSEL: PP0 (Bitfield-Mask: 0x01)             */
/* =======================================================  P0_PUDEN  ======================================================== */
#define PORT_P0_PUDEN_PP5_Pos             (5UL)                     /*!< PORT P0_PUDEN: PP5 (Bit 5)                            */
#define PORT_P0_PUDEN_PP5_Msk             (0x20UL)                  /*!< PORT P0_PUDEN: PP5 (Bitfield-Mask: 0x01)              */
#define PORT_P0_PUDEN_PP4_Pos             (4UL)                     /*!< PORT P0_PUDEN: PP4 (Bit 4)                            */
#define PORT_P0_PUDEN_PP4_Msk             (0x10UL)                  /*!< PORT P0_PUDEN: PP4 (Bitfield-Mask: 0x01)              */
#define PORT_P0_PUDEN_PP3_Pos             (3UL)                     /*!< PORT P0_PUDEN: PP3 (Bit 3)                            */
#define PORT_P0_PUDEN_PP3_Msk             (0x8UL)                   /*!< PORT P0_PUDEN: PP3 (Bitfield-Mask: 0x01)              */
#define PORT_P0_PUDEN_PP2_Pos             (2UL)                     /*!< PORT P0_PUDEN: PP2 (Bit 2)                            */
#define PORT_P0_PUDEN_PP2_Msk             (0x4UL)                   /*!< PORT P0_PUDEN: PP2 (Bitfield-Mask: 0x01)              */
#define PORT_P0_PUDEN_PP1_Pos             (1UL)                     /*!< PORT P0_PUDEN: PP1 (Bit 1)                            */
#define PORT_P0_PUDEN_PP1_Msk             (0x2UL)                   /*!< PORT P0_PUDEN: PP1 (Bitfield-Mask: 0x01)              */
#define PORT_P0_PUDEN_PP0_Pos             (0UL)                     /*!< PORT P0_PUDEN: PP0 (Bit 0)                            */
#define PORT_P0_PUDEN_PP0_Msk             (0x1UL)                   /*!< PORT P0_PUDEN: PP0 (Bitfield-Mask: 0x01)              */
/* ======================================================  P0_ALTSEL0  ======================================================= */
#define PORT_P0_ALTSEL0_PP5_Pos           (5UL)                     /*!< PORT P0_ALTSEL0: PP5 (Bit 5)                          */
#define PORT_P0_ALTSEL0_PP5_Msk           (0x20UL)                  /*!< PORT P0_ALTSEL0: PP5 (Bitfield-Mask: 0x01)            */
#define PORT_P0_ALTSEL0_PP4_Pos           (4UL)                     /*!< PORT P0_ALTSEL0: PP4 (Bit 4)                          */
#define PORT_P0_ALTSEL0_PP4_Msk           (0x10UL)                  /*!< PORT P0_ALTSEL0: PP4 (Bitfield-Mask: 0x01)            */
#define PORT_P0_ALTSEL0_PP3_Pos           (3UL)                     /*!< PORT P0_ALTSEL0: PP3 (Bit 3)                          */
#define PORT_P0_ALTSEL0_PP3_Msk           (0x8UL)                   /*!< PORT P0_ALTSEL0: PP3 (Bitfield-Mask: 0x01)            */
#define PORT_P0_ALTSEL0_PP2_Pos           (2UL)                     /*!< PORT P0_ALTSEL0: PP2 (Bit 2)                          */
#define PORT_P0_ALTSEL0_PP2_Msk           (0x4UL)                   /*!< PORT P0_ALTSEL0: PP2 (Bitfield-Mask: 0x01)            */
#define PORT_P0_ALTSEL0_PP1_Pos           (1UL)                     /*!< PORT P0_ALTSEL0: PP1 (Bit 1)                          */
#define PORT_P0_ALTSEL0_PP1_Msk           (0x2UL)                   /*!< PORT P0_ALTSEL0: PP1 (Bitfield-Mask: 0x01)            */
#define PORT_P0_ALTSEL0_PP0_Pos           (0UL)                     /*!< PORT P0_ALTSEL0: PP0 (Bit 0)                          */
#define PORT_P0_ALTSEL0_PP0_Msk           (0x1UL)                   /*!< PORT P0_ALTSEL0: PP0 (Bitfield-Mask: 0x01)            */
/* ======================================================  P0_ALTSEL1  ======================================================= */
#define PORT_P0_ALTSEL1_PP5_Pos           (5UL)                     /*!< PORT P0_ALTSEL1: PP5 (Bit 5)                          */
#define PORT_P0_ALTSEL1_PP5_Msk           (0x20UL)                  /*!< PORT P0_ALTSEL1: PP5 (Bitfield-Mask: 0x01)            */
#define PORT_P0_ALTSEL1_PP4_Pos           (4UL)                     /*!< PORT P0_ALTSEL1: PP4 (Bit 4)                          */
#define PORT_P0_ALTSEL1_PP4_Msk           (0x10UL)                  /*!< PORT P0_ALTSEL1: PP4 (Bitfield-Mask: 0x01)            */
#define PORT_P0_ALTSEL1_PP3_Pos           (3UL)                     /*!< PORT P0_ALTSEL1: PP3 (Bit 3)                          */
#define PORT_P0_ALTSEL1_PP3_Msk           (0x8UL)                   /*!< PORT P0_ALTSEL1: PP3 (Bitfield-Mask: 0x01)            */
#define PORT_P0_ALTSEL1_PP2_Pos           (2UL)                     /*!< PORT P0_ALTSEL1: PP2 (Bit 2)                          */
#define PORT_P0_ALTSEL1_PP2_Msk           (0x4UL)                   /*!< PORT P0_ALTSEL1: PP2 (Bitfield-Mask: 0x01)            */
#define PORT_P0_ALTSEL1_PP1_Pos           (1UL)                     /*!< PORT P0_ALTSEL1: PP1 (Bit 1)                          */
#define PORT_P0_ALTSEL1_PP1_Msk           (0x2UL)                   /*!< PORT P0_ALTSEL1: PP1 (Bitfield-Mask: 0x01)            */
#define PORT_P0_ALTSEL1_PP0_Pos           (0UL)                     /*!< PORT P0_ALTSEL1: PP0 (Bit 0)                          */
#define PORT_P0_ALTSEL1_PP0_Msk           (0x1UL)                   /*!< PORT P0_ALTSEL1: PP0 (Bitfield-Mask: 0x01)            */
/* ========================================================  P1_DATA  ======================================================== */
#define PORT_P1_DATA_PP4_STS_Pos          (20UL)                    /*!< PORT P1_DATA: PP4_STS (Bit 20)                        */
#define PORT_P1_DATA_PP4_STS_Msk          (0x100000UL)              /*!< PORT P1_DATA: PP4_STS (Bitfield-Mask: 0x01)           */
#define PORT_P1_DATA_PP2_STS_Pos          (18UL)                    /*!< PORT P1_DATA: PP2_STS (Bit 18)                        */
#define PORT_P1_DATA_PP2_STS_Msk          (0x40000UL)               /*!< PORT P1_DATA: PP2_STS (Bitfield-Mask: 0x01)           */
#define PORT_P1_DATA_PP1_STS_Pos          (17UL)                    /*!< PORT P1_DATA: PP1_STS (Bit 17)                        */
#define PORT_P1_DATA_PP1_STS_Msk          (0x20000UL)               /*!< PORT P1_DATA: PP1_STS (Bitfield-Mask: 0x01)           */
#define PORT_P1_DATA_PP0_STS_Pos          (16UL)                    /*!< PORT P1_DATA: PP0_STS (Bit 16)                        */
#define PORT_P1_DATA_PP0_STS_Msk          (0x10000UL)               /*!< PORT P1_DATA: PP0_STS (Bitfield-Mask: 0x01)           */
#define PORT_P1_DATA_PP4_Pos              (4UL)                     /*!< PORT P1_DATA: PP4 (Bit 4)                             */
#define PORT_P1_DATA_PP4_Msk              (0x10UL)                  /*!< PORT P1_DATA: PP4 (Bitfield-Mask: 0x01)               */
#define PORT_P1_DATA_PP2_Pos              (2UL)                     /*!< PORT P1_DATA: PP2 (Bit 2)                             */
#define PORT_P1_DATA_PP2_Msk              (0x4UL)                   /*!< PORT P1_DATA: PP2 (Bitfield-Mask: 0x01)               */
#define PORT_P1_DATA_PP1_Pos              (1UL)                     /*!< PORT P1_DATA: PP1 (Bit 1)                             */
#define PORT_P1_DATA_PP1_Msk              (0x2UL)                   /*!< PORT P1_DATA: PP1 (Bitfield-Mask: 0x01)               */
#define PORT_P1_DATA_PP0_Pos              (0UL)                     /*!< PORT P1_DATA: PP0 (Bit 0)                             */
#define PORT_P1_DATA_PP0_Msk              (0x1UL)                   /*!< PORT P1_DATA: PP0 (Bitfield-Mask: 0x01)               */
/* ========================================================  P1_DIR  ========================================================= */
#define PORT_P1_DIR_PP4_INEN_Pos          (20UL)                    /*!< PORT P1_DIR: PP4_INEN (Bit 20)                        */
#define PORT_P1_DIR_PP4_INEN_Msk          (0x100000UL)              /*!< PORT P1_DIR: PP4_INEN (Bitfield-Mask: 0x01)           */
#define PORT_P1_DIR_PP2_INEN_Pos          (18UL)                    /*!< PORT P1_DIR: PP2_INEN (Bit 18)                        */
#define PORT_P1_DIR_PP2_INEN_Msk          (0x40000UL)               /*!< PORT P1_DIR: PP2_INEN (Bitfield-Mask: 0x01)           */
#define PORT_P1_DIR_PP1_INEN_Pos          (17UL)                    /*!< PORT P1_DIR: PP1_INEN (Bit 17)                        */
#define PORT_P1_DIR_PP1_INEN_Msk          (0x20000UL)               /*!< PORT P1_DIR: PP1_INEN (Bitfield-Mask: 0x01)           */
#define PORT_P1_DIR_PP0_INEN_Pos          (16UL)                    /*!< PORT P1_DIR: PP0_INEN (Bit 16)                        */
#define PORT_P1_DIR_PP0_INEN_Msk          (0x10000UL)               /*!< PORT P1_DIR: PP0_INEN (Bitfield-Mask: 0x01)           */
#define PORT_P1_DIR_PP4_Pos               (4UL)                     /*!< PORT P1_DIR: PP4 (Bit 4)                              */
#define PORT_P1_DIR_PP4_Msk               (0x10UL)                  /*!< PORT P1_DIR: PP4 (Bitfield-Mask: 0x01)                */
#define PORT_P1_DIR_PP2_Pos               (2UL)                     /*!< PORT P1_DIR: PP2 (Bit 2)                              */
#define PORT_P1_DIR_PP2_Msk               (0x4UL)                   /*!< PORT P1_DIR: PP2 (Bitfield-Mask: 0x01)                */
#define PORT_P1_DIR_PP1_Pos               (1UL)                     /*!< PORT P1_DIR: PP1 (Bit 1)                              */
#define PORT_P1_DIR_PP1_Msk               (0x2UL)                   /*!< PORT P1_DIR: PP1 (Bitfield-Mask: 0x01)                */
#define PORT_P1_DIR_PP0_Pos               (0UL)                     /*!< PORT P1_DIR: PP0 (Bit 0)                              */
#define PORT_P1_DIR_PP0_Msk               (0x1UL)                   /*!< PORT P1_DIR: PP0 (Bitfield-Mask: 0x01)                */
/* =========================================================  P1_OD  ========================================================= */
#define PORT_P1_OD_PP4_Pos                (4UL)                     /*!< PORT P1_OD: PP4 (Bit 4)                               */
#define PORT_P1_OD_PP4_Msk                (0x10UL)                  /*!< PORT P1_OD: PP4 (Bitfield-Mask: 0x01)                 */
#define PORT_P1_OD_PP2_Pos                (2UL)                     /*!< PORT P1_OD: PP2 (Bit 2)                               */
#define PORT_P1_OD_PP2_Msk                (0x4UL)                   /*!< PORT P1_OD: PP2 (Bitfield-Mask: 0x01)                 */
#define PORT_P1_OD_PP1_Pos                (1UL)                     /*!< PORT P1_OD: PP1 (Bit 1)                               */
#define PORT_P1_OD_PP1_Msk                (0x2UL)                   /*!< PORT P1_OD: PP1 (Bitfield-Mask: 0x01)                 */
#define PORT_P1_OD_PP0_Pos                (0UL)                     /*!< PORT P1_OD: PP0 (Bit 0)                               */
#define PORT_P1_OD_PP0_Msk                (0x1UL)                   /*!< PORT P1_OD: PP0 (Bitfield-Mask: 0x01)                 */
/* =======================================================  P1_PUDSEL  ======================================================= */
#define PORT_P1_PUDSEL_PP4_Pos            (4UL)                     /*!< PORT P1_PUDSEL: PP4 (Bit 4)                           */
#define PORT_P1_PUDSEL_PP4_Msk            (0x10UL)                  /*!< PORT P1_PUDSEL: PP4 (Bitfield-Mask: 0x01)             */
#define PORT_P1_PUDSEL_PP2_Pos            (2UL)                     /*!< PORT P1_PUDSEL: PP2 (Bit 2)                           */
#define PORT_P1_PUDSEL_PP2_Msk            (0x4UL)                   /*!< PORT P1_PUDSEL: PP2 (Bitfield-Mask: 0x01)             */
#define PORT_P1_PUDSEL_PP1_Pos            (1UL)                     /*!< PORT P1_PUDSEL: PP1 (Bit 1)                           */
#define PORT_P1_PUDSEL_PP1_Msk            (0x2UL)                   /*!< PORT P1_PUDSEL: PP1 (Bitfield-Mask: 0x01)             */
#define PORT_P1_PUDSEL_PP0_Pos            (0UL)                     /*!< PORT P1_PUDSEL: PP0 (Bit 0)                           */
#define PORT_P1_PUDSEL_PP0_Msk            (0x1UL)                   /*!< PORT P1_PUDSEL: PP0 (Bitfield-Mask: 0x01)             */
/* =======================================================  P1_PUDEN  ======================================================== */
#define PORT_P1_PUDEN_PP4_Pos             (4UL)                     /*!< PORT P1_PUDEN: PP4 (Bit 4)                            */
#define PORT_P1_PUDEN_PP4_Msk             (0x10UL)                  /*!< PORT P1_PUDEN: PP4 (Bitfield-Mask: 0x01)              */
#define PORT_P1_PUDEN_PP2_Pos             (2UL)                     /*!< PORT P1_PUDEN: PP2 (Bit 2)                            */
#define PORT_P1_PUDEN_PP2_Msk             (0x4UL)                   /*!< PORT P1_PUDEN: PP2 (Bitfield-Mask: 0x01)              */
#define PORT_P1_PUDEN_PP1_Pos             (1UL)                     /*!< PORT P1_PUDEN: PP1 (Bit 1)                            */
#define PORT_P1_PUDEN_PP1_Msk             (0x2UL)                   /*!< PORT P1_PUDEN: PP1 (Bitfield-Mask: 0x01)              */
#define PORT_P1_PUDEN_PP0_Pos             (0UL)                     /*!< PORT P1_PUDEN: PP0 (Bit 0)                            */
#define PORT_P1_PUDEN_PP0_Msk             (0x1UL)                   /*!< PORT P1_PUDEN: PP0 (Bitfield-Mask: 0x01)              */
/* ======================================================  P1_ALTSEL0  ======================================================= */
#define PORT_P1_ALTSEL0_PP4_Pos           (4UL)                     /*!< PORT P1_ALTSEL0: PP4 (Bit 4)                          */
#define PORT_P1_ALTSEL0_PP4_Msk           (0x10UL)                  /*!< PORT P1_ALTSEL0: PP4 (Bitfield-Mask: 0x01)            */
#define PORT_P1_ALTSEL0_PP2_Pos           (2UL)                     /*!< PORT P1_ALTSEL0: PP2 (Bit 2)                          */
#define PORT_P1_ALTSEL0_PP2_Msk           (0x4UL)                   /*!< PORT P1_ALTSEL0: PP2 (Bitfield-Mask: 0x01)            */
#define PORT_P1_ALTSEL0_PP1_Pos           (1UL)                     /*!< PORT P1_ALTSEL0: PP1 (Bit 1)                          */
#define PORT_P1_ALTSEL0_PP1_Msk           (0x2UL)                   /*!< PORT P1_ALTSEL0: PP1 (Bitfield-Mask: 0x01)            */
#define PORT_P1_ALTSEL0_PP0_Pos           (0UL)                     /*!< PORT P1_ALTSEL0: PP0 (Bit 0)                          */
#define PORT_P1_ALTSEL0_PP0_Msk           (0x1UL)                   /*!< PORT P1_ALTSEL0: PP0 (Bitfield-Mask: 0x01)            */
/* ======================================================  P1_ALTSEL1  ======================================================= */
#define PORT_P1_ALTSEL1_PP4_Pos           (4UL)                     /*!< PORT P1_ALTSEL1: PP4 (Bit 4)                          */
#define PORT_P1_ALTSEL1_PP4_Msk           (0x10UL)                  /*!< PORT P1_ALTSEL1: PP4 (Bitfield-Mask: 0x01)            */
#define PORT_P1_ALTSEL1_PP2_Pos           (2UL)                     /*!< PORT P1_ALTSEL1: PP2 (Bit 2)                          */
#define PORT_P1_ALTSEL1_PP2_Msk           (0x4UL)                   /*!< PORT P1_ALTSEL1: PP2 (Bitfield-Mask: 0x01)            */
#define PORT_P1_ALTSEL1_PP1_Pos           (1UL)                     /*!< PORT P1_ALTSEL1: PP1 (Bit 1)                          */
#define PORT_P1_ALTSEL1_PP1_Msk           (0x2UL)                   /*!< PORT P1_ALTSEL1: PP1 (Bitfield-Mask: 0x01)            */
#define PORT_P1_ALTSEL1_PP0_Pos           (0UL)                     /*!< PORT P1_ALTSEL1: PP0 (Bit 0)                          */
#define PORT_P1_ALTSEL1_PP0_Msk           (0x1UL)                   /*!< PORT P1_ALTSEL1: PP0 (Bitfield-Mask: 0x01)            */
/* ========================================================  P2_DATA  ======================================================== */
#define PORT_P2_DATA_PP7_Pos              (7UL)                     /*!< PORT P2_DATA: PP7 (Bit 7)                             */
#define PORT_P2_DATA_PP7_Msk              (0x80UL)                  /*!< PORT P2_DATA: PP7 (Bitfield-Mask: 0x01)               */
#define PORT_P2_DATA_PP6_Pos              (6UL)                     /*!< PORT P2_DATA: PP6 (Bit 6)                             */
#define PORT_P2_DATA_PP6_Msk              (0x40UL)                  /*!< PORT P2_DATA: PP6 (Bitfield-Mask: 0x01)               */
#define PORT_P2_DATA_PP5_Pos              (5UL)                     /*!< PORT P2_DATA: PP5 (Bit 5)                             */
#define PORT_P2_DATA_PP5_Msk              (0x20UL)                  /*!< PORT P2_DATA: PP5 (Bitfield-Mask: 0x01)               */
#define PORT_P2_DATA_PP4_Pos              (4UL)                     /*!< PORT P2_DATA: PP4 (Bit 4)                             */
#define PORT_P2_DATA_PP4_Msk              (0x10UL)                  /*!< PORT P2_DATA: PP4 (Bitfield-Mask: 0x01)               */
#define PORT_P2_DATA_PP3_Pos              (3UL)                     /*!< PORT P2_DATA: PP3 (Bit 3)                             */
#define PORT_P2_DATA_PP3_Msk              (0x8UL)                   /*!< PORT P2_DATA: PP3 (Bitfield-Mask: 0x01)               */
#define PORT_P2_DATA_PP2_Pos              (2UL)                     /*!< PORT P2_DATA: PP2 (Bit 2)                             */
#define PORT_P2_DATA_PP2_Msk              (0x4UL)                   /*!< PORT P2_DATA: PP2 (Bitfield-Mask: 0x01)               */
#define PORT_P2_DATA_PP1_Pos              (1UL)                     /*!< PORT P2_DATA: PP1 (Bit 1)                             */
#define PORT_P2_DATA_PP1_Msk              (0x2UL)                   /*!< PORT P2_DATA: PP1 (Bitfield-Mask: 0x01)               */
#define PORT_P2_DATA_PP0_Pos              (0UL)                     /*!< PORT P2_DATA: PP0 (Bit 0)                             */
#define PORT_P2_DATA_PP0_Msk              (0x1UL)                   /*!< PORT P2_DATA: PP0 (Bitfield-Mask: 0x01)               */
/* ========================================================  P2_DIR  ========================================================= */
#define PORT_P2_DIR_PP7_Pos               (7UL)                     /*!< PORT P2_DIR: PP7 (Bit 7)                              */
#define PORT_P2_DIR_PP7_Msk               (0x80UL)                  /*!< PORT P2_DIR: PP7 (Bitfield-Mask: 0x01)                */
#define PORT_P2_DIR_PP6_Pos               (6UL)                     /*!< PORT P2_DIR: PP6 (Bit 6)                              */
#define PORT_P2_DIR_PP6_Msk               (0x40UL)                  /*!< PORT P2_DIR: PP6 (Bitfield-Mask: 0x01)                */
#define PORT_P2_DIR_PP5_Pos               (5UL)                     /*!< PORT P2_DIR: PP5 (Bit 5)                              */
#define PORT_P2_DIR_PP5_Msk               (0x20UL)                  /*!< PORT P2_DIR: PP5 (Bitfield-Mask: 0x01)                */
#define PORT_P2_DIR_PP4_Pos               (4UL)                     /*!< PORT P2_DIR: PP4 (Bit 4)                              */
#define PORT_P2_DIR_PP4_Msk               (0x10UL)                  /*!< PORT P2_DIR: PP4 (Bitfield-Mask: 0x01)                */
#define PORT_P2_DIR_PP3_Pos               (3UL)                     /*!< PORT P2_DIR: PP3 (Bit 3)                              */
#define PORT_P2_DIR_PP3_Msk               (0x8UL)                   /*!< PORT P2_DIR: PP3 (Bitfield-Mask: 0x01)                */
#define PORT_P2_DIR_PP2_Pos               (2UL)                     /*!< PORT P2_DIR: PP2 (Bit 2)                              */
#define PORT_P2_DIR_PP2_Msk               (0x4UL)                   /*!< PORT P2_DIR: PP2 (Bitfield-Mask: 0x01)                */
#define PORT_P2_DIR_PP1_Pos               (1UL)                     /*!< PORT P2_DIR: PP1 (Bit 1)                              */
#define PORT_P2_DIR_PP1_Msk               (0x2UL)                   /*!< PORT P2_DIR: PP1 (Bitfield-Mask: 0x01)                */
#define PORT_P2_DIR_PP0_Pos               (0UL)                     /*!< PORT P2_DIR: PP0 (Bit 0)                              */
#define PORT_P2_DIR_PP0_Msk               (0x1UL)                   /*!< PORT P2_DIR: PP0 (Bitfield-Mask: 0x01)                */
/* =======================================================  P2_PUDSEL  ======================================================= */
#define PORT_P2_PUDSEL_PP7_Pos            (7UL)                     /*!< PORT P2_PUDSEL: PP7 (Bit 7)                           */
#define PORT_P2_PUDSEL_PP7_Msk            (0x80UL)                  /*!< PORT P2_PUDSEL: PP7 (Bitfield-Mask: 0x01)             */
#define PORT_P2_PUDSEL_PP6_Pos            (6UL)                     /*!< PORT P2_PUDSEL: PP6 (Bit 6)                           */
#define PORT_P2_PUDSEL_PP6_Msk            (0x40UL)                  /*!< PORT P2_PUDSEL: PP6 (Bitfield-Mask: 0x01)             */
#define PORT_P2_PUDSEL_PP5_Pos            (5UL)                     /*!< PORT P2_PUDSEL: PP5 (Bit 5)                           */
#define PORT_P2_PUDSEL_PP5_Msk            (0x20UL)                  /*!< PORT P2_PUDSEL: PP5 (Bitfield-Mask: 0x01)             */
#define PORT_P2_PUDSEL_PP4_Pos            (4UL)                     /*!< PORT P2_PUDSEL: PP4 (Bit 4)                           */
#define PORT_P2_PUDSEL_PP4_Msk            (0x10UL)                  /*!< PORT P2_PUDSEL: PP4 (Bitfield-Mask: 0x01)             */
#define PORT_P2_PUDSEL_PP3_Pos            (3UL)                     /*!< PORT P2_PUDSEL: PP3 (Bit 3)                           */
#define PORT_P2_PUDSEL_PP3_Msk            (0x8UL)                   /*!< PORT P2_PUDSEL: PP3 (Bitfield-Mask: 0x01)             */
#define PORT_P2_PUDSEL_PP2_Pos            (2UL)                     /*!< PORT P2_PUDSEL: PP2 (Bit 2)                           */
#define PORT_P2_PUDSEL_PP2_Msk            (0x4UL)                   /*!< PORT P2_PUDSEL: PP2 (Bitfield-Mask: 0x01)             */
#define PORT_P2_PUDSEL_PP1_Pos            (1UL)                     /*!< PORT P2_PUDSEL: PP1 (Bit 1)                           */
#define PORT_P2_PUDSEL_PP1_Msk            (0x2UL)                   /*!< PORT P2_PUDSEL: PP1 (Bitfield-Mask: 0x01)             */
#define PORT_P2_PUDSEL_PP0_Pos            (0UL)                     /*!< PORT P2_PUDSEL: PP0 (Bit 0)                           */
#define PORT_P2_PUDSEL_PP0_Msk            (0x1UL)                   /*!< PORT P2_PUDSEL: PP0 (Bitfield-Mask: 0x01)             */
/* =======================================================  P2_PUDEN  ======================================================== */
#define PORT_P2_PUDEN_PP7_Pos             (7UL)                     /*!< PORT P2_PUDEN: PP7 (Bit 7)                            */
#define PORT_P2_PUDEN_PP7_Msk             (0x80UL)                  /*!< PORT P2_PUDEN: PP7 (Bitfield-Mask: 0x01)              */
#define PORT_P2_PUDEN_PP6_Pos             (6UL)                     /*!< PORT P2_PUDEN: PP6 (Bit 6)                            */
#define PORT_P2_PUDEN_PP6_Msk             (0x40UL)                  /*!< PORT P2_PUDEN: PP6 (Bitfield-Mask: 0x01)              */
#define PORT_P2_PUDEN_PP5_Pos             (5UL)                     /*!< PORT P2_PUDEN: PP5 (Bit 5)                            */
#define PORT_P2_PUDEN_PP5_Msk             (0x20UL)                  /*!< PORT P2_PUDEN: PP5 (Bitfield-Mask: 0x01)              */
#define PORT_P2_PUDEN_PP4_Pos             (4UL)                     /*!< PORT P2_PUDEN: PP4 (Bit 4)                            */
#define PORT_P2_PUDEN_PP4_Msk             (0x10UL)                  /*!< PORT P2_PUDEN: PP4 (Bitfield-Mask: 0x01)              */
#define PORT_P2_PUDEN_PP3_Pos             (3UL)                     /*!< PORT P2_PUDEN: PP3 (Bit 3)                            */
#define PORT_P2_PUDEN_PP3_Msk             (0x8UL)                   /*!< PORT P2_PUDEN: PP3 (Bitfield-Mask: 0x01)              */
#define PORT_P2_PUDEN_PP2_Pos             (2UL)                     /*!< PORT P2_PUDEN: PP2 (Bit 2)                            */
#define PORT_P2_PUDEN_PP2_Msk             (0x4UL)                   /*!< PORT P2_PUDEN: PP2 (Bitfield-Mask: 0x01)              */
#define PORT_P2_PUDEN_PP1_Pos             (1UL)                     /*!< PORT P2_PUDEN: PP1 (Bit 1)                            */
#define PORT_P2_PUDEN_PP1_Msk             (0x2UL)                   /*!< PORT P2_PUDEN: PP1 (Bitfield-Mask: 0x01)              */
#define PORT_P2_PUDEN_PP0_Pos             (0UL)                     /*!< PORT P2_PUDEN: PP0 (Bit 0)                            */
#define PORT_P2_PUDEN_PP0_Msk             (0x1UL)                   /*!< PORT P2_PUDEN: PP0 (Bitfield-Mask: 0x01)              */


/* =========================================================================================================================== */
/* ================                                            SCU                                            ================ */
/* =========================================================================================================================== */

/* ========================================================  OSC_CON  ======================================================== */
#define SCU_OSC_CON_XPD_Pos               (4UL)                     /*!< SCU OSC_CON: XPD (Bit 4)                              */
#define SCU_OSC_CON_XPD_Msk               (0x10UL)                  /*!< SCU OSC_CON: XPD (Bitfield-Mask: 0x01)                */
#define SCU_OSC_CON_OSC2L_Pos             (3UL)                     /*!< SCU OSC_CON: OSC2L (Bit 3)                            */
#define SCU_OSC_CON_OSC2L_Msk             (0x8UL)                   /*!< SCU OSC_CON: OSC2L (Bitfield-Mask: 0x01)              */
#define SCU_OSC_CON_OSCWDTRST_Pos         (2UL)                     /*!< SCU OSC_CON: OSCWDTRST (Bit 2)                        */
#define SCU_OSC_CON_OSCWDTRST_Msk         (0x4UL)                   /*!< SCU OSC_CON: OSCWDTRST (Bitfield-Mask: 0x01)          */
#define SCU_OSC_CON_OSCSS_Pos             (0UL)                     /*!< SCU OSC_CON: OSCSS (Bit 0)                            */
#define SCU_OSC_CON_OSCSS_Msk             (0x3UL)                   /*!< SCU OSC_CON: OSCSS (Bitfield-Mask: 0x03)              */
/* ========================================================  PLL_CON  ======================================================== */
#define SCU_PLL_CON_UNPROT_VCOBYP_Pos     (11UL)                    /*!< SCU PLL_CON: UNPROT_VCOBYP (Bit 11)                   */
#define SCU_PLL_CON_UNPROT_VCOBYP_Msk     (0x800UL)                 /*!< SCU PLL_CON: UNPROT_VCOBYP (Bitfield-Mask: 0x01)      */
#define SCU_PLL_CON_UNPROT_OSCDISC_Pos    (10UL)                    /*!< SCU PLL_CON: UNPROT_OSCDISC (Bit 10)                  */
#define SCU_PLL_CON_UNPROT_OSCDISC_Msk    (0x400UL)                 /*!< SCU PLL_CON: UNPROT_OSCDISC (Bitfield-Mask: 0x01)     */
#define SCU_PLL_CON_NDIV_Pos              (4UL)                     /*!< SCU PLL_CON: NDIV (Bit 4)                             */
#define SCU_PLL_CON_NDIV_Msk              (0xf0UL)                  /*!< SCU PLL_CON: NDIV (Bitfield-Mask: 0x0f)               */
#define SCU_PLL_CON_VCOBYP_Pos            (3UL)                     /*!< SCU PLL_CON: VCOBYP (Bit 3)                           */
#define SCU_PLL_CON_VCOBYP_Msk            (0x8UL)                   /*!< SCU PLL_CON: VCOBYP (Bitfield-Mask: 0x01)             */
#define SCU_PLL_CON_OSCDISC_Pos           (2UL)                     /*!< SCU PLL_CON: OSCDISC (Bit 2)                          */
#define SCU_PLL_CON_OSCDISC_Msk           (0x4UL)                   /*!< SCU PLL_CON: OSCDISC (Bitfield-Mask: 0x01)            */
#define SCU_PLL_CON_RESLD_Pos             (1UL)                     /*!< SCU PLL_CON: RESLD (Bit 1)                            */
#define SCU_PLL_CON_RESLD_Msk             (0x2UL)                   /*!< SCU PLL_CON: RESLD (Bitfield-Mask: 0x01)              */
#define SCU_PLL_CON_LOCK_Pos              (0UL)                     /*!< SCU PLL_CON: LOCK (Bit 0)                             */
#define SCU_PLL_CON_LOCK_Msk              (0x1UL)                   /*!< SCU PLL_CON: LOCK (Bitfield-Mask: 0x01)               */
/* ========================================================  CMCON1  ========================================================= */
#define SCU_CMCON1_PDIV_Pos               (8UL)                     /*!< SCU CMCON1: PDIV (Bit 8)                              */
#define SCU_CMCON1_PDIV_Msk               (0x300UL)                 /*!< SCU CMCON1: PDIV (Bitfield-Mask: 0x03)                */
#define SCU_CMCON1_K1DIV_Pos              (6UL)                     /*!< SCU CMCON1: K1DIV (Bit 6)                             */
#define SCU_CMCON1_K1DIV_Msk              (0x40UL)                  /*!< SCU CMCON1: K1DIV (Bitfield-Mask: 0x01)               */
#define SCU_CMCON1_K2DIV_Pos              (4UL)                     /*!< SCU CMCON1: K2DIV (Bit 4)                             */
#define SCU_CMCON1_K2DIV_Msk              (0x30UL)                  /*!< SCU CMCON1: K2DIV (Bitfield-Mask: 0x03)               */
#define SCU_CMCON1_CLKREL_Pos             (0UL)                     /*!< SCU CMCON1: CLKREL (Bit 0)                            */
#define SCU_CMCON1_CLKREL_Msk             (0xfUL)                   /*!< SCU CMCON1: CLKREL (Bitfield-Mask: 0x0f)              */
/* ========================================================  CMCON2  ========================================================= */
#define SCU_CMCON2_PBA0CLKREL_Pos         (0UL)                     /*!< SCU CMCON2: PBA0CLKREL (Bit 0)                        */
#define SCU_CMCON2_PBA0CLKREL_Msk         (0x1UL)                   /*!< SCU CMCON2: PBA0CLKREL (Bitfield-Mask: 0x01)          */
/* ========================================================  SYSCON0  ======================================================== */
#define SCU_SYSCON0_SYSCLKSEL_Pos         (6UL)                     /*!< SCU SYSCON0: SYSCLKSEL (Bit 6)                        */
#define SCU_SYSCON0_SYSCLKSEL_Msk         (0xc0UL)                  /*!< SCU SYSCON0: SYSCLKSEL (Bitfield-Mask: 0x03)          */
#define SCU_SYSCON0_NVMCLKFAC_Pos         (4UL)                     /*!< SCU SYSCON0: NVMCLKFAC (Bit 4)                        */
#define SCU_SYSCON0_NVMCLKFAC_Msk         (0x30UL)                  /*!< SCU SYSCON0: NVMCLKFAC (Bitfield-Mask: 0x03)          */
/* ======================================================  APCLK_CTRL  ======================================================= */
#define SCU_APCLK_CTRL_CLKWDT_IE_Pos      (8UL)                     /*!< SCU APCLK_CTRL: CLKWDT_IE (Bit 8)                     */
#define SCU_APCLK_CTRL_CLKWDT_IE_Msk      (0x100UL)                 /*!< SCU APCLK_CTRL: CLKWDT_IE (Bitfield-Mask: 0x01)       */
#define SCU_APCLK_CTRL_APCLK_SET_Pos      (0UL)                     /*!< SCU APCLK_CTRL: APCLK_SET (Bit 0)                     */
#define SCU_APCLK_CTRL_APCLK_SET_Msk      (0x1UL)                   /*!< SCU APCLK_CTRL: APCLK_SET (Bitfield-Mask: 0x01)       */
/* =========================================================  APCLK  ========================================================= */
#define SCU_APCLK_BGCLK_DIV_Pos           (25UL)                    /*!< SCU APCLK: BGCLK_DIV (Bit 25)                         */
#define SCU_APCLK_BGCLK_DIV_Msk           (0x2000000UL)             /*!< SCU APCLK: BGCLK_DIV (Bitfield-Mask: 0x01)            */
#define SCU_APCLK_BGCLK_SEL_Pos           (24UL)                    /*!< SCU APCLK: BGCLK_SEL (Bit 24)                         */
#define SCU_APCLK_BGCLK_SEL_Msk           (0x1000000UL)             /*!< SCU APCLK: BGCLK_SEL (Bitfield-Mask: 0x01)            */
#define SCU_APCLK_APCLK2FAC_Pos           (8UL)                     /*!< SCU APCLK: APCLK2FAC (Bit 8)                          */
#define SCU_APCLK_APCLK2FAC_Msk           (0x1f00UL)                /*!< SCU APCLK: APCLK2FAC (Bitfield-Mask: 0x1f)            */
#define SCU_APCLK_APCLK1FAC_Pos           (0UL)                     /*!< SCU APCLK: APCLK1FAC (Bit 0)                          */
#define SCU_APCLK_APCLK1FAC_Msk           (0x3UL)                   /*!< SCU APCLK: APCLK1FAC (Bitfield-Mask: 0x03)            */
/* =======================================================  ADC1_CLK  ======================================================== */
#define SCU_ADC1_CLK_DPP1_CLK_DIV_Pos     (8UL)                     /*!< SCU ADC1_CLK: DPP1_CLK_DIV (Bit 8)                    */
#define SCU_ADC1_CLK_DPP1_CLK_DIV_Msk     (0x300UL)                 /*!< SCU ADC1_CLK: DPP1_CLK_DIV (Bitfield-Mask: 0x03)      */
#define SCU_ADC1_CLK_ADC1_CLK_DIV_Pos     (0UL)                     /*!< SCU ADC1_CLK: ADC1_CLK_DIV (Bit 0)                    */
#define SCU_ADC1_CLK_ADC1_CLK_DIV_Msk     (0xfUL)                   /*!< SCU ADC1_CLK: ADC1_CLK_DIV (Bitfield-Mask: 0x0f)      */
/* =======================================================  APCLK_STS  ======================================================= */
#define SCU_APCLK_STS_PLL_LOCK_Pos        (24UL)                    /*!< SCU APCLK_STS: PLL_LOCK (Bit 24)                      */
#define SCU_APCLK_STS_PLL_LOCK_Msk        (0x1000000UL)             /*!< SCU APCLK_STS: PLL_LOCK (Bitfield-Mask: 0x01)         */
#define SCU_APCLK_STS_APCLK3STS_Pos       (16UL)                    /*!< SCU APCLK_STS: APCLK3STS (Bit 16)                     */
#define SCU_APCLK_STS_APCLK3STS_Msk       (0x10000UL)               /*!< SCU APCLK_STS: APCLK3STS (Bitfield-Mask: 0x01)        */
#define SCU_APCLK_STS_APCLK2STS_Pos       (8UL)                     /*!< SCU APCLK_STS: APCLK2STS (Bit 8)                      */
#define SCU_APCLK_STS_APCLK2STS_Msk       (0x300UL)                 /*!< SCU APCLK_STS: APCLK2STS (Bitfield-Mask: 0x03)        */
#define SCU_APCLK_STS_APCLK1STS_Pos       (0UL)                     /*!< SCU APCLK_STS: APCLK1STS (Bit 0)                      */
#define SCU_APCLK_STS_APCLK1STS_Msk       (0x3UL)                   /*!< SCU APCLK_STS: APCLK1STS (Bitfield-Mask: 0x03)        */
/* ======================================================  APCLK_SCLR  ======================================================= */
#define SCU_APCLK_SCLR_PLL_LOCK_SCLR_Pos  (24UL)                    /*!< SCU APCLK_SCLR: PLL_LOCK_SCLR (Bit 24)                */
#define SCU_APCLK_SCLR_PLL_LOCK_SCLR_Msk  (0x1000000UL)             /*!< SCU APCLK_SCLR: PLL_LOCK_SCLR (Bitfield-Mask: 0x01)   */
#define SCU_APCLK_SCLR_APCLK3SCLR_Pos     (16UL)                    /*!< SCU APCLK_SCLR: APCLK3SCLR (Bit 16)                   */
#define SCU_APCLK_SCLR_APCLK3SCLR_Msk     (0x10000UL)               /*!< SCU APCLK_SCLR: APCLK3SCLR (Bitfield-Mask: 0x01)      */
#define SCU_APCLK_SCLR_APCLK2SCLR_Pos     (8UL)                     /*!< SCU APCLK_SCLR: APCLK2SCLR (Bit 8)                    */
#define SCU_APCLK_SCLR_APCLK2SCLR_Msk     (0x100UL)                 /*!< SCU APCLK_SCLR: APCLK2SCLR (Bitfield-Mask: 0x01)      */
#define SCU_APCLK_SCLR_APCLK1SCLR_Pos     (0UL)                     /*!< SCU APCLK_SCLR: APCLK1SCLR (Bit 0)                    */
#define SCU_APCLK_SCLR_APCLK1SCLR_Msk     (0x1UL)                   /*!< SCU APCLK_SCLR: APCLK1SCLR (Bitfield-Mask: 0x01)      */
/* =========================================================  COCON  ========================================================= */
#define SCU_COCON_EN_Pos                  (7UL)                     /*!< SCU COCON: EN (Bit 7)                                 */
#define SCU_COCON_EN_Msk                  (0x80UL)                  /*!< SCU COCON: EN (Bitfield-Mask: 0x01)                   */
#define SCU_COCON_COUTS1_Pos              (6UL)                     /*!< SCU COCON: COUTS1 (Bit 6)                             */
#define SCU_COCON_COUTS1_Msk              (0x40UL)                  /*!< SCU COCON: COUTS1 (Bitfield-Mask: 0x01)               */
#define SCU_COCON_TLEN_Pos                (5UL)                     /*!< SCU COCON: TLEN (Bit 5)                               */
#define SCU_COCON_TLEN_Msk                (0x20UL)                  /*!< SCU COCON: TLEN (Bitfield-Mask: 0x01)                 */
#define SCU_COCON_COUTS0_Pos              (4UL)                     /*!< SCU COCON: COUTS0 (Bit 4)                             */
#define SCU_COCON_COUTS0_Msk              (0x10UL)                  /*!< SCU COCON: COUTS0 (Bitfield-Mask: 0x01)               */
#define SCU_COCON_COREL_Pos               (0UL)                     /*!< SCU COCON: COREL (Bit 0)                              */
#define SCU_COCON_COREL_Msk               (0xfUL)                   /*!< SCU COCON: COREL (Bitfield-Mask: 0x0f)                */
/* ========================================================  RSTCON  ========================================================= */
#define SCU_RSTCON_LOCKUP_EN_Pos          (7UL)                     /*!< SCU RSTCON: LOCKUP_EN (Bit 7)                         */
#define SCU_RSTCON_LOCKUP_EN_Msk          (0x80UL)                  /*!< SCU RSTCON: LOCKUP_EN (Bitfield-Mask: 0x01)           */
#define SCU_RSTCON_LOCKUP_Pos             (0UL)                     /*!< SCU RSTCON: LOCKUP (Bit 0)                            */
#define SCU_RSTCON_LOCKUP_Msk             (0x1UL)                   /*!< SCU RSTCON: LOCKUP (Bitfield-Mask: 0x01)              */
/* ========================================================  PMCON0  ========================================================= */
#define SCU_PMCON0_SD_Pos                 (3UL)                     /*!< SCU PMCON0: SD (Bit 3)                                */
#define SCU_PMCON0_SD_Msk                 (0x8UL)                   /*!< SCU PMCON0: SD (Bitfield-Mask: 0x01)                  */
#define SCU_PMCON0_PD_Pos                 (2UL)                     /*!< SCU PMCON0: PD (Bit 2)                                */
#define SCU_PMCON0_PD_Msk                 (0x4UL)                   /*!< SCU PMCON0: PD (Bitfield-Mask: 0x01)                  */
#define SCU_PMCON0_SL_Pos                 (1UL)                     /*!< SCU PMCON0: SL (Bit 1)                                */
#define SCU_PMCON0_SL_Msk                 (0x2UL)                   /*!< SCU PMCON0: SL (Bitfield-Mask: 0x01)                  */
#define SCU_PMCON0_XTAL_ON_Pos            (0UL)                     /*!< SCU PMCON0: XTAL_ON (Bit 0)                           */
#define SCU_PMCON0_XTAL_ON_Msk            (0x1UL)                   /*!< SCU PMCON0: XTAL_ON (Bitfield-Mask: 0x01)             */
/* =========================================================  IEN0  ========================================================== */
#define SCU_IEN0_EA_Pos                   (31UL)                    /*!< SCU IEN0: EA (Bit 31)                                 */
#define SCU_IEN0_EA_Msk                   (0x80000000UL)            /*!< SCU IEN0: EA (Bitfield-Mask: 0x01)                    */
/* =========================================================  VTOR  ========================================================== */
#define SCU_VTOR_VTOR_BYP_Pos             (0UL)                     /*!< SCU VTOR: VTOR_BYP (Bit 0)                            */
#define SCU_VTOR_VTOR_BYP_Msk             (0x3UL)                   /*!< SCU VTOR: VTOR_BYP (Bitfield-Mask: 0x03)              */
/* ========================================================  NMICON  ========================================================= */
#define SCU_NMICON_NMISUP_Pos             (7UL)                     /*!< SCU NMICON: NMISUP (Bit 7)                            */
#define SCU_NMICON_NMISUP_Msk             (0x80UL)                  /*!< SCU NMICON: NMISUP (Bitfield-Mask: 0x01)              */
#define SCU_NMICON_NMIECC_Pos             (6UL)                     /*!< SCU NMICON: NMIECC (Bit 6)                            */
#define SCU_NMICON_NMIECC_Msk             (0x40UL)                  /*!< SCU NMICON: NMIECC (Bitfield-Mask: 0x01)              */
#define SCU_NMICON_NMIMAP_Pos             (5UL)                     /*!< SCU NMICON: NMIMAP (Bit 5)                            */
#define SCU_NMICON_NMIMAP_Msk             (0x20UL)                  /*!< SCU NMICON: NMIMAP (Bitfield-Mask: 0x01)              */
#define SCU_NMICON_NMIOWD_Pos             (4UL)                     /*!< SCU NMICON: NMIOWD (Bit 4)                            */
#define SCU_NMICON_NMIOWD_Msk             (0x10UL)                  /*!< SCU NMICON: NMIOWD (Bitfield-Mask: 0x01)              */
#define SCU_NMICON_NMIOT_Pos              (3UL)                     /*!< SCU NMICON: NMIOT (Bit 3)                             */
#define SCU_NMICON_NMIOT_Msk              (0x8UL)                   /*!< SCU NMICON: NMIOT (Bitfield-Mask: 0x01)               */
#define SCU_NMICON_NMINVM_Pos             (2UL)                     /*!< SCU NMICON: NMINVM (Bit 2)                            */
#define SCU_NMICON_NMINVM_Msk             (0x4UL)                   /*!< SCU NMICON: NMINVM (Bitfield-Mask: 0x01)              */
#define SCU_NMICON_NMIPLL_Pos             (1UL)                     /*!< SCU NMICON: NMIPLL (Bit 1)                            */
#define SCU_NMICON_NMIPLL_Msk             (0x2UL)                   /*!< SCU NMICON: NMIPLL (Bitfield-Mask: 0x01)              */
/* ========================================================  EXICON0  ======================================================== */
#define SCU_EXICON0_EXINT2_Pos            (4UL)                     /*!< SCU EXICON0: EXINT2 (Bit 4)                           */
#define SCU_EXICON0_EXINT2_Msk            (0x30UL)                  /*!< SCU EXICON0: EXINT2 (Bitfield-Mask: 0x03)             */
#define SCU_EXICON0_EXINT1_Pos            (2UL)                     /*!< SCU EXICON0: EXINT1 (Bit 2)                           */
#define SCU_EXICON0_EXINT1_Msk            (0xcUL)                   /*!< SCU EXICON0: EXINT1 (Bitfield-Mask: 0x03)             */
#define SCU_EXICON0_EXINT0_Pos            (0UL)                     /*!< SCU EXICON0: EXINT0 (Bit 0)                           */
#define SCU_EXICON0_EXINT0_Msk            (0x3UL)                   /*!< SCU EXICON0: EXINT0 (Bitfield-Mask: 0x03)             */
/* ========================================================  EXICON1  ======================================================== */
#define SCU_EXICON1_MON5_Pos              (8UL)                     /*!< SCU EXICON1: MON5 (Bit 8)                             */
#define SCU_EXICON1_MON5_Msk              (0x300UL)                 /*!< SCU EXICON1: MON5 (Bitfield-Mask: 0x03)               */
#define SCU_EXICON1_MON4_Pos              (6UL)                     /*!< SCU EXICON1: MON4 (Bit 6)                             */
#define SCU_EXICON1_MON4_Msk              (0xc0UL)                  /*!< SCU EXICON1: MON4 (Bitfield-Mask: 0x03)               */
#define SCU_EXICON1_MON3_Pos              (4UL)                     /*!< SCU EXICON1: MON3 (Bit 4)                             */
#define SCU_EXICON1_MON3_Msk              (0x30UL)                  /*!< SCU EXICON1: MON3 (Bitfield-Mask: 0x03)               */
#define SCU_EXICON1_MON2_Pos              (2UL)                     /*!< SCU EXICON1: MON2 (Bit 2)                             */
#define SCU_EXICON1_MON2_Msk              (0xcUL)                   /*!< SCU EXICON1: MON2 (Bitfield-Mask: 0x03)               */
#define SCU_EXICON1_MON1_Pos              (0UL)                     /*!< SCU EXICON1: MON1 (Bit 0)                             */
#define SCU_EXICON1_MON1_Msk              (0x3UL)                   /*!< SCU EXICON1: MON1 (Bitfield-Mask: 0x03)               */
/* ========================================================  WAKECON  ======================================================== */
#define SCU_WAKECON_WAKEUPEN_Pos          (0UL)                     /*!< SCU WAKECON: WAKEUPEN (Bit 0)                         */
#define SCU_WAKECON_WAKEUPEN_Msk          (0x1UL)                   /*!< SCU WAKECON: WAKEUPEN (Bitfield-Mask: 0x01)           */
/* ========================================================  IRCON0  ========================================================= */
#define SCU_IRCON0_EXINT2F_Pos            (5UL)                     /*!< SCU IRCON0: EXINT2F (Bit 5)                           */
#define SCU_IRCON0_EXINT2F_Msk            (0x20UL)                  /*!< SCU IRCON0: EXINT2F (Bitfield-Mask: 0x01)             */
#define SCU_IRCON0_EXINT2R_Pos            (4UL)                     /*!< SCU IRCON0: EXINT2R (Bit 4)                           */
#define SCU_IRCON0_EXINT2R_Msk            (0x10UL)                  /*!< SCU IRCON0: EXINT2R (Bitfield-Mask: 0x01)             */
#define SCU_IRCON0_EXINT1F_Pos            (3UL)                     /*!< SCU IRCON0: EXINT1F (Bit 3)                           */
#define SCU_IRCON0_EXINT1F_Msk            (0x8UL)                   /*!< SCU IRCON0: EXINT1F (Bitfield-Mask: 0x01)             */
#define SCU_IRCON0_EXINT1R_Pos            (2UL)                     /*!< SCU IRCON0: EXINT1R (Bit 2)                           */
#define SCU_IRCON0_EXINT1R_Msk            (0x4UL)                   /*!< SCU IRCON0: EXINT1R (Bitfield-Mask: 0x01)             */
#define SCU_IRCON0_EXINT0F_Pos            (1UL)                     /*!< SCU IRCON0: EXINT0F (Bit 1)                           */
#define SCU_IRCON0_EXINT0F_Msk            (0x2UL)                   /*!< SCU IRCON0: EXINT0F (Bitfield-Mask: 0x01)             */
#define SCU_IRCON0_EXINT0R_Pos            (0UL)                     /*!< SCU IRCON0: EXINT0R (Bit 0)                           */
#define SCU_IRCON0_EXINT0R_Msk            (0x1UL)                   /*!< SCU IRCON0: EXINT0R (Bitfield-Mask: 0x01)             */
/* =======================================================  IRCON0CLR  ======================================================= */
#define SCU_IRCON0CLR_EXINT2FC_Pos        (5UL)                     /*!< SCU IRCON0CLR: EXINT2FC (Bit 5)                       */
#define SCU_IRCON0CLR_EXINT2FC_Msk        (0x20UL)                  /*!< SCU IRCON0CLR: EXINT2FC (Bitfield-Mask: 0x01)         */
#define SCU_IRCON0CLR_EXINT2RC_Pos        (4UL)                     /*!< SCU IRCON0CLR: EXINT2RC (Bit 4)                       */
#define SCU_IRCON0CLR_EXINT2RC_Msk        (0x10UL)                  /*!< SCU IRCON0CLR: EXINT2RC (Bitfield-Mask: 0x01)         */
#define SCU_IRCON0CLR_EXINT1FC_Pos        (3UL)                     /*!< SCU IRCON0CLR: EXINT1FC (Bit 3)                       */
#define SCU_IRCON0CLR_EXINT1FC_Msk        (0x8UL)                   /*!< SCU IRCON0CLR: EXINT1FC (Bitfield-Mask: 0x01)         */
#define SCU_IRCON0CLR_EXINT1RC_Pos        (2UL)                     /*!< SCU IRCON0CLR: EXINT1RC (Bit 2)                       */
#define SCU_IRCON0CLR_EXINT1RC_Msk        (0x4UL)                   /*!< SCU IRCON0CLR: EXINT1RC (Bitfield-Mask: 0x01)         */
#define SCU_IRCON0CLR_EXINT0FC_Pos        (1UL)                     /*!< SCU IRCON0CLR: EXINT0FC (Bit 1)                       */
#define SCU_IRCON0CLR_EXINT0FC_Msk        (0x2UL)                   /*!< SCU IRCON0CLR: EXINT0FC (Bitfield-Mask: 0x01)         */
#define SCU_IRCON0CLR_EXINT0RC_Pos        (0UL)                     /*!< SCU IRCON0CLR: EXINT0RC (Bit 0)                       */
#define SCU_IRCON0CLR_EXINT0RC_Msk        (0x1UL)                   /*!< SCU IRCON0CLR: EXINT0RC (Bitfield-Mask: 0x01)         */
/* ========================================================  IRCON1  ========================================================= */
#define SCU_IRCON1_MON5F_Pos              (9UL)                     /*!< SCU IRCON1: MON5F (Bit 9)                             */
#define SCU_IRCON1_MON5F_Msk              (0x200UL)                 /*!< SCU IRCON1: MON5F (Bitfield-Mask: 0x01)               */
#define SCU_IRCON1_MON5R_Pos              (8UL)                     /*!< SCU IRCON1: MON5R (Bit 8)                             */
#define SCU_IRCON1_MON5R_Msk              (0x100UL)                 /*!< SCU IRCON1: MON5R (Bitfield-Mask: 0x01)               */
#define SCU_IRCON1_MON4F_Pos              (7UL)                     /*!< SCU IRCON1: MON4F (Bit 7)                             */
#define SCU_IRCON1_MON4F_Msk              (0x80UL)                  /*!< SCU IRCON1: MON4F (Bitfield-Mask: 0x01)               */
#define SCU_IRCON1_MON4R_Pos              (6UL)                     /*!< SCU IRCON1: MON4R (Bit 6)                             */
#define SCU_IRCON1_MON4R_Msk              (0x40UL)                  /*!< SCU IRCON1: MON4R (Bitfield-Mask: 0x01)               */
#define SCU_IRCON1_MON3F_Pos              (5UL)                     /*!< SCU IRCON1: MON3F (Bit 5)                             */
#define SCU_IRCON1_MON3F_Msk              (0x20UL)                  /*!< SCU IRCON1: MON3F (Bitfield-Mask: 0x01)               */
#define SCU_IRCON1_MON3R_Pos              (4UL)                     /*!< SCU IRCON1: MON3R (Bit 4)                             */
#define SCU_IRCON1_MON3R_Msk              (0x10UL)                  /*!< SCU IRCON1: MON3R (Bitfield-Mask: 0x01)               */
#define SCU_IRCON1_MON2F_Pos              (3UL)                     /*!< SCU IRCON1: MON2F (Bit 3)                             */
#define SCU_IRCON1_MON2F_Msk              (0x8UL)                   /*!< SCU IRCON1: MON2F (Bitfield-Mask: 0x01)               */
#define SCU_IRCON1_MON2R_Pos              (2UL)                     /*!< SCU IRCON1: MON2R (Bit 2)                             */
#define SCU_IRCON1_MON2R_Msk              (0x4UL)                   /*!< SCU IRCON1: MON2R (Bitfield-Mask: 0x01)               */
#define SCU_IRCON1_MON1F_Pos              (1UL)                     /*!< SCU IRCON1: MON1F (Bit 1)                             */
#define SCU_IRCON1_MON1F_Msk              (0x2UL)                   /*!< SCU IRCON1: MON1F (Bitfield-Mask: 0x01)               */
#define SCU_IRCON1_MON1R_Pos              (0UL)                     /*!< SCU IRCON1: MON1R (Bit 0)                             */
#define SCU_IRCON1_MON1R_Msk              (0x1UL)                   /*!< SCU IRCON1: MON1R (Bitfield-Mask: 0x01)               */
/* =======================================================  IRCON1CLR  ======================================================= */
#define SCU_IRCON1CLR_MON5FC_Pos          (9UL)                     /*!< SCU IRCON1CLR: MON5FC (Bit 9)                         */
#define SCU_IRCON1CLR_MON5FC_Msk          (0x200UL)                 /*!< SCU IRCON1CLR: MON5FC (Bitfield-Mask: 0x01)           */
#define SCU_IRCON1CLR_MON5RC_Pos          (8UL)                     /*!< SCU IRCON1CLR: MON5RC (Bit 8)                         */
#define SCU_IRCON1CLR_MON5RC_Msk          (0x100UL)                 /*!< SCU IRCON1CLR: MON5RC (Bitfield-Mask: 0x01)           */
#define SCU_IRCON1CLR_MON4FC_Pos          (7UL)                     /*!< SCU IRCON1CLR: MON4FC (Bit 7)                         */
#define SCU_IRCON1CLR_MON4FC_Msk          (0x80UL)                  /*!< SCU IRCON1CLR: MON4FC (Bitfield-Mask: 0x01)           */
#define SCU_IRCON1CLR_MON4RC_Pos          (6UL)                     /*!< SCU IRCON1CLR: MON4RC (Bit 6)                         */
#define SCU_IRCON1CLR_MON4RC_Msk          (0x40UL)                  /*!< SCU IRCON1CLR: MON4RC (Bitfield-Mask: 0x01)           */
#define SCU_IRCON1CLR_MON3FC_Pos          (5UL)                     /*!< SCU IRCON1CLR: MON3FC (Bit 5)                         */
#define SCU_IRCON1CLR_MON3FC_Msk          (0x20UL)                  /*!< SCU IRCON1CLR: MON3FC (Bitfield-Mask: 0x01)           */
#define SCU_IRCON1CLR_MON3RC_Pos          (4UL)                     /*!< SCU IRCON1CLR: MON3RC (Bit 4)                         */
#define SCU_IRCON1CLR_MON3RC_Msk          (0x10UL)                  /*!< SCU IRCON1CLR: MON3RC (Bitfield-Mask: 0x01)           */
#define SCU_IRCON1CLR_MON2FC_Pos          (3UL)                     /*!< SCU IRCON1CLR: MON2FC (Bit 3)                         */
#define SCU_IRCON1CLR_MON2FC_Msk          (0x8UL)                   /*!< SCU IRCON1CLR: MON2FC (Bitfield-Mask: 0x01)           */
#define SCU_IRCON1CLR_MON2RC_Pos          (2UL)                     /*!< SCU IRCON1CLR: MON2RC (Bit 2)                         */
#define SCU_IRCON1CLR_MON2RC_Msk          (0x4UL)                   /*!< SCU IRCON1CLR: MON2RC (Bitfield-Mask: 0x01)           */
#define SCU_IRCON1CLR_MON1FC_Pos          (1UL)                     /*!< SCU IRCON1CLR: MON1FC (Bit 1)                         */
#define SCU_IRCON1CLR_MON1FC_Msk          (0x2UL)                   /*!< SCU IRCON1CLR: MON1FC (Bitfield-Mask: 0x01)           */
#define SCU_IRCON1CLR_MON1RC_Pos          (0UL)                     /*!< SCU IRCON1CLR: MON1RC (Bit 0)                         */
#define SCU_IRCON1CLR_MON1RC_Msk          (0x1UL)                   /*!< SCU IRCON1CLR: MON1RC (Bitfield-Mask: 0x01)           */
/* ========================================================  IRCON2  ========================================================= */
#define SCU_IRCON2_RIR1_Pos               (2UL)                     /*!< SCU IRCON2: RIR1 (Bit 2)                              */
#define SCU_IRCON2_RIR1_Msk               (0x4UL)                   /*!< SCU IRCON2: RIR1 (Bitfield-Mask: 0x01)                */
#define SCU_IRCON2_TIR1_Pos               (1UL)                     /*!< SCU IRCON2: TIR1 (Bit 1)                              */
#define SCU_IRCON2_TIR1_Msk               (0x2UL)                   /*!< SCU IRCON2: TIR1 (Bitfield-Mask: 0x01)                */
#define SCU_IRCON2_EIR1_Pos               (0UL)                     /*!< SCU IRCON2: EIR1 (Bit 0)                              */
#define SCU_IRCON2_EIR1_Msk               (0x1UL)                   /*!< SCU IRCON2: EIR1 (Bitfield-Mask: 0x01)                */
/* =======================================================  IRCON2CLR  ======================================================= */
#define SCU_IRCON2CLR_RIR1C_Pos           (2UL)                     /*!< SCU IRCON2CLR: RIR1C (Bit 2)                          */
#define SCU_IRCON2CLR_RIR1C_Msk           (0x4UL)                   /*!< SCU IRCON2CLR: RIR1C (Bitfield-Mask: 0x01)            */
#define SCU_IRCON2CLR_TIR1C_Pos           (1UL)                     /*!< SCU IRCON2CLR: TIR1C (Bit 1)                          */
#define SCU_IRCON2CLR_TIR1C_Msk           (0x2UL)                   /*!< SCU IRCON2CLR: TIR1C (Bitfield-Mask: 0x01)            */
#define SCU_IRCON2CLR_EIR1C_Pos           (0UL)                     /*!< SCU IRCON2CLR: EIR1C (Bit 0)                          */
#define SCU_IRCON2CLR_EIR1C_Msk           (0x1UL)                   /*!< SCU IRCON2CLR: EIR1C (Bitfield-Mask: 0x01)            */
/* ========================================================  IRCON3  ========================================================= */
#define SCU_IRCON3_RIR2_Pos               (2UL)                     /*!< SCU IRCON3: RIR2 (Bit 2)                              */
#define SCU_IRCON3_RIR2_Msk               (0x4UL)                   /*!< SCU IRCON3: RIR2 (Bitfield-Mask: 0x01)                */
#define SCU_IRCON3_TIR2_Pos               (1UL)                     /*!< SCU IRCON3: TIR2 (Bit 1)                              */
#define SCU_IRCON3_TIR2_Msk               (0x2UL)                   /*!< SCU IRCON3: TIR2 (Bitfield-Mask: 0x01)                */
#define SCU_IRCON3_EIR2_Pos               (0UL)                     /*!< SCU IRCON3: EIR2 (Bit 0)                              */
#define SCU_IRCON3_EIR2_Msk               (0x1UL)                   /*!< SCU IRCON3: EIR2 (Bitfield-Mask: 0x01)                */
/* =======================================================  IRCON3CLR  ======================================================= */
#define SCU_IRCON3CLR_RIR2C_Pos           (2UL)                     /*!< SCU IRCON3CLR: RIR2C (Bit 2)                          */
#define SCU_IRCON3CLR_RIR2C_Msk           (0x4UL)                   /*!< SCU IRCON3CLR: RIR2C (Bitfield-Mask: 0x01)            */
#define SCU_IRCON3CLR_TIR2C_Pos           (1UL)                     /*!< SCU IRCON3CLR: TIR2C (Bit 1)                          */
#define SCU_IRCON3CLR_TIR2C_Msk           (0x2UL)                   /*!< SCU IRCON3CLR: TIR2C (Bitfield-Mask: 0x01)            */
#define SCU_IRCON3CLR_EIR2C_Pos           (0UL)                     /*!< SCU IRCON3CLR: EIR2C (Bit 0)                          */
#define SCU_IRCON3CLR_EIR2C_Msk           (0x1UL)                   /*!< SCU IRCON3CLR: EIR2C (Bitfield-Mask: 0x01)            */
/* ========================================================  IRCON4  ========================================================= */
#define SCU_IRCON4_CCU6SR3_Pos            (20UL)                    /*!< SCU IRCON4: CCU6SR3 (Bit 20)                          */
#define SCU_IRCON4_CCU6SR3_Msk            (0x100000UL)              /*!< SCU IRCON4: CCU6SR3 (Bitfield-Mask: 0x01)             */
#define SCU_IRCON4_CCU6SR2_Pos            (16UL)                    /*!< SCU IRCON4: CCU6SR2 (Bit 16)                          */
#define SCU_IRCON4_CCU6SR2_Msk            (0x10000UL)               /*!< SCU IRCON4: CCU6SR2 (Bitfield-Mask: 0x01)             */
#define SCU_IRCON4_CCU6SR1_Pos            (4UL)                     /*!< SCU IRCON4: CCU6SR1 (Bit 4)                           */
#define SCU_IRCON4_CCU6SR1_Msk            (0x10UL)                  /*!< SCU IRCON4: CCU6SR1 (Bitfield-Mask: 0x01)             */
#define SCU_IRCON4_CCU6SR0_Pos            (0UL)                     /*!< SCU IRCON4: CCU6SR0 (Bit 0)                           */
#define SCU_IRCON4_CCU6SR0_Msk            (0x1UL)                   /*!< SCU IRCON4: CCU6SR0 (Bitfield-Mask: 0x01)             */
/* =======================================================  IRCON4CLR  ======================================================= */
#define SCU_IRCON4CLR_CCU6SR3C_Pos        (20UL)                    /*!< SCU IRCON4CLR: CCU6SR3C (Bit 20)                      */
#define SCU_IRCON4CLR_CCU6SR3C_Msk        (0x100000UL)              /*!< SCU IRCON4CLR: CCU6SR3C (Bitfield-Mask: 0x01)         */
#define SCU_IRCON4CLR_CCU6SR2C_Pos        (16UL)                    /*!< SCU IRCON4CLR: CCU6SR2C (Bit 16)                      */
#define SCU_IRCON4CLR_CCU6SR2C_Msk        (0x10000UL)               /*!< SCU IRCON4CLR: CCU6SR2C (Bitfield-Mask: 0x01)         */
#define SCU_IRCON4CLR_CCU6SR1C_Pos        (4UL)                     /*!< SCU IRCON4CLR: CCU6SR1C (Bit 4)                       */
#define SCU_IRCON4CLR_CCU6SR1C_Msk        (0x10UL)                  /*!< SCU IRCON4CLR: CCU6SR1C (Bitfield-Mask: 0x01)         */
#define SCU_IRCON4CLR_CCU6SR0C_Pos        (0UL)                     /*!< SCU IRCON4CLR: CCU6SR0C (Bit 0)                       */
#define SCU_IRCON4CLR_CCU6SR0C_Msk        (0x1UL)                   /*!< SCU IRCON4CLR: CCU6SR0C (Bitfield-Mask: 0x01)         */
/* ========================================================  IRCON5  ========================================================= */
#define SCU_IRCON5_WAKEUP_Pos             (0UL)                     /*!< SCU IRCON5: WAKEUP (Bit 0)                            */
#define SCU_IRCON5_WAKEUP_Msk             (0x1UL)                   /*!< SCU IRCON5: WAKEUP (Bitfield-Mask: 0x01)              */
/* =======================================================  IRCON5CLR  ======================================================= */
#define SCU_IRCON5CLR_WAKEUPC_Pos         (0UL)                     /*!< SCU IRCON5CLR: WAKEUPC (Bit 0)                        */
#define SCU_IRCON5CLR_WAKEUPC_Msk         (0x1UL)                   /*!< SCU IRCON5CLR: WAKEUPC (Bitfield-Mask: 0x01)          */
/* =======================================================  GPT12IRC  ======================================================== */
#define SCU_GPT12IRC_GPT12CR_Pos          (5UL)                     /*!< SCU GPT12IRC: GPT12CR (Bit 5)                         */
#define SCU_GPT12IRC_GPT12CR_Msk          (0x20UL)                  /*!< SCU GPT12IRC: GPT12CR (Bitfield-Mask: 0x01)           */
#define SCU_GPT12IRC_GPT2T6_Pos           (4UL)                     /*!< SCU GPT12IRC: GPT2T6 (Bit 4)                          */
#define SCU_GPT12IRC_GPT2T6_Msk           (0x10UL)                  /*!< SCU GPT12IRC: GPT2T6 (Bitfield-Mask: 0x01)            */
#define SCU_GPT12IRC_GPT2T5_Pos           (3UL)                     /*!< SCU GPT12IRC: GPT2T5 (Bit 3)                          */
#define SCU_GPT12IRC_GPT2T5_Msk           (0x8UL)                   /*!< SCU GPT12IRC: GPT2T5 (Bitfield-Mask: 0x01)            */
#define SCU_GPT12IRC_GPT1T4_Pos           (2UL)                     /*!< SCU GPT12IRC: GPT1T4 (Bit 2)                          */
#define SCU_GPT12IRC_GPT1T4_Msk           (0x4UL)                   /*!< SCU GPT12IRC: GPT1T4 (Bitfield-Mask: 0x01)            */
#define SCU_GPT12IRC_GPT1T3_Pos           (1UL)                     /*!< SCU GPT12IRC: GPT1T3 (Bit 1)                          */
#define SCU_GPT12IRC_GPT1T3_Msk           (0x2UL)                   /*!< SCU GPT12IRC: GPT1T3 (Bitfield-Mask: 0x01)            */
#define SCU_GPT12IRC_GPT1T2_Pos           (0UL)                     /*!< SCU GPT12IRC: GPT1T2 (Bit 0)                          */
#define SCU_GPT12IRC_GPT1T2_Msk           (0x1UL)                   /*!< SCU GPT12IRC: GPT1T2 (Bitfield-Mask: 0x01)            */
/* =======================================================  GPT12ICLR  ======================================================= */
#define SCU_GPT12ICLR_GPT12CRC_Pos        (5UL)                     /*!< SCU GPT12ICLR: GPT12CRC (Bit 5)                       */
#define SCU_GPT12ICLR_GPT12CRC_Msk        (0x20UL)                  /*!< SCU GPT12ICLR: GPT12CRC (Bitfield-Mask: 0x01)         */
#define SCU_GPT12ICLR_GPT2T6C_Pos         (4UL)                     /*!< SCU GPT12ICLR: GPT2T6C (Bit 4)                        */
#define SCU_GPT12ICLR_GPT2T6C_Msk         (0x10UL)                  /*!< SCU GPT12ICLR: GPT2T6C (Bitfield-Mask: 0x01)          */
#define SCU_GPT12ICLR_GPT2T5C_Pos         (3UL)                     /*!< SCU GPT12ICLR: GPT2T5C (Bit 3)                        */
#define SCU_GPT12ICLR_GPT2T5C_Msk         (0x8UL)                   /*!< SCU GPT12ICLR: GPT2T5C (Bitfield-Mask: 0x01)          */
#define SCU_GPT12ICLR_GPT1T4C_Pos         (2UL)                     /*!< SCU GPT12ICLR: GPT1T4C (Bit 2)                        */
#define SCU_GPT12ICLR_GPT1T4C_Msk         (0x4UL)                   /*!< SCU GPT12ICLR: GPT1T4C (Bitfield-Mask: 0x01)          */
#define SCU_GPT12ICLR_GPT1T3C_Pos         (1UL)                     /*!< SCU GPT12ICLR: GPT1T3C (Bit 1)                        */
#define SCU_GPT12ICLR_GPT1T3C_Msk         (0x2UL)                   /*!< SCU GPT12ICLR: GPT1T3C (Bitfield-Mask: 0x01)          */
#define SCU_GPT12ICLR_GPT1T2C_Pos         (0UL)                     /*!< SCU GPT12ICLR: GPT1T2C (Bit 0)                        */
#define SCU_GPT12ICLR_GPT1T2C_Msk         (0x1UL)                   /*!< SCU GPT12ICLR: GPT1T2C (Bitfield-Mask: 0x01)          */
/* =========================================================  NMISR  ========================================================= */
#define SCU_NMISR_FNMISUP_Pos             (7UL)                     /*!< SCU NMISR: FNMISUP (Bit 7)                            */
#define SCU_NMISR_FNMISUP_Msk             (0x80UL)                  /*!< SCU NMISR: FNMISUP (Bitfield-Mask: 0x01)              */
#define SCU_NMISR_FNMIECC_Pos             (6UL)                     /*!< SCU NMISR: FNMIECC (Bit 6)                            */
#define SCU_NMISR_FNMIECC_Msk             (0x40UL)                  /*!< SCU NMISR: FNMIECC (Bitfield-Mask: 0x01)              */
#define SCU_NMISR_FNMIMAP_Pos             (5UL)                     /*!< SCU NMISR: FNMIMAP (Bit 5)                            */
#define SCU_NMISR_FNMIMAP_Msk             (0x20UL)                  /*!< SCU NMISR: FNMIMAP (Bitfield-Mask: 0x01)              */
#define SCU_NMISR_FNMIOWD_Pos             (4UL)                     /*!< SCU NMISR: FNMIOWD (Bit 4)                            */
#define SCU_NMISR_FNMIOWD_Msk             (0x10UL)                  /*!< SCU NMISR: FNMIOWD (Bitfield-Mask: 0x01)              */
#define SCU_NMISR_FNMIOT_Pos              (3UL)                     /*!< SCU NMISR: FNMIOT (Bit 3)                             */
#define SCU_NMISR_FNMIOT_Msk              (0x8UL)                   /*!< SCU NMISR: FNMIOT (Bitfield-Mask: 0x01)               */
#define SCU_NMISR_FNMINVM_Pos             (2UL)                     /*!< SCU NMISR: FNMINVM (Bit 2)                            */
#define SCU_NMISR_FNMINVM_Msk             (0x4UL)                   /*!< SCU NMISR: FNMINVM (Bitfield-Mask: 0x01)              */
#define SCU_NMISR_FNMIPLL_Pos             (1UL)                     /*!< SCU NMISR: FNMIPLL (Bit 1)                            */
#define SCU_NMISR_FNMIPLL_Msk             (0x2UL)                   /*!< SCU NMISR: FNMIPLL (Bitfield-Mask: 0x01)              */
/* =======================================================  NMISRCLR  ======================================================== */
#define SCU_NMISRCLR_FNMISUPC_Pos         (7UL)                     /*!< SCU NMISRCLR: FNMISUPC (Bit 7)                        */
#define SCU_NMISRCLR_FNMISUPC_Msk         (0x80UL)                  /*!< SCU NMISRCLR: FNMISUPC (Bitfield-Mask: 0x01)          */
#define SCU_NMISRCLR_FNMIECCC_Pos         (6UL)                     /*!< SCU NMISRCLR: FNMIECCC (Bit 6)                        */
#define SCU_NMISRCLR_FNMIECCC_Msk         (0x40UL)                  /*!< SCU NMISRCLR: FNMIECCC (Bitfield-Mask: 0x01)          */
#define SCU_NMISRCLR_FNMIMAPC_Pos         (5UL)                     /*!< SCU NMISRCLR: FNMIMAPC (Bit 5)                        */
#define SCU_NMISRCLR_FNMIMAPC_Msk         (0x20UL)                  /*!< SCU NMISRCLR: FNMIMAPC (Bitfield-Mask: 0x01)          */
#define SCU_NMISRCLR_FNMIOWDC_Pos         (4UL)                     /*!< SCU NMISRCLR: FNMIOWDC (Bit 4)                        */
#define SCU_NMISRCLR_FNMIOWDC_Msk         (0x10UL)                  /*!< SCU NMISRCLR: FNMIOWDC (Bitfield-Mask: 0x01)          */
#define SCU_NMISRCLR_FNMIOTC_Pos          (3UL)                     /*!< SCU NMISRCLR: FNMIOTC (Bit 3)                         */
#define SCU_NMISRCLR_FNMIOTC_Msk          (0x8UL)                   /*!< SCU NMISRCLR: FNMIOTC (Bitfield-Mask: 0x01)           */
#define SCU_NMISRCLR_FNMINVMC_Pos         (2UL)                     /*!< SCU NMISRCLR: FNMINVMC (Bit 2)                        */
#define SCU_NMISRCLR_FNMINVMC_Msk         (0x4UL)                   /*!< SCU NMISRCLR: FNMINVMC (Bitfield-Mask: 0x01)          */
#define SCU_NMISRCLR_FNMIPLLC_Pos         (1UL)                     /*!< SCU NMISRCLR: FNMIPLLC (Bit 1)                        */
#define SCU_NMISRCLR_FNMIPLLC_Msk         (0x2UL)                   /*!< SCU NMISRCLR: FNMIPLLC (Bitfield-Mask: 0x01)          */
/* ========================================================  MODIEN1  ======================================================== */
#define SCU_MODIEN1_RIREN2_Pos            (10UL)                    /*!< SCU MODIEN1: RIREN2 (Bit 10)                          */
#define SCU_MODIEN1_RIREN2_Msk            (0x400UL)                 /*!< SCU MODIEN1: RIREN2 (Bitfield-Mask: 0x01)             */
#define SCU_MODIEN1_TIREN2_Pos            (9UL)                     /*!< SCU MODIEN1: TIREN2 (Bit 9)                           */
#define SCU_MODIEN1_TIREN2_Msk            (0x200UL)                 /*!< SCU MODIEN1: TIREN2 (Bitfield-Mask: 0x01)             */
#define SCU_MODIEN1_EIREN2_Pos            (8UL)                     /*!< SCU MODIEN1: EIREN2 (Bit 8)                           */
#define SCU_MODIEN1_EIREN2_Msk            (0x100UL)                 /*!< SCU MODIEN1: EIREN2 (Bitfield-Mask: 0x01)             */
#define SCU_MODIEN1_RIREN1_Pos            (2UL)                     /*!< SCU MODIEN1: RIREN1 (Bit 2)                           */
#define SCU_MODIEN1_RIREN1_Msk            (0x4UL)                   /*!< SCU MODIEN1: RIREN1 (Bitfield-Mask: 0x01)             */
#define SCU_MODIEN1_TIREN1_Pos            (1UL)                     /*!< SCU MODIEN1: TIREN1 (Bit 1)                           */
#define SCU_MODIEN1_TIREN1_Msk            (0x2UL)                   /*!< SCU MODIEN1: TIREN1 (Bitfield-Mask: 0x01)             */
#define SCU_MODIEN1_EIREN1_Pos            (0UL)                     /*!< SCU MODIEN1: EIREN1 (Bit 0)                           */
#define SCU_MODIEN1_EIREN1_Msk            (0x1UL)                   /*!< SCU MODIEN1: EIREN1 (Bitfield-Mask: 0x01)             */
/* ========================================================  MODIEN2  ======================================================== */
#define SCU_MODIEN2_TIEN2_Pos             (7UL)                     /*!< SCU MODIEN2: TIEN2 (Bit 7)                            */
#define SCU_MODIEN2_TIEN2_Msk             (0x80UL)                  /*!< SCU MODIEN2: TIEN2 (Bitfield-Mask: 0x01)              */
#define SCU_MODIEN2_RIEN2_Pos             (6UL)                     /*!< SCU MODIEN2: RIEN2 (Bit 6)                            */
#define SCU_MODIEN2_RIEN2_Msk             (0x40UL)                  /*!< SCU MODIEN2: RIEN2 (Bitfield-Mask: 0x01)              */
#define SCU_MODIEN2_EXINT2_EN_Pos         (5UL)                     /*!< SCU MODIEN2: EXINT2_EN (Bit 5)                        */
#define SCU_MODIEN2_EXINT2_EN_Msk         (0x20UL)                  /*!< SCU MODIEN2: EXINT2_EN (Bitfield-Mask: 0x01)          */
#define SCU_MODIEN2_TIEN1_Pos             (1UL)                     /*!< SCU MODIEN2: TIEN1 (Bit 1)                            */
#define SCU_MODIEN2_TIEN1_Msk             (0x2UL)                   /*!< SCU MODIEN2: TIEN1 (Bitfield-Mask: 0x01)              */
#define SCU_MODIEN2_RIEN1_Pos             (0UL)                     /*!< SCU MODIEN2: RIEN1 (Bit 0)                            */
#define SCU_MODIEN2_RIEN1_Msk             (0x1UL)                   /*!< SCU MODIEN2: RIEN1 (Bitfield-Mask: 0x01)              */
/* ========================================================  MODIEN3  ======================================================== */
#define SCU_MODIEN3_IE0_Pos               (0UL)                     /*!< SCU MODIEN3: IE0 (Bit 0)                              */
#define SCU_MODIEN3_IE0_Msk               (0x1UL)                   /*!< SCU MODIEN3: IE0 (Bitfield-Mask: 0x01)                */
/* ========================================================  MODIEN4  ======================================================== */
#define SCU_MODIEN4_IE1_Pos               (0UL)                     /*!< SCU MODIEN4: IE1 (Bit 0)                              */
#define SCU_MODIEN4_IE1_Msk               (0x1UL)                   /*!< SCU MODIEN4: IE1 (Bitfield-Mask: 0x01)                */
/* ========================================================  MONIEN  ========================================================= */
#define SCU_MONIEN_MON5IE_Pos             (4UL)                     /*!< SCU MONIEN: MON5IE (Bit 4)                            */
#define SCU_MONIEN_MON5IE_Msk             (0x10UL)                  /*!< SCU MONIEN: MON5IE (Bitfield-Mask: 0x01)              */
#define SCU_MONIEN_MON4IE_Pos             (3UL)                     /*!< SCU MONIEN: MON4IE (Bit 3)                            */
#define SCU_MONIEN_MON4IE_Msk             (0x8UL)                   /*!< SCU MONIEN: MON4IE (Bitfield-Mask: 0x01)              */
#define SCU_MONIEN_MON3IE_Pos             (2UL)                     /*!< SCU MONIEN: MON3IE (Bit 2)                            */
#define SCU_MONIEN_MON3IE_Msk             (0x4UL)                   /*!< SCU MONIEN: MON3IE (Bitfield-Mask: 0x01)              */
#define SCU_MONIEN_MON2IE_Pos             (1UL)                     /*!< SCU MONIEN: MON2IE (Bit 1)                            */
#define SCU_MONIEN_MON2IE_Msk             (0x2UL)                   /*!< SCU MONIEN: MON2IE (Bitfield-Mask: 0x01)              */
#define SCU_MONIEN_MON1IE_Pos             (0UL)                     /*!< SCU MONIEN: MON1IE (Bit 0)                            */
#define SCU_MONIEN_MON1IE_Msk             (0x1UL)                   /*!< SCU MONIEN: MON1IE (Bitfield-Mask: 0x01)              */
/* =======================================================  GPT12IEN  ======================================================== */
#define SCU_GPT12IEN_CRIE_Pos             (5UL)                     /*!< SCU GPT12IEN: CRIE (Bit 5)                            */
#define SCU_GPT12IEN_CRIE_Msk             (0x20UL)                  /*!< SCU GPT12IEN: CRIE (Bitfield-Mask: 0x01)              */
#define SCU_GPT12IEN_T6IE_Pos             (4UL)                     /*!< SCU GPT12IEN: T6IE (Bit 4)                            */
#define SCU_GPT12IEN_T6IE_Msk             (0x10UL)                  /*!< SCU GPT12IEN: T6IE (Bitfield-Mask: 0x01)              */
#define SCU_GPT12IEN_T5IE_Pos             (3UL)                     /*!< SCU GPT12IEN: T5IE (Bit 3)                            */
#define SCU_GPT12IEN_T5IE_Msk             (0x8UL)                   /*!< SCU GPT12IEN: T5IE (Bitfield-Mask: 0x01)              */
#define SCU_GPT12IEN_T4IE_Pos             (2UL)                     /*!< SCU GPT12IEN: T4IE (Bit 2)                            */
#define SCU_GPT12IEN_T4IE_Msk             (0x4UL)                   /*!< SCU GPT12IEN: T4IE (Bitfield-Mask: 0x01)              */
#define SCU_GPT12IEN_T3IE_Pos             (1UL)                     /*!< SCU GPT12IEN: T3IE (Bit 1)                            */
#define SCU_GPT12IEN_T3IE_Msk             (0x2UL)                   /*!< SCU GPT12IEN: T3IE (Bitfield-Mask: 0x01)              */
#define SCU_GPT12IEN_T2IE_Pos             (0UL)                     /*!< SCU GPT12IEN: T2IE (Bit 0)                            */
#define SCU_GPT12IEN_T2IE_Msk             (0x1UL)                   /*!< SCU GPT12IEN: T2IE (Bitfield-Mask: 0x01)              */
/* =======================================================  MODPISEL  ======================================================== */
#define SCU_MODPISEL_SSC12_S_MRST_OUTSEL_Pos (18UL)                 /*!< SCU MODPISEL: SSC12_S_MRST_OUTSEL (Bit 18)            */
#define SCU_MODPISEL_SSC12_S_MRST_OUTSEL_Msk (0x40000UL)            /*!< SCU MODPISEL: SSC12_S_MRST_OUTSEL (Bitfield-Mask: 0x01) */
#define SCU_MODPISEL_SSC12_M_MTSR_OUTSEL_Pos (17UL)                 /*!< SCU MODPISEL: SSC12_M_MTSR_OUTSEL (Bit 17)            */
#define SCU_MODPISEL_SSC12_M_MTSR_OUTSEL_Msk (0x20000UL)            /*!< SCU MODPISEL: SSC12_M_MTSR_OUTSEL (Bitfield-Mask: 0x01) */
#define SCU_MODPISEL_SSC12_M_SCK_OUTSEL_Pos (16UL)                  /*!< SCU MODPISEL: SSC12_M_SCK_OUTSEL (Bit 16)             */
#define SCU_MODPISEL_SSC12_M_SCK_OUTSEL_Msk (0x10000UL)             /*!< SCU MODPISEL: SSC12_M_SCK_OUTSEL (Bitfield-Mask: 0x01) */
#define SCU_MODPISEL_U_TX_CONDIS_Pos      (7UL)                     /*!< SCU MODPISEL: U_TX_CONDIS (Bit 7)                     */
#define SCU_MODPISEL_U_TX_CONDIS_Msk      (0x80UL)                  /*!< SCU MODPISEL: U_TX_CONDIS (Bitfield-Mask: 0x01)       */
#define SCU_MODPISEL_URIOS1_Pos           (6UL)                     /*!< SCU MODPISEL: URIOS1 (Bit 6)                          */
#define SCU_MODPISEL_URIOS1_Msk           (0x40UL)                  /*!< SCU MODPISEL: URIOS1 (Bitfield-Mask: 0x01)            */
#define SCU_MODPISEL_EXINT2IS_Pos         (4UL)                     /*!< SCU MODPISEL: EXINT2IS (Bit 4)                        */
#define SCU_MODPISEL_EXINT2IS_Msk         (0x30UL)                  /*!< SCU MODPISEL: EXINT2IS (Bitfield-Mask: 0x03)          */
#define SCU_MODPISEL_EXINT1IS_Pos         (2UL)                     /*!< SCU MODPISEL: EXINT1IS (Bit 2)                        */
#define SCU_MODPISEL_EXINT1IS_Msk         (0xcUL)                   /*!< SCU MODPISEL: EXINT1IS (Bitfield-Mask: 0x03)          */
#define SCU_MODPISEL_EXINT0IS_Pos         (0UL)                     /*!< SCU MODPISEL: EXINT0IS (Bit 0)                        */
#define SCU_MODPISEL_EXINT0IS_Msk         (0x3UL)                   /*!< SCU MODPISEL: EXINT0IS (Bitfield-Mask: 0x03)          */
/* =======================================================  MODPISEL1  ======================================================= */
#define SCU_MODPISEL1_T21EXCON_Pos        (7UL)                     /*!< SCU MODPISEL1: T21EXCON (Bit 7)                       */
#define SCU_MODPISEL1_T21EXCON_Msk        (0x80UL)                  /*!< SCU MODPISEL1: T21EXCON (Bitfield-Mask: 0x01)         */
#define SCU_MODPISEL1_T2EXCON_Pos         (6UL)                     /*!< SCU MODPISEL1: T2EXCON (Bit 6)                        */
#define SCU_MODPISEL1_T2EXCON_Msk         (0x40UL)                  /*!< SCU MODPISEL1: T2EXCON (Bitfield-Mask: 0x01)          */
#define SCU_MODPISEL1_XTAL12EN_Pos        (0UL)                     /*!< SCU MODPISEL1: XTAL12EN (Bit 0)                       */
#define SCU_MODPISEL1_XTAL12EN_Msk        (0x1UL)                   /*!< SCU MODPISEL1: XTAL12EN (Bitfield-Mask: 0x01)         */
/* =======================================================  MODPISEL2  ======================================================= */
#define SCU_MODPISEL2_T21EXIS_Pos         (6UL)                     /*!< SCU MODPISEL2: T21EXIS (Bit 6)                        */
#define SCU_MODPISEL2_T21EXIS_Msk         (0xc0UL)                  /*!< SCU MODPISEL2: T21EXIS (Bitfield-Mask: 0x03)          */
#define SCU_MODPISEL2_T2EXIS_Pos          (4UL)                     /*!< SCU MODPISEL2: T2EXIS (Bit 4)                         */
#define SCU_MODPISEL2_T2EXIS_Msk          (0x30UL)                  /*!< SCU MODPISEL2: T2EXIS (Bitfield-Mask: 0x03)           */
#define SCU_MODPISEL2_T21IS_Pos           (2UL)                     /*!< SCU MODPISEL2: T21IS (Bit 2)                          */
#define SCU_MODPISEL2_T21IS_Msk           (0xcUL)                   /*!< SCU MODPISEL2: T21IS (Bitfield-Mask: 0x03)            */
#define SCU_MODPISEL2_T2IS_Pos            (0UL)                     /*!< SCU MODPISEL2: T2IS (Bit 0)                           */
#define SCU_MODPISEL2_T2IS_Msk            (0x3UL)                   /*!< SCU MODPISEL2: T2IS (Bitfield-Mask: 0x03)             */
/* =======================================================  MODPISEL3  ======================================================= */
#define SCU_MODPISEL3_URIOS2_Pos          (6UL)                     /*!< SCU MODPISEL3: URIOS2 (Bit 6)                         */
#define SCU_MODPISEL3_URIOS2_Msk          (0x40UL)                  /*!< SCU MODPISEL3: URIOS2 (Bitfield-Mask: 0x01)           */
/* =======================================================  P0_POCON0  ======================================================= */
#define SCU_P0_POCON0_P0_PDM5_Pos         (20UL)                    /*!< SCU P0_POCON0: P0_PDM5 (Bit 20)                       */
#define SCU_P0_POCON0_P0_PDM5_Msk         (0x700000UL)              /*!< SCU P0_POCON0: P0_PDM5 (Bitfield-Mask: 0x07)          */
#define SCU_P0_POCON0_P0_PDM4_Pos         (16UL)                    /*!< SCU P0_POCON0: P0_PDM4 (Bit 16)                       */
#define SCU_P0_POCON0_P0_PDM4_Msk         (0x70000UL)               /*!< SCU P0_POCON0: P0_PDM4 (Bitfield-Mask: 0x07)          */
#define SCU_P0_POCON0_P0_PDM3_Pos         (12UL)                    /*!< SCU P0_POCON0: P0_PDM3 (Bit 12)                       */
#define SCU_P0_POCON0_P0_PDM3_Msk         (0x7000UL)                /*!< SCU P0_POCON0: P0_PDM3 (Bitfield-Mask: 0x07)          */
#define SCU_P0_POCON0_P0_PDM2_Pos         (8UL)                     /*!< SCU P0_POCON0: P0_PDM2 (Bit 8)                        */
#define SCU_P0_POCON0_P0_PDM2_Msk         (0x700UL)                 /*!< SCU P0_POCON0: P0_PDM2 (Bitfield-Mask: 0x07)          */
#define SCU_P0_POCON0_P0_PDM1_Pos         (4UL)                     /*!< SCU P0_POCON0: P0_PDM1 (Bit 4)                        */
#define SCU_P0_POCON0_P0_PDM1_Msk         (0x70UL)                  /*!< SCU P0_POCON0: P0_PDM1 (Bitfield-Mask: 0x07)          */
#define SCU_P0_POCON0_P0_PDM0_Pos         (0UL)                     /*!< SCU P0_POCON0: P0_PDM0 (Bit 0)                        */
#define SCU_P0_POCON0_P0_PDM0_Msk         (0x7UL)                   /*!< SCU P0_POCON0: P0_PDM0 (Bitfield-Mask: 0x07)          */
/* =======================================================  P1_POCON0  ======================================================= */
#define SCU_P1_POCON0_P1_PDM4_Pos         (16UL)                    /*!< SCU P1_POCON0: P1_PDM4 (Bit 16)                       */
#define SCU_P1_POCON0_P1_PDM4_Msk         (0x70000UL)               /*!< SCU P1_POCON0: P1_PDM4 (Bitfield-Mask: 0x07)          */
#define SCU_P1_POCON0_P1_PDM2_Pos         (8UL)                     /*!< SCU P1_POCON0: P1_PDM2 (Bit 8)                        */
#define SCU_P1_POCON0_P1_PDM2_Msk         (0x700UL)                 /*!< SCU P1_POCON0: P1_PDM2 (Bitfield-Mask: 0x07)          */
#define SCU_P1_POCON0_P1_PDM1_Pos         (4UL)                     /*!< SCU P1_POCON0: P1_PDM1 (Bit 4)                        */
#define SCU_P1_POCON0_P1_PDM1_Msk         (0x70UL)                  /*!< SCU P1_POCON0: P1_PDM1 (Bitfield-Mask: 0x07)          */
#define SCU_P1_POCON0_P1_PDM0_Pos         (0UL)                     /*!< SCU P1_POCON0: P1_PDM0 (Bit 0)                        */
#define SCU_P1_POCON0_P1_PDM0_Msk         (0x7UL)                   /*!< SCU P1_POCON0: P1_PDM0 (Bitfield-Mask: 0x07)          */
/* =========================================================  TCCR  ========================================================== */
#define SCU_TCCR_TCC_Pos                  (0UL)                     /*!< SCU TCCR: TCC (Bit 0)                                 */
#define SCU_TCCR_TCC_Msk                  (0x3UL)                   /*!< SCU TCCR: TCC (Bitfield-Mask: 0x03)                   */
/* ======================================================  GPT12PISEL  ======================================================= */
#define SCU_GPT12PISEL_GPT12_SEL_Pos      (5UL)                     /*!< SCU GPT12PISEL: GPT12_SEL (Bit 5)                     */
#define SCU_GPT12PISEL_GPT12_SEL_Msk      (0x20UL)                  /*!< SCU GPT12PISEL: GPT12_SEL (Bitfield-Mask: 0x01)       */
#define SCU_GPT12PISEL_TRIG_CONF_Pos      (4UL)                     /*!< SCU GPT12PISEL: TRIG_CONF (Bit 4)                     */
#define SCU_GPT12PISEL_TRIG_CONF_Msk      (0x10UL)                  /*!< SCU GPT12PISEL: TRIG_CONF (Bitfield-Mask: 0x01)       */
#define SCU_GPT12PISEL_GPT12_Pos          (0UL)                     /*!< SCU GPT12PISEL: GPT12 (Bit 0)                         */
#define SCU_GPT12PISEL_GPT12_Msk          (0xfUL)                   /*!< SCU GPT12PISEL: GPT12 (Bitfield-Mask: 0x0f)           */
/* =======================================================  MODPISEL4  ======================================================= */
#define SCU_MODPISEL4_DU4TRIGGEN_Pos      (24UL)                    /*!< SCU MODPISEL4: DU4TRIGGEN (Bit 24)                    */
#define SCU_MODPISEL4_DU4TRIGGEN_Msk      (0x7000000UL)             /*!< SCU MODPISEL4: DU4TRIGGEN (Bitfield-Mask: 0x07)       */
#define SCU_MODPISEL4_DU3TRIGGEN_Pos      (16UL)                    /*!< SCU MODPISEL4: DU3TRIGGEN (Bit 16)                    */
#define SCU_MODPISEL4_DU3TRIGGEN_Msk      (0x70000UL)               /*!< SCU MODPISEL4: DU3TRIGGEN (Bitfield-Mask: 0x07)       */
#define SCU_MODPISEL4_DU2TRIGGEN_Pos      (8UL)                     /*!< SCU MODPISEL4: DU2TRIGGEN (Bit 8)                     */
#define SCU_MODPISEL4_DU2TRIGGEN_Msk      (0x700UL)                 /*!< SCU MODPISEL4: DU2TRIGGEN (Bitfield-Mask: 0x07)       */
#define SCU_MODPISEL4_DU1TRIGGEN_Pos      (0UL)                     /*!< SCU MODPISEL4: DU1TRIGGEN (Bit 0)                     */
#define SCU_MODPISEL4_DU1TRIGGEN_Msk      (0x7UL)                   /*!< SCU MODPISEL4: DU1TRIGGEN (Bitfield-Mask: 0x07)       */
/* =========================================================  PMCON  ========================================================= */
#define SCU_PMCON_T21_DIS_Pos             (10UL)                    /*!< SCU PMCON: T21_DIS (Bit 10)                           */
#define SCU_PMCON_T21_DIS_Msk             (0x400UL)                 /*!< SCU PMCON: T21_DIS (Bitfield-Mask: 0x01)              */
#define SCU_PMCON_SSC2_DIS_Pos            (8UL)                     /*!< SCU PMCON: SSC2_DIS (Bit 8)                           */
#define SCU_PMCON_SSC2_DIS_Msk            (0x100UL)                 /*!< SCU PMCON: SSC2_DIS (Bitfield-Mask: 0x01)             */
#define SCU_PMCON_GPT12_DIS_Pos           (4UL)                     /*!< SCU PMCON: GPT12_DIS (Bit 4)                          */
#define SCU_PMCON_GPT12_DIS_Msk           (0x10UL)                  /*!< SCU PMCON: GPT12_DIS (Bitfield-Mask: 0x01)            */
#define SCU_PMCON_T2_DIS_Pos              (3UL)                     /*!< SCU PMCON: T2_DIS (Bit 3)                             */
#define SCU_PMCON_T2_DIS_Msk              (0x8UL)                   /*!< SCU PMCON: T2_DIS (Bitfield-Mask: 0x01)               */
#define SCU_PMCON_CCU_DIS_Pos             (2UL)                     /*!< SCU PMCON: CCU_DIS (Bit 2)                            */
#define SCU_PMCON_CCU_DIS_Msk             (0x4UL)                   /*!< SCU PMCON: CCU_DIS (Bitfield-Mask: 0x01)              */
#define SCU_PMCON_SSC1_DIS_Pos            (1UL)                     /*!< SCU PMCON: SSC1_DIS (Bit 1)                           */
#define SCU_PMCON_SSC1_DIS_Msk            (0x2UL)                   /*!< SCU PMCON: SSC1_DIS (Bitfield-Mask: 0x01)             */
#define SCU_PMCON_ADC1_DIS_Pos            (0UL)                     /*!< SCU PMCON: ADC1_DIS (Bit 0)                           */
#define SCU_PMCON_ADC1_DIS_Msk            (0x1UL)                   /*!< SCU PMCON: ADC1_DIS (Bitfield-Mask: 0x01)             */
/* ========================================================  MODSUSP  ======================================================== */
#define SCU_MODSUSP_ADC1_SUSP_Pos         (10UL)                    /*!< SCU MODSUSP: ADC1_SUSP (Bit 10)                       */
#define SCU_MODSUSP_ADC1_SUSP_Msk         (0x400UL)                 /*!< SCU MODSUSP: ADC1_SUSP (Bitfield-Mask: 0x01)          */
#define SCU_MODSUSP_MU_SUSP_Pos           (9UL)                     /*!< SCU MODSUSP: MU_SUSP (Bit 9)                          */
#define SCU_MODSUSP_MU_SUSP_Msk           (0x200UL)                 /*!< SCU MODSUSP: MU_SUSP (Bitfield-Mask: 0x01)            */
#define SCU_MODSUSP_WDT1SUSP_Pos          (7UL)                     /*!< SCU MODSUSP: WDT1SUSP (Bit 7)                         */
#define SCU_MODSUSP_WDT1SUSP_Msk          (0x80UL)                  /*!< SCU MODSUSP: WDT1SUSP (Bitfield-Mask: 0x01)           */
#define SCU_MODSUSP_T21_SUSP_Pos          (6UL)                     /*!< SCU MODSUSP: T21_SUSP (Bit 6)                         */
#define SCU_MODSUSP_T21_SUSP_Msk          (0x40UL)                  /*!< SCU MODSUSP: T21_SUSP (Bitfield-Mask: 0x01)           */
#define SCU_MODSUSP_GPT12_SUSP_Pos        (4UL)                     /*!< SCU MODSUSP: GPT12_SUSP (Bit 4)                       */
#define SCU_MODSUSP_GPT12_SUSP_Msk        (0x10UL)                  /*!< SCU MODSUSP: GPT12_SUSP (Bitfield-Mask: 0x01)         */
#define SCU_MODSUSP_T2_SUSP_Pos           (3UL)                     /*!< SCU MODSUSP: T2_SUSP (Bit 3)                          */
#define SCU_MODSUSP_T2_SUSP_Msk           (0x8UL)                   /*!< SCU MODSUSP: T2_SUSP (Bitfield-Mask: 0x01)            */
#define SCU_MODSUSP_T13SUSP_Pos           (2UL)                     /*!< SCU MODSUSP: T13SUSP (Bit 2)                          */
#define SCU_MODSUSP_T13SUSP_Msk           (0x4UL)                   /*!< SCU MODSUSP: T13SUSP (Bitfield-Mask: 0x01)            */
#define SCU_MODSUSP_T12SUSP_Pos           (1UL)                     /*!< SCU MODSUSP: T12SUSP (Bit 1)                          */
#define SCU_MODSUSP_T12SUSP_Msk           (0x2UL)                   /*!< SCU MODSUSP: T12SUSP (Bitfield-Mask: 0x01)            */
/* =========================================================  BCON1  ========================================================= */
#define SCU_BCON1_BR1_PRE_Pos             (1UL)                     /*!< SCU BCON1: BR1_PRE (Bit 1)                            */
#define SCU_BCON1_BR1_PRE_Msk             (0xeUL)                   /*!< SCU BCON1: BR1_PRE (Bitfield-Mask: 0x07)              */
#define SCU_BCON1_BR1_R_Pos               (0UL)                     /*!< SCU BCON1: BR1_R (Bit 0)                              */
#define SCU_BCON1_BR1_R_Msk               (0x1UL)                   /*!< SCU BCON1: BR1_R (Bitfield-Mask: 0x01)                */
/* =========================================================  BCON2  ========================================================= */
#define SCU_BCON2_BR2_PRE_Pos             (1UL)                     /*!< SCU BCON2: BR2_PRE (Bit 1)                            */
#define SCU_BCON2_BR2_PRE_Msk             (0xeUL)                   /*!< SCU BCON2: BR2_PRE (Bitfield-Mask: 0x07)              */
#define SCU_BCON2_BR2_R_Pos               (0UL)                     /*!< SCU BCON2: BR2_R (Bit 0)                              */
#define SCU_BCON2_BR2_R_Msk               (0x1UL)                   /*!< SCU BCON2: BR2_R (Bitfield-Mask: 0x01)                */
/* =========================================================  BGL1  ========================================================== */
#define SCU_BGL1_BG1_FD_SEL_Pos           (0UL)                     /*!< SCU BGL1: BG1_FD_SEL (Bit 0)                          */
#define SCU_BGL1_BG1_FD_SEL_Msk           (0x1fUL)                  /*!< SCU BGL1: BG1_FD_SEL (Bitfield-Mask: 0x1f)            */
/* =========================================================  BGL2  ========================================================== */
#define SCU_BGL2_BG2_FD_SEL_Pos           (0UL)                     /*!< SCU BGL2: BG2_FD_SEL (Bit 0)                          */
#define SCU_BGL2_BG2_FD_SEL_Msk           (0x1fUL)                  /*!< SCU BGL2: BG2_FD_SEL (Bitfield-Mask: 0x1f)            */
/* ==========================================================  BG1  ========================================================== */
#define SCU_BG1_BG1_BR_VALUE_Pos          (0UL)                     /*!< SCU BG1: BG1_BR_VALUE (Bit 0)                         */
#define SCU_BG1_BG1_BR_VALUE_Msk          (0x7ffUL)                 /*!< SCU BG1: BG1_BR_VALUE (Bitfield-Mask: 0x7ff)          */
/* ==========================================================  BG2  ========================================================== */
#define SCU_BG2_BG2_BR_VALUE_Pos          (0UL)                     /*!< SCU BG2: BG2_BR_VALUE (Bit 0)                         */
#define SCU_BG2_BG2_BR_VALUE_Msk          (0x7ffUL)                 /*!< SCU BG2: BG2_BR_VALUE (Bitfield-Mask: 0x7ff)          */
/* =========================================================  LINST  ========================================================= */
#define SCU_LINST_SYNEN_Pos               (6UL)                     /*!< SCU LINST: SYNEN (Bit 6)                              */
#define SCU_LINST_SYNEN_Msk               (0x40UL)                  /*!< SCU LINST: SYNEN (Bitfield-Mask: 0x01)                */
#define SCU_LINST_ERRSYN_Pos              (5UL)                     /*!< SCU LINST: ERRSYN (Bit 5)                             */
#define SCU_LINST_ERRSYN_Msk              (0x20UL)                  /*!< SCU LINST: ERRSYN (Bitfield-Mask: 0x01)               */
#define SCU_LINST_EOFSYN_Pos              (4UL)                     /*!< SCU LINST: EOFSYN (Bit 4)                             */
#define SCU_LINST_EOFSYN_Msk              (0x10UL)                  /*!< SCU LINST: EOFSYN (Bitfield-Mask: 0x01)               */
#define SCU_LINST_BRK_Pos                 (3UL)                     /*!< SCU LINST: BRK (Bit 3)                                */
#define SCU_LINST_BRK_Msk                 (0x8UL)                   /*!< SCU LINST: BRK (Bitfield-Mask: 0x01)                  */
#define SCU_LINST_BGSEL_Pos               (1UL)                     /*!< SCU LINST: BGSEL (Bit 1)                              */
#define SCU_LINST_BGSEL_Msk               (0x6UL)                   /*!< SCU LINST: BGSEL (Bitfield-Mask: 0x03)                */
#define SCU_LINST_BRDIS_Pos               (0UL)                     /*!< SCU LINST: BRDIS (Bit 0)                              */
#define SCU_LINST_BRDIS_Msk               (0x1UL)                   /*!< SCU LINST: BRDIS (Bitfield-Mask: 0x01)                */
/* ========================================================  LINSCLR  ======================================================== */
#define SCU_LINSCLR_ERRSYNC_Pos           (5UL)                     /*!< SCU LINSCLR: ERRSYNC (Bit 5)                          */
#define SCU_LINSCLR_ERRSYNC_Msk           (0x20UL)                  /*!< SCU LINSCLR: ERRSYNC (Bitfield-Mask: 0x01)            */
#define SCU_LINSCLR_EOFSYNC_Pos           (4UL)                     /*!< SCU LINSCLR: EOFSYNC (Bit 4)                          */
#define SCU_LINSCLR_EOFSYNC_Msk           (0x10UL)                  /*!< SCU LINSCLR: EOFSYNC (Bitfield-Mask: 0x01)            */
#define SCU_LINSCLR_BRKC_Pos              (3UL)                     /*!< SCU LINSCLR: BRKC (Bit 3)                             */
#define SCU_LINSCLR_BRKC_Msk              (0x8UL)                   /*!< SCU LINSCLR: BRKC (Bitfield-Mask: 0x01)               */
/* ========================================================  EDCCON  ========================================================= */
#define SCU_EDCCON_NVMIE_Pos              (2UL)                     /*!< SCU EDCCON: NVMIE (Bit 2)                             */
#define SCU_EDCCON_NVMIE_Msk              (0x4UL)                   /*!< SCU EDCCON: NVMIE (Bitfield-Mask: 0x01)               */
#define SCU_EDCCON_RIE_Pos                (0UL)                     /*!< SCU EDCCON: RIE (Bit 0)                               */
#define SCU_EDCCON_RIE_Msk                (0x1UL)                   /*!< SCU EDCCON: RIE (Bitfield-Mask: 0x01)                 */
/* ========================================================  EDCSTAT  ======================================================== */
#define SCU_EDCSTAT_RSBE_Pos              (4UL)                     /*!< SCU EDCSTAT: RSBE (Bit 4)                             */
#define SCU_EDCSTAT_RSBE_Msk              (0x10UL)                  /*!< SCU EDCSTAT: RSBE (Bitfield-Mask: 0x01)               */
#define SCU_EDCSTAT_NVMDBE_Pos            (2UL)                     /*!< SCU EDCSTAT: NVMDBE (Bit 2)                           */
#define SCU_EDCSTAT_NVMDBE_Msk            (0x4UL)                   /*!< SCU EDCSTAT: NVMDBE (Bitfield-Mask: 0x01)             */
#define SCU_EDCSTAT_RDBE_Pos              (0UL)                     /*!< SCU EDCSTAT: RDBE (Bit 0)                             */
#define SCU_EDCSTAT_RDBE_Msk              (0x1UL)                   /*!< SCU EDCSTAT: RDBE (Bitfield-Mask: 0x01)               */
/* ========================================================  EDCSCLR  ======================================================== */
#define SCU_EDCSCLR_RSBEC_Pos             (4UL)                     /*!< SCU EDCSCLR: RSBEC (Bit 4)                            */
#define SCU_EDCSCLR_RSBEC_Msk             (0x10UL)                  /*!< SCU EDCSCLR: RSBEC (Bitfield-Mask: 0x01)              */
#define SCU_EDCSCLR_NVMDBEC_Pos           (2UL)                     /*!< SCU EDCSCLR: NVMDBEC (Bit 2)                          */
#define SCU_EDCSCLR_NVMDBEC_Msk           (0x4UL)                   /*!< SCU EDCSCLR: NVMDBEC (Bitfield-Mask: 0x01)            */
#define SCU_EDCSCLR_RDBEC_Pos             (0UL)                     /*!< SCU EDCSCLR: RDBEC (Bit 0)                            */
#define SCU_EDCSCLR_RDBEC_Msk             (0x1UL)                   /*!< SCU EDCSCLR: RDBEC (Bitfield-Mask: 0x01)              */
/* ========================================================  PASSWD  ========================================================= */
#define SCU_PASSWD_PASS_Pos               (3UL)                     /*!< SCU PASSWD: PASS (Bit 3)                              */
#define SCU_PASSWD_PASS_Msk               (0xf8UL)                  /*!< SCU PASSWD: PASS (Bitfield-Mask: 0x1f)                */
#define SCU_PASSWD_PROTECT_S_Pos          (2UL)                     /*!< SCU PASSWD: PROTECT_S (Bit 2)                         */
#define SCU_PASSWD_PROTECT_S_Msk          (0x4UL)                   /*!< SCU PASSWD: PROTECT_S (Bitfield-Mask: 0x01)           */
#define SCU_PASSWD_PW_MODE_Pos            (0UL)                     /*!< SCU PASSWD: PW_MODE (Bit 0)                           */
#define SCU_PASSWD_PW_MODE_Msk            (0x3UL)                   /*!< SCU PASSWD: PW_MODE (Bitfield-Mask: 0x03)             */
/* ====================================================  SYS_STRTUP_STS  ===================================================== */
#define SCU_SYS_STRTUP_STS_PG100TP_CHKS_ERR_Pos (2UL)               /*!< SCU SYS_STRTUP_STS: PG100TP_CHKS_ERR (Bit 2)          */
#define SCU_SYS_STRTUP_STS_PG100TP_CHKS_ERR_Msk (0x4UL)             /*!< SCU SYS_STRTUP_STS: PG100TP_CHKS_ERR (Bitfield-Mask: 0x01) */
#define SCU_SYS_STRTUP_STS_MRAMINITSTS_Pos (1UL)                    /*!< SCU SYS_STRTUP_STS: MRAMINITSTS (Bit 1)               */
#define SCU_SYS_STRTUP_STS_MRAMINITSTS_Msk (0x2UL)                  /*!< SCU SYS_STRTUP_STS: MRAMINITSTS (Bitfield-Mask: 0x01) */
#define SCU_SYS_STRTUP_STS_INIT_FAIL_Pos  (0UL)                     /*!< SCU SYS_STRTUP_STS: INIT_FAIL (Bit 0)                 */
#define SCU_SYS_STRTUP_STS_INIT_FAIL_Msk  (0x1UL)                   /*!< SCU SYS_STRTUP_STS: INIT_FAIL (Bitfield-Mask: 0x01)   */
/* =====================================================  NVM_PROT_STS  ====================================================== */
#define SCU_NVM_PROT_STS_NVMBSL_Pos       (14UL)                    /*!< SCU NVM_PROT_STS: NVMBSL (Bit 14)                     */
#define SCU_NVM_PROT_STS_NVMBSL_Msk       (0xc000UL)                /*!< SCU NVM_PROT_STS: NVMBSL (Bitfield-Mask: 0x03)        */
#define SCU_NVM_PROT_STS_CBSL_PW_Pos      (13UL)                    /*!< SCU NVM_PROT_STS: CBSL_PW (Bit 13)                    */
#define SCU_NVM_PROT_STS_CBSL_PW_Msk      (0x2000UL)                /*!< SCU NVM_PROT_STS: CBSL_PW (Bitfield-Mask: 0x01)       */
#define SCU_NVM_PROT_STS_LIN_PW_Pos       (12UL)                    /*!< SCU NVM_PROT_STS: LIN_PW (Bit 12)                     */
#define SCU_NVM_PROT_STS_LIN_PW_Msk       (0x1000UL)                /*!< SCU NVM_PROT_STS: LIN_PW (Bitfield-Mask: 0x01)        */
#define SCU_NVM_PROT_STS_NL_PW_Pos        (11UL)                    /*!< SCU NVM_PROT_STS: NL_PW (Bit 11)                      */
#define SCU_NVM_PROT_STS_NL_PW_Msk        (0x800UL)                 /*!< SCU NVM_PROT_STS: NL_PW (Bitfield-Mask: 0x01)         */
#define SCU_NVM_PROT_STS_DIS_RDUS_S0_Pos  (10UL)                    /*!< SCU NVM_PROT_STS: DIS_RDUS_S0 (Bit 10)                */
#define SCU_NVM_PROT_STS_DIS_RDUS_S0_Msk  (0x400UL)                 /*!< SCU NVM_PROT_STS: DIS_RDUS_S0 (Bitfield-Mask: 0x01)   */
#define SCU_NVM_PROT_STS_DIS_RDUS_Pos     (9UL)                     /*!< SCU NVM_PROT_STS: DIS_RDUS (Bit 9)                    */
#define SCU_NVM_PROT_STS_DIS_RDUS_Msk     (0x200UL)                 /*!< SCU NVM_PROT_STS: DIS_RDUS (Bitfield-Mask: 0x01)      */
#define SCU_NVM_PROT_STS_EN_RD_S0_Pos     (8UL)                     /*!< SCU NVM_PROT_STS: EN_RD_S0 (Bit 8)                    */
#define SCU_NVM_PROT_STS_EN_RD_S0_Msk     (0x100UL)                 /*!< SCU NVM_PROT_STS: EN_RD_S0 (Bitfield-Mask: 0x01)      */
#define SCU_NVM_PROT_STS_EN_RD_CBSL_Pos   (5UL)                     /*!< SCU NVM_PROT_STS: EN_RD_CBSL (Bit 5)                  */
#define SCU_NVM_PROT_STS_EN_RD_CBSL_Msk   (0x20UL)                  /*!< SCU NVM_PROT_STS: EN_RD_CBSL (Bitfield-Mask: 0x01)    */
#define SCU_NVM_PROT_STS_EN_RD_LIN_Pos    (4UL)                     /*!< SCU NVM_PROT_STS: EN_RD_LIN (Bit 4)                   */
#define SCU_NVM_PROT_STS_EN_RD_LIN_Msk    (0x10UL)                  /*!< SCU NVM_PROT_STS: EN_RD_LIN (Bitfield-Mask: 0x01)     */
#define SCU_NVM_PROT_STS_EN_RD_NL_Pos     (3UL)                     /*!< SCU NVM_PROT_STS: EN_RD_NL (Bit 3)                    */
#define SCU_NVM_PROT_STS_EN_RD_NL_Msk     (0x8UL)                   /*!< SCU NVM_PROT_STS: EN_RD_NL (Bitfield-Mask: 0x01)      */
#define SCU_NVM_PROT_STS_EN_PRG_CBSL_Pos  (2UL)                     /*!< SCU NVM_PROT_STS: EN_PRG_CBSL (Bit 2)                 */
#define SCU_NVM_PROT_STS_EN_PRG_CBSL_Msk  (0x4UL)                   /*!< SCU NVM_PROT_STS: EN_PRG_CBSL (Bitfield-Mask: 0x01)   */
#define SCU_NVM_PROT_STS_EN_PRG_LIN_Pos   (1UL)                     /*!< SCU NVM_PROT_STS: EN_PRG_LIN (Bit 1)                  */
#define SCU_NVM_PROT_STS_EN_PRG_LIN_Msk   (0x2UL)                   /*!< SCU NVM_PROT_STS: EN_PRG_LIN (Bitfield-Mask: 0x01)    */
#define SCU_NVM_PROT_STS_EN_PRG_NL_Pos    (0UL)                     /*!< SCU NVM_PROT_STS: EN_PRG_NL (Bit 0)                   */
#define SCU_NVM_PROT_STS_EN_PRG_NL_Msk    (0x1UL)                   /*!< SCU NVM_PROT_STS: EN_PRG_NL (Bitfield-Mask: 0x01)     */
/* ======================================================  MEM_ACC_STS  ====================================================== */
#define SCU_MEM_ACC_STS_ROM_PROT_ERR_Pos  (4UL)                     /*!< SCU MEM_ACC_STS: ROM_PROT_ERR (Bit 4)                 */
#define SCU_MEM_ACC_STS_ROM_PROT_ERR_Msk  (0x10UL)                  /*!< SCU MEM_ACC_STS: ROM_PROT_ERR (Bitfield-Mask: 0x01)   */
#define SCU_MEM_ACC_STS_NVM_SFR_ADDR_ERR_Pos (3UL)                  /*!< SCU MEM_ACC_STS: NVM_SFR_ADDR_ERR (Bit 3)             */
#define SCU_MEM_ACC_STS_NVM_SFR_ADDR_ERR_Msk (0x8UL)                /*!< SCU MEM_ACC_STS: NVM_SFR_ADDR_ERR (Bitfield-Mask: 0x01) */
#define SCU_MEM_ACC_STS_NVM_SFR_PROT_ERR_Pos (2UL)                  /*!< SCU MEM_ACC_STS: NVM_SFR_PROT_ERR (Bit 2)             */
#define SCU_MEM_ACC_STS_NVM_SFR_PROT_ERR_Msk (0x4UL)                /*!< SCU MEM_ACC_STS: NVM_SFR_PROT_ERR (Bitfield-Mask: 0x01) */
#define SCU_MEM_ACC_STS_NVM_ADDR_ERR_Pos  (1UL)                     /*!< SCU MEM_ACC_STS: NVM_ADDR_ERR (Bit 1)                 */
#define SCU_MEM_ACC_STS_NVM_ADDR_ERR_Msk  (0x2UL)                   /*!< SCU MEM_ACC_STS: NVM_ADDR_ERR (Bitfield-Mask: 0x01)   */
#define SCU_MEM_ACC_STS_NVM_PROT_ERR_Pos  (0UL)                     /*!< SCU MEM_ACC_STS: NVM_PROT_ERR (Bit 0)                 */
#define SCU_MEM_ACC_STS_NVM_PROT_ERR_Msk  (0x1UL)                   /*!< SCU MEM_ACC_STS: NVM_PROT_ERR (Bitfield-Mask: 0x01)   */
/* ==========================================================  ID  =========================================================== */
#define SCU_ID_PRODID_Pos                 (3UL)                     /*!< SCU ID: PRODID (Bit 3)                                */
#define SCU_ID_PRODID_Msk                 (0xf8UL)                  /*!< SCU ID: PRODID (Bitfield-Mask: 0x1f)                  */
#define SCU_ID_VERID_Pos                  (0UL)                     /*!< SCU ID: VERID (Bit 0)                                 */
#define SCU_ID_VERID_Msk                  (0x7UL)                   /*!< SCU ID: VERID (Bitfield-Mask: 0x07)                   */
/* ========================================================  MEMSTAT  ======================================================== */
#define SCU_MEMSTAT_SASTATUS_Pos          (6UL)                     /*!< SCU MEMSTAT: SASTATUS (Bit 6)                         */
#define SCU_MEMSTAT_SASTATUS_Msk          (0xc0UL)                  /*!< SCU MEMSTAT: SASTATUS (Bitfield-Mask: 0x03)           */
#define SCU_MEMSTAT_SECTORINFO_Pos        (0UL)                     /*!< SCU MEMSTAT: SECTORINFO (Bit 0)                       */
#define SCU_MEMSTAT_SECTORINFO_Msk        (0x3fUL)                  /*!< SCU MEMSTAT: SECTORINFO (Bitfield-Mask: 0x3f)         */
/* =========================================================  EMOP  ========================================================== */
#define SCU_EMOP_EMPROP_Pos               (1UL)                     /*!< SCU EMOP: EMPROP (Bit 1)                              */
#define SCU_EMOP_EMPROP_Msk               (0x2UL)                   /*!< SCU EMOP: EMPROP (Bitfield-Mask: 0x01)                */
#define SCU_EMOP_NVMPROP_Pos              (0UL)                     /*!< SCU EMOP: NVMPROP (Bit 0)                             */
#define SCU_EMOP_NVMPROP_Msk              (0x1UL)                   /*!< SCU EMOP: NVMPROP (Bitfield-Mask: 0x01)               */


/* =========================================================================================================================== */
/* ================                                           SCUPM                                           ================ */
/* =========================================================================================================================== */

/* ====================================================  AMCLK_FREQ_STS  ===================================================== */
#define SCUPM_AMCLK_FREQ_STS_AMCLK2_FREQ_Pos (8UL)                  /*!< SCUPM AMCLK_FREQ_STS: AMCLK2_FREQ (Bit 8)             */
#define SCUPM_AMCLK_FREQ_STS_AMCLK2_FREQ_Msk (0x3f00UL)             /*!< SCUPM AMCLK_FREQ_STS: AMCLK2_FREQ (Bitfield-Mask: 0x3f) */
#define SCUPM_AMCLK_FREQ_STS_AMCLK1_FREQ_Pos (0UL)                  /*!< SCUPM AMCLK_FREQ_STS: AMCLK1_FREQ (Bit 0)             */
#define SCUPM_AMCLK_FREQ_STS_AMCLK1_FREQ_Msk (0x3fUL)               /*!< SCUPM AMCLK_FREQ_STS: AMCLK1_FREQ (Bitfield-Mask: 0x3f) */
/* ======================================================  AMCLK_CTRL  ======================================================= */
#define SCUPM_AMCLK_CTRL_CLKWDT_PD_N_Pos  (0UL)                     /*!< SCUPM AMCLK_CTRL: CLKWDT_PD_N (Bit 0)                 */
#define SCUPM_AMCLK_CTRL_CLKWDT_PD_N_Msk  (0x1UL)                   /*!< SCUPM AMCLK_CTRL: CLKWDT_PD_N (Bitfield-Mask: 0x01)   */
/* =====================================================  AMCLK_TH_HYS  ====================================================== */
#define SCUPM_AMCLK_TH_HYS_AMCLK2_LOW_HYS_Pos (30UL)                /*!< SCUPM AMCLK_TH_HYS: AMCLK2_LOW_HYS (Bit 30)           */
#define SCUPM_AMCLK_TH_HYS_AMCLK2_LOW_HYS_Msk (0xc0000000UL)        /*!< SCUPM AMCLK_TH_HYS: AMCLK2_LOW_HYS (Bitfield-Mask: 0x03) */
#define SCUPM_AMCLK_TH_HYS_AMCLK2_LOW_TH_Pos (24UL)                 /*!< SCUPM AMCLK_TH_HYS: AMCLK2_LOW_TH (Bit 24)            */
#define SCUPM_AMCLK_TH_HYS_AMCLK2_LOW_TH_Msk (0x3f000000UL)         /*!< SCUPM AMCLK_TH_HYS: AMCLK2_LOW_TH (Bitfield-Mask: 0x3f) */
#define SCUPM_AMCLK_TH_HYS_AMCLK2_UP_HYS_Pos (22UL)                 /*!< SCUPM AMCLK_TH_HYS: AMCLK2_UP_HYS (Bit 22)            */
#define SCUPM_AMCLK_TH_HYS_AMCLK2_UP_HYS_Msk (0xc00000UL)           /*!< SCUPM AMCLK_TH_HYS: AMCLK2_UP_HYS (Bitfield-Mask: 0x03) */
#define SCUPM_AMCLK_TH_HYS_AMCLK2_UP_TH_Pos (16UL)                  /*!< SCUPM AMCLK_TH_HYS: AMCLK2_UP_TH (Bit 16)             */
#define SCUPM_AMCLK_TH_HYS_AMCLK2_UP_TH_Msk (0x3f0000UL)            /*!< SCUPM AMCLK_TH_HYS: AMCLK2_UP_TH (Bitfield-Mask: 0x3f) */
#define SCUPM_AMCLK_TH_HYS_AMCLK1_LOW_HYS_Pos (14UL)                /*!< SCUPM AMCLK_TH_HYS: AMCLK1_LOW_HYS (Bit 14)           */
#define SCUPM_AMCLK_TH_HYS_AMCLK1_LOW_HYS_Msk (0xc000UL)            /*!< SCUPM AMCLK_TH_HYS: AMCLK1_LOW_HYS (Bitfield-Mask: 0x03) */
#define SCUPM_AMCLK_TH_HYS_AMCLK1_LOW_TH_Pos (8UL)                  /*!< SCUPM AMCLK_TH_HYS: AMCLK1_LOW_TH (Bit 8)             */
#define SCUPM_AMCLK_TH_HYS_AMCLK1_LOW_TH_Msk (0x3f00UL)             /*!< SCUPM AMCLK_TH_HYS: AMCLK1_LOW_TH (Bitfield-Mask: 0x3f) */
#define SCUPM_AMCLK_TH_HYS_AMCLK1_UP_HYS_Pos (6UL)                  /*!< SCUPM AMCLK_TH_HYS: AMCLK1_UP_HYS (Bit 6)             */
#define SCUPM_AMCLK_TH_HYS_AMCLK1_UP_HYS_Msk (0xc0UL)               /*!< SCUPM AMCLK_TH_HYS: AMCLK1_UP_HYS (Bitfield-Mask: 0x03) */
#define SCUPM_AMCLK_TH_HYS_AMCLK1_UP_TH_Pos (0UL)                   /*!< SCUPM AMCLK_TH_HYS: AMCLK1_UP_TH (Bit 0)              */
#define SCUPM_AMCLK_TH_HYS_AMCLK1_UP_TH_Msk (0x3fUL)                /*!< SCUPM AMCLK_TH_HYS: AMCLK1_UP_TH (Bitfield-Mask: 0x3f) */
/* ========================================================  STCALIB  ======================================================== */
#define SCUPM_STCALIB_STCALIB_Pos         (0UL)                     /*!< SCUPM STCALIB: STCALIB (Bit 0)                        */
#define SCUPM_STCALIB_STCALIB_Msk         (0x3ffffffUL)             /*!< SCUPM STCALIB: STCALIB (Bitfield-Mask: 0x3ffffff)     */
/* ========================================================  SYS_IS  ========================================================= */
#define SCUPM_SYS_IS_SYS_SUPPLY_STS_Pos   (28UL)                    /*!< SCUPM SYS_IS: SYS_SUPPLY_STS (Bit 28)                 */
#define SCUPM_SYS_IS_SYS_SUPPLY_STS_Msk   (0x10000000UL)            /*!< SCUPM SYS_IS: SYS_SUPPLY_STS (Bitfield-Mask: 0x01)    */
#define SCUPM_SYS_IS_SYS_OT_STS_Pos       (25UL)                    /*!< SCUPM SYS_IS: SYS_OT_STS (Bit 25)                     */
#define SCUPM_SYS_IS_SYS_OT_STS_Msk       (0x2000000UL)             /*!< SCUPM SYS_IS: SYS_OT_STS (Bitfield-Mask: 0x01)        */
#define SCUPM_SYS_IS_SYS_OTWARN_STS_Pos   (24UL)                    /*!< SCUPM SYS_IS: SYS_OTWARN_STS (Bit 24)                 */
#define SCUPM_SYS_IS_SYS_OTWARN_STS_Msk   (0x1000000UL)             /*!< SCUPM SYS_IS: SYS_OTWARN_STS (Bitfield-Mask: 0x01)    */
#define SCUPM_SYS_IS_LIN_FAIL_STS_Pos     (22UL)                    /*!< SCUPM SYS_IS: LIN_FAIL_STS (Bit 22)                   */
#define SCUPM_SYS_IS_LIN_FAIL_STS_Msk     (0x400000UL)              /*!< SCUPM SYS_IS: LIN_FAIL_STS (Bitfield-Mask: 0x01)      */
#define SCUPM_SYS_IS_HS2_FAIL_STS_Pos     (19UL)                    /*!< SCUPM SYS_IS: HS2_FAIL_STS (Bit 19)                   */
#define SCUPM_SYS_IS_HS2_FAIL_STS_Msk     (0x80000UL)               /*!< SCUPM SYS_IS: HS2_FAIL_STS (Bitfield-Mask: 0x01)      */
#define SCUPM_SYS_IS_HS1_FAIL_STS_Pos     (18UL)                    /*!< SCUPM SYS_IS: HS1_FAIL_STS (Bit 18)                   */
#define SCUPM_SYS_IS_HS1_FAIL_STS_Msk     (0x40000UL)               /*!< SCUPM SYS_IS: HS1_FAIL_STS (Bitfield-Mask: 0x01)      */
#define SCUPM_SYS_IS_LS2_FAIL_STS_Pos     (17UL)                    /*!< SCUPM SYS_IS: LS2_FAIL_STS (Bit 17)                   */
#define SCUPM_SYS_IS_LS2_FAIL_STS_Msk     (0x20000UL)               /*!< SCUPM SYS_IS: LS2_FAIL_STS (Bitfield-Mask: 0x01)      */
#define SCUPM_SYS_IS_LS1_FAIL_STS_Pos     (16UL)                    /*!< SCUPM SYS_IS: LS1_FAIL_STS (Bit 16)                   */
#define SCUPM_SYS_IS_LS1_FAIL_STS_Msk     (0x10000UL)               /*!< SCUPM SYS_IS: LS1_FAIL_STS (Bitfield-Mask: 0x01)      */
#define SCUPM_SYS_IS_SYS_SUPPLY_IS_Pos    (12UL)                    /*!< SCUPM SYS_IS: SYS_SUPPLY_IS (Bit 12)                  */
#define SCUPM_SYS_IS_SYS_SUPPLY_IS_Msk    (0x1000UL)                /*!< SCUPM SYS_IS: SYS_SUPPLY_IS (Bitfield-Mask: 0x01)     */
#define SCUPM_SYS_IS_REFBG_UPTHWARN_IS_Pos (11UL)                   /*!< SCUPM SYS_IS: REFBG_UPTHWARN_IS (Bit 11)              */
#define SCUPM_SYS_IS_REFBG_UPTHWARN_IS_Msk (0x800UL)                /*!< SCUPM SYS_IS: REFBG_UPTHWARN_IS (Bitfield-Mask: 0x01) */
#define SCUPM_SYS_IS_REFBG_LOTHWARN_IS_Pos (10UL)                   /*!< SCUPM SYS_IS: REFBG_LOTHWARN_IS (Bit 10)              */
#define SCUPM_SYS_IS_REFBG_LOTHWARN_IS_Msk (0x400UL)                /*!< SCUPM SYS_IS: REFBG_LOTHWARN_IS (Bitfield-Mask: 0x01) */
#define SCUPM_SYS_IS_SYS_OT_IS_Pos        (9UL)                     /*!< SCUPM SYS_IS: SYS_OT_IS (Bit 9)                       */
#define SCUPM_SYS_IS_SYS_OT_IS_Msk        (0x200UL)                 /*!< SCUPM SYS_IS: SYS_OT_IS (Bitfield-Mask: 0x01)         */
#define SCUPM_SYS_IS_SYS_OTWARN_IS_Pos    (8UL)                     /*!< SCUPM SYS_IS: SYS_OTWARN_IS (Bit 8)                   */
#define SCUPM_SYS_IS_SYS_OTWARN_IS_Msk    (0x100UL)                 /*!< SCUPM SYS_IS: SYS_OTWARN_IS (Bitfield-Mask: 0x01)     */
#define SCUPM_SYS_IS_LIN_FAIL_IS_Pos      (6UL)                     /*!< SCUPM SYS_IS: LIN_FAIL_IS (Bit 6)                     */
#define SCUPM_SYS_IS_LIN_FAIL_IS_Msk      (0x40UL)                  /*!< SCUPM SYS_IS: LIN_FAIL_IS (Bitfield-Mask: 0x01)       */
#define SCUPM_SYS_IS_HS2_FAIL_IS_Pos      (3UL)                     /*!< SCUPM SYS_IS: HS2_FAIL_IS (Bit 3)                     */
#define SCUPM_SYS_IS_HS2_FAIL_IS_Msk      (0x8UL)                   /*!< SCUPM SYS_IS: HS2_FAIL_IS (Bitfield-Mask: 0x01)       */
#define SCUPM_SYS_IS_HS1_FAIL_IS_Pos      (2UL)                     /*!< SCUPM SYS_IS: HS1_FAIL_IS (Bit 2)                     */
#define SCUPM_SYS_IS_HS1_FAIL_IS_Msk      (0x4UL)                   /*!< SCUPM SYS_IS: HS1_FAIL_IS (Bitfield-Mask: 0x01)       */
#define SCUPM_SYS_IS_LS2_FAIL_IS_Pos      (1UL)                     /*!< SCUPM SYS_IS: LS2_FAIL_IS (Bit 1)                     */
#define SCUPM_SYS_IS_LS2_FAIL_IS_Msk      (0x2UL)                   /*!< SCUPM SYS_IS: LS2_FAIL_IS (Bitfield-Mask: 0x01)       */
#define SCUPM_SYS_IS_LS1_FAIL_IS_Pos      (0UL)                     /*!< SCUPM SYS_IS: LS1_FAIL_IS (Bit 0)                     */
#define SCUPM_SYS_IS_LS1_FAIL_IS_Msk      (0x1UL)                   /*!< SCUPM SYS_IS: LS1_FAIL_IS (Bitfield-Mask: 0x01)       */
/* ==================================================  SYS_SUPPLY_IRQ_STS  =================================================== */
#define SCUPM_SYS_SUPPLY_IRQ_STS_VDDEXT_OV_STS_Pos (25UL)           /*!< SCUPM SYS_SUPPLY_IRQ_STS: VDDEXT_OV_STS (Bit 25)      */
#define SCUPM_SYS_SUPPLY_IRQ_STS_VDDEXT_OV_STS_Msk (0x2000000UL)    /*!< SCUPM SYS_SUPPLY_IRQ_STS: VDDEXT_OV_STS (Bitfield-Mask: 0x01) */
#define SCUPM_SYS_SUPPLY_IRQ_STS_VDD1V5_OV_STS_Pos (24UL)           /*!< SCUPM SYS_SUPPLY_IRQ_STS: VDD1V5_OV_STS (Bit 24)      */
#define SCUPM_SYS_SUPPLY_IRQ_STS_VDD1V5_OV_STS_Msk (0x1000000UL)    /*!< SCUPM SYS_SUPPLY_IRQ_STS: VDD1V5_OV_STS (Bitfield-Mask: 0x01) */
#define SCUPM_SYS_SUPPLY_IRQ_STS_VDD5V_OV_STS_Pos (23UL)            /*!< SCUPM SYS_SUPPLY_IRQ_STS: VDD5V_OV_STS (Bit 23)       */
#define SCUPM_SYS_SUPPLY_IRQ_STS_VDD5V_OV_STS_Msk (0x800000UL)      /*!< SCUPM SYS_SUPPLY_IRQ_STS: VDD5V_OV_STS (Bitfield-Mask: 0x01) */
#define SCUPM_SYS_SUPPLY_IRQ_STS_VS_OV_STS_Pos (22UL)               /*!< SCUPM SYS_SUPPLY_IRQ_STS: VS_OV_STS (Bit 22)          */
#define SCUPM_SYS_SUPPLY_IRQ_STS_VS_OV_STS_Msk (0x400000UL)         /*!< SCUPM SYS_SUPPLY_IRQ_STS: VS_OV_STS (Bitfield-Mask: 0x01) */
#define SCUPM_SYS_SUPPLY_IRQ_STS_VBAT_OV_STS_Pos (21UL)             /*!< SCUPM SYS_SUPPLY_IRQ_STS: VBAT_OV_STS (Bit 21)        */
#define SCUPM_SYS_SUPPLY_IRQ_STS_VBAT_OV_STS_Msk (0x200000UL)       /*!< SCUPM SYS_SUPPLY_IRQ_STS: VBAT_OV_STS (Bitfield-Mask: 0x01) */
#define SCUPM_SYS_SUPPLY_IRQ_STS_VDDEXT_UV_STS_Pos (20UL)           /*!< SCUPM SYS_SUPPLY_IRQ_STS: VDDEXT_UV_STS (Bit 20)      */
#define SCUPM_SYS_SUPPLY_IRQ_STS_VDDEXT_UV_STS_Msk (0x100000UL)     /*!< SCUPM SYS_SUPPLY_IRQ_STS: VDDEXT_UV_STS (Bitfield-Mask: 0x01) */
#define SCUPM_SYS_SUPPLY_IRQ_STS_VDD1V5_UV_STS_Pos (19UL)           /*!< SCUPM SYS_SUPPLY_IRQ_STS: VDD1V5_UV_STS (Bit 19)      */
#define SCUPM_SYS_SUPPLY_IRQ_STS_VDD1V5_UV_STS_Msk (0x80000UL)      /*!< SCUPM SYS_SUPPLY_IRQ_STS: VDD1V5_UV_STS (Bitfield-Mask: 0x01) */
#define SCUPM_SYS_SUPPLY_IRQ_STS_VDD5V_UV_STS_Pos (18UL)            /*!< SCUPM SYS_SUPPLY_IRQ_STS: VDD5V_UV_STS (Bit 18)       */
#define SCUPM_SYS_SUPPLY_IRQ_STS_VDD5V_UV_STS_Msk (0x40000UL)       /*!< SCUPM SYS_SUPPLY_IRQ_STS: VDD5V_UV_STS (Bitfield-Mask: 0x01) */
#define SCUPM_SYS_SUPPLY_IRQ_STS_VS_UV_STS_Pos (17UL)               /*!< SCUPM SYS_SUPPLY_IRQ_STS: VS_UV_STS (Bit 17)          */
#define SCUPM_SYS_SUPPLY_IRQ_STS_VS_UV_STS_Msk (0x20000UL)          /*!< SCUPM SYS_SUPPLY_IRQ_STS: VS_UV_STS (Bitfield-Mask: 0x01) */
#define SCUPM_SYS_SUPPLY_IRQ_STS_VBAT_UV_STS_Pos (16UL)             /*!< SCUPM SYS_SUPPLY_IRQ_STS: VBAT_UV_STS (Bit 16)        */
#define SCUPM_SYS_SUPPLY_IRQ_STS_VBAT_UV_STS_Msk (0x10000UL)        /*!< SCUPM SYS_SUPPLY_IRQ_STS: VBAT_UV_STS (Bitfield-Mask: 0x01) */
#define SCUPM_SYS_SUPPLY_IRQ_STS_VDDEXT_OV_IS_Pos (9UL)             /*!< SCUPM SYS_SUPPLY_IRQ_STS: VDDEXT_OV_IS (Bit 9)        */
#define SCUPM_SYS_SUPPLY_IRQ_STS_VDDEXT_OV_IS_Msk (0x200UL)         /*!< SCUPM SYS_SUPPLY_IRQ_STS: VDDEXT_OV_IS (Bitfield-Mask: 0x01) */
#define SCUPM_SYS_SUPPLY_IRQ_STS_VDD1V5_OV_IS_Pos (8UL)             /*!< SCUPM SYS_SUPPLY_IRQ_STS: VDD1V5_OV_IS (Bit 8)        */
#define SCUPM_SYS_SUPPLY_IRQ_STS_VDD1V5_OV_IS_Msk (0x100UL)         /*!< SCUPM SYS_SUPPLY_IRQ_STS: VDD1V5_OV_IS (Bitfield-Mask: 0x01) */
#define SCUPM_SYS_SUPPLY_IRQ_STS_VDD5V_OV_IS_Pos (7UL)              /*!< SCUPM SYS_SUPPLY_IRQ_STS: VDD5V_OV_IS (Bit 7)         */
#define SCUPM_SYS_SUPPLY_IRQ_STS_VDD5V_OV_IS_Msk (0x80UL)           /*!< SCUPM SYS_SUPPLY_IRQ_STS: VDD5V_OV_IS (Bitfield-Mask: 0x01) */
#define SCUPM_SYS_SUPPLY_IRQ_STS_VS_OV_IS_Pos (6UL)                 /*!< SCUPM SYS_SUPPLY_IRQ_STS: VS_OV_IS (Bit 6)            */
#define SCUPM_SYS_SUPPLY_IRQ_STS_VS_OV_IS_Msk (0x40UL)              /*!< SCUPM SYS_SUPPLY_IRQ_STS: VS_OV_IS (Bitfield-Mask: 0x01) */
#define SCUPM_SYS_SUPPLY_IRQ_STS_VBAT_OV_IS_Pos (5UL)               /*!< SCUPM SYS_SUPPLY_IRQ_STS: VBAT_OV_IS (Bit 5)          */
#define SCUPM_SYS_SUPPLY_IRQ_STS_VBAT_OV_IS_Msk (0x20UL)            /*!< SCUPM SYS_SUPPLY_IRQ_STS: VBAT_OV_IS (Bitfield-Mask: 0x01) */
#define SCUPM_SYS_SUPPLY_IRQ_STS_VDDEXT_UV_IS_Pos (4UL)             /*!< SCUPM SYS_SUPPLY_IRQ_STS: VDDEXT_UV_IS (Bit 4)        */
#define SCUPM_SYS_SUPPLY_IRQ_STS_VDDEXT_UV_IS_Msk (0x10UL)          /*!< SCUPM SYS_SUPPLY_IRQ_STS: VDDEXT_UV_IS (Bitfield-Mask: 0x01) */
#define SCUPM_SYS_SUPPLY_IRQ_STS_VDD1V5_UV_IS_Pos (3UL)             /*!< SCUPM SYS_SUPPLY_IRQ_STS: VDD1V5_UV_IS (Bit 3)        */
#define SCUPM_SYS_SUPPLY_IRQ_STS_VDD1V5_UV_IS_Msk (0x8UL)           /*!< SCUPM SYS_SUPPLY_IRQ_STS: VDD1V5_UV_IS (Bitfield-Mask: 0x01) */
#define SCUPM_SYS_SUPPLY_IRQ_STS_VDD5V_UV_IS_Pos (2UL)              /*!< SCUPM SYS_SUPPLY_IRQ_STS: VDD5V_UV_IS (Bit 2)         */
#define SCUPM_SYS_SUPPLY_IRQ_STS_VDD5V_UV_IS_Msk (0x4UL)            /*!< SCUPM SYS_SUPPLY_IRQ_STS: VDD5V_UV_IS (Bitfield-Mask: 0x01) */
#define SCUPM_SYS_SUPPLY_IRQ_STS_VS_UV_IS_Pos (1UL)                 /*!< SCUPM SYS_SUPPLY_IRQ_STS: VS_UV_IS (Bit 1)            */
#define SCUPM_SYS_SUPPLY_IRQ_STS_VS_UV_IS_Msk (0x2UL)               /*!< SCUPM SYS_SUPPLY_IRQ_STS: VS_UV_IS (Bitfield-Mask: 0x01) */
#define SCUPM_SYS_SUPPLY_IRQ_STS_VBAT_UV_IS_Pos (0UL)               /*!< SCUPM SYS_SUPPLY_IRQ_STS: VBAT_UV_IS (Bit 0)          */
#define SCUPM_SYS_SUPPLY_IRQ_STS_VBAT_UV_IS_Msk (0x1UL)             /*!< SCUPM SYS_SUPPLY_IRQ_STS: VBAT_UV_IS (Bitfield-Mask: 0x01) */
/* =======================================================  SYS_ISCLR  ======================================================= */
#define SCUPM_SYS_ISCLR_SYS_OT_SC_Pos     (25UL)                    /*!< SCUPM SYS_ISCLR: SYS_OT_SC (Bit 25)                   */
#define SCUPM_SYS_ISCLR_SYS_OT_SC_Msk     (0x2000000UL)             /*!< SCUPM SYS_ISCLR: SYS_OT_SC (Bitfield-Mask: 0x01)      */
#define SCUPM_SYS_ISCLR_SYS_OTWARN_SC_Pos (24UL)                    /*!< SCUPM SYS_ISCLR: SYS_OTWARN_SC (Bit 24)               */
#define SCUPM_SYS_ISCLR_SYS_OTWARN_SC_Msk (0x1000000UL)             /*!< SCUPM SYS_ISCLR: SYS_OTWARN_SC (Bitfield-Mask: 0x01)  */
#define SCUPM_SYS_ISCLR_REFBG_UPTHWARN_ISC_Pos (11UL)               /*!< SCUPM SYS_ISCLR: REFBG_UPTHWARN_ISC (Bit 11)          */
#define SCUPM_SYS_ISCLR_REFBG_UPTHWARN_ISC_Msk (0x800UL)            /*!< SCUPM SYS_ISCLR: REFBG_UPTHWARN_ISC (Bitfield-Mask: 0x01) */
#define SCUPM_SYS_ISCLR_REFBG_LOTHWARN_ISC_Pos (10UL)               /*!< SCUPM SYS_ISCLR: REFBG_LOTHWARN_ISC (Bit 10)          */
#define SCUPM_SYS_ISCLR_REFBG_LOTHWARN_ISC_Msk (0x400UL)            /*!< SCUPM SYS_ISCLR: REFBG_LOTHWARN_ISC (Bitfield-Mask: 0x01) */
#define SCUPM_SYS_ISCLR_SYS_OT_ISC_Pos    (9UL)                     /*!< SCUPM SYS_ISCLR: SYS_OT_ISC (Bit 9)                   */
#define SCUPM_SYS_ISCLR_SYS_OT_ISC_Msk    (0x200UL)                 /*!< SCUPM SYS_ISCLR: SYS_OT_ISC (Bitfield-Mask: 0x01)     */
#define SCUPM_SYS_ISCLR_SYS_OTWARN_ISC_Pos (8UL)                    /*!< SCUPM SYS_ISCLR: SYS_OTWARN_ISC (Bit 8)               */
#define SCUPM_SYS_ISCLR_SYS_OTWARN_ISC_Msk (0x100UL)                /*!< SCUPM SYS_ISCLR: SYS_OTWARN_ISC (Bitfield-Mask: 0x01) */
/* ==================================================  SYS_SUPPLY_IRQ_CLR  =================================================== */
#define SCUPM_SYS_SUPPLY_IRQ_CLR_VDDEXT_OV_SC_Pos (25UL)            /*!< SCUPM SYS_SUPPLY_IRQ_CLR: VDDEXT_OV_SC (Bit 25)       */
#define SCUPM_SYS_SUPPLY_IRQ_CLR_VDDEXT_OV_SC_Msk (0x2000000UL)     /*!< SCUPM SYS_SUPPLY_IRQ_CLR: VDDEXT_OV_SC (Bitfield-Mask: 0x01) */
#define SCUPM_SYS_SUPPLY_IRQ_CLR_VDD1V5_OV_SC_Pos (24UL)            /*!< SCUPM SYS_SUPPLY_IRQ_CLR: VDD1V5_OV_SC (Bit 24)       */
#define SCUPM_SYS_SUPPLY_IRQ_CLR_VDD1V5_OV_SC_Msk (0x1000000UL)     /*!< SCUPM SYS_SUPPLY_IRQ_CLR: VDD1V5_OV_SC (Bitfield-Mask: 0x01) */
#define SCUPM_SYS_SUPPLY_IRQ_CLR_VDD5V_OV_SC_Pos (23UL)             /*!< SCUPM SYS_SUPPLY_IRQ_CLR: VDD5V_OV_SC (Bit 23)        */
#define SCUPM_SYS_SUPPLY_IRQ_CLR_VDD5V_OV_SC_Msk (0x800000UL)       /*!< SCUPM SYS_SUPPLY_IRQ_CLR: VDD5V_OV_SC (Bitfield-Mask: 0x01) */
#define SCUPM_SYS_SUPPLY_IRQ_CLR_VS_OV_SC_Pos (22UL)                /*!< SCUPM SYS_SUPPLY_IRQ_CLR: VS_OV_SC (Bit 22)           */
#define SCUPM_SYS_SUPPLY_IRQ_CLR_VS_OV_SC_Msk (0x400000UL)          /*!< SCUPM SYS_SUPPLY_IRQ_CLR: VS_OV_SC (Bitfield-Mask: 0x01) */
#define SCUPM_SYS_SUPPLY_IRQ_CLR_VBAT_OV_SC_Pos (21UL)              /*!< SCUPM SYS_SUPPLY_IRQ_CLR: VBAT_OV_SC (Bit 21)         */
#define SCUPM_SYS_SUPPLY_IRQ_CLR_VBAT_OV_SC_Msk (0x200000UL)        /*!< SCUPM SYS_SUPPLY_IRQ_CLR: VBAT_OV_SC (Bitfield-Mask: 0x01) */
#define SCUPM_SYS_SUPPLY_IRQ_CLR_VDDEXT_UV_SC_Pos (20UL)            /*!< SCUPM SYS_SUPPLY_IRQ_CLR: VDDEXT_UV_SC (Bit 20)       */
#define SCUPM_SYS_SUPPLY_IRQ_CLR_VDDEXT_UV_SC_Msk (0x100000UL)      /*!< SCUPM SYS_SUPPLY_IRQ_CLR: VDDEXT_UV_SC (Bitfield-Mask: 0x01) */
#define SCUPM_SYS_SUPPLY_IRQ_CLR_VDD1V5_UV_SC_Pos (19UL)            /*!< SCUPM SYS_SUPPLY_IRQ_CLR: VDD1V5_UV_SC (Bit 19)       */
#define SCUPM_SYS_SUPPLY_IRQ_CLR_VDD1V5_UV_SC_Msk (0x80000UL)       /*!< SCUPM SYS_SUPPLY_IRQ_CLR: VDD1V5_UV_SC (Bitfield-Mask: 0x01) */
#define SCUPM_SYS_SUPPLY_IRQ_CLR_VDD5V_UV_SC_Pos (18UL)             /*!< SCUPM SYS_SUPPLY_IRQ_CLR: VDD5V_UV_SC (Bit 18)        */
#define SCUPM_SYS_SUPPLY_IRQ_CLR_VDD5V_UV_SC_Msk (0x40000UL)        /*!< SCUPM SYS_SUPPLY_IRQ_CLR: VDD5V_UV_SC (Bitfield-Mask: 0x01) */
#define SCUPM_SYS_SUPPLY_IRQ_CLR_VS_UV_SC_Pos (17UL)                /*!< SCUPM SYS_SUPPLY_IRQ_CLR: VS_UV_SC (Bit 17)           */
#define SCUPM_SYS_SUPPLY_IRQ_CLR_VS_UV_SC_Msk (0x20000UL)           /*!< SCUPM SYS_SUPPLY_IRQ_CLR: VS_UV_SC (Bitfield-Mask: 0x01) */
#define SCUPM_SYS_SUPPLY_IRQ_CLR_VBAT_UV_SC_Pos (16UL)              /*!< SCUPM SYS_SUPPLY_IRQ_CLR: VBAT_UV_SC (Bit 16)         */
#define SCUPM_SYS_SUPPLY_IRQ_CLR_VBAT_UV_SC_Msk (0x10000UL)         /*!< SCUPM SYS_SUPPLY_IRQ_CLR: VBAT_UV_SC (Bitfield-Mask: 0x01) */
#define SCUPM_SYS_SUPPLY_IRQ_CLR_VDDEXT_OV_ISC_Pos (9UL)            /*!< SCUPM SYS_SUPPLY_IRQ_CLR: VDDEXT_OV_ISC (Bit 9)       */
#define SCUPM_SYS_SUPPLY_IRQ_CLR_VDDEXT_OV_ISC_Msk (0x200UL)        /*!< SCUPM SYS_SUPPLY_IRQ_CLR: VDDEXT_OV_ISC (Bitfield-Mask: 0x01) */
#define SCUPM_SYS_SUPPLY_IRQ_CLR_VDD1V5_OV_ISC_Pos (8UL)            /*!< SCUPM SYS_SUPPLY_IRQ_CLR: VDD1V5_OV_ISC (Bit 8)       */
#define SCUPM_SYS_SUPPLY_IRQ_CLR_VDD1V5_OV_ISC_Msk (0x100UL)        /*!< SCUPM SYS_SUPPLY_IRQ_CLR: VDD1V5_OV_ISC (Bitfield-Mask: 0x01) */
#define SCUPM_SYS_SUPPLY_IRQ_CLR_VDD5V_OV_ISC_Pos (7UL)             /*!< SCUPM SYS_SUPPLY_IRQ_CLR: VDD5V_OV_ISC (Bit 7)        */
#define SCUPM_SYS_SUPPLY_IRQ_CLR_VDD5V_OV_ISC_Msk (0x80UL)          /*!< SCUPM SYS_SUPPLY_IRQ_CLR: VDD5V_OV_ISC (Bitfield-Mask: 0x01) */
#define SCUPM_SYS_SUPPLY_IRQ_CLR_VS_OV_ISC_Pos (6UL)                /*!< SCUPM SYS_SUPPLY_IRQ_CLR: VS_OV_ISC (Bit 6)           */
#define SCUPM_SYS_SUPPLY_IRQ_CLR_VS_OV_ISC_Msk (0x40UL)             /*!< SCUPM SYS_SUPPLY_IRQ_CLR: VS_OV_ISC (Bitfield-Mask: 0x01) */
#define SCUPM_SYS_SUPPLY_IRQ_CLR_VBAT_OV_ISC_Pos (5UL)              /*!< SCUPM SYS_SUPPLY_IRQ_CLR: VBAT_OV_ISC (Bit 5)         */
#define SCUPM_SYS_SUPPLY_IRQ_CLR_VBAT_OV_ISC_Msk (0x20UL)           /*!< SCUPM SYS_SUPPLY_IRQ_CLR: VBAT_OV_ISC (Bitfield-Mask: 0x01) */
#define SCUPM_SYS_SUPPLY_IRQ_CLR_VDDEXT_UV_ISC_Pos (4UL)            /*!< SCUPM SYS_SUPPLY_IRQ_CLR: VDDEXT_UV_ISC (Bit 4)       */
#define SCUPM_SYS_SUPPLY_IRQ_CLR_VDDEXT_UV_ISC_Msk (0x10UL)         /*!< SCUPM SYS_SUPPLY_IRQ_CLR: VDDEXT_UV_ISC (Bitfield-Mask: 0x01) */
#define SCUPM_SYS_SUPPLY_IRQ_CLR_VDD1V5_UV_ISC_Pos (3UL)            /*!< SCUPM SYS_SUPPLY_IRQ_CLR: VDD1V5_UV_ISC (Bit 3)       */
#define SCUPM_SYS_SUPPLY_IRQ_CLR_VDD1V5_UV_ISC_Msk (0x8UL)          /*!< SCUPM SYS_SUPPLY_IRQ_CLR: VDD1V5_UV_ISC (Bitfield-Mask: 0x01) */
#define SCUPM_SYS_SUPPLY_IRQ_CLR_VDD5V_UV_ISC_Pos (2UL)             /*!< SCUPM SYS_SUPPLY_IRQ_CLR: VDD5V_UV_ISC (Bit 2)        */
#define SCUPM_SYS_SUPPLY_IRQ_CLR_VDD5V_UV_ISC_Msk (0x4UL)           /*!< SCUPM SYS_SUPPLY_IRQ_CLR: VDD5V_UV_ISC (Bitfield-Mask: 0x01) */
#define SCUPM_SYS_SUPPLY_IRQ_CLR_VS_UV_ISC_Pos (1UL)                /*!< SCUPM SYS_SUPPLY_IRQ_CLR: VS_UV_ISC (Bit 1)           */
#define SCUPM_SYS_SUPPLY_IRQ_CLR_VS_UV_ISC_Msk (0x2UL)              /*!< SCUPM SYS_SUPPLY_IRQ_CLR: VS_UV_ISC (Bitfield-Mask: 0x01) */
#define SCUPM_SYS_SUPPLY_IRQ_CLR_VBAT_UV_ISC_Pos (0UL)              /*!< SCUPM SYS_SUPPLY_IRQ_CLR: VBAT_UV_ISC (Bit 0)         */
#define SCUPM_SYS_SUPPLY_IRQ_CLR_VBAT_UV_ISC_Msk (0x1UL)            /*!< SCUPM SYS_SUPPLY_IRQ_CLR: VBAT_UV_ISC (Bitfield-Mask: 0x01) */
/* =====================================================  SYS_IRQ_CTRL  ====================================================== */
#define SCUPM_SYS_IRQ_CTRL_REFBG_UPTHWARN_IE_Pos (11UL)             /*!< SCUPM SYS_IRQ_CTRL: REFBG_UPTHWARN_IE (Bit 11)        */
#define SCUPM_SYS_IRQ_CTRL_REFBG_UPTHWARN_IE_Msk (0x800UL)          /*!< SCUPM SYS_IRQ_CTRL: REFBG_UPTHWARN_IE (Bitfield-Mask: 0x01) */
#define SCUPM_SYS_IRQ_CTRL_REFBG_LOTHWARN_IE_Pos (10UL)             /*!< SCUPM SYS_IRQ_CTRL: REFBG_LOTHWARN_IE (Bit 10)        */
#define SCUPM_SYS_IRQ_CTRL_REFBG_LOTHWARN_IE_Msk (0x400UL)          /*!< SCUPM SYS_IRQ_CTRL: REFBG_LOTHWARN_IE (Bitfield-Mask: 0x01) */
#define SCUPM_SYS_IRQ_CTRL_SYS_OT_IE_Pos  (9UL)                     /*!< SCUPM SYS_IRQ_CTRL: SYS_OT_IE (Bit 9)                 */
#define SCUPM_SYS_IRQ_CTRL_SYS_OT_IE_Msk  (0x200UL)                 /*!< SCUPM SYS_IRQ_CTRL: SYS_OT_IE (Bitfield-Mask: 0x01)   */
#define SCUPM_SYS_IRQ_CTRL_SYS_OTWARN_IE_Pos (8UL)                  /*!< SCUPM SYS_IRQ_CTRL: SYS_OTWARN_IE (Bit 8)             */
#define SCUPM_SYS_IRQ_CTRL_SYS_OTWARN_IE_Msk (0x100UL)              /*!< SCUPM SYS_IRQ_CTRL: SYS_OTWARN_IE (Bitfield-Mask: 0x01) */
/* ==================================================  SYS_SUPPLY_IRQ_CTRL  ================================================== */
#define SCUPM_SYS_SUPPLY_IRQ_CTRL_VDDEXT_OV_IE_Pos (9UL)            /*!< SCUPM SYS_SUPPLY_IRQ_CTRL: VDDEXT_OV_IE (Bit 9)       */
#define SCUPM_SYS_SUPPLY_IRQ_CTRL_VDDEXT_OV_IE_Msk (0x200UL)        /*!< SCUPM SYS_SUPPLY_IRQ_CTRL: VDDEXT_OV_IE (Bitfield-Mask: 0x01) */
#define SCUPM_SYS_SUPPLY_IRQ_CTRL_VDD1V5_OV_IE_Pos (8UL)            /*!< SCUPM SYS_SUPPLY_IRQ_CTRL: VDD1V5_OV_IE (Bit 8)       */
#define SCUPM_SYS_SUPPLY_IRQ_CTRL_VDD1V5_OV_IE_Msk (0x100UL)        /*!< SCUPM SYS_SUPPLY_IRQ_CTRL: VDD1V5_OV_IE (Bitfield-Mask: 0x01) */
#define SCUPM_SYS_SUPPLY_IRQ_CTRL_VDD5V_OV_IE_Pos (7UL)             /*!< SCUPM SYS_SUPPLY_IRQ_CTRL: VDD5V_OV_IE (Bit 7)        */
#define SCUPM_SYS_SUPPLY_IRQ_CTRL_VDD5V_OV_IE_Msk (0x80UL)          /*!< SCUPM SYS_SUPPLY_IRQ_CTRL: VDD5V_OV_IE (Bitfield-Mask: 0x01) */
#define SCUPM_SYS_SUPPLY_IRQ_CTRL_VS_OV_IE_Pos (6UL)                /*!< SCUPM SYS_SUPPLY_IRQ_CTRL: VS_OV_IE (Bit 6)           */
#define SCUPM_SYS_SUPPLY_IRQ_CTRL_VS_OV_IE_Msk (0x40UL)             /*!< SCUPM SYS_SUPPLY_IRQ_CTRL: VS_OV_IE (Bitfield-Mask: 0x01) */
#define SCUPM_SYS_SUPPLY_IRQ_CTRL_VBAT_OV_IE_Pos (5UL)              /*!< SCUPM SYS_SUPPLY_IRQ_CTRL: VBAT_OV_IE (Bit 5)         */
#define SCUPM_SYS_SUPPLY_IRQ_CTRL_VBAT_OV_IE_Msk (0x20UL)           /*!< SCUPM SYS_SUPPLY_IRQ_CTRL: VBAT_OV_IE (Bitfield-Mask: 0x01) */
#define SCUPM_SYS_SUPPLY_IRQ_CTRL_VDDEXT_UV_IE_Pos (4UL)            /*!< SCUPM SYS_SUPPLY_IRQ_CTRL: VDDEXT_UV_IE (Bit 4)       */
#define SCUPM_SYS_SUPPLY_IRQ_CTRL_VDDEXT_UV_IE_Msk (0x10UL)         /*!< SCUPM SYS_SUPPLY_IRQ_CTRL: VDDEXT_UV_IE (Bitfield-Mask: 0x01) */
#define SCUPM_SYS_SUPPLY_IRQ_CTRL_VDD1V5_UV_IE_Pos (3UL)            /*!< SCUPM SYS_SUPPLY_IRQ_CTRL: VDD1V5_UV_IE (Bit 3)       */
#define SCUPM_SYS_SUPPLY_IRQ_CTRL_VDD1V5_UV_IE_Msk (0x8UL)          /*!< SCUPM SYS_SUPPLY_IRQ_CTRL: VDD1V5_UV_IE (Bitfield-Mask: 0x01) */
#define SCUPM_SYS_SUPPLY_IRQ_CTRL_VDD5V_UV_IE_Pos (2UL)             /*!< SCUPM SYS_SUPPLY_IRQ_CTRL: VDD5V_UV_IE (Bit 2)        */
#define SCUPM_SYS_SUPPLY_IRQ_CTRL_VDD5V_UV_IE_Msk (0x4UL)           /*!< SCUPM SYS_SUPPLY_IRQ_CTRL: VDD5V_UV_IE (Bitfield-Mask: 0x01) */
#define SCUPM_SYS_SUPPLY_IRQ_CTRL_VS_UV_IE_Pos (1UL)                /*!< SCUPM SYS_SUPPLY_IRQ_CTRL: VS_UV_IE (Bit 1)           */
#define SCUPM_SYS_SUPPLY_IRQ_CTRL_VS_UV_IE_Msk (0x2UL)              /*!< SCUPM SYS_SUPPLY_IRQ_CTRL: VS_UV_IE (Bitfield-Mask: 0x01) */
#define SCUPM_SYS_SUPPLY_IRQ_CTRL_VBAT_UV_IE_Pos (0UL)              /*!< SCUPM SYS_SUPPLY_IRQ_CTRL: VBAT_UV_IE (Bit 0)         */
#define SCUPM_SYS_SUPPLY_IRQ_CTRL_VBAT_UV_IE_Msk (0x1UL)            /*!< SCUPM SYS_SUPPLY_IRQ_CTRL: VBAT_UV_IE (Bitfield-Mask: 0x01) */
/* =====================================================  PCU_CTRL_STS  ====================================================== */
#define SCUPM_PCU_CTRL_STS_LIN_VS_UV_SD_DIS_Pos (8UL)               /*!< SCUPM PCU_CTRL_STS: LIN_VS_UV_SD_DIS (Bit 8)          */
#define SCUPM_PCU_CTRL_STS_LIN_VS_UV_SD_DIS_Msk (0x100UL)           /*!< SCUPM PCU_CTRL_STS: LIN_VS_UV_SD_DIS (Bitfield-Mask: 0x01) */
#define SCUPM_PCU_CTRL_STS_CLKWDT_SD_DIS_Pos (1UL)                  /*!< SCUPM PCU_CTRL_STS: CLKWDT_SD_DIS (Bit 1)             */
#define SCUPM_PCU_CTRL_STS_CLKWDT_SD_DIS_Msk (0x2UL)                /*!< SCUPM PCU_CTRL_STS: CLKWDT_SD_DIS (Bitfield-Mask: 0x01) */
/* ========================================================  PKGCFG1  ======================================================== */
#define SCUPM_PKGCFG1_HS2EN_Pos           (8UL)                     /*!< SCUPM PKGCFG1: HS2EN (Bit 8)                          */
#define SCUPM_PKGCFG1_HS2EN_Msk           (0x100UL)                 /*!< SCUPM PKGCFG1: HS2EN (Bitfield-Mask: 0x01)            */
/* =======================================================  WDT1_TRIG  ======================================================= */
#define SCUPM_WDT1_TRIG_SOWCONF_Pos       (6UL)                     /*!< SCUPM WDT1_TRIG: SOWCONF (Bit 6)                      */
#define SCUPM_WDT1_TRIG_SOWCONF_Msk       (0xc0UL)                  /*!< SCUPM WDT1_TRIG: SOWCONF (Bitfield-Mask: 0x03)        */
#define SCUPM_WDT1_TRIG_WDP_SEL_Pos       (0UL)                     /*!< SCUPM WDT1_TRIG: WDP_SEL (Bit 0)                      */
#define SCUPM_WDT1_TRIG_WDP_SEL_Msk       (0x3fUL)                  /*!< SCUPM WDT1_TRIG: WDP_SEL (Bitfield-Mask: 0x3f)        */


/* =========================================================================================================================== */
/* ================                                           SSC1                                            ================ */
/* =========================================================================================================================== */

/* =========================================================  PISEL  ========================================================= */
#define SSC1_PISEL_MIS_1_Pos              (3UL)                     /*!< SSC1 PISEL: MIS_1 (Bit 3)                             */
#define SSC1_PISEL_MIS_1_Msk              (0x8UL)                   /*!< SSC1 PISEL: MIS_1 (Bitfield-Mask: 0x01)               */
#define SSC1_PISEL_CIS_Pos                (2UL)                     /*!< SSC1 PISEL: CIS (Bit 2)                               */
#define SSC1_PISEL_CIS_Msk                (0x4UL)                   /*!< SSC1 PISEL: CIS (Bitfield-Mask: 0x01)                 */
#define SSC1_PISEL_SIS_Pos                (1UL)                     /*!< SSC1 PISEL: SIS (Bit 1)                               */
#define SSC1_PISEL_SIS_Msk                (0x2UL)                   /*!< SSC1 PISEL: SIS (Bitfield-Mask: 0x01)                 */
#define SSC1_PISEL_MIS_0_Pos              (0UL)                     /*!< SSC1 PISEL: MIS_0 (Bit 0)                             */
#define SSC1_PISEL_MIS_0_Msk              (0x1UL)                   /*!< SSC1 PISEL: MIS_0 (Bitfield-Mask: 0x01)               */
/* ==========================================================  CON  ========================================================== */
#define SSC1_CON_BSY_Pos                  (28UL)                    /*!< SSC1 CON: BSY (Bit 28)                                */
#define SSC1_CON_BSY_Msk                  (0x10000000UL)            /*!< SSC1 CON: BSY (Bitfield-Mask: 0x01)                   */
#define SSC1_CON_BE_Pos                   (27UL)                    /*!< SSC1 CON: BE (Bit 27)                                 */
#define SSC1_CON_BE_Msk                   (0x8000000UL)             /*!< SSC1 CON: BE (Bitfield-Mask: 0x01)                    */
#define SSC1_CON_PE_Pos                   (26UL)                    /*!< SSC1 CON: PE (Bit 26)                                 */
#define SSC1_CON_PE_Msk                   (0x4000000UL)             /*!< SSC1 CON: PE (Bitfield-Mask: 0x01)                    */
#define SSC1_CON_RE_Pos                   (25UL)                    /*!< SSC1 CON: RE (Bit 25)                                 */
#define SSC1_CON_RE_Msk                   (0x2000000UL)             /*!< SSC1 CON: RE (Bitfield-Mask: 0x01)                    */
#define SSC1_CON_TE_Pos                   (24UL)                    /*!< SSC1 CON: TE (Bit 24)                                 */
#define SSC1_CON_TE_Msk                   (0x1000000UL)             /*!< SSC1 CON: TE (Bitfield-Mask: 0x01)                    */
#define SSC1_CON_BC_Pos                   (16UL)                    /*!< SSC1 CON: BC (Bit 16)                                 */
#define SSC1_CON_BC_Msk                   (0xf0000UL)               /*!< SSC1 CON: BC (Bitfield-Mask: 0x0f)                    */
#define SSC1_CON_EN_Pos                   (15UL)                    /*!< SSC1 CON: EN (Bit 15)                                 */
#define SSC1_CON_EN_Msk                   (0x8000UL)                /*!< SSC1 CON: EN (Bitfield-Mask: 0x01)                    */
#define SSC1_CON_MS_Pos                   (14UL)                    /*!< SSC1 CON: MS (Bit 14)                                 */
#define SSC1_CON_MS_Msk                   (0x4000UL)                /*!< SSC1 CON: MS (Bitfield-Mask: 0x01)                    */
#define SSC1_CON_AREN_Pos                 (12UL)                    /*!< SSC1 CON: AREN (Bit 12)                               */
#define SSC1_CON_AREN_Msk                 (0x1000UL)                /*!< SSC1 CON: AREN (Bitfield-Mask: 0x01)                  */
#define SSC1_CON_BEN_Pos                  (11UL)                    /*!< SSC1 CON: BEN (Bit 11)                                */
#define SSC1_CON_BEN_Msk                  (0x800UL)                 /*!< SSC1 CON: BEN (Bitfield-Mask: 0x01)                   */
#define SSC1_CON_PEN_Pos                  (10UL)                    /*!< SSC1 CON: PEN (Bit 10)                                */
#define SSC1_CON_PEN_Msk                  (0x400UL)                 /*!< SSC1 CON: PEN (Bitfield-Mask: 0x01)                   */
#define SSC1_CON_REN_Pos                  (9UL)                     /*!< SSC1 CON: REN (Bit 9)                                 */
#define SSC1_CON_REN_Msk                  (0x200UL)                 /*!< SSC1 CON: REN (Bitfield-Mask: 0x01)                   */
#define SSC1_CON_TEN_Pos                  (8UL)                     /*!< SSC1 CON: TEN (Bit 8)                                 */
#define SSC1_CON_TEN_Msk                  (0x100UL)                 /*!< SSC1 CON: TEN (Bitfield-Mask: 0x01)                   */
#define SSC1_CON_LB_Pos                   (7UL)                     /*!< SSC1 CON: LB (Bit 7)                                  */
#define SSC1_CON_LB_Msk                   (0x80UL)                  /*!< SSC1 CON: LB (Bitfield-Mask: 0x01)                    */
#define SSC1_CON_PO_Pos                   (6UL)                     /*!< SSC1 CON: PO (Bit 6)                                  */
#define SSC1_CON_PO_Msk                   (0x40UL)                  /*!< SSC1 CON: PO (Bitfield-Mask: 0x01)                    */
#define SSC1_CON_PH_Pos                   (5UL)                     /*!< SSC1 CON: PH (Bit 5)                                  */
#define SSC1_CON_PH_Msk                   (0x20UL)                  /*!< SSC1 CON: PH (Bitfield-Mask: 0x01)                    */
#define SSC1_CON_HB_Pos                   (4UL)                     /*!< SSC1 CON: HB (Bit 4)                                  */
#define SSC1_CON_HB_Msk                   (0x10UL)                  /*!< SSC1 CON: HB (Bitfield-Mask: 0x01)                    */
#define SSC1_CON_BM_Pos                   (0UL)                     /*!< SSC1 CON: BM (Bit 0)                                  */
#define SSC1_CON_BM_Msk                   (0xfUL)                   /*!< SSC1 CON: BM (Bitfield-Mask: 0x0f)                    */
/* ========================================================  ISRCLR  ========================================================= */
#define SSC1_ISRCLR_BECLR_Pos             (11UL)                    /*!< SSC1 ISRCLR: BECLR (Bit 11)                           */
#define SSC1_ISRCLR_BECLR_Msk             (0x800UL)                 /*!< SSC1 ISRCLR: BECLR (Bitfield-Mask: 0x01)              */
#define SSC1_ISRCLR_PECLR_Pos             (10UL)                    /*!< SSC1 ISRCLR: PECLR (Bit 10)                           */
#define SSC1_ISRCLR_PECLR_Msk             (0x400UL)                 /*!< SSC1 ISRCLR: PECLR (Bitfield-Mask: 0x01)              */
#define SSC1_ISRCLR_RECLR_Pos             (9UL)                     /*!< SSC1 ISRCLR: RECLR (Bit 9)                            */
#define SSC1_ISRCLR_RECLR_Msk             (0x200UL)                 /*!< SSC1 ISRCLR: RECLR (Bitfield-Mask: 0x01)              */
#define SSC1_ISRCLR_TECLR_Pos             (8UL)                     /*!< SSC1 ISRCLR: TECLR (Bit 8)                            */
#define SSC1_ISRCLR_TECLR_Msk             (0x100UL)                 /*!< SSC1 ISRCLR: TECLR (Bitfield-Mask: 0x01)              */
/* ==========================================================  BR  =========================================================== */
#define SSC1_BR_BR_VALUE_Pos              (0UL)                     /*!< SSC1 BR: BR_VALUE (Bit 0)                             */
#define SSC1_BR_BR_VALUE_Msk              (0xffffUL)                /*!< SSC1 BR: BR_VALUE (Bitfield-Mask: 0xffff)             */
/* ==========================================================  TB  =========================================================== */
#define SSC1_TB_TB_VALUE_Pos              (0UL)                     /*!< SSC1 TB: TB_VALUE (Bit 0)                             */
#define SSC1_TB_TB_VALUE_Msk              (0xffffUL)                /*!< SSC1 TB: TB_VALUE (Bitfield-Mask: 0xffff)             */
/* ==========================================================  RB  =========================================================== */
#define SSC1_RB_RB_VALUE_Pos              (0UL)                     /*!< SSC1 RB: RB_VALUE (Bit 0)                             */
#define SSC1_RB_RB_VALUE_Msk              (0xffffUL)                /*!< SSC1 RB: RB_VALUE (Bitfield-Mask: 0xffff)             */


/* =========================================================================================================================== */
/* ================                                           SSC2                                            ================ */
/* =========================================================================================================================== */

/* =========================================================  PISEL  ========================================================= */
#define SSC2_PISEL_MIS_1_Pos              (3UL)                     /*!< SSC2 PISEL: MIS_1 (Bit 3)                             */
#define SSC2_PISEL_MIS_1_Msk              (0x8UL)                   /*!< SSC2 PISEL: MIS_1 (Bitfield-Mask: 0x01)               */
#define SSC2_PISEL_CIS_Pos                (2UL)                     /*!< SSC2 PISEL: CIS (Bit 2)                               */
#define SSC2_PISEL_CIS_Msk                (0x4UL)                   /*!< SSC2 PISEL: CIS (Bitfield-Mask: 0x01)                 */
#define SSC2_PISEL_SIS_Pos                (1UL)                     /*!< SSC2 PISEL: SIS (Bit 1)                               */
#define SSC2_PISEL_SIS_Msk                (0x2UL)                   /*!< SSC2 PISEL: SIS (Bitfield-Mask: 0x01)                 */
#define SSC2_PISEL_MIS_0_Pos              (0UL)                     /*!< SSC2 PISEL: MIS_0 (Bit 0)                             */
#define SSC2_PISEL_MIS_0_Msk              (0x1UL)                   /*!< SSC2 PISEL: MIS_0 (Bitfield-Mask: 0x01)               */
/* ==========================================================  CON  ========================================================== */
#define SSC2_CON_BSY_Pos                  (28UL)                    /*!< SSC2 CON: BSY (Bit 28)                                */
#define SSC2_CON_BSY_Msk                  (0x10000000UL)            /*!< SSC2 CON: BSY (Bitfield-Mask: 0x01)                   */
#define SSC2_CON_BE_Pos                   (27UL)                    /*!< SSC2 CON: BE (Bit 27)                                 */
#define SSC2_CON_BE_Msk                   (0x8000000UL)             /*!< SSC2 CON: BE (Bitfield-Mask: 0x01)                    */
#define SSC2_CON_PE_Pos                   (26UL)                    /*!< SSC2 CON: PE (Bit 26)                                 */
#define SSC2_CON_PE_Msk                   (0x4000000UL)             /*!< SSC2 CON: PE (Bitfield-Mask: 0x01)                    */
#define SSC2_CON_RE_Pos                   (25UL)                    /*!< SSC2 CON: RE (Bit 25)                                 */
#define SSC2_CON_RE_Msk                   (0x2000000UL)             /*!< SSC2 CON: RE (Bitfield-Mask: 0x01)                    */
#define SSC2_CON_TE_Pos                   (24UL)                    /*!< SSC2 CON: TE (Bit 24)                                 */
#define SSC2_CON_TE_Msk                   (0x1000000UL)             /*!< SSC2 CON: TE (Bitfield-Mask: 0x01)                    */
#define SSC2_CON_BC_Pos                   (16UL)                    /*!< SSC2 CON: BC (Bit 16)                                 */
#define SSC2_CON_BC_Msk                   (0xf0000UL)               /*!< SSC2 CON: BC (Bitfield-Mask: 0x0f)                    */
#define SSC2_CON_EN_Pos                   (15UL)                    /*!< SSC2 CON: EN (Bit 15)                                 */
#define SSC2_CON_EN_Msk                   (0x8000UL)                /*!< SSC2 CON: EN (Bitfield-Mask: 0x01)                    */
#define SSC2_CON_MS_Pos                   (14UL)                    /*!< SSC2 CON: MS (Bit 14)                                 */
#define SSC2_CON_MS_Msk                   (0x4000UL)                /*!< SSC2 CON: MS (Bitfield-Mask: 0x01)                    */
#define SSC2_CON_AREN_Pos                 (12UL)                    /*!< SSC2 CON: AREN (Bit 12)                               */
#define SSC2_CON_AREN_Msk                 (0x1000UL)                /*!< SSC2 CON: AREN (Bitfield-Mask: 0x01)                  */
#define SSC2_CON_BEN_Pos                  (11UL)                    /*!< SSC2 CON: BEN (Bit 11)                                */
#define SSC2_CON_BEN_Msk                  (0x800UL)                 /*!< SSC2 CON: BEN (Bitfield-Mask: 0x01)                   */
#define SSC2_CON_PEN_Pos                  (10UL)                    /*!< SSC2 CON: PEN (Bit 10)                                */
#define SSC2_CON_PEN_Msk                  (0x400UL)                 /*!< SSC2 CON: PEN (Bitfield-Mask: 0x01)                   */
#define SSC2_CON_REN_Pos                  (9UL)                     /*!< SSC2 CON: REN (Bit 9)                                 */
#define SSC2_CON_REN_Msk                  (0x200UL)                 /*!< SSC2 CON: REN (Bitfield-Mask: 0x01)                   */
#define SSC2_CON_TEN_Pos                  (8UL)                     /*!< SSC2 CON: TEN (Bit 8)                                 */
#define SSC2_CON_TEN_Msk                  (0x100UL)                 /*!< SSC2 CON: TEN (Bitfield-Mask: 0x01)                   */
#define SSC2_CON_LB_Pos                   (7UL)                     /*!< SSC2 CON: LB (Bit 7)                                  */
#define SSC2_CON_LB_Msk                   (0x80UL)                  /*!< SSC2 CON: LB (Bitfield-Mask: 0x01)                    */
#define SSC2_CON_PO_Pos                   (6UL)                     /*!< SSC2 CON: PO (Bit 6)                                  */
#define SSC2_CON_PO_Msk                   (0x40UL)                  /*!< SSC2 CON: PO (Bitfield-Mask: 0x01)                    */
#define SSC2_CON_PH_Pos                   (5UL)                     /*!< SSC2 CON: PH (Bit 5)                                  */
#define SSC2_CON_PH_Msk                   (0x20UL)                  /*!< SSC2 CON: PH (Bitfield-Mask: 0x01)                    */
#define SSC2_CON_HB_Pos                   (4UL)                     /*!< SSC2 CON: HB (Bit 4)                                  */
#define SSC2_CON_HB_Msk                   (0x10UL)                  /*!< SSC2 CON: HB (Bitfield-Mask: 0x01)                    */
#define SSC2_CON_BM_Pos                   (0UL)                     /*!< SSC2 CON: BM (Bit 0)                                  */
#define SSC2_CON_BM_Msk                   (0xfUL)                   /*!< SSC2 CON: BM (Bitfield-Mask: 0x0f)                    */
/* ========================================================  ISRCLR  ========================================================= */
#define SSC2_ISRCLR_BECLR_Pos             (11UL)                    /*!< SSC2 ISRCLR: BECLR (Bit 11)                           */
#define SSC2_ISRCLR_BECLR_Msk             (0x800UL)                 /*!< SSC2 ISRCLR: BECLR (Bitfield-Mask: 0x01)              */
#define SSC2_ISRCLR_PECLR_Pos             (10UL)                    /*!< SSC2 ISRCLR: PECLR (Bit 10)                           */
#define SSC2_ISRCLR_PECLR_Msk             (0x400UL)                 /*!< SSC2 ISRCLR: PECLR (Bitfield-Mask: 0x01)              */
#define SSC2_ISRCLR_RECLR_Pos             (9UL)                     /*!< SSC2 ISRCLR: RECLR (Bit 9)                            */
#define SSC2_ISRCLR_RECLR_Msk             (0x200UL)                 /*!< SSC2 ISRCLR: RECLR (Bitfield-Mask: 0x01)              */
#define SSC2_ISRCLR_TECLR_Pos             (8UL)                     /*!< SSC2 ISRCLR: TECLR (Bit 8)                            */
#define SSC2_ISRCLR_TECLR_Msk             (0x100UL)                 /*!< SSC2 ISRCLR: TECLR (Bitfield-Mask: 0x01)              */
/* ==========================================================  BR  =========================================================== */
#define SSC2_BR_BR_VALUE_Pos              (0UL)                     /*!< SSC2 BR: BR_VALUE (Bit 0)                             */
#define SSC2_BR_BR_VALUE_Msk              (0xffffUL)                /*!< SSC2 BR: BR_VALUE (Bitfield-Mask: 0xffff)             */
/* ==========================================================  TB  =========================================================== */
#define SSC2_TB_TB_VALUE_Pos              (0UL)                     /*!< SSC2 TB: TB_VALUE (Bit 0)                             */
#define SSC2_TB_TB_VALUE_Msk              (0xffffUL)                /*!< SSC2 TB: TB_VALUE (Bitfield-Mask: 0xffff)             */
/* ==========================================================  RB  =========================================================== */
#define SSC2_RB_RB_VALUE_Pos              (0UL)                     /*!< SSC2 RB: RB_VALUE (Bit 0)                             */
#define SSC2_RB_RB_VALUE_Msk              (0xffffUL)                /*!< SSC2 RB: RB_VALUE (Bitfield-Mask: 0xffff)             */


/* =========================================================================================================================== */
/* ================                                          TIMER2                                           ================ */
/* =========================================================================================================================== */

/* ==========================================================  MOD  ========================================================== */
#define TIMER2_MOD_T2REGS_Pos             (7UL)                     /*!< TIMER2 MOD: T2REGS (Bit 7)                            */
#define TIMER2_MOD_T2REGS_Msk             (0x80UL)                  /*!< TIMER2 MOD: T2REGS (Bitfield-Mask: 0x01)              */
#define TIMER2_MOD_T2RHEN_Pos             (6UL)                     /*!< TIMER2 MOD: T2RHEN (Bit 6)                            */
#define TIMER2_MOD_T2RHEN_Msk             (0x40UL)                  /*!< TIMER2 MOD: T2RHEN (Bitfield-Mask: 0x01)              */
#define TIMER2_MOD_EDGESEL_Pos            (5UL)                     /*!< TIMER2 MOD: EDGESEL (Bit 5)                           */
#define TIMER2_MOD_EDGESEL_Msk            (0x20UL)                  /*!< TIMER2 MOD: EDGESEL (Bitfield-Mask: 0x01)             */
#define TIMER2_MOD_PREN_Pos               (4UL)                     /*!< TIMER2 MOD: PREN (Bit 4)                              */
#define TIMER2_MOD_PREN_Msk               (0x10UL)                  /*!< TIMER2 MOD: PREN (Bitfield-Mask: 0x01)                */
#define TIMER2_MOD_T2PRE_Pos              (1UL)                     /*!< TIMER2 MOD: T2PRE (Bit 1)                             */
#define TIMER2_MOD_T2PRE_Msk              (0xeUL)                   /*!< TIMER2 MOD: T2PRE (Bitfield-Mask: 0x07)               */
#define TIMER2_MOD_DCEN_Pos               (0UL)                     /*!< TIMER2 MOD: DCEN (Bit 0)                              */
#define TIMER2_MOD_DCEN_Msk               (0x1UL)                   /*!< TIMER2 MOD: DCEN (Bitfield-Mask: 0x01)                */
/* ==========================================================  CON  ========================================================== */
#define TIMER2_CON_TF2_Pos                (7UL)                     /*!< TIMER2 CON: TF2 (Bit 7)                               */
#define TIMER2_CON_TF2_Msk                (0x80UL)                  /*!< TIMER2 CON: TF2 (Bitfield-Mask: 0x01)                 */
#define TIMER2_CON_EXF2_Pos               (6UL)                     /*!< TIMER2 CON: EXF2 (Bit 6)                              */
#define TIMER2_CON_EXF2_Msk               (0x40UL)                  /*!< TIMER2 CON: EXF2 (Bitfield-Mask: 0x01)                */
#define TIMER2_CON_EXEN2_Pos              (3UL)                     /*!< TIMER2 CON: EXEN2 (Bit 3)                             */
#define TIMER2_CON_EXEN2_Msk              (0x8UL)                   /*!< TIMER2 CON: EXEN2 (Bitfield-Mask: 0x01)               */
#define TIMER2_CON_TR2_Pos                (2UL)                     /*!< TIMER2 CON: TR2 (Bit 2)                               */
#define TIMER2_CON_TR2_Msk                (0x4UL)                   /*!< TIMER2 CON: TR2 (Bitfield-Mask: 0x01)                 */
#define TIMER2_CON_C_T2_Pos               (1UL)                     /*!< TIMER2 CON: C_T2 (Bit 1)                              */
#define TIMER2_CON_C_T2_Msk               (0x2UL)                   /*!< TIMER2 CON: C_T2 (Bitfield-Mask: 0x01)                */
#define TIMER2_CON_CP_RL2_Pos             (0UL)                     /*!< TIMER2 CON: CP_RL2 (Bit 0)                            */
#define TIMER2_CON_CP_RL2_Msk             (0x1UL)                   /*!< TIMER2 CON: CP_RL2 (Bitfield-Mask: 0x01)              */
/* =========================================================  ICLR  ========================================================== */
#define TIMER2_ICLR_TF2CLR_Pos            (7UL)                     /*!< TIMER2 ICLR: TF2CLR (Bit 7)                           */
#define TIMER2_ICLR_TF2CLR_Msk            (0x80UL)                  /*!< TIMER2 ICLR: TF2CLR (Bitfield-Mask: 0x01)             */
#define TIMER2_ICLR_EXF2CLR_Pos           (6UL)                     /*!< TIMER2 ICLR: EXF2CLR (Bit 6)                          */
#define TIMER2_ICLR_EXF2CLR_Msk           (0x40UL)                  /*!< TIMER2 ICLR: EXF2CLR (Bitfield-Mask: 0x01)            */
/* =========================================================  CON1  ========================================================== */
#define TIMER2_CON1_TF2EN_Pos             (1UL)                     /*!< TIMER2 CON1: TF2EN (Bit 1)                            */
#define TIMER2_CON1_TF2EN_Msk             (0x2UL)                   /*!< TIMER2 CON1: TF2EN (Bitfield-Mask: 0x01)              */
#define TIMER2_CON1_EXF2EN_Pos            (0UL)                     /*!< TIMER2 CON1: EXF2EN (Bit 0)                           */
#define TIMER2_CON1_EXF2EN_Msk            (0x1UL)                   /*!< TIMER2 CON1: EXF2EN (Bitfield-Mask: 0x01)             */
/* ==========================================================  RC  =========================================================== */
#define TIMER2_RC_RCH2_Pos                (8UL)                     /*!< TIMER2 RC: RCH2 (Bit 8)                               */
#define TIMER2_RC_RCH2_Msk                (0xff00UL)                /*!< TIMER2 RC: RCH2 (Bitfield-Mask: 0xff)                 */
#define TIMER2_RC_RCL2_Pos                (0UL)                     /*!< TIMER2 RC: RCL2 (Bit 0)                               */
#define TIMER2_RC_RCL2_Msk                (0xffUL)                  /*!< TIMER2 RC: RCL2 (Bitfield-Mask: 0xff)                 */
/* ==========================================================  CNT  ========================================================== */
#define TIMER2_CNT_T2H_Pos                (8UL)                     /*!< TIMER2 CNT: T2H (Bit 8)                               */
#define TIMER2_CNT_T2H_Msk                (0xff00UL)                /*!< TIMER2 CNT: T2H (Bitfield-Mask: 0xff)                 */
#define TIMER2_CNT_T2L_Pos                (0UL)                     /*!< TIMER2 CNT: T2L (Bit 0)                               */
#define TIMER2_CNT_T2L_Msk                (0xffUL)                  /*!< TIMER2 CNT: T2L (Bitfield-Mask: 0xff)                 */


/* =========================================================================================================================== */
/* ================                                          TIMER21                                          ================ */
/* =========================================================================================================================== */

/* ==========================================================  MOD  ========================================================== */
#define TIMER21_MOD_T2REGS_Pos            (7UL)                     /*!< TIMER21 MOD: T2REGS (Bit 7)                           */
#define TIMER21_MOD_T2REGS_Msk            (0x80UL)                  /*!< TIMER21 MOD: T2REGS (Bitfield-Mask: 0x01)             */
#define TIMER21_MOD_T2RHEN_Pos            (6UL)                     /*!< TIMER21 MOD: T2RHEN (Bit 6)                           */
#define TIMER21_MOD_T2RHEN_Msk            (0x40UL)                  /*!< TIMER21 MOD: T2RHEN (Bitfield-Mask: 0x01)             */
#define TIMER21_MOD_EDGESEL_Pos           (5UL)                     /*!< TIMER21 MOD: EDGESEL (Bit 5)                          */
#define TIMER21_MOD_EDGESEL_Msk           (0x20UL)                  /*!< TIMER21 MOD: EDGESEL (Bitfield-Mask: 0x01)            */
#define TIMER21_MOD_PREN_Pos              (4UL)                     /*!< TIMER21 MOD: PREN (Bit 4)                             */
#define TIMER21_MOD_PREN_Msk              (0x10UL)                  /*!< TIMER21 MOD: PREN (Bitfield-Mask: 0x01)               */
#define TIMER21_MOD_T2PRE_Pos             (1UL)                     /*!< TIMER21 MOD: T2PRE (Bit 1)                            */
#define TIMER21_MOD_T2PRE_Msk             (0xeUL)                   /*!< TIMER21 MOD: T2PRE (Bitfield-Mask: 0x07)              */
#define TIMER21_MOD_DCEN_Pos              (0UL)                     /*!< TIMER21 MOD: DCEN (Bit 0)                             */
#define TIMER21_MOD_DCEN_Msk              (0x1UL)                   /*!< TIMER21 MOD: DCEN (Bitfield-Mask: 0x01)               */
/* ==========================================================  CON  ========================================================== */
#define TIMER21_CON_TF2_Pos               (7UL)                     /*!< TIMER21 CON: TF2 (Bit 7)                              */
#define TIMER21_CON_TF2_Msk               (0x80UL)                  /*!< TIMER21 CON: TF2 (Bitfield-Mask: 0x01)                */
#define TIMER21_CON_EXF2_Pos              (6UL)                     /*!< TIMER21 CON: EXF2 (Bit 6)                             */
#define TIMER21_CON_EXF2_Msk              (0x40UL)                  /*!< TIMER21 CON: EXF2 (Bitfield-Mask: 0x01)               */
#define TIMER21_CON_EXEN2_Pos             (3UL)                     /*!< TIMER21 CON: EXEN2 (Bit 3)                            */
#define TIMER21_CON_EXEN2_Msk             (0x8UL)                   /*!< TIMER21 CON: EXEN2 (Bitfield-Mask: 0x01)              */
#define TIMER21_CON_TR2_Pos               (2UL)                     /*!< TIMER21 CON: TR2 (Bit 2)                              */
#define TIMER21_CON_TR2_Msk               (0x4UL)                   /*!< TIMER21 CON: TR2 (Bitfield-Mask: 0x01)                */
#define TIMER21_CON_C_T2_Pos              (1UL)                     /*!< TIMER21 CON: C_T2 (Bit 1)                             */
#define TIMER21_CON_C_T2_Msk              (0x2UL)                   /*!< TIMER21 CON: C_T2 (Bitfield-Mask: 0x01)               */
#define TIMER21_CON_CP_RL2_Pos            (0UL)                     /*!< TIMER21 CON: CP_RL2 (Bit 0)                           */
#define TIMER21_CON_CP_RL2_Msk            (0x1UL)                   /*!< TIMER21 CON: CP_RL2 (Bitfield-Mask: 0x01)             */
/* =========================================================  ICLR  ========================================================== */
#define TIMER21_ICLR_TF2CLR_Pos           (7UL)                     /*!< TIMER21 ICLR: TF2CLR (Bit 7)                          */
#define TIMER21_ICLR_TF2CLR_Msk           (0x80UL)                  /*!< TIMER21 ICLR: TF2CLR (Bitfield-Mask: 0x01)            */
#define TIMER21_ICLR_EXF2CLR_Pos          (6UL)                     /*!< TIMER21 ICLR: EXF2CLR (Bit 6)                         */
#define TIMER21_ICLR_EXF2CLR_Msk          (0x40UL)                  /*!< TIMER21 ICLR: EXF2CLR (Bitfield-Mask: 0x01)           */
/* =========================================================  CON1  ========================================================== */
#define TIMER21_CON1_TF2EN_Pos            (1UL)                     /*!< TIMER21 CON1: TF2EN (Bit 1)                           */
#define TIMER21_CON1_TF2EN_Msk            (0x2UL)                   /*!< TIMER21 CON1: TF2EN (Bitfield-Mask: 0x01)             */
#define TIMER21_CON1_EXF2EN_Pos           (0UL)                     /*!< TIMER21 CON1: EXF2EN (Bit 0)                          */
#define TIMER21_CON1_EXF2EN_Msk           (0x1UL)                   /*!< TIMER21 CON1: EXF2EN (Bitfield-Mask: 0x01)            */
/* ==========================================================  RC  =========================================================== */
#define TIMER21_RC_RCH2_Pos               (8UL)                     /*!< TIMER21 RC: RCH2 (Bit 8)                              */
#define TIMER21_RC_RCH2_Msk               (0xff00UL)                /*!< TIMER21 RC: RCH2 (Bitfield-Mask: 0xff)                */
#define TIMER21_RC_RCL2_Pos               (0UL)                     /*!< TIMER21 RC: RCL2 (Bit 0)                              */
#define TIMER21_RC_RCL2_Msk               (0xffUL)                  /*!< TIMER21 RC: RCL2 (Bitfield-Mask: 0xff)                */
/* ==========================================================  CNT  ========================================================== */
#define TIMER21_CNT_T2H_Pos               (8UL)                     /*!< TIMER21 CNT: T2H (Bit 8)                              */
#define TIMER21_CNT_T2H_Msk               (0xff00UL)                /*!< TIMER21 CNT: T2H (Bitfield-Mask: 0xff)                */
#define TIMER21_CNT_T2L_Pos               (0UL)                     /*!< TIMER21 CNT: T2L (Bit 0)                              */
#define TIMER21_CNT_T2L_Msk               (0xffUL)                  /*!< TIMER21 CNT: T2L (Bitfield-Mask: 0xff)                */


/* =========================================================================================================================== */
/* ================                                           UART1                                           ================ */
/* =========================================================================================================================== */

/* =========================================================  SBUF  ========================================================== */
#define UART1_SBUF_VAL_Pos                (0UL)                     /*!< UART1 SBUF: VAL (Bit 0)                               */
#define UART1_SBUF_VAL_Msk                (0xffUL)                  /*!< UART1 SBUF: VAL (Bitfield-Mask: 0xff)                 */
/* =========================================================  SCON  ========================================================== */
#define UART1_SCON_SM0_Pos                (7UL)                     /*!< UART1 SCON: SM0 (Bit 7)                               */
#define UART1_SCON_SM0_Msk                (0x80UL)                  /*!< UART1 SCON: SM0 (Bitfield-Mask: 0x01)                 */
#define UART1_SCON_SM1_Pos                (6UL)                     /*!< UART1 SCON: SM1 (Bit 6)                               */
#define UART1_SCON_SM1_Msk                (0x40UL)                  /*!< UART1 SCON: SM1 (Bitfield-Mask: 0x01)                 */
#define UART1_SCON_SM2_Pos                (5UL)                     /*!< UART1 SCON: SM2 (Bit 5)                               */
#define UART1_SCON_SM2_Msk                (0x20UL)                  /*!< UART1 SCON: SM2 (Bitfield-Mask: 0x01)                 */
#define UART1_SCON_REN_Pos                (4UL)                     /*!< UART1 SCON: REN (Bit 4)                               */
#define UART1_SCON_REN_Msk                (0x10UL)                  /*!< UART1 SCON: REN (Bitfield-Mask: 0x01)                 */
#define UART1_SCON_TB8_Pos                (3UL)                     /*!< UART1 SCON: TB8 (Bit 3)                               */
#define UART1_SCON_TB8_Msk                (0x8UL)                   /*!< UART1 SCON: TB8 (Bitfield-Mask: 0x01)                 */
#define UART1_SCON_RB8_Pos                (2UL)                     /*!< UART1 SCON: RB8 (Bit 2)                               */
#define UART1_SCON_RB8_Msk                (0x4UL)                   /*!< UART1 SCON: RB8 (Bitfield-Mask: 0x01)                 */
#define UART1_SCON_TI_Pos                 (1UL)                     /*!< UART1 SCON: TI (Bit 1)                                */
#define UART1_SCON_TI_Msk                 (0x2UL)                   /*!< UART1 SCON: TI (Bitfield-Mask: 0x01)                  */
#define UART1_SCON_RI_Pos                 (0UL)                     /*!< UART1 SCON: RI (Bit 0)                                */
#define UART1_SCON_RI_Msk                 (0x1UL)                   /*!< UART1 SCON: RI (Bitfield-Mask: 0x01)                  */
/* ========================================================  SCONCLR  ======================================================== */
#define UART1_SCONCLR_RB8CLR_Pos          (2UL)                     /*!< UART1 SCONCLR: RB8CLR (Bit 2)                         */
#define UART1_SCONCLR_RB8CLR_Msk          (0x4UL)                   /*!< UART1 SCONCLR: RB8CLR (Bitfield-Mask: 0x01)           */
#define UART1_SCONCLR_TICLR_Pos           (1UL)                     /*!< UART1 SCONCLR: TICLR (Bit 1)                          */
#define UART1_SCONCLR_TICLR_Msk           (0x2UL)                   /*!< UART1 SCONCLR: TICLR (Bitfield-Mask: 0x01)            */
#define UART1_SCONCLR_RICLR_Pos           (0UL)                     /*!< UART1 SCONCLR: RICLR (Bit 0)                          */
#define UART1_SCONCLR_RICLR_Msk           (0x1UL)                   /*!< UART1 SCONCLR: RICLR (Bitfield-Mask: 0x01)            */


/* =========================================================================================================================== */
/* ================                                           UART2                                           ================ */
/* =========================================================================================================================== */

/* =========================================================  SBUF  ========================================================== */
#define UART2_SBUF_VAL_Pos                (0UL)                     /*!< UART2 SBUF: VAL (Bit 0)                               */
#define UART2_SBUF_VAL_Msk                (0xffUL)                  /*!< UART2 SBUF: VAL (Bitfield-Mask: 0xff)                 */
/* =========================================================  SCON  ========================================================== */
#define UART2_SCON_SM0_Pos                (7UL)                     /*!< UART2 SCON: SM0 (Bit 7)                               */
#define UART2_SCON_SM0_Msk                (0x80UL)                  /*!< UART2 SCON: SM0 (Bitfield-Mask: 0x01)                 */
#define UART2_SCON_SM1_Pos                (6UL)                     /*!< UART2 SCON: SM1 (Bit 6)                               */
#define UART2_SCON_SM1_Msk                (0x40UL)                  /*!< UART2 SCON: SM1 (Bitfield-Mask: 0x01)                 */
#define UART2_SCON_SM2_Pos                (5UL)                     /*!< UART2 SCON: SM2 (Bit 5)                               */
#define UART2_SCON_SM2_Msk                (0x20UL)                  /*!< UART2 SCON: SM2 (Bitfield-Mask: 0x01)                 */
#define UART2_SCON_REN_Pos                (4UL)                     /*!< UART2 SCON: REN (Bit 4)                               */
#define UART2_SCON_REN_Msk                (0x10UL)                  /*!< UART2 SCON: REN (Bitfield-Mask: 0x01)                 */
#define UART2_SCON_TB8_Pos                (3UL)                     /*!< UART2 SCON: TB8 (Bit 3)                               */
#define UART2_SCON_TB8_Msk                (0x8UL)                   /*!< UART2 SCON: TB8 (Bitfield-Mask: 0x01)                 */
#define UART2_SCON_RB8_Pos                (2UL)                     /*!< UART2 SCON: RB8 (Bit 2)                               */
#define UART2_SCON_RB8_Msk                (0x4UL)                   /*!< UART2 SCON: RB8 (Bitfield-Mask: 0x01)                 */
#define UART2_SCON_TI_Pos                 (1UL)                     /*!< UART2 SCON: TI (Bit 1)                                */
#define UART2_SCON_TI_Msk                 (0x2UL)                   /*!< UART2 SCON: TI (Bitfield-Mask: 0x01)                  */
#define UART2_SCON_RI_Pos                 (0UL)                     /*!< UART2 SCON: RI (Bit 0)                                */
#define UART2_SCON_RI_Msk                 (0x1UL)                   /*!< UART2 SCON: RI (Bitfield-Mask: 0x01)                  */
/* ========================================================  SCONCLR  ======================================================== */
#define UART2_SCONCLR_RB8CLR_Pos          (2UL)                     /*!< UART2 SCONCLR: RB8CLR (Bit 2)                         */
#define UART2_SCONCLR_RB8CLR_Msk          (0x4UL)                   /*!< UART2 SCONCLR: RB8CLR (Bitfield-Mask: 0x01)           */
#define UART2_SCONCLR_TICLR_Pos           (1UL)                     /*!< UART2 SCONCLR: TICLR (Bit 1)                          */
#define UART2_SCONCLR_TICLR_Msk           (0x2UL)                   /*!< UART2 SCONCLR: TICLR (Bitfield-Mask: 0x01)            */
#define UART2_SCONCLR_RICLR_Pos           (0UL)                     /*!< UART2 SCONCLR: RICLR (Bit 0)                          */
#define UART2_SCONCLR_RICLR_Msk           (0x1UL)                   /*!< UART2 SCONCLR: RICLR (Bitfield-Mask: 0x01)            */

/** @} */ /* End of group PosMask_peripherals */

/** @} */ /* End of group TLE984x */
/** @} */ /* End of group Infineon Technologies AG */

#ifdef __cplusplus
}
#endif


#endif  /* TLE984x_H */

