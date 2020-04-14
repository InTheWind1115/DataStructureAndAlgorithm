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
    return g.edge[v1][v2];
}

void newNode(MTGraph &g, VertexData v) {
    g.vexlist[g.n] = v;
    g.n++;
}

void setSucc(MTGraph &g, int v1, int v2) {
    if (isEdge(g, v1, v2))
        return;
    g.e++;
    g.edge[v1][v2] = 1;
    g.edge[v2][v1] = 1;
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
    int i, j, x, y;
    //memset(g.edge, 0, sizeof(g.edge));
    for (i = 0; i < g.n; i++) {
        for (j = 0; j < g.n; j++) {
            g.edge[i][j] = INF;
        }
    }
    g.n = g.e = 0;
    cin>>g.n>>g.e;

    for(i = 0; i < g.n; i++) {
        cin>>g.vexlist[i];
    }

    for(i = 0; i < g.e; i++) {
        cin>>x>>y;
        setSucc(g, x, y);
    }
}

void prime(MTGraph g) {
    int min;
    int i, j, k, t = g.n-1;
    
    //lowcost的下标代表着v - u 中的节点，存的是最小权值                                                                                                                                                                                                                                                         
    int lowcost[NumVertices], closeset[NumVertices], u[NumVertices];
    u[0] = 1;
    for (i = 0; i < g.n; i++) {
        lowcost[i] = g.edge[0][i];
        closeset[i] = 0;
        u[i] = 0;
    }

    while (t--) {
        min = lowcost[1], k = 1;
        for (i = 2; i < g.n; i++) { //可以用最小堆优化O(logn), STL priority_queue
            if (lowcost[i] < min) {
                min = lowcost[i];
                k = i;
            }
        }
        u[k] = 1;
        //cout<<k<<","<<closeset[k]<<endl;
        for (i = 1; i < g.n; i++) { /////////////2??
            if (lowcost[i] < g.edge[k][i] && u[i] == 0) {
                lowcost[i] = g.edge[k][i];
                closeset[i] = k;
            }
        }
    }

    for (i = 1; i < g.n; i++) {
        cout<<i<<','<<closeset[i]<<endl;
    }

}

int main() {
    MTGraph g;
    createMTGraph(g);
    prime(g);
    system("pause");
    return 0;
}