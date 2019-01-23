/**
 * @cond
 ***********************************************************************************************************************
 *
 * Copyright (c) 2017, Infineon Technologies AG
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

/*******************************************************************************
**                      Author(s) Identity                                    **
********************************************************************************
**                                                                            **
** Initials     Name                                                          **
** ---------------------------------------------------------------------------**
** DM           Daniel Mysliwitz                                              **
** TA           Thomas Albersinger                                            **
** AV           Axel Viebig                                                   **
** KC           Kay Claussen                                                  **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/* 
 * V0.1.0: 2015-09-30, AV:   Initial version, ported from V0.5.1 (Proteus SDK)
 * V0.1.1: 2015-11-27, AV:   Include ssc_defines.h (def. SCU_MODPISEL)
 * V0.1.2: 2017-06-19, KC:   global variable SystemFrequency added
 *                           global interrupt disabled during SCU_ClkInit()
 * V0.3.0: 2017-10-20, KC:   Removed conditional compilation for
 *                           SCU_EnterSleepMode() and SCU_EnterStopMode()
 *                           Version jump to be consistent with pdsc-file
 * V0.3.1: 2017-12-06, KC:   Dummy read (GPIO_WAKE_STATUS) fixes problems 
 *                             when entering sleep mode
 *                           For XTAL enabling MODPISEL1 is set in SCU_ClkInit()
 * V0.3.2: 2017-12-08, KC:   SCU_EnterSleepMode(): LIN functions removed and
 *                             dummy read of CNF_WAKE_FILTER added
 *                           Include of lin.h removed
 *                           Variable type of "dummy" changed to 32bit
 */

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "scu.h"
#include "wdt1.h"
#include "scu_defines.h"

/*******************************************************************************
**                      External CallBacks                                    **
*******************************************************************************/

/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/
uint32 SystemFrequency = (uint32)SCU_FSYS;

/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
/** \brief Initializes the system clocks.
 *
 * \param None
 * \return None
 *
 * \ingroup drv_api
 */
void SCU_ClkInit(void)
{
  /* disable all interrupts                */
  __disable_irq();
  /***************************************************************************
   ** NVM Protection Control                                                **
   ***************************************************************************/
/*lint -e534 Supressing MISRA 2012 MISRA 2012 Directive 4.7 */
#if (SCU_NVM_BOOT_PROT == 1)
  user_nvm_protect_set((uint32) SCU_NVM_PROT_PW, (NVM_PASSWORD_SEGMENT_t)SCU_NVM_BOOT_PROT);
#endif
#if (SCU_NVM_CODE_PROT == 1)
  user_nvm_protect_set((uint32) SCU_NVM_PROT_PW, (NVM_PASSWORD_SEGMENT_t)SCU_NVM_CODE_PROT);
#endif
#if (SCU_NVM_DATA_PROT == 1)
  user_nvm_protect_set((uint32) SCU_NVM_PROT_PW, (NVM_PASSWORD_SEGMENT_t)SCU_NVM_DATA_PROT);
#endif
/*lint +e534 */
   /**************************************************************************
    ** PLL/SYSCLK Control                                                   **
    **************************************************************************/
  SCU->NMICON.bit.NMIPLL = 0u;

  /* enable XTAL1/2 pins */
  SCU->PASSWD.reg = PASSWD_Open;
  SCU->MODPISEL1.reg = (uint32)(SCU_MODPISEL1 & SCU_MODPISEL1_XTAL12EN_Msk);
  SCU->PASSWD.reg = PASSWD_Close;

  /* select LP_CLK */
  SCU->PASSWD.reg = PASSWD_Open;
  SCU->SYSCON0.bit.SYSCLKSEL = 3u;
  SCU->PASSWD.reg = PASSWD_Close;

  /* Oscillator Select */
  SCU->PASSWD.reg = PASSWD_Open;
  SCU->OSC_CON.reg = (uint32)SCU_OSC_CON;
  SCU->PASSWD.reg = PASSWD_Close;

  SCU->PASSWD.reg = PASSWD_Open;
  SCU->PLL_CON.reg = (uint32) SCU_PLL_CON;
  SCU->PASSWD.reg = PASSWD_Close;

  SCU->PASSWD.reg = PASSWD_Open;
  SCU->CMCON1.reg = (uint32) SCU_CMCON1;
  SCU->PASSWD.reg = PASSWD_Close;

  SCU->PLL_CON.bit.RESLD = 1u;
  /* set PLL_CON.bit.VCOBYP=0 */
  SCU->PLL_CON.reg=(SCU->PLL_CON.reg&~SCU_PLL_CON_VCOBYP_Msk)|SCU_PLL_CON_UNPROT_VCOBYP_Msk;
  /* set PLL_CON.bit.OSCDISC=0 */
  SCU->PLL_CON.reg=(SCU->PLL_CON.reg&~SCU_PLL_CON_OSCDISC_Msk)|SCU_PLL_CON_UNPROT_OSCDISC_Msk;

  while (SCU->PLL_CON.bit.LOCK == 0u)
  {
  }

  SCU->PASSWD.reg = PASSWD_Open;
  /* 0u << 6u */
  SCU->SYSCON0.reg = 0u;
  SCU->PASSWD.reg = PASSWD_Close;

  SCU->NMISRCLR.bit.FNMIPLLC = 1u;
  
  /***************************************************************************
   ** Analog Clock Control                                                  **
   ***************************************************************************/

  /* set factor for MI_CLK and Filt_CLK*/
  SCU->APCLK.reg = (uint32) SCU_APCLK;

  /* apply setting by toggling APCLK_SET */
  SCU->PASSWD.reg = 0x98;
  SCU->APCLK_CTRL.bit.APCLK_SET = 1u;
  SCU->PASSWD.reg = 0xA8;
  __NOP();
  SCU->PASSWD.reg = 0x98;
  SCU->APCLK_CTRL.bit.APCLK_SET = 0u;
  SCU->PASSWD.reg = 0xA8;

  /* enable interrupts                     */
  __enable_irq();
}


