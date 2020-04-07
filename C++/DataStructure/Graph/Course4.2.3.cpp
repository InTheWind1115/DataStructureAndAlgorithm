#include<iostream>
#include<vector>
using namespace std;
#define N 1000

vector<int> g[N];
vector<pair<int, int>> g1[N];
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

int main() {
    int i, n, e, x, y;
    cin>>n>>e;
    for (i = 0; i < e; i++) {
        cin>>x>>y;  //0~n-1之间
        addEdge(x, y);
        addEdge(y, x);
    }
}