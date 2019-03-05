#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector< vector< int > > langs;
int n, m, num, lang;

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
        x--, y--;

        x = find_set(x), y=find_set(y);

        if(x!=y){
            link(x, y);
            forests--;
        }

        return x != y;

    }


};


int main(){

    scanf("%d %d", &n, &m);
    disjoin_set gp(n);
    int t1=0;
    langs= vector< vector< int > >(m+1);
    for(int i=0;i<n;i++){
        scanf("%d", &num);

        if(num==0) t1++;

        while(num--){
            scanf("%d", &lang);
            langs[lang].push_back(i+1);
        }

    }

    int c=0;
    for(int i=1;i<=m;i++){

        for(int j=0;j<langs[i].size();j++){
            for(int k=j+1;k<langs[i].size();k++){
                if(gp.union_sets(langs[i][j], langs[i][k]))
                    c++;
            }
        }

    }

    if(c==n-1){
        printf("0");
        return 0;
    }
    int re=0;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if( gp.union_sets(i, j) ) c++, re++;;
            if(c == n-1) {
                if(t1==n) re++;
                printf("%d", re);
                return 0;
            }
        }
    }


    return 0;
}
