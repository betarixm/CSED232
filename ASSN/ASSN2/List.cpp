#include "List.h"

template <typename T>
List<T>::List(int max){
    list = new Node<T>[max];
    this->max = max;

    for(int i=0; i<max; i++){
        list[i].data = nullptr;
        list[i].prev = nullptr;
        list[i].next = nullptr;
    }
}

template <typename T>
Node<T>* List<T>::add(T* data){
    if (size >= max){
        return nullptr;
    }
    for(int i = 0; i< max; i++){
        if(list[i].data == nullptr){
            list[i].data = data;
            if(size == 0){
                first = &(list[i]);
            }
            list[i].prev = last;
            last = &(list[i]);
            size++;
            return &(list[i]);
        }
    }
    return nullptr;
}

template <typename T>
Node<T>* List<T>::drop(Node<T>* node){
    if(node->prev == nullptr){
        first=node->next;
    } else {
        (node->prev)->next = node->next;
    }
    delete node->data;
    node->data = nullptr;
    node->prev = nullptr;
    node->next = nullptr;
    size--;
    return node;
}