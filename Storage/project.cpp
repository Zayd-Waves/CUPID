/*
 -----------------------------------------------------------------------
|                                                                       |
|   Class:          Project                                             |
|   Description:    Project entity class.                               |
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

#include "project.h"

Project::Project() : Registerable()
{
}

Project::Project(const Project& other) : Registerable(other)
{
  id = other.getId();
  title = other.getTitle();
  courseCode = other.getCourseCode();
  description = other.getDescription();
}

Project::Project(const QString& title, const QString& courseCode, const QString& description, int maxNumberOfRegistrations) :
   Registerable(maxNumberOfRegistrations)
{
  this->id = -1;
  this->title = title;
  this->courseCode = courseCode;
  this->description = description;
}

Project::Project(int id, const QString& title, const QString& courseCode, const QString& description, int maxNumberOfRegistrations) :
   Registerable(maxNumberOfRegistrations)
{
  this->id = id;
  this->title = title;
  this->courseCode = courseCode;
  this->description = description;
}

int Project::getId() const
{
  return id;
}

void Project::setId(int value)
{
  id = value;
}

QString Project::getTitle() const
{
  return title;
}

void Project::setTitle(const QString& value)
{
  title = value;
}

QString Project::getCourseCode() const
{
  return courseCode;
}

void Project::setCourseCode(const QString& value)
{
  courseCode = value;
}

QString Project::getDescription() const
{
  return description;
}

void Project::setDescription(const QString& value)
{
  description = value;
}
