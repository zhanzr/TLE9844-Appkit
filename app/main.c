/*******************************************************************************
 * Infineon TLE9844-2QX Appkit Demo
 *
 * Author: zhanzr(zhanzr@foxmail.com)
 *
 ******************************************************************************/
 
#include <tle_device.h>
#include <stdio.h>
#include <stdint.h>

#define	TEST_DELAY_MS	1000

__IO uint32_t g_Ticks;

void User_SysTick_Handler(void)
{
  g_Ticks++;
}

void SimpleDelay(uint32_t t)
{
	uint32_t d = t*1000;
	while(--d)
	{
		__NOP();
		(void)WDT1_Service();	
	}  
}

uint32_t HAL_Ticks(void)
{
	return g_Ticks;
}

void HAL_Delay(uint32_t t)
{
	uint32_t d = t + HAL_Ticks();
	while(d > HAL_Ticks())
	{
		(void)WDT1_Service();	
	}  
}

int main(void)
{
  TLE_Init();
	
  /* System timer configuration */
  SysTick_Config(SystemFrequency / 1000);
	
  printf("UART2 ADC Demo %s %s %u\n", 
	__DATE__, 
	__TIME__,
	SystemFrequency);
	
  /* Switch On LS Modules */
  LS1_On();
  LS2_On();
	
  for (;;)
  {		
  printf("%s %s %u %u\n", 
	__DATE__, 
	__TIME__,
	SystemFrequency,
		g_Ticks);
		
	/* Channel 0 - VS */
	/* Channel 1 - VDDEXT */
	/* Channel 2 - VDDP */
	/* Channel 3 - VBG */
	/* Channel 4 - VDDC */
	/* Channel 5 - TEMP1 */
	/* Channel 6 - TEMP2 */		
		printf("VS:%d mV VDDEXT:%d mV VDDP:%d mV VBG:%d mV VDDC:%d mV TEMP1:%d mV TEMP2:%d mV\n",
		ADC2_GetChResult_mVC(ADC2_RESULT_VS),
		ADC2_GetChResult_mVC(ADC2_RESULT_VDDEXT),
		ADC2_GetChResult_mVC(ADC2_RESULT_VDDP),
		ADC2_GetChResult_mVC(ADC2_RESULT_VBG),
		ADC2_GetChResult_mVC(ADC2_RESULT_VDDC),
		ADC2_GetChResult_mVC(ADC2_RESULT_TEMP1),
		ADC2_GetChResult_mVC(ADC2_RESULT_TEMP2)
		);

/* Enabel Relais coil 1 */
		LS1_En();
		HAL_Delay(TEST_DELAY_MS);
		/* Disabel Relais coil 1 */
		LS1_Dis();		
		HAL_Delay(TEST_DELAY_MS);
		/* Enabel Relais coil 2 */
		LS2_En();
		HAL_Delay(TEST_DELAY_MS);
		/* Disabel Relais coil 2 */
		LS2_Dis();			
		HAL_Delay(TEST_DELAY_MS);
  }
}
