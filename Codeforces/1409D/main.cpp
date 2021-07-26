#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int t;ll n;int s;

ll poww(int no){

    ll ans =1;
    while(no--){
        ans *= 10;
    }

    return ans;

}

int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%lld%d",&n,&s);
        vector<int> vi;
        int sum=0;
        ll pren=n;
        while(n){
            vi.push_back(n%10);
            sum += n%10;
            n/=10;
        }

        if(sum <= s){
            cout << 0 << "\n";
            continue;
        }

        vi.push_back(0);

        sum -= vi[0];
        ll ans=2e18;
        for(int i=1;i<vi.size();i++){
            if(sum + 1 <= s){
                ll p=poww(i);
                ans=min(ans, p-pren%p);
            }
            sum -= vi[i];
        }

        cout << ans << "\n";


    }
    return 0;
}
