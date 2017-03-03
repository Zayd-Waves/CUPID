#include "administratoruserinputcontrol.h"
#include "team.h"
#include <QDebug>

AdministratorUserInputControl::AdministratorUserInputControl(AdminInputManager* adminInputManager,
                                                             AuthenticationDialog* authDialog,
                                                             AdministratorAuthenticationControl* adminAuthControl,
                                                             AlgorithmConfigurationControl* algorithmConfigControl,
                                                             TeamGenerationControl* teamGenerationControl) :
  Subscriber()
{
  this->adminInputManager = adminInputManager;
  this->authDialog = authDialog;
  this->adminAuthControl = adminAuthControl;
  this->algorithmConfigControl = algorithmConfigControl;
  this->teamGenerationControl = teamGenerationControl;

  authDialog->subscribeToAdminAuthEvent(this);
  adminInputManager->subscribeToGenerateTeamsEvent(this);
  adminInputManager->subscribeToSaveAlgorithmConfigEvent(this);
}

void AdministratorUserInputControl::notify(Event* event)
{
  QString eventName = event->getName();

  if (eventName == "adminLogin") {
    authenticateAdmin();
  } else if (eventName == "saveAlgorithmConfig") {
    saveAlgorithmConfig();
  } else if (eventName == "generateTeams") {
    generateTeams();
  } else {
    qDebug() << "AministratorUserInputControl: Unknown event received" << eventName;
  }
}

void AdministratorUserInputControl::authenticateAdmin()
{
  QString email = authDialog->getAuthEmail();
  if (adminAuthControl->authenticateAdministrator(email)) {
    authDialog->closeInterface();
  } else  {
    authDialog->showMessage("Authentication Failed", "Could not authenticate as an Administrator.");
  }
}

void AdministratorUserInputControl::generateTeams()
{
  Project* project = adminInputManager->getSelectedProject();
  if (!project) {
    return;
  }
  Administrator* admin = adminInputManager->getAdministrator();
  teamGenerationControl->generateTeams(admin->getAlgorithmConfiguration(), project);
}

void AdministratorUserInputControl::saveAlgorithmConfig()
{
  algorithmConfigControl->updateAlgorithmConfiguration(adminInputManager->getAdministrator());
}

