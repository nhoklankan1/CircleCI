#ifndef __LED_SINGLETON_SAMPLE_H
#define __LED_SINGLETON_SAMPLE_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @file LED_Singleton_Sample.h
 * @brief LED Singleton Sample class for controlling an LED state using Singleton design pattern
 */

#include "LED_Proxy.h"

/**
 * @class LED_test
 * @brief LED Singleton Sample class for controlling an LED state using Singleton design pattern
 */
class LED_test : public LED_Proxy {
private:
    static LED_test instance; /**< Static instance of the LED_test class */

    /**
     * @brief LED_test private constructor
     */
    LED_test();

    ~LED_test();

public:
    /**
     * @brief Get the singleton instance of LED_test
     * @return Reference to the singleton instance
     */
    static LED_test& getInstance();

    // Delete copy constructor and operator= to enforce singleton pattern
    LED_test(const LED_test&) = delete;
    LED_test& operator=(const LED_test&) = delete;
};

#ifdef __cplusplus
}
#endif

#endif /* __LED_SINGLETON_SAMPLE_H */
