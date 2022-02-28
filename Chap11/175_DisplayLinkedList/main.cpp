#include <iostream>
using namespace std;

struct Node{
    int data;
    struct Node *next;
};

struct Node *first = NULL;


void create(int A[], int n){
    struct Node *current, *last;
    first = new struct Node;
    first->data = A[0];
    first->next = NULL;
    last = first;

    for(int i=1; i<n; i++){
        current = new struct Node;
        current->data = A[i];
        last->next = current;
        last = current;
    }
}

void display(struct Node *p){
    while(p!=NULL){
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

void display_recursive(struct Node *p){
    if(p != NULL){
        cout << p->data << " ";
        display_recursive(p->next);
    }
}


int main(){
    int A[] = {3, 5, 7, 10, 15};
    create(A, 5);
    display(first);
    display_recursive(first);
}
