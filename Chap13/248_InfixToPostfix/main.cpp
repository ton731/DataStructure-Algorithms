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
    int isEmpty();
    int stackTop();
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

int Stack::isEmpty(){
    return top==NULL;
}

int Stack::stackTop(){
    if(top == NULL){
        return -1;
    }
    return top->data;
}

int isOperand(char x){
    if(x == '+' || x == '-' || x == '*' || x == '/'){
        return 0;
    }
    else{
        return 1;
    }
}

int pre(char x){
    if(x == '+' || x == '-'){
        return 1;
    }
    else if(x == '*' || x == '/'){
        return 2;
    }
    else{
        return 0;
    }
}

char * convert(char *infix){
    Stack stk;
    char *postfix = new char[strlen(infix)+1];
    int i = 0, j = 0;
    while(infix[i] != '\0'){
        if(isOperand(infix[i])){
            postfix[j++] = infix[i++];
        }
        else{
            if(pre(infix[i]) > pre(stk.stackTop())){
                stk.push(infix[i++]);
            }
            else{
                postfix[j++] = stk.pop();
            }
        }
    }
    while(!stk.isEmpty()){
        postfix[j++] = stk.pop();
    }
    postfix[j] = '\0';
    return postfix;
}





int main(){
    char *infix = "a+b*c";
    char *postfix = convert(infix);
    cout << postfix << endl;

}
