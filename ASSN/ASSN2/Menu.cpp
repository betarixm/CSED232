//
// Created by PBS on 2020-04-08.
//

#include "Menu.h"

void Menu::show(const User *user) {
    printLine();
    cout << "Menu - " << type << endl;
    for (const auto &text : texts) {
        cout << text << endl;
    }
    printLine();
}

void Menu::setTexts(string s[4]) {
    for (int i = 0; i < 4; i++) {
        texts[i].assign(s[i]);
    }
}

int Menu::input(User *user, Stream &s) {
    int num;
    show(user);
    cout << "Select Menu:";
    num = s.in<int>();
    if (!(0 < num && num < 5)) {
        num = 0, cout << "Invalid input." << endl;
    } else {
        cout << "Selected Menu: " << texts[num - 1] << endl;
    }
    return num;
}


MainMenu::MainMenu() {
    type = "Main";
    setTexts(mainText);
}

void MyPageMenu::show(const User *user) {
    printLine();
    cout << "Menu - " << type << endl;
    // cout << "@" << user.id << " - " << user.name << " " << user.birth.year << "." << user.birth.month << "." << user.birth.date << endl;
    cout << "@" << user->id << " - " << user->name << " " << user->birth_str << endl;
    for (const auto &text : texts) {
        cout << text << endl;
    }
    printLine();
}

MyPageMenu::MyPageMenu() {
    type = "My page";
    setTexts(myTexts);
}

FriendsMenu::FriendsMenu() {
    type = "Friends";
    setTexts(myTexts);
}


FeedMenu::FeedMenu() {
    type = "Feed";
    setTexts(myTexts);
}