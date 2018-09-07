//http://noi.openjudge.cn/ch0205/131/
//针对数据规模小的涂色问题可采用枚举方法

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;
int n;
int g[26][26];
int c[26];
int cnt;

//判断此次涂色尝试是否合法
bool is_valid(int x, int color){  //为x点图上color颜色
    for(int i=0; i<26;i++) if(g[x][i] && c[i]==color){ //相邻点相同颜色
        return false;
    }
    c[x] = color;
    cnt = max(cnt, color);
    return true;
}
//每个点一次从2号颜色开始枚举
void tintage(){
    for(int i=0; i<n; i++){
        for(int j=1; j<=26;j++){
            if(is_valid(i, j)) {c[i] = j; break;}
        }
    }
}
int main()
{
    while(true){
        cin >> n;
        if(!n) break;
        char s[30];
        memset(g,0,sizeof(g));
        for(int i=0; i<n; i++){
            scanf("%s",s);
            int k = s[0]-'A';
            for(int j=2; j<strlen(s); j++) g[k][s[j]-'A']=1 ; //构造无向图
        }
        memset(c,0,sizeof(c));
        cnt=0;
        tintage();
        cout << cnt << "\n";
    }
    return 0;
}
