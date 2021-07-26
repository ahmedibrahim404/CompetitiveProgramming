#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        map<int, int> mp;
        for(int i=0;i<n;i++){int no;
            scanf("%d",&no);
            mp[no-i]++;
        }


        ll ans=0;
        for(auto it=mp.begin();it != mp.end();it++){
            ans += 1LL * (it->second)*(it->second-1)/2;
        }

        printf("%lld\n", ans);

    }
    return 0;
}
