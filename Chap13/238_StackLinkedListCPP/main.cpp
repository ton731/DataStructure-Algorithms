#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
};

class Stack{
    private:
    Node *top;

    public:
    Stack(){top = NULL;}
    void push(int x);
    int pop();
    void display();
};


void Stack::push(int x){
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

int Stack::pop(){
    int x = -1;
    if(top == NULL){
        cout << "Stack is empty!" << endl;
    }
    else{
        x = top->data;
        Node *t = top;
        top = top->next;
        delete t;
    }
    return x;
}

void Stack::display(){
    Node *p = top;
    while(p){
        cout << p->data << ", ";
        p = p->next;
    }
    cout << endl;
}

int main(){
    Stack stk;

    stk.push(1);
    stk.push(5);
    stk.push(7);

    stk.display();
    cout << "Pop out: " << stk.pop() << endl;
}
