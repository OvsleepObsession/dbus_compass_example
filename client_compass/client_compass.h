#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsEllipseItem>
#include <QtDBus/QtDBus>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void draw_compass();
    void delay(int msecs); // delay that not freeze gui

public slots:
    // changes compass needle position by some degree
    void rotate_compass_needle(qreal rotation);

private slots:
    void on_sub_button_clicked();

    void on_unsub_button_clicked();

private:
    // subscribed or not
    bool subscription_status;

    Ui::MainWindow *ui;
    QGraphicsRectItem *line;
    QGraphicsScene *scene;
    QGraphicsEllipseItem *circle;
};


#endif // MAINWINDOW_H
