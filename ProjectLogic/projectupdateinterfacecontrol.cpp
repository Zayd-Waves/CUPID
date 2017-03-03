#include "projectupdateinterfacecontrol.h"

ProjectUpdateInterfaceControl::ProjectUpdateInterfaceControl(StudentOutputManager* studentOutputManager,
                                                             AdminOutputManager* adminOutputManager)
{
  this->studentOutputManager = studentOutputManager;
  this->adminOutputManager = adminOutputManager;
}

void ProjectUpdateInterfaceControl::projectsLoaded(QList<Project*> projectList)
{
  this->studentOutputManager->setProjectList(projectList);
  this->adminOutputManager->setProjectList(projectList);
}

void ProjectUpdateInterfaceControl::projectAdded(Project* project)
{
  adminOutputManager->projectAdded(project);
}


void ProjectUpdateInterfaceControl::projectUpdated(Project* project)
{
  adminOutputManager->projectUpdated(project);
}


void ProjectUpdateInterfaceControl::projectDeleted(int projectId)
{
  adminOutputManager->projectDeleted(projectId);
}


void ProjectUpdateInterfaceControl::registrationAdded(Registration* registration)
{
    studentOutputManager->registrationHasAdded(registration);
}


void ProjectUpdateInterfaceControl::registrationDeleted(int projectId)
{
    studentOutputManager->registrationHasRemoved(projectId);
}
