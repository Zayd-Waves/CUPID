#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QException>
#include <QString>
#include <QList>

#include "Storage/student.h"
#include "Storage/profile.h"
#include "Storage/questionnaireanswer.h"
#include "Storage/project.h"
#include "Storage/administrator.h"
#include "Storage/algorithmconfiguration.h"
#include "Storage/registration.h"

#include "studentdata.h"
#include "profiledata.h"
#include "questionnaireanswerdata.h"
#include "projectdata.h"
#include "administratordata.h"
#include "algorithmconfigurationdata.h"
#include "registrationdata.h"


class DatabaseManager
{
  public:
    DatabaseManager();
    ~DatabaseManager();

    /* Students */
    bool storeStudent(Student* student);
    Student* retrieveStudent(int id);
    QList<Student*> retrieveAllStudents();

    /* Profiles */
    bool storeProfile(Profile* profile);
    Profile* retrieveProfile(int id);
    QList<Profile*> retrieveAllProfiles();

    /* QuestionnaireAnswers */
    bool storeQuestionnaireAnswer(QuestionnaireAnswer* qa);
    QuestionnaireAnswer* retrieveQuestionnaireAnswer(int id);
    QList<QuestionnaireAnswer*> retrieveAllQuestionnaireAnswers();
    QList<QuestionnaireAnswer*> retrieveProfileQuestionnaireAnswers(int profileId);

    /* Projects */
    bool storeProject(Project* project);
    bool deleteProject(Project* project);
    Project* retrieveProject(int id);
    QList<Project*> retrieveAllProjects();

    /* Administrator */
    bool storeAdministrator(Administrator* administrator);
    Administrator* retrieveAdministrator(int id);
    QList<Administrator*> retrieveAllAdministrators();

    /* AlgorithmConfiguration */
    bool storeAlgorithmConfiguration(AlgorithmConfiguration* ac);
    AlgorithmConfiguration* retrieveAlgorithmConfiguration(int id);
    QList<AlgorithmConfiguration*> retrieveAllAlgorithmConfigurations();

    /* Registration */
    bool storeRegistration(Registration* registration);
    bool deleteRegistration(Registration* registration);
    Registration* retrieveRegistration(int id);
    QList<Registration*> retrieveAllRegistrations();


  private:
    QSqlDatabase db;

    StudentData* studentData;
    ProfileData* profileData;
    QuestionnaireAnswerData* questionnaireAnswerData;
    ProjectData* projectData;
    AdministratorData* administratorData;
    AlgorithmConfigurationData* algorithmConfigurationData;
    RegistrationData* registrationData;

    bool connect();
    bool recordExists(const QString& table, int id);
};

#endif // DATABASEMANAGER_H
