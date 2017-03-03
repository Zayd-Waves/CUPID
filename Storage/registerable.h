#ifndef REGISTERABLE_H
#define REGISTERABLE_H

#include <QException>
#include <QList>
#include "registration.h"

class Registerable
{
  public:
    Registerable();
    Registerable(const Registerable& other);
    Registerable(int maxNumberOfRegistrations);
    int getMaxNumberOfRegistrations() const;
    void setMaxNumberOfRegistrations(int value);

    bool addRegistration(Registration*);
    bool addRegistrations(QList<Registration*>);
    Registration* getRegistration(int) const;
    QList<Registration*> getAllRegistrations() const;
    bool removeRegistration(Registration*);
    Registration* removeRegistration(int);
    int getCurrentNumberOfRegistrations() const;

  private:
    int maxNumberOfRegistrations;
    QList<Registration*> registrations;
};

/* Thrown when adding a registration and the project is full */
class ProjectFullException : public QException
{
  public:
    void raise() const {
      throw *this;
    }
    ProjectFullException *clone() const {
      return new ProjectFullException(*this);
    }
};

/* Thrown when adding many registrations and the project would be beyond capacity */
class TooManyRegistrationsException : public QException
{
  public:
    void raise() const {
      throw *this;
    }
    TooManyRegistrationsException *clone() const {
      return new TooManyRegistrationsException(*this);
    }
};

#endif // REGISTERABLE_H
