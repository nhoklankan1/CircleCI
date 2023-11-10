#include "RotatingArmJoint.h"

/**
 * @brief Constructor for the RotatingArmJoint class.
 *
 * This constructor initializes the current angle and current speed of the RJoint motor.
 */
RotatingArmJoint::RotatingArmJoint()
{
	RJoint_currentAngle = 0;
	RJoint_currentSpeed = 0;
}

/**
 * @brief Destructor for the RotatingArmJoint class.
 */
RotatingArmJoint::~RotatingArmJoint()
{
}

/**
 * @brief Get the current angle of the RJoint motor.
 *
 * @return The current angle of the RJoint motor.
 */
uint8_t RotatingArmJoint::RJoint_getCurrentAngle()
{
	return RJoint_currentAngle;
}

/**
 * @brief Get the current speed of the RJoint motor.
 *
 * @return The current speed of the RJoint motor.
 */
uint8_t RotatingArmJoint::RJoint_getCurrentSpeed()
{
	return RJoint_currentSpeed;
}

/**
 * @brief Set the speed of the RJoint motor.
 *
 * @param speed The speed to be set for the RJoint motor.
 */
void RotatingArmJoint::RJoint_setSpeed(uint8_t speed)
{
	RJoint_currentSpeed = speed;
}

void RotatingArmJoint::RJoint_setAngle(uint8_t angle)
{
	RJoint_currentAngle = angle;
}
int RotatingArmJoint::check_ValidAngle(ActionValue Value)
{
	int target_Angle = 0;
	if (Value.direction == CCW_Direction)
	{
		target_Angle = RJoint_currentAngle + Value.angle;
	}
	else
	{
		target_Angle = RJoint_currentAngle - Value.angle;
	}
	if (RJoint_MinLimit <= target_Angle && target_Angle >= RJoint_MaxLimit)
	{

		return -1;
	}
	return 0;
}

/**
 * @brief Set the angle of the RJoint motor.
 *
 * @param angle The angle to be set for the RJoint motor.
 */
uint8_t RotatingArmJoint::Rotating_Joint(ActionValue Value)
{
	int RJoint_StepNumber = (int)(Value.angle / RJoint_OneStepAngle);
	int RJoint_Time = (int)(Value.angle / Value.speed);
	int RJoint_DelayTime = (int)(((RJoint_Time * 1000) / RJoint_StepNumber) / 2); // s to ms, delay cả time quay lẫn time dừng nên phải chia 2
	if (!check_ValidAngle(Value))
	{
		if (RJoint_StepNumber != 0)
		{
			Rotate_Angle(RJoint_StepNumber, RJoint_DelayTime, Value.direction);
		}
		else
		{
			return -1;
		}
	}
	else
	{
		return -1;
	}

	if (Value.direction == CCW_Direction)
	{
		RJoint_setAngle(RJoint_currentAngle + Value.angle);
	}
	else
	{
		RJoint_setAngle(RJoint_currentAngle - Value.angle);
	}

	this->RJoint_setSpeed(Value.speed);
	return 0;
}
void RotatingArmJoint::Rotate_Angle(int RJoint_StepNumber, int RJoint_DelayTime, int direction)
{
	//	this->RTE_DIRECTION = direction;
	direction = CCW_Direction;
	for (int i = 0; i < (int)RJoint_StepNumber; i++)
	{
		this->RTE_STEP_MOTOR_SET_ANGLE(GPIO_PIN_SET);
		HAL_Delay((uint8_t)RJoint_DelayTime);
		this->RTE_STEP_MOTOR_SET_ANGLE(GPIO_PIN_RESET);
		HAL_Delay((uint8_t)RJoint_DelayTime);
	}
}

uint8_t RotatingArmJoint::zero()
{
	int RJoint_StepNumber = (int)(RJoint_currentAngle / RJoint_OneStepAngle);
	if (RJoint_StepNumber != 0)
	{
		Rotate_Angle(RJoint_StepNumber, RJoint_Default_Delay, CW_Direction);
	}
	return 0;
}
