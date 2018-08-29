#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;
int m[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main()
{
    int start; cin >> start;
    int d=13, day;
    for(int i=0; i<12; i++){
        day = (d-1+start)%7;
        d += m[i];
        if(day == 5) printf("%d\n", i+1);
    }
    return 0;
}
