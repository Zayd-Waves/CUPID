#include "admininterfaceinitializor.h"
#include "algorithmconfigurationeditdialog.h"
#include "busydialog.h"

AdminInterfaceInitializor::AdminInterfaceInitializor()
{
  adminInputManager = NULL;
  adminOutputManager = NULL;
}

AdminInterfaceInitializor::~AdminInterfaceInitializor()
{
  if (adminInputManager) {
    delete adminInputManager;
  }
  if (adminOutputManager) {
    delete adminOutputManager;
  }
}

void AdminInterfaceInitializor::initialize()
{
  this->adminInputManager = new AdminInputManager();
  this->adminOutputManager = new AdminOutputManager();

  ProjectListWindow* projectListWindow = new ProjectListWindow(this->adminInputManager);
  ProjectEditDialog* projectEditDialog = new ProjectEditDialog(this->adminInputManager, projectListWindow);

  TeamResultDialog* teamResultDialog = new TeamResultDialog(projectListWindow);
  AlgorithmConfigurationEditDialog* algoEditDialog = new AlgorithmConfigurationEditDialog(this->adminInputManager,
                                                                                          projectListWindow);
  BusyDialog* busyDialog = new BusyDialog(projectListWindow);

  this->adminInputManager->setProjectListWindow(projectListWindow);
  this->adminInputManager->setProjectEditDialog(projectEditDialog);
  this->adminInputManager->setTeamResultDialog(teamResultDialog);
  this->adminInputManager->setAlgoEditDialog(algoEditDialog);
  this->adminInputManager->setBusyDialog(busyDialog);

  this->adminOutputManager->setProjectListWindow(projectListWindow);
  this->adminOutputManager->setProjectEditDialog(projectEditDialog);
  this->adminOutputManager->setTeamResultDialog(teamResultDialog);
  this->adminOutputManager->setAlgoEditDialog(algoEditDialog);
  this->adminOutputManager->setBusyDialog(busyDialog);
}

AdminInputManager* AdminInterfaceInitializor::getAdminInputManager() const
{
  return adminInputManager;
}

AdminOutputManager* AdminInterfaceInitializor::getAdminOutputManager() const
{
  return adminOutputManager;
}
