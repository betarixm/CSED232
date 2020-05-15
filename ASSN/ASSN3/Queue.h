#ifndef CSED232_QUEUE_H
#define CSED232_QUEUE_H

#include "Node.h"

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

template <typename T>
class Node;

template <typename T>
/**
 * @brief 큐 구현 클래스
 * @tparam T 큐에 저장될 데이터 타입
 */
class Queue {
private:
    Node<T>* begin = nullptr; /// @brief 큐의 시작 노드
    Node<T>* end = nullptr; /// @brief 큐의 마지막 노드
    int queue_size = 0; /// @brief 큐 크기

public:
    /// @brief 큐의 크기를 반환하는 메서드
    int size(){
        return queue_size;
    }

    /// @brief 큐에 데이터를 추가하는 메서드
    void push(T data){
        // 새로운 노드 생성
        auto tmp = new Node<T>(data, begin, nullptr);

        // 시작 노드가 비어있지 않다면 시작노드의 이전 값을 새로운 노드로 등록
        if(begin != nullptr) begin->prev() = tmp;

        // 시작 노드를 새로운 노드로 설정
        begin = tmp;

        // 빈 큐라면 마지막 노드도 새로운 노드로 설정
        if(queue_size == 0) end = tmp;

        // 큐 사이즈 증가
        queue_size++;
    }

    /// @brief 큐에서 데이터를 제거하는 메서드
    bool pop(T& input){
        // 마지막 노드가 없다면 false를 반환
        if (end == nullptr) return false;

        // 마지막 노드 주소 백업
        auto tmp = end;

        // input에 데이터 복사
        input = end->data();

        // 마지막 노드를 마지막 노드의 이전 노드로 설정
        end = end->prev();

        // 변경된 마지막 노드가 빈 노드가 아니라면, 마지막 노드의 다음 노드의 주소를 nullptr으로 지정
        if(end != nullptr) { end->next() = nullptr; }

        // 빈 큐가 될 예정이라면, 시작 노드도 nullptr으로 초기화
        if(queue_size == 1) { begin = nullptr; }

        // 동적 할당된 노드 삭제
        delete tmp;

        // 큐 사이즈 감소
        queue_size--;

        // pop에 성공했음을 반환
        return true;
    }

    /// @brief 큐를 복사하는 = 오버로딩
    Queue&operator=(Queue const& param){
        if(this != &param){
            // 큐 크기, 시작 노드, 마지막 노드를 복사
            queue_size = param.queue_size;
            begin = param.begin;
            end = param.end;
        }
        return *this;
    }
};


#endif //CSED232_QUEUE_H
