#ifndef ROTATING_ARM_JOINT_H
#define ROTATING_ARM_JOINT_H

#include "RTE.h"
#include "AppType.h"

/**
 * @file RotatingArmJoint.h
 * @brief Definition of the RotatingArmJoint class for controlling a step motor.
 */

#define CW_Direction 1
#define CCW_Direction 0
#define RJoint_OneStepAngle 1.8
#define RJoint_MaxLimit 180
#define RJoint_MinLimit 0
#define RJoint_Default_Delay 1

/**
 * @class RotatingArmJoint
 * @brief Proxy class for controlling a step motor's state.
 */
class RotatingArmJoint
{
private:
    uint8_t RJoint_currentAngle; /**< Current angle of the step motor */
    uint8_t RJoint_currentSpeed; /**< Current speed of the step motor */

public:
    /**
     * @brief Function pointer type for setting the angle of a step motor.
     *
     * This function pointer can be used to set the angle of a step motor.
     *
     * @param angle The angle to set for the step motor.
     */
    void (*RTE_STEP_MOTOR_SET_ANGLE)(uint8_t angle);

    /**
     * @brief Constructor for the RotatingArmJoint class.
     */
    RotatingArmJoint();

    /**
     * @brief Destructor for the RotatingArmJoint class.
     */
    ~RotatingArmJoint();

    /**
     * @brief Get the current angle of the step motor.
     * @return The current angle of the step motor.
     */
    uint8_t RJoint_getCurrentAngle();

    /**
     * @brief Get the current speed of the step motor.
     * @return The current speed of the step motor.
     */
    uint8_t RJoint_getCurrentSpeed();

    /**
     * @brief Set the speed of the step motor.
     * @param speed The speed to be set for the step motor.
     */
    void RJoint_setSpeed(uint8_t speed);

    /**
     * @brief Set the angle of the step motor.
     * @param angle The angle to be set for the step motor.
     */
    void RJoint_setAngle(uint8_t angle);

    /**
     * @brief Check if the given angle is valid.
     * @param value The angle to be checked.
     * @return 1 if the angle is valid, 0 otherwise.
     */
    int check_ValidAngle(ActionValue value);

    /**
     * @brief Rotate the step motor to a specific angle.
     * @param Value The angle to rotate to.
     * @return The current angle after rotation.
     */
    uint8_t Rotating_Joint(ActionValue Value);

    /**
     * @brief Rotate the step motor to a specific angle.
     * @param stepNumber The number of steps to rotate.
     * @param delayTime The delay time between steps.
     * @param direction The rotation direction (CW_Direction or CCW_Direction).
     */
    void Rotate_Angle(int RJoint_StepNumber, int RJoint_DelayTime, int direction);

    /**
     * @brief Reset the angle to zero.
     * @return 1 if the operation is successful, 0 otherwise.
     */
    uint8_t zero();
};

#endif /* ROTATING_ARM_JOINT_H */
