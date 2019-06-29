#include<bits/stdc++.h>
using namespace std;

int n;
int xs[200], ys[200];
double ns[200][200];

double r(int f, int t){
    return sqrt( (xs[t]-xs[f])*(xs[t]-xs[f]) + (ys[t]-ys[f])*(ys[t]-ys[f]) );
}

int main(){
    int t=1;
    while(scanf("%d", &n) == 1 && n){

        for(int i=0;i<n;i++) scanf("%d %d", &xs[i], &ys[i]);
        for(int i=0;i<n;i++) for(int j=0;j<n;j++) ns[i][j] = (double) r(i, j);
        for(int k=0;k<n;k++)for(int i=0;i<n;i++)for(int j=0;j<n;j++){
            if(i == k || i == j || k == j) continue;
            ns[i][j]=(double) min( ns[i][j], max(ns[i][k], ns[k][j]) );
        }

        printf("Scenario #%d\nFrog Distance = %.3lf\n\n", t++, ns[0][1]);

    }
    return 0;
}
