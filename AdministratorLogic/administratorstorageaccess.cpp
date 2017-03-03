#include "administratorstorageaccess.h"

AdministratorStorageAccess::AdministratorStorageAccess(StorageManager* storageManager)
{
  this->storageManager = storageManager;
}

Administrator* AdministratorStorageAccess::getAdministrator(QString email)
{
  return storageManager->retrieveAdministrator(email);
}

bool AdministratorStorageAccess::storeAdministrator(Administrator* administrator)
{
  return storageManager->storeAdministrator(administrator);
}
