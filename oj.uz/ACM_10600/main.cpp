#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct edg {
    int x, y, v, index;
    bool del=false;
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

int t, n, m, a, b, c;
vector<int> tok;
int main(){
    cin >> t;
    string answer="";
    while(t--){

        cin >> n >> m;

        disjoin_set ds(n);
        tok = vector<int>(m);

        for(int i=0;i<m;i++){

            cin >> a >> b >> c;
            E[i].x = a, E[i].y=b, E[i].v=c, E[i].del=false;

        }

        sort(E, E+m, cmp);

        int to=0;
        int en=0;
        for(int i=0;i<m;i++){

            if(ds.union_sets(E[i].x, E[i].y)){

                to += E[i].v;
                tok[en]=i;
                en++;

            }
        }

        int secondMin = 1e7, co2;

        for(int i=0;i<en;i++){

            E[tok[i]].del=true;
            co2=0;
            disjoin_set ds2(n);

            for(int j=0;j<m;j++){

                if(E[j].del) continue;

                if(ds2.union_sets(E[j].x, E[j].y))
                    co2 += E[j].v;

            }

            E[tok[i]].del = false;

            secondMin = min(co2, secondMin);

        }


        answer += to_string(to) + " " + to_string(secondMin) + "\n";

    }

    cout << answer << endl;
    return 0;
}
