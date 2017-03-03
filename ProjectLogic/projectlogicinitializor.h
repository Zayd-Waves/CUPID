#ifndef PROJECTLOGICINITIALIZOR_H
#define PROJECTLOGICINITIALIZOR_H

#include "Storage/storagemanager.h"
#include "projectupdateinterfacecontrol.h"
#include "projectuserinputcontrol.h"

class ProjectLogicInitializor
{
  public:
    ProjectLogicInitializor();
    ~ProjectLogicInitializor();
    void initialize(StorageManager* storageManager,
                    StudentInputManager* studentInput,
                    StudentOutputManager* studentOutput,
                    AdminInputManager* adminInput,
                    AdminOutputManager* adminOutput);

  private:
    ProjectUpdateInterfaceControl* projectUpdateInterface;
    ProjectUserInputControl* projectUserInput;

};

#endif // PROJECTLOGICINITIALIZOR_H
