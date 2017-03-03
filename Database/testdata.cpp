#include "testdata.h"

#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QFile>
#include <QDebug>
#include <QStringList>

#include "dataqueryfailedexception.h"

TestData::TestData()
{}

void TestData::dropTables()
{
  qDebug() << "Dropping tables";

  QSqlQuery query;
  bool result = query.exec("DROP TABLE student;");
  result = query.exec("DROP TABLE profile;");
  result = query.exec("DROP TABLE project;");
  result = query.exec("DROP TABLE registration;");
  result = query.exec("DROP TABLE administrator;");
  result = query.exec("DROP TABLE algorithmConfig;");
  result = query.exec("DROP TABLE questionnaireAnswer;");

  if (!result) {
    qDebug() << "Query" << query.executedQuery() << "failed: " << query.lastError();
  }
}

void TestData::createTables()
{
  qDebug() << "Reading schema file";

  QFile file("./database-schema.sql");
  if(!file.open(QIODevice::ReadOnly)) {
    qDebug() << "Could not read schema file" << file.errorString();
    return;
  }

  QByteArray byteArr = file.readAll();
  file.close();

  if (byteArr.isEmpty()) {
    qDebug() << "Table schema file could not be read (database-schema.sql)";
    return;
  }

  qDebug() << "Creating database schema";
  QSqlQuery query;
  QStringList scriptQueries = QString(byteArr).split(';');

  foreach (QString queryTxt, scriptQueries)
  {
    if (queryTxt.trimmed().isEmpty()) {
      continue;
    }
    if (!query.exec(queryTxt))
    {
      qDebug() << "Query failed:" << query.lastError();
    }
    query.finish();
  }
}

void TestData::generate()
{
  qDebug() << "Generating test data";

  addAdministrators();
  addAlgorithmConfigurations();
  addStudents();
  addProfiles();
  addQuestionnaireAnswers();
  addProjects();
  addRegistrations();

  qDebug() << "Test data generated.";
}

void TestData::addAdministrators()
{
  qDebug() << "  > Administrators";
  db.storeAdministrator(new Administrator("mick.jagger@carleton.ca", "Mick", "Jagger", 1));
  db.storeAdministrator(new Administrator("bob.marley@carleton.ca", "Bob", "Marley", 2));
  db.storeAdministrator(new Administrator("janis.joplin@carleton.ca", "Janis", "Joplin", 3));
}

void TestData::addAlgorithmConfigurations()
{
  qDebug() << "  > Algorithm Configurations...";
  db.storeAlgorithmConfiguration(new AlgorithmConfiguration(1, 5));
  db.storeAlgorithmConfiguration(new AlgorithmConfiguration(2, 4));
  db.storeAlgorithmConfiguration(new AlgorithmConfiguration(3, 2));
}

