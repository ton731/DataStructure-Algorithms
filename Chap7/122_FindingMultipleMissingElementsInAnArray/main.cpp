#include <iostream>
using namespace std;

void FindMultipleMissing(int *arr){
    int diff = arr[0] - 0;
    for(int i=0; i<10; i++){
        if(arr[i] - i > diff){
            while(arr[i] - i > diff){
                cout << "Missing: " << i+diff << endl;
                diff++;
            }
        }
    }
}

int main(){
    int arr[10] = {6, 7, 8, 9, 11, 12, 15, 16, 17, 18};
    FindMultipleMissing(arr);
}

