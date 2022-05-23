# ifndef NODE_H
# define NODE_H
// last value's ptr shoul dbe null
class Node{
    public: 
        Node(); 
        Node(int data, Node *next);
        void setNext(Node * _next); // set next node
        Node * getNext(); // returns pointer to the next node
        void setData(int _data); 
        int getData(); 
    private:
        int data; 
        Node * next;
};
# endif 