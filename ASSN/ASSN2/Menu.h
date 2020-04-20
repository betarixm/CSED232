#ifndef CSED232_MENU_H
#define CSED232_MENU_H

#include "20190084.h"
#include <iostream>
#include "IO.h"
#include "Utils.h"
#include "List.h"

/*
 * 명예서약 (Honor Code)
 * 나는 이 프로그래밍 과제를 다른 사람의 부적절한 도움 없이 완수하였습니다.
 * I completed this programming task without the improper help of others.
 */

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
    User *user;
    Node<User> *node_user;
    UserList *userList;
    CommentList *commentList;
    PostList *postList;

    int show(string &type, string texts[], bool isProfile, Stream &s);

public:
    Menu(Node<User> *&user, UserList *userList, CommentList *commentList, PostList *postList);

    void main(Stream &s);

    void myPage(Stream &s);

    void friends(Stream &s);

    void feed(Stream &s);
};

#endif //CSED232_MENU_H
