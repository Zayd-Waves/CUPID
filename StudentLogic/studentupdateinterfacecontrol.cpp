#include "studentupdateinterfacecontrol.h"

StudentUpdateInterfaceControl::StudentUpdateInterfaceControl(StudentOutputManager* som)
{
    studentOutputManager = som;
}

StudentUpdateInterfaceControl::~StudentUpdateInterfaceControl()
{
    delete studentOutputManager;
}

void StudentUpdateInterfaceControl::setStudent(Student * stu)
{
    student = stu;
}

void StudentUpdateInterfaceControl::showProjectList()
{
    studentOutputManager->displayProjectList();
}

void StudentUpdateInterfaceControl::showProfileForm()
{
    studentOutputManager->displayProfileDetails(student);
}




