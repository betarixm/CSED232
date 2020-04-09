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

    virtual void show(const User* user);

public:
    int input(User* user, Stream& s);
};

class MainMenu : public Menu {
private:
    string texts[4] = {"1. Sign up", "2. Sign in", "3. Load command", "4. Program exit"};
    string type="Main";
};

class MyPageMenu : public Menu {
private:
    string texts[4] = {"1. Friends", "2. Feed", "3. Sign out", "4. Delete my account"};
    string type="My Page";
protected:
    void show(const User* user) override;
};

class FriendsMenu : public Menu {
private:
    string texts[4] = {"1. Add friends", "2. Delete friends", "3. My friends", "4. Previous menu"};
    string type="Friends";
};

class FeedMenu : public Menu {
private:
    string texts[4] = {"1. All Feed", "2. Post", "3. My posting", "4. Previous menu"};
    string type="Feed";
};

#endif //CSED232_MENU_H
