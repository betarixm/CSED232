#ifndef CSED232_LIST_H
#define CSED232_LIST_H

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

using namespace std;

/*
 * 템플릿 클래스를 .h 파일과 .cpp 파일에 분리해서 작성할 경우,
 * 링크 에러가 발생하기에 .h 파일에만 작성하였습니다.
 */

template<typename T>
class List; // 리스트 클래스 프로토타이핑

template<typename T>
class Node; // 리스트 클래스 프로토타이핑


/**
 * @brief List의 Element가 되는 노드 클래스
 * @details List의 요소로 사용되며, 각 노드들은 전 후 노드의 주소를 가진다.
 * @tparam T 노드가 저장할 데이터의 타입을 지정한다.
 */
template<typename T>
class Node {
private:
    T *node_data = nullptr; /// @brief 노드에 저장할 데이터의 포인터
    Node<T> *node_next = nullptr; /// @brief 다음 노드의 주소
    Node<T> *node_prev = nullptr; /// @brief 이전 노드의 주소
    List<T> *list_parent = nullptr; /// @brief 어떤 리스트의 노드인지 저장
public:

    /**
     * @brief 노드에 저장할 데이터를 할당하는 메서드
     * @param data 저장될 데이터의 포인터를 지정한다.
     */
    void setData(T *data) {
        this->node_data = data; // 데이터 할당
    }

    /**
     * @brief 노드에 저장된 데이터의 포인터를 반환하는 메서드
     * @return 노드에 저장된 데이터의 포인터를 반환
     */
    T *data() {
        return this->node_data; // 데이터 반환
    }

    /**
     * @brief 노드의 다음 노드 주소를 set하는 메서드
     * @param next 다음 노드의 주소
     */
    void setNext(Node<T> *next) {
        this->node_next = next; // 다음 노드 주소를 저장
    }

    /**
     * @brief 노드의 다음 노드 주소를 get하는 메서드
     * @return 다음 노드의 주소
     */
    Node<T> *next() {
        return this->node_next; // 다음 노드의 주소를 반환
    }

    /**
     * @brief 노드의 이전 노드 주소를 set하는 메서드
     * @param prev 이전 노드의 주소
     */
    void setPrev(Node<T> *prev) {
        this->node_prev = prev; // 이전 노드 주소를 저장
    }

    /**
     * @brief 노드의 이전 노드 주소를 get하는 메서드
     * @return 이전 노드의 주소
     */
    Node<T> *prev() {
        return this->node_prev;
    }

    /**
     * @brief 노드의 부모 리스트 주소를 set하는 메서드
     * @param parent 부모 리스트의 주소
     */
    void setParent(List<T> *parent) {
        this->list_parent = parent; // 부모 리스트의 주소 할당
    }

    /**
     * @brief 노드의 부모 리스트의 주소를 get하는 메서드
     * @return 부모 리스트의 주소
     */
    List<T> *parent() {
        return this->list_parent; // 부모 리스트의 주소 반환
    }
};

/**
 * @brief 커서 리스트
 * @details 메모리를 효율적으로 사용하여 시간 순으로 정렬되도록 저장하기 위해 커서 리스트를 구현하여 사용
 * @tparam T 커서 리스트의 데이터 타입 지정
 */
template<typename T>
class List {
private:
    Node<T> *list = nullptr; /// @brief 노드 배열이 저장될 포인터
    int list_size = 0; /// @brief 리스트에 값이 있는 노드의 개수
    int max = 0; /// @brief 리스트가 최대한 저장할 수 있는 노드의 크기
    Node<T> *first = nullptr; /// @brief 리스트의 첫번째 노드 주소
    Node<T> *last = nullptr; /// @brief 리스트의 마지막 노드 주소

public:
    /**
     * @brief List의 생성자
     * @details List의 사이즈를 입력받아서 노드 배열을 동적 할당한다.
     * @param max List의 최대 크기
     */
    explicit List(int max) {
        list = new Node<T>[max]; // list에 주어진 크기만큼의 노드 배열을 할당한다.
        this->max = max; // 주어진 크기를 멤버 변수 max에 할당한다.
    }

