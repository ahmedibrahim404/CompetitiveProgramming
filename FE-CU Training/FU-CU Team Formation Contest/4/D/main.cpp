#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<double, ll> pi;
const int MAX=100000+3;
const double EPS=1e-8;
int N;


pi ns[MAX];
ll xx, yy;

int is(double x) {
    int cur=0;
    while (cur < N) {
        if(ns[cur].first > x + ns[cur].second) return 0;
        x += 1.0 * ns[cur].second;
        cur++;
    }
    return 1;
}

int main(){

    scanf("%d%lld%lld",&N,&xx,&yy);
    ll x, y;
    for(int i=0;i<N;i++){
        scanf("%lld%lld%lld",&x,&y,&ns[i].second);
        ns[i].first= sqrt( 1LL*(x-xx)*(x-xx)+1LL*(y-yy)*(y-yy) );
    }

    sort(ns, ns+N);
    double l=0, r=ns[N-1].first; double ans=r;

    while(r-l>EPS){
        double mid=l+(r-l)/2;

        if(is(mid)){r=mid;
        }
        else {l=mid;
        }
        }

     printf("%.10lf\n", r);

    return 0;
}
