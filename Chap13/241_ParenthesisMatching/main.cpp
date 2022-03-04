#include <iostream>
using namespace std;

class Node{
    public:
    char data;
    Node *next;
};

class Stack{
    private:
    Node *top;

    public:
    Stack(){top = NULL;}
    void push(char x);
    char pop();
    void display();
    bool isEmpty();
};


void Stack::push(char x){
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

char Stack::pop(){
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

bool Stack::isEmpty(){
    return top==NULL;
}

bool isBalanced(char *exp){
    Stack stk;
    for(int i=0; exp[i]!='\0'; i++){
        if(exp[i] == '('){
            stk.push(exp[i]);
        }
        else if(exp[i] == ')'){
            if(stk.isEmpty()){
                return false;
            }
            else{
                stk.pop();
            }
        }
    }
    return stk.isEmpty() ? true : false;
}


int main(){
    char exp[] = "(((a+b)*(c-d)))";
    cout << "exp is balanced: " << isBalanced(exp) << endl;;
}
