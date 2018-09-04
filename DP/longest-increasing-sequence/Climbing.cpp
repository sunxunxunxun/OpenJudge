//题目链接
//http://noi.openjudge.cn/ch0206/1996/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;
const int maxn = 1010;
int h[maxn];
int t[maxn];

//二分查找求下界
int bound(int x, int y, int v){
    while(x<y){
        int m = (x+y)/2;
        if(t[m]>=v) y=m;
        else x=m+1;  //x=m是否可行
    }
    return x;
}
int main()
{
    int n; cin >> n;
    for(int i=0; i<n; i++) cin >> h[i];
    int ans=1;
    memset(t,0,sizeof(t));
    t[0] = h[0];
    for(int i=1; i<n; i++){
        if(h[i]>t[ans-1]) {
            t[ans] = h[i];
            ans++;
        }
        else if(h[i]==t[ans-1]) continue;
        else {
            int p = bound(0,ans,h[i]);
            t[p] = h[i];
        }
    }
    cout << ans;
    return 0;
}
