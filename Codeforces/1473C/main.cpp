#include<bits/stdc++.h>
using namespace std;
const double eps=1e-9;

int main()
{
    int t, n, k;
    cin>>t;
    while(t--&&cin>>n>>k){
        for(int i=1;i<=n-(2*(n-k)+1);i++)
            cout<<i<<" ";
        for(int i=k;i>=2*k-n;i--)
            cout<<i<<" ";
        cout<<"\n";
    }
    return 0;
}
