#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool vis[2001][2001];

int xs[4] = { 1, -1, 0, 0 };
int ys[4] = { 0, 0, 1, -1 };
int N, M, K, a, b;
pair<int, int> sol;

void bfs(queue<int> q){
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        int y = q.front();
        q.pop();

        if(vis[x][y]) continue;
        vis[x][y]=true;

        sol.first=x;
        sol.second=y;

        for(int i=0;i<4;i++){

            int newx = x+xs[i], newy = y+ys[i];
            if(newx > 0 && newy > 0 && newx <= N && newy <= M)
                q.push(newx), q.push(newy);

        }


    }
}



int main(){

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> N >> M;
    cin >> K;


    queue<int> q;

    while(K--){
        cin >> a >> b;
        q.push(a);
        q.push(b);
    }

    bfs(q);

    cout << sol.first << " " << sol.second << endl;

    return 0;
}
