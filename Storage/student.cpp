/*
 -----------------------------------------------------------------------
|                                                                       |
|   Class:          Student                                             |
|   Description:    Student entity class.                               |
|                                                                       |
|                                                                       |
|                                                                       |
|                                                                       |
|   Author:         Syzgy                                               |
|   Date:           11/27/2015                                          |
|                                                                       |
|                                                                       |
 -----------------------------------------------------------------------
*/

#include "student.h"

Student::Student() : User(), Registerable()
{
  profile = NULL;
  profileId = -1;
}

Student::Student(const Student& other) : User(other), Registerable(other)
{
  studentNumber = other.getStudentNumber();
  profile = other.getProfile();
  profileId = other.getProfileId();
}

Student::Student(Profile* profile, int studentNumber, const QString& email, const QString& firstName,
                 const QString& lastName) :
  User(email, firstName, lastName), Registerable()
{
  this->studentNumber = studentNumber;
  this->profile = profile;
  if (this->profile) {
    this->profileId = profile->getId();
  } else {
    this->profileId = -1;
  }
}

Student::Student(int profileId, int studentNumber, const QString& email, const QString& firstName,
                 const QString& lastName) :
  User(email, firstName, lastName), Registerable()
{
  this->studentNumber = studentNumber;
  this->profile = NULL;
  this->profileId = profileId;
}

Student::Student(int id, int profileId, int studentNumber, const QString& email, const QString& firstName,
                 const QString& lastName) :
  User(id, email, firstName, lastName), Registerable()
{
  this->profileId = profileId;
  this->studentNumber = studentNumber;
}

int Student::getStudentNumber() const
{
  return studentNumber;
}

void Student::setStudentNumber(int value)
{
  studentNumber = value;
}

Profile* Student::getProfile() const
{
  return profile;
}

void Student::setProfile(Profile* value)
{
  profile = value;
  if (value) {
    profileId = value->getId();
  } else {
    profileId = -1;
  }
}

int Student::getProfileId() const
{
  return profileId;
}

void Student::setProfileId(int value)
{
  profileId = value;
}

Registration* Student::getProjectRegistration(int projectId)
{
  foreach (Registration* reg, getAllRegistrations()) {
    if (reg->getProjectId() == projectId) {
      return reg;
    }
  }
  return NULL;
}

bool Student::isRegisteredIn(Project* project)
{
  return !!getProjectRegistration(project->getId());
}



