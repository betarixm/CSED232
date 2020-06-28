#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QDateTime>
#include <QMainWindow>
#include <QTimer>
#include <QElapsedTimer>
#include <QSoundEffect>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void event_clock();

    void event_stopwatch();

    void on_stopwatch_btn_start_clicked();

    void on_stopwatch_btn_stop_clicked();

    void on_stopwatch_btn_reset_clicked();

    void event_timer();

    void on_timer_btn_hour_up_clicked();

    void on_timer_btn_minute_up_clicked();

    void on_timer_btn_sec_up_clicked();

    void on_timer_btn_hour_down_clicked();

    void on_timer_btn_minute_down_clicked();

    void on_timer_btn_sec_down_clicked();

    void on_timer_start_clicked();

    void on_timer_stop_clicked();

    void on_timer_reset_clicked();

private:
    Ui::MainWindow *ui;

    QTimer s_timer;
    QTimer m_timer;

    QDateTime stopwatch_start_time;
    QDateTime stopwatch_stop_time;
    qint64 stopwatch_stoped_time;

    bool stopwatch_is_started;
    bool stopwatch_is_reset;

    QTime timer_start_time{0,0,0,0};

    bool timer_is_started;

    qint64 timer_elapsed;

    QSoundEffect timer_alram;

    QString timer_label_update(QString q, int d, int min, int max);

    void set_timer_label(QString h, QString m, QString s);

    void timer_done();

};
#endif // MAINWINDOW_H
