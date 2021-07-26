#include <bits/stdc++.h>
using namespace std;
int n,h,i,s,a[1010];
int main()
{
    cin>>n>>h;
    for(i=1;i<=n;i++)
        cin>>a[i];
    for(i=1;i<=n;i++)
    {
        sort(a+1,a+i+1);
        s=0;
        for(int j=i;j>=1;j-=2)
            s+=max(a[j],a[j-1]);
        if(s>h)
            break;
    }
    cout<<i-1;
    return 0;
}
