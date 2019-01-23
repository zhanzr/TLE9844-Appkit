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
 * V0.1.1: 2015-11-06, AV:   Improved UART init/send routines (now blocking 
 *                             until send is complete). Intended for sending
 *                             from low(est) priority task.
 * V0.1.2: 2015-11-12, AV:   Added UARTx_Read_Byte, UARTx_Send_String and
 *                             UART2_Send_HEX functions as basic communication
 *                             routines  
 * V0.1.3: 2015-07-15, DM:   STDIN/STDOUT function added
 * V0.1.4: 2017-06-19, KC:   GetByte, isByteReceived and isByteTransmitted
 *                             inline functions added
 *                           Baudrate_Set function added
 *                           Blocking characteristic of send routines removed
 * V0.1.5: 2018-04-27, KC:   uart_defines.h moved from uart.c to uart.h
 */
 
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "uart.h"
#include "wdt1.h"
#include "scu_defines.h"
#if ((UART1_STD_EN == 1) || (UART2_STD_EN == 1))
  #include <stdio.h>
#endif

/*******************************************************************************
**                      External CallBacks                                    **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
/** \brief Initializes the UART module.
 *
 * \param None
 * \return None
 *
 * \ingroup drv_api
 */
void UART1_Init(void)
{
#if (UART1_Configuration_En == 1)
  UART1->SCON.reg = UART1_SCON;
  SCU->BCON1.reg = 0;
  SCU->BG1.reg =  UART1_BRVAL;
  SCU->BGL1.reg = UART1_FD;
  SCU->BCON1.reg = SCU_BCON1;
  UART1->SCONCLR.bit.RICLR = 1u;
  UART1->SCONCLR.bit.TICLR = 1u;
#endif
}

/** \brief Sets the baudrate for UART1.
 *
 * \param baudrate, e.g. 19200, or 115200
 * \return None
 *
 * \ingroup drv_api
 */
void UART1_BaudRate_Set(uint32 baudrate)
{
  uint16 BRVAL;
  uint16 FD;
  
  BRVAL = (uint16)(((uint32)UART1_CLK * (uint32)1E6) / (16 * baudrate));
  FD =    (uint16)(((((uint32)UART1_CLK * (uint32)1E6) / (16 * baudrate)) - BRVAL) * 32);
  
  UART1_BaudRateGen_Dis();

  SCU->BG1.reg = (uint16)BRVAL;
  SCU->BGL1.reg = (uint16)(FD);
  
  UART1_BaudRateGen_En();
}

/** \brief Initializes the UART module.
 *
 * \param None
 * \return None
 *
 * \ingroup drv_api
 */
void UART2_Init(void)
{
#if (UART2_Configuration_En == 1)
  UART2->SCON.reg = (uint32) UART2_SCON;
  SCU->BCON2.reg = (uint32) 0;
  SCU->BG2.reg = (uint32) UART2_BRVAL;
  SCU->BGL2.reg = (uint32) UART2_FD;
  SCU->BCON2.reg = (uint32) SCU_BCON2;
  UART2->SCONCLR.bit.RICLR = 1u;
  UART2->SCONCLR.bit.TICLR = 1u;
#endif
}
/** \brief Sets the baudrate for UART2.
 *
 * \param baudrate, e.g. 19200, or 115200
 * \return None
 *
 * \ingroup drv_api
 */
void UART2_BaudRate_Set(uint32 baudrate)
{
  uint16 BRVAL;
  uint16 FD;
  
  BRVAL = (uint16)(((uint32)UART2_CLK * (uint32)1E6) / (16 * baudrate));
  FD =    (uint16)(((((uint32)UART2_CLK * (uint32)1E6) / (16 * baudrate)) - BRVAL) * 32);
  
  UART2_BaudRateGen_Dis();

  SCU->BG2.reg = (uint16) BRVAL;
  SCU->BGL2.reg = (uint16)FD;
  
  UART2_BaudRateGen_En();
}
/** \brief Reads a Byte from UART1
 *
 * \param uint8* pointer
 * \return true if a byte was received
 *
 * \ingroup drv_api
 */
