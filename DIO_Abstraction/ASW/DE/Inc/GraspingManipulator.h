#ifndef GRASPING_MANIPULATOR_H_
#define GRASPING_MANIPULATOR_H_

class GraspingManipulator
{
private:
    int maxForce;
    bool isOpen;

public:
    GraspingManipulator()
    {
        maxForce = 0;
        isOpen = false;
    }

    void setMaxForce(int force)
    {
        maxForce = force;
    }

    int getMaxForce() const
    {
        return maxForce;
    }

    void open()
    {
        isOpen = true;
    }

    void close()
    {
        isOpen = false;
    }

    bool isOpened() const
    {
        return isOpen;
    }

    // Add other member functions and data members as needed

    ~GraspingManipulator()
    {
        // Destructor code, if any
    }
};

#endif /* GRASPING_MANIPULATOR_H_ */
