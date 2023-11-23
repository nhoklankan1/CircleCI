#ifndef __APP_TYPE_H
#define __APP_TYPE_H

#ifdef __cplusplus
extern "C" {
#endif

#include <cstdint>

/**
 * @file AppType.h
 * @brief Defines common data types and structures for the application.
 */

/**
 * @struct ActionValue
 * @brief Represents values associated with an action.
 */
struct ActionValue {
    int angle; /**< Angle value associated with the action. */
    int speed; /**< Speed value associated with the action. */
    int direction; /**< Direction value associated with the action. */
    int active; /**< Flag indicating if the action is active or not. */
};

#ifdef __cplusplus
}
#endif

#endif /* __APP_TYPE_H */
