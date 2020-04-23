#ifndef CSED232_POST_H
#define CSED232_POST_H

#include "20190084.h"
#include <iostream>
#include "List.h"

/*
 *
 *  ██╗  ██╗ ██████╗ ███╗   ██╗ ██████╗ ██████╗
 *  ██║  ██║██╔═══██╗████╗  ██║██╔═══██╗██╔══██╗
 *  ███████║██║   ██║██╔██╗ ██║██║   ██║██████╔╝
 *  ██╔══██║██║   ██║██║╚██╗██║██║   ██║██╔══██╗
 *  ██║  ██║╚██████╔╝██║ ╚████║╚██████╔╝██║  ██║
 *  ╚═╝  ╚═╝ ╚═════╝ ╚═╝  ╚═══╝ ╚═════╝ ╚═╝  ╚═╝
 *
 *        ██████╗ ██████╗ ██████╗ ███████╗
 *       ██╔════╝██╔═══██╗██╔══██╗██╔════╝
 *       ██║     ██║   ██║██║  ██║█████╗
 *       ██║     ██║   ██║██║  ██║██╔══╝
 *       ╚██████╗╚██████╔╝██████╔╝███████╗
 *        ╚═════╝ ╚═════╝ ╚═════╝ ╚══════╝
 *
 *
 * 명예서약 (Honor Code)
 * 나는 이 프로그래밍 과제를 다른 사람의 부적절한 도움 없이 완수하였습니다.
 * I completed this programming task without the improper help of others.
 *
 */

using namespace std;

class User; // 유저 클래스 프로토타이핑

class Stream; // 입출력 클래스 프로토타이핑

class CommentList; // 댓글 클래스 프로토타이핑

class Friends; // 친구 클래스 프로토타이핑

/**
 * @brief Post 클래스
 * @details 게시글을 저장하고 관리하는 클래스이다.
 */
class Post {
private:
    string content; /// @brief 게시글의 내용을 저장
    User *post_user; /// @brief 게시글의 작성자를 저장
    List<User> *likeList = new List<User>(MAX_USER); /// @brief 좋아요 노드를 저장할 리스트 동적 할당
public:
    /// @brief Post 클래스 생성자
    Post(User *user, string &content);

    /// @brief Post 클래스 소멸자
    ~Post();

    /// @brief 게시물을 출력하는 메서드
    void printPost();

    /// @brief 게시물을 댓글까지 출력하는 메서드
    void printPostWrapper(User *user, CommentList *commentList, Stream &s);

    /// @brief 좋아요 개수를 반환하는 메서드
    int num_like();

    /// @brief 좋아요 옵션을 출력하는 메서드
    void add_like(User *target, Stream &s);

    /// @brief 주어진 유저가 좋아요를 눌렀는지 여부를 반환하는 메서드
    bool isLiked(User *target);

    /// @brief 게시글의 작성자를 반환하는 메서드
    User *user();

};

/**
 * @brief PostList 클래스
 * @details 게시글 목록을 저장하고 관리하는 클래스이다.
 */
class PostList {
private:
    List<Post> *list = new List<Post>(MAX_POST); /// @brief 게시글 노드를 저장할 배열을 동적할당
public:
    /// @brief 게시글을 추가하는 메서드
    Node<Post> *addPost(User *user, Stream &s);

    /// @brief 특정 유저의 게시글을 삭제하는 메서드
    void removeUserPost(User *target);

    /// @brief 게시글 목록을 출력하는 메서드
    void printPostList(Stream &s, User *user, CommentList *commentList, List<User> &target);

    /// @brief 게시글 개수를 반환하는 메서드
    int size();

    /// @brief PostList 소멸자
    ~PostList();
};


#endif //CSED232_POST_H
