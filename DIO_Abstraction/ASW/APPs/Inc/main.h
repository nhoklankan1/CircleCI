#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32f1xx_hal.h"
#include "BSW_DIO.h"
#include "ECU_Config.h"
#include "RTE.h"
#include "BUTTON_Proxy.h"
#include "LED_Proxy.h"
#include "LED_Singleton_Sample.h"
#include "RobotArmManager.h"
#include "RotatingArmJoint.h"
#include "Action.h"
#include "AppType.h"

int main();

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
