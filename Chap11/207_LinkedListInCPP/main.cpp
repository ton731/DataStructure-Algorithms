#include <iostream>
#include "linkedlist.h"
using namespace std;

int main(){
    int A[] = {1, 3, 5, 7, 9, 11};
    linkedlist::LinkedList list(A, 5);
    list.Display();
}

