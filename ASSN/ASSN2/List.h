#ifndef CSED232_LIST_H
#define CSED232_LIST_H

template <typename T>
class List;
template <typename T>
class Node;

template <typename T>
class Node {
public:
    T* data;
    Node<T>* next;
    Node<T>* prev;
    List<T>* parent;
};

template <typename T>
class List{
private:
    Node<T>* list = nullptr;
    int size = 0;
    int max = 0;

public:
    explicit List(int size);
    Node<T>* first = nullptr;
    Node<T>* last = nullptr;
    Node<T>* add(T* data);
    Node<T>* drop(Node<T>* node);
};


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

#endif //CSED232_LIST_H
