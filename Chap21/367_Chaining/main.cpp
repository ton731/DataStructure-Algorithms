#include <iostream>
using namespace std;

// Linked List Node
class Node{
    public:
    int data;
    Node *next;
};

// Hash Table
class HashTable{
    public:
    Node** HT;
	HashTable();
	int hash(int key);
	void insert(int key);
	int search(int key);
	~HashTable();
};

HashTable::HashTable(){
    HT = new Node* [10];
    for(int i=0; i<10; i++){
        HT[i] = nullptr;
    }
}

int HashTable::hash(int key){
    return key % 10;
}

void HashTable::insert(int key){
    int hash_index = hash(key);
    Node *t = new Node;
    t->data = key;
    t->next = nullptr;

    // Case: no nodes in the linked list
    if(HT[hash_index] == nullptr){
        HT[hash_index] = t;
    }
    else{
        // Traverse to find insert position
        Node *p = HT[hash_index];
        Node *q = HT[hash_index];
        while(p != nullptr && p->data < key){
            q = p;
            p = p->next;
        }
        // Case: first data is bigger than key
        if(q == HT[hash_index]){
            t->next = HT[hash_index];
            HT[hash_index] = t;
        }
        else{
            t->next = q->next;
            q->next = t;
        }
    }
}

int HashTable::search(int key){
    int hash_index = hash(key);
    Node *p = HT[hash_index];
    while(p != nullptr){
        if(p->data == key){
            return p->data;
        }
        p = p->next;
    }
    return -1;
}

HashTable::~HashTable(){
    for(int i=0; i<10; i++){
        Node *p = HT[i];
        while(HT[i] != nullptr){
            HT[i] = HT[i]->next;
            delete p;
            p = HT[i];
        }
    }
    delete [] HT;
}



int main() {
	int A[] = {16, 12, 25, 39, 6, 122, 5, 68, 75};
	int n = sizeof(A)/sizeof(A[0]);
	HashTable H;
	for(int i=0; i<n; i++){
		H.insert(A[i]);
	}
	cout << "Successful Search" << endl;
	int key = 6;
	int value = H.search(key);
	cout << "Key: " << key << ", Value: " << value << endl;
	cout << "Unsuccessful Search" << endl;
	key = 95;
	value = H.search(key);
	cout << "Key: " << key << ", Value: " << value << endl;

	return 0;
}

