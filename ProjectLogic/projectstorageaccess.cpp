#include "projectstorageaccess.h"

ProjectStorageAccess::ProjectStorageAccess(StorageManager* storageManager)
{
  this->storageManager = storageManager;
}


Project* ProjectStorageAccess::retrieveProjectFromStorage(int id)
{
    return storageManager->retrieveProject(id);
}


QList<Project*> ProjectStorageAccess::retrieveAllProjectsFromStorage()
{
  return storageManager->retrieveAllProjects();
}

bool ProjectStorageAccess::storeProjectIntoStorage(Project* project)
{
  return storageManager->storeProject(project);
}


bool ProjectStorageAccess::updateProjectToStorage(Project* p)
{
    return storageManager->storeProject(p);
}


bool ProjectStorageAccess::deleteProjectFromStorage(Project* p)
{
    return storageManager->deleteProject(p);
}



bool ProjectStorageAccess::addRegistrationToStorage(Registration* r)
{
    return storageManager->storeRegistration(r);
}



bool ProjectStorageAccess::removeRegistrationFromStorage(Registration* r)
{
    return storageManager->deleteRegistration(r);
}
