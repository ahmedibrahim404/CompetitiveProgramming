#include<bits/stdc++.h>
using namespace std;
typedef vector<pair<int,int>> vp;

int N,a,b;
bool no[11],can;
void solve(int idx=0, bool cols[]=no, vp cn=vp(10)){


    if(idx==N){

        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(j==cn[i].second) cout<<"Q";
                else cout<<".";
            }
            cout<<endl;
        }

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
        cout<< idx << " " << i << " " << can << endl;
        if(can){
            cols[i]=1;
            cn[idx].first=idx, cn[idx].second=i;
            solve(idx+1, cols, cn);
        }
    }

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>N;
    for(int i=0;i<11;i++) no[i]=0;
    solve();
    return 0;
}
