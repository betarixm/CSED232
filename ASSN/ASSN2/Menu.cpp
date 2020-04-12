#include "Menu.h"

void Menu::show(const Node<User> *user) {
    printLine();
    cout << "Menu - " << type << endl;
    for (const auto &text : texts) {
        cout << text << endl;
    }
    printLine();
}

void Menu::setMenu(string* msgs, string &target) {
    for(int i = 0; i < 4; i++){
        this->texts[i].assign(msgs[i]);
    }
    this->type.assign(target);
}
int Menu::input(Node<User>* user, Stream &s) {
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

void MyPageMenu::show(const Node<User> *user) {
    if (user == nullptr){
        return;
    }
    printLine();
    cout << "Menu - " << type << endl;
    // cout << "@" << user.id << " - " << user.name << " " << user.birth.year << "." << user.birth.month << "." << user.birth.date << endl;
    cout << "@" << user->data->id << " - " << user->data->name << " " << user->data->birthday << endl;
    for (const auto &text : texts) {
        cout << text << endl;
    }
    printLine();
}

MainMenu::MainMenu(){
    string _texts[4] = {"1. Sign up", "2. Sign in", "3. Load command", "4. Program exit"};
    string _type="Main";

    this->setMenu(_texts, _type);
}

void MainMenu::selector(Stream& s, Node<User>*& user, UserList& userList, int& mode){
    int input = this->input(user, s);
    if(input == 0){
        return;
    } else if (input == 1){
        userList.addUser(s);
    } else if (input == 2){
        user = userList.signIn(s);
        if(user != nullptr){
            mode = MENU_MY_PAGE;
        }
    } else if (input == 3){
        // LOAD COMMAND
    } else if (input == 4){
        mode = MENU_EXIT;
    }

}
MyPageMenu::MyPageMenu(){
    string _texts[4] = {"1. Friends", "2. Feed", "3. Sign out", "4. Delete my account"};
    string _type="My Page";

    this->setMenu(_texts, _type);
}
FriendsMenu::FriendsMenu(){
    string _texts[4] = {"1. Add friends", "2. Delete friends", "3. My friends", "4. Previous menu"};
    string _type="Friends";

    this->setMenu(_texts, _type);
}
FeedMenu::FeedMenu(){
    string _texts[4] = {"1. All Feed", "2. Post", "3. My posting", "4. Previous menu"};
    string _type="Feed";

    this->setMenu(_texts, _type);
}
