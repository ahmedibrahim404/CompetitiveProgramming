#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pi;
const ll MAX=100000+5;
ll n, m;
vector<pi> ns;
ll a, b;
ll par[MAX], add[MAX];
ll get(ll no){
    if(par[no]==no) return no;
    return par[no]=get(par[no]);
}
bool cpr(pi p2, pi p1){
    if(max(p2.first+1, p2.second+1) != max(p1.first+1, p1.second+1))
    return max(p2.first+1, p2.second+1) < max(p1.first+1, p1.second+1);
    return min(p2.first+1, p2.second+1) < min(p1.first+1, p1.second+1);
}


bool union_set(ll a, ll b){
    a=get(a);
    b=get(b);
    if(a==b) return 0;
    par[a]=b;
    return 1;
}

int main(){
    scanf("%lld%lld",&n,&m);
    for(int i=0;i<n;i++) par[i]=i, add[i]=0;

    ns=vector<pi>(m);
    for(int i=0;i<m;i++){
        scanf("%lld%lld",&a,&b);
        a--, b--;
        if(a>b) swap(a, b);
        ns[i]={b, a};
    }
    sort(ns.begin(), ns.end(), cpr);

    for(int i=0;i<m;i++){
        a=ns[i].first, b=ns[i].second;
        if(get(a) != get(b)){
            union_set(a, b);
            add[a]++, add[b]++;
//            cout << a << " TO " << b << endl;
//            cout << get(a) << " " << get(b) << endl;
        }
    }
    ll mx=1;
    for(int i=0;i<n;i++){
        mx=max(mx, add[i]);
    }

    printf("%lld\n", mx);

    return 0;
}
