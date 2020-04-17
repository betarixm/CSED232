#ifndef CSED232_CONTENTS_H
#define CSED232_CONTENTS_H
#include <iostream>
#include "List.h"
#include "IO.h"
#include "20190084.h"

using namespace std;
class Comment;
class CommentList;
class Post;
class PostList;
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
class Post {
private:
    List<Comment>* commentCache = new List<Comment>(MAX_COMMENT);
    string content;
    User* user;
public:
    int like = 0;
    Node<Post>* baseCache_p = nullptr;
    Node<Post>* userCache_p = nullptr;

    Post(User *user, string& content);
    ~Post();
    void printPost(){
        cout << "@" << user->id << "(Like: " << like << ")" << endl;
        cout << "- " << content << endl;
    }


};

class PostList {
private:
    int num_post;
public:
    List<Post>* list = new List<Post>(MAX_POST);
    Post* addPost(User* user, string& content);
    void removePost(Post* target);

    void printAllPost(){
        int idx = 0;
        auto p_list = new Post*[num_post];
        for(auto node = list->last; node != nullptr; node=node->prev){
            cout << idx++ << ". ";
            node->data->printPost();
            p_list[idx] = node->data;
        }
    }
    void inputPost(Stream& s, Node<User>* userNode){
        cout << "Post: ";
        string content;
        content.assign(s.in<string>());
        addPost(userNode->data, content);
        num_post++;
    }
};
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


#endif //CSED232_CONTENTS_H
