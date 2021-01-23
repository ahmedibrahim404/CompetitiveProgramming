#include<bits/stdc++.h>
using namespace std;
int t, n;
int prime[1000+3];
void prim(){

    memset(prime, -1, sizeof prime);

    for(int i=2;i<=1000;i++){
        if(prime[i] != -1) continue;
        for(int j=i*i;j<=1000;j+=i){
            prime[j]=i;
        }
        prime[i]=i;
    }


}

int main(){
    cin >> t;
    prim();
    while(t--){
        cin >> n;
        int ns[n];
        for(int i=0;i<n;i++){
            cin >> ns[i];
            ns[i] = prime[ ns[i] ];
        }

        map<int, int> mp;
        int k=1;
        for(int i=0;i<n;i++){
            if(mp.find( ns[i] )==mp.end()) mp[ ns[i] ]=k++;
        }

        cout << mp.size() << "\n";
        for(int i=0;i<n;i++) cout << mp[ns[i]] << " ";
        cout << "\n";
    }
    return 0;
}
