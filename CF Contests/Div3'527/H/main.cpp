#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long ll;
const int MAX=1000000+3;
ll arr[MAX];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%lld",&arr[i]);
    }

    int r=n-1,l=0;
    while(r>l)
    {
        if(arr[l]>arr[r])
        {
            printf("1 ");
            ++l;
        }
        else if(arr[l]<arr[r])
        {
            printf("2 ");
            --r;
        }
        else
        {
            printf("0 ");
            --r;
            ++l;
        }
    }

    printf("0\n");

    return 0;
}
