#ifndef STUDENT_H
#define STUDENT_H

#include <QString>
#include "user.h"
#include "registerable.h"
#include "profile.h"
#include "project.h"

class Student : public User, public Registerable
{
  public:
    Student();
    Student(const Student& other);
    Student(Profile* profile, int studentNumber, const QString& email,
            const QString& firstName, const QString& lastName);
    Student(int profileId, int studentNumber, const QString& email,
            const QString& firstName, const QString& lastName);
    Student(int id, int profileId, int studentNumber, const QString& email,
            const QString& firstName, const QString& lastName);

    int getStudentNumber() const;
    void setStudentNumber(int value);
    Profile* getProfile() const;
    void setProfile(Profile* value);
    int getProfileId() const;
    void setProfileId(int value);
    Registration* getProjectRegistration(int projectId);
    bool isRegisteredIn(Project* project);

  private:
    int studentNumber;
    Profile* profile;
    int profileId;
};

#endif // STUDENT_H
