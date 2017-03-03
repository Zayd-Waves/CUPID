#ifndef DATAQUERYFAILED_H
#define DATAQUERYFAILED_H

#include <QException>

class DataQueryFailedException : public QException
{
    void raise() const {
      throw *this;
    }
    DataQueryFailedException *clone() const {
      return new DataQueryFailedException(*this);
    }
};

#endif // DATAQUERYFAILED_H
