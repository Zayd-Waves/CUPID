#include "adminoutputmanager.h"

AdminOutputManager::AdminOutputManager()
{

}

AdminOutputManager::~AdminOutputManager()
{

}

void AdminOutputManager::displayProjectList(Administrator* administrator){
  this->administrator = administrator;
  this->projectListWindow->show(administrator, projectList);
}

void AdminOutputManager::setProjectList(QList<Project*> projectList)
{
  this->projectList.clear();
  this->projectList.append(projectList);
}

void AdminOutputManager::projectAdded(Project* project)
{
  this->projectList.append(project);
  this->projectListWindow->addProject(project);
  this->projectEditDialog->close();
}

void AdminOutputManager::projectUpdated(Project* project)
{
  this->projectListWindow->updateProject(project);
  this->projectEditDialog->close();
}

void AdminOutputManager::projectDeleted(int projectId)
{
  this->projectListWindow->removeProject(projectId);
}

void AdminOutputManager::algorithmConfigurationUpdated(AlgorithmConfiguration* config)
{
  if (config) {
    this->algoEditDialog->close();
  }
}

void AdminOutputManager::teamsGenerated(QList<Team*> teams)
{
  if (!teams.length()) {
    this->projectListWindow->showCriticalMessage("Team Generation failed.",
                                         "There aren't enough students registered for this project.");
    this->busyDialog->close();
    return;
  }

  this->busyDialog->close();
  this->teamResultDialog->show(teams);
}

ProjectListWindow* AdminOutputManager::getProjectListWindow() const
{
  return projectListWindow;
}

void AdminOutputManager::setProjectListWindow(ProjectListWindow* value)
{
  projectListWindow = value;
}

ProjectEditDialog* AdminOutputManager::getProjectEditDialog() const
{
  return projectEditDialog;
}

void AdminOutputManager::setProjectEditDialog(ProjectEditDialog* value)
{
  projectEditDialog = value;
}

TeamResultDialog* AdminOutputManager::getTeamResultDialog() const
{
  return teamResultDialog;
}

void AdminOutputManager::setTeamResultDialog(TeamResultDialog* value)
{
  teamResultDialog = value;
}

BusyDialog* AdminOutputManager::getBusyDialog() const
{
  return busyDialog;
}

void AdminOutputManager::setBusyDialog(BusyDialog* value)
{
  busyDialog = value;
}
AlgorithmConfigurationEditDialog* AdminOutputManager::getAlgoEditDialog() const
{
  return algoEditDialog;
}

void AdminOutputManager::setAlgoEditDialog(AlgorithmConfigurationEditDialog* value)
{
  algoEditDialog = value;
}



