#ifndef ALGORITHMCONFIGURATIONDATA_H
#define ALGORITHMCONFIGURATIONDATA_H

#include <QList>

#include "Storage/algorithmconfiguration.h"

class AlgorithmConfigurationData
{
  public:
    AlgorithmConfigurationData();
    bool updateAlgorithmConfiguration(AlgorithmConfiguration* ac);
    bool insertAlgorithmConfiguration(AlgorithmConfiguration* ac);
    AlgorithmConfiguration* retrieveAlgorithmConfiguration(int id);
    QList<AlgorithmConfiguration*> retrieveAllAlgorithmConfigurations();
};

#endif // ALGORITHMCONFIGURATIONDATA_H
