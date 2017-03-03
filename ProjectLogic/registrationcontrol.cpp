#include "registrationcontrol.h"

RegistrationControl::RegistrationControl(ProjectStorageAccess* projectStorageAccess,
                                         ProjectUpdateInterfaceControl* projectUpdateInterfaceControl)
{
  this->projectStorageAccess = projectStorageAccess;
  this->projectUpdateInterfaceControl = projectUpdateInterfaceControl;
}

bool RegistrationControl::addRegistration(Project* project, Student* student)
{
  Registration* reg = new Registration(student, project);
  bool success = projectStorageAccess->addRegistrationToStorage(reg);
  if (success == true) {
    projectUpdateInterfaceControl->registrationAdded(reg);
  }
  return success;
}


bool RegistrationControl::removeRegistration(Registration* registration)
{
  int projectId = registration->getProjectId();
  bool success = projectStorageAccess->removeRegistrationFromStorage(registration);
  if(success == true) {
    projectUpdateInterfaceControl->registrationDeleted(projectId);
  }
  return success;
}
