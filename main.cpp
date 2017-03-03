#include <QApplication>
#include <QFile>

#include "AuthenticationInterface/authenticationdialog.h"
#include "Storage/storagemanager.h"

#include "Database/testdata.h"

// Initializors
#include "AdministratorInterface/admininterfaceinitializor.h"
#include "AdministratorLogic/administratorlogicinitializor.h"
#include "StudentInterface/studentinterfaceinitializor.h"
#include "StudentLogic/studentlogicinitializor.h"
#include "ProjectLogic/projectlogicinitializor.h"
#include "StudentLogic/studentlogicinitializor.h"



int main(int argc, char *argv[])
{
  QApplication a(argc, argv);

  /* generate test data on first run */
  if (!QFile::exists("./storage.db")) {
    TestData* td = new TestData();
    td->createTables();
    td->generate();
    delete td;
  }

  /*
   * Initialize the program
   */

  StorageManager* storageManager = new StorageManager();
  AuthenticationDialog* authDialog = new AuthenticationDialog();

  /* Initialize the subsystems */
  AdminInterfaceInitializor* adminInterfaceInitializor = new AdminInterfaceInitializor();
  AdministratorLogicInitializor* adminLogicInitializor = new AdministratorLogicInitializor();
  StudentInterfaceInitializor* studentInterfaceInitializor = new StudentInterfaceInitializor();
  StudentLogicInitializor* studentLogicInitializor = new StudentLogicInitializor();
  ProjectLogicInitializor* projectLogicInitializor = new ProjectLogicInitializor();

  adminInterfaceInitializor->initialize();
  adminLogicInitializor->intialize(storageManager,
                                   adminInterfaceInitializor->getAdminInputManager(),
                                   adminInterfaceInitializor->getAdminOutputManager(),
                                   authDialog);

  studentInterfaceInitializor->initialize();
  studentLogicInitializor->initialize(storageManager,
                                      studentInterfaceInitializor->getStudentInputManager(),
                                      studentInterfaceInitializor->getStudentOutputManager(),
                                      authDialog);


  projectLogicInitializor->initialize(storageManager,
                                      studentInterfaceInitializor->getStudentInputManager(),
                                      studentInterfaceInitializor->getStudentOutputManager(),
                                      adminInterfaceInitializor->getAdminInputManager(),
                                      adminInterfaceInitializor->getAdminOutputManager());


  /* display auth dialog */
  authDialog->show();

  /**************************************************
   *            NOTE for the DEVELOPERS
   *
   * Resetting the database and generating test data
   **************************************************
   *    DANGER! This deletes all existing data!
   **************************************************
   *
   * 1) delete the "storage.db" file in your
   *    "build-cupid-d4-Desktop-Debug" directory.
   * 2) copy the "database-schema.sql" file from the
   *    cupid-d4 directory to the
   *    "build-cupid-d4-Desktop-Debug" directory
   * 3) uncomment the code below:
   *
   **************************************************/

  //DatabaseManager db;
  //TestData* td = new TestData();
  //td->dropTables();
  //td->createTables();
  //td->generate();
  //delete td;
  //return 1;

  /**************************************************
   *
   * 4) run the program (Ctrl+R). The program will
   *    generate the test data and then exit
   *    immediately.
   *
   * 5) comment out the above code again.
   *
   * 6) That's it. If something gets messed up and
   *    you want to start over with a fresh set of
   *    testdata, simply repeat these steps.
   *
   **************************************************
   **************************************************
   **************************************************/

  return a.exec();


}
