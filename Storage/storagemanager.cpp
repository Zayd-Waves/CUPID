#include "storagemanager.h"
#include "Database/dataqueryfailedexception.h"
#include <QDebug>

StorageManager::StorageManager()
{
  if (!loadState()) {
    throw new InitiatingStorageFailedException();
  }
}

Student* StorageManager::retrieveStudent(QString email)
{
  foreach (Student* stu, students) {
    if (stu->getEmail() == email) {
      return stu;
    }
  }

  return NULL;
}

QList<Student*> StorageManager::retrieveAllStudents()
{
  return students;
}

Administrator* StorageManager::retrieveAdministrator(QString email)
{
  foreach (Administrator* admin, administrators) {
    if (admin->getEmail() == email) {
      return admin;
    }
  }

  return NULL;
}

QList<Project*> StorageManager::retrieveAllProjects()
{
  return projects;
}

Project* StorageManager::retrieveProject(int id)
{
  foreach (Project* proj, projects) {
    if (proj->getId() == id) {
      return proj;
    }
  }

  return NULL;
}

bool StorageManager::storeRegistration(Registration* registration)
{
  Student* s = registration->getStudent();
  Project* p = registration->getProject();
  s->addRegistration(registration);
  p->addRegistration(registration);

  try {
    return db.storeRegistration(registration);
  } catch (DataQueryFailedException e) {
    qDebug() << "Storing registration has failed.";
    return false;
  }
}

bool StorageManager::storeStudent(Student* student)
{
  bool completeSuccess;
  Profile* profile = student->getProfile();

  /* store the profile */
  completeSuccess = db.storeProfile(profile);

  /* store the questionnaire answers */
  foreach (QuestionnaireAnswer* qa, profile->getAllAnswers()) {
    bool success = db.storeQuestionnaireAnswer(qa);
    completeSuccess = completeSuccess ? success : false;
  }

  bool success = db.storeStudent(student);
  return completeSuccess ? success : false;
}

bool StorageManager::storeAdministrator(Administrator* administrator)
{
  if (!db.storeAlgorithmConfiguration(administrator->getAlgorithmConfiguration())) {
    qDebug() << "Storing AlgorithmConfiguration failed.";
    return false;
  }
  return db.storeAdministrator(administrator);
}

bool StorageManager::storeProject(Project* project)
{
  return db.storeProject(project);
}

bool StorageManager::deleteProject(Project* project)
{
  // remove project's registrations from students and from database
  QList<Registration*> registrations = project->getAllRegistrations();
  foreach (Registration* r, registrations) {
    r->getStudent()->removeRegistration(r);
    db.deleteRegistration(r);
    delete r;
  }
  // delete project itself
  if (db.deleteProject(project)) {
    delete project;
    return true;
  }
  return false;
}

bool StorageManager::deleteRegistration(Registration* registration)
{
  // remove registration from student
  Student* s = registration->getStudent();
  if (s) {
    s->removeRegistration(registration);
  }

  // remove registration from project
  Project* p = registration->getProject();
  if (p) {
    p->removeRegistration(registration);
  }

  if (db.deleteRegistration(registration)) {
    delete registration;
    return true;
  }
  return false;
}


bool StorageManager::loadState()
{
  /* Administrators & AlgorithmConfigurations */
  administrators = db.retrieveAllAdministrators();
  QList<Administrator*>::iterator adminIter;
  for (adminIter = administrators.begin(); adminIter != administrators.end(); ++adminIter) {
    AlgorithmConfiguration* ac = db.retrieveAlgorithmConfiguration(
          (*adminIter)->getAlgorithmConfigurationId());
    (*adminIter)->setAlgorithmConfiguration(ac);
  }

  /* Students, Profiles & QuestionnaireAnswers */
  students = db.retrieveAllStudents();
  QList<Student*>::iterator stuIter;
  for (stuIter = students.begin(); stuIter != students.end(); ++stuIter) {
    Profile* profile = loadProfile((*stuIter)->getProfileId());
    (*stuIter)->setProfile(profile);
  }

  /* Projects & Registrations */
  projects = db.retrieveAllProjects();

  /* add registrations to students and projects */
  QList<Registration*> registrations = db.retrieveAllRegistrations();
  QMap<int, QList<Registration*> > studentRegistrations;
  QMap<int, QList<Registration*> > projectRegistrations;

  foreach (Registration* reg, registrations) {
    studentRegistrations[reg->getStudentId()].append(reg);
    projectRegistrations[reg->getProjectId()].append(reg);
  }

  foreach (Student* stu, students) {
    addRegistrationsToStudent(stu, studentRegistrations[stu->getId()]);
  }

  foreach (Project* pro, projects) {
    addRegistrationsToProject(pro, projectRegistrations[pro->getId()]);
  }

  return true;
}

Profile* StorageManager::loadProfile(int id)
{
  Profile* profile = db.retrieveProfile(id);
  profile->addAllAnswers(db.retrieveProfileQuestionnaireAnswers(id));
  return profile;
}

void StorageManager::addRegistrationsToStudent(Student* student,
                                               QList<Registration*> registrations)
{
  Registration* reg;
  foreach (reg, registrations) {
    student->addRegistration(reg);
    reg->setStudent(student);
  }
}

void StorageManager::addRegistrationsToProject(Project* project,
                                               QList<Registration*> registrations)
{
  Registration* reg;
  foreach (reg, registrations) {
    project->addRegistration(reg);
    reg->setProject(project);
  }
}
