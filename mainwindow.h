#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "mqtt.h"

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void     SetMqtt(Mqtt *p_mqtt);

public slots:
    void slot_on_reset_event(void);
    void slot_on_start_event(struct Mqtt_msg *msg);

private:
    Ui::MainWindow *ui;
        Mqtt *p_mqtt;
        int randID;
        QString name;
};

#endif // MAINWINDOW_H
