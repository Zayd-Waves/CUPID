#ifndef ADMINISTRATORSTORAGEACCESS_H
#define ADMINISTRATORSTORAGEACCESS_H

#include "Storage/storagemanager.h"


class AdministratorStorageAccess
{
  public:
    AdministratorStorageAccess(StorageManager* storageManager);
    Administrator* getAdministrator(QString);
    bool storeAdministrator(Administrator*);

  private:
    StorageManager* storageManager;
};

#endif // ADMINISTRATORSTORAGEACCESS_H
