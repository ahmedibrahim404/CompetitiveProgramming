#include <iostream>

using namespace std;

int t, n;

int main(){
    freopen("collectingofficer.in", "r", stdin);
    cin >> t;
    while(t--){
    string s;
        cin >> n >> s;
        int ans=1e9;
        for(int i=0;i<n;i++){
            int cur=0;
            for(int j=i;j<n;j++){
                if(cur == s[j]-'A') cur++;
                if(cur==26){
                    ans=min(ans, j-i+1);
                    break;
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
