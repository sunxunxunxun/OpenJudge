//http://noi.openjudge.cn/ch0113/07/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;
char m1[20][10]={"pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax", "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu", "uayet"};
char m2[21][10]={" ","imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk", "ok", "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau"};

int main()
{
    int T; cin >> T;
    while(T--){
        int d, m=0 ,y;
        long long n=0;
        char str[8];
        scanf("%d. %s %d",&d, str, &y);
        for(int i=0; i<20; i++)
            if(strcmp(str,m1[i])==0) {m=i;break;}
        n = (d+1+m*20+y*365)%260;
        y = (d+1+m*20+y*365)/260;
        d = n%13; if(!d) d=13;
        m = n%20; if(!m) m=20;
        printf("%d %s %d\n",d, m2[m], y);
    }
    return 0;
}
