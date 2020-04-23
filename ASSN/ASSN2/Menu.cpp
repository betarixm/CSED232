#include "Menu.h"
#include "User.h"
#include "Post.h"

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

/**
 * @brief 메뉴를 보여주는 메서드
 * @param type 메뉴의 종류
 * @param texts 메뉴의 텍스트들
 * @param isProfile 메뉴에 프로필 노출 여부
 * @param s 입출력 wrapper 참조
 * @return 사용자가 선택한 값 반환
 */
int Menu::show(string &type, string texts[], bool isProfile, Stream &s) {
    int input = 0; // 사용자가 선택한 메뉴를 저장할 곳

    while (true) { // 정상적인 입력이 들어올 때 까지 반복한다.
        printLine(); // 구분선 출력
        cout << "Menu - " << type << endl; // 메뉴의 종류를 출력한다.
        if (isProfile) { // 프로필을 출력해야 할 경우, 현재 유저의 프로필을 출력한다.
            this->user->printProfile();
        }
        // 메뉴의 텍스트를 출력한다.
        for (int i = 0; i < 4; i++) {
            cout << texts[i] << endl;
        }
        printLine(); // 구분선 출력

        // 사용자로부터 메뉴를 선택받는다.
        cout << "Select Menu: ";

        if ((!s.getInt(input))||(input < 1 || input > 4)) {
            // 1 이상 4 이하의 정수인 입력이 아닐 경우 에러 메세지를 출력한다.
            cout << "Invalid Input!" << endl;
        } else {
            // 선택된 메뉴의 이름을 출력한다.
            cout << "Selected Menu: " << texts[input - 1] << endl;
            // 유저가 선택한 값을 반환한다.
            return input;
        }
    }
}

/**
 * @brief 메뉴 클래스의 생성자
 * @param node_user 현재 사용자 주소
 * @param userList 사용자 리스트 주소
 * @param commentList 댓글 리스트 주소
 * @param postList 게시글 리스트 주소
 */
Menu::Menu(Node<User> *&node_user, UserList *userList, CommentList *commentList, PostList *postList) {
    this->node_user = node_user; // 현재 사용자 주소를 참조로 리스트의 유저에 세팅한다.
    this->user = nullptr; // 메뉴 오브젝트가 생성될 시점에는 유저 노드가 비어있을 것이므로, 우선 유저에는 nullptr을 할당한다.
    this->userList = userList; // 유저리스트의 주소를 저장한다.
    this->commentList = commentList; // 댓글리스트의 주소를 저장한다.
    this->postList = postList; // 게시글 리스트의 주소를 저장한다.
}

/**
 * @brief 메인 메뉴를 출력하는 메서드
 * @param s 입출력 wrapper 오브젝트 참조
 */
void Menu::main(Stream &s) {
    string type = "Main"; // 메뉴의 타입을 지정
    int input = 0;
    while (true) { // 메뉴를 명시적으로 종료할 때까지 반복한다.
        // 메인 타이틀 노출
        cout << endl << endl
             << "███╗   ███╗██╗███╗   ██╗██╗    ███████╗███╗   ██╗███████╗\n"
                "████╗ ████║██║████╗  ██║██║    ██╔════╝████╗  ██║██╔════╝\n"
                "██╔████╔██║██║██╔██╗ ██║██║    ███████╗██╔██╗ ██║███████╗\n"
                "██║╚██╔╝██║██║██║╚██╗██║██║    ╚════██║██║╚██╗██║╚════██║\n"
                "██║ ╚═╝ ██║██║██║ ╚████║██║    ███████║██║ ╚████║███████║\n"
                "╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝    ╚══════╝╚═╝  ╚═══╝╚══════╝\n\n"
                "              by beta@plus, Gwon Minjae.                 \n\n";

        // 메인 메뉴를 출력하고, 사용자의 입력값을 받아온다.
        input = show(type, mainTexts, false, s);

        // 메뉴 셀렉터
        if (input == 1) {
            // 1을 선택한 경우, 유저 추가 수행
            userList->addUser(s);
        } else if (input == 2) {
            // 2를 선택할 경우, 로그인 수행
            this->node_user = userList->signIn(s);
            if (node_user == nullptr) {
                // 로그인 실패시 에러 메시지 생성
                cout << "Failed to Sign In!" << endl;
            } else {
                // 로그인 성공 시 마이 페이지 노출
                this->user = node_user->data();
                this->myPage(s);
            }
        } else if (input == 3) {
            // 3을 선택할 경우, 커맨드 로드
            if (s.isLoadingCommand()) {
                // 이미 커맨드를 로드하고 있는 상태라면, 프로그램의 안전을 위해 무시한다.
                cout << "Additional 'Load Command' is Detected." << endl
                     << "It will be ignored to protect program." << endl;
            } else {
                // 커맨드를 로드한다.
                s.loadCommand();
            }
        } else if (input == 4) {
            // 4를 선택할 경우, 종료한다.
            return;
        }
    }
}

