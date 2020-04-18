#include <iostream>
#include "List.h"
#include "Menu.h"
#include "IO.h"
#include "Comment.h"
#include "Post.h"
#include "User.h"

using namespace std;

int main() {
    bool isLogin = false;
    int input = 0;

    int mode = MENU_MAIN;

    User* user = nullptr;
    UserList userList;
    PostList postList;
    CommentList commentList;

    Stream s = Stream(cin.rdbuf());

    Menu menu = Menu(nullptr, &userList, &commentList, &postList);
    menu.main(s);
    return 0;

}


