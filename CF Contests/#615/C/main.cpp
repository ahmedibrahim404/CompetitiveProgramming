#include<bits/stdc++.h>
using namespace std;
int t;
int a, b, c;
typedef long long ll;
ll n;

int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%lld",&n);
        vector<ll> vi;
        for(ll i=2;i*i<n;i++){
            if(n%i) continue;
            vi.push_back(i);
            if(n/i!=i) vi.push_back(n/i);
        }
        int sz=vi.size();
        bool found=0;
        for(int i=0;i<sz;i++){
            for(int j=i+1;j<sz;j++){
                if(n%(vi[i]*vi[j]) || vi[i]*vi[j]==n) continue;
                ll third=n/(vi[i]*vi[j]);
                if(vi[i]==vi[j] || vi[i]==third || vi[j]==third) continue;
                found=1;
                printf("YES\n%lld %lld %lld\n", vi[i], vi[j], third);
                break;
            }
            if(found) break;
        }
        if(found) continue;
        printf("NO\n");
    }
    return 0;
}
