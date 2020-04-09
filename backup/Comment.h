#ifndef CSED232_COMMENT_H
#define CSED232_COMMENT_H

#include "20190084.h"
#include "User.h"
#include "List.h"
#include "Post.h"

using namespace std;

class Comment;
class CommentList;

class Comment {
public:
    string content;
    User* user;

    Node<Comment>* ptr_baseCache = nullptr;
    Node<Comment>* ptr_userCache = nullptr;
    Node<Comment>* ptr_postCache = nullptr;

    Comment(User *user, string& content);
    ~Comment();
};

class CommentList{
public:
    List<Comment>* list = new List<Comment>(MAX_COMMENT);
    Comment* addComment(User* user, string& content, Post* post);
    void removeComment(Comment* target);
};

#endif //CSED232_COMMENT_H
