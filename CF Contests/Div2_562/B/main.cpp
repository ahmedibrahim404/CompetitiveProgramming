#include<bits/stdc++.h>
using namespace std;

int n, m, a, b;
int ns[300000+9];
map<string, int> mp;
vector<int> v;
int main(){

    scanf("%d %d", &n, &m);
    v=vector<int>(n+1);
    int idx=0;
    for(int i=0;i<m;i++){
        scanf("%d %d", &a, &b);
        a--, b--;

        ns[a]++;
        ns[b]++;

        v[idx++]=a, v[idx++]=b;

        if(a > b) swap(a, b);
        if(mp.count( to_string(a) + " " + to_string(b) )){
            mp[ to_string(a) + " " + to_string(b) ]++;
        } else mp[ to_string(a) + " " + to_string(b) ]=1;
    }



//    sort(ns, ns+n);
    for(int i=0;i<idx;i++){
        for(int j=i+1;j<idx;j++){
            if(ns[ v[i] ] + ns[ v[j] ] < m) continue;
            int id=v[i], id2=v[j];
            if(id > id2) swap(id, id2);
            if( ns[ v[i] ] + ns[ v[j] ] - mp[ to_string(id) + " " + to_string(id2) ] == m ){
                return printf("YES\n"), 0;
            }
        }
    }

    printf("NO\n");


    return 0;
}
