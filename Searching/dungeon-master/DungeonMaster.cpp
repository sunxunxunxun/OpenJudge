//http://noi.openjudge.cn/ch0205/1253/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <queue>

using namespace std;
const int maxn =100;
const int INF = 0xfffffff;
char G[maxn][maxn][maxn];
int vis[maxn][maxn][maxn];
int d[maxn][maxn][maxn];
int a, b, c;
int x, y, z;
int dx[]={1, -1, 0,0,0,0}, dy[]={0,0,1,-1,0,0},dz[]={0,0,0,0,1,-1};

struct node{
    int x, y, z;
    node(int x=0,int y=0,int z=0):x(x), y(y),z(z) {}
};
node s, e;
queue<node> q;

bool check(int x, int y, int z){
    if(x>=0 && y>=0 && z>=0 && x<a && y<b && z<c) return true;
    else return false;
}
void bfs(){
    node t;
    q.push(s);
    d[x][y][z]=0;
    while(!q.empty()){
        node nd = q.front(); q.pop();
        vis[nd.x][nd.y][nd.z]=1;
        for(int i=0; i<6; i++){
            t.x = nd.x+dx[i]; t.y = nd.y+dy[i]; t.z = nd.z+dz[i];
            if(check(t.x, t.y, t.z) && G[t.x][t.y][t.z]!='#' && !vis[t.x][t.y][t.z]){
                d[t.x][t.y][t.z] = min(d[t.x][t.y][t.z], d[nd.x][nd.y][nd.z]+1);
                q.push(t);
            }
        }
    }
}
int main()
{
    while(true){
        cin >> a >> b >> c;
        char G[a][b][c];
        if(!a && !b && !c) break;
        for(int i=0; i<a; i++)
            for(int j=0; j<b; j++)
                for(int k=0; k<c; k++) {
                    cin >> G[i][j][k];
                    d[i][j][k] = INF;
                    if(G[i][j][k] == 'S') {s.x=i;s.y=j;s.z=k;}
                    else if(G[i][j][k] == 'E') {e.x=i;e.y=y;e.z=z;}
                }
        memset(vis, 0, sizeof(vis));
        bfs();
        if(d[e.x][e.y][e.z]!=999999) cout << d[e.x][e.y][e.z];
        else cout << "Trapped";
    }
    return 0;
}
