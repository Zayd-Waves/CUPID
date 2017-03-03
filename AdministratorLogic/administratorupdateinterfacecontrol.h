#ifndef ADMINISTRATORUPDATEINTERFACECONTROL_H
#define ADMINISTRATORUPDATEINTERFACECONTROL_H

#include "AdministratorInterface/adminoutputmanager.h"
#include "Storage/algorithmconfiguration.h"
#include "Storage/administrator.h"
#include "team.h"

#include <QList>
#include <QFuture>
#include <QFutureWatcher>


class AdministratorUpdateInterfaceControl
{
  public:
    AdministratorUpdateInterfaceControl(AdminOutputManager* adminOutputManager);
    void displayProjectList(Administrator* administrator);
    void algorithmConfigUpdated(AlgorithmConfiguration* algorithmConfig);
    void teamsGenerated(QList<Team*> teams);

  private:
    AdminOutputManager* adminOutputManager;
};

#endif // ADMINISTRATORUPDATEINTERFACECONTROL_H
