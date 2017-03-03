#ifndef REGISTRATIONDATA_H
#define REGISTRATIONDATA_H

#include <QList>
#include <QString>
#include <QDate>

#include "Storage/registration.h"

class RegistrationData
{
  public:
    RegistrationData();
    bool updateRegistration(Registration* registration);
    bool insertRegistration(Registration* registration);
    bool deleteRegistration(Registration* registration);
    Registration* retrieveRegistration(int id);
    QList<Registration*> retrieveAllRegistrations();

  private:
    QString dateToString(const QDate& date);
    QDate stringToDate(const QString& date);
};

#endif // REGISTRATIONDATA_H
