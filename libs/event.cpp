#include "event.h"
#include "subscriber.h"

Event::Event(QString name)
{
  this->name = name;
}

void Event::subscribe(Subscriber* s)
{
  subscribers.append(s);
}

void Event::unsubscribe(Subscriber* s)
{
  // not sure if this'll work, gotta test
  subscribers.removeOne(s);
}

void Event::notifySubscribers()
{
  QList<Subscriber*>::const_iterator iter;
  for (iter = subscribers.begin(); iter != subscribers.end(); ++iter) {
    (*iter)->notify(this);
  }
}

QString Event::getName() const
{
  return name;
}

void Event::setName(const QString& value)
{
  name = value;
}

