#include<bits/stdc++.h>
using namespace std;

int as[1000][1000];
int c1[1000];
vector<int> v;
int n, m, a, b;
int main(){
    scanf("%d %d", &n, &m);
    v= vector<int>( max(n, m) );
    for(int i=0;i<n;i++){
        scanf("%d %d", &a, &b);
        a--, b--;
        as[a][b]++;
        c1[b]++;
    }


    int be=0, ma=0, idx=0;
    for(int i=0;i<m;i++){
        scanf("%d %d", &a, &b);
        a--, b--;

        if(as[a][b] > 0){
            as[a][b]--;
            be++;
            c1[b]--;
        } else {
            v[idx++] = b;
        }

    }

    for(int i=0;i<idx;i++){
        if( c1[ v[i] ] > 0 ){
            c1[ v[i] ]--;
            ma++;
        }
    }

    printf("%d %d", ma+be, be);



    return 0;
}
