#include <iostream>
#include <stdio.h>
using namespace std;

struct Rectangle{
    int length;
    int breadth;
    char x;
};


int main(){
    struct Rectangle r1 = {10, 5, 'a'};
    r1.length = 15;
    r1.breadth = 7;

    // printf("%lu", sizeof(r1));
    cout << r1.length << endl;
    cout << r1.breadth << endl;

    return 0;
}


