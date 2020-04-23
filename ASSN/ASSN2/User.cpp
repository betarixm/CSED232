#include "User.h"
#include "IO.h"
#include "Comment.h"
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
 * @brief 유저 클래스 생성자
 * @param id 유저의 아이디
 * @param name 유저의 이름
 * @param birthday 유저의 생일
 * @param password 유저의 비밀번호
 */
User::User(string &id, string &name, string &birthday, string &password) {
    // 입력된 정보들을 유저 클래스에 저장한다.
    this->user_id.assign(id);
    this->name.assign(name);
    this->birthday.assign(birthday);
    this->user_password = hash<string>{}(password); // 유저의 비밀번호는 보안을 위해 해시를 이용하여 저장한다.
    friendList = new Friends; // 친구 목록 리스트를 동적할당한다.
}

/**
 * @brief 유저 클래스 소멸자
 * @details 동적할당된 메모리를 해제한다.
 */
User::~User() {
    delete friendList; // 동적할당된 친구 목록 리스트를 해제한다.
}

/**
 * @brief 프로필을 출력하는 클래스
 */
void User::printProfile() {
    // 유저의 아이디, 이름, 생일을 출력한다.
    cout << "@" << user_id << " - " << name << " " << birthday << endl;
}

/**
 * @brief 유저의 아이디를 반환하는 클래스
 * @return 유저의 아이디
 */
string &User::id() {
    return user_id; // 유저의 아이디를 참조형으로 반환한다.
}


/**
 * @brief 유저를 인증하는 클래스
 * @param id 유저의 아이디
 * @param password 유저의 비밀번호
 * @return 인증 성공 여부
 */
bool User::auth(string &id, string &password) {
    // 입력된 아이디와, 해시된 비밀번호를 비교하여 인증을 수행한다.
    return (this->user_id == id && this->user_password == hash<string>{}(password));
}

/**
 * @brief 유저의 친구 리스트를 반환하는 클래스
 * @return 유저의 친구 리스트
 */
Friends &User::friends() {
    return *(this->friendList); // 유저의 친구 리스트를 참조형으로 반환한다.
}

/**
 * @brief 유저 리스트에 유저를 추가하는 메서드
 * @param s 입출력 wrapper 오브젝트 참조
 * @return 추가된 사용자의 주소
 */
Node<User> *UserList::addUser(Stream &s) {
    string infos[4];
    string msgs[4] = {"ID: ", "Name: ", "Birthday: ", "Password: "}; // 출력될 메시지 목록

    // 사용자 정보를 입력받는다.
    for (int i = 0; i < 4; i++) {
        cout << msgs[i];
        s.getLine(infos[i]);
    }

    // 이미 존재하는 아이디인지 확인한다.
    for (auto user = list->begin(); user != nullptr; user = user->next()) {
        if (user->data()->id() == infos[0]) {
            // 이미 존재하는 아이디라면 에러 메시지를 띄우고 회원 가입을 취소한다.
            cout << infos[0] << "is already exist id." << endl;
            return nullptr;
        }
    }

    // 새로운 유저를 동적 할당 하고, 리스트에 추가한다.
    auto tmp = new User(infos[0], infos[1], infos[2], infos[3]);
    Node<User> *user = list->add(tmp);

    // 안내메시지 출력
    cout << "Registration Done!" << endl;
    return user; // 새로 등록된 유저의 주소를 반환한다.

}

/**
 * @brief 로그인 메서드
 * @return 로그인에 성공한 유저의 주소
 */
Node<User> *UserList::signIn(Stream &s) {
    // 사용자로부터 아이디와 비밀번호를 입력받는다.
    string id, password;
    cout << "ID: ";
    s.getLine(id);
    cout << "Password: ";
    s.getLine(password);

    for (Node<User> *user = list->begin(); user != nullptr; user = user->next()) {
        // 리스트를 순회하면서 인증을 진행한다.
        if (user->data()->auth(id, password)) {
            return user; // 인증에 성공하면 사용자를 반환한다.
        }
    }
    return nullptr; // 실패할 경우 nullptr을 환한다.
}

/**
 * @brief 유저를 삭제하는 메서드
 * @param user 삭제될 유저의 노드 주소
 * @param commentList 댓글 리스트 주소
 * @param postList 게시글 리스트 주소
 */
void UserList::removeUser(Node<User> *user, CommentList *commentList, PostList *postList) {
    postList->removeUserPost(user->data()); // 게시글 리스트에서 유저의 게시글 삭제
    commentList->removeUserComment(user->data()); // 댓글 리스트에서 유저의 댓글 삭제

    for (auto tmp = list->begin(); tmp != nullptr; tmp = tmp->next()) {
        // 유저 리스트를 탐색하면서 어떤 유저의 친구로 등록되어 있다면, 친구 삭제.
        tmp->data()->friends().removeFriendByUser(user->data());
    }

    delete user->data(); // 동적 할당 해제
    list->drop(user); // 리스트에서 유저 삭제
}

/**
 * @brief ID로 유저를 찾아서 반환하는 메서드
 * @param id 찾을 유저의 아이디
 * @return 찾은 유저의 주소
 */
Node<User> *UserList::getUserById(string &id) {
    for (auto tmp = list->begin(); tmp != nullptr; tmp = tmp->next()) {
        // 유저리스트를 순회하면서 아이디를 조회하고, 찾는데 성공할 경우 유저를 반환한다.
        if (id == tmp->data()->id()) {
            return tmp;
        }
    }
    return nullptr; // 못 찾았을 경우 nullptr을 반환
}

/**
 * @brief UserList 소멸자
 * @details 동적할당된 메모리를 해제한다.
 */
UserList::~UserList() {
    // 유저 리스트를 순회하면서 모든 유저를 삭제한다.
    for (auto tmp = list->begin(); tmp != nullptr; tmp = list->drop(tmp)) {
        delete tmp->data(); // 동적할당 해제
    }
    delete list; // 리스트도 삭제한다.
}
