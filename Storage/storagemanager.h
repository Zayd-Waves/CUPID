#ifndef STORAGEMANAGER_H
#define STORAGEMANAGER_H

#include "Database/databasemanager.h"
#include "student.h"
#include "profile.h"
#include "questionnaireanswer.h"
#include "project.h"
#include "registration.h"
#include "administrator.h"
#include "algorithmconfiguration.h"

#include <QException>
#include <QList>
#include <QString>

class StorageManager
{
  public:
    StorageManager();

    Student* retrieveStudent(QString email);
    QList<Student*> retrieveAllStudents(); /* added for algorithm */
    Administrator* retrieveAdministrator(QString email);
    QList<Project*> retrieveAllProjects();
    Project* retrieveProject(int id);

    bool storeRegistration(Registration* registration); /* NEW FUNCTION not on Diagram */
    bool storeStudent(Student* student);
    bool storeAdministrator(Administrator* administrator);
    bool storeProject(Project* project);

    bool deleteProject(Project* project);
    bool deleteRegistration(Registration* registration);

  private:
    DatabaseManager db;
    QList<Student*> students;
    QList<Administrator*> administrators;
    QList<Project*> projects;

    bool loadState();
    Profile* loadProfile(int id);
    void addRegistrationsToStudent(Student* student,
                          QList<Registration*> registrations);
    void addRegistrationsToProject(Project* project,
                          QList<Registration*> registrations);
};

class InitiatingStorageFailedException : public QException
{
    void raise() const {
      throw *this;
    }
    InitiatingStorageFailedException *clone() const {
      return new InitiatingStorageFailedException(*this);
    }
};

#endif // STORAGEMANAGER_H