    /**
     * @brief List의 소멸자
     * @details 동적 할당된 list 배열을 할당 해제한다.
     */
    ~List() {
        delete[] list; // 동적할당 된 노드 배열을 할당 해제한다.
    }

    /**
     * @brief 리스트의 마지막에 노드를 추가하는 메서드
     * @details 데이터의 포인터를 입력받아서 리스트의 마지막 노드로 추가한다.
     * @param data 저장할 데이터
     * @return 추가된 노드의 주소
     */
    Node<T> *add(T *data) {
        if (list_size >= max) { // 만약 사이즈가 한계에 다다랐다면
            return nullptr; // 새로 할당하지 않는다
        }
        for (int i = 0; i < max; i++) { // 노드 배열을 탐색하면서
            if (list[i].data() == nullptr) { // 비어있는 노드가 있으면
                list[i].setData(data); // 노드에 데이터를 할당
                if (list_size == 0) {
                    // 리스트의 사이즈가 0일 경우, 리스트의 첫 노드로 등록한다.
                    first = &(list[i]);
                } else {
                    // 아닐 경우, 마지막 노드의 다음 노드에 새로 추가된 노드를 등록한다.
                    last->setNext(&(list[i]));
                }
                // 기존 마지막 노드의 주소를 새로운 노드의 이전 주소로 저장한다.
                list[i].setPrev(last);

                // 마지막 노드를 갱신한다.
                last = &(list[i]);
                list_size++; // 리스트 사이즈 갱신
                return &(list[i]); // 새로 추가된 node의 주소를 반환한다.
            }
        }
        return nullptr; // 실패했을 경우 nullptr을 반환한다.
    }

    /**
     * @brief 리스트의 특정 노드를 삭제하는 메서드
     * @details 삭제한 이후, 삭제된 노드의 다음 주소를 반환함으로써,
     *          List를 for문을 이용하여 탐색할 때 오작동을 방지한다.
     *          예를 들어, for문을 이용하여 리스트를 탐색하는 중에 노드를 drop하게 되면
     *          해당 노드의 다음 노드의 주소가 nullptr이 되어 탐색이 의도치 않게 종료되는
     *          경우가 생길 수 있기에, 삭제된 노드의 다음 주소를 drop에서 반환해준다.
     * @param node 삭제할 노드의 주소
     * @return 삭제된 노드의 다음 노드의 주소
     */
    Node<T> *drop(Node<T> *node) {
        Node<T>* backup = node->next(); // 삭제된 노드의 다음 노드의 주소를 백업한다.
        if (node->prev() == nullptr) {
            // 주어진 노드가 첫번째 노드일 경우, 리스트의 첫번째 노드를 그 다음 노드로 갱신한다.
            first = node->next();
        } else {
            // 첫번째 노드가 아니라면, 주어진 노드의 이전 노드의 다음 노드의 주소를 주어진 노드의 다음 노드 주소로 설정한다.
            (node->prev())->setNext(node->next());
        }
        if (node->next() == nullptr) {
            // 주어진 노드가 마지막 노드일 경우, 리스트의 마지막 노드를 그 이전 노드로 갱신한다.
            last = node->prev();
        } else {
            // 마지막 노드가 아니라면, 주어진 노드의 다음 노드의 이전 노드의 주소를 주어진 노드의 이전 노드 주소로 설정한다.
            (node->next())->setPrev(node->prev());
        }

        // 노드에 저장된 데이터를 초기화 한다.
        // 단, 여기서 데이터를 delete 할 경우, Friends 클래스에서 오동작이 발생할 수 있기에,
        // 할당된 메모리를 해제하지는 않는다.
        node->setData(nullptr);
        node->setPrev(nullptr);
        node->setNext(nullptr);

        list_size--; // 리스트 사이즈 갱신
        return backup; // 주어진 노드의 다음 노드의 주소를 반환한다.
    }

