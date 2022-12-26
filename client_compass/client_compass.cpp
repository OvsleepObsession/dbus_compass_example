#include "client_compass.h"
#include "./ui_client_compass.h"
#include <QDebug>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    // opens connection with session bus
    if (!QDBusConnection::sessionBus().isConnected()) {
        qCritical() << "Cannot connect to the D-Bus\n";
        return;
      }
    ui->setupUi(this);
    // draws initial compass in gui
    draw_compass();
}

MainWindow::~MainWindow()
{
    // RAII
    delete ui;
    delete line;
    delete scene;
    delete circle;
}

void MainWindow::draw_compass()
{
    // compass drawing
    const int DIAMETER = 300;
    const int WIDTH = 5;
    const int LENGTH = DIAMETER/2;
    this->circle = new QGraphicsEllipseItem(0, 0, DIAMETER, DIAMETER);
    circle->setFlag(QGraphicsItem::ItemClipsChildrenToShape, true);
    circle->setBrush(Qt::white);
    this->line = new QGraphicsRectItem(150,150, -WIDTH, -LENGTH);
    line->setTransformOriginPoint(150,150); // sets origin point to the center of the compass
    line->setParentItem(circle);
    line->setBrush(Qt::red);
    this->scene = new QGraphicsScene;
    scene->addItem(circle);
    ui->graphicsView->setScene(scene);
}

void MainWindow::rotate_compass_needle(qreal rotation)
{
    line->setRotation(rotation); // rotates compass line
    scene->update(); // updates the scene after that
}

void MainWindow::delay(int msecs) // delay that not freeze gui
{
    QTime dieTime= QTime::currentTime().addMSecs(msecs);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 500);
}

void MainWindow::on_sub_button_clicked() // subscribe button
{
      // creates proxy for interface on remote object (server)
      QDBusInterface iface("server.Compass", "/server/Compass", "local.Compass", QDBusConnection::sessionBus());
      if (!iface.isValid()) {
          return;
      }
      subscription_status = true;
      // while subscription is valid
      while (subscription_status) {
        delay(ui->comboBox->currentText().toInt()); // some timeout
        QDBusReply<double> reply = iface.call("get_data"); // retreiving rotation value
        if (reply.isValid()) {
          qDebug() << "Reply was captured, Value: " << reply.value();
          if (!reply.error().isValid()) // if reply is not error
            rotate_compass_needle(reply.value());
        } else {
          qCritical() << "Failed:" << qPrintable(reply.error().message());
          return;
        }
      }
}

void MainWindow::on_unsub_button_clicked() // unsubscribe button
{
    subscription_status = false;
}
