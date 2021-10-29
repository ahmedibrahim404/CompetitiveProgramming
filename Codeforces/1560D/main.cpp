#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;cin >> n;
        string s;s=to_string(n);

        int ans = 1e9;
        for(long long i=1;i<=2e18;i*=2){
            string s2=to_string(i);
            int i1=0, i2=0;
            int del=0;
            while(i1 < s.length() && i2 < s2.length()){
                if(s[i1] == s2[i2]){
                    i2++;
                } else del++;
                i1++;
            }

            int req = s2.length() - i2 + del;
            req += s.length() - i1;
            ans=min(ans, req);

        }

        cout << ans << endl;


    }

    return 0;
}
