#include "BUTTON_Proxy.h"

/**
 * @brief BUTTON_Proxy constructor
 */
BUTTON_Proxy::BUTTON_Proxy()
{
    state = 0;
    RTE_BUTTON_READ_VALUE = nullptr;
}

/**
 * @brief BUTTON_Proxy destructor
 */
BUTTON_Proxy::~BUTTON_Proxy()
{
}

/**
 * @brief Get the current state of the button.
 *
 * @return The current state of the button (HIGH or LOW).
 */
uint8_t BUTTON_Proxy::getState()
{
    return state;
}

/**
 * @brief Set the state of the button.
 *
 * @param state The state to be set for the button (HIGH or LOW).
 */
void BUTTON_Proxy::setState(uint8_t state)
{
    this->state = state;
}
