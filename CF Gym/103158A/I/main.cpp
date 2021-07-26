#include<bits/stdc++.h>
using namespace std;

const int N = 2000 + 3;



int n, x;
string s;

int cnt[N], sz[N];
//unordered_map< bitset<N> , bool> mp;


int main(){
	freopen("binary.in", "r", stdin);


    cin >> n >> x >> s;

    // 010010


    for(int k=1;k<=n;k++){

        for(int i=0;i<k;i++) cnt[i]=0, sz[i]=0;
        for(int i=0;i<n;i++){
            if(s[i] == '1')cnt[i%k]++;
            sz[i%k]++;
        }

        bitset<N> dp;
        dp[0] = 1;
        for (int i = 0; i < n; i++) {
            dp |= (dp << (cnt[i]));
            if(sz[i] - 2*cnt[i] > 0) dp |= (dp << (sz[i]-2*cnt[i]));
            else dp |= (dp >> (2*cnt[i]-sz[i]));
        }

        if(dp[x]){
            printf("%d\n", k);
            return 0;
        }

    }

    return 0;
}
