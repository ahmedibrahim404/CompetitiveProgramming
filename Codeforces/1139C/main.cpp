#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

int n, k, a, b, c;
bool visited[100000+9];

vvi ns;
int cnt;
void BFS(int src){

    queue<int> q;
    cnt=0;
    q.push(src);
    while(!q.empty()){
        int no=q.front();q.pop();
        cnt++;
        visited[no]=true;
        for(int i=0;i<ns[no].size();i++){
            if(visited[ns[no][i]]) continue;
            q.push( ns[no][i] );
        }
    }

}

inline ll power(ll x, ll p, ll m){
    ll res = 1;
    while(p){
        if(p & 1)
            res = ((res % m) * (x % m)) % m;
        x = ((x % m) * (x % m)) % m;
        p >>= 1;
    }
    return res;
}

int main(){

    scanf("%d %d", &n, &k);

    ns = vvi(n);

    for(int i=0;i<n-1;i++){
        scanf("%d %d %d", &a, &b, &c);
        a--, b--;
        if(c == 1) continue;
        ns[ a ].push_back(b);
        ns[ b ].push_back(a);
    }

    ll ans=power(n, k, 1e9+7);
    for(int i=0;i<n;i++){
        if(!visited[i]){
            BFS(i);
            ans -= power(cnt, k, 1e9+7);
        }
    }

    while(ans < 0){
        ans += 1e9+7;
    }

    printf("%lld", ans);


    return 0;
}
