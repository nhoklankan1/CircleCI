#include "LED_Proxy.h"

/**
 * @brief Constructor for the LED_Proxy class.
 *
 * This constructor initializes the state of the LED and the function pointer for setting the LED value.
 */
LED_Proxy::LED_Proxy() {
    state = 0;
    RTE_LED_SET_VALUE = nullptr;
}

/**
 * @brief Destructor for the LED_Proxy class.
 */
LED_Proxy::~LED_Proxy() {}

/**
 * @brief Get the current state of the LED.
 *
 * @return The current state of the LED (HIGH or LOW).
 */
uint8_t LED_Proxy::getState() {
    return state;
}

/**
 * @brief Set the state of the LED.
 *
 * @param state The state to be set for the LED (HIGH or LOW).
 *
 * This function also checks if the RTE_LED_SET_VALUE function pointer is not nullptr and calls it to set the LED state.
 */
void LED_Proxy::setState(uint8_t state) {
    this->state = state;

    // Check if RTE_LED_SET_VALUE function pointer is not nullptr and call it to set the LED state
    if (RTE_LED_SET_VALUE != nullptr) {
        RTE_LED_SET_VALUE(state);
    }
}
