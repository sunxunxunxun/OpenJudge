//https://acm.uestc.edu.cn/problem/clock/description
#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

int main()
{
    int cs;cin>>cs;
    int h,m,subs;
    int H,M;
    string str;
    for(int T=0;T<cs;T++){
        scanf("%d:%d",&h,&m);
        h = h%12;
        H = h*60+m;
        M = m*12;
        subs=max(H,M)-min(H,M);
        if(subs>=360) subs=720-subs;
        if(subs%2==0) cout << subs/2<<endl;
        else cout << subs<<"/"<<2<<endl;

    }
    return 0;
}