/** \brief Initializes the SCU module.
 *
 * \param None
 * \return None
 *
 * \ingroup drv_api
 */
void SCU_Init(void)
{
  /***************************************************************************
   ** System Clock Output Control                                           **
   ***************************************************************************/
  SCU->COCON.reg = (uint32) (SCU_COCON);

 /***************************************************************************
  ** Module Pin Select                                                     **
  **************************************************************************/
#ifdef SCU_MODPISEL
  SCU->MODPISEL.reg = (uint32) SCU_MODPISEL;
#endif
#ifdef SCU_MODPISEL1
  SCU->MODPISEL1.reg = (uint8) SCU_MODPISEL1;
#endif
#ifdef SCU_MODPISEL2
  SCU->MODPISEL2.reg = (uint8) SCU_MODPISEL2;
#endif
#ifdef SCU_MODPISEL3
  SCU->MODPISEL3.reg = (uint8) SCU_MODPISEL3;
#endif
  SCU->GPT12PISEL.reg = (uint8) SCU_GPT12PISEL;
}

/** \brief Sets the device into Sleep Mode
 *
 * \param[in] none
 * \param[in] 
 * \return nothing
 *
 * \ingroup scu_api
 */
void SCU_EnterSleepMode(void)
{
  /* This function assumes the desired wake up sources are enabled already   */
  uint32 dummy;
  /* to remove compiler warning of unused dummy variable                     */
  dummy = dummy;
  /* dummy read to clr wake up status to prevent the device from wakeing up  *
   * immediately because of still set wake up flags                          */
  dummy = PMU->WAKE_STATUS.reg;
  dummy = PMU->GPIO_WAKE_STATUS.reg;
  dummy = PMU->CNF_WAKE_FILTER.reg;  
  /* stop WDT1 (SysTick) to prevent any SysTick interrupt to disturb the     *
   * Sleep Mode Entry sequence                                               */
  WDT1_Stop();
  /* Trigger a ShortOpenWindow on WDT1 to prevent an unserviced WDT1 by      *
   * accident                                                                */
  WDT1_SOW_Service(1);
  __disable_irq(); /* disable all interrupts                                 */
  SCU->PASSWD.reg = PASSWD_Open; /* open passwd to access PMCON0 register    */
  if (SCU->PASSWD.bit.PROTECT_S == 0) /* check if pw protection is opened    */
  {
    SCU->PMCON0.reg = 0x02; /* set SleepMode flag in PMCON0 */
/*lint -e718 Supressing MISRA 2012 Rule 17.3 */
/*lint -e746 Supressing MISRA 2012 Rule 10.4 */
    __SEV();
    __WFE();
    __WFE();
/*lint +e746 */
/*lint +e718 */
    /* dont do anything anymore device is in SleepMode */
    while (1)
    {
    }
    /* device is in Sleep Mode now wake up performes RESET */
  }
  /* program execution should not come here unless the passwd protection     *
   * opening did not work                                                    */
  SCU->IEN0.bit.EA = 1;
  WDT1_Init();
}

