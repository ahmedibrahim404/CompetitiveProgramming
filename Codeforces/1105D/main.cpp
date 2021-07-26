#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef pair<pi, int> pii;

int n, m, p;
char ns[1000+9][1000+9];
ll speed[10];
ll res[10];

bool stop[10];

vector< queue<pi> > qus;
int xs[] = {1, -1, 0, 0};
int ys[] = {0, 0, -1, 1};

int BFS(int st){


    queue<pii> q;

    while(!qus[st].empty()){
        pi o = qus[st].front();
        q.push(make_pair(pi(o.first, o.second), 0));
        qus[st].pop();
    }



    int cnt=0;
    while(!q.empty()){
        pii no=q.front();q.pop();
        int x=no.first.first, y=no.first.second, u=no.second;
        if(u >= speed[st]) continue;
        for(int i=0;i<4;i++){
            int nx=x+xs[i], ny=y+ys[i];
            if(nx >= 0 && ny >=0 && nx < n && ny < m && ns[nx][ny] == '.'){
                qus[st].push(pi(nx, ny));
                q.push(make_pair(pi(nx, ny), u+1));
                ns[nx][ny]=(char) st;
                cnt++;
            }
        }
    }

    return cnt;

}

int main(){

    scanf("%d %d %d", &n, &m, &p);

    qus=vector< queue<pi> >(p+1);


    for(int i=0;i<p;i++){
        scanf("%lld", &speed[i]);
    }

    for(int i=0;i<n;i++) {
        scanf("%s", ns[i]);
        for(int j=0;j<m;j++) if(isdigit(ns[i][j])){
            qus[ ns[i][j]- '0' - 1 ].push(pi(i, j));
            res[ns[i][j]- '0' - 1]++;
        }
    }

    int turn=0, stp=0;


    while(true){

        if(turn == p) turn=0;
        if(stp == p) break;
        if(stop[turn]){
            turn++;
            continue;
        }


        ll in=BFS(turn);

        if(in == 0){
            stop[turn]=1;
            stp++;
        }

        res[turn] += in;
        turn++;

    }


    for(int i=0;i<p;i++) printf("%d ", res[i]);

    return 0;
}
