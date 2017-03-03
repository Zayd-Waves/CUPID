#ifndef STUDENTLOGICINITIALIZOR_H
#define STUDENTLOGICINITIALIZOR_H

#include "Storage/storagemanager.h"
#include "studentupdateinterfacecontrol.h"
#include "AuthenticationInterface/authenticationdialog.h"
#include "studentuserinputcontrol.h"
#include "studentauthenticationcontrol.h"
#include "profilecontrol.h"
#include "studentstorageaccess.h"

class StudentLogicInitializor
{
  public:
    StudentLogicInitializor();
    ~StudentLogicInitializor();
    void initialize(StorageManager* storageManager,
                    StudentInputManager* studentInputManager,
                    StudentOutputManager* studentOutputManager,
                    AuthenticationDialog* authDialog);

  private:
    StudentUpdateInterfaceControl* studentUpdateInterfaceControl;
    StudentUserInputControl* studentUserInputControl;
};

#endif // STUDENTLOGICINITIALIZOR_H
