//http://noi.openjudge.cn/ch0206/2985/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int f[1210];
int num[1210];
int main()
{
    int n,t;
    scanf("%d%d",&n,&t);
    memset(f,0,sizeof(f));
    f[0] = 1;
    for(int i = 1 ; i <= n ; i ++)
        scanf("%d",&num[i]);
    for(int i = 1 ; i <= n ; i ++)
        for(int j = t ; j >= num[i] ; j --)
            f[j] += f[j-num[i]];
    printf("%d\n",f[t]);
    return 0;
}
