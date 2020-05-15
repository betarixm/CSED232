#ifndef CSED232_QUEUE_H
#define CSED232_QUEUE_H

#include "Node.h"

template <typename T>
class Node;

template <typename T>
class Queue {
private:
    Node<T>* begin = nullptr;
    Node<T>* end = nullptr;
    int queue_size = 0;

public:
    int size(){
        return queue_size;
    }

    void push(T data){
        auto tmp = new Node<T>(data, begin, nullptr);
        if(begin != nullptr) begin->prev() = tmp;
        begin = tmp;
        if(queue_size == 0) end = tmp;
        queue_size++;
    }

    bool pop(T& input){
        if (end == nullptr) return false;

        auto tmp = end;
        input = end->data();
        end = end->prev();
        if(end != nullptr) { end->next() = nullptr; }
        if(queue_size == 1) { begin = nullptr; }
        delete tmp;
        queue_size--;

        return true;
    }
    Queue&operator=(Queue const& param){
        if(this != &param){
            queue_size = param.queue_size;
            begin = param.begin;
            end = param.end;
        }
        return *this;
    }
};


#endif //CSED232_QUEUE_H
