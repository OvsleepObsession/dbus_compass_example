/*
 * This file was generated by qdbusxml2cpp version 0.8
 * Command line was: qdbusxml2cpp -a Compass_adapter Compass.xml
 *
 * qdbusxml2cpp is Copyright (C) 2020 The Qt Company Ltd.
 *
 * This is an auto-generated file.
 * Do not edit! All changes made to it will be lost.
 */

#include "Compass_adapter.h"
#include <QtCore/QMetaObject>
#include <QtCore/QByteArray>
#include <QtCore/QList>
#include <QtCore/QMap>
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QVariant>

/*
 * Implementation of adaptor class CompassAdaptor
 */

CompassAdaptor::CompassAdaptor(QObject *parent)
    : QDBusAbstractAdaptor(parent)
{
    // constructor
    setAutoRelaySignals(true);
}

CompassAdaptor::~CompassAdaptor()
{
    // destructor
}

double CompassAdaptor::get_data()
{
    // handle method call local.Compass.get_data
    double out0;
    QMetaObject::invokeMethod(parent(), "get_data", Q_RETURN_ARG(double, out0));
    return out0;
}
