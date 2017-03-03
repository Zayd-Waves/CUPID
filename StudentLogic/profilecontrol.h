#ifndef PROFILECONTROL_H
#define PROFILECONTROL_H

#include "Storage/profile.h"

#include "studentstorageaccess.h"
#include "studentupdateinterfacecontrol.h"


class ProfileControl
{
public:
    ProfileControl(StudentStorageAccess* studentStorageAccess,
                   StudentUpdateInterfaceControl* studentUpdateInterfaceControl);
    ~ProfileControl();
    void setStudent(Student*);
    bool updateProfile();
    Profile* getProfileDetail(Student*);

private:
    StudentStorageAccess* studentStorageAccess;
    StudentUpdateInterfaceControl* studentUpdateInterfaceControl;
    Student* student;
};

#endif // PROFILECONTROL_H
