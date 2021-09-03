#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    time = new QTimer(this);
    connect(time, SIGNAL(timeout()), this, SLOT(myTimer()));

    ui->label->setText(inicio);
    for(int i = 1; i <= 60; i++) {
        ui->comboBox->addItem(QString::number(i));
    }

    music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sound/sound/heyDude.wav"));

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::myTimer(){
    QString  currentCbb = ui->comboBox->currentText();   


    if(segundos >= 60){
        minutos += 1;
        cont = 0;
        segundos = 0;
    }


    m = (minutos < 10) ? "0" + QString::number(minutos) : QString::number(minutos);
    s = (segundos < 10) ? "0" + QString::number(segundos) : QString::number(segundos);

    qDebug() << minutos;


    QString t = m +" : " + s;
    ui->label->setText(t);

    if(minutos == currentCbb.toInt()){
        finishTime();
    }

    qDebug() << currentCbb;
    segundos = cont++;

}


void MainWindow::on_pushButton_clicked()
{
    time->start(1000);
}


void MainWindow::on_btn_stop_clicked()
{
    time->stop();
}


void MainWindow::on_btn_reset_clicked()
{
    time->stop();
    cont = 0;
    minutos = 0;
    segundos = 0;
    qDebug() << cont;
    qDebug() << minutos;
    qDebug() << segundos;

    ui->label->setText(inicio);
}

void MainWindow::finishTime(){
    time->stop();

    music->play();

    QMessageBox msgBox;
    msgBox.setText("Time finished");
    msgBox.setInformativeText("let's procrastinate");
    msgBox.setStandardButtons(QMessageBox::Ok);
    int ret = msgBox.exec();
    if(ret){
        music->stop();
    }
}
