/*******************************************************************************
 * Infineon TLE9844-2QX Appkit Demo
 *
 * Author: zhanzr(zhanzr@foxmail.com)
 *
 ******************************************************************************/
 
#include <tle_device.h>
#include <stdio.h>
#include <stdint.h>

#include "asm_prototype.h"

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

void TestFunct(void)
{
	printf("CPUID:%08X\n", SCB->CPUID);
}

int main(void)
{
  TLE_Init();
	
  /* System timer configuration */
  SysTick_Config(SystemFrequency / 1000);
	
  printf("Assembler Demo 1 %s %s %u\n", 
	__DATE__, 
	__TIME__,
	SystemFrequency);
	
	printf("Part 1\n");
	printf("Test 1 Result:%u\n", asm_get_8bit_number());
	printf("Test 2 Result:%08X\t[%08X]\n", asm_get_xor(0x12345678, 0x34567890), 0x12345678^0x34567890);
	printf("Test 3 Direct Jump:%08X\n", TestFunct);
	printf("Jump 1, Before.%08X\n", __get_MSP());
	asm_direct_jump_1(TestFunct);
	printf("Jump 1, After.%08X\n\n", __get_MSP());
	
	printf("Jump 2, Before.%08X\n", __get_MSP());
	asm_direct_jump_2(TestFunct);
	printf("Jump 2, After.%08X\n\n", __get_MSP());
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
		
  for (;;)
  {		
		__WFI();
		(void)WDT1_Service();			
  }
}
