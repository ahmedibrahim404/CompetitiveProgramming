#include <iostream>
#include <bits/stdc++.h>


using namespace std;


struct edg {
    int x, y, v;
};
edg E[755*755];
bool cmp(edg a, edg b) {
    return a.v < b.v;
}

typedef vector<int> vi;

struct disjoin_set {

    vi rank, parent;
    int forests;

    disjoin_set(int n){
        rank = vi(n+1), parent=vi(n+1);
        forests = n;
        for(int i=0;i<n;i++) parent[i]=i, rank[i]=1;
    }

    int find_set(int x){
        if(parent[x] == x) return x;
        return parent[x] = find_set(parent[x]);
    }

    void link(int x, int y){

        if(rank[x] > rank[y]) swap(x, y);
        parent[x] = y;
        if(rank[x] == rank[y]) rank[y]++;

    }

    bool union_sets(int x, int y){

        x = find_set(x), y=find_set(y);

        if(x!=y){
            link(x, y);
            forests--;
        }

        return x != y;

    }

};

int t;
int n, m,a ,b;
int x[1000], y[1000];
int main(){
    cin >> t;

    while(t--){

        cin >> n;
        disjoin_set ks(n);

        for(int i=1;i<=n;i++)
            cin >> x[i] >> y[i];

        cin >> m;
        int ad=0;
        while(m--){
            cin >> a >> b;
            ad += ks.union_sets(a, b);
        }


        if(ad == n-1){
            cout << "No new highways need" << endl;
        } else {

            m = 0;
            for(int i = 1; i <= n; i++) {
                for(int j = i+1; j <= n; j++) {
                    E[m].x = i, E[m].y = j;
                    E[m].v = (x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
                    m++;
                }
            }

            sort(E, E+m, cmp);

            for(int i = 0; i < m; i++) {
                if(ks.union_sets(E[i].x, E[i].y)) {
                    cout << E[i].x << " " << E[i].y << endl;
                }
            }

        }

        if(t>0)
            cout << "" << endl;

    }

    return 0;
}
