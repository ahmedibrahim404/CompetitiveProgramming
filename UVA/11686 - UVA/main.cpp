#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
int n, m;
vvi ns;
vi ans;

int in[1000000+3];
int main(){
    while(cin >> n >> m){
        if(!n&&!m) break;
        ns=vvi(n);
        ans.clear();
        memset(in, 0, sizeof in);
        int a, b;
        while(m--){
            cin >> a >> b;
            a--, b--;
            ns[a].push_back(b);
            in[b]++;
        }
        bool done=1;
        queue<int> q;
        for(int i=0;i<n;i++){
            if(!in[i]) q.push(i);
        }

        while(!q.empty()){

            int node=q.front();q.pop();
            for(int to: ns[node]){
                in[to]--;
                if(!in[to]) q.push(to);
            }
            ans.push_back(node);

        }

        if(ans.size()==n){
            for(int i=0;i<ans.size();i++) cout << ans[i]+1 << "\n";
        } else {
            cout << "IMPOSSIBLE\n";
        }




    }

    return 0;
}
