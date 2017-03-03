#include "profilecontrol.h"

ProfileControl::ProfileControl(StudentStorageAccess* studentStorageAccess,
                               StudentUpdateInterfaceControl* studentUpdateInterfaceControl)
{
    this->studentStorageAccess = studentStorageAccess;
    this->studentUpdateInterfaceControl = studentUpdateInterfaceControl;
}

ProfileControl::~ProfileControl()
{

}

void ProfileControl::setStudent(Student *stud)
{
    student = stud;
}

bool ProfileControl::updateProfile()
{
    return studentStorageAccess->storeProfile(student);
}

Profile* ProfileControl::getProfileDetail(Student* student)
{
    return student->getProfile();
}


