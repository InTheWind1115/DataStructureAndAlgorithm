#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
int main() {
    srand((int)time(0)); //用来产生随机种子
    int numsArray[172] = {0}; //用来存放10个产生随机数
    int i, j;
    for (i = 0; i < 172; i++) {
        numsArray[i] = rand() % 100; //用来产生0 - 99的随机数
    }

    //查看排序前的数组
    cout<<"Before sort:"<<endl;
    for (i = 0; i < 172; i++) {
        cout<<numsArray[i]<<" ";
    }
    cout<<endl;

    //排序算法 此处采用冒泡法降序排序
    for (i = 1; i < 172; i++) {
        for (j = 0; j < 172 - i; j++) {
            if (numsArray[j] > numsArray[j + 1]) {
                int temp = numsArray[j];
                numsArray[j] = numsArray[j + 1];
                numsArray[j + 1] = temp;
            }
        }
    }

    //查看排序后的数组
    cout<<"After sort:"<<endl;
    for (i = 0; i < 172; i++) {
        cout<<numsArray[i]<<" ";
    }
    cout<<endl;


    int a;
    cin>>a;
    return 0;
}