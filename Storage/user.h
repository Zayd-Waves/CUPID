#ifndef USER_H
#define USER_H

#include <QString>

class User
{
  public:
    User();
    User(const User& other);
    User(const QString& email, const QString& firstName, const QString& lastName);
    User(int id, const QString& email, const QString& firstName, const QString& lastName);
    int getId() const;
    void setId(int value);
    QString getEmail() const;
    void setEmail(const QString& value);
    QString getFirstName() const;
    void setFirstName(const QString& value);
    QString getLastName() const;
    void setLastName(const QString& value);

  private:
    int id;
    QString email;
    QString firstName;
    QString lastName;
};

#endif // USER_H
