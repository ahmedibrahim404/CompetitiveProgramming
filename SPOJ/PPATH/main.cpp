#include<bits/stdc++.h>

using namespace std;
typedef pair<int, int> pi;
const int MAX=10000+1;
bool prime[MAX];
bool vis[MAX];

int main(){
    memset(prime, 1, sizeof prime);
    prime[1]=0;
    for(int i=2;i*i<MAX;i++){
        if(!prime[i]) continue;
        for(int j=i*i;j<MAX;j+=i){
            prime[j]=0;
        }
    }

    int T;
    cin >> T;
    while(T--){
    memset(vis, 0, sizeof vis);
    int a, b;
    cin >> a >> b;
    queue<pi> q;
    q.push({a, 0});
    bool is=0;
    while(!q.empty()){

        pi num=q.front();q.pop();
        int dup=num.first;
        if(dup==b){
            cout << num.second << "\n";
            is=1;
            break;
        }
        vis[dup]=1;

        int res=1;
        for(int i=0;i<4;i++){
            int cur=dup%10;

            for(int j=0+(i==3);j<=9;j++){
                if(cur == j) continue;
                int nw=num.first-cur*res+j*res;
                if(vis[nw] || !prime[nw]) continue;
                vis[nw]=1;
                q.push({nw, num.second+1});
            }
            res *= 10;
            dup /= 10;
        }

    }

    if(!is){
        cout << "Impossible\n";
    }

    }

    return 0;
}
