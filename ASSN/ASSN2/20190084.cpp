#include <iostream>
#include "List.h"
#include "Menu.h"
#include "IO.h"
#include "Comment.h"
#include "Post.h"
#include "User.h"

using namespace std;

/*
 * 명예서약 (Honor Code)
 * 나는 이 프로그래밍 과제를 다른 사람의 부적절한 도움 없이 완수하였습니다.
 * I completed this programming task without the improper help of others.
 */

int main() {

    Node<User> *node_user;
    UserList userList;
    PostList postList;
    CommentList commentList;

    Stream s(cin.rdbuf());

    Menu menu = Menu(node_user, &userList, &commentList, &postList);
    menu.main(s);

    return 0;
}