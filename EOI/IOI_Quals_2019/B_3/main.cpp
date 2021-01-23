#include <iostream>

using namespace std;

int T;
string s;
int ns[26][26];

int getmin(char a, char b){

    if(a==b) return 0;
    int i1=a-'a', i2=b-'a';

    int mincost=min(ns[i1][i2], ns[i2][i1]);
    for(int i=0;i<26;i++){
        mincost=min(mincost, ns[i1][i] + ns[i2][i]);
    }

    return mincost;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    cin >> T;

    while(T--){

        cin >> s;
        for(int i=0;i<26;i++) for(int j=0;j<26;j++) cin >> ns[i][j];
        int len=s.length();
        string s1="", s2="";
        for(int i=0;i<len;i++) if(i&1) s2 += s[i]; else s1 += s[i];

        int l1=s1.length(), l2=s2.length();
        len=max(l1, l2);
        long long o=0, e=0;
        for(int i=0;i<len/2;i++){
            if(l1-1 >= i) {
                o+=getmin(s1[i], s1[l1-i-1]);
            }
            if(l2-1 >= i){
                e+=getmin(s2[i], s2[l2-i-1]);
            }
        }

        cout << min(o, e) << endl;

    }

    return 0;
}
