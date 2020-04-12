#ifndef CSED232_MENU_H
#define CSED232_MENU_H

#include "20190084.h"
#include <iostream>
#include "IO.h"
#include "Utils.h"
#include "Contents.h"
using namespace std;

class Menu;
class MainMenu;
class MyPageMenu;
class FriendsMenu;
class FeedMenu;

class Menu {
protected:
    string texts[4];
    string type;

    virtual void show(const Node<User>* user);
    void setMenu(string* msgs, string& target);
public:
    int input(Node<User>* user, Stream& s);
};

class MainMenu : public Menu {
public:
    MainMenu();
    void selector(Stream& s, Node<User>*& user, UserList& userList, int& mode);
};

class MyPageMenu : public Menu {
protected:
    void show(const Node<User>* user) override;

public:
    MyPageMenu();
    void selector(Stream& s, Node<User>*& user, UserList& userList, int& mode){
        int input = this->input(user, s);
        if(input == 0){
            return;
        } else if (input == 1){
            mode = MENU_FRIENDS;
        } else if (input == 2){
            mode = MENU_FEED;
        } else if (input == 3){
            user = nullptr;
            mode = MENU_MAIN;
        } else if (input == 4){
            userList.removeUser(user);
            mode = MENU_MAIN;
        }
    }
};

class FriendsMenu : public Menu {
public:
    FriendsMenu();
};

class FeedMenu : public Menu {
public:
    FeedMenu();
    void selector(Stream& s, Node<User>*& user, PostList& postList, int& mode){
        int input = this->input(user, s);
        if(input == 0){
            return;
        } else if (input == 1){
            postList.printAllPost();
            mode = MENU_FEED;
        } else if (input == 2){
            postList.inputPost(s, user);
            mode = MENU_FEED;
        } else if (input == 3){
            user = nullptr;
            mode = MENU_FEED;
        } else if (input == 4){
            mode = MENU_MY_PAGE;
        }
    }
};

#endif //CSED232_MENU_H