void TestData::addStudents()
{
  qDebug() << "  > Students...";

  db.storeStudent(new Student(1, 100000001, "johnny.cash@carleton.ca", "Johnny", "Cash"));
  db.storeStudent(new Student(2, 100485245, "jay.farrar@carleton.ca", "Jay", "Farrar"));
  db.storeStudent(new Student(3, 100055861, "june.carter@carleton.ca", "June", "Carter"));
  db.storeStudent(new Student(4, 100654987, "joe.pug@carleton.ca", "Joe", "Pug"));
  db.storeStudent(new Student(5, 100685483, "ben.gibbard@carleton.ca", "Ben", "Gibbard"));
  db.storeStudent(new Student(6, 100685483, "leslie.feist@carleton.ca", "Leslie", "Feist"));
  db.storeStudent(new Student(7, 1, 100852844, "townes.vanzandt@carleton.ca", "Townes", "Van Zandt"));
  db.storeStudent(new Student(8, 100851586, "justin.earle@carleton.ca", "Justin", "Earle"));
  db.storeStudent(new Student(9, 100685875, "ani.difranco@carleton.ca", "Ani", "DiFranco"));
  db.storeStudent(new Student(10, 100685955, "alison.krauss@carleton.ca", "Alison", "Krauss"));
  db.storeStudent(new Student(11, 100852481, "orland.bloom@carleton.ca", "Orlando", "Bloom"));
  db.storeStudent(new Student(12, 101568135, "johnny.depp@carleton.ca", "Johnny", "Depp"));
  db.storeStudent(new Student(13, 101568135, "reynaldo.hancock@carleton.ca", "Reynaldo", "Hancock"));
  db.storeStudent(new Student(14, 101684315, "peter.parker@carleton.ca", "Peter", "Parker"));
  db.storeStudent(new Student(15, 100864132, "taylor.swift@carleton.ca", "Taylor", "Swift"));
  db.storeStudent(new Student(16, 100684513, "wesley.snipes@carleton.ca", "Wesley", "Snipes"));
  db.storeStudent(new Student(17, 100568415, "carl.masters@carleton.ca", "Carl", "Masters"));
  db.storeStudent(new Student(18, 100684165, "maria.diangelo@carleton.ca", "Maria", "DiAngelo"));
  db.storeStudent(new Student(19, 100984646, "carina.camaro@carleton.ca", "Carina", "Camaro"));
  db.storeStudent(new Student(20, 101598138, "mike.mustang@carleton.ca", "Mike", "Mustang"));
  db.storeStudent(new Student(21, 100685434, "miguel.ramirez@carleton.ca", "Miguel", "Ramirez"));
  db.storeStudent(new Student(22, 100984885, "charlie.brown@carleton.ca", "Charlie", "Brown"));
  db.storeStudent(new Student(23, 100994852, "charlize.therone@carleton.ca", "Charlize", "Therone"));
  db.storeStudent(new Student(24, 100558845, "barry.brown@carleton.ca", "Barry", "Brown"));
  db.storeStudent(new Student(25, 101898465, "rick.grimes@carleton.ca", "Rick", "Grimes"));
  db.storeStudent(new Student(26, 100654684, "michele.marcato@carleton.ca", "Michele", "Marcato"));
  db.storeStudent(new Student(27, 101666888, "terry.fletcher@carleton.ca", "Terry", "Fletcher"));
  db.storeStudent(new Student(28, 100558452, "marc.longe@carleton.ca", "Marc", "Longe"));
  db.storeStudent(new Student(29, 100668845, "francois.boulangerie@carleton.ca", "Francois", "Boulangerie"));
  db.storeStudent(new Student(30, 100688454, "freddy.bakery@carleton.ca", "Freddy", "Bakery"));
}

void TestData::addProfiles()
{
  qDebug() << "  > Profiles...";

  for (int i = 0; i < 30; ++i) {
    db.storeProfile(new Profile());
  }
}

void TestData::addQuestionnaireAnswers()
{
  qDebug() << "  > Questionnaire Answers...";

  // random seed
  srand (time(NULL));

  QList<Profile*> profiles = db.retrieveAllProfiles();
  QList<Profile*>::const_iterator profileIter;

  // generate random answers for each student profile
  for (profileIter = profiles.begin(); profileIter != profiles.end(); ++profileIter) {
    for (int i = 0; i < 17; ++i) {
      bool ownAnswers[4];
      ownAnswers[0] = randomBool();
      ownAnswers[1] = randomBool();
      ownAnswers[2] = randomBool();
      ownAnswers[3] = randomBool();

      if (!ownAnswers[0] && !ownAnswers[1] && !ownAnswers[2] && !ownAnswers[3]) {
        int pos = rand() % 4;
        ownAnswers[pos] = true;
      }

      bool groupAnswers[4];
      groupAnswers[0] = randomBool();
      groupAnswers[1] = randomBool();
      groupAnswers[2] = randomBool();
      groupAnswers[3] = randomBool();

      if (!groupAnswers[0] && !groupAnswers[1] && !groupAnswers[2] && !groupAnswers[3]) {
        int pos = rand() % 4;
        groupAnswers[pos] = true;
      }

      db.storeQuestionnaireAnswer(new QuestionnaireAnswer((*profileIter)->getId(), i + 1,
                      ownAnswers[0], ownAnswers[1], ownAnswers[2], ownAnswers[3],
                      groupAnswers[0], groupAnswers[1], groupAnswers[2], groupAnswers[3]));
    }
  }
}

void TestData::addProjects()
{
  qDebug() << "  > Projects...";

  db.storeProject(new Project("Term Project", "COMP3004", "Term project for Fall 2015", 54));
  db.storeProject(new Project("Final Project", "COMP3000", "The final project in 2015", 25));
  db.storeProject(new Project("Extra Project", "COMP2404", "Project to gain extra marks", 20));
  db.storeProject(new Project("The Project", "COMP2401", "C project", 50));
  db.storeProject(new Project("Grand Project", "COMP3666", "Risking it all on this", 20));
  db.storeProject(new Project("Honours Project", "COMP4900", "It's the big one, folks", 500));
  db.storeProject(new Project("Weekly project", "COMP3400", "Linux kernel memory project", 40));
}

