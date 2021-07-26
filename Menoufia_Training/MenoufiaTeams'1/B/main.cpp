#include<bits/stdc++.h>
using namespace std;

int t;
string a, b;

int main(){
    cin >> t;
    while(t--){
        cin >> a >> b;
        if(a.length() != b.length()){
            cout << "No\n";
            continue;
        }
        int len=a.length();
        bool is=1;
        for(int i=0;i<len;i++){
            a[i]=(tolower(a[i]));
            b[i]=(tolower(b[i]));
            if(a[i]==b[i]) continue;
            if(a[i]=='i' && b[i]=='e') continue;
            if(a[i]=='b' && b[i]=='p') continue;
            if(b[i]=='i' && a[i]=='e') continue;
            if(b[i]=='b' && a[i]=='p') continue;
            is=0;
        }
        if(!is) cout << "No\n";
        else cout << "Yes\n";
    }
    return 0;
}
