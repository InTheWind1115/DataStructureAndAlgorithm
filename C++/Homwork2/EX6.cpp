#include <iostream>
#include <string>
using namespace std;
#define INF 0x3f3f3f
#define maxsize 100
typedef int element;
typedef int elementtype;

typedef struct node{
    elementtype eles[maxsize];
    int top;//栈顶元素的下标
    node() : top(0) {};
}stack;

void error(char str[]) {
    cout<<str<<endl;
}

bool empty(stack s) {
    return s.top == 0;
}

elementtype top(stack s) {
    return s.eles[s.top];
}
void makeNull(stack &s) {
    s.top = 0;
}

void pop(stack &s) {
    if (empty(s)) {
        error("栈为空！");
        return;
    }
    s.top--;
}

void push(elementtype x, stack &s) {
     if (s.top == maxsize - 1) {
         error("栈已满,添加失败！");
         return;
     }
     s.top++;
     s.eles[s.top] = x;
}

void convert(int num, stack &s, int n) {
    while (num != 0) {
        push(num % n, s);
        num /= n;
    }

    while (!empty(s)) {
        cout<<top(s);
        pop(s);
    }
}

int main() {
    stack s;
    cout<<"189的二进制为:"<<'\t';
    convert(189, s, 2);
    system("pause");
    return 0;
}