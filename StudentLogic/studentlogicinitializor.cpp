#include "studentlogicinitializor.h"

StudentLogicInitializor::StudentLogicInitializor()
{
  studentUpdateInterfaceControl = NULL;
  studentUserInputControl = NULL;
}

StudentLogicInitializor::~StudentLogicInitializor()
{
  if (studentUpdateInterfaceControl) {
    delete studentUpdateInterfaceControl;
  }
}

void StudentLogicInitializor::initialize(StorageManager* storageManager,
                                         StudentInputManager* studentInputManager,
                                         StudentOutputManager* studentOutputManager,
                                         AuthenticationDialog* authDialog)
{
  studentUpdateInterfaceControl = new StudentUpdateInterfaceControl(studentOutputManager);
  StudentStorageAccess* studentStorageAccess = new StudentStorageAccess(storageManager);

  StudentAuthenticationControl* studentAuthenticationControl = new StudentAuthenticationControl(studentStorageAccess,
                                                                                                studentUpdateInterfaceControl);
  ProfileControl* profileControl = new ProfileControl(studentStorageAccess, studentUpdateInterfaceControl);

  studentUserInputControl = new StudentUserInputControl(authDialog,
                                                        studentInputManager,
                                                        studentAuthenticationControl,
                                                        profileControl);
}
