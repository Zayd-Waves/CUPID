#ifndef PROFILEDATA_H
#define PROFILEDATA_H

#include "Storage/profile.h"

class ProfileData
{
  public:
    ProfileData();
    bool updateProfile(Profile* profile);
    bool insertProfile(Profile* profile);
    Profile* retrieveProfile(int id);
    QList<Profile*> retrieveAllProfiles();
};

#endif // PROFILEDATA_H
