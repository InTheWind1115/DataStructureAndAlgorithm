#include <iostream>
#include <string>
using namespace std;
#define INF 0x3f3f3f
#define maxsize 100
typedef int element;
typedef int elementtype;

void error(char str[]) {
    cout<<str<<endl;
}
 
struct celltype {
    elementtype ele;
    celltype *next;
};

struct queue {
    celltype *fro;
    celltype *rea;
    queue() {
        fro = rea = new celltype;
    }
};

bool empty(queue q) {
    return q.fro == q.rea;
}

elementtype front(queue q) {
    if (empty(q)) {
        error("队列为空！");
        return INF;
    }
    return q.fro -> next -> ele;
}

void dequeue(queue &q) {
    if (empty(q)) {
        error("队列为空！");
    }
    celltype *p = q.fro -> next;
    q.fro -> next = p -> next;
    delete p;
}

void enqueue(elementtype x, queue &q) {
    celltype *p = new celltype;
    p -> ele = x;
    p -> next = NULL;
    q.rea -> next = p;
    q.rea = p;

}

int main() {
    queue q;
    
    system("pause");
    return 0;
}