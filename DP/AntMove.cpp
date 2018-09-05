//http://noi.openjudge.cn/ch0206/2718/
#include <iostream>
#include <cstring>

using namespace std;
const int maxn = 20;
int dp[maxn][maxn];

int main()
{
    int m, n; cin >> m >> n;
    memset(dp,0,sizeof(dp));
    dp[1][1]=1;
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++) {
            if(i==1&&j==1) continue;
            else dp[i][j] = dp[i-1][j]+dp[i][j-1];
        }
    }
    cout << dp[m][n];
    return 0;
}
