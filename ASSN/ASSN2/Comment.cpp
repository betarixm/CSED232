#include "Comment.h"
#include "User.h"
#include "Post.h"
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
 * @brief Comment 생성자
 * @param user 댓글 작성자
 * @param content 댓글 내용
 * @param post 어떤 게시물의 댓글인지
 */
Comment::Comment(User *user, string &content, Post *post) {
    this->comment_user = user; // 어떤 유저가 작성한 댓글인지 기록
    this->comment_content.assign(content); // 댓글 내용 저장
    this->comment_post = post; // 어떤 게시물의 댓글인지 기록
}

/**
 * @brief 댓글을 출력하는 메서드
 */
void Comment::show() {
    cout << "@" << this->comment_user->id() << " - " << this->comment_content << endl;
}

/**
 * @brief 작성자를 반환하는 메서드
 * @return 작성자의 주소
 */
User* Comment::user() {
    return comment_user; // 작성자의 주소 반환
}

/**
 * @brief 게시물을 반환하는 메서드
 * @return 게시물의 주소
 */
Post* Comment::post() {
    return comment_post; // 게시물의 주소 반환
}
/**
 * @brief 댓글을 추가하는 메서드
 * @param user 댓글 작성자
 * @param post 어떤 게시물의 댓글인지
 * @param s 입출력 wrapper 오브젝트 참조
 * @return 새로 만든 댓글의 주소
 */
Node<Comment> *CommentList::addComment(User *user, Post *post, Stream &s) {
    string input; // 입력 받을 문자열 변수
    // 사용자에게 댓글 내용 입력받음
    cout << "Write Comment: ";
    s.getLine(input); // Stream Wrapper 이용.

    if (input.empty()) { // 만약 결과가 비어있다면
        return nullptr; // nullptr을 반환한다.
    }

    // 입력받은 값으로 새로운 댓글을 동적 할당하고, 리스트에 추가한다.
    auto *tmp = new Comment(user, input, post);
    return this->list->add(tmp);
}

/**
 * @brief 특정 사용자의 댓글을 삭제하는 메서드
 * @param target 삭제할 사용자 지정
 */
void CommentList::removeUserComment(User *target) {
    for (auto tmp = list->begin(); tmp != nullptr;) { // 댓글을 순회하면서
        if (tmp->data()->user() == target || tmp->data()->post()->user() == target) {
            // 만약 삭제하고자 하는 유저의 댓글이라면 삭제한다.
            delete tmp->data();
            tmp = list->drop(tmp); // list.drop은 삭제한 노드의 다음 노드의 주소를 반환한다.
        } else {
            // 삭제하고자 하는 유저의 댓글이 아니라면 다음 댓글을 체크한다.
            tmp = tmp->next();
        }
    }
}

/**
 * @brief 특정 게시글의 모든 댓글을 출력하는 메서드
 * @param target 출력할 게시글 지정
 */
void CommentList::printComment(Post *target) {
    for (auto tmp = list->end(); tmp != nullptr; tmp = tmp->prev()) {
        // 최신순으로 출력하기 위해 리스트의 뒤에서부터 출력한다.
        if (tmp->data()->post() == target) { // 만약 출력하고자 하는 게시글이라면
            tmp->data()->show(); // 댓글을 출력한다
        }
    }
}

/**
 * @brief 전체 댓글의 개수를 반환하는 메서드
 * @return 댓글의 전체 개수
 */
int CommentList::size() {
    return list->size(); // 댓글의 전체 개수를 반환한다.
}

/**
 * @brief CommentList 소멸자
 */
CommentList::~CommentList() { // 소멸자
    // CommentList가 소멸될 때 동적 할당된 메모리를 해제하고자 한다.
    for (auto tmp = list->begin(); tmp != nullptr; tmp = list->drop(tmp)) { // 리스트를 순회하면서
        delete tmp->data(); // 할당된 메모리를 해제한다.
    }
    delete list; // 동적할당 된 리스트 오브젝트 또한 할당 해제한다.
}