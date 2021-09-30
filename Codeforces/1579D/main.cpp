#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;scanf("%d",&n);
        pair<int, int> ns[n];
        int tot =0 ;
        for(int i=0;i<n;i++) {
            scanf("%d",&ns[i].first);
            ns[i].second = i;
            tot += ns[i].first;
        }
        sort(ns, ns+n);
        int st=0, en=n-1;
        vector<pair<int, int>> ans;
        while(en > st){
            int mn = min(ns[st].first, ns[en].first);
            ns[st].first -= mn;
            ns[en].first -= mn;
            while(mn--) ans.push_back({ns[st].second, ns[en].second});
            if(!ns[st].first) st++;
            else en--;
        }

        if(st == en){
            for(int i=0;i<ans.size();i++){
                if(ans[i].first == ns[st].second || ans[i].second == ns[st].second) continue;
                int fir = ans[i].first, sec = ans[i].second;
                if(ns[st].first < 2) break;
                ns[st].first -= 2;
                ans[i].second = ns[st].second;
                ans.push_back({sec, ns[st].second});
            }


        }

        printf("%d\n", ans.size());
        for(int i=0;i<ans.size();i++){
            printf("%d %d\n", ans[i].first+1, ans[i].second+1);
        }

    }
    return 0;
}
