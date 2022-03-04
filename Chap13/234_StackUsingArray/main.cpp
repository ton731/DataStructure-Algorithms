#include <iostream>
using namespace std;

struct Stack{
    int size;
    int top;
    int *s;
};

void create(Stack *st){
    cout << "Enter size: ";
    cin >> st->size;
    st->top = -1;
    st->s = new int[st->size];
}

void display(Stack st){
    for(int i=st.top; i>=0; i--){
        cout << st.s[i] << ", ";
    }
    cout << endl;
}

bool isEmpty(Stack st){
    return st.top==-1;
}

bool isFull(Stack st){
    return st.top==st.size-1;
}

void push(Stack *st, int x){
    if(st->top == st->size - 1){
        cout << "Stack Overflow!" << endl;
    }
    else{
        st->top++;
        st->s[st->top] = x;
    }
}

int pop(Stack *st){
    int x = -1;
    if(st->top == -1){
        cout << "Stack Underflow!" << endl;
    }
    else{
        x = st->s[st->top];
        st->top--;
    }
    return x;
}

int peek(Stack st, int index){
    int x = -1;
    if(index < 0 || st.top - index < 0){
        cout << "Invalid Index" << endl;
    }
    else{
        x = st.s[st.top - index];
    }
    return x;
}

int stackTop(Stack st){
    if(st.top == -1){
        return -1;
    }
    else{
        return st.s[st.top];
    }
}


int main(){
    Stack st;
    create(&st);

    push(&st, 1);
    push(&st, 3);
    push(&st, 5);

    cout << "Pop: " << pop(&st) << endl;;

    display(st);
}

