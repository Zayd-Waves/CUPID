#include "projectcontrol.h"

ProjectControl::ProjectControl(ProjectStorageAccess* projectStorageAccess,
                               ProjectUpdateInterfaceControl* projectUpdateInterfaceControl)
{
  this->projectStorageAccess = projectStorageAccess;
  this->projectUpdateInterfaceControl = projectUpdateInterfaceControl;

  projectUpdateInterfaceControl->projectsLoaded(getAllProjects());
}

Project* ProjectControl::get(int projectId)
{
  return projectStorageAccess->retrieveProjectFromStorage(projectId);
}


QList<Project*> ProjectControl::getAllProjects()
{
  return projectStorageAccess->retrieveAllProjectsFromStorage();
}


bool ProjectControl::addProject(Project* project)
{
  bool success = projectStorageAccess->storeProjectIntoStorage(project);
  if(success == true) {
    projectUpdateInterfaceControl->projectAdded(project);
  }
  return success;

}


bool ProjectControl::updateProject(Project* project)
{
  bool success = projectStorageAccess->updateProjectToStorage(project);
  if(success == true) {
    projectUpdateInterfaceControl->projectUpdated(project);
  }
  return success;
}



bool ProjectControl::removeProject(Project* project)
{
  int id = project->getId();
  bool success = projectStorageAccess->deleteProjectFromStorage(project);
  if(success == true) {
    projectUpdateInterfaceControl->projectDeleted(id);
  }
  return success;
}
