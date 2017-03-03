#include <QDebug>
#include <QSqlError>

#include "databasemanager.h"
#include "connectionfailedexception.h"
#include "dataqueryfailedexception.h"


DatabaseManager::DatabaseManager()
{
  // Unless we successfully connect the object is not useable
  // therefore, it should not exist, so make the constructor fail.
  try {
    connect();
  } catch (ConnectionFailedException& e) {
    throw e;
  }

  studentData = new StudentData();
  profileData = new ProfileData();
  questionnaireAnswerData = new QuestionnaireAnswerData();
  projectData = new ProjectData();
  administratorData = new AdministratorData();
  algorithmConfigurationData = new AlgorithmConfigurationData();
  registrationData = new RegistrationData();
}

DatabaseManager::~DatabaseManager()
{
  if (db.isOpen()) {
    db.close();
  }

  delete studentData;
  delete profileData;
  delete questionnaireAnswerData;
  delete projectData;
  delete administratorData;
  delete algorithmConfigurationData;
  delete registrationData;
}

bool DatabaseManager::storeStudent(Student* student)
{
  if (recordExists("student", student->getId())) {
    try {
      return studentData->updateStudent(student);
    } catch (DataQueryFailedException& e) {
      throw e;
    }
  } else {
    try {
      return studentData->insertStudent(student);
    } catch (DataQueryFailedException& e) {
      throw e;
    }
  }
}

Student* DatabaseManager::retrieveStudent(int id)
{
  try {
    return studentData->retrieveStudent(id);
  } catch (DataQueryFailedException& e) {
    throw e;
  }
}

QList<Student*> DatabaseManager::retrieveAllStudents()
{
  try {
    return studentData->retrieveAllStudents();
  } catch (DataQueryFailedException& e) {
    throw e;
  }
}

bool DatabaseManager::storeProfile(Profile* profile)
{
  if (recordExists("profile", profile->getId())) {
    try {
      return profileData->updateProfile(profile);
    } catch (DataQueryFailedException& e) {
      throw e;
    }
  } else {
    try {
      return profileData->insertProfile(profile);
    } catch (DataQueryFailedException& e) {
      throw e;
    }
  }
}

Profile* DatabaseManager::retrieveProfile(int id)
{
  try {
    return profileData->retrieveProfile(id);
  } catch (DataQueryFailedException& e) {
    throw e;
  }
}

QList<Profile*> DatabaseManager::retrieveAllProfiles()
{
  try {
    return profileData->retrieveAllProfiles();
  } catch (DataQueryFailedException& e) {
    throw e;
  }
}

bool DatabaseManager::storeQuestionnaireAnswer(QuestionnaireAnswer* qa)
{
  if (recordExists("questionnaireAnswer", qa->getId())) {
    try {
      return questionnaireAnswerData->updateQuestionnaireAnswer(qa);
    } catch (DataQueryFailedException& e) {
      throw e;
    }
  } else {
    try {
      return questionnaireAnswerData->insertQuestionnaireAnswer(qa);
    } catch (DataQueryFailedException& e) {
      throw e;
    }
  }
}

QuestionnaireAnswer* DatabaseManager::retrieveQuestionnaireAnswer(int id)
{
  try {
    return questionnaireAnswerData->retrieveQuestionnaireAnswer(id);
  } catch (DataQueryFailedException& e) {
    throw e;
  }
}

QList<QuestionnaireAnswer*> DatabaseManager::retrieveAllQuestionnaireAnswers()
{
  try {
    return questionnaireAnswerData->retrieveAllQuestionnaireAnswers();
  } catch (DataQueryFailedException& e) {
    throw e;
  }
}

QList<QuestionnaireAnswer*> DatabaseManager::retrieveProfileQuestionnaireAnswers(int profileId)
{
  try {
    return questionnaireAnswerData->retrieveProfileQuestionnaireAnswers(profileId);
  } catch (DataQueryFailedException& e) {
    throw e;
  }
}

bool DatabaseManager::storeProject(Project* project)
{
  if (recordExists("project", project->getId())) {
    try {
      return projectData->updateProject(project);
    } catch (DataQueryFailedException& e) {
      throw e;
    }
  } else {
    try {
      return projectData->insertProject(project);
    } catch (DataQueryFailedException& e) {
      throw e;
    }
  }
}

