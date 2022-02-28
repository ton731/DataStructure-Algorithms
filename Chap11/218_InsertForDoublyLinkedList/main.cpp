#include <iostream>
using namespace std;

struct Node{
    Node *prev;
    int data;
    Node *next;
};
Node *first = NULL;

void create(int A[], int n){
    Node *t, *last;
    first = new Node;
    first->data = A[0];
    first->prev = first->next = NULL;
    last = first;
    for(int i=1; i<n; i++){
        t = new Node;
        t->data = A[i];
        t->next = last->next;
        t->prev = last;
        last->next = t;
        last = t;
    }
}

void Display(Node *p){
    while(p){
        cout << p->data << ", ";
        p = p->next;
    }
    cout << endl;
}

int Length(Node *p){
    int len = 0;
    while(p){
        len++;
        p = p->next;
    }
    return len;
}

void Insert(Node *p, int index, int x){
    if(index < 0 || index >= Length(p)){
        return;
    }
    Node *t;
    if(index == 0){
        t = new Node;
        t->data = x;
        t->prev = nullptr;
        t->next = first;
        first->prev = t;
        first = p;
    }
    else{
        for(int i=0; i<index-1; i++){
            p = p->next;
        }
        t = new Node;
        t->data = x;
        t->next = p->next;
        t->prev = p;
        if(p->next){
            p->next->prev = t;
        }
        p->next = t;
    }
}



int main(){
    int A[] = {1, 3, 5, 7, 9};
    create(A, 5);
    cout << "Length = " << Length(first) << endl;
    Display(first);
    Insert(first, 3, 6);
    Display(first);
}
