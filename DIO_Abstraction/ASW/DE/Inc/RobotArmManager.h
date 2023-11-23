#ifndef ROBOT_ARM_MANAGER_H_
#define ROBOT_ARM_MANAGER_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <cstdint>
#include "RotatingArmJoint.h"
#include "Action.h"
#include "AppType.h"

using namespace std;
/**
* @file RobotArmManager.h
* @brief Defines the RobotArmManager class for managing a robot arm's movements.
*/

#define MAX 3

	/**
	 * @class RobotArmManager
	 * @brief Manages the control of a robot arm.
	 */
	class RobotArmManager
	{
	private:
		unsigned int currentStep; /**< Current step in the trajectory */
		unsigned int nSteps;	  /**< Total number of steps in the trajectory */
		RotatingArmJoint *itsRotatingArmJoint[MAX]; /**< Array of RotatingArmJoint objects */
		Action itsAction[100]; /**< Array of Action objects */
		int status;
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

		/**
		 * @brief Constructor for the RobotArmManager class.
		 */
		RobotArmManager();

		/**
		 * @brief Destructor for the RobotArmManager class.
		 */
		virtual ~RobotArmManager();
	};

#ifdef __cplusplus
}
#endif

#endif /* ROBOT_ARM_MANAGER_H_ */
