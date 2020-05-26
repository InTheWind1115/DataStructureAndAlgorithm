#include<iostream>
using namespace std;

typedef int keytype;
typedef struct recordtype {
    keytype key;
    char ele;
}records;

typedef struct celltype {
    records data;
    struct celltype *lchild , *rchild;
} BSTNode;

typedef BSTNode * BST; //二叉查找树的型

BST SearchBST (keytype k, BST F) {
    BST r = F;
    if (r == NULL)
        return NULL;
    if (r->data.key == k)
        return r;
    else if (r->data.key > k)
        return SearchBST(k, F->lchild);
    else
        return SearchBST(k, F->rchild);
}

void InsertBST(records R, BST F) {// 在二叉查找树F中插入新记录R

    if (F == NULL) {
        F = new celltype;
        F->data = R;
        F->lchild = NULL;
        F->rchild = NULL;
    } else if (F->data.key < R.key)
        InsertBST(R, F->rchild);
    else if (F->data.key > R.key)
        InsertBST(R, F->lchild);
    else
        return;

}

BST CreateBST() {
    int n, i, key;
    char ele;
    records R;
    BST F;
    cin>>n;
    for (i = 0; i < n; i++) {
        cin>>key>>ele;
        R.key = key;
        R.ele = ele;
        InsertBST(R, F);
    }
    return F;
}

int DeleteB(keytype k, BST &F, BST fa) {
    BST tmp;
    if (F == NULL)
        return 0;
    else if (F->data.key < k)
        return DeleteB(k, F->rchild, F);
    else if (F->data.key > k)
        return DeleteB(k, F->lchild, F);
    else {  //F->data.key == k
        if (F->lchild == NULL && F->rchild == NULL) {   //F为叶节点
            if (fa != NULL && fa->lchild == F) {    //F为fa的左分支
                fa->lchild = NULL;
            } else if (fa != NULL && fa->rchild == F) {    //F为fa的右分支
                fa->rchild = NULL;
            }
            delete F;
            F = NULL;
        } else if (F->lchild == NULL) { // F只有右子树
            tmp = F->rchild;
            F->data = tmp->data;
            F->lchild = tmp->lchild; 
            F->rchild = tmp->rchild; 
            delete tmp;
            tmp = NULL;
        } else if (F->rchild == NULL) { // F只有左子树
            tmp = F->lchild;
            F->data = tmp->data;
            F->lchild = tmp->lchild; 
            F->rchild = tmp->rchild;
            delete tmp;
            tmp = NULL;
        } else {
            // 找继承节点
            tmp = F->rchild;
            while (tmp->lchild != NULL) {
                tmp = tmp->lchild;
            }
            F->data = tmp->data;
            DeleteB(tmp->data.key, F->rchild, F);
        }
    }
    
}


int main() {
    return 0;
}