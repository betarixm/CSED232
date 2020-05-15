#ifndef CSED232_POSITION_H
#define CSED232_POSITION_H

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

/**
 * @brief 기본적인 좌표를 관리하는 클래스
 */
class Position {
private:
    int pos_x = 0; /// @brief x 좌표
    int pos_y = 0; /// @brief y 좌표
public:
    /// @brief Position 기본 생성자
    Position() = default;

    /// @brief 정수 좌표로 초기화하는 Position 생성자
    Position(int x, int y);

    /// @brief x 좌표를 반환하는 메서드
    int& x();

    /// @brief y 좌표를 반환하는 메서드
    int& y();

    /// @brief 정수형으로 좌표를 설정하는 메서드
    void setPosition(int x, int y);

    /// @brief Position으로 좌표를 설정하는 메서드
    void setPosition(Position p);

    /// @brief x와 y 좌표 값을 바꿔주는 메서드
    void swap();

    /// @brief 좌표를 더하는 + 오버로딩
    Position& operator+(Position param);

    /// @brief 좌표를 대입하는 = 오버로딩
    Position& operator=(const Position & param);

    /// @brief 좌표를 빼는 - 오버로딩
    Position&operator-(Position param);

    /// @brief 좌표를 더하는 += 오버로딩
    Position&operator+=(Position param);

    /// @brief 좌표를 빼는 -= 오버로딩
    Position&operator-=(Position& param);

};


#endif //CSED232_POSITION_H
