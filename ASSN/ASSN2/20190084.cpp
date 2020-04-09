#include <iostream>
#include "Contents.h"
#include "List.h"
#include "Menu.h"
#include "IO.h"

using namespace std;

int main() {
    bool isLogin = false;
    int input = 0;
    enum Mode {
        MENU_MAIN,
        MENU_MY_PAGE,
        MENU_FRIENDS,
        MENU_FEED
    };

    Mode mode = MENU_MAIN;
    MainMenu mainMenu;
    FriendsMenu friendsMenu;
    MyPageMenu myPageMenu;
    FeedMenu feedMenu;

    Node<User>* user = nullptr;
    UserList userList = UserList();

    auto cin_backup = cin.rdbuf();

    Stream s = Stream(cin.rdbuf());
    s._out.open("command.txt", ios::app);

    while(true){
        if(mode == MENU_MAIN){
            input = mainMenu.input(user->data, s);
            if(input == 0){
                continue;
            } else if (input == 1){
                userList.addUser(s);
            } else if (input == 2){
                user = userList.signIn(s);
                if(user != nullptr){
                    mode = MENU_MY_PAGE;
                }
            } else if (input == 3){

            } else if (input == 4){
                break;
            }
        } else if (mode == MENU_MY_PAGE) {
            input = myPageMenu.input(user->data, s);
            if(input == 0){
                continue;
            } else if (input == 1){
                mode = MENU_FRIENDS;
            } else if (input == 2){
                mode = MENU_FEED;
            } else if (input == 3){
                user = nullptr;
                mode = MENU_MAIN;
            } else if (input == 4){
                mode = MENU_MAIN;
            }
        } else if (mode == MENU_FRIENDS) {
            input = friendsMenu.input(user->data, s);
            if(input == 0){
                continue;
            } else if (input == 1){

            } else if (input == 2){

            } else if (input == 3){

            } else if (input == 4){
                mode = MENU_MY_PAGE;
            }
        } else if (mode == MENU_FEED) {
            input = feedMenu.input(user->data, s);
            if(input == 0){
                continue;
            } else if (input == 1){

            } else if (input == 2){

            } else if (input == 3){

            } else if (input == 4){
                mode = MENU_MY_PAGE;
            }
        }
    }


}


