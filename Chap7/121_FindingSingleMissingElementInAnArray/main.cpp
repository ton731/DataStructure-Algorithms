#include <iostream>
using namespace std;

void FindSingleMissing(int *arr){
    int diff = arr[0] - 0;
    int i = 0;
    while(true){
        if(arr[i] - i > diff){
            cout << "Missing: " << i+diff << endl;
            return;
        }
        i++;
    }
}

int main(){
    int arr[10] = {3, 4, 5, 6, 8, 9, 10, 11, 12, 13};
    FindSingleMissing(arr);
}

