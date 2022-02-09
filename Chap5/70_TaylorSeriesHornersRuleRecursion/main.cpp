#include <iostream>
#include <stdio.h>
using namespace std;

double e(int x, int n){
    static double s;
    if(n == 0){
        return s;
    }
    s = 1 + s * x/n;
    return e(x, n-1);
}


int main(){
    cout << e(1, 10) << endl;
}

