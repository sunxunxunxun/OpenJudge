#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int maxn=105;
int v[maxn];

int main()
{
    int n, cnt;
    while(cin>>n && n){
        cnt=0;
        memset(v,0,sizeof(v));
        for(int i=0;i<n;i++) cin >> v[i];
        int m=(n+2)/2;//注意题目是超过一半的州
        sort(v,v+n);
        for(int i=0;i<m;i++) cnt+=(v[i]+2)/2;
        cout << cnt<<endl;
    }
    return 0;
}
