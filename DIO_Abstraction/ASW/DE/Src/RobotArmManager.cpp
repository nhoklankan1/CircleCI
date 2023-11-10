#include <RobotArmManager.h>
/* computeTrajectory with nStep of Action
create an Action array with nStep elethisnts

*/
void RobotArmManager::RobotArmManager_computeTrajectory(int x, int y, int z, int t)
{
	this->nSteps = 1;
	RobotArmManager_clearItsAction();
	// Allocate thismory for the array
	for (unsigned int i = 0; i < nSteps; ++i)
	{
		this->itsAction[i] = Action{{90, 10, CCW_Direction, 1}, {0, 0, 0, 0}, {0, 0, 0, 0}, 0, 0, 0, 0};
	}
}

int RobotArmManager::RotatingArmJoint_rotate(RotatingArmJoint *itsRotatingArmJoint, ActionValue value)
{
	return itsRotatingArmJoint->Rotating_Joint(value);
}

bool RobotArmManager::isActionEmpty(const Action &action)
{
	return action.rotatingArmJoint1.active == 1; //&&
												 //		   action.rotatingArmJoint2.active == 1 &&
												 //		   action.rotatingArmJoint3.active == 1; //&&
												 //		   action.slidingArmJoint1 == 1 &&
												 //		   action.slidingArmJoint2 == 1 &&
												 //		   action.manipulatorForce == 1 &&
												 //		   action.manipulatorOpen == 1;
}

/* operation executeStep()
This operation executes a single step in the chain of actions by
executing all of the commands within the current action
*/

int RobotArmManager::RobotArmManager_executeStep()
{
	ActionValue actionValue = {0, 0, 0, 0};
	int step = this->currentStep;
	int status = 0;
	if (isActionEmpty(this->itsAction[step]))
	{
		actionValue = this->itsAction[step].rotatingArmJoint1;
		status = RotatingArmJoint_rotate(this->itsRotatingArmJoint[0], actionValue);
		if (status)
			return status;
		actionValue = this->itsAction[step].rotatingArmJoint2;
		status = RotatingArmJoint_rotate(this->itsRotatingArmJoint[1], actionValue);
		if (status)
			return status;
		actionValue = this->itsAction[step].rotatingArmJoint3;
		status = RotatingArmJoint_rotate(this->itsRotatingArmJoint[2], actionValue);
		if (status)
			return status;
		// actionValue = this->itsAction[step]->slidingArmJoint1;
		// status = SlidingArmJoint_setLength(this->itsSlidingArmJoint[0], actionValue);
		// if (status)
		// 	return status;
		// actionValue = this->itsAction[step]->slidingArmJoint2;
		// status = SlidingArmJoint_setLength(this->itsSlidingArmJoint[1], actionValue);
		// if (status)
		// 	return status;
		// actionValue = this->itsAction[step]->manipulatorForce;
		// status = GraspingManipulator_setMaxForce(this->itsGraspingManipulator, actionValue);
		// if (status)
		// 	return status;
		// if (this->itsAction[step]->manipulatorOpen)
		// 	status = GraspingManipulator_open(this->itsGraspingManipulator);
		// else
		// 	status = GraspingManipulator_close(this->itsGraspingManipulator);
	}
	//notifyObservers();
	return status;
}

/* operation graspAt(x,y,z,t) is the main function called by clients of the
RobotArmManager. This operation:
1. zeros the servos
2. computes the trajectory with a call to computeTrajectory()
3. executes each step in the constructed action list
*/

int RobotArmManager::RobotArmManager_graspAt(int x, int y, int z, int t)
{
	this->currentStep = -1;
	this->nSteps = 0;
	if (RobotArmManager_zero())
	{
//		//notifyErrorObservers();
		return -1;
	}
	RobotArmManager_computeTrajectory(x, y, z, t);
	if (this->nSteps == 0)
	{
		//notifyErrorObservers();
		this->status = -1;
	}
	else
	{
		do
		{
			this->currentStep++;
			this->status = RobotArmManager_executeStep();
		} while (this->status == 0 && this->currentStep < this->nSteps);
	}
	return this->status;
}

int RobotArmManager::RotatingArmJoint_zero(RotatingArmJoint *itsRotatingArmJoint)
{
	return itsRotatingArmJoint->zero();
}

/* operation zero()
This operation returns all servos to a starting default position
*/

int RobotArmManager::RobotArmManager_zero()
{
	/* zero all devices */
	int j;
	for (j = 0; j < MAX; j++)
	{
		if (this->itsRotatingArmJoint[j] == NULL)
		{
			//notifyErrorObservers();
			return -1;
		}

		if (RotatingArmJoint_zero(this->itsRotatingArmJoint[j]))
		{
			//notifyErrorObservers();
			return -1;
		}

	}
	// for (j = 0; j < 2; j++)
	// {
	// 	if (this->itsSlidingArmJoint[j] == NULL)
	// 		return -1;
	// 	if (SlidingArmJoint_zero(this->itsSlidingArmJoint[j]))
	// 		return -1;
	// }
	// if (this->itsGraspingManipulator == NULL)
	// 	return -1;
	// if (GraspingManipulator_open(this->itsGraspingManipulator))
	// 	return -1;
	return 0;
}

