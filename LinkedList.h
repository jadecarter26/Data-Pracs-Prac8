# ifndef LINKEDLIST
# define LINKEDLIST
# include "Node.h"
class LinkedList{
    public:
        LinkedList();
        void addFront(int newItem); 
        void addEnd(int newItem);
    private:
        // when you create linked list object it'll be empty
        Node * head; // = nullptr; 
}; 
# endif