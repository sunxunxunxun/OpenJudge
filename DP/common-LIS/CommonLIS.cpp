//http://noi.openjudge.cn/ch0206/2000/
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const int maxn =505;
int t[maxn];

int low_bound(int x, int y, int v){
    int m;
    while(x<y){
        m=(x+y)/2;
        if(t[m]>=v) y = m;
        else x=m+1;
    }

    return x;
}
int main()
{
    int m, n, ans=0;
    int A[maxn], B[maxn];
    memset(A,0,sizeof(A));
    memset(B,0,sizeof(B));
    memset(t,0,sizeof(t));
    cin >> m;
    for(int i=1; i<=m; i++) cin >> A[i];
    cin >> n;
    for(int i=1; i<=n; i++) cin >> B[i];
    int dp[m+1][n+1]; //
    memset(dp,0,sizeof(dp));
    t[0] = 9999999;
    for(int i=1; i<=m; i++)
        for(int j=1; j<=n; j++){
            if(A[i]!=B[j]) dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            else {
                int v=A[i];
                if(t[ans]<v) {ans++; t[ans]=v;dp[i][j] = dp[i-1][j-1]+1;}
                else if(t[ans]==v) continue;
                else{
                    int p = low_bound(0,ans+1,v);
                    t[p] = v;
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
    cout << ans+1 << "\n";
    for(int i=0; i<=ans; i++) printf("%d ",t[i]);
    return 0;
}
