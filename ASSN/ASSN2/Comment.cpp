#include "Comment.h"

Comment::Comment(User *user, Post *post, string &content) {

}

CommentList::CommentList() {
    num_comments = 0;
    for(auto& comment: comments){
        comment = nullptr;
    }
}

Comment * CommentList::addComment(User *user, Post *post, string content) {
    if(num_comments >= MAX_COMMENT){
        return nullptr;
    } else {

    }
}

Post* CommentList::removeComment(Comment* target) {
    Post* post = nullptr;
    for(int i = 0; i < num_comments; i++){
        if(comments[i] != nullptr && comments[i] == target){
            post=comments[i]->post;
            delete(comments[i]);
            memmove(comments + i, comments + i + 1, sizeof(comments) * (MAX_COMMENT - i -1));
            comments[MAX_COMMENT - 1] = nullptr;
            num_comments--;
            break;
        }
    }

    return post;
}
