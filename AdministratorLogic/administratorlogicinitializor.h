#ifndef ADMINISTRATORLOGICINITIALIZOR_H
#define ADMINISTRATORLOGICINITIALIZOR_H

#include "administratoruserinputcontrol.h"
#include "administratorupdateinterfacecontrol.h"
#include "administratorstorageaccess.h"
#include "administratorauthenticationcontrol.h"
#include "algorithmconfigurationcontrol.h"
#include "teamgenerationcontrol.h"

#include "Storage/storagemanager.h"
#include "AdministratorInterface/admininputmanager.h"
#include "AdministratorInterface/adminoutputmanager.h"
#include "AuthenticationInterface/authenticationdialog.h"

class AdministratorLogicInitializor
{
  public:
    AdministratorLogicInitializor();
    ~AdministratorLogicInitializor();
    void intialize(StorageManager* storageManager,
                   AdminInputManager* adminInputManager,
                   AdminOutputManager* adminOutputManager,
                   AuthenticationDialog* authDialog);

  private:
    AdministratorUserInputControl* adminUserInputControl;
    AdministratorUpdateInterfaceControl* adminUpdateInterfaceControl;
    AdministratorStorageAccess* adminStorageAccess;
    AdministratorAuthenticationControl* adminAuthControl;
    AlgorithmConfigurationControl* algorithmConfigControl;
    TeamGenerationControl* teamGenerationControl;

};

#endif // ADMINISTRATORLOGICINITIALIZOR_H
