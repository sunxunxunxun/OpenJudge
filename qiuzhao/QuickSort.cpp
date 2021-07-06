#include <iostream>

using namespace std;

void swap(int &a, int &b){
    int tep = a;
    a=b; b=tep;
}
int parti(int A[], int s, int e){
    int pindex = s;
    int pivot = A[e];
    for(int i=s;i<e;i++){
        if(A[i]<=pivot){
            //交换A[i]和A[pindex]
            swap(A[i],A[pindex]);
            pindex++;
        }
    }
    swap(A[e],A[pindex]);
    return pindex;
}
void quick_sort(int *A, int s, int e){  //e是有效的数组元素下标，不是数组长度
    if(s>=e) return;
    int pindex;
    pindex = parti(A, s, e);
    quick_sort(A,s,pindex-1);
    quick_sort(A,pindex+1,e);

}
int main()
{
    int n;n=10;
    int A[10] = {2,1,6,7,11,8,9,3,5,4};
    quick_sort(A,0,n-1);
    for(int i=0;i<n-1;i++) cout << A[i]<< " ";
    cout << A[n-1];
    return 0;
}
