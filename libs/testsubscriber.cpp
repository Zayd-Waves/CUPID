#include <QDebug>
#include "testsubscriber.h"
#include "event.h"

TestSubscriber::TestSubscriber() : Subscriber()
{
}

void TestSubscriber::notify(Event* e)
{
  qDebug() << "I have been notified of" << e->getName();
}


