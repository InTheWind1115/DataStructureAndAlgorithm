#include<iostream>
using namespace std;

int main() {
    int prime[200] = {0}; //用来存放1000-2000中的素数 初始化为0
    int count = 0; //用来存放素数的个数
    int i, j;
    bool isPrime; //用来判断是否为素数 true为是 flase为否
    for (i = 1000; i <= 2000; i++) {
        isPrime = true; //默认初始化为是
        for (j = 2; j * j <= i; j++) { //此循环用来判读是否为素数
            if (i % j == 0) {
                isPrime = false; //有除了1 和 它本身之外的约数，所以不是素数
            }
        }
        if (isPrime) {
            prime[count++] = i;
        }
    }

    //将素数输出 检验程序的正确性
    for (i = 0; i < count; i++)
        cout<<prime[i]<<" ";
    cout<<endl;

    return 0;
}