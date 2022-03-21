#ifndef Queue_h
#define Queue_h
#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *lchild;
    Node *rchild;
};

class Queue{
    private:
    int front;
    int rear;
    int size;
    Node **Q;

    public:
    Queue(){
        front = rear = 0;
        size = 10;
        Q = new Node* [size];
    }
    Queue(int size){
        front = rear = 0;
        this->size = size;
        Q = new Node* [size];
    }
    void enqueue(Node *x);
    Node* dequeue();
    bool isEmpty(){
        return front == rear;
    }
};

void Queue::enqueue(Node *x){
    if(rear == size - 1){
        cout << "Queue Full" << endl;
    }
    else{
        Q[rear] = x;
        rear++;
    }
}

Node* Queue::dequeue(){
    Node* x = nullptr;
    if(front == rear){
        cout << "Queue is empty" << endl;
    }
    else{
        x = Q[front];
        front++;
    }
    return x;
}



#endif