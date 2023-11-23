#include "main.h"

int main(void)
{
	ECU_Config();
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

	}
}