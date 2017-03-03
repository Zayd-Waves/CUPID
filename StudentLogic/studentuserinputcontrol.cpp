#include "studentuserinputcontrol.h"
#include "QDebug"

StudentUserInputControl::StudentUserInputControl(AuthenticationDialog* ad,
                                                 StudentInputManager* sim,
                                                 StudentAuthenticationControl* sac,
                                                 ProfileControl* pc)
{
    authDialog = ad;
    studentInputManager = sim;
    studentAuthenticationControl = sac;
    profileControl = pc;

    authDialog->subscribeToStudentAuthEvent(this);
    studentInputManager->subscribeToUpdateProfileEvent(this);
}

StudentUserInputControl::~StudentUserInputControl()
{
    delete authDialog;
    delete studentInputManager;
    delete studentAuthenticationControl;
    delete profileControl;
}

void StudentUserInputControl::notify(Event* event)
{
  QString eventname = event->getName();
  if (eventname == "studentLogin") {
      authenticateStudent();
  } else if (eventname == "updateProfile") {
      updateProfile();
  } else {
      qDebug() << "StudentUserInputControl: Unknown event type" << event->getName();
  }
}

void StudentUserInputControl::authenticateStudent()
{
    student = studentAuthenticationControl->verifyStudent(authDialog->getAuthEmail());
    if (student == NULL) {
        authDialog->showMessage("E-mail address not found",
                                "Couldn't find that Student's e-mail address. Are you sure you spelled it correctly?");
    } else {
        // succesfully logged in
        profileControl->setStudent(student);
        studentInputManager->setStudent(student);
        studentAuthenticationControl->displayStudentWindow();
        authDialog->close();
    }
}

void StudentUserInputControl::updateProfile()
{
  profileControl->updateProfile();
}
