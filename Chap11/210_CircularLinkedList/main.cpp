#include <iostream>
using namespace std;

struct Node{
    int data;
    struct Node *next;
};

Node *head;

void create(int A[], int n){
    struct Node *t, *last;
    head = new Node;
    head->data = A[0];
    head->next = head;
    last = head;

    for(int i=1; i<n; i++){
        t = new Node;
        t->data = A[i];
        t->next = last->next;
        last->next = t;
        last = t;
    }
}

void display(Node *h){
    do{
        cout << h->data << ", ";
        h = h->next;
    }while(h != head);
    cout << endl;
}

void Rdisplay(Node *h){
    static int flag = 0;
    if(h != head || flag == 0){
        flag = 1;
        cout << h->data << ", ";
        Rdisplay(h->next);
    }
    flag = 0;
}

int main(){
    int A[] = {1, 3, 5, 7, 9};
    create(A, 5);
    display(head);
    Rdisplay(head);
}

