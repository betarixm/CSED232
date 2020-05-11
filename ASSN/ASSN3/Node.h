#ifndef CSED232_NODE_H
#define CSED232_NODE_H

template <typename T>
class Node {
private:
    T node_data;
    Node* node_next;
public:
    Node(T data, Node* next=nullptr){
        node_data = data;
        node_next = next;
    }

    Node*& next(){
        return node_next;
    }

    T& data(){
        return node_data;
    }
};


#endif //CSED232_NODE_H
