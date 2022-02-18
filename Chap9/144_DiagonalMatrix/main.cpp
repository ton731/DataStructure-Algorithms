#include <iostream>
using namespace std;

struct Matrix{
    int A[10];
    int n;
};


void Set(struct Matrix *m, int i, int j, int x){
    if(i == j){
        m->A[i] = x;
    }
}

int get(struct Matrix m, int i, int j){
    if(i == j){
        return m.A[i];
    }
    else{
        return 0;
    }
}

void Display(struct Matrix m){
    for(int i=0; i<m.n; i++){
        for(int j=0; j<m.n; j++){
            if(i == j){
                cout << m.A[i] << " ";
            }
            else{
                cout << "0 ";
            }
        }
        cout << endl;
    }
}

int main(){
    struct Matrix m;
    m.n = 4;
    Set(&m, 0, 0, 5);
    Set(&m, 1, 1, 8);
    Set(&m, 2, 2, 4);
    Set(&m, 3, 3, 1);
    Display(m);
}

