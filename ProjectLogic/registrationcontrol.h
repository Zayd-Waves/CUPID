#ifndef REGISTRATIONCONTROL_H
#define REGISTRATIONCONTROL_H
#include <QObject>
#include <QString>
#include "projectcontrol.h"
#include "projectstorageaccess.h"

class RegistrationControl
{
  public:
    RegistrationControl(ProjectStorageAccess* projectStorageAccess,
                        ProjectUpdateInterfaceControl* projectUpdateInterfaceControl);
    QList<Registration*> list();
    bool addRegistration(Project*, Student*);
    bool removeRegistration(Registration*);

  private:
    ProjectStorageAccess* projectStorageAccess;
    ProjectUpdateInterfaceControl* projectUpdateInterfaceControl;
};

#endif // REGISTRATIONCONTROL_H
