#include <iostream>
#include "linkedlist.h"

namespace linkedlist{
    LinkedList::LinkedList(int A[], int n){
        Node *p = first;
        Node *nextNode;
        for(int i=0; i<n-1; i++){
            p->data = A[i];
            nextNode = new Node;
            p->next = nextNode;
            p = nextNode;
        }
        p->data = A[n-1];
        p->next = nullptr;
    }

    LinkedList::~LinkedList(){
        Node *p = first;
        Node *nextNode;
        while(p){
            nextNode = p->next;
            delete p;
            p = nextNode;
        }
    }

    void LinkedList::Display(){
        Node *p = first;
        while(p){
            std::cout << p->data << ", ";
            p = p->next;
        }
        std::cout << std::endl;
    }
    
}

int main(){return 0;}
