#include <iostream>

using namespace std;

string s;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> s;
    int len=s.length();
    bool f=0;
    for(int i=0;i<len-26+1;i++){

        int cur[26], h=0, q=0;
        for(int i=0;i<26;i++) cur[i]=0;
        bool can=1;
        for(int j=i;j<i+26;j++){
            if(s[j] == '?'){
                q++;
                continue;
            }
            int ch=tolower(s[j])-'a';
            cur[ch]++;
            if(cur[ch] == 1) h++;
            else if(cur[ch]==2){
                can=0;
                break;
            }
        }


        if(!can) continue;
        if((26-h)==q){
            for(int j=i;j<i+26;j++){
                if(s[j] == '?'){
                    for(int k=0;k<26;k++){
                        if(cur[k]==0){
                            s[j]=toupper(k+'a');
                            cur[k]=1;
                            break;
                        }
                    }
                }
            }
            for(int i=0;i<len;i++) if(s[i]=='?') s[i]='A';
            f=1;
            break;
        }
    }
    if(!f) cout << -1 << endl;
    else cout << s << endl;
    return 0;
}
