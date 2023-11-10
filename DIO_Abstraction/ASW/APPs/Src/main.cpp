#include "main.h"

int main()
{
	ECU_Config();
//	RTE_HW_Init();
//	LED_Proxy led1;
//	BUTTON_Proxy button1; // proxy
//	led1.RTE_LED_SET_VALUE = &RTE_Write;
//	button1.RTE_BUTTON_READ_VALUE = &RTE_Read; //proxy
//	LED_test::getInstance().RTE_LED_SET_VALUE = &RTE_Write; // singleton
	RotatingArmJoint Joint1;
	Joint1.RTE_STEP_MOTOR_SET_ANGLE = &RTE_Write;
	ActionValue value[1];
	value[0].angle = 90;
	value[0].speed = 10;
	value[0].direction = CCW_Direction;
	value[0].active = 1;
	RobotArmManager armManager;
	armManager.RobotArmManager_addItsRotatingArmJoint(&Joint1);
	int x = 10;
	int y = 20;
	int z = 30;
    int t = 40;
    int result = armManager.RobotArmManager_graspAt(x, y, z, t);
	while(1)
	{
//		Joint1.RotatingJoint(value[0]);
	}

////		LED_test::getInstance().setState(1); //singleton
////		led1.setState(1);
////		button1.RTE_BUTTON_READ_VALUE(); //proxy
////		DIO_TogglePin(GPIOA, GPIO_PIN_1);
////		RTE_LED_Toggle();
////		HAL_Delay(1000);
////		led1.setState(0);
//		for(int i = 0; i < 400; i++)
//		{
//			DIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_SET);
//			HAL_Delay(10);
//			DIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_RESET);
//			HAL_Delay(10);
//		}
////		if (DIO_GPIO_ReadPin(GPIOA, GPIO_PIN_0) == 1)
////		{
////			HAL_Delay(1000);
////			DIO_GPIO_TogglePin(GPIOD, GPIO_PIN_12);
////		}
////		DIO_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_SET);
//	}
	return 0;
}




