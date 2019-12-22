//https://acm.uestc.edu.cn/problem/ants-run/description
#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;
#define pi 3.141592653589793
#define INF 0xfffffff

int main()
{
    int cs;cin>>cs;
    int n, r;
    float spd[25], sub_spd[25];
    for(int T=0;T<cs;T++){
        cin >> n>> r;
        float l = 2*pi*r;
        cin >> spd[0];
        int spd_sum=0;
        for(int i=1;i<n;i++) {
            cin>>spd[i];
            spd[i]<spd[i-1]? sub_spd[i-1]=spd[i-1]-spd[i]:sub_spd[i-1]=INF;
        }
        spd[n-1]>spd[0]?sub_spd[n-1]=spd[n-1]-spd[0]:sub_spd[n-1]=INF;
        for(int i=0;i<n;i++)
            if(sub_spd[i]!=INF) spd_sum+=sub_spd[i];
        if(spd_sum==0) cout<<"Inf";
        else cout << setprecision(3)<<std::fixed<<l/spd_sum;
        if(T<cs-1) cout << "\n";
    }
    return 0;
}