void TestData::addRegistrations()
{
  qDebug() << "  > Registrations...";

  db.storeRegistration(new Registration(1, 1));
  db.storeRegistration(new Registration(1, 5));

  db.storeRegistration(new Registration(2, 0));
  db.storeRegistration(new Registration(2, 1));

  db.storeRegistration(new Registration(3, 1));
  db.storeRegistration(new Registration(3, 2));
  db.storeRegistration(new Registration(3, 4));

  db.storeRegistration(new Registration(4, 3));
  db.storeRegistration(new Registration(4, 4));

  db.storeRegistration(new Registration(4, 5));
  db.storeRegistration(new Registration(4, 6));

  db.storeRegistration(new Registration(5, 1));
  db.storeRegistration(new Registration(5, 3));
  db.storeRegistration(new Registration(5, 6));

  db.storeRegistration(new Registration(6, 1));
  db.storeRegistration(new Registration(6, 3));
  db.storeRegistration(new Registration(6, 4));

  db.storeRegistration(new Registration(7, 1));
  db.storeRegistration(new Registration(7, 2));

  db.storeRegistration(new Registration(8, 1));
  db.storeRegistration(new Registration(8, 4));

  db.storeRegistration(new Registration(9, 1));
  db.storeRegistration(new Registration(9, 3));
  db.storeRegistration(new Registration(9, 4));

  db.storeRegistration(new Registration(10, 1));
  db.storeRegistration(new Registration(10, 2));

  db.storeRegistration(new Registration(11, 2));
  db.storeRegistration(new Registration(11, 4));
  db.storeRegistration(new Registration(11, 5));

  db.storeRegistration(new Registration(12, 6));

  db.storeRegistration(new Registration(13, 0));
  db.storeRegistration(new Registration(13, 1));
  db.storeRegistration(new Registration(13, 3));
  db.storeRegistration(new Registration(13, 5));

  db.storeRegistration(new Registration(14, 1));
  db.storeRegistration(new Registration(14, 5));

  db.storeRegistration(new Registration(15, 0));
  db.storeRegistration(new Registration(15, 1));

  db.storeRegistration(new Registration(16, 1));
  db.storeRegistration(new Registration(16, 2));
  db.storeRegistration(new Registration(16, 4));

  db.storeRegistration(new Registration(17, 3));
  db.storeRegistration(new Registration(17, 4));
  db.storeRegistration(new Registration(17, 5));

  db.storeRegistration(new Registration(18, 1));
  db.storeRegistration(new Registration(18, 2));

  db.storeRegistration(new Registration(18, 4));
  db.storeRegistration(new Registration(18, 5));
  db.storeRegistration(new Registration(18, 6));

  db.storeRegistration(new Registration(19, 1));
  db.storeRegistration(new Registration(19, 3));
  db.storeRegistration(new Registration(19, 4));
  db.storeRegistration(new Registration(19, 5));

  db.storeRegistration(new Registration(20, 2));

  db.storeRegistration(new Registration(21, 4));

  db.storeRegistration(new Registration(22, 3));
  db.storeRegistration(new Registration(22, 4));
  db.storeRegistration(new Registration(22, 6));

  db.storeRegistration(new Registration(23, 1));
  db.storeRegistration(new Registration(23, 2));
  db.storeRegistration(new Registration(23, 4));

  db.storeRegistration(new Registration(24, 2));
  db.storeRegistration(new Registration(24, 4));
  db.storeRegistration(new Registration(24, 5));

  db.storeRegistration(new Registration(25, 6));

  db.storeRegistration(new Registration(26, 1));
  db.storeRegistration(new Registration(26, 3));
  db.storeRegistration(new Registration(26, 4));

  db.storeRegistration(new Registration(27, 2));

  db.storeRegistration(new Registration(28, 1));
  db.storeRegistration(new Registration(28, 2));
  db.storeRegistration(new Registration(28, 4));
  db.storeRegistration(new Registration(28, 5));

  db.storeRegistration(new Registration(29, 6));

  db.storeRegistration(new Registration(30, 1));
  db.storeRegistration(new Registration(30, 3));
  db.storeRegistration(new Registration(30, 4));
  db.storeRegistration(new Registration(30, 6));
}

bool TestData::randomBool()
{
  return rand() % 2 == 1;
}
