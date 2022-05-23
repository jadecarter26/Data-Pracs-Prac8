# ifndef LINKEDLIST
# define LINKEDLIST
# include "Node.h"
class LinkedList{
    public:
    // default
        LinkedList();
        LinkedList(int *array, int length);
        void addFront(int newItem); 
        void addEnd(int newItem);
        void addAtPosition(int position, int newItem);
        int search(int item); //: The function searches the list for the first instance of the  item
        void deleteFront();
        void deleteEnd();
        void deletePosition(int position); 
        int getItem(int position);
        void printItems(); 

        virtual ~LinkedList();
    private:
        // when you create linked list object it'll be empty
        Node * head = nullptr; 
}; 
# endif