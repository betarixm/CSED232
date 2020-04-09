#ifndef CSED232_LIST_H
#define CSED232_LIST_H

#include "20190084.h"

template <typename T>
class Node {
public:
    T* data;
    Node<T>* next;
    Node<T>* prev;
};

template <typename T>
class List{
    Node<T>* list = nullptr;
    Node<T>* first = nullptr;
    Node<T>* last = nullptr;
    int size = 0;
    int max = 0;

    List(int size);

    Node<T>* add(T* data);
    Node<T>* drop(Node<T>* node);
};


#endif //CSED232_LIST_H
