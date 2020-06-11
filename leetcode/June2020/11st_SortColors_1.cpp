//https://leetcode.com/explore/featured/card/june-leetcoding-challenge/540/week-2-june-8th-june-14th/3357/
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = n-1;
        for(int i = 0; i < n; i++) {
            if(nums[i] == 0) nums[low++] = 0;
            if(nums[i] == 2) high--;
        }
        for(int i = low; i <= high; i++) nums[i] = 1;
        for(int i = high+1; i < n; i++) nums[i] = 2;
    }
};
