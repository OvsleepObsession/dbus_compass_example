#ifndef COMPASS_H
#define COMPASS_H

#include <QObject>
#include <QThread>

class Compass : public QObject
{
    Q_OBJECT
    Q_CLASSINFO("D-Bus", "local.Compass");
    qreal data; // some data

public:
    Compass(QObject *par);
    ~Compass();
    void collect_data();

public slots:
    qreal get_data();
};

#endif // COMPASS_H
