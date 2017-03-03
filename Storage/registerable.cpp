#include "registerable.h"

Registerable::Registerable()
{
  maxNumberOfRegistrations = 0;
}

Registerable::Registerable(const Registerable& other)
{
  maxNumberOfRegistrations = other.getMaxNumberOfRegistrations();
  this->addRegistrations(other.getAllRegistrations());
}

Registerable::Registerable(int maxNumberOfRegistrations)
{
  this->maxNumberOfRegistrations = maxNumberOfRegistrations;
}

int Registerable::getMaxNumberOfRegistrations() const
{
  return maxNumberOfRegistrations;
}

void Registerable::setMaxNumberOfRegistrations(int value)
{
  maxNumberOfRegistrations = value;
}

bool Registerable::addRegistration(Registration* registration)
{
  if (maxNumberOfRegistrations &&
      registrations.size() + 1 > maxNumberOfRegistrations) {
    throw new ProjectFullException();
    return false;
  }

  registrations.append(registration);
  return true;
}

bool Registerable::addRegistrations(QList<Registration*> newRegistrations)
{
  // This operation is atomic: Either all reigstrations are added or none.
  if (maxNumberOfRegistrations &&
      (registrations.size() + newRegistrations.length()) > maxNumberOfRegistrations) {
    throw new TooManyRegistrationsException();
    return false;
  }
  registrations.append(newRegistrations);
  return true;
}

Registration* Registerable::getRegistration(int registrationId) const
{
  if (!registrations.size()) {
    return NULL;
  }

  Registration* r = NULL;
  QList<Registration*>::const_iterator iter;

  for (iter = registrations.begin(); iter != registrations.end(); ++iter) {
    if ((*iter)->getId() == registrationId) {
      r = *iter;
      break;
    }
  }

  return r;
}

QList<Registration*> Registerable::getAllRegistrations() const
{
  return registrations;
}

bool Registerable::removeRegistration(Registration* registration)
{
  return registrations.removeOne(registration);
}

Registration* Registerable::removeRegistration(int registrationId)
{
  if (!registrations.size()) {
    return NULL;
  }

  Registration *r = NULL;
  QList<Registration*>::const_iterator iter;

  for (iter = registrations.begin(); iter != registrations.end(); ++iter) {
    if ((*iter)->getId() == registrationId) {
      r = *iter;
      registrations.removeOne(r);
      break;
    }
  }

  return r;
}

int Registerable::getCurrentNumberOfRegistrations() const
{
  return registrations.size();
}
