//https://leetcode.com/explore/featured/card/june-leetcoding-challenge/540/week-2-june-8th-june-14th/3354/
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0) return false; //不要忘了取值范围检查
        while(!(n%2)) n/=2;
        return n==1;
    }
};
