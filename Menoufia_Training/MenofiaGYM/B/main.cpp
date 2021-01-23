#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
int T,n ,m ,q;
vector<pi> ns;
vector<pi> sp;

int si(pi p){
    return p.first;
}

bool cmpr(pi p2, pi p1){
    if(si(p2) != si(p1)) return si(p2) < si(p1);
    return p2.second < p1.second;
}

bool cmp(int n, pair<int,int> &p)
{
    return p.second > n;
}

int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d %d %d",&n,&m,&q);
        ns=vector<pi>(n);
        sp=vector<pi>(n+5);
        for(int i=0;i<n;i++) scanf("%d %d", &ns[i].first, &ns[i].second);
        sort(ns.begin(), ns.end());
        int idx=0;

        if(ns[0].first > 1){
            sp[idx].first=ns[0].first-1, sp[idx].second=1, idx++;
        }

        for(int i=0;i<n-1;i++){
            if(ns[i+1].first - ns[i].second > 1){
                sp[idx].first=(ns[i+1].first-1)-(ns[i].second+1)+1;
                sp[idx].second=ns[i].second+1;
                idx++;
            }
        }

        if(m-ns[n-1].second>0){
            sp[idx].first=m-(ns[n-1].second+1)+1;
            sp[idx].second=ns[n-1].second+1;idx++;
        }

        sp.resize(idx);
        sort(sp.begin(), sp.end(), cmpr);

        int sz;
        while(q--){
            scanf("%d",&sz);
            int ix=upper_bound(sp.begin(), sp.end(), sz, cmp)-sp.begin();
            int f=0, t=0;
            cout << "IDX IS " << ix << endl;
            for(int i=ix;i<idx;i++){
                if(sp[i].second > f) f=sp[i].second=f, t=sp[i].second+sp[i].first-1;
            }
            if(f!=0 && t!=0) printf("%d %d\n", f, t);
            else printf("-1 -1\n");
        }

    }
    return 0;
}
