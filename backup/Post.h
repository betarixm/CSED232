#ifndef CSED232_POST_H
#define CSED232_POST_H

#include "20190084.h"
#include <iostream>
#include "List.h"
#include "User.h"
#include "Comment.h"

using namespace std;

class Post;
class PostList;

class Post {
public:
    List<Comment>* commentCache = new List<Comment>(MAX_COMMENT);
    string title;
    string content;
    User* user;

    Node<Post>* baseCache_p = nullptr;
    Node<Post>* userCache_p = nullptr;

    Post(User *user, string& title, string& content);
    ~Post();
};

class PostList {
public:
    List<Post>* list = new List<Post>(MAX_POST);
    Post* addPost(User* user, string& title, string& content);
    void removePost(Post* target);
};


#endif //CSED232_POST_H
