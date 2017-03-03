#include "studentauthenticationcontrol.h"

StudentAuthenticationControl::StudentAuthenticationControl(StudentStorageAccess* ssa,
                                                           StudentUpdateInterfaceControl* suic)
{
    studentStorageAccessor = ssa;
    studentUpdateInterfaceControl = suic;

}

StudentAuthenticationControl::~StudentAuthenticationControl()
{
    delete studentStorageAccessor;
    delete studentUpdateInterfaceControl;
}

Student* StudentAuthenticationControl::verifyStudent(QString email)
{
    student = studentStorageAccessor->getStudentByEmail(email);
    studentUpdateInterfaceControl->setStudent(student);
    return student;
}

void StudentAuthenticationControl::displayStudentWindow()
{
    studentUpdateInterfaceControl->showProjectList();
}
