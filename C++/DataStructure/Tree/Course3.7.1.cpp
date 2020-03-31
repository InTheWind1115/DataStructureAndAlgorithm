#include <iostream>
#include <string>
using namespace std;
#define INF 0x3f3f3f
#define N 8
//typedef int MFSET[N];
typedef int elementtype;

typedef struct node{
    int parent;
    int count;//集合中的数量
    //int level; or int rank; //集合中的高度 
    //elementtype data;
}MFSET[N];

//找到a属于哪个集合，其实就是找到根节点
int find(int a,MFSET mf) {
    while (mf[a].parent != 0) {
        a = mf[a].parent;
    }
    return a;
}

//这里面通过节点merge，即节点少的并到节点多的上面。
void merge(int a, int b, MFSET mf) {
    int x = find(a, mf), y = find(b, mf);
    if(x == y)
        return;
    if (mf[x].count < mf[y].count) {
        mf[x].parent = y;
        mf[y].count += mf[x].count;
    } else {
        mf[y].parent = x;
        mf[x].count += mf[y].count;
    }
        
    //mf[y] = x;
}

void initial(int a, MFSET mf) {
    mf[a].parent = 0;
    mf[a].count = 1;
    //mf[a] = a;
}

void error(char str[]) {
    cout<<str<<endl;
}

void equal(MFSET mf) {
    int i;
    int x, y;
    for (i = 1; i < N; i++) {
        initial(i, mf);
    }
    while (cin>>x>>y, x*y) {
        merge(x, y, mf);
    }
}
 
int main() {

    int i;
    int ret = 0;
    MFSET mf;
    equal(mf);
    // 统计有多少个等价类
    for (i = 1; i < N; i++) {
        if (mf[i].parent == 0)
            ret++;
    }
    system("pause");
    return 0;
}