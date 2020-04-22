#include "Menu.h"
#include "User.h"
#include "Post.h"

/*
 * 명예서약 (Honor Code)
 * 나는 이 프로그래밍 과제를 다른 사람의 부적절한 도움 없이 완수하였습니다.
 * I completed this programming task without the improper help of others.
 */

int Menu::show(string &type, string texts[], bool isProfile, Stream &s) {
    int input = 0;

    while (true) {
        printLine();
        cout << "Menu - " << type << endl;
        if (isProfile) {
            this->user->printProfile();
        }
        for (int i = 0; i < 4; i++) {
            cout << texts[i] << endl;
        }
        printLine();

        cout << "Select Menu: ";

        if ((!s.getInt(input))||(input < 1 || input > 4)) {
            cout << "Invalid Input!" << endl;
        } else {
            cout << "Selected Menu: " << texts[input - 1] << endl;
            return input;
        }
    }
}

Menu::Menu(Node<User> *&node_user, UserList *userList, CommentList *commentList, PostList *postList) {
    this->node_user = node_user;
    this->user = nullptr;
    this->userList = userList;
    this->commentList = commentList;
    this->postList = postList;
}

void Menu::main(Stream &s) {
    string type = "Main";
    int input = 0;
    while (true) {
        cout << endl << endl
             << "███╗   ███╗██╗███╗   ██╗██╗    ███████╗███╗   ██╗███████╗\n"
                "████╗ ████║██║████╗  ██║██║    ██╔════╝████╗  ██║██╔════╝\n"
                "██╔████╔██║██║██╔██╗ ██║██║    ███████╗██╔██╗ ██║███████╗\n"
                "██║╚██╔╝██║██║██║╚██╗██║██║    ╚════██║██║╚██╗██║╚════██║\n"
                "██║ ╚═╝ ██║██║██║ ╚████║██║    ███████║██║ ╚████║███████║\n"
                "╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝    ╚══════╝╚═╝  ╚═══╝╚══════╝\n\n"
                "              by beta@plus, Gwon Minjae.                 \n\n";


        input = show(type, mainTexts, false, s);
        if (input == 1) {
            userList->addUser(s);
        } else if (input == 2) {
            this->node_user = userList->signIn(s);
            if (node_user == nullptr) {
                cout << "Failed to Sign In!" << endl;
            } else {
                this->user = node_user->data();
                this->myPage(s);
            }
        } else if (input == 3) {
            if (s.isLoadingCommand()) {
                cout << "Additional 'Load Command' is Detected." << endl
                     << "It will be ignored to protect program." << endl;
            } else {
                s.loadCommand();
            }
        } else if (input == 4) {
            return;
        }
    }
}

void Menu::myPage(Stream &s) {
    string type = "My Page";
    int input = 0;
    while (true) {
        input = show(type, myPageTexts, true, s);
        if (input == 1) {
            this->friends(s);
        } else if (input == 2) {
            this->feed(s);
        } else if (input == 3) {
            this->user = nullptr;
            return;
        } else if (input == 4) {
            userList->removeUser(node_user, commentList, postList);
            return;
        }
    }
}

void Menu::friends(Stream &s) {
    string type = "Friends";
    int input = 0;
    while (true) {
        input = show(type, friendsTexts, false, s);
        if (input == 1) {
            user->friends().addFriend(s, user, userList);
        } else if (input == 2) {
            user->friends().removeFriendById(s, userList);
        } else if (input == 3) {
            user->friends().printFriends();
        } else if (input == 4) {
            return;
        }
    }
}

void Menu::feed(Stream &s) {
    string type = "Feed";
    int input = 0;
    while (true) {
        input = show(type, feedTexts, false, s);
        if (input == 1) {
            postList->printPostList(s, user, commentList, user->friends().list());
        } else if (input == 2) {
            postList->addPost(user, s);
        } else if (input == 3) {
            auto me = new List<User>(1);
            me->add(this->user);
            postList->printPostList(s, user, commentList, *me);
        } else if (input == 4) {
            return;
        }
    }
}
