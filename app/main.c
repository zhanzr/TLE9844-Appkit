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
  TLE_Init();
	
  /* System timer configuration */
  SysTick_Config(SystemFrequency / 1000);
	
  printf("Assembler Demo 4 %s %s %u\n", 
	__DATE__, 
	__TIME__,
	SystemFrequency);
		
	printf("%04X in16_t extend:%08X\n", 0x8001, asm_s16ext((int16_t)0x8001));
	printf("%02X in8_t extend:%08X\n", 0xC4, asm_s8ext((int8_t)0xC4));
	printf("%04X uin16_t extend:%08X\n",0x8001, asm_u16ext((uint16_t)0x8001));
	printf("%08X rev: %08X\n", 0x123456C8, asm_rev(0x123456C8));
	printf("%08X rev16 :%08X\n", 0x123456C8, asm_rev16(0x123456C8));
	printf("%08X revsh :%08X\n", 0x123456C8, asm_revsh(0x123456C8));
	
	//Part 8: Test SVC, MSR, MRS
	printf("Before SVC #1\n");
	asm_svc_1();
	printf("After SVC #1\n");
	
	printf("Before SVC #2\n");
	asm_svc_2();
	printf("After SVC #2\n");	
	
	g_TestVar32 = asm_test_mrs();
	printf("MRS read PRIMASK:%08X\n", g_TestVar32);
	printf("Tick:%u\n", SysTick->VAL);
	asm_test_msr(0x00000001);
	uint32_t p1 = asm_test_mrs();
	asm_test_msr(0x00000000);
	uint32_t p2 = asm_test_mrs();
	printf("MSR %08X\t%08X\n", p1, p2);
	
	//Recover the field
	asm_test_msr(g_TestVar32);
	
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
