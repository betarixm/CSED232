#include <iostream>

using namespace std;

template <typename T>
class Node {
public:
    T* node_data;
    Node<T>* node_next;
    Node<T>* node_prev;
};

template <typename T>
class cList{
public:
    Node<T>* list = nullptr;
    Node<T>* first = nullptr;
    Node<T>* last = nullptr;
    int size = 0;
    int max = 0;

    cList(int size);

    Node<T>* add(T* data);
    Node<T>* drop(Node<T>* node);
};

template <typename T>
cList<T>::cList(int max){
    list = new Node<T>[max];
    this->max = max;

    for(int i=0; i<max; i++){
        list[i].node_data = nullptr;
        list[i].node_prev = nullptr;
        list[i].node_next = nullptr;
    }

}

template <typename T>
Node<T>* cList<T>::add(T* data){
    if (size >= max){
        return nullptr;
    }
    for(int i = 0; i< max; i++){
        if(list[i].node_data == nullptr){
            list[i].node_data = data;
            if(last == nullptr){
                first = &(list[i]);
            } else {
                last->node_next = &(list[i]);
            }
            list[i].node_prev = last;
            last = &(list[i]);
            size++;
            return &list[i];
        }
    }
    return nullptr;
}

template <typename T>
Node<T>* cList<T>::drop(Node<T>* node){
    if(node->node_prev == nullptr){
        first=node->node_next;
    } else {
        (node->node_prev)->node_next = node->node_next;
    }
    delete node->node_data;
    node->node_data = nullptr;
    node->node_prev = nullptr;
    node->node_next = nullptr;
    size--;
    return node;
}
int main(){
    cList<int> l = cList<int>(50);
    int* a = new int;
    int* b = new int;
    *a = 1;
    *b = 2;
    Node<int>* x = l.add(a);
    Node<int>* y = l.add(b);
    l.drop(x);
    l.drop(x);
    cout << *a << endl;
    int * c = new int;
    *c = 3;
    Node<int>* z = l.add(c);
}