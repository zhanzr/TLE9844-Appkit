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

#define TEST_BLOCK_FIR_SIZE 	64
#define NTAPS 		64

int pi_Input_blockfir[TEST_BLOCK_FIR_SIZE+NTAPS-1];
int pi_Output_blockfir[TEST_BLOCK_FIR_SIZE];
int pi_Coeffs[NTAPS];

void vF_dsplib_testbench_blockfir32(void)
{
	int j;

	tS_blockfir32_Coeff S_Coeff =
	{
		pi_Coeffs,
		NTAPS
	};

	pi_Coeffs[0] = 1;
	pi_Input_blockfir[0]  = 1;
	pi_Input_blockfir[32] = 1;

	vF_dspl_blockfir32(pi_Output_blockfir, pi_Input_blockfir, &S_Coeff, TEST_BLOCK_FIR_SIZE);

	printf("Input:\n");
	for(j = 0; j < TEST_BLOCK_FIR_SIZE; j++)
	{
		printf("%f\n", pi_Input_blockfir[j]*1.0f/(1<<28));
	}
	
	printf("Output:\n");
	for(j = 0; j < TEST_BLOCK_FIR_SIZE; j++)
	{
		printf("%f\n", pi_Output_blockfir[j]*1.0f/(1<<28));
	}
}

int main(void)
{	
  TLE_Init();
	
  /* System timer configuration */
  SysTick_Config(SystemFrequency / 1000);
	
  printf("Assembler Demo FIR %08X %s %u\n", 
	SCB->CPUID, 
	__TIME__,
	SystemFrequency);
		
	//Test Block Fir32
	vF_dsplib_testbench_blockfir32();
	
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
