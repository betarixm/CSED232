#include "Post.h"
#include "User.h"
#include "Comment.h"
#include "Utils.h"
#include "IO.h"

/*
 * 명예서약 (Honor Code)
 * 나는 이 프로그래밍 과제를 다른 사람의 부적절한 도움 없이 완수하였습니다.
 * I completed this programming task without the improper help of others.
 */

Post::Post(User *user, string &content)  {
    this->post_user = user;
    this->content.assign(content);
}

Post::~Post() {
    delete likeList;
}

int Post::num_like() {
    return likeList->size();
}
void Post::printPost() {
    cout << "@" << post_user->id() << " (Like: " << num_like() << ")" << endl;
    cout << "- " << content << endl;
}

void Post::printPostWrapper(User* user, CommentList* commentList, Stream& s) {
    this->printPost();
    if(commentList->size() != 0){
        cout << "Reply: " << endl;
        commentList->printComment(this);
    }
    printLine();
    if(!isLiked(user)){
        add_like(user, s);
    }
    commentList->addComment(user, this, s);
}

bool Post::isLiked(User* target){
    for(auto tmp=likeList->begin(); tmp != nullptr; tmp=tmp->next()){
        if(tmp->data() == target){
            return true;
        }
    }
    return false;
}

void Post::add_like(User *target, Stream& s) {
    string input;
    cout << "Do you like it? (y/n): ";
    s.getLine(input);
    if(input == "y"){
        likeList->add(target);
    }
}

User* Post::user() {
    return this->post_user;
}
Node<Post>* PostList::addPost(User *user,  Stream& s)  {
    cout << "Post: ";
    string input;
    s.getLine(input);
    if(input.empty()){
        return nullptr;
    }
    Post* tmp = new Post(user, input);
    return this->list->add(tmp);
}

void PostList::removeUserPost(User* target){
    for(auto tmp=list->begin(); tmp != nullptr; tmp=tmp->next()){
        if(tmp->data()->user() == target){
            delete tmp->data();
            list->drop(tmp);
        }
    }
}

void PostList::printPostList(Stream& s, User* user, CommentList* commentList, List<User>& target) {
    if(target.size() == 0){
        cout << "There's nothing to show you." << endl;
        return;
    }
    while(true){
        int idx = 0;
        int input = -1;
        auto p_list = new Post*[this->size()];
        for(auto tmp=list->end(); tmp!=nullptr; tmp=tmp->prev()){
            if(target.exist(tmp->data()->user())){
                cout << idx << ". ";
                tmp->data()->printPost();
                p_list[idx++] = tmp->data();
            }
        }
        if(idx == 0){
            cout << "There's nothing to show you." << endl;
            delete[] p_list;
            return;
        }
        printLine();
        cout << "Select number: ";
        if(!s.getInt(input)){
            cout << "Invalid input!" << endl;
            delete[] p_list;
            return;
        }

        if(!(-2 < input && input < idx)){
            cout << "Invalid input!" << endl;
            delete[] p_list;
            return;
        }
        if(input == -1){
            delete[] p_list;
            return;
        } else {
            p_list[input]->printPostWrapper(user, commentList, s);
        }
    }

}

PostList::~PostList() {
    for(auto tmp=list->begin(); tmp != nullptr; tmp=tmp->next()){
        delete tmp->data();
        list->drop(tmp);
    }
    delete list;
}