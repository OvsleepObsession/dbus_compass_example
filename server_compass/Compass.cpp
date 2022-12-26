#include "Compass.h"
// autogenereted by qdbusxml2cpp -a Compass_adapter Compass.xml
#include "Compass_adapter.h"
#include <QRandomGenerator>
#include <QDebug>

Compass::Compass(QObject *parent) : QObject(parent)
{
    // wrapper
    new CompassAdaptor(this);
    // connects to session bus
    QDBusConnection dbus = QDBusConnection::sessionBus();
    // regisering object
    dbus.registerObject("/server/Compass", this);
    // registering service
    dbus.registerService("server.Compass");
}

Compass::~Compass() {}

qreal Compass::get_data()
{
    collect_data();
    return data;
}

void Compass::collect_data()
{
    // some random values for example purposes
    QRandomGenerator *rg = QRandomGenerator::global();
    this->data = rg->bounded(-360,360);
    qDebug() << this->data;

}

