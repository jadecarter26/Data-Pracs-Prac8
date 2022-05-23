# include "Node.h" 

Node::Node(){}

void Node::setData(int _data){
    data = _data;
}

int Node::getData(){
    return data;
}

void Node::setNext(Node * _next) {
    next = _next; 
}

Node * Node::getNext(){
    return next;
}