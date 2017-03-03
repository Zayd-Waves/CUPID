#ifndef TESTDATA_H
#define TESTDATA_H

#include "databasemanager.h"

class TestData
{
  public:
    TestData();
    void dropTables();
    void createTables();
    void generate();

  private:
    DatabaseManager db;
    void addAdministrators();
    void addAlgorithmConfigurations();
    void addStudents();
    void addProfiles();
    void addQuestionnaireAnswers();
    void addProjects();
    void addRegistrations();
    bool randomBool();
};

#endif // TESTDATA_H
