#include<bits/stdc++.h>
using namespace std;
const int MAX=200000+3;
int n, m, k;
int ns[MAX], mx[MAX], dp[MAX];
vector<int> v;
int solve(int idx=0){

    if(idx==k) return 0;

    int &ret=dp[idx];
    if(~ret) return ret;

    ret=solve(idx+1)+ns[idx]-(idx?ns[idx-1]:0);
    for(int i=1;i<=k-idx;i++){
        if(mx[i]==0)continue;
        ret=min(ret, solve(idx+i)+ns[idx+i-1]-ns[idx+mx[i]-1]);
    }

    return ret;

}


int main(){
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<k+2;i++) dp[i]=-1;
    for(int i=0;i<n;i++) {
        scanf("%d",&ns[i]);
    }
    sort(ns, ns+n);
    for(int i=1;i<n;i++) ns[i] += ns[i-1];
    int a,b;
    for(int i=0;i<m;i++){
        scanf("%d%d",&a,&b);
        mx[a]=max(mx[a], b);
    }

    printf("%d\n", solve(0));


    return 0;
}