bool UART1_Read_Byte(uint8* pc)
{ 
  if (UART1->SCON.bit.RI==1)
  {
    *pc = (uint8)UART1->SBUF.reg;
    UART1->SCONCLR.bit.RICLR = 1u;
    return true;
  }
  else
  {
    return false;
  }
}

/** \brief Reads a Byte from UART2
 *
 * \param uint8* pointer
 * \return true if a byte was received
 *
 * \ingroup drv_api
 */
bool UART2_Read_Byte(uint8* pc)
{ 
  if (UART2->SCON.bit.RI==1)
  {
    *pc = (uint8)UART2->SBUF.reg;
    UART2->SCONCLR.bit.RICLR = 1u;
    return true;
  }
  else
  {
    return false;
  }
}

/** \brief Sends a String via UART1 (blocking, does not trigger tx interrupt)
 *
 * \param char*
 * \return None
 *
 * \ingroup drv_api
 */
void UART1_Send_String(char* s) 
{
  int i;
  for (i=0;s[i]!='\0';i++) 
  {  
    UART1_Send_Byte(s[i]);
    while (UART1->SCON.bit.TI == 0)
    {
      /* Execute wait function until character is transmitted */
      (void)WDT1_Service();
    }
  }
}


/** \brief Sends a String via UART2 (blocking, does not trigger tx interrupt)
 *
 * \param char*
 * \return None
 *
 * \ingroup drv_api
 */
void UART2_Send_String(char* s) 
{
  int i;
  for (i=0;s[i]!='\0';i++) 
  {  
    UART2_Send_Byte(s[i]);
    while (UART2->SCON.bit.TI == 0)
    {
      /* Execute wait function until character is transmitted */
      (void)WDT1_Service();
    }
  }
}


/** \brief Sends a uint32_t number as HEX via UART1 (no leading zeros, blocking, does not trigger tx interrupt)
 *
 * \param uint32_t
 * \return None
 *
 * \ingroup drv_api
 */
