/*******************************************************************************
 * Infineon TLE9844-2QX Appkit Demo
 *
 * Author: zhanzr(zhanzr@foxmail.com)
 *
 ******************************************************************************/
#include <stdio.h>
#include <stdint.h>
//#define __USE_ANSI_EXAMPLE_RAND
#include <stdlib.h>
#include <tle_device.h>

#include "asm_prototype.h"

#define	RNG_TEST_NUM	10

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

uint32_t HAL_GetTick(void)
{
	return g_Ticks;
}

void HAL_Delay(uint32_t t)
{
	uint32_t d = t + HAL_GetTick();
	while(d > HAL_GetTick())
	{
		(void)WDT1_Service();	
	}  
}

#define TEST_BIQUAD_SIZE 	64

//4.28 Q Format
int32_t pi_Input[TEST_BIQUAD_SIZE];
int32_t pi_Output[TEST_BIQUAD_SIZE];

void vF_dsplib_testbench_biquad32(void)
{
	int j;

	tS_biquad32_StateCoeff S_StateCoeff =
	{
		//2.14 Q Format
		{0x2000, 0, 0x4000, 0, 0},
		{0, 0}
	};

	pi_Input[0] = 0x10000000;

	vF_dspl_biquad32(pi_Output, pi_Input, &S_StateCoeff, TEST_BIQUAD_SIZE);

	for(j = 0; j < TEST_BIQUAD_SIZE; j++)
	{
		printf("%d, %08X\n", j, pi_Output[j]);
	}
}

int main(void)
{
	uint32_t tmpTick;
	
  TLE_Init();
	
  /* System timer configuration */
  SysTick_Config(SystemFrequency / 1000);
	
  printf("Assembler Demo 5 %08X %s %u\n", 
	SCB->CPUID, 
	__TIME__,
	SystemFrequency);
		
	//Test Biquad32
	vF_dsplib_testbench_biquad32();
	
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
