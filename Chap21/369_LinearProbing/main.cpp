#include <iostream>
#define SIZE 10

using namespace std;


template <class T>
void print(T& vec, int n, string s){
    cout << s << ": [" << flush;
    for (int i=0; i<n; i++){
        cout << vec[i] << flush;
        if (i < n-1){
            cout << ", " << flush;
        }
    }
    cout << "]" << endl;
}


// A Linear Probing hash table with "n" space should not contain more than "n/2" elements!
// Linear Probing deletion will cause the re-insert of all elements,
// hence it's not recommended to delete in Linear Probing.
class LinearProbingHash{
    private:
    int *HT;

    public:
    LinearProbingHash(){
        HT = new int[SIZE];
    }

    int hash(int key);
    int linearProbe(int key);
    void insert(int key);
    int search(int key);
    int* getHashTable();
};

int LinearProbingHash::hash(int key){
    return key % SIZE;
}

int LinearProbingHash::linearProbe(int key){
    int hash_index = hash(key);
    int i = 0;
    while(HT[(hash_index+i) % SIZE] != 0){
        i++;
    }
    return (hash_index + i) % SIZE;
}


void LinearProbingHash::insert(int key){
    int hash_index = hash(key);

    if(HT[hash_index] != 0){
        hash_index = linearProbe(key);
    }
    HT[hash_index] = key;
}

int LinearProbingHash::search(int key){
    int hash_index = hash(key);
    int i = 0;
    while(HT[(hash_index + i) % SIZE] != key){
        if(HT[(hash_index + i) % SIZE] == 0){
            return -1;
        }
        i++;
    }
    return (hash_index + i) % SIZE;
}

int* LinearProbingHash::getHashTable(){
    return HT;
}



int main(){
    int A[] = {26, 30, 45, 23, 25, 43, 74, 19, 29};
    int n = sizeof(A) / sizeof(A[0]);
    print(A, n, " A");

    // Hash table
    LinearProbingHash HT;
    for(int i=0; i<n; i++){
        HT.insert(A[i]);
    }

    int index = HT.search(25);
    cout << "key found at: " << index << endl;

    index = HT.search(35);
    cout << "key found at: " << index << endl;
}
