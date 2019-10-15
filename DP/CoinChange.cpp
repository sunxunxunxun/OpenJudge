//https://www.jianshu.com/p/2cb0da3d3e54

#include <iostream>
#include <cstring>

using namespace std;
const int maxn = 205;
const int INF = 0xfffffff;

int main()
{
    int m; cin>>m;
    int crr[m], dp[maxn], money;
    memset(dp, INF, sizeof(dp));
    memset(crr, 0, sizeof(crr));
    for(int i=0;i<m;i++){
        cin >> crr[i];
    }
    cin >> money;
    dp[0]=0;
    for(int i=1;i<=money;i++) dp[i]=INF;
    for(int i=1;i<=money;i++){
        for(int j=0; j<m;j++){
            if(i>=crr[j]) dp[i] = min(dp[i], dp[i-crr[j]]+1);
        }
    }
    cout << dp[money];
    return 0;
}
