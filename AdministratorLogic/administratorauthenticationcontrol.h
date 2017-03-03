#ifndef ADMINISTRATORAUTHENTICATIONCONTROL_H
#define ADMINISTRATORAUTHENTICATIONCONTROL_H

#include "administratorstorageaccess.h"
#include "administratorupdateinterfacecontrol.h"

class AdministratorAuthenticationControl
{
  public:
    AdministratorAuthenticationControl(AdministratorStorageAccess* adminStorageAccess,
                                       AdministratorUpdateInterfaceControl* adminUpdateInterface);
    bool authenticateAdministrator(QString);

  private:
    AdministratorStorageAccess* adminStorageAccess;
    AdministratorUpdateInterfaceControl* adminUpdateInterface;
};

#endif // ADMINISTRATORAUTHENTICATIONCONTROL_H
