//https://acm.uestc.edu.cn/status/
#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    long long n;
    while(scanf("%lld",&n)!=EOF){
        if(n%4==2) cout << "yes"<<endl;
        else cout<<"no"<<endl;
    }
    return 0;
}
