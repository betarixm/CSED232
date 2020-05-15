#ifndef CSED232_STACK_H
#define CSED232_STACK_H

#include "Node.h"

template <typename T>
class Node;

template <typename T>
class Stack {
private:
    Node<T>* top = nullptr;
    int stack_size = 0;
public:
    int size(){
        return stack_size;
    }
    void push(T data){
        auto tmp = new Node<T>(data, top);
        top = tmp;
        stack_size ++;
    }

    bool pop(T& input){
        auto tmp = top;
        T tmp_data;
        if(tmp != nullptr){
            top = top->next();
            input = tmp->data();
            delete tmp;
            stack_size--;
            return true;
        }
        return false;
    }
    Stack&operator=(Stack const& param){
        if(this != &param){
            stack_size = param.stack_size;
            top = param.top;
        }
        return *this;
    }
};


#endif //CSED232_STACK_H
