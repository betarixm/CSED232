#ifndef CSED232_COMMENT_H
#define CSED232_COMMENT_H

#include "20190084.h"
#include "List.h"
#include <iostream>

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

class User; // 유저 클래스 프로토타이핑

class Post; // 게시물 클래스 프로토타이핑

class Stream; // 스트림 클래스 프로토타이핑

using namespace std;

/**
 * @brief 댓글을 저장하고 관리하는 클래스
 */
class Comment {
private:
    string comment_content; /// @brief 댓글 내용을 저장
    User *comment_user; /// @brief 댓글의 작성자를 저장
    Post *comment_post; /// @brief 어떤 게시물의 댓글인지 저장

public:
    /// @brief Comment 생성자
    Comment(User *user, string &content, Post *post); // 생성자 선언

    /// @brief 댓글을 출력하는 메서드
    void show();

    /// @brief 작성자를 반환하는 메서드
    User *user();

    /// @brief 게시물을 반환하는 메서드
    Post *post();
};
/**
 * @brief 댓글 목록을 관리하는 클래스
 */
class CommentList {
private:
    List<Comment> *list = new List<Comment>(MAX_COMMENT); /// @brief 댓글들이 저장될 리스트
public:
    /// @brief CommentList 소멸자
    ~CommentList();
    /// @brief 댓글을 추가하는 메서드
    Node<Comment> *addComment(User *user, Post *post, Stream &s);
    /// @brief 특정 사용자의 댓글을 삭제하는 메서드
    void removeUserComment(User *target);
    /// @brief 특정 게시글의 모든 댓글을 출력하는 메서드
    void printComment(Post *target);
    /// @brief 전체 댓글의 개수를 반환하는 메서드
    int size();
};

#endif //CSED232_COMMENT_H
