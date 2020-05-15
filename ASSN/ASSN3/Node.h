#ifndef CSED232_NODE_H
#define CSED232_NODE_H

template <typename T>
class Node {
private:
    T node_data;
    Node* node_next;
    Node* node_prev;
public:
    explicit Node(T data, Node* next=nullptr, Node* prev=nullptr){
        node_data = data;
        node_next = next;
        node_prev = prev;
    }

    Node*& next(){
        return node_next;
    }

    T& data(){
        return node_data;
    }

    Node*& prev(){
        return node_prev;
    }
};


#endif //CSED232_NODE_H
