#include<iostream>
#include<string>
#include<cmath>
using namespace std;
int main() {

    string str;
    int i, m;
    int result;
    while (1) {
        result = 0;
        m = 0;
        cin>>str;
        for (i = str.length() - 1; i >= 0; i--) {
            if (str[i] >= 'A' && str[i] <= 'Z') {
                result += ((int)str[i] - 'A' + 10) * pow(16, m++);
            } else {
                result += ((int)str[i] - '0') * pow(16, m++);
            }
        }
        cout<<result<<endl;
    }
    
    system("pause");
    return 0;
}