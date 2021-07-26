#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int>pi;
const int MAX= 200000+3;
pi ns[MAX];
pi level[MAX];
int n, END;
ll dp[MAX][2];
const ll OO=1e18;

//bool vis[MAX][2];

bool cpr(pi p1, pi p2){

    int mx1=max(p1.first, p1.second);
    int mx2=max(p2.first, p2.second);
    if(mx2!=mx1) return mx1<mx2;
    if(p1.first == p2.first) return p2.second < p1.second;
    return p1.first < p2.first;


}

ll getdis(int i1, int i2){
    return abs(ns[i1].first-ns[i2].first)+abs(ns[i1].second-ns[i2].second);
}

ll getlen(int i){
    int p1=level[i].first, p2=level[i].second;
    return 1LL*abs(ns[p1].first-ns[p2].first)+1LL*abs(ns[p1].second-ns[p2].second);
}

ll solve(int lvl=0, bool pos=0){


    if(lvl==END-1) return 0;

    ll &ret=dp[lvl][pos];
    if(~ret) return ret;
    ret=OO;

    int idx1=level[lvl+1].first, idx2=level[lvl+1].second;

    ll len=getlen(lvl+1);

    ll dis=getdis(level[lvl+1].first, pos?level[lvl].first:level[lvl].second);
//    cout << dis << endl;
    ret=min( ret, dis+len+solve(lvl+1, 0) );

    dis=getdis(level[lvl+1].second, pos?level[lvl].first:level[lvl].second);
//    cout << dis << endl;

    ret=min( ret, dis+len+solve(lvl+1, 1) );

    return ret;

}
//
//void build(int lvl=0, bool pos=0){
//
//
//    if(lvl==END-1){
//        cout << "DELEIVERED" << endl;
//        return;
//    }
//
//    ll ret=dp[lvl][pos];
//    if(vis[lvl][pos]) return;
//    vis[lvl][pos]=1;
//    int idx1=level[lvl+1].first, idx2=level[lvl+1].second;
//
//    ll len=getlen(lvl+1);
//    ll dis=getdis(level[lvl+1].first, pos?level[lvl].first:level[lvl].second);
//    ll ret1=dis+len+solve(lvl+1, 0);
//
//    dis=getdis(level[lvl+1].second, pos?level[lvl].first:level[lvl].second);
//    ll ret2=dis+len+solve(lvl+1, 1);
//
//    if(ret==ret1){
//        cout << "TO (" << ns[level[lvl+1].first].first << ", " << ns[level[lvl+1].first].second <<")" << "AND ADD " << len+getdis(level[lvl+1].first, pos?level[lvl].first:level[lvl].second) << endl;
//        build(lvl+1, 0);
//    } else if(ret==ret2){
//        cout << "TO (" << ns[level[lvl+1].second].first << ", " << ns[level[lvl+1].second].second <<")" << "AND ADD " << len+dis << endl;
//        build(lvl+1, 1);
//    }
//
//    return;
//
//
//}
//


int main(){

    for(int i=0;i<MAX;i++) for(int j=0;j<2;j++) dp[i][j]=-1;

    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&ns[i].first,&ns[i].second);
    }

    sort(ns, ns+n+1, cpr);
//    for(int i=1;i<=n;i++) cout << ns[i].first << ", " << ns[i].second << endl;

    int mx=0; END=0;
    for(int i=0;i<=n;i++){
        int curmx = max(ns[i].first, ns[i].second);
        if(curmx!=mx){
            if(END) level[END].second=i-1;
            level[++END].first=i;
            mx=curmx;
        }
    }
    level[END].second=n;
    END++;

    printf("%lld\n", solve(0, 0));
//    build();

    return 0;
}
