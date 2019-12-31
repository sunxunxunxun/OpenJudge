//https://acm.uestc.edu.cn/status/
#include <iostream>
#include <cstring>

using namespace std;
const int maxn =105;
int price[maxn];
#define INF 200

int main()
{
    int n,m;cin>>n>>m;
    int p;
    for(int i=0;i<maxn;i++) price[i] = INF;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>p;
            if(p>0) price[j] = min(price[j],p);
        }
    }
    int sum=0;
    for(int i=0;i<n;i++)    sum+=price[i];
    cout << sum<<endl;
    return 0;
}
