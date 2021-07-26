#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int q, t;
ll v, u, w;

map<ll, pair<ll, ll>> mp;

void increase(ll v, ll u, ll w){

    while(v != u){

        if(v > u){
            if((double) v/2 == v/2 ) mp[v/2].first+=w;
            else mp[v/2].second+=w;
            v=v/2;
        } else {
            if((double) u/2 == u/2 ) mp[u/2].first+=w;
            else mp[u/2].second+=w;
            u=u/2;
        }


    }

}

ll getw(ll v, ll u){
    ll cost=0, p;
    while(v != u){

        if(v > u){
            p=v/2;
            if((double) v/2 == p) cost += mp[p].first;
            else cost += mp[p].second;
            v=v/2;
        } else {
            p=u/2;
            if((double) u/2 == p) cost += mp[p].first;
            else cost += mp[p].second;
            u=u/2;
        }

    }

    return cost;

}

int main(){

    scanf("%d", &q);

    while(q--){

        scanf("%d", &t);

        if(t==1){
            scanf("%lld %lld %lld", &v, &u, &w);
            increase(v, u, w);
        } else {
            scanf("%lld %lld", &v, &u);
            printf("%lld\n", getw(v, u));
        }

    }

    return 0;
}
