#include <iostream>
#include <stdio.h>
using namespace std;




int main(){
    int length, breadth;
    printf("Enter Length and Breadth: ");
    cin >> length >> breadth;

    int area = length * breadth;
    int peri = 2 * (length + breadth);
    printf("Area = %d \nPerimeter = %d \n", area, peri);
    
}

