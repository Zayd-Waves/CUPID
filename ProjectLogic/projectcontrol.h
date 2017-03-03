#ifndef PROJECTCONTROL_H
#define PROJECTCONTROL_H
#include <QObject>
#include <QList>
#include "Storage/project.h"
#include "projectstorageaccess.h"
#include "projectupdateinterfacecontrol.h"


class ProjectControl
{
  public:
    ProjectControl(ProjectStorageAccess* projectStorageAccess,
                   ProjectUpdateInterfaceControl* projectUpdateInterfaceControl);
    Project* get(int);
    QList<Project*> getAllProjects();

    bool addProject(Project*);
    bool updateProject(Project*);
    bool removeProject(Project*);


  private:
    ProjectStorageAccess* projectStorageAccess;
    ProjectUpdateInterfaceControl* projectUpdateInterfaceControl;


};

#endif // PROJECTCONTROL_H
