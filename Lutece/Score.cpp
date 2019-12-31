//https://acm.uestc.edu.cn/problem/tiao-shui-da-fen-wen-ti/description
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int cs; cin>>cs;
    float minm, maxm;
    float sum,score;
    int n;
    for(int i=0;i<cs;i++){
        cin>>n;
        minm = 10; maxm=0; sum=0;
        for(int j=0;j<n;j++){
            cin >> score;
            sum+=score;
            maxm = max(score,maxm);
            minm = min(score,minm);
        }
        cout<<fixed<<setprecision(2)<<(sum-maxm-minm)/(n-2)<<endl;
    }
    return 0;
}
