#ifndef STUDENTSTORAGEACCESS_H
#define STUDENTSTORAGEACCESS_H

#include "Storage/storagemanager.h"
#include "Storage/student.h"

class StudentStorageAccess
{
public:
    StudentStorageAccess(StorageManager*);
    ~StudentStorageAccess();
    Student* getStudentByEmail(QString);
    bool storeProfile(Student*);

private:
    StorageManager* storageManager;
};

#endif // STUDENTSTORAGEACCESS_H
