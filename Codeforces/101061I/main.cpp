#include <iostream>

using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
long long binpow(long long a, long long b) {
    a %= MOD;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

int t, n;
int main(){
    cin >> t;
    while(t--){
        int ns[26]={0}, ns2[26]={0};
        string s, s2;
        cin >> s >> s2;

        for(int i=0;i<s.length();i++){
            ns[s[i]-'a']++;
        }
        for(int i=0;i<s2.length();i++){
            ns2[s2[i]-'a']++;
        }

        int ans=0;
        for(int i=0;i<26;i++){
            ans += abs(ns[i]-ns2[i]);
        }

        printf("%d\n", ans);

    }
    return 0;
}
