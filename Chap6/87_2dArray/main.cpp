#include <iostream>
#include <stdio.h>
using namespace std;

int main(){
    int A[2][3] = {{1, 2, 3}, {2, 3, 4}};

    int *B[2];
    B[0] = new int[3];
    B[1] = new int[3];

    int **C;
    C = new int*[2];
    C[0] = new int[3];
    C[1] = new int[3];

    for(int i=0; i<2; i++){
        for(int j=0; j<3; j++){
            cout << C[i][j] << " "; 
        }
        cout << endl;
    }

}


