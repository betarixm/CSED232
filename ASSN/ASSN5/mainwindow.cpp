#include <QDebug>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow),
      stopwatch_stoped_time(0), stopwatch_is_started(false), stopwatch_is_reset(true),
      timer_is_started(false), timer_elapsed(0)
{
    ui->setupUi(this);
    on_stopwatch_btn_reset_clicked();
    on_timer_reset_clicked();

    timer_alram.setSource(QUrl::fromLocalFile(":/audio/alarm.wav"));
    timer_alram.setLoopCount(1);
    timer_alram.setVolume(1.0f);

    connect(&s_timer, SIGNAL(timeout()), this, SLOT(event_clock()));
    connect(&m_timer, SIGNAL(timeout()), this, SLOT(event_stopwatch()));
    connect(&s_timer, SIGNAL(timeout()), this, SLOT(event_timer()));
    m_timer.start(10);
    s_timer.start(1000);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::set_timer_label(QString h, QString m, QString s){
    ui->timer_label_hour->setText(h);
    ui->timer_label_minute->setText(m);
    ui->timer_label_sec->setText(s);

    ui->timer_label_hour->repaint();
    ui->timer_label_minute->repaint();
    ui->timer_label_sec->repaint();
}

void MainWindow::event_clock(){
    auto t = QDateTime::currentDateTime();
    auto str_time = QLocale("en_EN").toString(t, "hh : mm : ss AP");
    auto str_date = QLocale("en_EN").toString(t, "dddd, MMMM d, yyyy");
    ui->clock_label_time->setText(str_time);
    ui->clock_label_date->setText(str_date);
}

void MainWindow::event_stopwatch(){
    if(!stopwatch_is_started) return;
    QTime elapsed{0,0};
    auto t = stopwatch_start_time.msecsTo(QDateTime::currentDateTime()) - stopwatch_stoped_time;
    elapsed = elapsed.addMSecs(t);
    if(t >= 60*60000){
        on_stopwatch_btn_stop_clicked();
        on_stopwatch_btn_reset_clicked();
        return;
    }
    QString s = elapsed.toString("mm : ss.zzz");
    s.chop(1);
    ui->stopwatch_label->setText(s);
}

void MainWindow::on_stopwatch_btn_start_clicked()
{
    ui->stopwatch_btn_start->setDisabled(true);
    ui->stopwatch_btn_stop->setDisabled(false);
    ui->stopwatch_btn_reset->setDisabled(true);

    stopwatch_is_started = true;
    if(stopwatch_is_reset){
        stopwatch_is_reset = false;
        stopwatch_start_time = QDateTime::currentDateTime();
        stopwatch_stop_time = QDateTime::currentDateTime();
        stopwatch_stoped_time = 0;
    }

    stopwatch_stoped_time += stopwatch_stop_time.msecsTo(QDateTime::currentDateTime());
    ui->stopwatch_label->repaint();
}



void MainWindow::on_stopwatch_btn_stop_clicked()
{
    ui->stopwatch_btn_start->setDisabled(false);
    ui->stopwatch_btn_stop->setDisabled(true);
    ui->stopwatch_btn_reset->setDisabled(false);

    stopwatch_is_started = false;
    stopwatch_stop_time = QDateTime::currentDateTime();
    ui->stopwatch_label->repaint();
}




void MainWindow::on_stopwatch_btn_reset_clicked()
{
    ui->stopwatch_btn_start->setDisabled(false);
    ui->stopwatch_btn_stop->setDisabled(true);
    ui->stopwatch_btn_reset->setDisabled(false);

    ui->stopwatch_label->setText("00 : 00.00");

    stopwatch_is_started = false;
    stopwatch_is_reset = true;
    ui->stopwatch_label->repaint();
}

QString MainWindow::timer_label_update(QString q, int d, int min, int max){
    QString res;
    int t = q.toInt() + d;

    if(t < min){t = max; }
    if(t > max){t = min; }

    res = QString("%1").arg(t, 2, 10, QLatin1Char('0'));
    return res;
}

void MainWindow::event_timer(){
    if(!timer_is_started) return;

    if(timer_start_time.secsTo(QTime(0,0,0)) == 0){
        timer_done();
        return;
    }
    timer_start_time = timer_start_time.addSecs(-1);
    set_timer_label(
                QString("%1").arg(timer_start_time.hour(), 2, 10, QLatin1Char('0')),
                QString("%1").arg(timer_start_time.minute(), 2, 10, QLatin1Char('0')),
                QString("%1").arg(timer_start_time.second(), 2, 10, QLatin1Char('0')));


}

void MainWindow::timer_done(){
    timer_alram.play();
    on_timer_stop_clicked();
    on_timer_reset_clicked();
    return;
}


void MainWindow::on_timer_start_clicked()
{
    ui->timer_start->setDisabled(true);
    ui->timer_stop->setDisabled(false);
    ui->timer_reset->setDisabled(true);

    timer_is_started = true;

    timer_start_time.setHMS(
                ui->timer_label_hour->text().toInt(),
                ui->timer_label_minute->text().toInt(),
                ui->timer_label_sec->text().toInt());
    ui->timer_stop->repaint();

}

void MainWindow::on_timer_stop_clicked()
{
    ui->timer_start->setDisabled(false);
    ui->timer_stop->setDisabled(true);
    ui->timer_reset->setDisabled(false);
    timer_is_started = false;
    ui->timer_stop->repaint();

}

void MainWindow::on_timer_reset_clicked()
{
    ui->timer_start->setDisabled(false);
    ui->timer_stop->setDisabled(true);
    ui->timer_reset->setDisabled(false);
    timer_is_started = false;

    set_timer_label("00", "00", "00");
    timer_start_time.setHMS(0, 0, 0);
    timer_elapsed = 0;
    ui->timer_stop->repaint();
}


void MainWindow::on_timer_btn_hour_up_clicked()
{
    ui->timer_label_hour->setText(timer_label_update(ui->timer_label_hour->text(), 1, 0, 23));
    ui->timer_label_hour->repaint();
}

void MainWindow::on_timer_btn_minute_up_clicked()
{
    ui->timer_label_minute->setText(timer_label_update(ui->timer_label_minute->text(), 1, 0, 59));
    ui->timer_label_minute->repaint();
}

void MainWindow::on_timer_btn_sec_up_clicked()
{
    ui->timer_label_sec->setText(timer_label_update(ui->timer_label_sec->text(), 1, 0, 59));
        ui->timer_label_sec->repaint();
}

void MainWindow::on_timer_btn_hour_down_clicked()
{
    ui->timer_label_hour->setText(timer_label_update(ui->timer_label_hour->text(), -1, 0, 23));
    ui->timer_label_hour->repaint();
}

void MainWindow::on_timer_btn_minute_down_clicked()
{
    ui->timer_label_minute->setText(timer_label_update(ui->timer_label_minute->text(), -1, 0, 59));
    ui->timer_label_minute->repaint();
}

void MainWindow::on_timer_btn_sec_down_clicked()
{
    ui->timer_label_sec->setText(timer_label_update(ui->timer_label_sec->text(), -1, 0, 59));
    ui->timer_label_sec->repaint();
}

