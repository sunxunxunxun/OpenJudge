//https://acm.uestc.edu.cn/problem/yue-hui-ii/description
#include <stdio.h>

using namespace std;
int a,b;

int main()
{
    while(scanf("%d %d",&a,&b)!=EOF&&(a||b)){
        int cnt =0;
        cnt =b/3-(a-1)/3;
        printf("%d\n",cnt);
    }
    return 0;
}
