//https://acm.uestc.edu.cn/problem/shu-chu-qian-mda-de-shu-ju/description

#include <iostream>
#include <algorithm>

using namespace std;
#define maxn 1000100
int A[maxn];
int n,m;

//将数组l到r位置前k大的数移到l到r位置的右边
void move_right(int *A, int l, int r, int k){
    if(l>r) return;
    int i=l,j=r;
    int key=A[l];
    while(i!=j){
        if(i<j&&A[j]>=key) --j;
        swap(A[i],A[j]);
        if(i<j&&A[i]<=key) ++i;
        swap(A[i],A[j]);
    }
    int len = r-i+1;
    if(len==k) return;
    else if(len>k) move_right(A, i+1, r, k);
    else move_right(A,l,i-1,k-len);
}

int main()
{
    while(cin>>n>>m){
        for(int i=0; i<n;i++) cin >> A[i];
        //memset(A, 0, sizeof(A));
        move_right(A,0,n-1,m);
        sort(A+n-m,A+n); //将右边的m个数升序排序
        for(int i=n-1;i>=n-m;i--) cout << A[i] << " ";
    }
    return 0;
}
