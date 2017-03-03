#ifndef SUBSCRIBER_H
#define SUBSCRIBER_H

class Event;

class Subscriber
{
  public:
    Subscriber();
    virtual void notify(Event*) = 0;
};

#endif // SUBSCRIBER_H
