#include<iostream>
#include<cstring>
using namespace std;

#define INF 0x3f3f3f3f
#define NumEdges 10000//边条数 
#define NumVertices 100//顶点个数
typedef char VertexData;//顶点数据类型
typedef int EdgeData;//边上权值类型，数值
typedef int *listofnode;

//无向无权图
typedef struct {
    VertexData vexlist[NumVertices];//顶点表
    EdgeData edge[NumVertices][NumVertices];//邻接矩阵-边表，可视为边之间的关系
    int n, e;//图中当前的顶点个数与边数
}MTGraph;

bool isEdge(MTGraph g, int v1, int v2) {
    return g.edge[v1][v2] != INF;
}

void newNode(MTGraph &g, VertexData v) {
    g.vexlist[g.n] = v;
    g.n++;
}

void setSucc(MTGraph &g, int v1, int v2, int w) {
    if (isEdge(g, v1, v2))
        return;
    g.e++;
    g.edge[v1][v2] = w;
    //g.edge[v2][v1] = 1;
}

void delSucc(MTGraph &g, int v1, int v2) {
    if (!isEdge(g, v1, v2))
        return;
    g.e--;
    g.edge[v1][v2] = 0;
    g.edge[v2][v1] = 0;
}

//返回v的直接后继顶点序列
int *succ(MTGraph g, int v) {
    int *ret = new int[NumVertices];
    int i, k = 0;
    for (i = 0;i < g.n;  i++) {
        if (g.edge[v][i])
            ret[k++] = i;
    }
    ret[k] = -1;
    return ret;
}

//删除顶点v 
void delNode(MTGraph &g, int v) {
    int i, j;
    for (i = 0; i < g.n; i++) {
        if (g.edge[v][i]) {
            g.e--;
            g.edge[v][i] =  0;
            g.edge[i][v] =  0;
        }
    }

    for (i = v + 1; i < g.n; i++) { //行
        for (j = 0; j < g.n; j++) { //列
            g.edge[i - 1][j] = g.edge[i][j];
        }
    }
    
    for (i = v + 1; i < g.n; i++) { //列
        for (j = 0; j < g.n - 1; j++) { //行
            g.edge[j][i - 1] = g.edge[j][i];
        }
    }

    for (i = v + 1; i < g.n; i++) {
        g.vexlist[i - 1] = g.vexlist[i];
    }

    g.n--;
}

void createMTGraph(MTGraph &g) {
    int i, j, x, y, w;
    memset(g.edge, 0, sizeof(g.edge));
    for (i = 0; i < NumVertices; j++) {
        for (j = 0; j < NumVertices; j++) {
            g.edge[i][j] = INF;
        }
    }
    cin>>g.n>>g.e;

    for(i = 0; i < g.n; i++) {
        cin>>g.vexlist[i];
    }

    for(i = 0; i < g.e; i++) {
        cin>>x>>y>>w;
        setSucc(g, x, y, w);
    }
}

void floyed(MTGraph g, int d[NumVertices][NumVertices], int p[NumVertices][NumVertices]) {
    int i, j, k;
    for (i = 0; i < g.n; i++) {
        for (j = 0; j < g.n; j++) {
            d[i][j] = g.edge[i][j];
            p[i][j] = -1;
        }
    }

    for (k = 0; k < g.n; k++) {
        for (i = 0; i < g.n; i++) {
            for (j = 0; j < g.n; j++) {
                if (d[i][j] > d[i][k] + d[k][j]) {
                    d[i][j] = d[i][k] + d[k][j];
                    p[i][j] = k;
                }
            }
        }
    }
}
// O(g*n^3)

void printPath(MTGraph g,int p[NumVertices][NumVertices], int u, int v) {
    int k;
    if (p[u][v] == -1)
        cout<<"<"<<g.vexlist[u]<<","<<g.vexlist[v]<<">";
    k = p[u][v];
    printPath(g, p, u, k);
    printPath(g, p, k, v);
}

int main() {
    MTGraph g;
    int i, j;
    int d[NumVertices][NumVertices], p[NumVertices][NumVertices];
    createMTGraph(g);
    floyed(g, d, p);
    printPath(g, p, 0, 2);

    int par[NumVertices], center;
    // 求偏心度
    for (j = 0; j < g.n; j++) {
        par[j] = d[0][j];
        for (i = 0; i < g.n; i++) {
            if (par[j] < d[i][j])
                par[j] = d[i][j];
        }
    }
    center = 0;
    for (i = 1; i < g.n; i++) {
        if (par[i]<par[center])
            center = i;
    }
    cout<<center;
    system("pause");
    return 0;
}