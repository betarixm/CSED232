#ifndef CSED232_LIST_H
#define CSED232_LIST_H

#include <iostream>

/*
 * 명예서약 (Honor Code)
 * 나는 이 프로그래밍 과제를 다른 사람의 부적절한 도움 없이 완수하였습니다.
 * I completed this programming task without the improper help of others.
 */

using namespace std;

template<typename T>
class List;

template<typename T>
class Node;

template<typename T>
class Node {
private:
    T *node_data = nullptr;
    Node<T> *node_next = nullptr;
    Node<T> *node_prev = nullptr;
    List<T> *list_parent = nullptr;
public:

    void setData(T *data) {
        this->node_data = data;
    }

    T *data() {
        return this->node_data;
    }

    void setNext(Node<T> *next) {
        this->node_next = next;
    }

    Node<T> *next() {
        return this->node_next;
    }

    void setPrev(Node<T> *prev) {
        this->node_prev = prev;
    }

    Node<T> *prev() {
        return this->node_prev;
    }

    void setParent(List<T> *parent) {
        this->list_parent = parent;
    }

    List<T> *parent() {
        return this->list_parent;
    }
};

template<typename T>
class List {
private:
    Node<T> *list = nullptr;
    int list_size = 0;
    int max = 0;
    Node<T> *first = nullptr;
    Node<T> *last = nullptr;

public:
    explicit List(int max) {
        list = new Node<T>[max];
        this->max = max;
    }

    ~List() {
        delete list;
    }

    Node<T> *add(T *data) {
        if (list_size >= max) {
            return nullptr;
        }
        for (int i = 0; i < max; i++) {
            if (list[i].data() == nullptr) {
                list[i].setData(data);
                if (list_size == 0) {
                    first = &(list[i]);
                } else {
                    last->setNext(&(list[i]));
                }
                list[i].setPrev(last);
                last = &(list[i]);
                list_size++;
                return &(list[i]);
            }
        }
        return nullptr;
    }

    Node<T> *drop(Node<T> *node) {
        if (node->prev() == nullptr) {
            first = node->next();
        } else {
            (node->prev())->setNext(node->next());
        }
        if (node->next() == nullptr) {
            last = node->prev();
        } else {
            (node->next())->setPrev(node->prev());
        }

        node->setData(nullptr);
        node->setPrev(nullptr);
        node->setNext(nullptr);
        list_size--;
        return node;
    }

    Node<T> *insert(Node<T> *node, T *data) {
        if (list_size >= max) {
            return nullptr;
        }
        for (int i = 0; i < max; i++) {
            if (list[i].data() == nullptr) {
                Node<T> *tmp = &(list[i]);
                tmp->setData(data);
                tmp->setPrev(node);
                if (node == last) {
                    last = tmp;
                }
                if (node == nullptr) {
                    tmp->setNext(first);
                    first = tmp;
                } else {
                    tmp->setNext(node);
                }
                list_size++;
                return &(list[i]);
            }
        }
        return nullptr;
    }

    int size() {
        return list_size;
    }

    Node<T> *begin() {
        return first;
    }

    Node<T> *end() {
        return last;
    }

    bool exist(T *data) {
        for (auto tmp = begin(); tmp != nullptr; tmp = tmp->next()) {
            if (data == tmp->data()) {
                return true;
            }
        }
        return false;
    }

    Node<T> *find(T *data) {
        for (auto tmp = begin(); tmp != nullptr; tmp = tmp->next()) {
            if (data == tmp->data()) {
                return tmp;
            }
        }
        return nullptr;
    }
};

#endif //CSED232_LIST_H
