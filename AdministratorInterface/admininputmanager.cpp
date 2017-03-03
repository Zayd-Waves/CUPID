#include "admininputmanager.h"
#include <QList>
#include "AdministratorLogic/team.h"

AdminInputManager::AdminInputManager()
{
  createProjectEvent = new Event("createProject");
  updateProjectEvent= new Event("updateProject");
  deleteProjectEvent= new Event("deleteProject");
  generateTeamsEvent = new Event("generateTeams");
  saveAlgorithmConfigEvent = new Event("saveAlgorithmConfig");
}
AdminInputManager::~AdminInputManager(){}

void AdminInputManager::subscribeToCreateProjectEvent(Subscriber* s)
{
  createProjectEvent->subscribe(s);
}

void AdminInputManager::subscribeToUpdateProjectEvent(Subscriber* s)
{
  updateProjectEvent->subscribe(s);
}

void AdminInputManager::subscribeToDeleteProjectEvent(Subscriber* s)
{
  deleteProjectEvent->subscribe(s);
}

void AdminInputManager::subscribeToGenerateTeamsEvent(Subscriber* s)
{
  generateTeamsEvent->subscribe(s);
}

void AdminInputManager::subscribeToSaveAlgorithmConfigEvent(Subscriber* s)
{
  saveAlgorithmConfigEvent->subscribe(s);
}

Project* AdminInputManager::getSelectedProject()
{
  return this->projectListWindow->findSelectedProject();
}

Project* AdminInputManager::getProjectDetails()
{
  return this->projectEditDialog->getProject();
}

Administrator* AdminInputManager::getAdministrator()
{
  return this->projectListWindow->getAdministrator();
}

void AdminInputManager::createProject()
{
  this->createProjectEvent->notifySubscribers();
}

void AdminInputManager::updateProject()
{
  this->updateProjectEvent->notifySubscribers();
}


void AdminInputManager::deleteProject()
{
  this->deleteProjectEvent->notifySubscribers();

}

void AdminInputManager::generateTeams()
{
  this->busyDialog->show();
  this->generateTeamsEvent->notifySubscribers();
}

void AdminInputManager::saveAlgorithmConfig()
{
  this->saveAlgorithmConfigEvent->notifySubscribers();
}

void AdminInputManager::displayProjectEditDialog(Project* project)
{
  if (project) {
    this->projectEditDialog->showEdit(project);
  } else {
    this->projectEditDialog->show();
  }
}

void AdminInputManager::configureAlgorithm(AlgorithmConfiguration* algoConfig)
{
  this->algoEditDialog->show(algoConfig);
}


ProjectListWindow* AdminInputManager::getProjectListWindow() const
{
  return projectListWindow;
}

void AdminInputManager::setProjectListWindow(ProjectListWindow* value)
{
  projectListWindow = value;
}

ProjectEditDialog* AdminInputManager::getProjectEditDialog() const
{
  return projectEditDialog;
}

void AdminInputManager::setProjectEditDialog(ProjectEditDialog* value)
{
  projectEditDialog = value;
}

TeamResultDialog* AdminInputManager::getTeamResultDialog() const
{
  return teamResultDialog;
}

void AdminInputManager::setTeamResultDialog(TeamResultDialog* value)
{
  teamResultDialog = value;
}

BusyDialog* AdminInputManager::getBusyDialog() const
{
  return busyDialog;
}

void AdminInputManager::setBusyDialog(BusyDialog* value)
{
  busyDialog = value;
}
AlgorithmConfigurationEditDialog* AdminInputManager::getAlgoEditDialog() const
{
  return algoEditDialog;
}

void AdminInputManager::setAlgoEditDialog(AlgorithmConfigurationEditDialog* value)
{
  algoEditDialog = value;
}



