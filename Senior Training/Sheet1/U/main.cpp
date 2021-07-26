#include<bits/stdc++.h>

using namespace std;

int l, n;

int main(){
    cin >> l >> n;
    string str, str2;
    map<string ,string> mp;
    for(int i=0;i<l;i++){
        cin >> str >> str2;
        mp[str]=str2;
    }

    for(int i=0;i<n;i++){
        cin >> str;
        if(mp.find(str) != mp.end()){
            cout << mp[str] << "\n";
            continue;
        }

        int len=str.length();

        if(len >= 2 && str[len-1] == 'y' && str[len-2] != 'a' && str[len-2] != 'e' && str[len-2] != 'i' && str[len-2] != 'o' && str[len-2] != 'u' ) str[len-1]='i', str += "es";
        else if((len >= 1 && ( str[len-1] == 'o' || str[len-1] == 's' || str[len-1]== 'x')) ||
                 (len >= 2 && str[len-1] == 'h' && ( (str[len-2]=='c' || str[len-2] == 's') )) ) str += "es";
        else str += "s";


        cout << str << "\n";
    }


    return 0;
}
