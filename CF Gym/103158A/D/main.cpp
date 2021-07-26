#include<bits/stdc++.h>
using namespace std;
const int N = 200000 + 3;
int ans[N], dis[N];
bool vis[N];

bool valid(int x){
    return x > 0 && x < N && !dis[x];
}

void bfs(){
    queue<int> q;
    q.push(2);
    memset(dis, 0, sizeof dis);
    dis[2]=1;
    while(!q.empty()){
        int cur=q.front();q.pop();
        if(valid(cur*2)) dis[cur*2] = dis[cur]+1, q.push(cur*2);
        if(valid(cur/2)) dis[cur/2] = dis[cur]+1, q.push(cur/2);
        if(valid(cur+2)) dis[cur+2] = dis[cur]+1, q.push(cur+2);
        if(valid(cur-2)) dis[cur-2] = dis[cur]+1, q.push(cur-2);
    }

}

int main(){


    int t, n;
    scanf("%d",&t);
    bfs();
    while(t--){
        scanf("%d",&n);
        if(!n) printf("-1\n");
        else printf("%d\n", dis[n]);
    }

    return 0;
}
