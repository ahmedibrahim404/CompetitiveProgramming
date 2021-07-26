#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

typedef pair<ll, int> pi;
const int MAX=200000+3;
int t, n;
pi ns[MAX];
bool can[MAX];
ll get(int idx){
    return ns[idx].first - (idx ? ns[idx-1].first : 0 );
}

int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=0;i<n;i++) can[i]=0, ns[i].first=ns[i].second=0;
        for(int i=0;i<n;i++){
            scanf("%lld",&ns[i].first);
            ns[i].second=i;
        }
        sort(ns, ns+n);
        for(int i=0;i<n;i++) if(i) ns[i].first += ns[i-1].first;
        can[n-1]=1;vector<int> ans;
        ans.push_back(ns[n-1].second);
        for(int i=n-2;i>=0;i--){
            can[i] = (ns[i].first >= get(i+1) && can[i+1]);
            if(can[i]){
                ans.push_back(ns[i].second);
            } else break;
        }
        sort(ans.begin(), ans.end());
        printf("%d\n", ans.size());
        for(int to: ans){
            printf("%d ", to+1);

        }

        printf("\n");


    }
    return 0;
}
