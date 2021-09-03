#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QComboBox>
#include <QMediaPlayer>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void finishTime();
public slots:
    void myTimer();
private slots:
    void on_comboBox_currentIndexChanged(int index);

    void on_pushButton_clicked();

    void on_btn_stop_clicked();

    void on_btn_reset_clicked();

private:
    Ui::MainWindow *ui;
    QTimer *time;
    int cont=0;
    int minutos = 0;
    int segundos = 0;
    int entrada = 25;
    QString inicio = "00:00";
    QComboBox cbb;
   // int currentCbb = 0;
      QString m, s;
      QMediaPlayer * music;
};
#endif // MAINWINDOW_H
