#ifndef ADMININTERFACEINITIALIZOR_H
#define ADMININTERFACEINITIALIZOR_H

#include "admininputmanager.h"
#include "adminoutputmanager.h"

#include "AdministratorLogic/administratorupdateinterfacecontrol.h"
#include "AdministratorLogic/administratoruserinputcontrol.h"


class AdminInterfaceInitializor
{
  public:
    AdminInterfaceInitializor();
    ~AdminInterfaceInitializor();
    void initialize();
    AdminInputManager* getAdminInputManager() const;
    AdminOutputManager* getAdminOutputManager() const;

  private:
    AdminInputManager* adminInputManager;
    AdminOutputManager* adminOutputManager;

};

#endif // ADMININTERFACEINITIALIZOR_H
