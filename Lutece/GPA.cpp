//https://acm.uestc.edu.cn/problem/gpaji-suan/description
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int n;cin>>n;
    float credit_total=0,sum=0;
    for(int i=0;i<n;i++){
        float credit, grade; cin>>credit>>grade;
        credit_total+=credit;
        if(grade>=90) sum+=4*credit;
        else if(grade>=80 && grade<90) sum+=3*credit;
        else if(grade>=70 && grade<80)  sum+=2*credit;
        else if(grade>=60 && grade<70)  sum+=credit;
    }
    cout << setprecision(2)<< std::fixed <<sum/credit_total<<endl;
    return 0;
}
