#ifndef ADMINISTRATORUSERINPUTCONTROL_H
#define ADMINISTRATORUSERINPUTCONTROL_H

#include "AuthenticationInterface/authenticationdialog.h"
#include "AdministratorInterface/admininputmanager.h"

#include "administratorauthenticationcontrol.h"
#include "algorithmconfigurationcontrol.h"
#include "teamgenerationcontrol.h"

#include "libs/event.h"
#include "libs/subscriber.h"

class AdministratorUserInputControl : public Subscriber
{
  public:
    AdministratorUserInputControl(AdminInputManager* adminInputManager,
                                  AuthenticationDialog* authDialog,
                                  AdministratorAuthenticationControl* adminAuthControl,
                                  AlgorithmConfigurationControl* algorithmConfigControl,
                                  TeamGenerationControl* teamGenerationControl);

  private:
    void notify(Event* event);
    AdminInputManager* adminInputManager;
    AuthenticationDialog* authDialog;
    AdministratorAuthenticationControl* adminAuthControl;
    AlgorithmConfigurationControl* algorithmConfigControl;
    TeamGenerationControl* teamGenerationControl;

    void authenticateAdmin();
    void generateTeams();
    void saveAlgorithmConfig();
};

#endif // ADMINISTRATORUSERINPUTCONTROL_H
