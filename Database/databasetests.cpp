#include <QDebug>

#include "databasetests.h"
#include "Storage/student.h"
#include "Storage/profile.h"
#include "Storage/questionnaireanswer.h"
#include "Storage/project.h"
#include "Storage/administrator.h"
#include "Storage/algorithmconfiguration.h"
#include "Storage/registration.h"

DatabaseTests::DatabaseTests()
{}

bool DatabaseTests::run()
{
  qDebug() << "\nTesting database";
  qDebug() << "   > Student..." << (testStudent() ? "pass" : "FAIL");
  qDebug() << "   > Profile..." << (testProfile() ? "pass" : "FAIL");
  qDebug() << "   > Questionnaire Answer..." << (testQuestionnaireAnswer() ? "pass" : "FAIL");
  qDebug() << "   > Project..." << (testProject() ? "pass" : "FAIL");
  qDebug() << "   > Administrator..." << (testAdministrator() ? "pass" : "FAIL");
  qDebug() << "   > AlgorithmConfiguration..." << (testAlgorithmConfiguration() ? "pass" : "FAIL");
  qDebug() << "   > Registration..." << (testRegistration() ? "pass" : "FAIL");

  return true;
}

bool DatabaseTests::testStudent()
{
  Student* s1 = new Student(1, -1, 100654987, "test1@carleton.ca", "Test1", "Person1");
  Student* s2 = new Student(2, -1, 100456123, "test2@carleton.ca", "Test2", "Person2");

  db.storeStudent(s1);
  db.storeStudent(s2);

  Student* sr1 = db.retrieveStudent(1);

  Q_ASSERT(sr1 != NULL);
  Q_ASSERT(sr1->getId() == s1->getId());
  Q_ASSERT(sr1->getProfileId() == s1->getProfileId());
  Q_ASSERT(sr1->getStudentNumber() == s1->getStudentNumber());
  Q_ASSERT(sr1->getEmail() == s1->getEmail());
  Q_ASSERT(sr1->getFirstName() == s1->getFirstName());
  Q_ASSERT(sr1->getLastName() == s1->getLastName());

  delete sr1;

  QList<Student*> sList = db.retrieveAllStudents();

  sr1 = sList.at(0);
  Q_ASSERT(sr1 != NULL);
  Q_ASSERT(sr1->getId() == s1->getId());
  Q_ASSERT(sr1->getProfileId() == s1->getProfileId());
  Q_ASSERT(sr1->getStudentNumber() == s1->getStudentNumber());
  Q_ASSERT(sr1->getEmail() == s1->getEmail());
  Q_ASSERT(sr1->getFirstName() == s1->getFirstName());
  Q_ASSERT(sr1->getLastName() == s1->getLastName());

  Student* sr2 = sList.at(1);
  Q_ASSERT(sr2 != NULL);
  Q_ASSERT(sr2->getId() == s2->getId());
  Q_ASSERT(sr2->getProfileId() == s2->getProfileId());
  Q_ASSERT(sr2->getStudentNumber() == s2->getStudentNumber());
  Q_ASSERT(sr2->getEmail() == s2->getEmail());
  Q_ASSERT(sr2->getFirstName() == s2->getFirstName());
  Q_ASSERT(sr2->getLastName() == s2->getLastName());

  delete sr1;
  delete sr2;
  delete s1;
  delete s2;

  return true;
}

bool DatabaseTests::testProfile()
{
  Profile* p1 = new Profile(1);
  Profile* p2 = new Profile(2);

  db.storeProfile(p1);
  db.storeProfile(p2);

  Profile* pr1 = db.retrieveProfile(1);

  Q_ASSERT(pr1 != NULL);
  Q_ASSERT(pr1->getId() == p1->getId());

  delete pr1;

  QList<Profile*> pList = db.retrieveAllProfiles();

  pr1 = pList.at(0);
  Q_ASSERT(pr1 != NULL);
  Q_ASSERT(pr1->getId() == p1->getId());

  Profile* pr2 = pList.at(1);
  Q_ASSERT(pr2 != NULL);
  Q_ASSERT(pr2->getId() == p2->getId());

  delete pr1;
  delete pr2;
  delete p1;
  delete p2;

  return true;
}

