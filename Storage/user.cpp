/*
 -----------------------------------------------------------------------
|                                                                       |
|   Class:          User                                                |
|   Description:    User entity class.                                  |
|                                                                       |
|                                                                       |
|                                                                       |
|                                                                       |
|                                                                       |
|   Author:         Syzgy                                               |
|   Date:           11/03/2015                                          |
|                                                                       |
|                                                                       |
 -----------------------------------------------------------------------
*/

#include "user.h"

User::User()
{
  this->id = -1;
  this->email = "";
  this->firstName = "";
  this->lastName = "";
}

User::User(const User& other)
{
  this->id = other.getId();
  this->email = other.getEmail();
  this->firstName = other.getFirstName();
  this->lastName = other.getLastName();
}

User::User(const QString& email, const QString& firstName, const QString& lastName)
{
  this->id = -1;
  this->email = email;
  this->firstName = firstName;
  this->lastName = lastName;
}

User::User(int id, const QString& email, const QString& firstName, const QString& lastName)
{
  this->id = id;
  this->email = email;
  this->firstName = firstName;
  this->lastName = lastName;
}

int User::getId() const
{
  return id;
}

void User::setId(int value)
{
  id = value;
}

QString User::getEmail() const
{
  return email;
}

void User::setEmail(const QString& value)
{
  email = value;
}

QString User::getFirstName() const
{
  return firstName;
}

void User::setFirstName(const QString& value)
{
  firstName = value;
}

QString User::getLastName() const
{
  return lastName;
}

void User::setLastName(const QString& value)
{
  lastName = value;
}
