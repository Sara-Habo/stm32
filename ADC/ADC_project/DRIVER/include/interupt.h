/*
 * interupt.h
 *
 *  Created on: May 26, 2022
 *      Author: Dell
 */

#ifndef INCLUDE_INTERUPT_H_
#define INCLUDE_INTERUPT_H_

void EXTI_INIT(GPIO_TypeDef * GPIOx,char EXTI_line,char mask_set,char RES );
void NVIC_EXTI_Enable(char EXTI_line);
void NVIC_EXTI_Disable(char EXTI_line);

#endif /* INCLUDE_INTERUPT_H_ */
