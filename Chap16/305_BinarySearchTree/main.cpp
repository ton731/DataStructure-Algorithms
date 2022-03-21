#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *lchild;
    Node *rchild;
    Node(){
        lchild = nullptr;
        rchild = nullptr;
    }
};


class BinarySearchTree{
    private:
    Node *root;

    public:
    BinarySearchTree(){root = nullptr;}
    Node* getRoot(){return root;}
    void insert(int key);
    void inOrder(){inOrder(root);}
    void inOrder(Node *p);
    Node* search(int key);
    Node* del(Node *p, int key);
    int height(Node *p);
    Node* inPredecessor(Node *p);
    Node* inSuccessor(Node *p);
};


void BinarySearchTree::insert(int key){
    Node *p, *t;
    if(root == nullptr){
        p = new Node;
        p->data = key;
        root = p;
        return;
    }
    p = root;
    while(p){
        t = p;
        if(key == p->data){
            cout << "key: " << key << "is already in the tree!";
            return;
        }
        else if(key < p->data){
            p = p->lchild;
        }
        else{
            p = p->rchild;
        }
    }
    p = new Node;
    p->data = key;
    if(key < t->data){
        t->lchild = p;
    }
    else{
        t->rchild = p;
    }
}

void BinarySearchTree::inOrder(Node *p){
    if(p == nullptr){
        return;
    }
    inOrder(p->lchild);
    cout << p->data << ", ";
    inOrder(p->rchild);
}


Node* BinarySearchTree::search(int key){
    Node *p = root;
    while(p){
        if(key == p->data){
            return p;
        }
        else if(key < p->data){
            p = p->lchild;
        }
        else{
            p = p->rchild;
        }
    }
    return nullptr;
}

Node* BinarySearchTree::del(Node *p, int key){
    Node *q;

    if(p == nullptr){
        return nullptr;
    }
    if(p->lchild == nullptr && p->rchild == nullptr){
        if(p == root){
            root = nullptr;
        }
        delete p;
        return nullptr;
    }
    if(key < p->data){
        p->lchild = del(p->lchild, key);
    }
    else if (key > p->data){
        p->rchild = del(p->rchild, key);
    }
    else{
        if(height(p->lchild) > height(p->rchild)){
            q = inPredecessor(p->lchild);
            p->data = q->data;
            p->lchild = del(p->lchild, q->data);
        }
        else{
            q = inSuccessor(p->rchild);
            p->data = q->data;
            p->rchild = del(p->rchild, q->data);
        }
    }
    return p;
}

int BinarySearchTree::height(Node *p){
    int x, y;
    if(p == nullptr){
        return 0;
    }
    x = height(p->lchild);
    y = height(p->rchild);
    return x>y ? x+1 : y+1;
}

Node* BinarySearchTree::inPredecessor(Node *p){
    while(p && p->rchild){
        p = p->rchild;
    }
    return p;
}

Node* BinarySearchTree::inSuccessor(Node *p){
    while(p && p->lchild){
        p = p->lchild;
    }
    return p;
}



int main(){
    BinarySearchTree tree;
    tree.insert(5);
    tree.insert(15);
    tree.insert(2);
    tree.insert(3);
    tree.insert(7);
    tree.insert(18);

    tree.inOrder();
    cout << endl;
    cout << "15 is in tree: " << (tree.search(15) ? 1 : 0) << endl; 

    tree.del(tree.getRoot(), 7);
    tree.inOrder();
    cout << endl;


}






