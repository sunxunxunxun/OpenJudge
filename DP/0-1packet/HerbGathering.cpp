/*原题链接
  http://noi.openjudge.cn/ch0206/1775/
*/
#include <iostream>
#include <cstring>

using namespace std;
const int maxt = 1010;
const int maxm = 105;

int main()
{
    int T, m;
    int t[maxm], v[maxm], dp[maxt];
    memset(t, 0, sizeof(t));
    memset(v, 0, sizeof(v));
    memset(dp, 0, sizeof(dp));
    cin >> T >> m;
    for(int i=0; i<m; i++) cin >> t[i] >> v[i];
    for(int i=1; i<m; i++){
        for(int tt=T; tt>=t[i]; tt--){
            dp[tt] = max(dp[tt], dp[tt-t[i]]+v[i]);
        }
    }
    cout << dp[T];
    return 0;
}
