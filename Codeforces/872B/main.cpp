#include<bits/stdc++.h>
using namespace std ;
long long i , a[1111111] , k , mx = -1e11 , mn = 1e11 , n;
int main()
{
    cin>>n>>k;
    for(i = 1 ; i <= n ; i ++)
    {
        cin>>a[i];
        mx = max(mx , a[i]);
        mn = min(mn , a[i]);
    }
    if(k > 2)cout<<mx; else {if(k == 1)cout<<mn; else cout<<max(a[1] , a[n]);}
}
