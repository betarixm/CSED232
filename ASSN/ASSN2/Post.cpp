#include "Post.h"
#include "User.h"
#include "Comment.h"
#include "Utils.h"
#include "IO.h"

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
 * @brief Post 클래스 생성자
 * @param user 게시물의 작성자
 * @param content 게시물의 내용
 */
Post::Post(User *user, string &content) {
    this->post_user = user; // 게시물의 작성자를 저장한다.
    this->content.assign(content); // 게시물의 내용을 할당한다.
}

/**
 * @brief Post 클래스 소멸자
 */
Post::~Post() {
    delete likeList; // 동적 할당된 리스트를 할당 해제한다.
}

/**
 * @brief 좋아요 개수를 반환하는 메서드
 * @return 좋아요 개수를 반환한다.
 */
int Post::num_like() {
    return likeList->size(); // likeList의 크기를 반환하여 좋아요의 개수를 반환해준다.
}

/**
 * @brief 게시물을 출력하는 메서드
 */
void Post::printPost() {
    // 게시물의 작성자, 좋아요 개수, 내용을 출력한다.
    cout << "@" << post_user->id() << " (Like: " << num_like() << ")" << endl;
    cout << "- " << content << endl;
}

/**
 * @brief 게시물을 댓글까지 출력하는 메서드
 * @param user 현재 유저
 * @param commentList 댓글 리스트 주소
 * @param s 입출력 wrapper 오브젝트 참조
 */
void Post::printPostWrapper(User *user, CommentList *commentList, Stream &s) {
    this->printPost(); // 게시물을 출력
    if (commentList->size() != 0) {
        // 댓글이 있다면 댓글을 출력한다.
        cout << "Reply: " << endl;
        commentList->printComment(this);
    } else {
        // 댓글이 없다면 안내 메시지를 출력한다.
        cout << "There are no comments on this post.. :(" << endl;
    }
    printLine();

    // 사용자가 좋아요를 누른 적이 없다면, 좋아요 옵션을 출력한다.
    if (!isLiked(user)) {
        add_like(user, s);
    }

    // 댓글 추가 모드를 실행한다.
    commentList->addComment(user, this, s);
}

/**
 * @brief 주어진 유저가 좋아요를 눌렀는지 여부를 반환하는 메서드
 * @param target 체크할 유저
 * @return 좋아요 누름 여부
 */
bool Post::isLiked(User *target) {
    for (auto tmp = likeList->begin(); tmp != nullptr; tmp = tmp->next()) {
        // 게시물의 likeList를 순회하면서 좋아요를 누른 적이 있다면 true를 반환한다.
        if (tmp->data() == target) {
            return true;
        }
    }
    // 아닐 경우 false를 반환한다.
    return false;
}

/**
 * @brief 좋아요 옵션을 출력하는 메서드
 * @param target 좋아요를 누를 유저
 * @param s 입출력 wrapper 오브젝트 참조
 */
void Post::add_like(User *target, Stream &s) {
    string input;
    // 메시지 출력
    cout << "Do you like it? (y/n): ";
    s.getLine(input);
    if (input == "y") {
        // 사용자의 입력이 "y"라면, likeList에 추가한다.
        likeList->add(target);
    }
}

/**
 * @brief 게시글의 작성자를 반환하는 메서드
 * @return 작성자의 주소
 */
User *Post::user() {
    return this->post_user; // 작성자의 주소를 반환한다.
}

/**
 * @brief 게시글을 추가하는 메서드
 * @param user 추가할 사용자의 주소
 * @param s 입출력 wrapper 오브젝트 참조
 * @return 추가된 게시글의 주소를 반환
 */
Node<Post> *PostList::addPost(User *user, Stream &s) {
    // 안내메세지 출력
    cout << "Post: ";
    string input;

    // 사용자로부터 내용을 입력받는다.
    s.getLine(input);

    // 내용이 비어있다면 취소한다.
    if (input.empty()) {
        return nullptr;
    }

    // 내용이 있다면 새로운 게시글로 등록한다.
    Post *tmp = new Post(user, input);
    return this->list->add(tmp); // 새 게시글의 주소 반환
}

