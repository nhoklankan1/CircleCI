#ifndef __BUTTON_SINGLETON_SAMPLE_H
#define __BUTTON_SINGLETON_SAMPLE_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @file BUTTON_Proxy.h
 * @brief Button Proxy class for controlling a button state
 */
#include "BUTTON_Proxy.h"

/**
 * @class BUTTON_Button_Start
 * @brief Button Proxy class for controlling the "Start" button state
 */
class BUTTON_Button_Start : public BUTTON_Proxy {
private:
	static BUTTON_Button_Start instance; /**< Unique instance of the class */

	BUTTON_Button_Start();

	~BUTTON_Button_Start();

public:
	/**
	 * @brief Get the unique instance of the class.
	 *
	 * @return A reference to the unique instance of BUTTON_Button_Start.
	 */
	static BUTTON_Button_Start& get_Instance();

	// Delete copy constructor and operator= to enforce singleton pattern
	BUTTON_Button_Start(const BUTTON_Button_Start&) = delete;
	BUTTON_Button_Start& operator=(const BUTTON_Button_Start&) = delete;
};

#ifdef __cplusplus
}
#endif

#endif /* __BUTTON_SINGLETON_SAMPLE_H */
