//http://noi.openjudge.cn/ch0205/1490/
//要求：输出字典序最小者
//核心：既然能够遍历，那么起点任选，据字典序要求应选（1，1）点
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>

using namespace std;
const int maxn = 10;
//按字典序排列的搜索路径
int dr[] = {-1,1,-2,2,-2,2,-1,1};  
int dc[] = {-2,-2,-1,-1,1,1,2,2};
int m, n;
int vis[maxn][maxn];
struct node{
    char ch; int k;
    node(char ch='A', int k=0):ch(ch),k(k){}
};
vector<node> path;

void dfs(int x, int y){
    if(x<1 || y<1 || x>m || y>n) return;// 越界
    if(vis[x][y]) return; //已走过
    char c = y-1+'A';
    path.push_back(node(c,x));
    vis[x][y]=1;
    for(int i=0; i<8; i++)
        dfs(x+dr[i],y+dc[i]);
}
int main()
{
    int T; cin >> T;
    while(T--){
        cin >>m >>n;
        memset(vis,0,sizeof(vis));
        path.clear();
        dfs(1,1);
        printf("Scenario #%d\n",3-T);
        if(path.size()==m*n){  //判断是否走遍所有点
            for(int i=0; i<path.size();i++){
                printf("%c%d",path[i].ch,path[i].k);
            }
            cout << "\n";
        }
        else cout << "impossible\n";
    }
    return 0;
}
