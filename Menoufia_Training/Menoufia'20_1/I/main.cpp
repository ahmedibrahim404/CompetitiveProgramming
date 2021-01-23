#include<bits/stdc++.h>
using namespace std;
const int MAX=1000+3;
int T, cnt[26];
string str;

int main(){
    cin >> T;
    while(T--){
        cin >> str;
        int n=str.length();
        for(int i=0;i<26;i++) cnt[i]=0;
        for(int i=0;i<n;i++) cnt[str[i]-'a']++;
        bool can=1;
        int iso=-1;
        char ch;
        for(int i=0;i<26;i++){
            if(cnt[i]&1){
                if(iso!=-1){iso=-1;can=0;break;}
                iso=i;
                ch=i+'a';
            }
        }
        if(!can) {cout << "impossible\n";continue;}
        string ans="";
        for(int i=0;i<26;i++){
            int tobe=cnt[i]/2;
            for(int j=0;j<tobe;j++) ans += i+'a';
        }
        cout << ans;
        reverse(ans.begin(), ans.end());
        if(iso!=-1) cout << ch;
        cout << ans << "\n";
    }

return 0;
}
