#include <iostream>
using namespace std;

class Queue{
    private:
    int size;
    int front;
    int rear;
    int *Q;

    public:
    Queue(int size);
    ~Queue();
    void enqueue(int x);
    int dequeue();
    void display();
};

Queue::Queue(int size){
    this->size = size;
    Q = new int[this->size];
    front = rear = -1;
}

Queue::~Queue(){
    delete []Q;
}

void Queue::enqueue(int x){
    if(rear == size - 1){
        cout << "Queue is full!" << endl;
    }
    else{
        rear++;
        Q[rear] = x;
    }
}

int Queue::dequeue(){
    int x = -1;
    if(front == rear){
        cout << "Queue is empty!" << endl;
    }
    else{
        front++;
        x = Q[front];
    }
    return x;
}

void Queue::display(){
    for(int i=front+1; i<=rear; i++){
        cout << Q[i] << ", ";
    }
    cout << endl;
}


int main(){
    Queue queue(10);
    queue.enqueue(2);
    queue.enqueue(5);
    queue.enqueue(8);
    queue.display();
}

