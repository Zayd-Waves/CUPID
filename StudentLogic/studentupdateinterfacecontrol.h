#ifndef STUDENTUPDATEINTERFACECONTROL_H
#define STUDENTUPDATEINTERFACECONTROL_H

#include "Storage/student.h"
#include "Storage/profile.h"
#include "StudentInterface/studentoutputmanager.h"

class StudentUpdateInterfaceControl
{
  public:
    StudentUpdateInterfaceControl(StudentOutputManager*);
    ~StudentUpdateInterfaceControl();
    void setStudent(Student*);
    void showProjectList();
    void showProfileForm();

  private:
    Student* student;
    StudentOutputManager* studentOutputManager;

};

#endif // STUDENTUPDATEINTERFACECONTROL_H
