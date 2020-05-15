#ifndef CSED232_NODE_H
#define CSED232_NODE_H

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
/**
 * @details 스택과 큐에 사용되는 노드 클래스
 * @tparam T 노드에 저장될 데이터 타입 지정
 */
class Node {
private:
    T node_data; /// @brief 노드에 저장될 데이터
    Node* node_next; /// @brief 다음 노드 주소
    Node* node_prev; /// @brief 이전 노드 주소
public:
    /// @brief Node 클래스 생성자
    explicit Node(T data, Node* next=nullptr, Node* prev=nullptr){
        node_data = data; // 데이터 초기화
        node_next = next; // 다음 노드 주소 초기화
        node_prev = prev; // 이전 노드 주소 초기화
    }

    /// @brief 다음 노드 주소를 참조형으로 반환하는 메서드
    Node*& next(){
        return node_next;
    }

    /// @brief 데이터를 참조형으로 반환하는 메서드
    T& data(){
        return node_data;
    }

    /// @brief 이전 노드 주소를 참조형으로 반환하는 메서드
    Node*& prev(){
        return node_prev;
    }
};


#endif //CSED232_NODE_H
