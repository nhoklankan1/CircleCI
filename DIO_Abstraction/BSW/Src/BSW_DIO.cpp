#include <BSW_DIO.h>

/**
 * @brief Deinitialize a GPIO pin.
 *
 * @param GPIOx Pointer to the GPIOx peripheral.
 * @param GPIO_Pin The pin to be deinitialized.
 */
void DIO_DeInit(GPIO_TypeDef *GPIOx, uint32_t GPIO_Pin) {
    HAL_GPIO_DeInit(GPIOx, GPIO_Pin);
}

/**
 * @brief Toggle the state of a GPIO pin.
 *
 * @param GPIOx Pointer to the GPIOx peripheral.
 * @param GPIO_Pin The pin to be toggled.
 */
void DIO_TogglePin(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin) {
    HAL_GPIO_TogglePin(GPIOx, GPIO_Pin);
}

/**
 * @brief Read the state of a GPIO pin.
 *
 * @param GPIOx Pointer to the GPIOx peripheral.
 * @param GPIO_Pin The pin to be read.
 * @return The state of the pin (GPIO_PIN_RESET or GPIO_PIN_SET).
 */
GPIO_PinState DIO_ReadPin(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin) {
    return HAL_GPIO_ReadPin(GPIOx, GPIO_Pin);
}

/**
 * @brief Write a state to a GPIO pin.
 *
 * @param GPIOx Pointer to the GPIOx peripheral.
 * @param GPIO_Pin The pin to be written.
 * @param PinState The state to be written (GPIO_PIN_RESET or GPIO_PIN_SET).
 */
void DIO_WritePin(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin, GPIO_PinState PinState) {
    if (PinState == GPIO_PIN_SET) {
        HAL_GPIO_WritePin(GPIOx, GPIO_Pin, PinState);
    } else {
        HAL_GPIO_WritePin(GPIOx, GPIO_Pin, PinState);
    }
}
