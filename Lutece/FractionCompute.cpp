#include <iostream>
#include <stdio.h>

using namespace std;

int gcd(int a, int b){
    if(a<b) {int tep=a;a=b;b=tep;}
    if(a%b==0)
        return b;
    int g=1;
    while(b){
        g=b;
        b=a%b;
        a=g;
    }
    return g;
}
int main()
{
    int cs;cin>>cs;
    int a,b,c,d;
    char opt;
    for(int i=0;i<cs;i++){
        cin>>a>>b>>c>>d>>opt;
        printf("%d/%d%c%d/%d=",a,b,opt,c,d);
        int numer=0,denom=0;
        switch (opt){
            case '+':
                numer = a*d+c*b;
                denom=b*d;
                break;
            case '-':
                numer = a*d-c*b;
                denom=b*d;
                break;
            case '*':
                numer = a*c;
                denom=b*d;
                break;
            case '/':
                numer = a*d;
                denom=b*c;
                break;
        }
        if(numer<0) {cout<<"-";numer *= -1;}
        if(numer%denom==0) cout<<numer/denom<<endl;
        else{
            int g = gcd(numer,denom);
            cout<<numer/g<<"/"<<denom/g<<endl;
        }
    }
    return 0;
}