/** \brief Sets the device into Stop Mode
 *
 * \param[in] nothing
 * \param[in]
 * \return nothing
 *
 * \ingroup scu_api
 */
void SCU_EnterStopMode(void)
{
  uint32 dummy;
  /* to remove compiler warning of unused  *
   * dummy variable                        */
  dummy = dummy;
  /* dummy read to clr wake up status      *
   * to prevent the device from wakeing up *
   * immediately because of still set      *
   * wake up flags                         */
  dummy = PMU->WAKE_STATUS.reg;
  /* stop WDT1 (SysTick) to prevent any    *
   * SysTick interrupt to disturb the      *
   * Sleep Mode Entry sequence             */
  WDT1_Stop();
  /* Trigger a ShortOpenWindow on WDT1     *
   * to prevent an unserviced WDT1 by      *
   * accident                              */
  WDT1_SOW_Service(1);
  /* disable all interrupts                */
  __disable_irq();

  /* select LP_CLK as sys clock            */
  SCU->PASSWD.reg = PASSWD_Open;
  SCU->SYSCON0.bit.SYSCLKSEL = 3U;
  SCU->PASSWD.reg = PASSWD_Close;

  /* select OSC_PLL async.                 */
  SCU->PASSWD.reg = PASSWD_Open;
  SCU->OSC_CON.bit.OSCSS = 3U;
  SCU->PASSWD.reg = PASSWD_Close;

  /* open passwd to access PMCON0 register */
  SCU->PASSWD.reg = PASSWD_Open;
  /* check if pwsswd protection is opened  */
  if (SCU->PASSWD.bit.PROTECT_S == 0)
  {
    /* set PowerDown flag in PMCON0        */
    SCU->PMCON0.reg = 0x04;
/*lint -e718 Supressing MISRA 2012 Rule 17.3 */
/*lint -e746 Supressing MISRA 2012 Rule 10.4 */
  __SEV();
  __WFE();
  __WFE();
  __NOP();
  __NOP();
  __NOP();
  __NOP();
/*lint +e746 */
/*lint +e718 */
    /* dont do anything anymore            *
     * device is in PowerDown Mode         */
    /***************************************/
    /********* DEVICE IN STOP MODE *********/
    /***************************************/
    /* Device has been woken up            */
    /* reset PLL locking                   */
    SCU->PLL_CON.bit.RESLD = 1;
    SCU->PLL_CON.reg=(SCU->PLL_CON.reg&~1u<<3u)|1u<<11u;  // set PLL_CON.bit.VCOBYP=0
    SCU->PLL_CON.reg=(SCU->PLL_CON.reg&~1u<<2u)|1u<<10u;  // set PLL_CON.bit.OSCDISC=0
    
    /* wait for PLL being locked           */
    while (SCU->PLL_CON.bit.LOCK == 0)
    {
    }
    /* switch fSYS back to                 *
     * user configuration                  */
    SCU->PASSWD.reg = PASSWD_Open;
    SCU->SYSCON0.reg = (uint8) (0 << 6);
    SCU->PASSWD.reg = PASSWD_Close;
  }
  /* enable interrupts                     */
  __enable_irq();
  /* Init and service WDT1                 */
  WDT1_Init();
}

/** \brief Sets the device into Slow Mode
 *
 * \param[in] nothing
 * \param[in]
 * \return nothing
 *
 * \ingroup scu_api
 */
