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

int length(Node *p){
    int len = 0;
    do{
        len++;
        p = p->next;
    }while(p != head);
    return len;
}

void insert(Node *p, int index, int x){
    if(index < 0 || index >= length(p)){
        return;
    }
    Node *t = new Node;

    if(index == 0){
        while(p->next != head){
            p = p->next;
        }
        t->data = x;
        t->next = head;
        p->next = t;
        head = t;
    }
    else{
        for(int i=0; i<index-1; i++){
            p = p->next;
        }
        t->data = x;
        t->next = p->next;
        p->next = t;
    }
}

int Delete(Node *p, int index){
    if(index >= length(p) || index < 0){
        return NULL;
    }
    Node *q;
    int x;
    if(index == 0){
        while(p->next != head){
            p = p->next;
        }
        x = head->data;
        q = head->next;
        p->next = q;
        delete head;
        head = q;
    }
    else{
        for(int i=0; i<index-1; i++){
            p = p->next;
        }
        q = p->next;
        x = q->data;
        p->next = q->next;
        delete q;
    }
    return x;
}




int main(){
    int A[] = {1, 3, 5, 7, 9};
    create(A, 5);
    display(head);
    cout << "Deleted value: " << Delete(head, 3) << endl;;
}