// GraspingManipulator *RobotArmManager::RobotArmManager_getItsGraspingManipulator()
//{
//	return (GraspingManipulator *)this->itsGraspingManipulator;
// }
//
// void RobotArmManager::RobotArmManager_setItsGraspingManipulator(GraspingManipulator *p_GraspingManipulator)
//{
//	this->itsGraspingManipulator = p_GraspingManipulator;
// }

int RobotArmManager::RobotArmManager_getItsRotatingArmJoint()
{
	int iter = 0;
	return iter;
}

void RobotArmManager::RobotArmManager_addItsRotatingArmJoint(RotatingArmJoint *p_RotatingArmJoint)
{
	int pos;
	for (pos = 0; pos < MAX; ++pos)
	{
		if (!this->itsRotatingArmJoint[pos])
		{
			this->itsRotatingArmJoint[pos] = p_RotatingArmJoint;
			break;
		}
	}
}

void RobotArmManager::RobotArmManager_removeItsRotatingArmJoint(RotatingArmJoint *p_RotatingArmJoint)
{
	int pos;
	for (pos = 0; pos < MAX; ++pos)
	{
		if (this->itsRotatingArmJoint[pos] == p_RotatingArmJoint)
		{
			this->itsRotatingArmJoint[pos] = NULL;
		}
	}
}

void RobotArmManager::RobotArmManager_clearItsRotatingArmJoint()
{
	int pos;
	for (pos = 0; pos < MAX; ++pos)
	{
		this->itsRotatingArmJoint[pos] = NULL;
	}
}

// int RobotArmManager::RobotArmManager_getItsSlidingArmJoint()
// {
// 	int iter = 0;
// 	return iter;
// }

// void RobotArmManager::RobotArmManager_addItsSlidingArmJoint(SlidingArmJoint *p_SlidingArmJoint)
// {
// 	int pos;
// 	for (pos = 0; pos < 2; ++pos)
// 	{
// 		if (!this->itsSlidingArmJoint[pos])
// 		{
// 			this->itsSlidingArmJoint[pos] = p_SlidingArmJoint;
// 			break;
// 		}
// 	}
// }

// void RobotArmManager::RobotArmManager_removeItsSlidingArmJoint(SlidingArmJoint *p_SlidingArmJoint)
// {
// 	int pos;
// 	for (pos = 0; pos < 2; ++pos)
// 	{
// 		if (this->itsSlidingArmJoint[pos] == p_SlidingArmJoint)
// 		{
// 			this->itsSlidingArmJoint[pos] = NULL;
// 		}
// 	}
// }

// void RobotArmManager::RobotArmManager_clearItsSlidingArmJoint()
// {
// 	int pos;
// 	for (pos = 0; pos < 2; ++pos)
// 	{
// 		this->itsSlidingArmJoint[pos] = NULL;
// 	}
// }

int RobotArmManager::RobotArmManager_getItsAction()
{
	int iter = 0;
	return iter;
}

void RobotArmManager::RobotArmManager_addItsAction(Action *p_Action)
{
	//	int pos;
	//	for (pos = 0; pos < 100; ++pos)
	//	{
	//		if (!this->itsAction[pos])
	//		{
	//			this->itsAction[pos] = p_Action;
	//			break;
	//		}
	//	}
}

void RobotArmManager::RobotArmManager_removeItsAction(Action *p_Action)
{
	//	int pos;
	//	for (pos = 0; pos < 100; ++pos)
	//	{
	//		if (this->itsAction[pos] == p_Action)
	//		{
	//			this->itsAction[pos] = NULL;
	//		}
	//	}
}

void RobotArmManager::RobotArmManager_clearItsAction()
{
	//	int pos;
	//	for (pos = 0; pos < 100; ++pos)
	//	{
	//		this->itsAction[pos] = NULL;
	//	}
}

// RobotArmManager::RobotArmManager()
//{
//	RobotArmManager *this = (RobotArmManager *)
//		malloc(sizeof(RobotArmManager));
//	if (this != NULL)
//	{
//		RobotArmManager_Init();
//	}
//	return *this;
// }
//
// RobotArmManager::~RobotArmManager()
//{
//	if (this != NULL)
//	{
//		RobotArmManager_Cleanup();
//	}
// }

//void attachObserver(Observer *observer)
//{
//	observers.push_back(observer);
//}
//
//// Hủy đăng ký một Observer
//void detachObserver(Observer *observer)
//{
//	observers.erase(remove(observers.begin(), observers.end(), observer), observers.end());
//}
//
//// Thông báo cho tất cả các Observer khi có sự thay đổi
//void notifyObservers()
//{
//	for (Observer *observer : observers)
//	{
//		observer->update();
//	}
//}

RobotArmManager::RobotArmManager()
{
	currentStep = 0;
	nSteps = 0;
	// Initialize itsRotatingArmJoint pointers here
	for (int i = 0; i < MAX; ++i)
	{
		itsRotatingArmJoint[i] = nullptr;
	}
	// Initialize other members as needed
	status = 0;
}

// Destructor
RobotArmManager::~RobotArmManager()
{
}
