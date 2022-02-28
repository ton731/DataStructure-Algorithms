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

int count(struct Node *p){
    int c = 0;
    while(p != NULL){
        c++;
        p = p->next;
    }
    return c;
}

int sum(struct Node *p){
    int s = 0;
    while(p != 0){
        s += p->data;
        p = p->next;
    }
    return s;
}

int max(struct Node *p){
    int m = INT32_MIN;
    while(p != NULL){
        if(p->data > m){
            m = p->data;
        }
        p = p->next;
    }
    return m;
}


int main(){
    int A[] = {3, 5, 7, 10, 15};
    create(A, 5);
    display(first);
    cout << "Length = " << count(first) << endl;
    cout << "Sum = " << sum(first) << endl;
    cout << "Max = " << max(first) << endl;
}
