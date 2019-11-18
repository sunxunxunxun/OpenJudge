//https://www.jianshu.com/p/3a1d5cecfbe5

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
const int maxn = 205;
struct JOB{
    int s, e, v, index;
    JOB(int s=0, int e=0, int v=0, int index=0):s(s), e(e), v(v), index(index){}
}job[maxn];
int frt[maxn], dp[maxn];

bool cmpe(JOB a, JOB b){ //定义按结束时间升序排序的排序规则
    return a.e<b.e;
}
/*bool cmps(JOB a, JOB b){ //定义按开始时间升序排序的排序规则
    return a.s<b.s;
}*/

int main()
{
    int n; cin >> n;
    //JOB a=(1,2,3);
    memset(frt, 0, sizeof(frt));
    memset(dp, 0, sizeof(dp));
    for(int i=1;i<=n;i++) cin >> job[i].s >> job[i].e >> job[i].v;
    //按结束时间升序排序，并为元素编号
    sort(job, job+n, cmpe);
    for(int i=1; i<=n; i++) job[i].index=i;
    //求frt[]数组
    //sort(job, job+n, cmps); //按开始时间升序排列
    for(int i=n;i>0;i--){
        for(int j=n-1;j>0;j--){
            if(job[j].e<=job[i].s) {frt[i]=job[j].index; break;}
        }
    }
    //sort(job, job+n, cmpe);
    for(int i=1;i<=n;i++){
        dp[i] = max(dp[i-1], dp[frt[i]]+job[i].v);
    }
    cout << dp[n];
    return 0;
}

