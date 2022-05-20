#include "stm32f4xx.h"
#include "gpio.h"
#include "keypad.h"

int main(void)
{
	//initialize seven segment pins
	GPIO_Init(GPIOA,1,1,0,0);
	GPIO_Init(GPIOA,2,1,0,0);
	GPIO_Init(GPIOA,3,1,0,0);
	GPIO_Init(GPIOA,4,1,0,0);

	GPIO_WritePin (GPIOA,1,1);
	GPIO_WritePin (GPIOA,2,1);
	GPIO_WritePin (GPIOA,3,1);
	GPIO_WritePin (GPIOA,4,1);

	KeyPad_INIT();
	while(1){
		KeyPad_MANAGE();
	}
}
