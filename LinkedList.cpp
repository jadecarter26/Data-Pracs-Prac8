# include "LinkedList.h"
# include <iostream> 
#include <limits> // std::numeric_limits
LinkedList::LinkedList(){
    //head = nullptr;
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

void LinkedList::addAtPosition(int position, int newItem) {
    if (position < 1) {
        this->addFront(newItem); // add new item at front
    }

    int count = 1; 
    Node * tmp = new Node(); 
    tmp = this->head; // temp points to what head points to

    // if you reach the index you want
    if (position == count) { 
        this->addFront(newItem); // add element in front
    }

    // stop before you get to last item in list
    while (tmp->getNext() != nullptr) {
    tmp = tmp->getNext(); // get pointer to next node
    count++; //INCREMENT COUNT

        if (count == position - 1 && tmp->getNext() != nullptr) {

            Node * newNode = new Node(); 
            newNode->setData(newItem); 
            newNode->setNext(tmp->getNext()); 
            tmp->setNext(newNode);
            return;
        }
    }
    
    if (position >= count) {
        Node * myNode = new Node(); 
        myNode->setData(newItem); 
        myNode->setNext(nullptr); 
        tmp->setNext(myNode); 
    }
}


int LinkedList::search(int item) {

    if (this->head == nullptr) {
        std::cout<<"EMPTY LIST"<<std::endl;
        return 0;
    }
    // increase position 
    int position = 1;
    Node * srch = new Node(); 
    srch = this->head;

    if (this->head->getData() == item) {
        std::cout<<position<<" ";
        return position;
    }
    // go through list 
    while (srch->getNext() != nullptr) {
        srch = srch->getNext(); 
        position = position + 1;
        if (srch->getData() == item) {
            std::cout<<position<< " ";
            return position;
        }
    }

    // if item isn't ound print error
    std::cout << "ITEM NOT FOUND"<<std::endl;
    return 0;
}

void LinkedList::deleteFront() {
    // check if list is empty ALWAYS
    if (this->head == nullptr) {
        return;
    } else {
        // create node 
        Node * temp = new Node(); 
        temp = this->head;
        // go through til end of list
        if (temp->getNext() != nullptr) {
            //  assign head
            // IS THIS RIGHT???
            this->head = temp->getNext(); 
        }
        else {
            // assign head to nullptr when you find 
            this->head = nullptr; 
        }
        delete temp;
    }
}

void LinkedList::deleteEnd(){
    //c heck to se if list is empty 
    if (this->head == nullptr) {
        return;
    } else {
        Node * tempor = new Node(); 
        tempor = this->head;

        // condition if there's only 1 node in list
        if (this->head->getNext() == nullptr) {
            delete tempor; // delete the node
            this->head = nullptr; // assign head to point to NULL
            return;
        }

        // go through list 
        while(tempor->getNext()->getNext() != nullptr) {
            tempor = tempor->getNext();
        }
        //std::cout<<temp->getNext();
        //
        delete tempor->getNext();
        // set next pointer to null
        tempor->setNext(nullptr);
    }

}

void LinkedList::deletePosition(int position) {
    int counter = 1; // set variable to count 
    Node * myNode = new Node(); 
    myNode = this->head;
    
    // for first call and position == 1
    if (counter == position) { 
        this->deleteFront(); // call function to detele front
            return;
    }

    // same same really
    while (myNode->getNext() != nullptr) {
        myNode = myNode->getNext();
        counter++; // incrememnt to remmeber position
        // brackets?
        if ((myNode->getNext() != nullptr) && (counter == position-1)) {
            Node * node2 = new Node(); 
            node2 = myNode->getNext();
            if (node2->getNext() != nullptr) {
                myNode->setNext(node2->getNext());
            }
            else {
                 myNode->setNext(nullptr);
            }
            delete node2; // you should delete what you dont' need lol
            return;
        }
    }

    if (position <= 0 || counter<position) {
        std::cout<<"Out of range"<<std::endl;
    }
    //std::cout<<"end"<<std::endl;
}

int LinkedList::getItem(int position) {
    int counter = 1;
        Node * nodynode = new Node(); 
        nodynode = this->head; 
    // check if pos is equivalent to counter 
    if (position == counter) {
        std::cout<<nodynode->getData()<<" ";
        return (nodynode->getData());
    }
    // stop going thru list if next item points to NULL
    while(nodynode->getNext() != nullptr) {
        // continue getting next
        nodynode = nodynode->getNext();
        counter++; // incrememnt counter
        // check if pos is equivalent to counter
        if (counter == position) {
            //             std::cout<<nodynode->getData()<<" ";
            // print with spaces 
            std::cout<<nodynode->getData()<<" ";
            return nodynode->getData();
        }
    }
    // If beyond the size of the array
    // specs given from instruc
    //std::cout<<std::numeric_limits<int>::max()<<" ";
    //return std::numeric_limits<int>::max();
    //return 0;
    std::cout<<std::numeric_limits<int>::max()<<" ";
    return std::numeric_limits<int>::max();
}


void LinkedList::printItems() {
    // same same
    if (this->head == nullptr) {
        return;
    }
    Node * myNode = new Node(); 
    myNode = this->head; 

    std::cout<<myNode->getData()<<" ";

    // 
    //while(tmp->getNext() ) { //
    while(myNode->getNext() != nullptr) {
        myNode = myNode->getNext();
        std::cout<<myNode->getData()<< " ";
    }



}

