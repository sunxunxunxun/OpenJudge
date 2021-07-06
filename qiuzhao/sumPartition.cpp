// 题目描述
// 输入十个数字，五个为一组，分两组，每组里的数字相加，问两组的差最少为多少。
// 例如：
// 输入10个数字，任意5个求和为a，剩下5个求和为b，问a和b的差的最小是多少。
// 解释
// 例如1 2 3 4 5 6 7 8 9 10这十个数，1 2 5 9 10为一组和为27，

// 3 4 6 7 8为另一组和为28，它们的差为1，是最小值。
#include <iostream>
#include <vector>

using namespace std;

int getMinSum(vector<int>& nums) {
    int n = nums.size();
    int sum = 0;

}

int main() {
    vector<int> nums = {};
    cout << getMinSum(nums) << endl;
    return 0;
}