#include <iostream>
using namespace std;

class Heap{
    private:
    int *A;
    int index;
    int size;

    public:
    Heap(){size = 10; A = new int[size]; index=1;}
    Heap(int n){size = n; A = new int[size]; index=1;}
    void display();
    void insert(int key);
    int del();
};

void Heap::display(){
    cout << "[";
    for(int i=1; i<index; i++){
        cout << A[i] << ", ";
    }
    cout << "]" << endl;
}

void Heap::insert(int key){
    int i = index;
    A[i] = key;
    while(i > 1 && key > A[i/2]){
        A[i] = A[i/2];
        i /= 2;
    }
    A[i] = key;
    index++;
}

int Heap::del(){
    // In heap, del wiil remove the highest priority value.
    int key = A[1];
    A[1] = A[index-1];
    index--;
    int i = 1, j = i * 2, temp;
    while(j < index){
        if(j+1 < index && A[j+1] > A[j]){
            j += 1;
        }
        if(A[i] < A[j]){
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
            i = j;
            j = 2 * i;
        }
        else{
            break;
        }
    }
    return key;
}



int main(){
    Heap heap(20);
    heap.insert(2);
    heap.insert(5);
    heap.insert(3);
    heap.insert(7);
    heap.insert(1);

    heap.display();

    heap.del();
    heap.del();
    heap.display();
}