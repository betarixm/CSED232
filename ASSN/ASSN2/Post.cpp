#include "Post.h"

Post::Post(string &title, string &content, User* author){
    this->title.assign(title);
    this->content.assign(content);
    this->author = author;
    this->num_comments = 0;
    for(auto& comment : comments){
        comment = nullptr;
    }
}

void Post::addComment(Comment *newComment) {
    comments[num_comments++] = newComment;
}

void Post::removeComment(Comment *target, CommentList& commentList) {
    for(int i = 0; i<num_comments; i++){
        if(comments[i] != nullptr && comments[i] == target){
            commentList.removeComment(target);
            memmove(comments+i, comments+i+1, sizeof(comments) * (MAX_COMMENT - i - 1));
            num_comments--;
            comments[MAX_COMMENT - 1] = nullptr;
        }
    }
}

PostList::PostList(){
    for(auto& post : posts){
        post= nullptr;
    }
    num_posts = 0;
};

Post* PostList::addPost(User *author, string title, string content) {
    if(num_posts >= MAX_POST){
        return nullptr;
    } else {
        auto* post = new Post(title, content, author);
        memmove(posts + 1, posts, sizeof(posts) * (MAX_POST - 1));
        posts[0] = post;
        return post;
    }
}

User* PostList::removePost(Post *target) {
    User* user = nullptr;
    for(int i=0; i < num_posts; i++){
        if(posts[i] != nullptr && posts[i] == target){
            user = posts[i]->author;
            delete(posts[i]);
            memmove(posts + i, posts + i + 1, sizeof(posts) *(MAX_POST - i - 1));
            break;
        }
    }

    return user;
}