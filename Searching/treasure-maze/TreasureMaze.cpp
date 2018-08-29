#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;
int key[26]={0}; //0表示可通过；-1表示有门但无钥匙；>0为所需钥匙数
char g[21][21];
bool OK = 0;
bool v[21][21];
int m, n, x, y;

void read_gragh(){
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin >> g[i][j];
            char ch = g[i][j];
            if(ch=='S') {x=i; y=j;}
            else if(ch>='a' && ch<='e'){  //是一把钥匙
                char CH = toupper(ch);
                if(key[CH-'A']==-1) key[CH-'A']=1;
                else key[CH-'A']++;
            }
            else if(ch>='A' && ch<='E' && !key[ch-'A']) key[ch-'A']=-1; //一把锁，但未出现钥匙，置为-1
        }
    }
}

void dfs(int x, int y){
    char ch = g[x][y];
    if(ch=='G') {OK=1; return;}
    if((ch>='A' && ch<='E'&& key[ch-'A']!=0) || ch =='X') return; //无法开门或者是墙

    if(ch>='a' && ch<='e') { //是一把钥匙
        char CH = toupper(ch);
        key[CH-'A']--;
        g[x][y] = '.';
    }
    v[x][y]=1;
    if(!OK){
        if(x-1>=0 && !v[x-1][y]) {
            dfs(x-1, y);
            if(OK) return;
        }
        if(y-1>=0 && !v[x][y-1]) {
            dfs(x, y-1);
            if(OK) return;
        }
        if(y+1<n && !v[x][y+1]) {
            dfs(x,y+1);
            if(OK) return;
        }
        if(x+1<m && !v[x+1][y]) {
            dfs(x+1,y);
            if(OK) return;
        }
    }
}
int main()
{
    while(true){
        cin >> m >> n;
        if(!m && !n) break;
        memset(key, 0, sizeof(key));
        memset(g, '\0', sizeof(g));
        memset(v, 0, sizeof(v));
        read_gragh();
        dfs(x,y);
        if(OK) cout << "YES" << "\n";
        else cout << "NO"<<"\n";
    }
    return 0;
}
