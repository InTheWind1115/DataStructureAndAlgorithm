#include<iostream>
#include<algorithm>
using namespace std;
#define VerNum 100
#define EdgeNum 1000
int father[VerNum];
int n, e;

struct node {
    int u;
    int v;
    int w;
    bool operator<(const node &n1)const {
        return w < n1.w;
    }
}Edge[EdgeNum];

int find(int x) {
    if (father[x] == -1)
        return x;
        father[x] = find(father[x]);    //路径压缩
        return father[x];
}


void merge(int x, int y) {
    x = find(x), y = find(y);
    if (x != y) 
        father[x] = y;
}

int main() {
    int u, v, w;
    int i;
    for (i = 0; i < VerNum;i++) {
        father[i] = -1;
    }
    cin>>n>>e;
    for (i = 0; i < e; i++) {
        cin>>Edge[i].u>>Edge[i].v>>Edge[i].w;
    }
    sort(Edge, Edge + e); //O(e*log e)
    int n1 =  n, e1 = 0;
    while (n1 > 1) { // O(n)
        u = Edge[n1].u;
        v = Edge[n1].v;
        w = Edge[n1].w;
        if (find(u) != find(v)) {
            merge(u, v);
            cout<<'('<<u<<','<<v<<','<<w<<')'<<endl;
            n1--;
        }
        e1++;
    }
    return 0;
}