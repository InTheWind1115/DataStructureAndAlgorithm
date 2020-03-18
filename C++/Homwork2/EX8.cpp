#include <iostream>
#include <string>
#include <cstring>
using namespace std;
#define INF 0x3f3f3f
#define maxsize 100
typedef int element;
typedef char elementtype;
enum Boolean {
    FALSE, TRUE
};

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

Boolean check(char *str, stack &s) {
    int i;
    for (i = 0; i < strlen(str); i++) {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
            push(str[i], s);
        } else if(str[i] == ')' || str[i] == ']' || str[i] == '}') {
            char ch = top(s);
            pop(s);
            if (!((ch == '(' && str[i] == ')') || (ch == '[' && str[i] == ']') || (ch == '{' && str[i] == '}')))
                return FALSE;
        }
    }
    return TRUE;
}

int main() {
    stack s1;
    stack s2;
    cout<<check("([dfd]fdf){}", s1)<<endl;
    cout<<check("(asdfa]sadf{f}sdf)", s2)<<endl;
    system("pause");
    return 0;
}