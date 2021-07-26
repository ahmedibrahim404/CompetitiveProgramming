#include<bits/stdc++.h>
using namespace std;
typedef vector<pair<int,int>> vp;

int N,a,b,mx=0,tot;
bool no[9],can;
int cnt[8][8];
void solve(int idx=0, bool cols[]=no, vp cn=vp(9)){


    if(idx==N){
        tot=0;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(j==cn[i].second) tot+=cnt[i][j];
                //(i,j)
            }
        }
        if(tot>mx)mx=tot;
        return;

    }

    for(int i=0;i<N;i++){
        if(cols[i]==1)continue;
        can=1;
        for(int j=0;j<idx;j++){
            a=cn[j].first-idx, b=cn[j].second-i;
            if(a==b||a==-b){
                can=0;
                break;
            }
        }
        if(can){
            cols[i]=1;
            cn[idx].first=idx, cn[idx].second=i;
            solve(idx+1, cols, cn);
            cols[i]=0;
        }
    }

}
int T;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>T;
    while(T--){
            mx=0;
    N=8;
    for(int i=0;i<8;i++)for(int j=0;j<8;j++){
        cin>>cnt[i][j];
    }
    for(int i=0;i<8;i++) no[i]=0;
    solve();
    cout<<mx<<endl;


    }
    return 0;
}