bool DatabaseTests::testQuestionnaireAnswer()
{
  QuestionnaireAnswer* q1 = new QuestionnaireAnswer(1, 1);
  QuestionnaireAnswer* q2 = new QuestionnaireAnswer(2, 5);

  q1->setOwnAnswer1Selected(true);
  q1->setOwnAnswer2Selected(true);
  q1->setOwnAnswer3Selected(true);
  q1->setOwnAnswer4Selected(true);
  q1->setGroupAnswer1Selected(true);
  q1->setGroupAnswer2Selected(true);
  q1->setGroupAnswer3Selected(true);
  q1->setGroupAnswer4Selected(true);

  db.storeQuestionnaireAnswer(q1);
  db.storeQuestionnaireAnswer(q2);

  QuestionnaireAnswer* qr1 = db.retrieveQuestionnaireAnswer(1);
  Q_ASSERT(qr1 != NULL);
  Q_ASSERT(qr1->getId() == q1->getId());
  Q_ASSERT(qr1->getProfileId() == q1->getProfileId());
  Q_ASSERT(qr1->getQuestionNumber() == q1->getQuestionNumber());
  Q_ASSERT(qr1->getOwnAnswer1Selected() == q1->getOwnAnswer1Selected());
  Q_ASSERT(qr1->getOwnAnswer2Selected() == q1->getOwnAnswer2Selected());
  Q_ASSERT(qr1->getOwnAnswer3Selected() == q1->getOwnAnswer3Selected());
  Q_ASSERT(qr1->getOwnAnswer4Selected() == q1->getOwnAnswer4Selected());
  Q_ASSERT(qr1->getGroupAnswer1Selected() == q1->getGroupAnswer1Selected());
  Q_ASSERT(qr1->getGroupAnswer2Selected() == q1->getGroupAnswer2Selected());
  Q_ASSERT(qr1->getGroupAnswer3Selected() == q1->getGroupAnswer3Selected());
  Q_ASSERT(qr1->getGroupAnswer4Selected() == q1->getGroupAnswer4Selected());

  delete qr1;

  QList<QuestionnaireAnswer*> qList = db.retrieveAllQuestionnaireAnswers();

  qr1 = qList.at(0);
  Q_ASSERT(qr1 != NULL);
  Q_ASSERT(qr1->getId() == q1->getId());
  Q_ASSERT(qr1->getProfileId() == q1->getProfileId());
  Q_ASSERT(qr1->getQuestionNumber() == q1->getQuestionNumber());
  Q_ASSERT(qr1->getOwnAnswer1Selected() == q1->getOwnAnswer1Selected());
  Q_ASSERT(qr1->getOwnAnswer2Selected() == q1->getOwnAnswer2Selected());
  Q_ASSERT(qr1->getOwnAnswer3Selected() == q1->getOwnAnswer3Selected());
  Q_ASSERT(qr1->getOwnAnswer4Selected() == q1->getOwnAnswer4Selected());
  Q_ASSERT(qr1->getGroupAnswer1Selected() == q1->getGroupAnswer1Selected());
  Q_ASSERT(qr1->getGroupAnswer2Selected() == q1->getGroupAnswer2Selected());
  Q_ASSERT(qr1->getGroupAnswer3Selected() == q1->getGroupAnswer3Selected());
  Q_ASSERT(qr1->getGroupAnswer4Selected() == q1->getGroupAnswer4Selected());

  QuestionnaireAnswer* qr2 = qList.at(1);
  Q_ASSERT(qr2 != NULL);
  Q_ASSERT(qr2->getId() == q2->getId());
  Q_ASSERT(qr2->getProfileId() == q2->getProfileId());
  Q_ASSERT(qr2->getQuestionNumber() == q2->getQuestionNumber());
  Q_ASSERT(qr2->getOwnAnswer1Selected() == q2->getOwnAnswer1Selected());
  Q_ASSERT(qr2->getOwnAnswer2Selected() == q2->getOwnAnswer2Selected());
  Q_ASSERT(qr2->getOwnAnswer3Selected() == q2->getOwnAnswer3Selected());
  Q_ASSERT(qr2->getOwnAnswer4Selected() == q2->getOwnAnswer4Selected());
  Q_ASSERT(qr2->getGroupAnswer1Selected() == q2->getGroupAnswer1Selected());
  Q_ASSERT(qr2->getGroupAnswer2Selected() == q2->getGroupAnswer2Selected());
  Q_ASSERT(qr2->getGroupAnswer3Selected() == q2->getGroupAnswer3Selected());
  Q_ASSERT(qr2->getGroupAnswer4Selected() == q2->getGroupAnswer4Selected());

  delete qr1;
  delete qr2;
  delete q1;
  delete q2;

  return true;
}

