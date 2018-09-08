#include <iostream>
#include <cstring>

using namespace std;
const int maxn = 1010;
int a[maxn];

int main()
{
    int n; cin >> n;
    for(int i=0; i<n; i++) cin >> a[i];
    int dp[n]={0}; dp[0] = a[0];
    int max_sum =0;
    for(int i=1; i<n; i++){
        for(int j=0; j<i; j++){
            if(a[i]>a[j]) dp[i] = max(dp[i], dp[j]+a[i]);
            max_sum = max(max_sum, dp[i]);
        }
    }
    cout << max_sum;
    return 0;
}
