#ifndef CSED232_USER_H
#define CSED232_USER_H

#include "20190084.h"
#include "List.h"
#include "Post.h"
#include "Comment.h"
#include "IO.h"

using namespace std;

class User;
class UserList;

class User {
public:
    List<Comment>* commentCache = new List<Comment>(MAX_COMMENT);
    List<Post>* postCache = new List<Post>(MAX_POST);
    List<User>* friends = new List<User>(MAX_USER);

    string id;
    string name;
    string birthday;
    string password;

    User(string& id, string& name, string& birthday, string& password);
};

class UserList {
private:
    List<User>* list = new List<User>(MAX_USER);
public:
    Node<User>* addUser(Stream& s);
    Node<User>* signIn(Stream& s);
    User* removeUser(Node<User>* user);
};


#endif //CSED232_USER_H
