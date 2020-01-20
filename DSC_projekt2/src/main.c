/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/


#include "stm32l4xx.h"
#include "stm32l4xx_nucleo_32.h"
			

int main(void)
{
	HAL_Init();

	//GPIO - PA8
	RCC -> AHB2ENR |= (RCC_AHB2ENR_GPIOAEN);
	GPIOA -> MODER &= ~(GPIO_MODER_MODER8_0);
	GPIOA -> OSPEEDR |= (GPIO_OSPEEDR_OSPEED8_1) | (GPIO_OSPEEDR_OSPEED8_0);

	//RCC
	//Konfiguracja MCO - sygna�  dzielony przez 2, �r�d�o MSI
	//RCC -> CFGR |= (RCC_CFGR_MCOPRE_DIV2);
	RCC -> CFGR |= (RCC_CFGR_MCOSEL_1); //MSI on MCO

	//MSI 2MHz
	//Cz�stotliwo�c pracy MSI ustawiona na 2MHz
	RCC -> CR &= ~(0x000000F0); //RESET RANGE
	RCC -> CR |= (RCC_CR_MSIRANGE_5);
	RCC -> CR |= (RCC_CR_MSIRGSEL);

	//HSI16
	//W��czenie sygna�u HSI i ustawienie go jako SYSCLK
	RCC -> CR |= (RCC_CR_HSION);
	RCC -> CFGR |= (RCC_CFGR_SW_HSI);
	RCC -> CFGR |= (RCC_CFGR_MCOSEL_0) | (RCC_CFGR_MCOSEL_1); //HSI on MCO

	//PLL
	//Konfiguracja PLL do pracy z maksymaln� cz�stotliwo�ci�


	RCC -> CR &= ~(RCC_CR_PLLON);
	while ((RCC -> CR & ~(RCC_CR_PLLRDY_Msk)) == 0) {}

	RCC -> PLLCFGR &= (0xFFFF80FF);
	RCC -> PLLCFGR |= (RCC_PLLCFGR_PLLSRC_HSI);
	RCC -> PLLCFGR |= (RCC_PLLCFGR_PLLN_3) | (RCC_PLLCFGR_PLLN_1);
	RCC -> PLLCFGR &= ~(RCC_PLLCFGR_PLLM_0);

	RCC -> CR |= (RCC_CR_PLLON);
	RCC -> PLLCFGR |= (RCC_PLLCFGR_PLLREN);


	FLASH->ACR |= (FLASH_ACR_LATENCY_4WS);
	RCC -> CFGR |= (RCC_CFGR_SW_PLL);

	//Ustawienie dzielnika cz�stotliwosci
	RCC -> PLLCFGR &= ~(RCC_PLLCFGR_PLLM_1); // /4
	//RCC -> PLLCFGR |= (RCC_PLLCFGR_PLLR_1);

	RCC -> CFGR &= ~(RCC_CFGR_MCOSEL_1);
	RCC -> CFGR |= (RCC_CFGR_MCOSEL_2) | (RCC_CFGR_MCOSEL_0); //PLL on MCO

	//LSE
	RCC-> APB1ENR1 |= RCC_APB1ENR1_PWREN;
	PWR -> CR1 |= PWR_CR1_DBP;
	RCC -> BDCR |= (RCC_BDCR_LSEON); //LSE ON
	RCC -> BDCR |= (RCC_BDCR_LSCOSEL); //LSE as Low Speed Clock
	RCC -> BDCR |= (RCC_BDCR_LSCOEN);
	RCC -> CFGR |= (RCC_CFGR_MCOSEL_1); //LSE on MCO

	SystemCoreClockUpdate();


	while(1)
	{
		RCC -> CFGR &= ~(RCC_CFGR_MCOSEL_0);
		RCC -> CFGR &= ~(RCC_CFGR_MCOSEL_1);
		RCC -> CFGR &= ~(RCC_CFGR_MCOSEL_2);
		RCC -> CFGR &= ~(RCC_CFGR_MCOSEL_3);

		//RCC
		//Konfiguracja MCO - sygna�  dzielony przez 2, �r�d�o MSI
		//RCC -> CFGR |= (RCC_CFGR_MCOPRE_DIV2);
		RCC -> CR &= ~(0x000000F0);
		RCC -> CR |= (RCC_CR_MSIRANGE_6);
		RCC -> CR &= ~(RCC_CR_MSIPLLEN);
		RCC -> CFGR |= (RCC_CFGR_MCOSEL_1); //MSI on MCO
		HAL_Delay(20000);
		RCC -> CR |= (RCC_CR_MSIPLLEN);
		HAL_Delay(20000);


		//MSI 2MHz
		//Cz�stotliwo�c pracy MSI ustawiona na 2MHz
		RCC -> CR &= ~(0x000000F0); //RESET RANGE
		RCC -> CR |= (RCC_CR_MSIRANGE_5);
		RCC -> CR |= (RCC_CR_MSIRGSEL);
		HAL_Delay(10000);

		//HSI16
		//W��czenie sygna�u HSI i ustawienie go jako SYSCLK
		RCC -> CR |= (RCC_CR_HSION);
		RCC -> CFGR |= (RCC_CFGR_MCOSEL_0) | (RCC_CFGR_MCOSEL_1); //HSI on MCO
		HAL_Delay(10000);

		//PLL
		//Konfiguracja PLL do pracy z maksymaln� cz�stotliwo�ci�
		RCC -> CFGR &= ~(RCC_CFGR_MCOSEL_1);
		RCC -> CFGR |= (RCC_CFGR_MCOSEL_2) | (RCC_CFGR_MCOSEL_0); //PLL on MCO
		HAL_Delay(10000);

		//LSE
		RCC -> CFGR |= (RCC_CFGR_MCOSEL_1); //LSE on MCO
		HAL_Delay(10000);

		/*RCC -> CFGR |= (RCC_CFGR_MCOSEL_1); //MSI on MCO
		HAL_Delay(12000);
		RCC -> CFGR |= (RCC_CFGR_MCOSEL_0); //HSI on MCO
		HAL_Delay(12000);
		RCC -> CFGR &= ~(RCC_CFGR_MCOSEL_1);
		RCC -> CFGR |= (RCC_CFGR_MCOSEL_2); //PLL on MCO
		HAL_Delay(12000);
		RCC -> CFGR |= (RCC_CFGR_MCOSEL_1); //LSE on MCO
		HAL_Delay(12000);
		RCC -> CFGR &= ~(RCC_CFGR_MCOSEL_0);
		RCC -> CFGR &= ~(RCC_CFGR_MCOSEL_2);*/

	}
}
