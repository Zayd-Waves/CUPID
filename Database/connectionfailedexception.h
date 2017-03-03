#ifndef CONNECTIONFAILEDEXCEPTION_H
#define CONNECTIONFAILEDEXCEPTION_H

#include <QException>

class ConnectionFailedException : public QException
{
    void raise() const {
      throw *this;
    }
    ConnectionFailedException *clone() const {
      return new ConnectionFailedException(*this);
    }
};

#endif // CONNECTIONFAILEDEXCEPTION_H
