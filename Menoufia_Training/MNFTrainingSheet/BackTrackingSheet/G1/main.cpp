#include<bits/stdc++.h>

using namespace std;
int N, ns[21], ans[21], h=0;
vector<vector<int>> vs;
void run(int idx=0, int no=0, vector<int> ans=vector<int>(N)){

    if(idx==N){
        if(!no) return;
        ans.resize(no);
        vs[h++]=ans;
        return;
    }
    run(idx+1, no, ans);

    if(!no || ns[idx]>ans[no-1]){
        ans[no]=ns[idx];
        run(idx+1, no+1, ans);
    }

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>N;
    for(int i=0;i<N;i++) cin >> ns[i];
    vs=vector<vector<int>>((1<<N));
    run();
    sort(vs.begin(), vs.begin()+h);
    for(int i=0;i<h;i++){
        int sz=vs[i].size();
        for(int k=0;k<sz;k++){
            cout<<vs[i][k];
            if(k!=sz-1) cout<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
