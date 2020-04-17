#ifndef CSED232_COMMENT_H
#define CSED232_COMMENT_H
#include "20190084.h"
#include "List.h"
#include <iostream>

class User;
class Post;
class Stream;

using namespace std;

class Comment {
private:
    string comment_content;
    User* comment_user;
    Post* comment_post;

public:
    Comment(User *user, string& content, Post* post);
    void show();
    string& content(){
        return comment_content;
    }

    User* user(){
        return comment_user;
    }

    Post* post(){
        return comment_post;
    }
};

class CommentList{
private:
    List<Comment>* list = new List<Comment>(MAX_COMMENT);
public:
    Node<Comment> * addComment(User *user, Post *post, Stream& s);
    void removeUserComment(User* target);
    void printComment(Post* target);
    int size();
};
#endif //CSED232_COMMENT_H
