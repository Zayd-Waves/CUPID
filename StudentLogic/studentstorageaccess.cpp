#include "studentstorageaccess.h"


StudentStorageAccess::StudentStorageAccess(StorageManager* storageManager)
{
        this->storageManager = storageManager;
}

StudentStorageAccess::~StudentStorageAccess()
{
    delete storageManager;
}

Student* StudentStorageAccess::getStudentByEmail(QString email)
{
    return storageManager->retrieveStudent(email);
}

bool StudentStorageAccess::storeProfile(Student* student)
{
      return storageManager->storeStudent(student);
}

