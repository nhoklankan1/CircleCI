#ifndef __RTE_H
#define __RTE_H

#ifdef __cplusplus
extern "C" {
#endif

#include "BSW_DIO.h"
#include "ECU_Config.h"
#include <cstdint>

/**
 * @brief Pointer to the state of LED1
 */
extern GPIO_PinState *RTE_LED1;

/**
 * @brief Pointer to the state of DIR1
 */
extern GPIO_PinState *RTE_DIR1;

/**
 * @brief Pointer to the value of BUTTON1
 */
extern uint8_t *RTE_BUTTON1;

/**
 * @brief Initialize the hardware resources
 */
void RTE_HW_Init();

/**
 * @brief Write a value to LED1
 * @param value: The value to be written
 */
void RTE_Write(uint8_t value);

/**
 * @brief Read the value of BUTTON1
 * @return The value of BUTTON1
 */
uint8_t RTE_Read();

/**
 * @brief Toggle the state of LED1
 */
void RTE_LED_Toggle();

#ifdef __cplusplus
}
#endif

#endif /* __RTE_H */
