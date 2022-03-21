#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    int height;
    Node *lchild;
    Node *rchild;
    Node(){
        lchild = nullptr;
        rchild = nullptr;
    }
};


class AVL{
    private:
    Node *root;

    public:
    AVL(){root = nullptr;}
    Node* getRoot(){return root;}

    void insert(int key){insert(getRoot(), key);}
    Node* insert(Node *p, int key);
    // Helper methods for inserting
    int nodeHeight(Node* p);
    int balanceFactor(Node* p);
    Node* llRotation(Node* p);
    Node* rrRotation(Node* p);
    Node* lrRotation(Node* p);
    Node* rlRotation(Node* p);


    void inOrder(){inOrder(root); cout<<endl;}
    void inOrder(Node *p);
    Node* search(int key);
    void del(int key){del(getRoot(), key);}
    Node* del(Node *p, int key);
    int height(Node *p);
    Node* inPredecessor(Node *p);
    Node* inSuccessor(Node *p);
};


Node* AVL::insert(Node *p, int key){
    if(p == nullptr){
        Node *t = new Node;
        t->data = key;
        t->height = 1;
        if(p == root){
            root = t;
        }
        return t;
    }
    if(key < p->data){
        p->lchild = insert(p->lchild, key);
    }
    else if(key > p->data){
        p->rchild = insert(p->rchild, key);
    }

    // update height
    p->height = nodeHeight(p);

    // balance factor and rotation
    if(balanceFactor(p) == 2 && balanceFactor(p->lchild) == 1){
        return llRotation(p);
    }
    else if(balanceFactor(p) == 2 && balanceFactor(p->lchild) == -1){
        return lrRotation(p);
    }
    else if(balanceFactor(p) == -2 && balanceFactor(p->rchild) == -1){
        return rrRotation(p);
    }
    else if(balanceFactor(p) == -2 && balanceFactor(p->rchild) == 1){
        return rlRotation(p);
    }
    return p;
}


int AVL::nodeHeight(Node *p){
    if(p == nullptr){
        return 0;
    }
    int lh, rh;
    lh = nodeHeight(p->lchild);
    rh = nodeHeight(p->rchild);
    return lh>rh ? lh+1 : rh+1;
}

int AVL::balanceFactor(Node *p){
    int lh, rh;
    lh = p && p->lchild ? p->lchild->height : 0;
    rh = p && p->rchild ? p->rchild->height : 0;
    return lh - rh;
}

Node* AVL::llRotation(Node *p){
    Node *pl = p->lchild;
    Node *plr = pl->rchild;

    p->lchild = plr;
    pl->rchild = p;

    // update height
    p->height = nodeHeight(p);
    pl->height = nodeHeight(pl);

    // update root if need
    if(p == root){
        root = pl;
    }
    return pl;
}

Node* AVL::lrRotation(Node *p){
    Node *pl = p->lchild;
    Node *plr = pl->rchild;

    p->lchild = plr->rchild;
    pl->rchild = plr->lchild;
    plr->lchild = pl;
    plr->rchild = p;

    // update height
    p->height = nodeHeight(p);
    pl->height = nodeHeight(pl);
    plr->height = nodeHeight(plr);

    if(p == root){
        root = plr;
    }
    return plr;
}

Node* AVL::rrRotation(Node *p){
    Node *pr = p->rchild;
    Node *prl = pr->lchild;

    p->rchild = prl;
    pr->lchild = p;

    p->height = nodeHeight(p);
    pr->height = nodeHeight(pr);

    if(p == root){
        root = pr;
    }
    return pr;
}

Node* AVL::rlRotation(Node *p){
    Node *pr = p->rchild;
    Node *prl = pr->lchild;

    p->rchild = prl->lchild;
    pr->lchild = prl->rchild;
    prl->lchild = p;
    prl->rchild = pr;

    p->height = nodeHeight(p);
    pr->height = nodeHeight(pr);
    prl->height = nodeHeight(prl);

    if(p == root){
        root = prl;
    }
    return prl;
}


void AVL::inOrder(Node *p){
    if(p == nullptr){
        return;
    }
    inOrder(p->lchild);
    cout << p->data << ", ";
    inOrder(p->rchild);
}


Node* AVL::search(int key){
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

Node* AVL::del(Node *p, int key){
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

    // Update height
    p->height = nodeHeight(p);
 
    // Balance Factor and Rotation
    if (balanceFactor(p) == 2 && balanceFactor(p->lchild) == 1) {  // L1 Rotation
        return llRotation(p);
    } else if (balanceFactor(p) == 2 && balanceFactor(p->lchild) == -1){  // L-1 Rotation
        return lrRotation(p);
    } else if (balanceFactor(p) == -2 && balanceFactor(p->rchild) == -1){  // R-1 Rotation
        return rrRotation(p);
    } else if (balanceFactor(p) == -2 && balanceFactor(p->rchild) == 1){  // R1 Rotation
        return rlRotation(p);
    } else if (balanceFactor(p) == 2 && balanceFactor(p->lchild) == 0){  // L0 Rotation
        return llRotation(p);
    } else if (balanceFactor(p) == -2 && balanceFactor(p->rchild) == 0){  // R0 Rotation
        return rrRotation(p);
    }
    return p;
}

int AVL::height(Node *p){
    int x, y;
    if(p == nullptr){
        return 0;
    }
    x = height(p->lchild);
    y = height(p->rchild);
    return x>y ? x+1 : y+1;
}

Node* AVL::inPredecessor(Node *p){
    while(p && p->rchild){
        p = p->rchild;
    }
    return p;
}

Node* AVL::inSuccessor(Node *p){
    while(p && p->lchild){
        p = p->lchild;
    }
    return p;
}



int main(){
    AVL tree;
    tree.insert(5);
    tree.insert(15);
    tree.insert(2);
    tree.insert(3);
    tree.insert(7);
    tree.insert(18);

    tree.inOrder();

    tree.del(5);
    tree.inOrder();
}






