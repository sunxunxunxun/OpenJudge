#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>

using namespace std;
const int maxn = 105;
long long dp[maxn][maxn];  //矩阵（1，1）到i行j列的和
int col_sum[maxn];
int M[maxn][maxn];
int m, n;

//复杂度为O(m^2 *n) ,根据行列数考虑是否交换
int main()
{
    cin >> m >> n;
    memset(dp, 0 ,sizeof(dp));
    memset(M, 0, sizeof(M));
    memset(col_sum, 0,sizeof(col_sum));
    for(int i=1; i<=m; i++)
        for(int j=1; j<=n; j++)
            cin >>M[i][j];
    dp[1][1] = M[1][1];
    for(int i=1; i<=m; i++)
        for(int j=1; j<=n; j++)
            dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + M[i][j];

    int ans = M[1][1], max_sum[n+1]={0}; //注意ans的初始值
    for(int i=1; i<=m; i++){
        for(int j=i; j<=m; j++){ //选择两行
            for(int k=1; k<=n; k++)
                col_sum[k] = dp[j][k] - dp[i-1][k] - dp[j][k-1] + dp[i-1][k-1]; //该两行间，第k列和
            //dp过程
            max_sum[1] = col_sum[1];
            for(int k=2; k<=n; k++){
                max_sum[k] = col_sum[k-1]>0? (max_sum[k-1]+col_sum[k]): col_sum[k];
                ans = ans>max_sum[k] ? ans:max_sum[k];
            }
        }
    }
    cout << ans;
    return 0;
}
