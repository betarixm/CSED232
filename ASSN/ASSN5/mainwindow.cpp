#include <QDebug>
#include "mainwindow.h"
#include "ui_mainwindow.h"

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

// 메인윈도우 생성자
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), // 메인윈도우, ui 초기화
      stopwatch_is_started(false), // 스탑워치 시작 여부 초기화
      timer_is_started(false) // 타이머 시작 여부 초기화
{
    ui->setupUi(this); // ui 셋업

    // 스탑워치, 타이머 초기화
    on_stopwatch_btn_reset_clicked();
    on_timer_reset_clicked();

    // 효과음 설정
    timer_alram.setSource(QUrl::fromLocalFile(":/audio/alarm.wav")); // qrc를 통해 알람 가져옴
    timer_alram.setLoopCount(1); // 1번만 반복
    timer_alram.setVolume(1.0f); // 볼륨 설정

    // 이벤트 연결
    connect(&s_timer, SIGNAL(timeout()), this, SLOT(event_clock())); // 1초마다 시계 이벤트 전달
    connect(&m_timer, SIGNAL(timeout()), this, SLOT(event_stopwatch())); // 10밀리초마다 스탑워치 이벤트 전달
    connect(&s_timer, SIGNAL(timeout()), this, SLOT(event_timer())); // 1초마다 시계 이벤트 전달
    m_timer.start(10); // 10밀리초마다 이벤트 전달
    s_timer.start(1000); // 1초마다 이벤트 전달
}

// 메인윈도우 소멸자
MainWindow::~MainWindow()
{
    delete ui; // ui 삭제
}

// 타이머 라벨에 표시되는 시간을 임의의 문자열로 설정하는 함수
void MainWindow::set_timer_label(QString h, QString m, QString s){
    // 각 라벨을 주어진 문자열로 업데이트
    ui->timer_label_hour->setText(h);
    ui->timer_label_minute->setText(m);
    ui->timer_label_sec->setText(s);

    // 업데이트된 라벨로 화면 리프레시
    ui->timer_label_hour->repaint();
    ui->timer_label_minute->repaint();
    ui->timer_label_sec->repaint();
}

// 시계 이벤트 시 실행되는 함수
void MainWindow::event_clock(){
    auto t = QDateTime::currentDateTime(); // 현재 시간 가져옴
    auto str_time = QLocale("en_EN").toString(t, "hh : mm : ss AP"); // 시간을 문자열로 변환
    auto str_date = QLocale("en_EN").toString(t, "dddd, MMMM d, yyyy"); // 시간을 날짜로 변환
    ui->clock_label_time->setText(str_time); // 시간 출력
    ui->clock_label_date->setText(str_date); // 날짜 출력
}

// 스탑워치 이벤트 시 실행되는 함수
void MainWindow::event_stopwatch(){
    if(!stopwatch_is_started) return; // 시작된 상태가 아니라면 종료

    // 59:59.99를 초과할 때 중지 및 리셋.
    if(stopwatch_time.msecsTo(QTime(0,0,0,0)) == -1 * 60 * 60000){
        on_stopwatch_btn_stop_clicked();
        on_stopwatch_btn_reset_clicked();
        return;
    }

    // 스탑워치 시간 10 밀리초 증가
    stopwatch_time = stopwatch_time.addMSecs(10);

    // 출력 문자열 설정
    QString s = stopwatch_time.toString("mm : ss.zzz");
    s.chop(1);

    // 문자열 출력 및 화면 리프레시
    ui->stopwatch_label->setText(s);
    ui->stopwatch_label->repaint();
}

// 스탑워치 시작 버튼이 클릭될 때 실행되는 함수
void MainWindow::on_stopwatch_btn_start_clicked()
{
    // 버튼 활성 및 비활성화
    ui->stopwatch_btn_start->setDisabled(true);
    ui->stopwatch_btn_stop->setDisabled(false);
    ui->stopwatch_btn_reset->setDisabled(true);

    // 시작 여부 마킹 (시작함)
    stopwatch_is_started = true;

    // 문자열에서 시간 추출
    QString s = ui->stopwatch_label->text() + "0";
    stopwatch_time = stopwatch_time.fromString(s, "mm : ss.zzz");

    // 화면 리프레시
    ui->stopwatch_label->repaint();
}


// 스탑워치 종료 버튼이 클릭될 때 실행되는 함수
void MainWindow::on_stopwatch_btn_stop_clicked()
{
    // 버튼 활성 및 비활성화
    ui->stopwatch_btn_start->setDisabled(false);
    ui->stopwatch_btn_stop->setDisabled(true);
    ui->stopwatch_btn_reset->setDisabled(false);

    // 시작 여부 마킹 (시작 안함)
    stopwatch_is_started = false;

    // 화면 리프레시
    ui->stopwatch_label->repaint();
}

// 스탑워치 리셋 버튼이 클릭될 때 실행되는 함수
void MainWindow::on_stopwatch_btn_reset_clicked()
{
    // 버튼 활성 및 비활성화
    ui->stopwatch_btn_start->setDisabled(false);
    ui->stopwatch_btn_stop->setDisabled(true);
    ui->stopwatch_btn_reset->setDisabled(false);

    // 라벨, 시간, 시작여부 초기화
    ui->stopwatch_label->setText("00 : 00.00");
    stopwatch_time.setHMS(0, 0, 0, 0);
    stopwatch_is_started = false;

    // 화면 리프레시
    ui->stopwatch_label->repaint();
}

