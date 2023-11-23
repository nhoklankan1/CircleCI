#ifndef __BSW_DIO_H
#define __BSW_DIO_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @file BSW.h
 * @brief Basic Software (BSW) module for GPIO operations
 */

#include "stm32f1xx_hal.h"
#include "stm32f1xx_hal_gpio.h"

#include <cstdint>

/**
 * @brief Deinitialize a GPIO pin
 * @param GPIOx: Pointer to the GPIO port
 * @param GPIO_Pin: Specifies the pin to be deinitialized
 */
void DIO_DeInit(GPIO_TypeDef *GPIOx, uint32_t GPIO_Pin);

/**
 * @brief Toggle the state of a GPIO pin
 * @param GPIOx: Pointer to the GPIO port
 * @param GPIO_Pin: Specifies the pin to be toggled
 */
void DIO_TogglePin(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);

/**
 * @brief Read the state of a GPIO pin
 * @param GPIOx: Pointer to the GPIO port
 * @param GPIO_Pin: Specifies the pin to be read
 * @return The pin state (GPIO_PIN_RESET or GPIO_PIN_SET)
 */
GPIO_PinState DIO_ReadPin(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);

/**
 * @brief Write a value to a GPIO pin
 * @param GPIOx: Pointer to the GPIO port
 * @param GPIO_Pin: Specifies the pin to be written
 * @param PinState: Specifies the value to be written (GPIO_PIN_RESET or GPIO_PIN_SET)
 */
void DIO_WritePin(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin, GPIO_PinState PinState);

#ifdef __cplusplus
}
#endif

#endif /* __BSW_DIO_H */
