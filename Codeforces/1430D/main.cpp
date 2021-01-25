#include<bits/stdc++.h>

using namespace std;
int t, n;
string s;
int main(){
    cin >> t;
    while(t--){
        cin >> n >> s;
        int len=1;
        queue<int> q;
        for(int i=1;i<n;i++){
            if(s[i]==s[i-1]){
                len++;
                continue;
            }
            q.push(len);
            len=1;
        }

        q.push(len);

        int cur=0, idx=0, ans=0;
        int tot=q.size();
        while(!q.empty()){
            int no=q.front();q.pop();
            int can=min(idx-cur+1, no-1);
            ans += can;
            cur += can;
            idx++;
        }

        ans += (tot-cur+1)/2;

        cout << ans << "\n";

    }
    return 0;
}
