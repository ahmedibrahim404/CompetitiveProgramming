#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int t, n;
vector<ll> as, bs;


int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        as.clear();bs.clear();
        for(int i=0;i<n;i++){ll no;
            scanf("%lld",&no);
            as.push_back(no);
        }

        sort(as.begin(), as.end(), greater<ll>());
        ll cur=0;
        for(int i=0;i<as.size();i++){

            if(i%2 == 0){
                if(as[i] % 2 == 0) cur += as[i];
            } else {
                if(as[i] % 2) cur -= as[i];
            }

        }


        if(cur > 0 ) cout << "Alice\n";
        else if(cur==0) cout << "Tie\n";
        else cout << "Bob\n";

    }


    return 0;
}
