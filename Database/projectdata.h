#ifndef PROJECTDATA_H
#define PROJECTDATA_H

#include<QList>

#include "Storage/project.h"

class ProjectData
{
  public:
    ProjectData();
    bool updateProject(Project* project);
    bool insertProject(Project* project);
    bool deleteProject(Project* project);
    Project* retrieveProject(int id);
    QList<Project*> retrieveAllProjects();
};

#endif // PROJECTDATA_H
