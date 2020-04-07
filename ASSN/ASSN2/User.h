#ifndef CSED232_USER_H
#define CSED232_USER_H
#include "20190084.h"

class User {
public:
    string id;
    string name;
    string password;
    string birth_str;
    Post* userPosts[MAX_POST] = {};
    User* friends[MAX_USER] = {};
    Comment* userComments[MAX_COMMENT] = {};

    User();
    ~User();
    bool deleteFriend(string& friend_id);
    User* addFriend(Stream& s);
};

class UserList {
public:
    User* user_db[MAX_USER] = {};
    int user_num;
    bool addUser(User* newUser);
    bool dropUser(string& id);
    UserList();
    bool signUp(Stream& s);
    User* signIn(Stream& s)
};


#endif //CSED232_USER_H