bool DatabaseManager::deleteProject(Project* project)
{
  try {
    return projectData->deleteProject(project);
  } catch (DataQueryFailedException& e) {
    throw e;
  }
}

Project* DatabaseManager::retrieveProject(int id)
{
  try {
    return projectData->retrieveProject(id);
  } catch (DataQueryFailedException& e) {
    throw e;
  }
}

QList<Project*> DatabaseManager::retrieveAllProjects()
{
  try {
    return projectData->retrieveAllProjects();
  } catch (DataQueryFailedException& e) {
    throw e;
  }
}

bool DatabaseManager::storeAdministrator(Administrator* administrator)
{
  if (recordExists("administrator", administrator->getId())) {
    try {
      return administratorData->updateAdministrator(administrator);
    } catch (DataQueryFailedException& e) {
      throw e;
    }
  } else {
    try {
      return administratorData->insertAdministrator(administrator);
    } catch (DataQueryFailedException& e) {
      throw e;
    }
  }
}

Administrator* DatabaseManager::retrieveAdministrator(int id)
{
  try {
    return administratorData->retrieveAdministrator(id);
  } catch (DataQueryFailedException& e) {
    throw e;
  }
}

QList<Administrator*> DatabaseManager::retrieveAllAdministrators()
{
  try {
    return administratorData->retrieveAllAdministrators();
  } catch (DataQueryFailedException& e) {
    throw e;
  }
}

bool DatabaseManager::storeAlgorithmConfiguration(AlgorithmConfiguration* ac)
{
  if (recordExists("algorithmConfig", ac->getId())) {
    try {
      return algorithmConfigurationData->updateAlgorithmConfiguration(ac);
    } catch (DataQueryFailedException& e) {
      throw e;
    }
  } else {
    try {
      return algorithmConfigurationData->insertAlgorithmConfiguration(ac);
    } catch (DataQueryFailedException& e) {
      throw e;
    }
  }
}

AlgorithmConfiguration* DatabaseManager::retrieveAlgorithmConfiguration(int id)
{
  try {
    return algorithmConfigurationData->retrieveAlgorithmConfiguration(id);
  } catch (DataQueryFailedException& e) {
    throw e;
  }
}

QList<AlgorithmConfiguration*> DatabaseManager::retrieveAllAlgorithmConfigurations()
{
  try {
    return algorithmConfigurationData->retrieveAllAlgorithmConfigurations();
  } catch (DataQueryFailedException& e) {
    throw e;
  }
}

bool DatabaseManager::storeRegistration(Registration* registration)
{
  if (recordExists("registration", registration->getId())) {
    try {
      return registrationData->updateRegistration(registration);
    } catch (DataQueryFailedException& e) {
      throw e;
    }
  } else {
    try {
      return registrationData->insertRegistration(registration);
    } catch (DataQueryFailedException& e) {
      throw e;
    }
  }
}

bool DatabaseManager::deleteRegistration(Registration* registration)
{
  try {
    return registrationData->deleteRegistration(registration);
  } catch (DataQueryFailedException& e) {
    throw e;
  }
}

Registration*DatabaseManager::retrieveRegistration(int id)
{
  try {
    return registrationData->retrieveRegistration(id);
  } catch (DataQueryFailedException& e) {
    throw e;
  }
}

QList<Registration*> DatabaseManager::retrieveAllRegistrations()
{
  try {
    return registrationData->retrieveAllRegistrations();
  } catch (DataQueryFailedException& e) {
    throw e;
  }
}

bool DatabaseManager::connect()
{
  if (db.open()) {
    return true;
  }

  db = QSqlDatabase::addDatabase("QSQLITE");
  db.setDatabaseName("./storage.db");

  if (!db.open()) {
    qDebug() << "Unable to open database connection!";
    throw new ConnectionFailedException();
    return false;
  }
  return true;
}

bool DatabaseManager::recordExists(const QString& table, int id)
{
  QSqlQuery query;
  query.prepare(
        QString("SELECT id FROM %1 WHERE id=%2")
        .arg(table)
        .arg(id));
  bool result = query.exec();

  if (!result) {
    qDebug() << "Query" << query.executedQuery() << "failed: " << query.lastError();
    throw new DataQueryFailedException();
  }

  bool exists = query.next();
  query.finish();
  return exists;
}

