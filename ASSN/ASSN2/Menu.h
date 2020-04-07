//
// Created by PBS on 2020-04-08.
//

#ifndef CSED232_MENU_H
#define CSED232_MENU_H

#include <iostream>
#include "User.h"
#include "Utils.h"

using namespace std;

class Menu {
protected:
    string texts[4];
    string type;

    virtual void show(const User* user);

    void setTexts(string s[4]);

public:
    int input(User* user, Stream& s);
};

class MainMenu : public Menu {
private:
    string mainText[4] = {"1. Sign up", "2. Sign in", "3. Load command", "4. Program exit"};
public:
    MainMenu();
};

class MyPageMenu : public Menu {
private:
    string myTexts[4] = {"1. Friends", "2. Feed", "3. Sign out", "4. Delete my account"};
protected:
    void show(const User* user) override;
public:
    MyPageMenu();
};

class FriendsMenu : public Menu {
private:
    string myTexts[4] = {"1. Add friends", "2. Delete friends", "3. My friends", "4. Previous menu"};
public:
    FriendsMenu();
};

class FeedMenu : public Menu {
private:
    string myTexts[4] = {"1. All Feed", "2. Post", "3. My posting", "4. Previous menu"};
public:
    FeedMenu();
};
#endif //CSED232_MENU_H
