#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include "user.h"
#include "algorithmconfiguration.h"
#include <QString>

class Administrator : public User
{
  public:
    Administrator();
    Administrator(const Administrator&);
    Administrator(const QString& email, const QString& firstName, const QString& lastName,
                  AlgorithmConfiguration* algorithmConfiguration);
    Administrator(const QString& email, const QString& firstName, const QString& lastName,
                  int algorithmConfigurationId);
    Administrator(int id, const QString& email, const QString& firstName, const QString& lastName,
                  AlgorithmConfiguration* algorithmConfiguration);
    Administrator(int id, const QString& email, const QString& firstName, const QString& lastName,
                  int algorithmConfigurationId);

    AlgorithmConfiguration* getAlgorithmConfiguration() const;
    void setAlgorithmConfiguration(AlgorithmConfiguration* value);
    int getAlgorithmConfigurationId() const;
    void setAlgorithmConfigurationId(int value);

  private:
    AlgorithmConfiguration* algorithmConfiguration;
    int algorithmConfigurationId;
};

#endif // ADMINISTRATOR_H