// 최대, 최솟값을 반영하여 d 만큼 더한 숫자 문자열을 반환하는 함수
QString MainWindow::timer_label_update(QString q, int d, int min, int max){
    QString res; // 결과 문자열
    int t = q.toInt() + d; // 입력 문자열 정수 변환 및 d 증가
    if(t < min){t = max; } // 최솟값보다 작아졌을 경우, 최댓값으로 설정
    if(t > max){t = min; } // 최댓값보다 커졌을 경우, 최솟값으로 설정.

    res = QString("%1").arg(t, 2, 10, QLatin1Char('0')); // 문자열 포맷
    return res; // 결과 문자열 반환
}

// 타이머 이벤트마다 실행되는 함수
void MainWindow::event_timer(){
    if(!timer_is_started) return; // 타이머가 실행 중인 상태가 아니라면 반환

    // 만약 0초에 다다랐다면 타이머 종료
    if(timer_time.secsTo(QTime(0,0,0)) == 0){
        timer_done();
        return;
    }

    // 타이머 시간 1초 감소
    timer_time = timer_time.addSecs(-1);

    // 타이머 시간으로 라벨 업데이트
    set_timer_label(
                QString("%1").arg(timer_time.hour(), 2, 10, QLatin1Char('0')),
                QString("%1").arg(timer_time.minute(), 2, 10, QLatin1Char('0')),
                QString("%1").arg(timer_time.second(), 2, 10, QLatin1Char('0')));
}

// 타이머 종료시 실행되는 함수
void MainWindow::timer_done(){
    timer_alram.play(); // 효과음 재생

    // 타이머 중지 및 초기화
    on_timer_stop_clicked();
    on_timer_reset_clicked();
    return;
}

// 타이머 시작 버튼이 클릭될 때 실행되는 함수
void MainWindow::on_timer_start_clicked()
{
    // 타이머 시간을 라벨의 시간으로 설정
    timer_time.setHMS(
                ui->timer_label_hour->text().toInt(),
                ui->timer_label_minute->text().toInt(),
                ui->timer_label_sec->text().toInt());

    // 시작 시간이 0일 경우 종료
    if(timer_time.secsTo(QTime(0,0,0)) == 0){ return; }

    // 버튼 활성 및 비활성화
    ui->timer_start->setDisabled(true);
    ui->timer_stop->setDisabled(false);
    ui->timer_reset->setDisabled(true);

    // 타이머 시작 여부 마킹 (시작함)
    timer_is_started = true;

    // 화면 리프레시
    ui->timer_stop->repaint();

}


// 타이머 중지 버튼이 클릭될 때 실행되는 함수
void MainWindow::on_timer_stop_clicked()
{
    // 버튼 활성 및 비활성화
    ui->timer_start->setDisabled(false);
    ui->timer_stop->setDisabled(true);
    ui->timer_reset->setDisabled(false);

    // 타이머 시작 여부 마킹 (시작 안함)
    timer_is_started = false;

    // 화면 리프레시
    ui->timer_stop->repaint();

}

// 타이머 리셋 버튼이 클릭될 때 실행되는 함수
void MainWindow::on_timer_reset_clicked()
{
    // 버튼 활성 및 비활성화
    ui->timer_start->setDisabled(false);
    ui->timer_stop->setDisabled(true);
    ui->timer_reset->setDisabled(false);

    // 타이머 라벨 초기화
    set_timer_label("00", "00", "00");
    timer_time.setHMS(0, 0, 0);

    // 타이머 시작 여부 마킹 (시작 안함)
    timer_is_started = false;

    // 화면 리프레시
    ui->timer_stop->repaint();
}

// 타이머 시간 증가 버튼이 클릭될 때 실행되는 함수
void MainWindow::on_timer_btn_hour_up_clicked()
{
    ui->timer_label_hour->setText(timer_label_update(ui->timer_label_hour->text(), 1, 0, 23));
    ui->timer_label_hour->repaint();
}

// 타이머 분 증가 버튼이 클릭될 때 실행되는 함수
void MainWindow::on_timer_btn_minute_up_clicked()
{
    ui->timer_label_minute->setText(timer_label_update(ui->timer_label_minute->text(), 1, 0, 59));
    ui->timer_label_minute->repaint();
}

// 타이머 초 증가 버튼이 클릭될 때 실행되는 함수
void MainWindow::on_timer_btn_sec_up_clicked()
{
    ui->timer_label_sec->setText(timer_label_update(ui->timer_label_sec->text(), 1, 0, 59));
        ui->timer_label_sec->repaint();
}

// 타이머 시간 감소 버튼이 클릭될 때 실행되는 함수
void MainWindow::on_timer_btn_hour_down_clicked()
{
    ui->timer_label_hour->setText(timer_label_update(ui->timer_label_hour->text(), -1, 0, 23));
    ui->timer_label_hour->repaint();
}

// 타이머 분 감소 버튼이 클릭될 때 실행되는 함수
void MainWindow::on_timer_btn_minute_down_clicked()
{
    ui->timer_label_minute->setText(timer_label_update(ui->timer_label_minute->text(), -1, 0, 59));
    ui->timer_label_minute->repaint();
}

// 타이머 초 감소 버튼이 클릭될 때 실행되는 함수
void MainWindow::on_timer_btn_sec_down_clicked()
{
    ui->timer_label_sec->setText(timer_label_update(ui->timer_label_sec->text(), -1, 0, 59));
    ui->timer_label_sec->repaint();
}

