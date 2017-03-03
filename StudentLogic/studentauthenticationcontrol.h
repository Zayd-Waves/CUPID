#ifndef STUDENTAUTHENTICATIONCONTROL_H
#define STUDENTAUTHENTICATIONCONTROL_H

#include "Storage/student.h"
#include "studentupdateinterfacecontrol.h"
#include "StudentLogic/studentstorageaccess.h"

class StudentAuthenticationControl
{
  public:
    StudentAuthenticationControl(StudentStorageAccess*, StudentUpdateInterfaceControl*);
    ~StudentAuthenticationControl();
    Student* verifyStudent(QString);
    void displayStudentWindow();

  private:
    StudentStorageAccess* studentStorageAccessor;
    StudentUpdateInterfaceControl* studentUpdateInterfaceControl;
    Student* student;

};

#endif // STUDENTAUTHENTICATIONCONTROL_H
