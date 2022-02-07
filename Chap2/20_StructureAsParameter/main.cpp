#include <iostream>
using namespace std;

struct Rectangle{
    int length;
    int breadth;
};

struct Rectangle * fun(){
    struct Rectangle *p;
    p = new struct Rectangle;
    p -> length = 15;
    p -> breadth = 12;
    return p;
}

int main(){
    struct Rectangle *ptr = fun();
    cout << "Length: " << ptr -> length << endl;
    cout << "Breadth: " << ptr -> breadth << endl;
}

