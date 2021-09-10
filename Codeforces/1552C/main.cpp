#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
int t, n, k;;
int main(){

    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&k);vector<pair<int, int>> ans;

        set<int> st;
        for(int i=0;i<2*n;i++) st.insert(i);
        for(int i=0;i<k;i++){
            int a, b;
            scanf("%d%d",&a,&b);a--, b--;
            ans.push_back({min(a, b), max(a, b)});
            if(st.count(b)) st.erase(st.find(b));
            if(st.count(a)) st.erase(st.find(a));
        }


        auto it1 = st.begin(), it2=it1;
        for(int i=0;i<n-k;i++) it2++;

        for(int i=0;i<n-k;i++){
            ans.push_back({*it1, *it2});
            it1++, it2++;
        }

        int cnt=0;
        for(int i=0;i<ans.size();i++){
            int f=ans[i].first, s=ans[i].second;
            for(int j=0;j<ans.size();j++){
                if(i == j) continue;
                int f2=ans[j].first, s2=ans[j].second;
                if(f2 > f && f2 < s && s2 > s) cnt++;
            }
        }

        printf("%d\n", cnt);



    }

    return 0;
}
