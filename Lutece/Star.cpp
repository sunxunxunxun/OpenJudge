//https://acm.uestc.edu.cn/problem/wu-xing/description
#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int cs; cin>>cs;
    int n;
    long long cnt;
    for(int T=1;T<=cs;T++){
        cin>>n;
        cnt=5;
        while(--n) cnt*=3;
        printf("Case #%d: %lld\n",T,cnt);
    }
    return 0;
}
