#include <iostream>
#include "List.h"
#include "Menu.h"
#include "IO.h"
#include "Comment.h"
#include "Post.h"
#include "User.h"

using namespace std;

/*
 *
 *  ██╗  ██╗ ██████╗ ███╗   ██╗ ██████╗ ██████╗
 *  ██║  ██║██╔═══██╗████╗  ██║██╔═══██╗██╔══██╗
 *  ███████║██║   ██║██╔██╗ ██║██║   ██║██████╔╝
 *  ██╔══██║██║   ██║██║╚██╗██║██║   ██║██╔══██╗
 *  ██║  ██║╚██████╔╝██║ ╚████║╚██████╔╝██║  ██║
 *  ╚═╝  ╚═╝ ╚═════╝ ╚═╝  ╚═══╝ ╚═════╝ ╚═╝  ╚═╝
 *
 *        ██████╗ ██████╗ ██████╗ ███████╗
 *       ██╔════╝██╔═══██╗██╔══██╗██╔════╝
 *       ██║     ██║   ██║██║  ██║█████╗
 *       ██║     ██║   ██║██║  ██║██╔══╝
 *       ╚██████╗╚██████╔╝██████╔╝███████╗
 *        ╚═════╝ ╚═════╝ ╚═════╝ ╚══════╝
 *
 *
 * 명예서약 (Honor Code)
 * 나는 이 프로그래밍 과제를 다른 사람의 부적절한 도움 없이 완수하였습니다.
 * I completed this programming task without the improper help of others.
 *
 */

int main() {

    Node<User> *node_user; /// @brief 현재 유저를 저장하는 노드
    UserList userList; /// @brief 유저들을 저장하는 리스트
    PostList postList; /// @brief 게시물들을 저장하는 리스트
    CommentList commentList; /// @brief 댓글들을 저장하는 리스트

    Stream s(cin.rdbuf()); /// @brief 입출력을 관리하는 스트림 Wrapper

    Menu menu(node_user, &userList, &commentList, &postList); // 메뉴 오브젝트 생성
    menu.main(s); // 메인 메뉴 시작

    return 0;
}