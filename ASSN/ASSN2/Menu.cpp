#include "Menu.h"

void Menu::show(const User *user) {
    printLine();
    cout << "Menu - " << type << endl;
    for (const auto &text : texts) {
        cout << text << endl;
    }
    printLine();
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

void MyPageMenu::show(const User *user) {
    printLine();
    cout << "Menu - " << type << endl;
    // cout << "@" << user.id << " - " << user.name << " " << user.birth.year << "." << user.birth.month << "." << user.birth.date << endl;
    cout << "@" << user->id << " - " << user->name << " " << user->birthday << endl;
    for (const auto &text : texts) {
        cout << text << endl;
    }
    printLine();
}
