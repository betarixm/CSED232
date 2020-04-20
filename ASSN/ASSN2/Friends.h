//
// Created by PBS on 2020-04-18.
//

#ifndef CSED232_FRIENDS_H
#define CSED232_FRIENDS_H

#include "20190084.h"
#include "List.h"
#include "IO.h"

/*
 * 명예서약 (Honor Code)
 * 나는 이 프로그래밍 과제를 다른 사람의 부적절한 도움 없이 완수하였습니다.
 * I completed this programming task without the improper help of others.
 */

class User;

class UserList;

template<typename T>
class List;

class Friends {
private:
    List<User> *friendsList = new List<User>(MAX_USER);

public:
    void addFriend(Stream &s, User *user, UserList *userList);

    void removeFriendById(Stream &s, UserList *userList);

    void removeFriendByUser(User *user);

    void printFriends();

    List<User> &list() {
        return *friendsList;
    }

    ~Friends();
};


#endif //CSED232_FRIENDS_H
