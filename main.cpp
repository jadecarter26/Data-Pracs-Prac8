# include "Node.h"
# include "LinkedList.h"
# include <iostream> 

int main() {
    LinkedList * myLinkedList = new LinkedList(); 
    myLinkedList->addFront(5);
    std::cout<<"Again"<<std::endl;
    myLinkedList->addFront(2);
    myLinkedList->addFront(9);
    myLinkedList->addEnd(1);
}