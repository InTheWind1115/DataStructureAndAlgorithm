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

void pop(stack s) {
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


 struct celltype {
     elementtype ele;
     celltype *next;
 };
 typedef celltype *stackP;
typedef celltype *position;

element topP(stackP s) {
    return s -> next -> ele;
}

void popP(stackP &s) {
    position top = s -> next;
    if (top == NULL) {
        error("栈为空！");
        return;
    }
    s -> next = top -> next;
    delete top;
}

void push(elementtype x, stackP &s) {
    position t = new celltype;
    if(t == NULL) {
        error("内存已满！");
        return;
    }
    t -> ele = x;
    t -> next = s -> next;
    s -> next = t;
}
int main() {
    string s = "hello";
    cout<<s<<endl;
    cout<<"Hello"<<endl;
    system("pause");
    return 0;
}