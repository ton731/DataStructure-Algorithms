#include <iostream>
#include <cmath>
using namespace std;

template <class T>
void print(T &vec, int n, string s){
    cout << s << ": [" << flush;
    for(int i=0; i<n; i++){
        cout << vec[i] << flush;
        if(i < n-1){
            cout << ", " << flush;
        }
    }
    cout << "]" << endl;
}


void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

int max(int A[], int n){
    int m = INT16_MIN;
    for(int i=0; i<n; i++){
        if(A[i] > m){
            m = A[i];
        }
    }
    return m;
}

// Linked List node
class Node{
    public:
    int value;
    Node *next;
};

int countDigits(int x){
    int count = 0;
    while(x != 0){
        x = x / 10;
        count++;
    }
    return count;
}



void bubbleSort(int A[], int n){
    int flag;
    for(int i=0; i<n-1; i++){
        flag = 0;
        for(int j=0; j<n-1-i; j++){
            if(A[j] > A[j+1]){
                swap(&A[j], &A[j+1]);
                flag = 1;
            }
        }
        if(flag == 0){
            break;
        }
    }
}

void insertionSort(int A[], int n){
    int j, x;
    for(int i=1; i<n; i++){
        x = A[i];
        j = i - 1;
        while(j >-1 && x < A[j]){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = x;
    }
}

void selectionSort(int A[], int n){
    int i, j, k;
    for(i=0; i<n-1; i++){
        for(j=k=i; j<n; j++){
            if(A[j] < A[k]){
                k = j;
            }
        }
        swap(&A[i], &A[k]);
    }
}

// QuickSort
// Using first element as pivot.
int partition(int A[], int low, int high){
    int pivot = A[low];
    int i = low + 1;
    int j = high;

    while(true){
        while(i <= j && A[i] <= pivot){i++;}
        while(i <= j && A[j] >= pivot){j--;}
        if(i <= j){swap(&A[i], &A[j]);}
        else{break;}
    }

    swap(&A[low], &A[j]);
    return j;
}



void quickSort(int A[], int low, int high){
    if(low < high){
        int p = partition(A, low, high);
        quickSort(A, low, p-1);
        quickSort(A, p+1, high);
    }
}


// MergeSort
void merge(int A[], int low, int mid, int high){
    int B[high+1];
    int i=low, j=mid+1, k=low;
    while(i <= mid && j <= high){
        if(A[i] <= A[j]){
            B[k++] = A[i++];
        }
        else{
            B[k++] = A[j++];
        }
    }
    while(i <= mid){
        B[k++] = A[i++];
    }
    while(j <= high){
        B[k++] = A[j++];
    }
    for(int i=low; i<=high; i++){
        A[i] = B[i];
    }
}

void mergeSort(int A[], int n){
    int p;
    int low, mid, high, i;
    for(p=2; p<=n; p*=2){
        for(i=0; i+p-1<n; i+=p){
            low = i;
            high = i + p - 1;
            mid = (low + high) / 2;
            merge(A, low, mid, high);
        }
        if(n-i > p/2){
            low = i;
            high = i + p - 1;
            mid = (low + high) / 2;
            merge(A, low, mid, high);
        }
    }
    if(p/2 < n){
        merge(A, 0, p/2-1, n-1);
    }
}

void rMergeSort(int A[], int low, int high){
    if(low < high){
        int mid = (low + high) / 2;
        rMergeSort(A, low, mid);
        rMergeSort(A, mid+1, high);
        merge(A, low, mid, high);
    }
}


void countSort(int A[], int n){
    // Find the largest number
    int max_num = max(A, n);

    // Create empty list
    int C[max_num+1];
    for(int i=0; i<max_num+1; i++){
        C[i] = 0;
    }

    // Fill the count
    for(int i=0; i<n; i++){
        C[A[i]]++;
    }

    // Fill it back to A
    int i=0, j=0;
    while(i <= max_num){
        if(C[i] > 0){
            A[j++] = i;
            C[i]--;
        }
        else{
            i++;
        }
    }
}



// Helper functions for binSort & radixSort
void initializeBins(Node* *p, int n){
    for(int i=0; i<n; i++){
        p[i] = nullptr;
    }
}


void binInsert(Node **ptrBins, int idx){
    Node *temp = new Node;
    temp->value = idx;
    temp->next = nullptr;

    if(ptrBins[idx] == nullptr){
        ptrBins[idx] = temp;
    }
    else{
        Node *p = ptrBins[idx];
        while(p->next){
            p = p->next;
        }
        p->next = temp;
    }
}

int binDelete(Node **ptrBins, int idx){
    Node *p = ptrBins[idx];
    ptrBins[idx] = ptrBins[idx]->next;
    int x = p->value;
    delete p;
    return x;
}

void binSort(int A[], int n){
    int max_num = max(A, n);

    // Create bins array;
    Node* *bins = new Node* [max_num+1];

    // Initialize bins array with nullptr
    for(int i=0; i<max_num+1; i++){
        bins[i] = nullptr;
    }

    // Update count array values vased on A values
    for(int i=0; i<n; i++){
        binInsert(bins, A[i]);
    }

    // Update A with sorted elements
    int i=0, j=0;
    while(i < max_num+1){
        while(bins[i]){
            A[j++] = binDelete(bins, i);
        }
        i++;
    }

    // Delete heap memory
    delete [] bins;
}


// Helper function for radixSort
int getBinIndex(int x, int idx){
    return (int)(x / pow(10, idx)) % 10;
}

void radixInsert(Node **ptrBins, int value, int idx){
    Node *temp = new Node;
    temp->value = value;
    temp->next = nullptr;

    if(ptrBins[idx] == nullptr){
        ptrBins[idx] = temp;
    }
    else{
        Node *p = ptrBins[idx];
        while(p->next){
            p = p->next;
        }
        p->next = temp;
    }
}

void radixSort(int A[], int n){
    int max_num = max(A, n);
    int nPass = countDigits(max_num);

    // Create bins array
    Node* *bins = new Node* [10];

    // Initialize bins array with nullptr
    initializeBins(bins, 10);

    // Update bins and A for nPass times
    for(int pass=0; pass<nPass; pass++){
        // Update bins based on A values
        for(int i=0; i<n; i++){
            int binIndex = getBinIndex(A[i], pass);
            radixInsert(bins, A[i], binIndex);
        }

        // Update A with sorted elements from bin
        int i=0, j=0;
        while(i<10){
            while(bins[i] != nullptr){
                A[j++] = binDelete(bins, i);
            }
            i++;
        }
        // Initialize bins with nullptr again
        initializeBins(bins, 10);
    }

    // Delete heap memory
    delete [] bins;
}




int main(){
    int A[] = {3, 1, 6, 8, 2, 7, 4};
    int n = 7;
    print(A, n, "A");
    // selectionSort(A, n);
    // quickSort(A, 0, n-1);
    // mergeSort(A, n);
    // rMergeSort(A, 0, n-1);
    // countSort(A, n);
    // binSort(A, n);
    radixSort(A, n);
    print(A, n, "Sorted A");
}

