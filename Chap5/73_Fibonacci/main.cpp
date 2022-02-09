#include <iostream>
#include <stdio.h>
using namespace std;

int fibI(int n){
    int t0=0, t1=1, s=0, i;
    if(n<=1) return n;
    for(i=2;i<=n;i++){
        s = t0 + t1;
        t0 = t1;
        t1 = s;
    }
    return s;
}

int fibR(int n){
    if(n<=1) return n;
    return fibR(n-2) + fibR(n-1);
}

int F[10];
// Memoization
int fibM(int n){
    if(n <= 1){
        F[n] = n;
        return n;
    }
    else{
        if(F[n-2]==-1)
            F[n-2] = fibM(n-2);
        if(F[n-1]==-1)
            F[n-1] = fibM(n-1);
        F[n] = F[n-2] + F[n-1];
    }
    return F[n-2] + F[n-1];
}



int main(){
    for(int i=0; i<10; i++){
        F[i] = -1;
    }
    cout << fibM(10) << endl;
}
