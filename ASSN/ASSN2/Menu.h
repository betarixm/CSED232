#ifndef CSED232_MENU_H
#define CSED232_MENU_H

#include "20190084.h"
#include <iostream>
#include "IO.h"
#include "Utils.h"
#include "List.h"
using namespace std;
class User;
class UserList;
class CommentList;
class PostList;


class Menu {
private:
    string mainTexts[4] = {"1. Sign up", "2. Sign in", "3. Load command", "4. Program exit"};
    string myPageTexts[4] = {"1. Friends", "2. Feed", "3. Sign out", "4. Delete my account"};
    string friendsTexts[4] = {"1. Add friends", "2. Delete friends", "3. My friends", "4. Previous menu"};
    string feedTexts[4] = {"1. All Feed", "2. Post", "3. My posting", "4. Previous menu"};
    User* user;
    Node<User>* node_user;
    UserList* userList;
    CommentList* commentList;
    PostList* postList;

    int show(string& type, string texts[], User* pUser, bool isProfile, Stream& s);
public:
    Menu(User* user, UserList* userList, CommentList* commentList, PostList* postList);
    void main(Stream& s);
    void myPage(Stream& s);
    void friends(Stream& s);
    void feed(Stream& s);
    void setUser(User* pUser);
};

#endif //CSED232_MENU_H
