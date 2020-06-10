//https://leetcode.com/explore/featured/card/june-leetcoding-challenge/540/week-2-june-8th-june-14th/3356/
class Solution {
public:
    int binarySearch(vector<int>& nums, int left, int right, int target) {
        if(left == right) return left;
        int m = (left + right) / 2;
        if(nums[m]>=target) return binarySearch(nums, left, m, target);
        else return binarySearch(nums, m+1, right, target);
    }
    
    int searchInsert(vector<int>& nums, int target) {
        int ind, n = nums.size();
        if(nums[n-1]<target) ind = n;
        else ind = binarySearch(nums, 0, n, target);
        return ind;
    }
};
