#ifndef PROJECTUPDATEINTERFACECONTROL_H
#define PROJECTUPDATEINTERFACECONTROL_H

#include <QDialog>
#include "AdministratorInterface/adminoutputmanager.h"
#include "StudentInterface/studentoutputmanager.h"

class ProjectUpdateInterfaceControl : public QDialog
{
    Q_OBJECT


  public:
    explicit ProjectUpdateInterfaceControl(StudentOutputManager* studentOutputManager,
                                           AdminOutputManager* adminOutputManager);
    void projectsLoaded(QList<Project*> projectList);
    void projectAdded(Project*);
    void projectUpdated(Project*);
    void projectDeleted(int projectId);
    void registrationAdded(Registration*);
    void registrationDeleted(int);

  private:
    StudentOutputManager* studentOutputManager;
    AdminOutputManager* adminOutputManager;
};
#endif // PROJECTUPDATEINTERFACECONTROL_H
