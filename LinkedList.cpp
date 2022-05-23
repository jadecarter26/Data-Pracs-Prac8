# include "LinkedList.h"
# include <iostream> 

LinkedList::LinkedList(){
    head = nullptr;
}

void LinkedList::addFront(int newItem) {
    // if list empty
    if (this->head == nullptr) {
        Node * myNode = new Node(); 
        myNode->setData(newItem); 
        myNode->setNext(nullptr); 
        this->head = myNode;
        //this->head = new Node(newItem, nullptr);
    } else {
        //this->head = new Node(newItem, this->head);
        Node * myNode = new Node(); 
        myNode->setData(newItem); 
        myNode->setNext(this->head); 
        this->head = myNode;
        //head->setNext(myNode);
        std::cout<<myNode->getData()<<std::endl;
        std::cout<<myNode->getNext()<<std::endl;
    }
}

void LinkedList::addEnd(int newItem) {
    if (this->head == nullptr) {
        Node * myNode = new Node(); 
        myNode->setData(newItem); 
        myNode->setNext(nullptr); 
        this->head = myNode;
        //this->head = new Node(newItem, nullptr);
    } else {
        // temp points to what head points to 
        Node * temp = this->head;
        // continue  going through list until you find pointer to null
        while (temp->getNext() != nullptr) {
            // will find last element in list
            temp = temp->getNext();
        }
        // create new node with data at end
        Node * myNode = new Node();
        myNode->setData(newItem); 
        myNode->setNext(nullptr); 
        // set temp to point to myNode
        temp->setNext(myNode); 
        std::cout<<myNode->getData()<<std::endl;
    }

}