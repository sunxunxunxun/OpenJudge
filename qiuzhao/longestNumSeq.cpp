// 题目描述
// 输入一个字符串，返回其最长的数字子串，以及其长度。若有多个最长的数字子串，则将它们全部输出（按原字符串的相对位置）
// 本题含有多组样例输入。

// 输入
// abcd12345ed125ss123058789
// a8a72a6a5yy98y65ee1r2
// 输出
// 123058789,9
// 729865,2

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string s;
    while (cin >> s) {
        vector<string> res;
        int len = 0, tempLen = 0;
        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];
            if (ch >= '0' && ch <= '9') {
                tempLen++;
            }
            else {
                if (!len && tempLen == len) {
                    res.push_back(s.substr(i-tempLen, tempLen));
                }
                else if (tempLen > len) {
                    res.clear();
                    res.push_back(s.substr(i-tempLen, tempLen));
                }
            }
        }
        for (string s: res) {
            cout << s << ",";
        }
        cout << len << endl;
    }
    return 0;
}