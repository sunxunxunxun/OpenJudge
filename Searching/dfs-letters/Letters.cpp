//http://noi.openjudge.cn/ch0205/156/

#include <iostream>
#include <cstring>

using namespace std;
const int maxn = 25;
bool vis[26]={0};
int m, n, step;
int g[maxn][maxn], d[maxn][maxn];

void dfs(int x, int y, int cnt){
    if(x<1 || y<1 || x>m || y>n) return;
    if(vis[g[x][y]]) return;
    d[x][y] = cnt;
    vis[g[x][y]] = 1;
    step = max(step, cnt);
    for(int dr=-1;dr<=1;dr++)
        for(int dc=-1;dc<=1;dc++) if((dr||dc) && dr*dc==0){
            dfs(x+dr, y+dc, d[x][y]+1);
        }
    vis[g[x][y]]=0; //重点！刚开始调出不出来就是因为回退操作放错了地方
}
int main()
{
    cin >> m >> n;
    for(int i=1; i<=m; i++)
        for(int j =1; j<=n; j++){
            char ch; cin >> ch;
            g[i][j] = ch-'A';
        }
    step=0;
    d[1][1]=1;
    dfs(1,1,d[1][1]);
    cout << step;
    return 0;
}
