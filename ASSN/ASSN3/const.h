
#ifndef CSED232_CONST_H
#define CSED232_CONST_H

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

// ANSI 컬러 코드 지정
#define RED 31
#define GREEN 32
#define YELLOW 33
#define BLUE 34
#define MAGENTA 35
#define CYAN 36
#define WHITE 37
#define RESET 0

// 회전 방향 지정
#define CW 1
#define CCW -1

// 테트리미노를 종류에 따른 번호로 지정
#define MINO_I 0
#define MINO_O 1
#define MINO_T 2
#define MINO_L 3
#define MINO_J 4
#define MINO_S 5
#define MINO_Z 6

// 블록 리스트에서 관리할 수 있는 최대의 블록 개수
#define MAX_BLOCK 1000

// 게임판의 가로 세로 크기
#define ROW 20
#define COL 10

// y 좌표를 렌더 형식에 맞게 변환하는 매크로
#define CONVERT_Y(Y) (ROW-Y-1)

#endif //CSED232_CONST_H
