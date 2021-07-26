#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> pii;

vector< vector< pii > > ns;

char mrk[3], stra[25], strb[25], useless[3];
int a, b;
map<string, int> mp;
int idx=0;

bool found=false;

bool visited[61];

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

void DFS(int fr, int to, int nume, int deno, char aa[], char bb[]){

    if(found) return;

    if(visited[fr]) return;

    visited[fr]=true;



    if(fr == to){

        int GCD=gcd(nume, deno);
        printf("%d %s = %d %s\n", nume/GCD, aa, deno/GCD, bb);
        found=true;
        return;
    }

    for(int i=0;i<ns[fr].size();i++){
        if(!visited[ ns[fr][i].first ]) DFS(ns[fr][i].first, to, nume*ns[fr][i].second.first, deno*ns[fr][i].second.second, aa, bb);
    }
}

int main(){

    ns = vector< vector< pii >> (61);

    while(scanf("%s", mrk) == 1 && mrk[0] != '.'){

        if(mrk[0] == '!'){

            scanf("%d %s %s %d %s", &a, stra, useless, &b, strb);

            if(mp.count( string(stra) ) == 0) mp[string(stra)]=idx++;
            if(mp.count( string(strb) ) == 0) mp[string(strb)]=idx++;


            ns[ mp[string(stra)] ].push_back( make_pair( mp[string(strb)], ii( a, b ) ) );
            ns[ mp[string(strb)] ].push_back( make_pair( mp[string(stra)], ii( b, a ) ) );

        } else {

            scanf("%s %s %s", stra, useless, strb);
            found=false;
            for(int i=0;i<61;i++) visited[i]=false;
            DFS( mp[ string(stra) ], mp[ strb ], 1, 1, stra, strb );

            if(found==false){
                printf("? %s = ? %s\n", stra, strb);
            }

        }

    }

    return 0;
}
