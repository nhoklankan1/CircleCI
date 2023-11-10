//#include "SlidingArmJoint_Proxy.h"
//
///**
// * @brief Constructor for the StepMotorProxy class.
// *
// * This constructor initializes the current angle and current speed of the stepper motor.
// */
//StepMotorProxy::StepMotorProxy()
//{
//	STEPPER_currentAngle = 0;
//	STEPPER_currentSpeed = 0;
//}
//
///**
// * @brief Destructor for the StepMotorProxy class.
// */
//StepMotorProxy::~StepMotorProxy()
//{
//}
//
///**
// * @brief Get the current angle of the stepper motor.
// *
// * @return The current angle of the stepper motor.
// */
//uint8_t StepMotorProxy::STEPER_getCurrentAngle()
//{
//	return STEPPER_currentAngle;
//}
//
///**
// * @brief Get the current speed of the stepper motor.
// *
// * @return The current speed of the stepper motor.
// */
//uint8_t StepMotorProxy::STEPPER_getCurrentSpeed()
//{
//	return STEPPER_currentSpeed;
//}
//
///**
// * @brief Set the speed of the stepper motor.
// *
// * @param speed The speed to be set for the stepper motor.
// */
//void StepMotorProxy::STEPPER_setSpeed(uint8_t speed)
//{
//	STEPPER_currentSpeed = speed;
//}
//
//
///**
// * @brief Set the angle of the stepper motor.
// *
// * @param angle The angle to be set for the stepper motor.
// */
//void StepMotorProxy::STEPPER_setAngle(StepMotorProxy stepper1, uint8_t angle, uint8_t speed)
//{
//	float STEPPER_StepNumber = (float)(angle/STEPPER_OneStepAngle);
//	float STEPPER_Time = (float)(angle/speed);
//	float STEPPER_DelayTime = (float)(((STEPPER_Time * 1000)/STEPPER_StepNumber) / 2); // s to ms, delay cả time quay lẫn time dừng nên phải chia 2
//	stepper1.RTE_STEP_MOTOR_SET_ANGLE = &RTE_Write;
//	for(int i = 0; i <(int)STEPPER_StepNumber; i++ ){
//		stepper1.RTE_STEP_MOTOR_SET_ANGLE(GPIO_PIN_SET);
//		HAL_Delay((uint8_t)STEPPER_DelayTime);
//		stepper1.RTE_STEP_MOTOR_SET_ANGLE(GPIO_PIN_RESET);
//		HAL_Delay((uint8_t)STEPPER_DelayTime);
//	}
//
//
//	this->STEPPER_setSpeed(speed);
//	if(STEPPER_currentAngle < 360)
//	{
//		if(STEPPER_currentAngle + angle < 360)
//		{
//			STEPPER_currentAngle += angle;
//		}
//		else if(STEPPER_currentAngle + angle > 360)
//		{
//			STEPPER_currentAngle = STEPPER_currentAngle + angle - 360;
//		}
//	}
//	else{
//		STEPPER_currentAngle = STEPPER_currentAngle - 360 + angle;
//	}
//
//}
