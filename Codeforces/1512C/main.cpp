#include<bits/stdc++.h>

using namespace std;

bool pal(string s){
    string ss=s;
    reverse(ss.begin(), ss.end());
    return s == ss;
}

int main(){
    int t;cin >> t;
    while(t--){
        int arr[2];
        cin >> arr[0] >> arr[1];
        string s;cin >> s;

        for(int i=0;i<s.length();i++){
            if(s[i] != '?' && s[ s.length()-i-1 ] == '?'){
                s[ s.length()-i-1 ] = s[i];
            }
        }

        for(int i=0;i<s.length();i++){
            if(s[i] != '?') arr[ s[i]-'0' ]--;
        }


        int st=0, en=s.length()-1;
        bool can = 1;
        while(en > st){
            if(s[st] == '?'){
                if(arr[0] >= 2) s[st] = s[en] = '0';
                else if(arr[1] >= 2)s[st] = s[en] = '1';
                arr[ s[st]-'0' ] -= 2;
            }
            st++, en--;
        }


        if(st == en) {
            if(s[st] == '?'){if(arr[0] >= 1) s[st] = '0';
            else s[st] = '1';arr[ s[st]-'0' ] --;}
        }

        if(arr[0] != 0 || arr[1] != 0 || !can || !pal(s)) cout << "-1\n";
        else cout << s << endl;

    }
    return 0;
}
