#include "Contents.h"

Comment::Comment(User *user, string& content){
    this->user = user;
    this->content.assign(content);

}

Comment::~Comment() {
    (ptr_userCache != nullptr) && (ptr_userCache->parent->drop(ptr_userCache));
    (ptr_postCache != nullptr) && (ptr_postCache->parent->drop(ptr_postCache));
    (ptr_baseCache != nullptr) && (ptr_baseCache->parent->drop(ptr_baseCache));
}


Comment *CommentList::addComment(User *user, string &content, Post *post) {
    auto* tmp = new Comment(user, content);
    tmp->ptr_baseCache = list->add(tmp);
    if(tmp->ptr_baseCache == nullptr){
        delete tmp;
        return nullptr;
    } else {
        tmp->ptr_userCache = user->commentCache->add(tmp);
        tmp->ptr_postCache = post->commentCache->add(tmp);
        return tmp;
    }
}

void CommentList::removeComment(Comment* target) {
    delete target;
}


Post::Post(User *user, string &title, string &content) {
    this->user = user;
    this->title.assign(title);
    this->content.assign(content);
}

Post::~Post() {
    (baseCache_p != nullptr) && (baseCache_p->parent->drop(baseCache_p));
    (userCache_p != nullptr) && (userCache_p->parent->drop(userCache_p));
}

Post *PostList::addPost(User *user, string &title, string &content) {
    auto* tmp = new Post(user, title, content);
    tmp->baseCache_p = list->add(tmp);
    if(tmp->baseCache_p == nullptr){
        delete tmp;
        return nullptr;
    } else {
        tmp->userCache_p = user->postCache->add(tmp);
    }
    return nullptr;
}

void PostList::removePost(Post *target) {
    delete target;
}

User::User(string &id, string &name, string &birthday, string &password) {
    this->id.assign(id);
    this->name.assign(name);
    this->birthday.assign(birthday);
    this->password.assign(password);
}

Node<User>* UserList::addUser(Stream& s) {
    string infos[4];
    string msgs[4] = {"ID: ", "Name: ", "Birthday: ", "Password: "};

    for(int i = 0; i < 4; i++){
        cout << msgs[i];
        infos[i].assign(s.in<string>());
    }

    for(auto user = list->first; user != nullptr; user = user->next){
        if(user->data->id == infos[0]){
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
    id.assign(s.in<string>());
    cout << "Password: ";
    password.assign(s.in<string>());

    for(auto user = list->first; user != nullptr; user = user->next){
        if(user->data->id == id && user->data->password == password){
            return user;
        }
    }
    return nullptr;
}

User* UserList::removeUser(Node<User>* user) {
    list->drop(user);
}
