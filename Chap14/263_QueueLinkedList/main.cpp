#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
};

class Queue{
    private:
    Node *front;
    Node *rear;

    public:
    Queue();
    void enqueue(int x);
    int dequeue();
    void display();
};

Queue::Queue(){
    front = rear = NULL;
}

void Queue::enqueue(int x){
    Node *t = new Node;
    if(t == NULL){
        cout << "Queue is full!" << endl;
    }
    else{
        t->data = x;
        t->next = NULL;
        if(front == NULL){
            front = rear = t;
        }
        else{
            rear->next = t;
            rear = t;
        }
    }
}

int Queue::dequeue(){
    int x = -1;
    Node *p;
    if(front == NULL){
        cout << "Queue is empty" << endl;
    }
    else{
        p = front;
        front = front->next;
        x = p->data;
        delete p;
    }
    return x;
}

void Queue::display(){
    Node *p = front;
    while(p){
        cout << p->data << ", ";
        p = p->next;
    }
    cout << endl;
}


int main(){
    Queue queue;
    queue.enqueue(2);
    queue.enqueue(5);
    queue.enqueue(8);
    queue.display();
}

