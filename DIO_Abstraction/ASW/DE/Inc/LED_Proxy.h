#ifndef __LED_PROXY_H
#define __LED_PROXY_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @file LED_Proxy.h
 * @brief LED Proxy class for controlling an LED state
 */

#include "RTE.h"

/**
 * @class LED_Proxy
 * @brief LED Proxy class for controlling an LED state
 */
class LED_Proxy
{
private:
    uint8_t state; /**< Current state of the LED */
public:
    /**
     * @brief Function pointer for setting the LED value
     *
     * This function pointer is used to set the state of the LED.
     *
     * @param state The state to be set for the LED (HIGH or LOW).
     */
    void (*RTE_LED_SET_VALUE)(uint8_t state);

    /**
     * @brief Get the current state of the LED.
     *
     * @return The current state of the LED (HIGH or LOW).
     */
    uint8_t getState();

    /**
     * @brief Set the state of the LED.
     *
     * @param state The state to be set for the LED (HIGH or LOW).
     */
    void setState(uint8_t state);

    /**
     * @brief LED_Proxy constructor
     */
    LED_Proxy();

    /**
     * @brief LED_Proxy destructor
     */
    virtual ~LED_Proxy();
};

#ifdef __cplusplus
}
#endif

#endif /* __LED_PROXY_H */
