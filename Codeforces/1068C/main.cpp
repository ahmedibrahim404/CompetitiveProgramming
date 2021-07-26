#include <bits/stdc++.h>
using namespace std;
#define r push_back
vector<int>v[2222];
int n,m,c,x,y,i,j;
int main(){
    cin>>n>>m;

    for(i=0;i<m;i++){
        cin>>x>>y;
        v[x].push_back(++c);
        v[y].push_back(c);
    }

    for(i=1;i<=n;i++){
        v[i].push_back(++c);
        x=v[i].size();
        cout<<x<<endl;
        for(j=0;j<x;j++)printf("%d %d\n",i,v[i][j]);
    }

}
