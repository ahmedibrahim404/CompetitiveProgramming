#include<bits/stdc++.h>

using namespace std;

int f, s,g, u, d;

int main(){
    scanf("%d%d%d%d%d",&f,&s,&g,&u,&d);
    queue<int> q;
    q.push(s);

    int dis[f+1];
    memset(dis, -1, sizeof dis);
    dis[s]=0;
    while(!q.empty()){
        int to=q.front();q.pop();

        if(to==g) break;

        if(to + u <= f && dis[to + u] == -1){
            dis[to + u] = dis[to] + 1;
            q.push(to + u);
        }

        if(to - d >= 1 && dis[to - d] == -1){
            dis[to - d] = dis[to] + 1;
            q.push(to - d);
        }
    }

    if(dis[g] == -1) printf("use the stairs\n");
    else printf("%d\n", dis[g]);



    return 0;
}
