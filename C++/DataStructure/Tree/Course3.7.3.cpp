#include <iostream>
#include <string>
using namespace std;
#define INF 0x3f3f3f
#define N 100
#define M 2 * (N) - 1
typedef int element;
typedef int elementtype;

typedef struct node{
    double weight;
    int lchild;
    int rchild;
    int parent;
    node(): lchild(-1), rchild(-1), parent(-1), weight(0.0) {};
}HTNODE;

typedef HTNODE HuffmanT[M];
int vis[M];

//p为最小，q为次小
void findMin(HuffmanT hu, int k, int &p, int &q) {
    p = q =  k - 1;
    int i;
    for (i = k - 2; i >= 0; i--) {
        if (vis[i] == 1)
            continue;
        if (hu[i].weight < hu[p].weight) { //很巧妙的算法
            p = i;
            q = p;
        } else if (hu[i].weight < hu[q].weight)
            q = i;
        
    }
}

//创建一个霍夫曼树，其外节点为leaf中的前n个元素.根节点为：2 * n - 1
void createHF(HuffmanT hu, int leaf[], int n) {
    int i, p, q;
    for (i = 0; i < n; i++) {
        hu[i].weight = leaf[i];
    }
    // i = n
    memset(vis, 0, sizeof(vis));
    while (i < 2 * n -1) {
        findMin(hu, i, p, q);
        vis[p] = vis[q] = 1;
        hu[i].lchild = p;
        hu[i].rchild = q;
        hu[p].parent = hu[q].parent = i;
        hu[i].weight = hu[p].weight + hu[q].weight;
        i++;
    }
    
    
}

void error(char str[]) {
    cout<<str<<endl;
}
 
int main() {
    
    system("pause");
    return 0;
}