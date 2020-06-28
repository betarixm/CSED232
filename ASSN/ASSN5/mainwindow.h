#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QDateTime>
#include <QMainWindow>
#include <QTimer>
#include <QElapsedTimer>
#include <QSoundEffect>

/*
 *
 *  ██╗  ██╗ ██████╗ ███╗   ██╗ ██████╗ ██████╗
 *  ██║  ██║██╔═══██╗████╗  ██║██╔═══██╗██╔══██╗
 *  ███████║██║   ██║██╔██╗ ██║██║   ██║██████╔╝
 *  ██╔══██║██║   ██║██║╚██╗██║██║   ██║██╔══██╗
 *  ██║  ██║╚██████╔╝██║ ╚████║╚██████╔╝██║  ██║
 *  ╚═╝  ╚═╝ ╚═════╝ ╚═╝  ╚═══╝ ╚═════╝ ╚═╝  ╚═╝
 *
 *        ██████╗ ██████╗ ██████╗ ███████╗
 *       ██╔════╝██╔═══██╗██╔══██╗██╔════╝
 *       ██║     ██║   ██║██║  ██║█████╗
 *       ██║     ██║   ██║██║  ██║██╔══╝
 *       ╚██████╗╚██████╔╝██████╔╝███████╗
 *        ╚═════╝ ╚═════╝ ╚═════╝ ╚══════╝
 *
 *
 * 명예서약 (Honor Code)
 * 나는 이 프로그래밍 과제를 다른 사람의 부적절한 도움 없이 완수하였습니다.
 * I completed this programming task without the improper help of others.
 *
 */

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
    void event_clock(); // 시계 이벤트 시 실행되는 함수

    void event_stopwatch(); // 스탑워치 이벤트 시 실행되는 함수

    void on_stopwatch_btn_start_clicked(); // 스탑워치 시작 버튼이 클릭될 때 실행되는 함수

    void on_stopwatch_btn_stop_clicked(); // 스탑워치 중지 버튼이 클릭될 때 실행되는 함수

    void on_stopwatch_btn_reset_clicked(); // 스탑워치 리셋 버튼이 클릭될 때 실행되는 함수

    void event_timer(); // 타이머 이벤트 시 실행되는 함수

    void on_timer_btn_hour_up_clicked(); // 타이머 시간 증가 버튼이 클릭될 때 실행되는 함수

    void on_timer_btn_minute_up_clicked(); // 타이머 분 증가 버튼이 클릭될 때 실행되는 함수

    void on_timer_btn_sec_up_clicked(); // 타이머 초 증가 버튼이 클릭될 때 실행되는 함수

    void on_timer_btn_hour_down_clicked(); // 타이머 시간 감소 버튼이 클릭될 때 실행되는 함수

    void on_timer_btn_minute_down_clicked(); // 타이머 분 감소 버튼이 클릭될 때 실행되는 함수

    void on_timer_btn_sec_down_clicked(); // 타이머 초 감소 버튼이 클릭될 때 실행되는 함수

    void on_timer_start_clicked(); // 타이머 시작 버튼이 클릭될 때 실행되는 함수

    void on_timer_stop_clicked(); // 타이머 중지 버튼이 클릭될 때 실행되는 함수

    void on_timer_reset_clicked(); // 타이머 리셋 버튼이 클릭될 때 실행되는 함수

private:
    Ui::MainWindow *ui; // 메인 윈도우 ui

    QTimer s_timer; // 초단위 (Second) 타이머
    QTimer m_timer; // 밀리초단위 (Millisecond) 타이머

    QTime stopwatch_time{0,0,0,0}; // 스탑워치 시간

    bool stopwatch_is_started; // 스탑워치의 시작 여부

    QTime timer_time{0,0,0,0}; // 타이머 시간

    bool timer_is_started; // 타이머의 시작 여부

    QSoundEffect timer_alram; // 타이머 종료 시 효과음

    // 최대, 최솟값을 반영하여 d 만큼 더한 숫자 문자열을 반환하는 함수.
    QString timer_label_update(QString q, int d, int min, int max);

    // 타이머 라벨에 표시되는 시간을 임의의 문자열로 설정하는 함수
    void set_timer_label(QString h, QString m, QString s);

    // 타이머 종료시 트리거되는 함수
    void timer_done();

};
#endif // MAINWINDOW_H
