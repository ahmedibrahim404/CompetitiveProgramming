#include<bits/stdc++.h>
using namespace std;
int T;
string s;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    cin >> T;
    while(T--){
        cin >> s;
        int len=s.length();
        stack<char> st;
        int i=0;
        for(;i<len;){
//            cout << i << endl;
            if(st.size() && s[i]==st.top()){
                st.pop();
            } else st.push(s[i]);
            i++;
        }
        vector<char> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        for(int i=0;i<ans.size();i++) cout << ans[i];

        if(ans.size()==0) cout << "EMPTY";
        cout << endl;

    }
    return 0;
}
