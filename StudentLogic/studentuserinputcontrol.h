#ifndef STUDENTUSERINPUTCONTROL_H
#define STUDENTUSERINPUTCONTROL_H

#include "libs/event.h"
#include "libs/subscriber.h"
#include "StudentInterface/studentinputmanager.h"
#include "AuthenticationInterface/authenticationdialog.h"
#include "studentauthenticationcontrol.h"
#include "profilecontrol.h"
#include "Storage/student.h"

class StudentUserInputControl : public Subscriber
{
  public:
    StudentUserInputControl(AuthenticationDialog*,
                            StudentInputManager*,
                            StudentAuthenticationControl*,
                            ProfileControl*);
    ~StudentUserInputControl();
    void notify(Event*);
    void authenticateStudent();
    void updateProfile();

  private:
    AuthenticationDialog* authDialog;
    StudentInputManager* studentInputManager;
    StudentAuthenticationControl* studentAuthenticationControl;
    ProfileControl* profileControl;
    Student* student;

};

#endif // STUDENTUSERINPUTCONTROL_H
