#ifndef TESTSUBSCRIBER_H
#define TESTSUBSCRIBER_H

#include "subscriber.h"

class Event;

class TestSubscriber : public Subscriber
{
  public:
    TestSubscriber();
    void notify(Event*);
};

#endif // TESTSUBSCRIBER_H
