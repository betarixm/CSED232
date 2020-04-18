#include "User.h"
#include "IO.h"
#include "Comment.h"
#include "Post.h"

User::User(string &id, string &name, string &birthday, string &password)  {
    this->user_id.assign(id);
    this->name.assign(name);
    this->birthday.assign(birthday);
    this->user_password.assign(password);
    friendList = new Friends;
}

User::~User() {
    delete friendList;
}

void User::printProfile() {
    cout << "@" << user_id << " - " << name << " " << birthday << endl;
}
string& User::id() {
    return user_id;
}

bool User::auth(string &id, string &password) {
    return (this->user_id == id && this->user_password == password);
}

Friends& User::friends() {
    return *(this->friendList);
}

Node<User>* UserList::addUser(Stream &s)  {
    string infos[4];
    string msgs[4] = {"ID: ", "Name: ", "Birthday: ", "Password: "};

    for(int i = 0; i < 4; i++){
        cout << msgs[i];
        s.getLine(infos[i]);
    }

    for(auto user = list->begin(); user != nullptr; user = user->next()){
        if(user->data()->id() == infos[0]){
            cout << infos[0] << "is already exist id." << endl;
            return nullptr;
        }
    }

    auto* tmp = new User(infos[0], infos[1], infos[2], infos[3]);
    Node<User>* user = list->add(tmp);
    cout << "Registration Done!" << endl;
    return user;

}

Node<User>* UserList::signIn(Stream &s) {
    string id, password;
    cout << "ID: ";
    s.getLine(id);
    cout << "Password: ";
    s.getLine(password);

    for(Node<User>* user = list->begin(); user != nullptr; user = user->next()){
        if(user->data()->auth(id, password)){
            return user;
        }
    }
    return nullptr;
}

void UserList::removeUser(Node<User> *user, CommentList* commentList, PostList* postList)  {
    postList->removeUserPost(user->data());
    commentList->removeUserComment(user->data());
    for(auto tmp=list->begin(); tmp != nullptr; tmp=tmp->next()){
        tmp->data()->friends().removeFriendByUser(user->data());
    }
    list->drop(user);
    delete user->data();
}

Node<User>* UserList::getUserById(string& id){
    for(auto tmp = list->begin(); tmp!=nullptr; tmp=tmp->next()){
        if(id == tmp->data()->id()){
            return tmp;
        }
    }
    return nullptr;
}
