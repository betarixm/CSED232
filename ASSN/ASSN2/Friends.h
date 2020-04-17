//
// Created by PBS on 2020-04-18.
//

#ifndef CSED232_FRIENDS_H
#define CSED232_FRIENDS_H

#include "20190084.h"
#include "List.h"
#include "IO.h"

class User;
class UserList;

template <typename T>
class List;
class Friends {
private:
    List<User>* friendsList = new List<User>(MAX_USER);

public:
    void addFriend(Stream& s, UserList *userList);
    void removeFriendById(Stream &s, UserList *userList);
    void removeFriendByUser(User* user);
    void printFriends();
    List<User>& list(){
        return *friendsList;
    }
};


#endif //CSED232_FRIENDS_H
