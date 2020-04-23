#include "Friends.h"
#include "User.h"

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
 * @brief 친구리스트에 친구를 추가하는 메서드
 *
 * @param s 입출력을 위해 스트림 Wrapper 클래스 참조
 * @param user 어떤 유저에게 친구를 추가할지 결정
 * @param userList 존재하는 유저인지 체크하기 위해 유저리스트 참조
 */
void Friends::addFriend(Stream &s, User *user, UserList *userList) { // 친구를 추가하는 메서드
    string id; // 아이디를 입력 받을 변수

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
                // ABC 순으로 정렬해야 하기에, 친구를 삽입할 적절한 위치를 찾는다.
                if (tmp->data()->id() <= id &&
                    ((tmp->next() == nullptr) || (tmp->next() != nullptr && id < tmp->next()->data()->id()))) {
                    break; // 적절한 위치를 찾았다면, 반복문을 탈출한다.
                }
            }
            friendsList->insert(tmp, target->data()); // 친구리스트에 친구를 삽입한다.
            cout << id << " is added to your friend." << endl; // 안내 메세지 출력.
        }

    }
}

/**
 * @brief 아이디를 입력받아서 친구를 삭제하는 메서드
 *
 * @param s 입출력을 위해 스트림 Wrapper 클래스 참조
 * @param userList 존재하는 유저인지 체크하기 위해 유저리스트 참조
 */
void Friends::removeFriendById(Stream &s, UserList *userList) {
    string id; // 아이디를 입력받을 스트링 변수

    // 사용자로부터 아이디를 입력 받음
    cout << "Input ID: ";
    s.getLine(id);

    // 입력 받은 아이디를 유저리스트에서 검색
    Node<User> *target = userList->getUserById(id);

    if (target == nullptr) { // 만약 없는 유저라면, 에러 메세지 출력
        cout << id << " is not exist user." << endl;
    } else {
        target = friendsList->find(target->data()); // 아이디를 친구 목록에서 검색
        if (target != nullptr) { // 친구 목록에서 친구를 삭제한다
            friendsList->drop(target);
            cout << id << " is deleted from your friend list." << endl;
        } else { // 친구 목록에 없는 친구라면 에러 메세지를 출력
            cout << id << " is not your friend." << endl;
        }
    }
}

/**
 * @brief 친구 목록을 출력하는 메서드
 */
void Friends::printFriends() {
    if (friendsList->size() == 0) { // 만약 친구가 없다면 에러메세지를 출력
        cout << "You have not any friends... :(" << endl;
        return;
    }
    for (auto tmp = friendsList->begin(); tmp != nullptr; tmp = tmp->next()) { // 친구리스트를 탐색하면서
        tmp->data()->printProfile(); // 해당 친구의 프로필을 출력
    }
}

/**
 * @brief 유저 포인터를 이용해서 친구를 삭제하는 메서드
 * @param user 삭제할 유저
 */
void Friends::removeFriendByUser(User *user) {
    // 친구 목록을 탐색하면서
    for (auto tmp = friendsList->begin(); tmp != nullptr; tmp = tmp->next()) {
        if (tmp->data() == user) { // 삭제하고자 하는 유저를 발견하면
            friendsList->drop(tmp); // 친구 목록에서 제거한다
            break;
        }
    }
}

/**
 * @brief 친구 리스트를 참조형으로 반환하는 메서드
 * @return 친구 리스트 (참조)
 */
List<User>& Friends::list() {
    return *friendsList;
}

/**
 * @brief 친구 목록 클래스 소멸자
 */
Friends::~Friends() {
    delete friendsList; // 동적으로 할당된 리스트 할당 해제
}