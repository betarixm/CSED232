#include "Comment.h"
#include "User.h"
#include "Post.h"
#include "IO.h"

Comment::Comment(User *user, string &content, Post* post) {
    this->comment_user = user;
    this->comment_content.assign(content);
    this->comment_post = post;
};

void Comment::show() {
    cout << "@" << this->comment_user->id() << " - " << this->comment_content << endl;
}


Node<Comment> * CommentList::addComment(User *user, Post *post, Stream& s) {
    string input;
    cout << "Write Comment: ";
    s.getline(input);
    if(input.empty())
        return nullptr;
    auto* tmp = new Comment(user, input, post);
    return this->list->add(tmp);
}

void CommentList::removeUserComment(User* target) {
    for(auto tmp=list->begin(); tmp != nullptr; tmp=tmp->next()){
        if(tmp->data()->user() == target || tmp->data()->post()->user() == target){
            list->drop(tmp);
            delete tmp->data();
        }
    }
}
void CommentList::printComment(Post* target) {
    for(auto tmp = list->end(); tmp != nullptr; tmp=tmp->prev()){
        if(tmp->data()->post() == target){
            tmp->data()->show();
        }
    }
}

int CommentList::size() {
    return list->size();
}