#include <iostream>
using namespace std;

struct Node{
    int data;
    struct Node *next;
};

struct Node *first = NULL;
struct Node *last = NULL;


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

struct Node * linearSearch(struct Node *p, int key){
    while(p != NULL){
        if(p->data == key){
            return p;
        }
        p = p->next;
    }
    return NULL;
}

struct Node * transSearch(struct Node *p, int key){
    struct Node *q = NULL;
    while(p != NULL){
        if(p->data == key){
            q->next = p->next;
            p->next = first;
            first = p;
            return first;
        }
        q = p;
        p = p->next;
    }
    return NULL;
}

void insert(struct Node *p, int pos, int x){
    struct Node *t;
    if(pos == 0){
        t = new struct Node;
        t->data = x;
        t->next = first;
        first = t;
    }
    else if(pos > 0 && pos < count(p)){
        for(int i=0; i<pos-1; i++){
            p = p->next;
        }
        if(p != NULL){
            t = new struct Node;
            t->data = x;
            t->next = p->next;
            p->next = t;
        }
    }
}

void insertLast(int x){
    struct Node *t = new struct Node;
    t->data = x;
    t->next = NULL;
    if(first == NULL && last == NULL){
        first = t;
        last = t;
    }
    else{
        last->next = t;
        last = t;
    }
}

void sortedInsert(struct Node *p, int x){
    struct Node *t = new struct Node;
    t->data = x;
    t->next = NULL;

    while(p->next != NULL && p->next->data <= x){
        p = p->next;
    }
    if(p == first){
        t->next = first;
        first = t;
    }
    else{
        t->next = p->next;
        p->next = t;
    }
}




int main(){
    int A[] = {3, 5, 7, 10, 15};
    create(A, 5);
    display(first);
    sortedInsert(first, 2);
    display(first);
    sortedInsert(first, 20);
    display(first);



}
