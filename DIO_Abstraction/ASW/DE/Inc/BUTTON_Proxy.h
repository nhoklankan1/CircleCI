#ifndef __BUTTON_PROXY_H
#define __BUTTON_PROXY_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @file BUTTON_Proxy.h
 * @brief Button Proxy class for controlling a button state
 */

#include "main.h"
#include "RTE.h"

/**
 * @class BUTTON_Proxy
 * @brief Button Proxy class for controlling a button state
 */
class BUTTON_Proxy
{
private:
	uint8_t state; /**< Current state of the button */
public:
	uint8_t (*RTE_BUTTON_READ_VALUE)(); /**< Function pointer for reading the button value */

	/**
	 * @brief Get the current state of the button.
	 *
	 * @return The current state of the button (HIGH or LOW).
	 */
	uint8_t getState();

	/**
	 * @brief Set the state of the button.
	 *
	 * @param state The state to be set for the button (HIGH or LOW).
	 */
	void setState(uint8_t state);

	/**
	 * @brief BUTTON_Proxy constructor
	 */
	BUTTON_Proxy();

	/**
	 * @brief BUTTON_Proxy destructor
	 */
	virtual ~BUTTON_Proxy();
};


#ifdef __cplusplus
}
#endif

#endif /* __BUTTON_PROXY_H */
