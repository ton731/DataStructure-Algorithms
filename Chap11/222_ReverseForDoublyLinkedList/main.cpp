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

int Delete(Node *p, int index){
    if(index < 0 || index >= Length(p)){
        return NULL;
    }
    int x;
    if(index == 0){
        x = p->data;
        if(p->next){
            p->next->prev = nullptr;
        }
        first = p->next;
        delete p;
    }
    else{
        for(int i=0; i<index; i++){
            p = p->next;
        }
        p->prev->next = p->next;
        if(p->next){
            p->next->prev = p->prev;
        }
        x = p->data;
        delete p;
    }
    return x;
}

void Reverse(Node *p){
    Node *temp;
    while(p){
        temp = p->next;
        p->next = p->prev;
        p->prev = temp;
        p = p->prev;
        if(p && p->next == NULL){
            first = p;
        }
    }
}


int main(){
    int A[] = {1, 3, 5, 7, 9};
    create(A, 5);
    Display(first);
    Reverse(first);
    Display(first);
}
