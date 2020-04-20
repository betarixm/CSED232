#include "Comment.h"
#include "User.h"
#include "Post.h"
#include "IO.h"

/*
 * 명예서약 (Honor Code)
 * 나는 이 프로그래밍 과제를 다른 사람의 부적절한 도움 없이 완수하였습니다.
 * I completed this programming task without the improper help of others.
 */

Comment::Comment(User *user, string &content, Post *post) {
    this->comment_user = user;
    this->comment_content.assign(content);
    this->comment_post = post;
}

void Comment::show() {
    cout << "@" << this->comment_user->id() << " - " << this->comment_content << endl;
}


Node<Comment> *CommentList::addComment(User *user, Post *post, Stream &s) {
    string input;
    cout << "Write Comment: ";
    s.getLine(input);
    if (input.empty())
        return nullptr;
    auto *tmp = new Comment(user, input, post);
    return this->list->add(tmp);
}

void CommentList::removeUserComment(User *target) {
    for (auto tmp = list->begin(); tmp != nullptr;) {
        if (tmp->data()->user() == target || tmp->data()->post()->user() == target) {
            delete tmp->data();
            tmp = list->drop(tmp);
        } else {
            tmp = tmp->next();
        }
    }
}

void CommentList::printComment(Post *target) {
    for (auto tmp = list->end(); tmp != nullptr; tmp = tmp->prev()) {
        if (tmp->data()->post() == target) {
            tmp->data()->show();
        }
    }
}

int CommentList::size() {
    return list->size();
}

CommentList::~CommentList() {
    for (auto tmp = list->begin(); tmp != nullptr; tmp = list->drop(tmp)) {
        delete tmp->data();
    }
    delete list;
}