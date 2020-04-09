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



#endif //CSED232_LIST_H
