#include<bits/stdc++.h>
using namespace std;

int N,R;
string ns[21];
int sol[21];
vector<vector<string>> ans;
void solve(int idx=0, int rem=0, int *res=sol){
    if(idx>N) return;
    if(rem==0){
        for(int i=R-1;i>=0;i--) {
            cout<<ns[ res[i] ];
            if(i!=0) cout<<" ";
        }
        cout<<endl;
        return;
    }
    if(idx==N)return;

    solve(idx+1, rem, sol);

    sol[R-rem]=idx;
    solve(idx+1, rem-1, sol);
    sol[R-rem]=0;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>N>>R;

    for(int i=0;i<N;i++)cin>>ns[i];
    sort(ns, ns+N);
    reverse(ns, ns+N);
    for(int i=0;i<21;i++) sol[i]=0;
    solve(0, R, sol);
    return 0;
}
