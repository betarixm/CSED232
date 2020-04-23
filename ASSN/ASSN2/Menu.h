#ifndef CSED232_MENU_H
#define CSED232_MENU_H

#include "20190084.h"
#include <iostream>
#include "IO.h"
#include "Utils.h"
#include "List.h"

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

using namespace std;

class User; // 유저 클래스 프로토타이핑

class UserList; // 유저 리스트 클래스 프로토타이핑

class CommentList; // 댓글 리스트 클래스 프로토타이핑

class PostList; // 게시글 리스트 클래스 프로토타이핑

/**
 * @brief 메뉴를 관리하는 클래스
 */
class Menu {
private:
    /// @brief 메인 메뉴 텍스트
    string mainTexts[4] = {"1. Sign up", "2. Sign in", "3. Load command", "4. Program exit"};
    /// @brief 마이 페이지 메뉴 텍스트
    string myPageTexts[4] = {"1. Friends", "2. Feed", "3. Sign out", "4. Delete my account"};
    /// @brief 친구 메뉴 텍스트
    string friendsTexts[4] = {"1. Add friends", "2. Delete friends", "3. My friends", "4. Previous menu"};
    /// @brief 피드 메뉴 텍스트
    string feedTexts[4] = {"1. All Feed", "2. Post", "3. My posting", "4. Previous menu"};

    User *user; /// @brief 현재 유저 저장
    Node<User> *node_user; /// @brief 현재 유저의 노드 저장
    UserList *userList; /// @brief 유저 목록 주소 저장
    CommentList *commentList; /// @brief 댓글 목록 주소 저장
    PostList *postList; /// @brief 게시글 목록 주소 저장

    /// @brief 메뉴를 보여주는 메서드
    int show(string &type, string texts[], bool isProfile, Stream &s);

public:
    /// @brief 메뉴 클래스의 생성자
    Menu(Node<User> *&user, UserList *userList, CommentList *commentList, PostList *postList);

    /// @brief 메인 메뉴를 출력하는 메서드
    void main(Stream &s);

    /// @brief 마이페이지 메뉴 출력 메서드
    void myPage(Stream &s);

    /// @brief 친구 메뉴 출력 메서드
    void friends(Stream &s);

    /// @brief 피드 메튜 출력 메서드
    void feed(Stream &s);
};

#endif //CSED232_MENU_H
