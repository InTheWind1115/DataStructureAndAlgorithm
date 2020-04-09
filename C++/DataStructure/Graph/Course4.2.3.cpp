#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define N 1000

vector<int> g[N]; //无权图
vector<pair<int, int>> g1[N];   //带权图
int visited[N];
int dfn[N];
int count;

void addEdge(int i, int j) {
    g[i].push_back(j);
}

void dfs(int x) {
    int i, j;
    visited[x] = 1;
    dfn[x] = count;
    count++;
    for (i = 0; i < g[x].size(); i++) {
        j = g[x][i];
        if(visited[j] == 0)
            dfs(j);
    }
}

int visited1[N];
int bfn[N];
int count1;
void bfs(int v) {
    int i, j;
    queue<int> qu;
    visited1[v] = 1;
    bfn[v] = count1++;
    qu.push(v);
    while (!qu.empty()) {
        v = qu.front();
        qu.pop();
        for (i = 0; i < g[v].size; i++) {
            j = g[v][i];    //j为与v相邻的顶点
            if (visited1[j] == 0) {
                visited1[j] = 1;
                bfn[j] = count++;
                qu.push(j);
            }
        }
    }
}

int main() {
    int i, n, e, x, y;
    cin>>n>>e;
    for (i = 0; i < e; i++) {
        cin>>x>>y;  //0~n-1之间
        addEdge(x, y);
        addEdge(y, x);
    }
}