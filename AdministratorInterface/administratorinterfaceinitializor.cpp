#include "administratorinterfaceinitializor.h"

AdministratorInterfaceInitializor::AdministratorInterfaceInitializor()
{
  adminInputManager = 0;
  adminOutputManager = 0;
}

AdministratorInterfaceInitializor::~AdministratorInterfaceInitializor()
{
  if (adminInputManager) {
    delete adminInputManager;
  }
  if (adminOutputManager) {
    delete adminOutputManager;
  }
}

void AdministratorInterfaceInitializor::intialize()
{
  if (!adminInputManager) {
    this->adminInputManager = new AdminInputManager();
  }
  if (!adminOutputManager) {
    this->adminOutputManager = new AdminOutputManager();
  }
}

AdminInputManager* AdministratorInterfaceInitializor::getAdminInputManager() const
{
  return adminInputManager;
}

AdminOutputManager* AdministratorInterfaceInitializor::getAdminOutputManager() const
{
  return adminOutputManager;
}


