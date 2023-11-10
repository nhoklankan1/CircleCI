//#ifndef __SLIDING_ARM_JOINT_H
//#define __SLIDING_ARM_JOINT_H
//
//#ifdef __cplusplus
//extern "C" {
//#endif
//
//#include "RTE.h"
//#include "AppType.h"
//
///**
// * @file StepMotorProxy.h
// * @brief Step Motor Proxy class for controlling a step motor state
// */
//#define STEPPER_OneStepAngle 1.8
//
//class StepMotorProxy
//{
//private:
//	uint8_t STEPPER_currentAngle; /**< Current angle of the step motor */
//	uint8_t STEPPER_currentSpeed; /**< Current speed of the step motor */
//public:
//
//	/**
//	 * @brief Function pointer for setting the angle of the step motor
//	 */
//	void (*RTE_STEP_MOTOR_SET_ANGLE)(uint8_t state);
//
//    /**
//     * @brief Get the current angle of the step motor.
//     *
//     * @return The current angle of the step motor.
//     */
//    uint8_t STEPER_getCurrentAngle();
//
//    /**
//     * @brief Get the current speed of the step motor.
//     *
//     * @return The current speed of the step motor.
//     */
//    uint8_t STEPPER_getCurrentSpeed();
//
//    /**
//     * @brief Set the speed of the step motor.
//     *
//     * @param speed The speed to be set for the step motor.
//     */
//	void STEPPER_setSpeed(uint8_t speed);
//
//	/**
//     * @brief Set the angle of the step motor.
//     *
//     * @param angle The angle to be set for the step motor.
//     */
//
//	void STEPPER_setAngle(StepMotorProxy stepper1, uint8_t angle, uint8_t speed);
//
//	/**
//     * @brief StepMotorProxy constructor
//     */
//	StepMotorProxy();
//
//	/**
//     * @brief StepMotorProxy destructor
//     */
//	~StepMotorProxy();
//};
//
//#ifdef __cplusplus
//}
//#endif
//
//#endif /* __SLIDING_ARM_JOINT_H */
