#ifndef DATABASETESTS_H
#define DATABASETESTS_H

#include "databasemanager.h"

class DatabaseTests
{
  public:
    DatabaseTests();
    bool run();

  private:
    DatabaseManager db;
    bool testStudent();
    bool testProfile();
    bool testQuestionnaireAnswer();
    bool testProject();
    bool testAdministrator();
    bool testAlgorithmConfiguration();
    bool testRegistration();
};

#endif // DATABASETESTS_H
