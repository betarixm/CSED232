#include "Comment.h"

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

