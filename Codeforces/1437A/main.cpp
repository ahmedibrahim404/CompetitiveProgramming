#include <iostream>

using namespace std;

string str;
int t, n;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    while(t--){
        cin >> n >> str;
        int cur=1, ans=0;
        for(int i=1;i<n;i++){
            if(str[i]=='1'&&str[i]==str[i-1]) cur++;
            else ans +=cur-1, cur=1;
        }
        ans += cur-1;
        int ans2=0;
        cur=1;
        for(int i=1;i<n;i++){
            if(str[i]=='0'&&str[i]==str[i-1]) cur++;
            else ans2 +=cur-1, cur=1;
        }
        ans=max(ans, ans2);
        cout << ans << "\n";
    }
    return 0;
}
