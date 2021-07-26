#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll sum=0, mx=0, no;
set<ll> st;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&no);
        sum += no;
        if(no>mx)mx=no;
    }

    if(mx <= sum-mx&&!(sum&1))
    printf("YES\n");
    else
    printf("NO\n");
    return 0;
}
