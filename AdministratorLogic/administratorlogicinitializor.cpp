#include "administratorlogicinitializor.h"

AdministratorLogicInitializor::AdministratorLogicInitializor()
{
  adminUserInputControl = 0;
  adminUpdateInterfaceControl = 0;
  adminStorageAccess = 0;
  adminAuthControl = 0;
  algorithmConfigControl = 0;
  teamGenerationControl = 0;
}

AdministratorLogicInitializor::~AdministratorLogicInitializor()
{
  if (adminUpdateInterfaceControl) {
    delete adminUpdateInterfaceControl;
  }
  if (adminStorageAccess) {
    delete adminStorageAccess;
  }
  if (adminAuthControl) {
    delete adminAuthControl;
  }
  if (algorithmConfigControl) {
    delete algorithmConfigControl;
  }
  if (teamGenerationControl) {
    delete teamGenerationControl;
  }
}

void AdministratorLogicInitializor::intialize(StorageManager* storageManager,
                                              AdminInputManager* adminInputManager,
                                              AdminOutputManager* adminOutputManager,
                                              AuthenticationDialog* authDialog)
{
  this->adminUpdateInterfaceControl = new AdministratorUpdateInterfaceControl(adminOutputManager);
  this->adminStorageAccess = new AdministratorStorageAccess(storageManager);

  this->adminAuthControl = new AdministratorAuthenticationControl(
        this->adminStorageAccess,
        this->adminUpdateInterfaceControl);
  this->algorithmConfigControl = new AlgorithmConfigurationControl(this->adminUpdateInterfaceControl,
                                                                   this->adminStorageAccess);
  this->teamGenerationControl = new TeamGenerationControl(this->adminUpdateInterfaceControl);

  this->adminUserInputControl = new AdministratorUserInputControl(adminInputManager,
                                                                  authDialog,
                                                                  this->adminAuthControl,
                                                                  this->algorithmConfigControl,
                                                                  this->teamGenerationControl);
}
