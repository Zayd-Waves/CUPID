#ifndef ALGORITHMCONFIGURATION_H
#define ALGORITHMCONFIGURATION_H

class AlgorithmConfiguration
{
  public:
    AlgorithmConfiguration();
    AlgorithmConfiguration(const AlgorithmConfiguration&);
    AlgorithmConfiguration(int teamSize);
    AlgorithmConfiguration(int id, int teamSize);
    int getId() const;
    void setId(int value);
    int getTeamSize() const;
    void setTeamSize(int value);

  private:
    int id;
    int teamSize;
};

#endif // ALGORITHMCONFIGURATION_H
