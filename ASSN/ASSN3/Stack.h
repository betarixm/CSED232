#ifndef CSED232_STACK_H
#define CSED232_STACK_H

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
 * @brief 스택 구현 클래스
 * @tparam T 스택에 저장될 데이터
 */
class Stack {
private:
    Node<T>* top = nullptr; /// @brief 스택의 가장 위 노드 주소
    int stack_size = 0; /// @brief 스택의 크기
public:
    /// @brief 스택의 크기를 반환하는 메서드
    int size(){
        return stack_size;
    }

    /// @brief 스택에 데이터를 추가하는 메서드
    void push(T data){
        // 다음 주소가 top이고 data를 내용물로 가지는 노드 생성
        auto tmp = new Node<T>(data, top);

        // 탑 노드로 지정하고 스택 사이즈 증가시킴
        top = tmp;
        stack_size++;
    }

    /// @brief 스택에서 데이터를 빼는 메서드
    bool pop(T& input){
        // 탑 노드 주소 백업
        auto tmp = top;
        T tmp_data;

        // 탑 노드가 비어있지 않을 경우
        if(tmp != nullptr){
            // 탑을 탑 다음 주소의 노드로 설정
            top = top->next();
            // 데이터를 input에 복사
            input = tmp->data();

            // 동적 할당된 노드 제거
            delete tmp;

            // 스택 사이즈 줄이고 데이터 복사에 성공했음을 반환
            stack_size--;
            return true;
        }

        // 데이터 복사에 실패했음을 반환
        return false;
    }

    /// @brief 스택을 복사하는 = 오버로딩
    Stack&operator=(Stack const& param){
        if(this != &param){
            // 스택 크기와 탑 노드 주소 복사
            stack_size = param.stack_size;
            top = param.top;
        }
        return *this;
    }

    /// @brief Stack 클래스 소멸자
    ~Stack(){
        Node<T>* tmp;
        while(top != nullptr){
            tmp = top->next();
            delete top;
            top = tmp;
        }
    }
};


#endif //CSED232_STACK_H
