#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct Rectangle{
    int length;
    int breadth;
};


int main(){
    /*
    // In stack...
    int A[5] = {2, 4, 6, 8, 10};
    int *p;
    p = A;
    */
    
    /*
    // In heap...
    int *p;
    // in c:
    // p = (int *)malloc(5 * sizeof(int));
    // in c++:
    p = new int[5];

    p[0] = 10;
    p[1] = 15;
    p[2] = 14;
    p[3] = 21;
    p[4] = 31;

    for(int i = 0;i<5;i++){
        cout << p[i] << endl;
    }

    // After using memory in heap, you have to delete the usage...
    // in c:
    // free(p);
    // in c++:
    delete [] p;
    */


   int *p1;
   char *p2;
   float *p3;
   double *p4;
   struct Rectangle *p5;

   cout << sizeof(p1) << endl;
   cout << sizeof(p2) << endl;
   cout << sizeof(p3) << endl;
   cout << sizeof(p4) << endl;
   cout << sizeof(p5) << endl;

}