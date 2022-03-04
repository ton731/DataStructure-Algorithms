#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};
Node *top = NULL;

void push(int x){
    Node *t = new Node;
    if(t == NULL){
        cout << "Stack is full!" << endl;
    }
    else{
        t->data = x;
        t->next = top;
        top = t;
    }
}

int pop(){
    Node *t;
    int x = -1;
    if(top == NULL){
        cout << "Stack is empty!" << endl;
    }
    else{
        t = top;
        top = top->next;
        x = t->data;
        delete t;
    }
    return x;
}

void display(){
    Node *p = top;
    while(p){
        cout << p->data << ", ";
        p = p->next;
    }
    cout << endl;
}

int main(){
    push(1);
    push(3);
    push(5);

    display();
    cout << "Pop: " << pop() << endl;
}

