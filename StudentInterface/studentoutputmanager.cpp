#include "studentoutputmanager.h"

StudentOutputManager::StudentOutputManager(StudentProjectListWindow* studentProjectListWindow,
                                           ProfileDetailsForm* profileDetailsForm)
{
    this->studentProjectWindow = studentProjectListWindow;
    this->profileDetailsForm = profileDetailsForm;
}

StudentOutputManager::~StudentOutputManager()
{
    delete studentProjectWindow;
    delete profileDetailsForm;
}

void StudentOutputManager::setProjectList(QList<Project *> pr)
{
    projects = pr;
}

void StudentOutputManager::setStudent(Student *stud)
{
    student = stud;
}

void StudentOutputManager::displayProjectList()
{
    studentProjectWindow->display(projects);
}

void StudentOutputManager::displayProfileDetails(Student* student)
{
    profileDetailsForm->display(student);
}

void StudentOutputManager::registrationHasAdded(Registration* registration)
{
    int projectId = studentProjectWindow->getSelectedProjectId();
    foreach(Project* p, projects)
    {
        if(p->getId() == projectId)
        {
            p->addRegistration(registration);
        }
    }
    studentProjectWindow->updateRegistration(registration);
}

void StudentOutputManager::registrationHasRemoved(int projectId)
{
    studentProjectWindow->updateDeRegistration(projectId);
}
