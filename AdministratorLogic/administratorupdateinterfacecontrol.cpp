#include "administratorupdateinterfacecontrol.h"

AdministratorUpdateInterfaceControl::AdministratorUpdateInterfaceControl(AdminOutputManager* adminOutputManager)
{
  this->adminOutputManager = adminOutputManager;
}

void AdministratorUpdateInterfaceControl::displayProjectList(Administrator* administrator)
{
  adminOutputManager->displayProjectList(administrator);
}

void AdministratorUpdateInterfaceControl::algorithmConfigUpdated(AlgorithmConfiguration* algorithmConfiguration)
{
  adminOutputManager->algorithmConfigurationUpdated(algorithmConfiguration);
}

void AdministratorUpdateInterfaceControl::teamsGenerated(QList<Team*> teams)
{
  adminOutputManager->teamsGenerated(teams);
}

