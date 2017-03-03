#include "projectlogicinitializor.h"

#include "StudentInterface/studentinputmanager.h"
#include "StudentInterface/studentoutputmanager.h"
#include "AdministratorInterface/admininputmanager.h"
#include "AdministratorInterface/adminoutputmanager.h"

#include "projectcontrol.h"
#include "registrationcontrol.h"
#include "projectstorageaccess.h"

ProjectLogicInitializor::ProjectLogicInitializor()
{
  projectUpdateInterface = NULL;
  projectUserInput = NULL;
}

ProjectLogicInitializor::~ProjectLogicInitializor()
{
  if (projectUpdateInterface) {
    delete projectUpdateInterface;
  }
}

void ProjectLogicInitializor::initialize(StorageManager* storageManager,
                                         StudentInputManager* studentInput,
                                         StudentOutputManager* studentOutput,
                                         AdminInputManager* adminInput,
                                         AdminOutputManager* adminOutput)
{
  ProjectStorageAccess* projectStorageAccess = new ProjectStorageAccess(storageManager);

  this->projectUpdateInterface = new ProjectUpdateInterfaceControl(studentOutput,
                                                             adminOutput);

  RegistrationControl* regstrationControl = new RegistrationControl(projectStorageAccess,
                                                                    projectUpdateInterface);
  ProjectControl* projectControl = new ProjectControl(projectStorageAccess,
                                                      projectUpdateInterface);

  this->projectUserInput = new ProjectUserInputControl(studentInput, adminInput,
                                                 projectControl, regstrationControl);
}
