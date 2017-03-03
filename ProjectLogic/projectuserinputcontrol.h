#ifndef PROJECTUSERINPUTCONTROL_H
#define PROJECTUSERINPUTCONTROL_H

#include "registrationcontrol.h"
#include "projectcontrol.h"
#include "libs/event.h"
#include "libs/subscriber.h"
#include "StudentInterface/studentinputmanager.h"
#include "AdministratorInterface/admininputmanager.h"


class ProjectUserInputControl : public Subscriber
{
  public:
    ProjectUserInputControl(StudentInputManager* studentInputManager,
                            AdminInputManager* adminInputManager,
                            ProjectControl* projectControl,
                            RegistrationControl* registrationControl);
    ~ProjectUserInputControl();


    void notify(Event* event);

    //administrator side
    void createProject();
    void updateProject();
    void deleteProject();

    //student side
    void registerForProject();
    void deregisterFromProject();

  private:
    StudentInputManager* studentInputManager;
    AdminInputManager* adminInputManager;
    RegistrationControl* registrationControl;
    ProjectControl* projectControl;

};
#endif // PROJECTUSERINPUTCONTROL_H
