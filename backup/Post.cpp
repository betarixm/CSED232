#include "Post.h"

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
