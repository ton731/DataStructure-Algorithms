#include <iostream>
using namespace std;

template <class T>
class Array{
private:
    T *A;
    int size;
    int length;
public:
    Array(){
        size = 10;
        A = new T[size];
        length = 0;
    }
    Array(int sz){
        size = sz;
        A = new T[size];
        length = 0;
    }
    ~Array(){
        delete []A;
    }
    void Display();
    void Insert(int index, T x);
    int Delete(int index);
};

template <class T>
void Array<T>::Display(){
    cout << "Elements are: " << endl;
    for(int i=0; i<length; i++){
        cout << A[i] << ", ";
    }
    cout << endl;
}

template <class T>
void Array<T>::Insert(int index, T x){
    if(index >= 0 && index <= length){
        for(int i=length; i>index; i--){
            A[i] = A[i-1];
        }
        A[index] = x;
        length++;
    }
}

template <class T>
int Array<T>::Delete(int index){
    int x;
    if(index >= 0 && index < length){
        x = A[index];
        for(int i=index; i<length-1; i++){
            A[i] = A[i+1];
        }
        length--;
        return x;
    }
    return 0;
}


int main(){
    Array<char> arr(10);

    arr.Insert(0, 't');
    arr.Insert(1, 'o');
    arr.Insert(2, 'n');
    arr.Display();
    cout << arr.Delete(1) << endl;
    arr.Display();
}