void UART1_Send_HEX(uint32_t number) 
{
  uint32_t x;
  int i;
  char h[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
  bool nonzero = false;
  UART1_Send_String("0x");
  for (i=0;i<8;i++) 
  {
    x = number >> 28;
    number = number << 4;
    if ((x!=0) || (i==7) || nonzero)
    {
      UART1_Send_Byte(h[x]);
      while (UART1->SCON.bit.TI == 0)
      {
        /* Execute wait function until character is transmitted */
        (void)WDT1_Service();
      }
      nonzero = true;
    }
  }
}

/** \brief Sends a uint32_t number as DEC via UART1 (no leading zeros, blocking, does not trigger tx interrupt)
 *
 * \param uint32_t
 * \return None
 *
 * \ingroup drv_api
 */
void UART1_Send_DEC(uint32_t number) 
{
  uint32 q;
  int i;
  bool nonzero = false;
  for (i=1000000000;i>0;i/=10) 
  {  
    q=(uint32)(number/i);
    if ((q!=0) || nonzero || (i==1))
    {
      UART1_Send_Byte((uint8)('0'+q));
      while (UART1->SCON.bit.TI == 0)
      {
        /* Execute wait function until character is transmitted */
        (void)WDT1_Service();
      }
      nonzero = true;
    }
    number-=(uint32)(q*i);
  }
}


/** \brief Sends a uint32_t number as HEX via UART2 (no leading zeros, blocking, does not trigger tx interrupt)
 *
 * \param uint32_t
 * \return None
 *
 * \ingroup drv_api
 */
void UART2_Send_HEX(uint32_t number) 
{
  uint32_t x;
  int i;
  char h[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
  bool nonzero = false;
  UART2_Send_String("0x");
  for (i=0;i<8;i++) 
  {
    x = number >> 28;
    number = number << 4;
    if ((x!=0) || (i==7) || nonzero)
    {
      UART2_Send_Byte(h[x]);
      while (UART2->SCON.bit.TI == 0)
      {
        /* Execute wait function until character is transmitted */
        (void)WDT1_Service();
      }
      nonzero = true;
    }
  }
}

/** \brief Sends a uint32_t number as DEC via UART2 (no leading zeros, blocking, does not trigger tx interrupt)
 *
 * \param uint32_t
 * \return None
 *
 * \ingroup drv_api
 */
void UART2_Send_DEC(uint32_t number) 
{
  uint32 q;
  int i;
  bool nonzero = false;
  for (i=1000000000;i>0;i/=10) 
  {  
    q=(uint32)(number/i);
    if ((q!=0) || nonzero || (i==1))
    {
      UART2_Send_Byte((uint8)('0'+q));
      while (UART2->SCON.bit.TI == 0)
      {
        /* Execute wait function until character is transmitted */
        (void)WDT1_Service();
      }
      nonzero = true;
    }
    number-=(uint32)(q*i);
  }
}

#if (UART1_STD_EN == 1)
/** \brief Sends a character via UART1.
 *
 * \param[in] Char Character to send
 * \return Sent character
 *
 * \ingroup uart_api
 */
sint32 stdout_putchar(sint32 Char)
{
  UART1_Send_Byte(Char);
  
  if (Char == (sint32)'\n')
  {
    /* line feed: */
    while (UART1->SCON.bit.TI == 0u)
    {
      /* Execute wait function until character is transmitted */
      (void)WDT1_Service();
    }
    /* Clear TI bit */
    UART1->SCONCLR.reg = UART_MASK_INT_TI;

    /* Send additional carriage return */
    UART1->SBUF.reg = (uint8)'\r';
  }
  while (UART1->SCON.bit.TI == 0u)
  {
    /* Execute wait function until character is transmitted */
    (void)WDT1_Service();
  }
  return Char;
} /* End of stdout_putchar */ 


/** \brief Receives a character via UART2.
 *
 * \return Received character
 *
 * \ingroup uart_api
 */
sint32 stdin_getchar(void)
{
  while (UART1->SCON.bit.RI == 0u)
  {
    /* Execute wait function until character is received */
    (void)WDT1_Service();
  }

  /* Clear RI bit */
  UART1->SCONCLR.reg = UART_MASK_INT_RI;

  /* Get character */
  return (sint32)UART1->SBUF.reg;
} /* End of stdin_getchar */ 

void ttywrch(int ch)
{
  stdout_putchar(ch);
}
#endif /* UART1_STD_EN == 1 */

#if (UART2_STD_EN == 1)
/** \brief Sends a character via UART1.
 *
 * \param[in] Char Character to send
 * \return Sent character
 *
 * \ingroup uart_api
 */
sint32 stdout_putchar(sint32 Char)
{
  UART2_Send_Byte(Char);
  
  if (Char == (sint32)'\n')
  {
    /* line feed: */
    while (UART2->SCON.bit.TI == 0u)
    {
      /* Execute wait function until character is transmitted */
      (void)WDT1_Service();
    }
    /* Clear TI bit */
    UART2->SCONCLR.reg = UART_MASK_INT_TI;

    /* Send additional carriage return */
    UART2->SBUF.reg = (uint8)'\r';
  }
  while (UART2->SCON.bit.TI == 0u)
  {
    /* Execute wait function until character is transmitted */
    (void)WDT1_Service();
  }
  return Char;
} /* End of stdout_putchar */ 


/** \brief Receives a character via UART2.
 *
 * \return Received character
 *
 * \ingroup uart_api
 */
sint32 stdin_getchar(void)
{
  while (UART2->SCON.bit.RI == 0u)
  {
    /* Execute wait function until character is received */
    (void)WDT1_Service();
  }

  /* Clear RI bit */
  UART2->SCONCLR.reg = UART_MASK_INT_RI;

  /* Get character */
  return (sint32)UART2->SBUF.reg;
} /* End of stdin_getchar */ 

void ttywrch(int ch)
{
  stdout_putchar(ch);
}
#endif /* UART2_STD_EN == 1 */



