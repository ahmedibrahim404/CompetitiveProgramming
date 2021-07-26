#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
int n;
pair<int, int> ns[100+9];
bool took[100+9];

bool cmpr(pi p2, pi p1){
    return p2.second > p1.second;
}

vector<pi> ans;

int main(){
    scanf("%d", &n);
    int poly;scanf("%d", &poly);
    ans=vector<pi>(n+9);
    for(int i=2;i<=n;i++){
        scanf("%d", &ns[i].second);
//        ns[i].second=100;
        ns[i].first=i;
    }

    took[1]=true;

    sort(ns+2, ns+n+1, cmpr);
    int ani=0;
    int i=2;
    queue<pi> q;
    for(int j=0;j<poly && i <= n;j++){
        q.push( pi( ns[i].first, ns[i].second ) );
        took[ ns[i].first ]=true;
        ans[ani].first=1, ans[ani++].second=ns[i].first;
        i++;
    }

    i=1+poly;
    while(!q.empty() && i <=n){
        pi node=q.front();q.pop();

        while(node.second && i <=n){
            if(took[ ns[i].first ]){
                i++;
                continue;
            }
            took[ ns[i].first ]=true;
            node.second--;
            q.push( pi( ns[i].first, ns[i].second ) );
            ans[ani].first=node.first, ans[ani++].second=ns[i].first;
            i++;
        }

    }

   if( ani != n-1 ){
        return printf("-1\n"), 0;
    }

    printf("%d\n", ani);
    for(i=0;i<ani;i++){
        printf("%d %d\n", ans[i].first, ans[i].second);
    }







    return 0;
}
