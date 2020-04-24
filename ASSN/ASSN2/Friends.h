#ifndef CSED232_FRIENDS_H
#define CSED232_FRIENDS_H

#include "20190084.h"
#include "List.h"
#include "IO.h"

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

class User; // 유저 클래스 프로토타이핑

class UserList; // 유저 클래스 프로토타이핑

template<typename T>
class List; // 리스트 클래스 프로토 타이핑

/**
 * @brief 친구 목록을 관리하는 클래스
 */
class Friends {
private:
    List<User> *friendsList = new List<User>(MAX_USER); // 친구 목록을 저장하기 위한 리스트를 동적 할당

public:
    /// @brief 친구 목록에 친구를 추가하는 메서드
    void addFriend(Stream &s, User *user, UserList *userList);

    /// @brief 아이디를 입력받아서 친구를 삭제하는 메서드
    void removeFriendById(Stream &s, UserList *userList);

    /// @brief 유저 포인터를 입력받아서 친구를 삭제하는 메서드
    void removeFriendByUser(User *user);

    /// @brief 친구 목록을 출력하는 메서드
    void printFriends();

    /// @brief 친구 리스트를 참조형으로 반환
    List<User> &list();

    /// @brief 친구 리스트 소멸자
    ~Friends();
};


#endif //CSED232_FRIENDS_H
