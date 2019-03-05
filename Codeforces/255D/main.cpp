#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pi;
typedef pair<pair<int, int>, int> pii;
typedef long long int ll;

ll n, x, y, c, cur;

vector< bool > vis;

ll xs[] = { 1, -1, 0, 0 };
ll ys[] = { 0, 0, 1, -1 };

void BFS(){

    queue<pair<pi, int>> q;
    q.push(make_pair(make_pair(x, y), 0));
    cur=0;

    while(!q.empty()){
        pii p = q.front();
        q.pop();
        cur++;

        if(cur >= c){
            cout << p.second << endl;
            return;
        }

        ll nx=p.first.first, ny=p.first.second;
        vis[((nx-1)*n)+ny] = true;


        for(int i=0;i<4;i++){
            ll newx = nx+xs[i], newy = ny+ys[i];
            if(newx >= 1 && newx <= n && newy >= 1 && newy <= n && !vis[((newx-1)*n)+newy]){
                q.push(make_pair(make_pair(newx, newy), p.second+1));
                vis[((newx-1)*n)+newy]=true;
            }
        }



    }

}

int main(){

    scanf("%lld %lld %lld %lld", &n, &x, &y, &c);
    vis = vector< bool >((n*n)+1);
    if(c == 1){
            printf("0");
            return 0;
    }

    BFS();

    return 0;
}