bool DatabaseTests::testProject()
{
  Project* p1 = new Project(1, "Test Project 1", "TEST1234", "Test description", 50);
  Project* p2 = new Project(2, "Test Project 2", "TEST4567", "Test2 description", 20);

  db.storeProject(p1);
  db.storeProject(p2);

  Project* pr1 = db.retrieveProject(1);

  Q_ASSERT(pr1 != NULL);
  Q_ASSERT(pr1->getId() == p1->getId());
  Q_ASSERT(pr1->getTitle() == p1->getTitle());
  Q_ASSERT(pr1->getCourseCode() == p1->getCourseCode());
  Q_ASSERT(pr1->getDescription() == p1->getDescription());
  Q_ASSERT(pr1->getMaxNumberOfRegistrations() == p1->getMaxNumberOfRegistrations());

  delete pr1;

  QList<Project*> pList = db.retrieveAllProjects();

  pr1 = pList.at(0);
  Q_ASSERT(pr1 != NULL);
  Q_ASSERT(pr1->getId() == p1->getId());
  Q_ASSERT(pr1->getTitle() == p1->getTitle());
  Q_ASSERT(pr1->getCourseCode() == p1->getCourseCode());
  Q_ASSERT(pr1->getDescription() == p1->getDescription());
  Q_ASSERT(pr1->getMaxNumberOfRegistrations() == p1->getMaxNumberOfRegistrations());

  int deleted = db.deleteProject(pr1);
  Q_ASSERT(deleted == 1);
  Q_ASSERT(db.retrieveProject(pr1->getId()) == NULL);
  pList = db.retrieveAllProjects();
  Q_ASSERT(pList.length() == 1);


  Project* pr2 = pList.at(0);
  Q_ASSERT(pr2 != NULL);
  Q_ASSERT(pr2->getId() == p2->getId());
  Q_ASSERT(pr2->getTitle() == p2->getTitle());
  Q_ASSERT(pr2->getCourseCode() == p2->getCourseCode());
  Q_ASSERT(pr2->getDescription() == p2->getDescription());
  Q_ASSERT(pr2->getMaxNumberOfRegistrations() == p2->getMaxNumberOfRegistrations());


  delete pr1;
  delete pr2;
  delete p1;
  delete p2;

  return true;
}

bool DatabaseTests::testAdministrator()
{
  Administrator* a1 = new Administrator(1, "admin1@carleton.ca", "Test1", "Admin", -1);
  Administrator* a2 = new Administrator(2, "admin2@carleton.ca", "Test2", "Admin", -1);

  db.storeAdministrator(a1);
  db.storeAdministrator(a2);

  Administrator* ar1 = db.retrieveAdministrator(1);

  Q_ASSERT(ar1 != NULL);
  Q_ASSERT(ar1->getId() == a1->getId());
  Q_ASSERT(ar1->getAlgorithmConfigurationId() == a1->getAlgorithmConfigurationId());
  Q_ASSERT(ar1->getEmail() == a1->getEmail());
  Q_ASSERT(ar1->getFirstName() == a1->getFirstName());
  Q_ASSERT(ar1->getLastName() == a1->getLastName());

  delete ar1;

  QList<Administrator*> aList = db.retrieveAllAdministrators();

  ar1 = aList.at(0);
  Q_ASSERT(ar1 != NULL);
  Q_ASSERT(ar1->getId() == a1->getId());
  Q_ASSERT(ar1->getAlgorithmConfigurationId() == a1->getAlgorithmConfigurationId());
  Q_ASSERT(ar1->getEmail() == a1->getEmail());
  Q_ASSERT(ar1->getFirstName() == a1->getFirstName());
  Q_ASSERT(ar1->getLastName() == a1->getLastName());

  Administrator* ar2 = aList.at(1);
  Q_ASSERT(ar2 != NULL);
  Q_ASSERT(ar2->getId() == a2->getId());
  Q_ASSERT(ar2->getAlgorithmConfigurationId() == a2->getAlgorithmConfigurationId());
  Q_ASSERT(ar2->getEmail() == a2->getEmail());
  Q_ASSERT(ar2->getFirstName() == a2->getFirstName());
  Q_ASSERT(ar2->getLastName() == a2->getLastName());

  delete ar1;
  delete ar2;
  delete a1;
  delete a2;

  return true;
}

