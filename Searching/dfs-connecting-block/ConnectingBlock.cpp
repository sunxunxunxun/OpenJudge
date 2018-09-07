//http://noi.openjudge.cn/ch0205/1388/
//紫书P63
#include <iostream>
#include <cstring>
#include <string>

using namespace std;
const int maxn =105;
char g[maxn][maxn];
int b[maxn][maxn];
int cnt=0;
int m, n;

void dfs(int x, int y, int id){
    if(x<0 || y<0 ||x>=m || y>=n) return;//越界
    if(b[x][y] || g[x][y]=='.') return; //已标记或者不是w
    b[x][y] = id;  //连通分量编号
    for(int dr=-1; dr<=1; dr++)
        for(int dc=-1; dc<=1; dc++)
            if(dr!=0 || dc!=0) dfs(x+dr,y+dc,id);  //不能是自身
}
int main()
{
    cin >> m >> n;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin >> g[i][j];
        }
    }
    memset(b,0,sizeof(b));
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
            if(g[i][j]=='w' && b[i][j]==0) dfs(i, j, ++cnt);
    cout << cnt;
    return 0;
}