    /**
     * @brief 리스트의 특정 위치에 새로운 노드를 삽입하는 메서드
     * @param node 새로운 노드가 삽입될 위치. 주어진 노드의 다음에 새로운 노드가 삽입된다.
     * @param data 새로운 노드에 저장될 데이터의 주소
     * @return 새로운 노드의 주소를 반환
     */
    Node<T> *insert(Node<T> *node, T *data) {
        if (list_size >= max) { // 리스트에 저장할 수 있는 최대 노드의 수에 다다랐을 경우, 삽입을 제한한다.
            return nullptr; // nullptr을 반환
        }
        for (int i = 0; i < max; i++) {
            // 리스트를 탐색하면서 빈 노드를 찾는다.
            if (list[i].data() == nullptr) {
                // 빈 노드를 찾았을 경우, 그 곳에 데이터를 할당한다.
                Node<T> *tmp = &(list[i]);
                tmp->setData(data);

                // 새로운 노드의 이전 노드의 주소를 node로 설정한다.
                tmp->setPrev(node);

                if (node == last) {
                    // 주어진 노드가 마지막 노드라면, 마지막 노드를 새로운 노드로 갱신한다.
                    last = tmp;
                }

                if (node == nullptr) {
                    // 주어진 노드가 nullptr인 경우는, 리스트의 시작에 노드를 삽입하는 경우로,
                    // 리스트의 시작 노드를 새로운 노드로 갱신한다.
                    tmp->setNext(first);
                    first = tmp;
                } else {
                    // 주어진 노드의 뒤에 삽입하는 경우이므로,
                    // 주어진 노드의 다음 노드의 값을 새로운 노드의 다음 노드 값으로 취한다.
                    tmp->setNext(node->next());
                }
                list_size++; // 리스트 사이즈 갱신
                return &(list[i]); // 새로 추가된 노드의 주소 반환
            }
        }
        return nullptr; // 실패했을 경우 nullptr 반환
    }

    /**
     * @brief 리스트의 사이즈를 반환하는 메서드
     * @return 리스트의 사이즈를 반환
     */
    int size() {
        return list_size; // 리스트의 사이즈를 반환
    }

    /**
     * @brief 리스트의 첫 노드의 주소를 반환하는 메서드
     * @return 리스트의 첫 노드의 주소를 반환
     */
    Node<T> *begin() {
        return first; // 리스트의 첫 노드를 반환한다.
    }

    /**
     * @brief 리스트의 마지막 노드의 주소를 반환하는 메서드
     * @return 리스트의 마지막 노드 주소를 반환
     */
    Node<T> *end() {
        return last; // 리스트의 마지막 노드를 반환한다.
    }

    /**
     * @brief 리스트에 주어진 데이터가 존재하는지 확인하는 메서드
     * @param data 찾을 데이터
     * @return 주어진 데이터의 유무 여부
     */
    bool exist(T *data) {
        for (auto tmp = begin(); tmp != nullptr; tmp = tmp->next()) { // 노드 배열을 탐색한다.
            if (data == tmp->data()) { // 만약 주어진 데이터를 찾았다면
                return true; // true를 반환한다.
            }
        }
        return false; // 찾지 못했다면 false를 반환한다.
    }

    /**
     * @brief 리스트에서 주어진 데이터의 노드의 주소를 반환하는 메서드
     * @param data 찾을 데이터
     * @return 주어진 데이터를 가지고 있는 노드의 주소
     */
    Node<T> *find(T *data) {
        for (auto tmp = begin(); tmp != nullptr; tmp = tmp->next()) {
            // 노드 배열을 탐색하여 주어진 데이터를 찾았다면 그 노드의 주소를 반환한다.
            if (data == tmp->data()) {
                return tmp;
            }
        }
        return nullptr; // 찾지 못했다면 nullptr을 반환한다.
    }
};

#endif //CSED232_LIST_H
