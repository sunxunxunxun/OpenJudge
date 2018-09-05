//题目链接
//http://noi.openjudge.cn/ch0113/06/
//按位数相乘和循环判断d的思想
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;
const int maxn =65;
int n;

void calculator(int* bef, int* aft, int a){
    memset(aft,0,sizeof(int)*maxn);
    int t[n];//存储在每一位上的进位
    memset(t,0,sizeof(t));
    for(int i=0; i<n; i++) aft[i] = bef[i]*a;
    for(int i=n-1; i>=0; i--){   //m没有考虑结果数组位数比原数组多的情况（或者已用0初始化了）
        t[i] = (aft[i]+t[i+1])/10;
        aft[i] = (aft[i] +t[i+1])%10;  //注意括号位置
    }
    return;
}

bool compare(int* bef, int* aft){
    bool OK;
    for(int i=0; i<n; i++) if(bef[i]==aft[0]){
        OK=1;
        for(int j=1;j<n; j++){
            int index = (i+j)%n;
            if(bef[index]!=aft[j]) {OK=0; break;}
        }
        if(OK) return true;
    }
    return false;
}

int main()
{
    char num[maxn];
    scanf("%s",num);
    n = strlen(num);
    int bef[maxn], aft[maxn];
    memset(bef,0,sizeof(bef));
    for(int i=0; i<n; i++) bef[i] = num[i]-'0';
    for(int i=2; i<=n; i++){
        calculator(bef,aft,i);
        if(!compare(bef,aft)) {
            cout << 0;
            return 0;
        }
    }
    cout <<1;
    return 0;
}
