#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pi;
typedef vector<pi> vi;
int n;
ll a, b, x, cnt=0;
vi ns, cur;
int main(){
    scanf("%d %lld",&n,&x);
    ns =vi(n+3);int idx=0;
    cur=vi(n);
    ns[0].first=ns[0].second=0;
    for(int i=0;i<n;i++){
        scanf("%lld %lld",&cur[i].first,&cur[i].second);
    }
    sort(cur.begin(), cur.end());
    for(int i=0;i<n;i++){
        ll a=cur[i].first, b=cur[i].second;
        if(a > ns[idx].second){
            ns[idx].first=a;
            ns[idx].second=b;
            idx++;
            continue;
        }
        if(b > ns[idx-1].second) ns[idx-1].second=b;
    }

    for(int i=0;i<idx;i++){
        ll a=ns[i].first, b=ns[i].second;
        cout << a << " " << b << endl;
        cnt += (b/x)-((a-1)/x);
    }
    printf("%lld", cnt);
    return 0;
}
