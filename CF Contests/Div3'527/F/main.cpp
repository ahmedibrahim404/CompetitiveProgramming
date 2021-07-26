#include<bits/stdc++.h>
using namespace std;
string str;
int T, cnt[26];
char let(int n)
{
    assert(n >=0  && n < 26);
    return "abcdefghijklmnopqrstuvwxyz"[n];
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    cin >> T;
    while(T--){
        cin >> str;
        for(int i=0;i<26;i++)cnt[i]=0;
        int len=str.length();
        for(int i=0;i<len;i++){
            cnt[str[i]-'a']++;
        }
        int cc=0;
        for(int i=0;i<26;i++){
            if(cnt[i]) cc++;
        }
        if(cc ==1){
            cout <<"-1\n";
            continue;
        }
        for(int i=0;i<26;i++){
            char l=let(i);
            for(int j=0;j<cnt[i];j++) cout << l;
        }
        cout << endl;
    }
    return 0;
}
