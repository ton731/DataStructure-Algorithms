#include <iostream>
using namespace std;

/*
// array is always & only passed by address!!!
// void fun(int A[], int n){
void fun(int *A, int n){
    A[0] = 15;
    
}


int main(){
    int A[] = {2, 4, 6, 8, 10};
    int n = 5;
    fun(A, n);

    for(int i=0;i<n;i++){
        cout << A[i] << endl;
    }
}
*/


int * fun(int size){
    int *p;
    p = new int[size];

    for(int i=0; i<size; i++){
        p[i] = i + 1;
    }

    return p;
}


int main(){
    int *ptr;
    int sz = 5;

    ptr = fun(sz);

    for(int i=0; i<sz; i++){
        cout << ptr[i] << endl;
    }
}




