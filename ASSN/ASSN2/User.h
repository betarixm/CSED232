#ifndef CSED232_USER_H
#define CSED232_USER_H

#include "20190084.h"
#include <iostream>
#include "List.h"
#include "Friends.h"

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

class Post; // 게시글 클래스 프로토타이핑

class PostList; // 게시글 목록 클래스 프로토타이핑

class Comment; // 댓글 클래스 프로토타이핑

class CommentList; // 댓글 목록 클래스 프로토타이핑

class Stream; // 입출력 클래스 프로토타이핑

class Friends; // 친구 클래스 프로토타이핑

/**
 * @brief 유저를 저장하고 관리하는 클래스
 */
class User {
private:
    string user_id; /// @brief 유저의 아이디
    string name; /// @brief 유저의 이름
    string birthday; /// @brief 유저의 생일
    size_t user_password; /// @brief 유저의 비밀번호
    Friends *friendList; /// @brief 유저의 친구 리스트

public:
    /// @brief 유저 클래스 생성자
    User(string &id, string &name, string &birthday, string &password);
    /// @brief 유저 클래스 소멸자
    ~User();
    /// @brief 유저의 아이디를 반환하는 클래스
    string &id();
    /// @brief 프로필을 출력하는 클래스
    void printProfile();
    /// @brief 프로필을 출력하는 클래스
    bool auth(string &id, string &password);
    /// @brief 유저의 친구 리스트를 반환하는 클래스
    Friends &friends();
};

/**
 * @brief 유저 목록을 관리하는 클래스
 */
class UserList {
private:
    List<User> *list = new List<User>(MAX_USER); /// @brief 유저 노드들을 저장할 리스트 동적할당
public:
    /// @brief 유저 리스트에 유저를 추가하는 메서드
    Node<User> *addUser(Stream &s);
    /// @brief 로그인 메서드
    Node<User> *signIn(Stream &s);
    /// @brief 유저를 삭제하는 메서드
    void removeUser(Node<User> *user, CommentList *commentList, PostList *postList);
    /// @brief ID로 유저를 찾아서 반환하는 메서드
    Node<User> *getUserById(string &id);
    /// @brief UserList 소멸자
    ~UserList();
};


#endif //CSED232_USER_H
