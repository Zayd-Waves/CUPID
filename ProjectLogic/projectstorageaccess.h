#ifndef PROJECTSTORAGEACCESS_H
#define PROJECTSTORAGEACCESS_H
#include "Storage/project.h"
#include "Storage/registerable.h"
#include "Storage/registration.h"
#include "Storage/storagemanager.h"
#include <QObject>
#include <QList>

class ProjectStorageAccess
{

  public:
    ProjectStorageAccess(StorageManager* storageManager);
    Project* retrieveProjectFromStorage(int id);
    QList<Project*> retrieveAllProjectsFromStorage();
    bool storeProjectIntoStorage(Project*);
    bool updateProjectToStorage(Project*);
    bool deleteProjectFromStorage(Project*);
    bool addRegistrationToStorage(Registration*);
    bool removeRegistrationFromStorage(Registration*);

  private:
    StorageManager* storageManager;

};

#endif // PROJECTSTORAGEACCESS_H
