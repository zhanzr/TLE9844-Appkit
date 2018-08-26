/*******************************************************************************
 * Infineon TLE9844-2QX Appkit Demo
 *
 * Author: zhanzr(zhanzr@foxmail.com)
 *
 ******************************************************************************/
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <tle_device.h>

#include "asm_prototype.h"

#define	RNG_TEST_NUM	100000

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

bool test_dspRand32(void)
{
	__IO int i_Random = 1;
	__IO int i_RandomLast = 0;
	volatile uint32_t i;

	bool ret = true;
	
	for(i = 0; i < RNG_TEST_NUM; i++)
	{
		/* Generate random number */
		i_Random = asm_rand_32(i_Random);
		//printf("rn = %08X\t", i_Random);

		/* Check number is not same as last one produced */
		if (i_Random != i_RandomLast)
		{
			i_RandomLast = i_Random;
		}
		else 
		{
			/* Test failed */
			ret = false;
			break;
		}
	}

	return ret;
}

bool test_stdlib_rand(void)
{
	__IO int i_Random = 1;
	__IO int i_RandomLast = 0;
	volatile uint32_t i;

	bool ret = true;
	
	for(i = 0; i < RNG_TEST_NUM; i++)
	{
		/* Generate random number */
		i_Random = rand();
		//printf("rn = %08X\t", i_Random);

		/* Check number is not same as last one produced */
		if (i_Random != i_RandomLast)
		{
			i_RandomLast = i_Random;
		}
		else 
		{
			/* Test failed */
			ret = false;
			break;
		}
	}

	return ret;
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
		
	//Test Random number generator
	tmpTick = HAL_GetTick();
	bool ret = test_dspRand32();
	tmpTick = HAL_GetTick() - tmpTick;
	printf("\ndspRand32:%s\n", ret?"OK":"FAILED");
	printf("%u\n", tmpTick);
	
	#ifdef __USE_ANSI_EXAMPLE_RAND
	printf("Use ANSI example rand.\n");
	#else
	printf("use CLib rand.\n");
	#endif	
	tmpTick = HAL_GetTick();
	ret = test_stdlib_rand();
	tmpTick = HAL_GetTick() - tmpTick;
	printf("\nstdlib rand:%s\n", 
	ret?"OK":"FAILED");
	printf("%u\n", tmpTick);
	
	//Test dot Product
	//Verification Python Code
	//a=[1,20,3,40,5,60,7,80,9,100]
	//b=[1, -1, 1, -1, 1, -1, 1, -1, 1, -1]
	//prod=0
	//l = len(a)
	//for i in range(l):
	//	prod += a[i]*b[i]
	//print(prod)
	
#define	VECT_LEN	10
	int32_t testV1[VECT_LEN] = {1,20,3,40,5,60,7,80,9,100};
	int32_t testV2[VECT_LEN] = {1, -1, 1, -1, 1, -1, 1, -1, 1, -1};
	int32_t result_dotProduct = asm_dot_prod_32(testV1, testV2, VECT_LEN);
	printf("dotProduct:%d\n", result_dotProduct);
	
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
