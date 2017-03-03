/*
 -----------------------------------------------------------------------
|                                                                       |
|   Class:          Registration                                        |
|   Description:    Registration entity class.                          |
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

#include "registration.h"
#include "student.h"
#include "project.h"

Registration::Registration()
{
  this->id = -1;
  this->student = NULL;
  this->studentId = -1;
  this->project = NULL;
  this->studentId = -1;
  this->date = QDate::currentDate();
}

Registration::Registration(const Registration& other)
{
  this->id = other.getId();
  this->student = other.getStudent();
  this->studentId = other.getStudentId();
  this->project = other.getProject();
  this->projectId = other.getProjectId();
  this->date = other.getDate();
}

Registration::Registration(Student* student, Project* project)
{
  this->id = -1;
  this->student = student;
  this->project = project;
  this->date = QDate::currentDate();

  if (student) {
    this->studentId = student->getId();
  } else {
    this->studentId = -1;
  }

  if (project) {
    this->projectId = project->getId();
  } else {
    this->projectId = -1;
  }
}

Registration::Registration(Student* student, Project* project, QDate& date)
{
  this->id = -1;
  this->student = student;
  this->project = project;
  this->date = date;

  if (student) {
    this->studentId = student->getId();
  } else {
    this->studentId = -1;
  }

  if (project) {
    this->projectId = project->getId();
  } else {
    this->projectId = -1;
  }
}

Registration::Registration(int studentId, int projectId)
{
  this->id = -1;
  this->studentId = studentId;
  this->student = NULL;
  this->projectId = projectId;
  this->project = NULL;
  this->date = QDate::currentDate();
}

Registration::Registration(int id, Student* student, Project* project)
{
  this->id = id;
  this->student = student;
  this->project = project;
  this->date = QDate::currentDate();

  if (student) {
    this->studentId = student->getId();
  } else {
    this->studentId = -1;
  }

  if (project) {
    this->projectId = project->getId();
  } else {
    this->projectId = -1;
  }
}

Registration::Registration(int id, Student* student, Project* project, QDate& date)
{
  this->id = id;
  this->student = student;
  this->project = project;
  this->date = date;

  if (student) {
    this->studentId = student->getId();
  } else {
    this->studentId = -1;
  }

  if (project) {
    this->projectId = project->getId();
  } else {
    this->projectId = -1;
  }
}

Registration::Registration(int id, int studentId, int projectId, QDate& date)
{
  this->id = id;
  this->student = NULL;
  this->studentId = studentId;
  this->project = NULL;
  this->projectId = projectId;
  this->date = date;
}

Registration::Registration(int id, Student* student, int studentId,
                           Project* project, int projectId, QDate& date)
{
  this->id = id;
  this->student = student;
  this->studentId = studentId;
  this->project = project;
  this->projectId = projectId;
  this->date = date;
}

int Registration::getId() const
{
  return id;
}

void Registration::setId(int value)
{
  id = value;
}

Student* Registration::getStudent() const
{
  return student;
}

void Registration::setStudent(Student* value)
{
  student = value;
  if (student) {
    studentId = student->getId();
  } else {
    studentId = -1;
  }
}

int Registration::getStudentId() const
{
    return studentId;
}

void Registration::setStudentId(int value)
{
    studentId = value;
}

Project* Registration::getProject() const
{
  return project;
}

void Registration::setProject(Project* value)
{
  project = value;
  if(project) {
    this->projectId = project->getId();
  } else {
    this->projectId = -1;
  }
}

int Registration::getProjectId() const
{
    return projectId;
}

void Registration::setProjectId(int value)
{
    projectId = value;
}

QDate Registration::getDate() const
{
  return date;
}

void Registration::setDate(const QDate& value)
{
  date = value;
}




