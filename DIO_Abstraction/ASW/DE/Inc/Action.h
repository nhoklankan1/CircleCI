#ifndef __ACTION_H
#define __ACTION_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "AppType.h"

/**
 * @file Action.h
 * @brief Defines the Action structure for specifying robot arm actions.
 */

/**
 * @struct Action
 * @brief Represents an action for controlling a robot arm.
 */
struct Action {
    ActionValue rotatingArmJoint1; /**< Value for rotatingArmJoint1 */
    ActionValue rotatingArmJoint2; /**< Value for rotatingArmJoint2 */
    ActionValue rotatingArmJoint3; /**< Value for rotatingArmJoint3 */
    int slidingArmJoint1; /**< Value for slidingArmJoint1 */
    int slidingArmJoint2; /**< Value for slidingArmJoint2 */
    int manipulatorForce; /**< Value for manipulatorForce */
    int manipulatorOpen; /**< Value for manipulatorOpen */
};

#ifdef __cplusplus
}
#endif

#endif /* __ACTION_H */
