//题目链接
//http://noi.openjudge.cn/ch0113/05/
#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;
int a[1000];

bool is_prime(int x){
    int k=sqrt(x)+1;
    for(int i=3; i<=k; i++){
        if(x%i==0) return false;
    }
    return true;
}
bool is_plalin(int x){
    if(x/100){
        if((x/100)!=(x%10)) return false;
    }
    else{
        if((x/10)!=(x%10)) return false;
    }
    return true;
}
int main()
{
    int n; cin >> n;
    memset(a, 0,sizeof(a));
    for(int i=33; i<1000; i++){
        if(is_prime(i) && is_plalin(i)) a[i] = a[i-1]+1;
    }
    cout << a[n];
    return 0;
}
