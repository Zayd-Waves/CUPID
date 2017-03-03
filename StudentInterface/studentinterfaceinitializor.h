#ifndef STUDENTINTERFACEINITIALIZOR_H
#define STUDENTINTERFACEINITIALIZOR_H

#include "studentinputmanager.h"
#include "studentoutputmanager.h"
#include "studentprojectlistwindow.h"
#include "profiledetailsform.h"

class StudentInterfaceInitializor
{
  public:
    StudentInterfaceInitializor();
    ~StudentInterfaceInitializor();
    void initialize();
    StudentInputManager* getStudentInputManager() const;
    StudentOutputManager* getStudentOutputManager() const;

  private:
    StudentInputManager* studentInputManager;
    StudentOutputManager* studentOutputManager;
};

#endif // STUDENTINTERFACEINITIALIZOR_H
