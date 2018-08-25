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

uint32_t g_TestVar32;// __attribute__((at(0x20003FF8)));

int main(void)
{
	uint32_t tmpTick;
	
  TLE_Init();
	
  /* System timer configuration */
  SysTick_Config(SystemFrequency / 1000);
	
  printf("Assembler Demo 3 %s %s %u\n", 
	__DATE__, 
	__TIME__,
	SystemFrequency);
	
	printf("Compare %u %u Result:%u\n", 123, 456, asm_test_cmp(123, 456));
	printf("Compare Not %u %u Result:%u\n", 123, 456, asm_test_cmn(123, 456));
	printf("%08X AND %08X Result:%08X\n", 0x12345678, 0x34567890, asm_get_and(0x12345678, 0x34567890));
	printf("%08X OR %08X Result:%08X\n", 0x12345678, 0x34567890, asm_get_or(0x12345678, 0x34567890));
	printf("NOT %08X Result:%08X\n", 0x12345678, asm_get_not(0x12345678));

	printf("%08X Logic Left Shift %u Result:%08X\n",0x80000001, 2, asm_logic_left(0x80000001, 2));
	printf("%08X Logic Right Shift %u Result:%08X\n",0x80000001, 2, asm_logic_right(0x80000001, 2));
	printf("%08X Arithm Right Shift %u Result:%08X\n",0x80000001, 2, asm_arithm_right(0x80000001, 2));
	printf("%08X Rotate Right Shift %u Result:%08X\n",0x80000001, 2, asm_rotate_right(0x80000001, 2));
	
	g_TestVar32 = 0x12345678;
	printf("Load[%08X] Result:%08X\n",&g_TestVar32, asm_ldr32(&g_TestVar32));
	asm_str32(&g_TestVar32, 0x78904563);	
	printf("After Store[%08X] Result:%08X\n",&g_TestVar32, asm_ldr32(&g_TestVar32));
	printf("ASM Test 22 Result:%u\n", asm_test_push_pop(123, 456));
	
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
