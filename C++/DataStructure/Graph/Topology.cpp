#include<iostream>
#include<queue>
using namespace std;
#define NumVertices 100
typedef string EdgeData;
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
        //setSucc(g, y, x);
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


int topsort[NumVertices];
void TopSort(AdjGraph g) {
    int indegree[NumVertices] = {0};
    int i, k, j;
    EdgeNode *h;
    for (i = 1; i <= g.n; i++) {
        h = g.vexList[i].firstEdge;
        if (h != NULL) 
            h = h ->  next;
        while (h != NULL) {
            indegree[h -> adjvex]++;
            h = h -> next;
        }
    }
    queue<int> qu;
    for (i = 1; i <= g.n; i++) {
        if (indegree[i] == 0)
            qu.push(i);
    }
    while (!qu.empty()) {
        k = qu.front();
        topsort[count++] = k; //count begin at 0
        qu.pop();
        h = g.vexList[k].firstEdge;
        if (h != NULL) 
            h = h ->  next;
        while (h != NULL) {
            j = h -> adjvex;
            indegree[j]--;
            if (indegree[j] == 0)
                qu.push(j);
            h = h -> next;
        }
    }
    if (count < g.n) {
        cout<<"此图包含环路！"<<endl;
    } else {
        for (i = 0; i < g.n; i++) {
            cout<<topsort[i]<<' ';
        }
        cout<<endl;
    }
}

int main() {
    int i, count;
    AdjGraph g;
    createAdjGraph(g);
    //`memset(visited, 0, sizeof(visited));
    count = 1;
    for(i = 0; i < g.n; i++) {
        if (visited[i] == 0) {
            dfs(g, i);
        }
    }
}