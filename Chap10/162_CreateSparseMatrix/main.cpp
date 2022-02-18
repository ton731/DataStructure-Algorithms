#include <iostream>
using namespace std;

struct Element{
    int i;
    int j;
    int x;
};

struct Sparse{
    int m;
    int n;
    int num;
    struct Element *ele;
};

void create(struct Sparse *s){
    cout << "Enter Dimensions: " << endl;
    cin >> s->m;
    cin >> s->n;
    cout << "Enter number of non-zero: ";
    cin >> s->num;

    s->ele = new struct Element[s->num];
    cout << "Enter all element: " << endl;
    for(int i=0; i<s->num; i++){
        // cin >> s->ele[i].i >> s->ele[i].j >> s->ele[i].x;
        cin >> s->ele[i].i;
        cin >> s->ele[i].j;
        cin >> s->ele[i].x;
    }
}

void display(struct Sparse s){
    int k = 0;
    for(int i=0; i<s.m; i++){
        for(int j=0; j<s.n; j++){
            if(i==s.ele[k].i && j==s.ele[k].j){
                cout << s.ele[k].x << " ";
                k++;
            }
            else{
                cout << "0 ";
            }
        }
        cout << endl;
    }
}

int main(){
    struct Sparse s;
    create(&s);
    display(s);
}


