#ifndef PROJECT_H
#define PROJECT_H

#include <QString>
#include "registerable.h"

class Project : public Registerable
{
  public:
    Project();
    Project(const Project& other);
    Project(const QString& title, const QString& courseCode, const QString& description, int maxNumberOfRegistrations);
    Project(int id, const QString& title, const QString& courseCode, const QString& description, int maxNumberOfRegistrations);
    int getId() const;
    void setId(int value);
    QString getTitle() const;
    void setTitle(const QString& value);
    QString getCourseCode() const;
    void setCourseCode(const QString& value);
    QString getDescription() const;
    void setDescription(const QString& value);

  private:
    int id;
    QString title;
    QString courseCode;
    QString description;
};

#endif // PROJECT_H
