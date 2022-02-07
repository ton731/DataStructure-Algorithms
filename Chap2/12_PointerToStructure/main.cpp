#include <iostream>
#include <stdio.h>
using namespace std;


struct Rectangle{
    int length;
    int breadth;
};

int main(){
    
    struct Rectangle r = {10, 5};
    cout << r.length << endl;
    cout << r.breadth << endl;

    // struct Rectangle *p = &r;
    // // cout << p->length << endl;
    // // cout << p->breadth << endl;
    // cout << (*p).length << endl;
    // cout << (*p).breadth << endl;
    

    struct Rectangle *p;
    // p = (struct Rectangle *)malloc(sizeof(struct Rectangle));
    p = new struct Rectangle;

    p -> length = 15;
    p -> breadth = 17;

    cout << p->length << endl;
    cout << p->breadth << endl;  
}


