#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

struct disjoin_set {

    vi rank, parent, cnt;

    disjoin_set(int n){
        parent=vi(n);
        cnt=vi(n);
        for(int i=0;i<n;i++) parent[i]=i;
    }

    int find_set(int x){
        if(parent[x] == x) return x;
        return parent[x] = find_set(parent[x]);
    }

    void link(int x, int y){
        parent[x] = y;
    }

    bool union_sets(int x, int y){
        x--, y--;

        x = find_set(x), y=find_set(y);

        if(x!=y) link(x, y);

        return x != y;

    }

};

int n, m, a, b;
int nss[500000+9];
int main(){
    scanf("%d %d", &n, &m);
    disjoin_set st=disjoin_set(n);

    while(m--){
        scanf("%d", &a);
        int idx=0;
        int num=-1;
        while(a--){
            scanf("%d", &b);
            if(num == -1) num=b;
            else st.union_sets(b, num);
        }
    }

    for(int i=0;i<n;i++) st.find_set(i);
    for(int i=0;i<n;i++) nss[st.parent[i]]++;
    for(int i=0;i<n;i++) printf("%d ", nss[st.parent[i]]);




    return 0;
}
