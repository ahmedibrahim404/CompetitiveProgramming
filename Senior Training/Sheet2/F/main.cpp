#include<bits/stdc++.h>

using namespace std;
const int N=10000 + 3, M=50000 + 3;
int to[M], nxt[M], head[N];
int ne=0;
int n, m;
int deg[N];
bool vis[M];
void addEdge(int f, int t){
    to[ne] = t;
    nxt[ne] = head[f];
    head[f] = ne++;
}

vector<int> vi;
void init(){
    ne=0;
    memset(head, -1, n * sizeof head[0]);
    memset(deg, 0, n * sizeof deg[0]);
    memset(vis, 0, m * sizeof vis[0]);
    vi.clear();
}

void euler(int u){

    for(int &e=head[u];~e;){
        int z=e;
        e=nxt[e];
        if(vis[z]) continue;
        vis[z]=1;
        euler(to[z]);
    }

    vi.push_back(u);
}

int main(){
    while(scanf("%d%d",&n,&m) == 2){
        if(!n && !m) break;
        init();
        for(int i=0;i<m;i++){
            int a, b;
            scanf("%d%d",&a,&b);
            addEdge(a, b);
            deg[a]++;
            deg[b]--;
        }


        int c1=0, c2=0, c3=0;
        int st=0;
        for(int i=0;i<n;i++){
            if(deg[i] == 0){
                continue;
            } else if(deg[i]==1){
                c1++;
                st=i;
            } else if(deg[i] == -1) c3++;
            else c2++;
        }



        if(c2 || c1 > 1){
            printf("Impossible\n");
            continue;
        }

        if(c1 != c3){
            printf("Impossible\n");
            continue;
        }

        euler(st);
        reverse(vi.begin(), vi.end());
        if(vi.size() != m + 1){
            printf("Impossible\n");
            continue;

        }
        for(auto no: vi) printf("%d ", no);
        printf("\n");

    }

    return 0;
}
