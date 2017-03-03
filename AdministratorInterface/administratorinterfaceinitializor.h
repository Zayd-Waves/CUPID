#ifndef ADMINISTRATORINTERFACEINITIALIZOR_H
#define ADMINISTRATORINTERFACEINITIALIZOR_H

#include "admininputmanager.h"
#include "adminoutputmanager.h"

class AdministratorInterfaceInitializor
{
  public:
    AdministratorInterfaceInitializor();
    ~AdministratorInterfaceInitializor();
    void intialize();
    AdminInputManager* getAdminInputManager() const;
    AdminOutputManager* getAdminOutputManager() const;

  private:
    AdminInputManager* adminInputManager;
    AdminOutputManager* adminOutputManager;
};

#endif // ADMINISTRATORINTERFACEINITIALIZOR_H