/**
 * @brief 특정 유저의 게시글을 삭제하는 메서드
 * @param target 삭제할 유저의 주소
 */
void PostList::removeUserPost(User *target) {
    for (auto tmp = list->begin(); tmp != nullptr;) {
        // 게시글 리스트를 순회한다.
        if (tmp->data()->user() == target) {
            // 만약 삭제할 유저의 게시글이라면,
            delete tmp->data(); // 할당을 해제하고,
            tmp = list->drop(tmp); // 리스트에서 삭제한다. drop의 반환값은 삭제된 노드의 다음 노드의 주소이다.
        } else {
            // 아니라면, 다음 노드로 설정한다.
            tmp = tmp->next();
        }
    }
}

/**
 * @brief 게시글 목록을 출력하는 메서드
 * @param s 입출력 wrapper 오브젝트 참조
 * @param user 현재 유저의 주소
 * @param commentList 댓글 목록의 주소
 * @param target target에 있는 유저만의 글을 추가한다.
 */
void PostList::printPostList(Stream &s, User *user, CommentList *commentList, List<User> &target) {
    // 타겟 유저 리스트가 비어있을 경우, 안내 메시지 출력 후 종료
    if (target.size() == 0) {
        cout << "There's nothing to show you." << endl;
        return;
    }

    // 명시적으로 피드를 벗어날 때 까지 피드 출력을 반복한다.
    while (true) {
        int idx = 0;
        int input = -1;
        auto p_list = new Post *[this->size()]; /// @brief 타겟에 맞는 게시물 목록을 캐싱할 배열
        for (auto tmp = list->end(); tmp != nullptr; tmp = tmp->prev()) {
            // 최신 글을 먼저 출력하기 위해 뒤에서 부터 순회한다.

            if (target.exist(tmp->data()->user())) {
                // 게시글의 작성자가 타겟 리스트에 존재한다면, 그 게시글을 출력한다.
                cout << idx << ". ";
                tmp->data()->printPost();
                // 해당 게시글을 캐시에 추가한다.
                p_list[idx++] = tmp->data();
            }
        }

        if (idx == 0) {
            // 타겟에 맞는 게시글을 하나도 찾지 못할 경우 메시지를 출력한다.0
            cout << "There's nothing to show you." << endl;
            delete[] p_list; // 캐시 할당 해제
            return;
        }
        printLine();

        // 게시글 번호를 선택하게 한다.
        cout << "Select number: ";
        if (!(s.getInt(input)) && (-2 < input && input < idx)) {
            // 잘못된 문자 입력일 경우 메시지를 출력시키고 피드를 종료한다.
            cout << "Invalid input!" << endl;
            delete[] p_list; // 캐시 할당 해제
            return;
        }

        if (input == -1) {
            // 입력이 -1일 경우 피드를 종료한다.
            delete[] p_list; // 캐시 할당 해제
            return;
        } else {
            // 캐시로부터 게시글을 조회해서 출력한다.
            p_list[input]->printPostWrapper(user, commentList, s);
        }
    }

}

/**
 * @brief 게시글 개수를 반환하는 메서드
 * @return 게시글 리스트의 크기를 반환한다.
 */
int PostList::size() {
    return list->size(); // 게시글 리스트의 크기 반환
}

/**
 * @brief PostList 소멸자
 * @details 동적할당된 게시글 관련 정보들을 해제한다.
 */
PostList::~PostList() {
    // 리스트를 순회화면서 모든 할당된 게시글을 해제한다.
    for (auto tmp = list->begin(); tmp != nullptr; tmp = list->drop(tmp)) {
        delete tmp->data();
    }
    delete list; // 리스트 또한 할당 해제한다.
}