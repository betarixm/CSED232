#ifndef CSED232_COMMENT_H
#define CSED232_COMMENT_H

#include "20190084.h"
#include "List.h"
#include <iostream>

/*
 * 명예서약 (Honor Code)
 * 나는 이 프로그래밍 과제를 다른 사람의 부적절한 도움 없이 완수하였습니다.
 * I completed this programming task without the improper help of others.
 */

class User;

class Post;

class Stream;

using namespace std;

class Comment {
private:
    string comment_content;
    User *comment_user;
    Post *comment_post;

public:
    Comment(User *user, string &content, Post *post);

    void show();

    User *user() {
        return comment_user;
    }

    Post *post() {
        return comment_post;
    }
};

class CommentList {
private:
    List<Comment> *list = new List<Comment>(MAX_COMMENT);
public:
    ~CommentList();

    Node<Comment> *addComment(User *user, Post *post, Stream &s);

    void removeUserComment(User *target);

    void printComment(Post *target);

    int size();
};

#endif //CSED232_COMMENT_H
