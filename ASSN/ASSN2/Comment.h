#ifndef CSED232_COMMENT_H
#define CSED232_COMMENT_H

#include "20190084.h"
#include "List.h"
#include <iostream>

/*
 * 명예서약 (Honor Code)
 * 나는 이 프로그래밍 과제를 다른 사람의 부적절한 도움 없이 완수하였습니다.
 * I completed this programming task without the improper help of others.
 */

class User; // 유저 클래스 프로토타이핑

class Post; // 게시물 클래스 프로토타이핑

class Stream; // 스트림 클래스 프로토타이핑

using namespace std;

class Comment { // 댓글 클래스
private:
    string comment_content; // 댓글 내용을 저장
    User *comment_user; // 댓글의 작성자를 저장
    Post *comment_post; // 어떤 게시물의 댓글인지 저장

public:
    Comment(User *user, string &content, Post *post); // 생성자 선언

    void show(); // 댓글을 출력하는 메서드

    User *user() { // 댓글의 작성자를 반환
        return comment_user;
    }

    Post *post() { // 어떤 게시물의 댓글인지 반환
        return comment_post;
    }
};

class CommentList { // 댓글 목록을 관리하는 클래스
private:
    List<Comment> *list = new List<Comment>(MAX_COMMENT); // 댓글들이 저장될 리스트
public:
    ~CommentList(); // CommentList 소멸자

    Node<Comment> *addComment(User *user, Post *post, Stream &s); // 새로운 댓글을 등록하는 메서드

    void removeUserComment(User *target); // 특정 사용자의 댓글을 삭제하는 메서드

    void printComment(Post *target); // 특정 게시글의 댓글을 출력하는 메서드

    int size(); // 전체 댓글의 수를 반환하는 메서드
};

#endif //CSED232_COMMENT_H
