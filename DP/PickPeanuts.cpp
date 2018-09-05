//http://noi.openjudge.cn/ch0206/2728/
#include <iostream>
#include <cstring>

using namespace std;
const int maxn = 105;
int dp[maxn][maxn];
int num[maxn][maxn];

int main()
{
    int T; cin >> T;
    while(T--){
        int m, n; cin >> m >> n;
        memset(dp, 0, sizeof(dp));
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++) cin >> num[i][j];
        }
        dp[1][1] = num[1][1];
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(i==1 && j==1) continue;
                else dp[i][j] = max(dp[i-1][j],dp[i][j-1]) + num[i][j];
            }
        }
        cout << dp[m][n];
    }
    return 0;
}
