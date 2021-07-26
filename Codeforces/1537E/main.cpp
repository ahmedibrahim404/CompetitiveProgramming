#include<bits/stdc++.h>

using namespace std;

int n, k;
string s;
int main(){
    cin >> n >> k >> s;


    int len=1;
    for(int i=1;i<n;i++){
        if( s[i%len] < s[i] ){
            break;
        } else if(s[i%len] > s[i]) {
            len=i+1;
        }
    }

    string ans = s.substr(0, len);
    while(ans.length() < k) ans += ans;
    while(ans.length() > k) ans.pop_back();


    cout << ans;

    return 0;
}
