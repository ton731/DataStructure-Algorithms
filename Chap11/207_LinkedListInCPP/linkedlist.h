#ifndef LINKEDLIST_H
#define LINKEDLIST_H
namespace linkedlist{
    class Node{
        public:
        int data;
        Node *next;
    };

    class LinkedList{
        // private:
        public:
        Node *first;

        // public:
        LinkedList();
        LinkedList(int A[], int n);
        ~LinkedList();

        void Display();
        void Length();
        void Insert(int index, int x);
        int Delete(int index);
    };
}
#endif