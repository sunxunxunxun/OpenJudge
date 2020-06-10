//https://leetcode.com/explore/featured/card/june-leetcoding-challenge/540/week-2-june-8th-june-14th/3355/
class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.empty()) return 1;
        else if(t.empty()) return 0;
        int dp[s.length()][t.length()];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = s[0]==t[0] ? 1:0;
        for(int i=1;i<t.length();i++){
            dp[0][i] = s[0]==t[i] ? 1:dp[0][i-1];
        }
        for(int i=1;i<s.length();i++) 
            for(int j=i;j<t.length();j++){
                if(s[i]==t[j]) dp[i][j] = dp[i-1][j-1];
                else dp[i][j] = dp[i][j-1];
            }
        return dp[s.length()-1][t.length()-1];
    }
};
