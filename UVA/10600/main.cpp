#include <iostream>
#include <bits/stdc++.h>

using namespace std;
string sol="";
struct node {
    int x, y, v;
    bool del;
};

node E[10000+9];

bool cmr(node n1, node n2){
    return n1.v < n2.v;
}

struct disjoint {

    vector<int> parents;

    disjoint(int n){
        parents = vector<int>(n+1);
        for(int i=1;i<=n;i++) parents[i]=i;
    }

    int find_set(int n){
        if(parents[n]==n) return n;
        return parents[n] = find_set(parents[n]);
    }

    bool link(int a, int b){

        a = find_set(a), b=find_set(b);

        if(a != b){
            if(a > b) swap(a, b);
            parents[a] = b;
        }

        return a != b;

    }

};

int T, N, M, a, b, c, total1=0, mincost=0xfffffff, th=0, en=0;
int main(){

    cin >> T;

    while(T--){
        mincost=0xfffffff;
        cin >> N >> M;
        disjoint ds(N);

        for(int i=0;i<M;i++){
            cin >> a >> b >> c;
            E[i].x = a, E[i].y = b, E[i].v=c, E[i].del=false;
        }

        sort(E, E+M, cmr);
        total1=0, en=0;

        int ontree[N+1];

        for(int i=0;i<M;i++)
            if(ds.link(E[i].x, E[i].y))
                total1 += E[i].v, ontree[en++]=i;

        printf("%d ", total1);

        for(int i=0;i<en;i++){
            E[ontree[i]].del=true;
            disjoint ds2(N);
            th=0;
            int cnt=0;
            for(int j=0;j<M;j++){
                if(!E[j].del)
                    if(ds2.link(E[j].x, E[j].y))
                        th += E[j].v, cnt++;
            }

            E[ontree[i]].del=false;
            if(mincost > th && cnt == N-1) // cnt important
                mincost = th;
        }

        printf("%d\n", mincost);
    }

    return 0;
}

