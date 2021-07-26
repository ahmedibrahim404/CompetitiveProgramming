#include<bits/stdc++.h>
using namespace std;
bool prime[32],is[17];

void sieve(){

    for(int i=2;i<=16;i++){
        if(!prime[i]) continue;
        for(int j=i*i;j<=31;j+=i) prime[j]=0;
    }
}
int N, tot=0;
vector<int>st;
void solve(int idx=1, vector<int>ans=st, bool *took=is){

    if(idx==N){
        if(!prime[ ans[0]+ans[N-1] ]) return;
        for(int i=0;i<N;i++){
            cout<<ans[i];
            if(i!=N-1)cout<<" ";
        }
        cout<<"\n";
        return;
    }

    for(int i=2;i<=N;i++){
        if(took[i]) continue;
        if(!idx||prime[i+ans[idx-1]]) {
            ans[idx]=i;
            took[i]=1;
            solve(idx+1, ans);
            ans[idx]=0;
            took[i]=0;
        }
    }

}

int main(){
    scanf("%d",&N);
    st=vector<int>(N+1);
    st[0]=1;
    for(int i=2;i<32;i++)prime[i]=1;
    for(int i=1;i<=16;i++)is[i]=0;
    sieve();
    solve();
    return 0;
}
