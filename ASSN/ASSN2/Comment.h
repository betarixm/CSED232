#ifndef CSED232_COMMENT_H
#define CSED232_COMMENT_H

#include "20190084.h"

using namespace std;

class Comment {
public:
    string content;
    User* user;
    Post* post;
    Comment(User* user, Post* post, string& content);
};

class CommentList{
private:
    int num_comments;
public:
    Comment* comments[MAX_COMMENT] = {};

    CommentList();
    Comment* addComment(User* user, Post* post, String content);
    Post* removeComment(Comment* target);
};

#endif //CSED232_COMMENT_H
