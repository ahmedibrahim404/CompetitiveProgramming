#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
int t, n, m;
vvi ns;
int colorArr[1000+3];

bool containsOdd(int src){
    colorArr[src] = 1;

    queue <int> q;
    q.push(src);

    while (!q.empty()){
        int u = q.front();
        q.pop();

        for (int v:ns[u]){

            if (colorArr[v] == -1){
                colorArr[v] = 1 - colorArr[u];
                q.push(v);
            }

            else if (colorArr[v] == colorArr[u])
                return true;
        }
    }

    return false;
}

int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&m);
        for (int i = 0; i < n; ++i) colorArr[i] = -1;
        ns=vvi(n);
        int a, b;
        for(int i=0;i<m;i++){
            scanf("%d %d",&a,&b);
            a--, b--;
            ns[a].push_back(b);
            ns[b].push_back(a);
        }
        bool c=0;
        for(int i=0;i<n;i++){
            if(colorArr[i]==-1){
                if(containsOdd(i)){
                    c=1;
                    break;
                }
            }
        }
        if(c) printf("no\n");
        else printf("yes\n");
    }
    return 0;
}
