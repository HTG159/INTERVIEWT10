#include "stm32f10x.h"                  // Device header
#include "stm32f10x_gpio.h"             // GPIO driver for STM32F10x
#include "stm32f10x_rcc.h"              // RCC driver for clock configuration
#include "stm32f10x_tim.h"              // Timer driver for delays

#define SPI_SCK_Pin GPIO_Pin_0
#define SPI_MISO_Pin GPIO_Pin_1
#define SPI_MOSI_Pin GPIO_Pin_2
#define SPI_CS_Pin GPIO_Pin_3
#define SPI_GPIO GPIOA
#define SPI_RCC RCC_APB2Periph_GPIOA

uint8_t ReceiveData;

void delay_ms(uint32_t time);

void Rcc_Config(){
	RCC_APB2PeriphClockCmd(SPI_RCC, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
}

// C?u hình Timer d? t?o hàm delay
void Tim_Config()
{
    TIM_TimeBaseInitTypeDef TIM_InitStruct;
    TIM_InitStruct.TIM_ClockDivision = TIM_CKD_DIV1;      // Set clock division
    TIM_InitStruct.TIM_Prescaler = 7200 - 1;              // Set prescaler to 7200 for 0.1 ms resolution
    TIM_InitStruct.TIM_Period = 0xFFFF;                   // Set maximum period
    TIM_InitStruct.TIM_CounterMode = TIM_CounterMode_Up;  // Count up mode

    TIM_TimeBaseInit(TIM2, &TIM_InitStruct);              // Initialize TIM2 with configuration
    TIM_Cmd(TIM2, ENABLE);                                // Start TIM2
}

// Generate delay in milliseconds using Timer
void delay_ms(uint32_t time)
{
    TIM_SetCounter(TIM2, 0);                           
    while (TIM_GetCounter(TIM2) < time * 10) {}         
}

// C?u hình GPIO
void GPIO_Config(){
	GPIO_InitTypeDef GPIO_InitStructure;
	
	// C?u hình SCK, MOSI, và CS là input
	GPIO_InitStructure.GPIO_Pin = SPI_SCK_Pin | SPI_MOSI_Pin | SPI_CS_Pin;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(SPI_GPIO, &GPIO_InitStructure);
	
	// C?u hình MISO là output
	GPIO_InitStructure.GPIO_Pin = SPI_MISO_Pin;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(SPI_GPIO, &GPIO_InitStructure);
}

// Kh?i t?o xung Clock b?ng cách kéo dây lên 1 và 0, cùng v?i hàm delay du?c t?o b?ng TIMER
void Clock(){
	GPIO_WriteBit(SPI_GPIO, SPI_SCK_Pin, Bit_SET);
	delay_ms(4);
	GPIO_WriteBit(SPI_GPIO, SPI_SCK_Pin, Bit_RESET);
	delay_ms(4);
}

// Kh?i t?o SPI
void SPI_init(){
	GPIO_WriteBit(SPI_GPIO, SPI_SCK_Pin, Bit_RESET);
	GPIO_WriteBit(SPI_GPIO, SPI_CS_Pin, Bit_SET);
	GPIO_WriteBit(SPI_GPIO, SPI_MISO_Pin, Bit_RESET);
	GPIO_WriteBit(SPI_GPIO, SPI_MOSI_Pin, Bit_RESET);
}

// Hàm nh?n d? li?u t? SPI Slave
uint8_t SPI_Slave_Receive()
{
	uint8_t DataRc = 0x00; 
	
	// Ch? CS th?p d? b?t d?u nh?n d? li?u
	while(GPIO_ReadInputDataBit(SPI_GPIO, SPI_CS_Pin));
	
	// Ð?c 8 bit d? li?u
	for(int i = 0; i < 8; i++)
	{
		// Ch? c?nh lên c?a SCK
		while(!GPIO_ReadInputDataBit(SPI_GPIO, SPI_SCK_Pin));
		
		// D?ch DataRc sang trái và l?y bit t? MOSI
		DataRc <<= 1;
		if(GPIO_ReadInputDataBit(SPI_GPIO, SPI_MOSI_Pin))
		{
			DataRc |= 1;
		}
		
		// Ch? c?nh xu?ng c?a SCK
		while(GPIO_ReadInputDataBit(SPI_GPIO, SPI_SCK_Pin));
	}
	
	// Ch? CS lên cao d? k?t thúc vi?c nh?n d? li?u
	while(!GPIO_ReadInputDataBit(SPI_GPIO, SPI_CS_Pin));
	
	return DataRc;
}

int main()
{
	Rcc_Config();       // C?u hình Clock
	GPIO_Config();      // C?u hình GPIO
	Tim_Config();       // C?u hình Timer
	SPI_init();         // Kh?i t?o SPI

	while(1)
	{
		ReceiveData = SPI_Slave_Receive();  // Nh?n d? li?u t? SPI Master
		// B?n có th? thêm mã d? x? lý d? li?u nh?n du?c ? dây
	}
}
