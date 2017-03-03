#ifndef EVENT_H
#define EVENT_H

#include <QList>
#include <QString>

/*
 * We do not actually need to subclass this class as shown in the diagram.
 * The name attribute is sufficient in identifying the type of the event
 */

class Subscriber;

class Event
{
  public:
    Event(QString);
    void subscribe(Subscriber*);
    void unsubscribe(Subscriber*);
    void notifySubscribers();
    QString getName() const;
    void setName(const QString& value);

  private:
    QList<Subscriber*> subscribers;
    QString name;
};

#endif // EVENT_H
