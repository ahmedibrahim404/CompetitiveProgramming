#include<bits/stdc++.h>
using namespace std;

int n, m, k;
int groups[500+9];
int idx[100000+9];
int parent[100000+9];
int ns[500+9][500+9];
int get(int node){
    if(parent[node]==node) return node;
    return parent[node]=get(parent[node]);
}

int a, b, c;
int main(){
    scanf("%d %d %d", &n, &m, &k);
    for(int i=1;i<=n;i++) parent[i]=i;
    for(int i=1;i<=k;i++){
        scanf("%d", &groups[i]);
        groups[i] += groups[i-1];
        for(int j=groups[i-1]+1;j<=groups[i];j++) idx[j]=i;
    }

    for(int i=1;i<=k;i++) for(int j=1;j<=k;j++){
        ns[i][j]=(i==j?0:1e9);
    }

    for(int i=0;i<m;i++){
        scanf("%d %d %d", &a, &b, &c);
        int gr1=idx[a], gr2=idx[b];
        if(c == 0)parent[ get(a) ]=get(b);
        ns[ gr1 ][ gr2 ]=ns[ gr2 ][ gr1 ]=min(ns[ gr1 ][ gr2 ], c);
    }
	for(int i=1;i<=k;i++){
		int cur=get(groups[i-1]+1);
		for(int j=groups[i-1]+1;j<=groups[i];j++){
                if (get(j)!=cur){printf("No\n");return 0;}
			}
    }


    printf("Yes\n");
    for(int l=1;l<=k;l++)
        for(int i=1;i<=k;i++)
            for(int j=1;j<=k;j++){
                if(i == l || l == j || i == j) continue;
                if(ns[i][l]+ns[l][j] < ns[i][j])ns[i][j]=ns[i][l]+ns[l][j];
            }

        for(int i=1;i<=k;i++){
            for(int j=1;j<=k;j++){
                if(ns[i][j]==1e9)ns[i][j]=-1;
                 printf("%d ", ns[i][j]);
            }
            printf("\n");
        }


    return 0;
}
