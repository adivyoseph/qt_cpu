#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    srand (time(nullptr));

    randID = rand();
    qDebug() << "new randID " << randID;
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::SetMqtt(Mqtt *p_mqtt_arg){
    p_mqtt = p_mqtt_arg;

}


void MainWindow::slot_on_reset_event(void){
    struct Mqtt_msg msg;
    randID = rand();
    msg.msg_type = MSG_TYPE_REGISTER;
    msg.msg_node_type = MSG_NODE_TYPE_CPU;
    strcpy(msg.msg_source, "core");
    msg.msg_data_len = 1;
    msg.msg_data[0].key = KVD_TYPE_RADOM;
    msg.msg_data[0].value = randID;
    qDebug() << " on_reset_event randID " << randID;
    msg.msg_len = MSG_LEN_FULL;
    p_mqtt->mqtt_pub_register(&msg);

    ;
}


void MainWindow::slot_on_start_event(struct Mqtt_msg *msg){
    qDebug() << "on_start_event my randID " << randID << " sent " << msg->msg_data[0].value;
    if(msg->msg_data[0].value == randID){

         this->setWindowTitle(QString(msg->msg_source));
    }


}
