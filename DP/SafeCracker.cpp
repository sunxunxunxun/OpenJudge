//http://noi.openjudge.cn/ch0206/4977/
#include <iostream>
#include <cstring>

using namespace std;
const int maxn = 105;
int a[maxn];
int toh[maxn], tol[maxn];  //暂存的最长上升/下降子序列

int low_bound(int x, int y, int v){  //求下界，用于上升子序列
    while(x<y){
        int m = (x+y)/2;
        if(toh[m]>v) y=m;
        else x=m+1;
    }
    return x;
}
int high_bound(int x, int y, int v){   //求上界，用于下降子序列
    while(x<y){
        int m = (x+y)/2;
        if(tol[m]<v) y = m;
        else x=m;
    }
    return x;
}
int main()
{
    int T; cin >> T;
    while(T--){
        int n; cin >> n;
        int ans1=1, ans2=1;
        memset(toh, 0, sizeof(toh));
        memset(tol, 0, sizeof(tol));
        for(int i=0; i<n; i++) cin >> a[i];
        toh[0] = tol[0] = a[0];
        for(int i=1; i<n; i++){
            //求最长上升，个数存于ans1
            if(toh[ans1-1]<a[i]) toh[ans1++] = a[i];
            else{
                int p = low_bound(0, ans1, a[i]);
                toh[p] = a[i];
            }
            //求最长下降，个数存于ans2
            if(tol[ans2-1]>a[i]) tol[ans2++] = a[i];
            else{
                int p = high_bound(0, ans2, a[i]);
                tol[p] = a[i];
            }
        }
        cout << max(ans1, ans2) << "\n";
    }
    return 0;
}
