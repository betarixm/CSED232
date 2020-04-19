#ifndef CSED232_POST_H
#define CSED232_POST_H
#include "20190084.h"
#include <iostream>
#include "List.h"

/*
 * 명예서약 (Honor Code)
 * 나는 이 프로그래밍 과제를 다른 사람의 부적절한 도움 없이 완수하였습니다.
 * I completed this programming task without the improper help of others.
 */

using namespace std;

class User;
class Stream;
class CommentList;
class Friends;

class Post {
private:
    string content;
    User* post_user;
    List<User>* likeList = new List<User>(MAX_USER);
public:
    Post(User *user, string &content);
    ~Post();
    void printPost();
    void printPostWrapper(User* user, CommentList* commentList, Stream& s);
    int num_like();
    void add_like(User* target, Stream& s);
    bool isLiked(User* target);
    User* user();

};

class PostList {
private:
    List<Post>* list = new List<Post>(MAX_POST);
public:
    Node<Post>* addPost(User *user, Stream& s);
    void removeUserPost(User* target);
    void printPostList(Stream& s, User* user, CommentList* commentList, List<User>& target);
    int size(){
        return list->size();
    }
    ~PostList();
};


#endif //CSED232_POST_H