/**
 * @brief 마이페이지 메뉴 출력 메서드
 * @param s 입출력 wrapper 오브젝트 참조
 */
void Menu::myPage(Stream &s) {
    string type = "My Page"; // 메뉴의 타입을 지정한다.
    int input = 0;
    while (true) { // 메뉴를 명시적으로 종료할 때 까지 반복한다.
        // 메뉴를 출력하고, 선택 값을 받아온다.
        input = show(type, myPageTexts, true, s);
        if (input == 1) {
            // 1을 선택할 경우, 친구 메뉴 실행
            this->friends(s);
        } else if (input == 2) {
            // 2를 선택할 경우, 피드 메뉴 실행
            this->feed(s);
        } else if (input == 3) {
            // 3을 선택할 경우, 현재 유저를 nullptr로 설정하고 메인 메뉴로 이동.
            this->user = nullptr;
            return;
        } else if (input == 4) {
            // 4를 선택할 경우, 현재 유저를 삭제하고, 메인 메뉴로 이동.
            userList->removeUser(node_user, commentList, postList);
            return;
        }
    }
}

/**
 * @brief 친구 메뉴 출력 메서드
 * @param s 입출력 wrapper 오브젝트 참조
 */
void Menu::friends(Stream &s) {
    string type = "Friends"; // 메뉴 타입 지정
    int input = 0;
    while (true) { // 명시적으로 메뉴를 종료할 때 까지 반복
        // 메뉴를 출력하고, 사용자로부터 입력값을 받아옴.
        input = show(type, friendsTexts, false, s);
        if (input == 1) {
            // 1을 선택할 경우 친구 추가 수행
            user->friends().addFriend(s, user, userList);
        } else if (input == 2) {
            // 2를 선택할 경우, 친구 제거 수행
            user->friends().removeFriendById(s, userList);
        } else if (input == 3) {
            // 3을 선택할 경우, 친구 출력 수행
            user->friends().printFriends();
        } else if (input == 4) {
            // 4를 선택할 경우 마이페이지로 이동
            return;
        }
    }
}


/**
 * @brief 피드 메튜 출력 메서드
 * @param s 입출력 wrapper 오브젝트 참조
 */
void Menu::feed(Stream &s) {
    string type = "Feed"; // 메뉴 타입 지정
    int input = 0;
    while (true) { // 명시적으로 메뉴를 종료할 때 까지 반복
        // 메뉴를 출력하고, 사용자로부터 입력값을 받아옴
        input = show(type, feedTexts, false, s);
        if (input == 1) {
            // 1을 선택할 경우, 모든 게시물 출력
            postList->printPostList(s, user, commentList, user->friends().list());
        } else if (input == 2) {
            // 2를 선택할 경우, 게시물 추가 진입
            postList->addPost(user, s);
        } else if (input == 3) {
            // 3을 선택할 경우, 내 게시물만 출력
            auto me = new List<User>(1);
            me->add(this->user);
            postList->printPostList(s, user, commentList, *me);
            delete me;
        } else if (input == 4) {
            // 4를 선택할 경우, 마이페이지로 이동.
            return;
        }
    }
}
