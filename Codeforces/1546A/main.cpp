#include<bits/stdc++.h>

using namespace std;
typedef pair<int, int> pi;

int main(){
    int t, n;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n); int ns[n], ms[n];
        int t1=0, t2=0;
        for(int i=0;i<n;i++){
            scanf("%d",&ns[i]);t1 += ns[i];
        }
        for(int i=0;i<n;i++){
            scanf("%d",&ms[i]);t2 += ms[i];
        }

        if(t1 != t2){
            printf("-1\n");
            continue;
        }

        vector<pi> ans;

        for(int i=0;i<n;i++){
            if(ns[i] == ms[i]) continue;
            for(int j=i+1;j<n;j++){
                while(ns[i] > ms[i] && ns[j] < ms[j]) ns[i]--, ns[j]++, ans.push_back({i+1, j+1});
                while(ns[i] < ms[i] && ns[j] > ms[j]) ns[i]++, ns[j]--, ans.push_back({j+1, i+1});
                if(ns[i] == ms[i]) break;
            }
        }


        printf("%d\n", ans.size());
        for(int i=0;i<ans.size();i++){
            printf("%d %d\n", ans[i].first, ans[i].second);
        }

    }
    return 0;
}
