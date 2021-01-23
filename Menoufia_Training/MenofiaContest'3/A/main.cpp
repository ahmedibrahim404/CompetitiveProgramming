#include<bits/stdc++.h>

using namespace std;

string s1, s2;
int main(){
    cin >> s1 >> s2;
    int l2=s2.length()-1, l1=s1.length();
    if(l2 >= l1){
        cout << 0 << ".";
        for(int i=0;i<l2-l1;i++){
            cout << 0;
        }
        cout << s1 << endl;
    } else {
        reverse(s1.begin(), s1.end());
        string ans = "";
        bool ad=0;
        for(int i=0;i<l1;i++){
            ans += s1[i];
            if(i == l2-1){
                ans += ".";
                ad=1;
            }
        }
        reverse(ans.begin(), ans.end());
        if(!ad)ans += ".";
        int l3=ans.length(), stop=l3-1;
        for(int i=l3-1;i>=0;i--){
            if(ans[i]=='0') continue;
            stop=i;
            if(ans[i]=='.'){
                if(i==stop) stop--;
                break;
            }
            break;
        }
        for(int i=0;i<=stop;i++) cout << ans[i];
    }
    return 0;
}
