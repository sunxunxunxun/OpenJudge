#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>

using namespace std;
const int maxn = 105;
int f[maxn], w[maxn], p[maxn];

int main()
{
    int n; cin >> n;
    int V; cin >> V;
    memset(f, 0, sizeof(f));
    memset(w, 0, sizeof(w));
    memset(p, 0, sizeof(p));
    for(int i=1; i<=n; i++)
        cin >> w[i] >> p[i];
    for(int i=1; i<=n; i++){
        int v = V;
        for(; v>=w[i]; v--){ //注意是从大到小的顺序
            f[v] = max(f[v], f[v-w[i]]+p[i]);  //递推公式
        }
    }
    cout << f[V];
    return 0;
}
