#include "LED_Singleton_Sample.h"

/**
 * @brief Static instance of the LED_test class.
 *
 * This static instance ensures that there is only one instance of the LED_test class throughout the program.
 */
LED_test LED_test::instance;

/**
 * @brief Constructor for the LED_test class.
 *
 * This constructor initializes the state of the LED and the function pointer for setting the LED value.
 */
LED_test::LED_test() {
    setState(0);
    RTE_LED_SET_VALUE = nullptr;
}

/**
 * @brief Destructor for the LED_test class.
 */
LED_test::~LED_test() {}

/**
 * @brief Get the singleton instance of the LED_test class.
 *
 * @return A reference to the unique instance of the LED_test class.
 */
LED_test& LED_test::getInstance() {
    return instance;
}
