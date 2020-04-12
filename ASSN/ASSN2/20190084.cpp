#include <iostream>
#include "Contents.h"
#include "List.h"
#include "Menu.h"
#include "IO.h"

using namespace std;

int main() {
    bool isLogin = false;
    int input = 0;

    int mode = MENU_MAIN;

    MainMenu mainMenu;
    FriendsMenu friendsMenu;
    MyPageMenu myPageMenu;
    FeedMenu feedMenu;

    Node<User>* user = nullptr;
    UserList userList = UserList();
    PostList postList = PostList();

    auto cin_backup = cin.rdbuf();

    Stream s = Stream(cin.rdbuf());
    s._out.open("command.txt", ios::app);

    while(true){

        if(mode == MENU_EXIT){
            break;
        } else if(mode == MENU_MAIN){
            mainMenu.selector(s, user, userList, mode);
        } else if (mode == MENU_MY_PAGE) {
            myPageMenu.selector(s, user, userList, mode);
        } else if (mode == MENU_FRIENDS) {
            input = friendsMenu.input(user, s);
            if(input == 0){
                continue;
            } else if (input == 1){

            } else if (input == 2){

            } else if (input == 3){

            } else if (input == 4){
                mode = MENU_MY_PAGE;
            }
        } else if (mode == MENU_FEED) {
            feedMenu.selector(s, user, postList, mode);
        }
    }

    return 0;

}


