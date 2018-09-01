#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;
const int maxn =205;
char s1[maxn], s2[maxn];

int main()
{
    while(scanf("%s%s", s1, s2) !=EOF){
        int l1 = strlen(s1), l2 = strlen(s2);
        int dp[l1+1][l2+1];//
        memset(dp, 0, sizeof(dp));
        for(int i=1; i<=l1; i++)
            for(int j=1; j<=l2; j++){
                if(s1[i]==s2[j]) dp[i][j] = dp[i-1][j-1] +1;
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        cout << dp[l1][l2] << "\n";
        memset(s1, 0, sizeof(s1));
        memset(s1, 0, sizeof(s2));
    }
    return 0;
}
