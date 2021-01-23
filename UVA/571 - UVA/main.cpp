#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
int ca, cb, n;
const int MAX=1000+1;
string anss[7];
int par[MAX][MAX];
pi pre[MAX][MAX];

int main(){

    anss[1]="empty A";
    anss[2]="empty B";
    anss[3]="fill A";
    anss[4]="fill B";
    anss[5]="pour A B";
    anss[6]="pour B A";
    while(cin >> ca >> cb >> n){
    memset(par, 0, sizeof par);
    queue<pi> q;
    q.push({0, 0});
    int fna, fnb;
    par[0][0]=-1;

    while(!q.empty()){

        pi cur=q.front();q.pop();
        int a=cur.first, b=cur.second;

        if(b==n){
            fna=a, fnb=b;
            break;
        }

        int na, nb;
        na=0, nb=b;
        if(!par[na][nb]){
            q.push({na, nb});
            par[na][nb]=1;
            pre[na][nb]=cur;
        }

        na=a, nb=0;
        if(!par[na][nb]){
            q.push({na, nb});
            par[na][nb]=2;
            pre[na][nb]=cur;
        }
        na=ca, nb=b;
        if(!par[na][nb]){
            q.push({na, nb});
            par[na][nb]=3;
            pre[na][nb]=cur;

        }

        na=a, nb=cb;
        if(!par[na][nb]){
            q.push({na, nb});
            par[na][nb]=4;
            pre[na][nb]=cur;

        }

        int put=min(cb-b, a);
        na=a-put, nb=b+put;
        if(!par[na][nb]){
            q.push({na, nb});
            par[na][nb]=5;
            pre[na][nb]=cur;

        }

        put=min(ca-a, b);
        nb=b-put, na=a+put;
        if(!par[na][nb]){
            q.push({na, nb});
            par[na][nb]=6;
            pre[na][nb]=cur;
        }

    }

    vector<string> ans;
    while(par[fna][fnb] != -1){
        ans.push_back(anss[ par[fna][fnb] ]);
        pi pr=pre[fna][fnb];
        fna=pr.first, fnb=pr.second;
    }

    reverse(ans.begin(), ans.end());
    for(int i=0;i<ans.size();i++){
        cout << ans[i] << "\n";
    }

    cout << "success\n";

    }
    return 0;
}
