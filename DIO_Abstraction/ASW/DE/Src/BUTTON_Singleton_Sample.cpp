#include "BUTTON_Singleton_Sample.h"

// Initialize the static instance of BUTTON_Button_Start
BUTTON_Button_Start BUTTON_Button_Start::instance;

/**
 * @brief Constructor for the BUTTON_Button_Start class.
 *
 * This constructor initializes the members and sets default values for the "Start" button.
 */
BUTTON_Button_Start::BUTTON_Button_Start() {
	setState(0);
	RTE_BUTTON_READ_VALUE = NULL;
}

/**
 * @brief Destructor for the BUTTON_Button_Start class.
 */
BUTTON_Button_Start::~BUTTON_Button_Start() {}

/**
 * @brief Get the unique instance of the BUTTON_Button_Start class.
 *
 * @return A reference to the unique instance of BUTTON_Button_Start.
 */
BUTTON_Button_Start& BUTTON_Button_Start::get_Instance() {
	return instance;
}
