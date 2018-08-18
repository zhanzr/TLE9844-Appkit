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
	uint32_t tmpTick;
	
  TLE_Init();
	
  /* System timer configuration */
  SysTick_Config(SystemFrequency / 1000);
	
  printf("Assembler Demo 2 %s %s %u\n", 
	__DATE__, 
	__TIME__,
	SystemFrequency);
	
	printf("ASM Test 4 :%u\n", asm_add2(34));
	printf("ASM Test 5 :%u\n", asm_simple_add(123, 456));
	printf("ASM Test 6 :%u\n", asm_pc_add());
	
	printf("ASM Test 7 :%d\n", asm_sub20(34));
	printf("ASM Test 8 :%d\n", asm_simple_sub(123, 456));
	printf("ASM Test 9 :%d\n", asm_get_neg(1024));

	printf("ASM Test 10 Result:%u\t[%u]\n", asm_simple_mul(123, 456), 123*456);

	//Test Addition/Mulitiplication Cycles
#define	TEST_ADD_MUL_NUM	50000
	//If the muliplication takes similar cycles, it is a single cycle multiplication implementation
	tmpTick = g_Ticks;
	for(uint32_t i=0; i<TEST_ADD_MUL_NUM; ++i)
	{
		uint32_t tn = 101;
		asm_simple_add(tn, 456);
	}
	tmpTick = g_Ticks-tmpTick;
	printf("A:%u\n", tmpTick);	
	
	tmpTick = g_Ticks;
	for(uint32_t i=0; i<TEST_ADD_MUL_NUM; ++i)
	{		
		uint32_t tn = 101;
		asm_simple_mul(tn, 456);
	}
	tmpTick = g_Ticks-tmpTick;
	printf("M:%u\n", tmpTick);	
	
	//Test Division
	{
		uint32_t ta = 10;
		uint32_t tb = 2;
		uint32_t tc = ta/tb;
		printf("%u %u %u\n", ta, tb, tc);
	}
	
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
