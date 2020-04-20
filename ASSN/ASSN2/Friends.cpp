#include "Friends.h"
#include "User.h"

/*
 * 명예서약 (Honor Code)
 * 나는 이 프로그래밍 과제를 다른 사람의 부적절한 도움 없이 완수하였습니다.
 * I completed this programming task without the improper help of others.
 */

void Friends::addFriend(Stream &s, User *user, UserList *userList) {
    string id;
    cout << "Input ID: ";
    s.getLine(id);
    Node<User> *target = userList->getUserById(id);
    if (target == nullptr) {
        cout << id << " is not exist user." << endl;
    } else {
        if (friendsList->exist(target->data())) {
            cout << id << " is already your friend." << endl;
        } else if (target->data() == user) {
            cout << "You can't add yourself as a friend." << endl;
        } else {
            auto tmp = friendsList->begin();
            for (; tmp != nullptr; tmp = tmp->next()) {
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
        }
    }
}

Friends::~Friends() {
    delete friendsList;
}