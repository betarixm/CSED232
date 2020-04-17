#ifndef CSED232_USER_H
#define CSED232_USER_H
#include "20190084.h"
#include <iostream>
#include "List.h"
#include "Friends.h"

using namespace std;

class Post;
class PostList;
class Comment;
class CommentList;
class Stream;
class Friends;
class User {
private:
    string user_id;
    string name;
    string birthday;
    string user_password;
    Friends* friendList;

public:

    User(string &id, string &name, string &birthday, string &password);
    ~User();
    string& id();
    void printProfile();
    bool auth(string& id, string& password);
    Friends& friends();
};

class UserList {
private:
    List<User>* list = new List<User>(MAX_USER);
public:
    Node<User>* addUser(Stream& s);
    Node<User>* signIn(Stream &s);
    void removeUser(Node<User> *user, CommentList* commentList, PostList* postList);
    Node<User>* getUserById(string& id);
};


#endif //CSED232_USER_H
