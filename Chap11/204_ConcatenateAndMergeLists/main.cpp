#include <iostream>
using namespace std;

struct Node{
    int data;
    struct Node *next;
};

struct Node *first = NULL;
struct Node *second = NULL;
struct Node *third = NULL;
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

int listDelete(struct Node *p, int index){
    struct Node *q;
    int x;
    if(index < 0 || index > count(p)-1){
        return -1;
    }
    if(index == 0){
        p = first;
        x = first->data;
        first = first->next;
        delete p;
    }
    else{
        p = first;
        q = NULL;
        for(int i=0; i<index && p; i++){
            q = p;
            p = p->next;
        }
        x = p->data;
        q->next = p->next;
        delete p;
    }
    return x;
}

bool isSorted(struct Node *p){
    int x = -INT32_MIN;
    while(p){
        if(p->data >= x){
            x = p->data;
            p = p->next;
        }
        else{
            return false;
        }
    }
    return true;
}

void removeDuplicate(struct Node *p){
    struct Node *q = p->next;
    while(q != NULL){
        if(p->data != q->data){
            p = q;
            q = q->next;
        }
        else{
            p->next = q->next;
            delete q;
            q = p->next;
        }
    }
}

void reverse1(struct Node *p){
    int *A = new int[count(p)];
    struct Node *q = p;
    int i=0;
    while(q != NULL){
        A[i++] = q->data;
        q = q->next;
    }
    q = p;
    i--;
    while(q != NULL){
        q->data = A[i--];
        q = q->next;
    }
}

// Changing links' direction is preferred than chaing node's value.
void reverse2(struct Node *p){
    struct Node *q, *r;
    q = NULL;
    r = NULL;
    while(p != NULL){
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;
}

void reverse3(struct Node *q, struct Node *p){
    if(p != NULL){
        reverse3(p, p->next);
        p->next = q;
    }
    else{
        first = q;
    }
}

void concatenate(struct Node *q, struct Node *p){
    third = q;
    while(q->next != NULL){
        q = q->next;
    }
    q->next = p;
}

void merge(struct Node *first, struct Node *second){
    struct Node *last;
    if(first->data <= second->data){
        third = first;
        last = first;
        first = first->next;
        last->next = NULL;
    }
    else{
        third = second;
        last = second;
        second = second->next;
        last->next = NULL;
    }
    while(first != NULL && second != NULL){
        if(first->data <= second->data){
            last->next = first;
            last = first;
            first = first->next;
            last->next = NULL;
        }
        else{
            last->next = second;
            last = second;
            second = second->next;
            last->next = NULL;
        }
    }
    if(first != NULL) last->next = first;
    if(second != NULL) last->next = second;
}

void create2(int A[], int n){
    struct Node *current, *last;
    second = new struct Node;
    second->data = A[0];
    second->next = NULL;
    last = second;

    for(int i=1; i<n; i++){
        current = new struct Node;
        current->data = A[i];
        last->next = current;
        last = current;
    }
}



int main(){
    int A[] = {3, 5, 8, 10, 15};
    int B[] = {2, 4, 7, 11, 18};
    create(A, 5);
    create2(B, 5);
    display(first);
    display(second);
    // concatenate(first, second);
    merge(first, second);
    display(third);


}
