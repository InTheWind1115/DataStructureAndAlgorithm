#include <iostream>
#include <string>
using namespace std;
#define INF 0x3f3f3f
#define maxsize 5
typedef int element;
typedef int elementtype;

void error(char str[]) {
    cout<<str<<endl;
}

struct queue {
    elementtype eles[maxsize];
    int front;
    int count;
    queue() : front(0), count(0) {};
};

bool isEmpty(queue q) {
    return q.count == 0;
}

bool isFull(queue q) {
    return q.count == maxsize;
}

void enqueue(elementtype x, queue &q) {
    if (isFull(q)) {
        error("队列已满！");
        return;
    }
    q.count++;
    q.eles[(q.front + q.count) % maxsize] = x;
}

void dequeue(queue &q) {
    if (isEmpty(q)) {
        error("队列为空");
    }
    q.front++;
    q.count--;

}

 
int main() {
    queue q;
    enqueue(1, q);
    enqueue(2, q);
    enqueue(3, q);
    enqueue(4, q);
    dequeue(q);
    dequeue(q);
    enqueue(5, q);
    enqueue(6, q);
    system("pause");
    return 0;
}