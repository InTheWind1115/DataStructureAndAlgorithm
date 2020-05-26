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
    int height;
} AVLNode;

typedef AVLNode * AVL; //AVL树的型

int Height(AVL F) {
    if (F == NULL)
        return 0;
    return F->height;
}

int Height_LR(AVL F) {
    if (F == NULL)
        return 0;
    return max(Height(F->lchild), Height(F->rchild)) + 1;
}


void RotateLL(AVL &F) {
    AVL R;
    R = F->lchild;
    F->lchild = R->rchild;
    R->rchild = F;
    F->height = Height_LR(F); //必须在前面
    R->height = Height_LR(R);
    F = R;
}

void RotateRR(AVL &F) {
    AVL R;
    R = F->rchild;
    F->rchild = R->lchild;
    R->lchild = F;
    F->height = Height_LR(F); //必须在前面
    R->height = Height_LR(R);
    F = R;
}

void RotateLR(AVL &F) {
    RotateRR(F->lchild);
    RotateLL(F);
}

void RotateRL(AVL &F) {
    RotateLL(F->lchild);
    RotateLL(F);
}

AVL SearchAVL (keytype k, AVL F) {
    AVL r = F;
    if (r == NULL)
        return NULL;
    if (r->data.key == k)
        return r;
    else if (r->data.key > k)
        return SearchAVL(k, F->lchild);
    else
        return SearchAVL(k, F->rchild);
}

int balance(AVL F) {
    if (F == NULL) 
        return 0;
    return Height(F->lchild) - Height(F->rchild);
    
}

void InsertAVL(records R, AVL &F) {// 在二叉查找树F中插入新记录R

    if (F == NULL) {
        F = new celltype;
        F->data = R;
        F->lchild = NULL;
        F->rchild = NULL;
    } else if (F->data.key < R.key) {
        InsertAVL(R, F->rchild);
        // 回退 F->rchild ----> F
        if (balance(F) == -2) {
            if (balance(F->rchild) <= 0) { // RR旋转
                RotateRR(F);
            } else { // RL旋转
                RotateRL(F);
            }
        }
    }
    else if (F->data.key > R.key) {
        InsertAVL(R, F->lchild);
        if (balance(F) == 2) { // LL LR
            if (balance(F->lchild) >= 0) { // LL旋转
                RotateLL(F);
            } else { // LR旋转
                RotateLR(F);
            }
        }
    }
        
    
    F->height = Height_LR(F);

}



AVL CreateAVL() {
    int n, i, key;
    char ele;
    records R;
    AVL F;
    cin>>n;
    for (i = 0; i < n; i++) {
        cin>>key>>ele;
        R.key = key;
        R.ele = ele;
        InsertAVL(R, F);
    }
    return F;
}

int DeleteB(keytype k, AVL &F, AVL fa) {
    AVL tmp;
    int ret;
    if (F == NULL)
        return 0;
    else if (F->data.key < k) {
        ret =  DeleteB(k, F->rchild, F);
        F->height = Height_LR(F);
        if (balance(F) ==  2) { // LL LR
            if (balance(F->lchild) >= 0) { // ll
                RotateLL(F);
            } else { //LR
                RotateLR(F);
            }
        }
    }
        
    else if (F->data.key > k) {
        ret = DeleteB(k, F->lchild, F);
        if (balance(F) ==  -2) { // RR RL
            if (balance(F->rchild) <= 0) { // RR
                RotateRR(F);
            } else { // RL
                RotateRL(F);
            }
        }

    } else {  //F->data.key == k
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

    return ret;
    
}

void inOrder(AVL F) {
    if (F == NULL)
        return;
    inOrder(F->lchild);
    cout<<F->data.key<<' ';
    if (F->lchild != NULL)
        cout<<"lchild: "<<F->lchild->data.key<<' ';
    if (F->rchild != NULL)
        cout<<"rchild: "<<F->rchild->data.key<<' ';
    cout<<endl;
    inOrder(F->rchild);
}

int main() {
    return 0;
}