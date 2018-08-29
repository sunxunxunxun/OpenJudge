#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

int main()
{
    int cnt[26] = {0}, maxn=0;
    //char [81][26] = {' '};
    char str[1024];
    int T=4;
    while(T--){
        gets(str);
        for(int i=0; i<strlen(str); i++){
            char ch=str[i];
            int index = ch-'A';
            if(isalpha(ch)) {
                cnt[index]++;
                maxn = maxn>cnt[index] ? maxn:cnt[index];
            }
        }
    }
    //int n = maxn;
    int start =1;
    while(maxn){
        for(int i=0;i<26; i++){
            if(!start) cout << " ";
            else if(start) start=0;
            if(cnt[i]==maxn) {cout << "*"; cnt[i]--;}
            else cout << " ";
        }
        cout << '\n';
        start=1;
        maxn--;
    }
    cout << 'A';
    for(int i=1; i<26; i++) {
        char ch= i+'A';
        cout << " "<< ch;
    }
    return 0;
}