bool DatabaseTests::testAlgorithmConfiguration()
{
  AlgorithmConfiguration* a1 = new AlgorithmConfiguration(1, 50);
  AlgorithmConfiguration* a2 = new AlgorithmConfiguration(2, 25);

  db.storeAlgorithmConfiguration(a1);
  db.storeAlgorithmConfiguration(a2);

  AlgorithmConfiguration* ar1 = db.retrieveAlgorithmConfiguration(1);

  Q_ASSERT(ar1 != NULL);
  Q_ASSERT(ar1->getId() == a1->getId());
  Q_ASSERT(ar1->getTeamSize() == a1->getTeamSize());

  delete ar1;

  QList<AlgorithmConfiguration*> aList = db.retrieveAllAlgorithmConfigurations();

  ar1 = aList.at(0);
  Q_ASSERT(ar1 != NULL);
  Q_ASSERT(ar1->getId() == a1->getId());
  Q_ASSERT(ar1->getTeamSize() == a1->getTeamSize());

  AlgorithmConfiguration* ar2 = aList.at(1);
  Q_ASSERT(ar2 != NULL);
  Q_ASSERT(ar2->getId() == a2->getId());
  Q_ASSERT(ar2->getTeamSize() == a2->getTeamSize());

  delete ar1;
  delete ar2;
  delete a1;
  delete a2;

  return true;
}

bool DatabaseTests::testRegistration()
{
  QDate d;
  Registration* r1 = new Registration(1, 15, 25, d);
  Registration* r2 = new Registration(2, 16, 26, d);

  db.storeRegistration(r1);
  db.storeRegistration(r2);

  Registration* rr1 = db.retrieveRegistration(1);

  Q_ASSERT(rr1 != NULL);
  Q_ASSERT(rr1->getId() == r1->getId());
  Q_ASSERT(rr1->getStudentId() == r1->getStudentId());
  Q_ASSERT(rr1->getProjectId() == r1->getProjectId());
  Q_ASSERT(rr1->getDate() == r1->getDate());

  delete rr1;

  QList<Registration*> rList = db.retrieveAllRegistrations();

  rr1 = rList.at(0);

  Q_ASSERT(rr1 != NULL);
  Q_ASSERT(rr1->getId() == r1->getId());
  Q_ASSERT(rr1->getStudentId() == r1->getStudentId());
  Q_ASSERT(rr1->getProjectId() == r1->getProjectId());
  Q_ASSERT(rr1->getDate() == r1->getDate());

  int deleted = db.deleteRegistration(rr1);
  Q_ASSERT(deleted == 1);
  Q_ASSERT(db.retrieveRegistration(rr1->getId()) == NULL);
  rList = db.retrieveAllRegistrations();
  Q_ASSERT(rList.length() == 1);

  Registration* rr2 =rList.at(0);
  Q_ASSERT(rr2 != NULL);
  Q_ASSERT(rr2->getId() == r2->getId());
  Q_ASSERT(rr2->getStudentId() == r2->getStudentId());
  Q_ASSERT(rr2->getProjectId() == r2->getProjectId());
  Q_ASSERT(rr2->getDate() == r2->getDate());

  delete rr1;
  delete rr2;
  delete r1;
  delete r2;

  return true;
}
