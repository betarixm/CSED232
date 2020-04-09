#ifndef CSED232_COMMENT_H
#define CSED232_COMMENT_H

#include "20190084.h"

class Comment {
public:
    string content;
    User* user;
    Post* post;

    List* listRef;
    List* postRef;
    List* userRef;

    Comment(User *user, Post *post, string &content);
    ~Comment();
};

class CommentList{
private:
    int num_comments;
    Comment* first;
    Comment* last;

public:
    Comment* comments[MAX_COMMENT] = {};

    CommentList();
    Comment* addComment(User* user, Post* post, String content);
    Post* removeComment(Comment* target);
};

#endif //CSED232_COMMENT_H
