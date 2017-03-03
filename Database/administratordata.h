#ifndef ADMINISTRATORDATA_H
#define ADMINISTRATORDATA_H

#include "Storage/administrator.h"
#include <QList>

class AdministratorData
{
  public:
    AdministratorData();
    bool updateAdministrator(Administrator* administrator);
    bool insertAdministrator(Administrator* administrator);
    Administrator* retrieveAdministrator(int id);
    QList<Administrator*> retrieveAllAdministrators();
};

#endif // ADMINISTRATORDATA_H
