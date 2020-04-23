#include<iostream>
using namespace std;
#define NumVertices 100
#define INF 0x3f3f3f3f
typedef int EdgeData;
typedef int VertexData;

//边
typedef struct node {
    int adjvex; //边的尾节点
    EdgeData cost;  //边的权重
    struct node *next; //下一条边
}EdgeNode;

//顶点
typedef struct {
    VertexData vertex;  //顶点的数据
    EdgeNode *firstEdge;
}VertexNode;

typedef struct {
    VertexNode vexList[NumVertices];
    int n, e;
}AdjGraph;

bool isEdge(AdjGraph g, int v1, int v2) {
    EdgeNode *head = g.vexList[v1].firstEdge;
    while (head != NULL) {
        if (head -> adjvex == v2)
            return true;
        head = head -> next;
    }
    return false;
}

void newNode(AdjGraph &g, VertexData v) {
    g.vexList[g.n].vertex = v;
    g.vexList[g.n].firstEdge = new EdgeNode;
    g.vexList[g.n].firstEdge -> next = NULL;
    g.n++;
}

//这里针对无向图 【我觉得针对有向图】
void setSucc(AdjGraph &g, int v1, int v2) {
    if (isEdge(g, v1, v2))
        return;
    g.e++;
    EdgeNode *temp = new EdgeNode, *temp1 = g.vexList[v1].firstEdge;
    temp -> adjvex = v2;
    temp -> next = temp1 -> next;
    temp1 -> next = temp;
}

//O(2e + n)[无向图]
void createAdjGraph(AdjGraph &g) {
    int i, j, x, y;
    cin>>g.n>>g.e;

    for(i = 0; i < g.n; i++) {
        cin>>g.vexList[i].vertex;
    }

    for(i = 0; i < g.e; i++) {
        cin>>x>>y;
        setSucc(g, x, y); //对无向图而言
        setSucc(g, y, x);
    }
}

int visited[NumVertices], dfn[NumVertices];
int count;

void dfs(AdjGraph g, int x) {
    int i;
    visited[x] = 1;
    dfn[x] = count;
    count++;
    EdgeNode *h = g.vexList[x].firstEdge;//从顶点x出发能直接到达的点所构成的链表的头节点
    h = h -> next;
    while (h != NULL) {
        i = h -> adjvex;
        if (visited[i] == 0)
            dfs(g, i);
        h = h -> next;
    }
}


//st: 源点的编号
void dijkstra(AdjGraph g, int st,int d[NumVertices], int path[NumVertices]) {
    int i, s[NumVertices];
    int j;
    for (i = 1; i <= g.n; i++) {
        d[i] = INF;
        path[i] = st;
    }
    s[st] = 1; //将源点加入s
    EdgeNode *p;
    p = g.vexList[st].firstEdge;
    if (p != NULL)
        p = p->next;
    while (p) {
        j = p -> adjvex;
        d[j] = p->cost;
        p = p->next;
    }

    int t = g.n - 2;
    int min, w;
    while (t--) {
        min = INF;
        for (i = 1; i <= g.n; i++) {
            if (s[i] == 0 && d[i] < min) {
                min = d[i];
                w = i;
            }
        }
        s[w] = 1;

        p = g.vexList[w].firstEdge;
        if (p != NULL)
            p = p->next;
        while (p) {
            j = p -> adjvex; //<w, j>为一条边
            if (s[j] == 0 && d[j] > d[w] + p->cost) {
                d[j] = d[w] + p->cost;
                path[j] = w;
            }

            p = p->next;
        }
        
    }
    
}

//求st -> en 的路径
void path(int st, int en, int p[NumVertices]) {
    if (en == st) {
        return;
    }
    path(st, p[en], p);

    cout<<en<<'-';
}
int main() {
    int i, count;
    AdjGraph g;
    createAdjGraph(g);
    // print(g);

    int d[NumVertices], p[NumVertices];
    dijkstra(g, 1, d, p);
    for (i = 2; i <= g.n; i++) {
        cout<<"1->"<<i<<':'<<d[i];
    }
    path(1, 5, p);
}


