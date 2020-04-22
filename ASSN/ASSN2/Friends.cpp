#include "Friends.h"
#include "User.h"

/*
 * 명예서약 (Honor Code)
 * 나는 이 프로그래밍 과제를 다른 사람의 부적절한 도움 없이 완수하였습니다.
 * I completed this programming task without the improper help of others.
 */

void Friends::addFriend(Stream &s, User *user, UserList *userList) { // 친구를 추가하는 메서드
    string id;

    // 사용자로부터 친구 아이디 입력 받음
    cout << "Input ID: ";
    s.getLine(id);

    // getUserID를 통해 유저를 찾음
    Node<User> *target = userList->getUserById(id);

    if (target == nullptr) { // 만약 유저가 없다면 오류 메세지 출력
        cout << id << " is not exist user." << endl;
    } else {
        if (friendsList->exist(target->data())) { // 이미 존재하는 친구인지 확인
            cout << id << " is already your friend." << endl; // 오류 메세지 출력
        } else if (target->data() == user) { // 자기 자신인지 확인
            cout << "You can't add yourself as a friend." << endl; // 오류 메세지 출력
        } else { // 친구를 추가할 수 있는 조건일 때
            auto tmp = friendsList->begin();
            for (; tmp != nullptr; tmp = tmp->next()) { // 친구 리스트를 탐색한다
                //
                if (tmp->data()->id() <= id &&
                    ((tmp->next() == nullptr) || (tmp->next() != nullptr && id < tmp->next()->data()->id()))) {
                    break;
                }
            }
            friendsList->insert(tmp, target->data());
            cout << id << " is added to your friend." << endl;
        }

    }
}

void Friends::removeFriendById(Stream &s, UserList *userList) {
    string id;
    cout << "Input ID: ";
    s.getLine(id);
    Node<User> *target = userList->getUserById(id);
    if (target == nullptr) {
        cout << id << " is not exist user." << endl;
    } else {
        target = friendsList->find(target->data());
        if (target != nullptr) {
            friendsList->drop(target);
            cout << id << " is deleted from your friend list." << endl;
        } else {
            cout << id << " is not your friend." << endl;
        }
    }
}

void Friends::printFriends() {
    if (friendsList->size() == 0) {
        cout << "You have not any friends... :(" << endl;
        return;
    }
    for (auto tmp = friendsList->begin(); tmp != nullptr; tmp = tmp->next()) {
        tmp->data()->printProfile();
    }
}

void Friends::removeFriendByUser(User *user) {
    for (auto tmp = friendsList->begin(); tmp != nullptr; tmp = tmp->next()) {
        if (tmp->data() == user) {
            friendsList->drop(tmp);
            break;
        }
    }
}

Friends::~Friends() {
    delete friendsList;
}