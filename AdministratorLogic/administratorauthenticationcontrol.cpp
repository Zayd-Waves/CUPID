#include "administratorauthenticationcontrol.h"

AdministratorAuthenticationControl::AdministratorAuthenticationControl(
    AdministratorStorageAccess* adminStorageAccess,
    AdministratorUpdateInterfaceControl* adminUpdateInterface)
{
  this->adminStorageAccess = adminStorageAccess;
  this->adminUpdateInterface = adminUpdateInterface;
}

bool AdministratorAuthenticationControl::authenticateAdministrator(QString email)
{
     Administrator* administrator = adminStorageAccess->getAdministrator(email);
     if (administrator == NULL) {
         return false;
     }
     adminUpdateInterface->displayProjectList(administrator);
     return true;
}
