#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int n, m;
int a, x, y;
vector< vector< int > > ns;
bool is[100000+9], vis[100000+9];
typedef pair<int, int> ii;
void BFS(int x){

    queue< pair<int, int> > q;
    q.push(ii(1, is[1]));
    int cnt=0;

    while(!q.empty()){

        ii no = q.front();q.pop();

        if(vis[no.first]) continue;
        vis[no.first]=true;

        if(no.second <= m ) {
            if(no.first != 1 && ns[no.first].size() == 1){
                cnt++;
            }
        }
        else continue;

        for(int i=0;i<ns[no.first].size();i++)
            q.push( ii( ns[no.first][i], is[ns[no.first][i]] ? no.second+1 : 0 ) );

    }

    printf("%d", cnt);

}

int main(){
    scanf("%d %d", &n, &m);
    ns= vector< vector< int > >(n+1);

    for(int i=1;i<=n;i++) scanf("%d", &is[i]);

    for(int i=0;i<n-1;i++){
        scanf("%d %d", &x, &y);
        ns[x].push_back(y);
        ns[y].push_back(x);
    }

    BFS(1);

    return 0;
}
