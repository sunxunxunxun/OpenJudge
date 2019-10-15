//https://www.jianshu.com/p/89f8c67b2a04

#include <iostream>
#include <utility> //pair所在的库

using namespace std;
const int maxn = 105;
pair<int, int> job[maxn];

int main()
{
    int n; cin >> n;
    for(int i=0;i<n;i++){
        cin>>job[i].first>>job[i].second;
    }
    int t=0;//上一被调度工作的结束时间
    int cnt=0;
    for(int i=0;i<n;i++){
        if(job[i].first>=t){
            cnt++;
            t=job[i].second;
        }
    }
    cout << cnt;
    return 0;
}
