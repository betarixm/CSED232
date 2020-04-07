//
// Created by PBS on 2020-04-08.
//

#ifndef CSED232_POST_H
#define CSED232_POST_H

#include "20190084.h"

class Post {
private:
    int num_comments;
public:
    string title;
    string content;
    User* author;
    Comment* comments[MAX_COMMENT] = {};
    Post(string &title, string &content, User* author);

    void addComment(Comment * newComment);
    void removeComment(Comment* target, CommentList& commentList);
};

class PostList {
private:
    int num_posts;
public:
    Post* posts[MAX_POST] = {};
    PostList();
    Post* addPost(User* author, string title, string content);
    User* removePost(Post* target);
};


#endif //CSED232_POST_H
