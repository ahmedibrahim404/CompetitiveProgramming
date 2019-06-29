#include<bits/stdc++.h>
using namespace std;

int n, m, a, b, c;
typedef long long ll;
struct edge {

    int from, to;
    ll v;
    edge(int from, int to, ll v): from(from), to(to), v(v) {}

    bool operator < (const edge &e) const {
        return v > e.v;
    }

};

typedef vector<vector<edge>> ve;
typedef vector<int> vi;
ve ns;
vi previous(100000+9, -1);

ll dijkstra(){

    int sz=ns.size();

    ll dist[sz+9];
    for(int i=0;i<sz+9;i++) dist[i]=1e17;
    dist[0]=0;

    priority_queue<edge> q;
    q.push( edge(-1, 0, 0) );

    while(!q.empty()){
        edge e=q.top();q.pop();

        if(e.v > dist[e.to]) continue;

        previous[ e.to ]=e.from;
        if(e.to == n-1) return dist[n-1];

        for(int j=0;j<ns[e.to].size();j++){
            edge no=ns[e.to][j];

            if(dist[no.to] > dist[no.from] + no.v){
                no.v = dist[no.to] =dist[no.from] + no.v;
                q.push(no);
            }

        }
    }
    return dist[n-1];

}

int rd(int src){
    if(src != 0) rd(previous[src]);
    cout << src+1 << " ";
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    cin >> n >> m;
    ns = ve(n);
    while(m--){
        cin >> a >> b >> c;
        a--, b--;
        ns[a].push_back(edge(a, b, c));
        ns[b].push_back(edge(b, a, c));
    }

    if(dijkstra() ==1e17){
        cout << -1 << endl;
        return 0;
    }


    string ans="";
    int cur=n-1;
    while(cur != 0){
        ans = to_string(cur+1) + " " + ans;
        cur = previous[cur];
    }

    cout <<  "1 " + ans << endl;

    rd(n-1);

    return 0;
}
