//http://noi.openjudge.cn/ch0206/3531/

#include <iostream>
#include <cstring>

using namespace std;
const int maxn = 10010, maxk = 105;
int num[maxn];
bool dp[maxn][maxk];

int main()
{
    int n, k;
    cin >> n >> k;
    memset(num, 0,sizeof(num));
    memset(dp, 0, sizeof(dp));
    for(int i=1; i<=n; i++){
        cin >> num[i]; num[i]%=k;
    }
    dp[1][num[1]] = true;
    for(int i=2; i<=n; i++){
        for(int j=0;j<k; j++){  //保证余数均为小于k的正数
            if(dp[i-1][j]){                               //第一个k避免变成负数
                dp[i][(j+num[i])%k] = true; dp[i][(j-num[i]+k)%k] = true;  //重点
            }
        }
    }
    if(dp[n][0]) cout << "YES";
    else cout << "NO";
    return 0;
}
