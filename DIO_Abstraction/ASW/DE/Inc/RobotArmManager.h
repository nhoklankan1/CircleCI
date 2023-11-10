#ifndef ROBOT_ARM_MANAGER_H_
#define ROBOT_ARM_MANAGER_H_

#ifdef __cplusplus
extern "C"
{
#endif

// #include "GraspingManipulator.h"
#include "RotatingArmJoint.h"
// #include "SlidingArmJoint.h"
#include "Action.h"
#include "AppType.h"
//#include <vector>
//#include <algorithm>
//#include <iostream>
//#include <string>
	using namespace std;
	/**
	 * @file RobotArmManager.h
	 * @brief Defines the RobotArmManager class for managing a robot arm's movements.
	 */

#define MAX 3

//	class Observer
//	{
//	public:
//		virtual void update() = 0;
//	};

	/**
	 * @class RobotArmManager
	 * @brief Manages the control of a robot arm.
	 */
	class RobotArmManager
	{
	private:
		unsigned int currentStep; /**< Current step in the trajectory */
		unsigned int nSteps;	  /**< Total number of steps in the trajectory */
		// GraspingManipulator *itsGraspingManipulator; // Uncomment if used
		RotatingArmJoint *itsRotatingArmJoint[MAX]; /**< Array of RotatingArmJoint objects */
		// SlidingArmJoint *itsSlidingArmJoint[2]; // Uncomment if used
		Action itsAction[100]; /**< Array of Action objects */
		int status;
//		vector<Observer*> observers;
//		vector<Observer*> errorObservers;
	public:
		/**
		 * @brief Computes the trajectory for the robot arm.
		 * @param x X-coordinate
		 * @param y Y-coordinate
		 * @param z Z-coordinate
		 * @param t Time parameter
		 */
		void RobotArmManager_computeTrajectory(int x, int y, int z, int t);

		/**
		 * @brief Rotate the step motor to a specific angle.
		 *
		 * This function rotates the step motor associated with the given `RotatingArmJoint` object
		 * to the specified angle.
		 *
		 * @param itsRotatingArmJoint Pointer to the `RotatingArmJoint` object controlling the step motor.
		 * @param value The angle to rotate to.
		 * @return 1 if the rotation is successful, 0 otherwise.
		 */
		int RotatingArmJoint_rotate(RotatingArmJoint *itsRotatingArmJoint, ActionValue value);

		/**
		 * @brief Checks if an Action object is empty.
		 * @param action The Action object to check.
		 * @return True if the Action object is empty, false otherwise.
		 */
		bool isActionEmpty(const Action &action);
		/**
		 * @brief Executes the next step in the trajectory.
		 * @return 1 if successful, 0 otherwise.
		 */
		int RobotArmManager_executeStep();

		/**
		 * @brief Grasps an object at the specified position.
		 * @param x X-coordinate
		 * @param y Y-coordinate
		 * @param z Z-coordinate
		 * @param t Time parameter
		 * @return 1 if successful, 0 otherwise.
		 */
		int RobotArmManager_graspAt(int x, int y, int z, int t);

		/**
		 * @brief Reset the angle of the step motor to zero.
		 *
		 * This function resets the angle of the step motor associated with the given `RotatingArmJoint`
		 * object to zero.
		 *
		 * @param itsRotatingArmJoint Pointer to the `RotatingArmJoint` object controlling the step motor.
		 * @return 1 if the reset operation is successful, 0 otherwise.
		 */
		int RotatingArmJoint_zero(RotatingArmJoint *itsRotatingArmJoint);

		/**
		 * @brief Resets the robot arm's position to zero.
		 * @return 1 if successful, 0 otherwise.
		 */
		int RobotArmManager_zero();

		// Uncomment these if used...
		// GraspingManipulator *RobotArmManager_getItsGraspingManipulator();
		// void RobotArmManager_setItsGraspingManipulator(GraspingManipulator *p_GraspingManipulator);

		/**
		 * @brief Gets the number of RotatingArmJoint objects.
		 * @return The number of RotatingArmJoint objects.
		 */
		int RobotArmManager_getItsRotatingArmJoint();

		/**
		 * @brief Adds a RotatingArmJoint object to the manager.
		 * @param p_RotatingArmJoint Pointer to the RotatingArmJoint object to add.
		 */
		void RobotArmManager_addItsRotatingArmJoint(RotatingArmJoint *p_RotatingArmJoint);

		/**
		 * @brief Removes a RotatingArmJoint object from the manager.
		 * @param p_RotatingArmJoint Pointer to the RotatingArmJoint object to remove.
		 */
		void RobotArmManager_removeItsRotatingArmJoint(RotatingArmJoint *p_RotatingArmJoint);

		/**
		 * @brief Clears the list of RotatingArmJoint objects.
		 */
		void RobotArmManager_clearItsRotatingArmJoint();

		// Uncomment these if used...
		// int RobotArmManager_getItsSlidingArmJoint();
		// void RobotArmManager_addItsSlidingArmJoint(SlidingArmJoint *p_SlidingArmJoint);
		// void RobotArmManager_removeItsSlidingArmJoint(SlidingArmJoint *p_SlidingArmJoint);
		// void RobotArmManager_clearItsSlidingArmJoint();

		/**
		 * @brief Gets the number of Action objects.
		 * @return The number of Action objects.
		 */
		int RobotArmManager_getItsAction();

		/**
		 * @brief Adds an Action object to the manager.
		 * @param p_Action Pointer to the Action object to add.
		 */
		void RobotArmManager_addItsAction(Action *p_Action);

		/**
		 * @brief Removes an Action object from the manager.
		 * @param p_Action Pointer to the Action object to remove.
		 */
		void RobotArmManager_removeItsAction(Action *p_Action);

		/**
		 * @brief Clears the list of Action objects.
		 */
		void RobotArmManager_clearItsAction();

//		void attachObserver(Observer *observer);
//
//		// Hủy đăng ký một Observer
//		void detachObserver(Observer *observer);
//
//		// Thông báo cho tất cả các Observer khi có sự thay đổi
//		void notifyObservers();
//		void attachObserver(Observer *observer)
//		{
//			observers.push_back(observer);
//		}
//
//		// Hủy đăng ký một Observer
//		void detachObserver(Observer *observer)
//		{
//			observers.erase(remove(observers.begin(), observers.end(), observer), observers.end());
//		}
//
//		// Thông báo cho tất cả các Observer khi có sự thay đổi
//		void notifyObservers()
//		{
//			for (Observer *observer : observers)
//			{
//				observer->update();
//			}
//		}
//		void attachErrorCheckObserver(Observer* observer) {
//		        errorObservers.push_back(observer);
//		    }
//
//		    // Hủy đăng ký một Observer cho cơ chế kiểm tra lỗi
//		    void detachErrorCheckObserver(Observer* observer) {
//		        errorObservers.erase(
//		            remove(errorObservers.begin(), errorObservers.end(), observer), errorObservers.end());
//		    }
//
//		    // Thông báo cho tất cả các Observer khi có lỗi xảy ra
//		    void notifyErrorObservers() {
//		        for (Observer* observer : errorObservers) {
//		            observer->update();
//		        }
//		    }

		/**
		 * @brief Constructor for the RobotArmManager class.
		 */
		RobotArmManager();

		/**
		 * @brief Destructor for the RobotArmManager class.
		 */
		virtual ~RobotArmManager();
	};

//	class ArmManagerObserver : public Observer
//	{
//	public:
//		// Constructor và các phương thức khác (nếu cần) cho ArmManagerObserver
//
//		void update() override
//		{
//			// Đây là nơi bạn triển khai hành động khi có sự thay đổi trong RobotArmManager
//			// Ví dụ: In ra thông báo hoặc thực hiện một tác vụ cụ thể
//			cout << "change" << endl;
//		}
//	};
//
//	class ErrorCheckObserver : public Observer {
//	public:
//	    void update() override {
//	        // Xử lý lỗi tại đây, ví dụ in ra thông báo hoặc thực hiện hành động cụ thể
//	        cout << "Lỗi trong RotatingArmJoint. Mã lỗi: " << endl;
//	    }
//	};

#ifdef __cplusplus
}
#endif

#endif /* ROBOT_ARM_MANAGER_H_ */