void SCU_EnterSlowMode(void)
{
  /* stop WDT1 (SysTick) to prevent any    *
   * SysTick interrupt to disturb the      *
   * Sleep Mode Entry sequence             */
  WDT1_Stop();
  /* Trigger a ShortOpenWindow on WDT1     *
   * to prevent an unserviced WDT1 by      *
   * accident                              */
  WDT1_SOW_Service((uint8) 1);
  /* disable all interrupts                */
  __disable_irq();
  /* open passwd to access PMCON0 register */
  SCU->PASSWD.reg = PASSWD_Open;
  /* check if pwsswd protection is opened  */
  if ((uint8) SCU->PASSWD.bit.PROTECT_S == (uint8) 0)
  {
    /* set PowerDown flag in PMCON0        */
    SCU->PMCON0.reg = 0x08;
/*lint -e718 Supressing MISRA 2012 Rule 17.3 */
/*lint -e746 Supressing MISRA 2012 Rule 10.4 */
    __WFE();
    __WFE();
/*lint +e746 */
/*lint +e718 */
    /* dont do anything anymore            *
     * device is in PowerDown Mode         */
    /***************************************/
    /********* DEVICE IN SLOW MODE *********/
    /***************************************/
  }
  /* enable interrupts                     */
  __enable_irq();
  /* Init and service WDT1                 */
  WDT1_Init();
}

/** \brief Gets the device out of Slow Mode
 *
 * \param[in] nothing
 * \param[in]
 * \return nothing
 *
 * \ingroup scu_api
 */
void SCU_ExitSlowMode(void)
{
  /* stop WDT1 (SysTick) to prevent any    *
   * SysTick interrupt to disturb the      *
   * Sleep Mode Entry sequence             */
  WDT1_Stop();
  /* Trigger a ShortOpenWindow on WDT1     *
   * to prevent an unserviced WDT1 by      *
   * accident                              */
  WDT1_SOW_Service((uint8) 1);
  /* disable all interrupts                */
  __disable_irq();
  /* open access to SYSCLKSEL register     */
  SCU->PASSWD.reg = PASSWD_Open;
  /* select LP_CLK as sys clock            */
  SCU->SYSCON0.bit.SYSCLKSEL = 3U;
  SCU->PASSWD.reg = PASSWD_Close;
  /* open passwd to access PMCON0 register */
  SCU->PASSWD.reg = PASSWD_Open;
  /* check if pwsswd protection is opened  */
  if ((uint8) SCU->PASSWD.bit.PROTECT_S == (uint8) 0)
  {
    /* set PowerDown flag in PMCON0        */
    SCU->PMCON0.reg = ~(uint8) 0x08;
    __WFE();
    /* dont do anything anymore            *
     * device is in PowerDown Mode         */
    /***************************************/
    /***** DEVICE back in NORMAL MODE ******/
    /***************************************/
  }
  /* enable interrupts                     */
  __enable_irq();
  /* Init and service WDT1                 */
  WDT1_Init();
}

/** \brief Sets the Write/Read Protection for the Code/Data Flash
 *
 * \param[in] Protection: BOOT/CODE/DATA
 * \param[in] Action: CLEAR/SET
 * \return ERR_LOG_SUCCESS or error code
 *
 * \ingroup scu_api
 */
int32_t SCU_ChangeNVMProtection(NVM_PASSWORD_SEGMENT_t Protection, uint8 Action)
{
  if (Action == PROTECTION_CLEAR)
  {
    if (Protection == NVM_PASSWORD_SEGMENT_BOOT)
    {
      return user_nvm_protect_clear((uint32) SCU_NVM_PROT_PW, (NVM_PASSWORD_SEGMENT_t) Protection);
    }
    else if (Protection == NVM_PASSWORD_SEGMENT_CODE)
    {
      return user_nvm_protect_clear((uint32) SCU_NVM_PROT_PW, (NVM_PASSWORD_SEGMENT_t) Protection);
    }
    else if (Protection == NVM_PASSWORD_SEGMENT_DATA)
    {
      return user_nvm_protect_clear((uint32) SCU_NVM_PROT_PW, (NVM_PASSWORD_SEGMENT_t) Protection);
    }
  }
  else
  {
    if (Protection == NVM_PASSWORD_SEGMENT_BOOT)
    {
      return user_nvm_protect_set((uint32) SCU_NVM_PROT_PW, (NVM_PASSWORD_SEGMENT_t) Protection);
    }
    else if (Protection == NVM_PASSWORD_SEGMENT_CODE)
    {
      return user_nvm_protect_set((uint32) SCU_NVM_PROT_PW, (NVM_PASSWORD_SEGMENT_t) Protection);
    }  
    else if (Protection == NVM_PASSWORD_SEGMENT_DATA)
    {
      return user_nvm_protect_set((uint32) SCU_NVM_PROT_PW, (NVM_PASSWORD_SEGMENT_t) Protection);
    }
  }
  return ERR_LOG_ERROR;
}
