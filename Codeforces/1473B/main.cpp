#include<bits/stdc++.h>

using namespace std;

int q;

int lcm(int a, int b){
    return (a / __gcd(a, b)) * b;
}

int main(){
    cin >> q;
    while(q--){
        string s, t;
        cin >> s >> t;
        if(s.length() < t.length()) swap(s, t);
        int n=s.length(), m=t.length();

        bool check=1;
        char ch=s[0];
        for(int i=0;i<n;i++){
            if(s[i] != ch) check=0;
        }

        for(int i=0;i<m;i++){
            if(t[i] != ch) check=0;
        }

        if(check){
            int no =lcm(n, m);
            for(int i=0;i<no;i++) cout << ch;
            cout << "\n";
            continue;
        }

        int idx=0;
        bool can=1;
        for(int i=0;i<n;i++){
            idx %= m;
            if(s[i] != t[idx]){
                can=0;
                break;
            }
            idx++;
        }
        idx %= m;
        if(!can){
            cout << "-1\n";
            continue;
        }

        int len=lcm(s.length(), t.length());
        string ans="";
        int i=0;
        while(len--){
            ans += s[i];
            i++;
            i%=n;
        }

        int k=ans.length(), ii=0;
        can=1;
        for(int i=0;i<k;i++){
            if(ans[i] != s[ii]) can=0;
            ii++;
            ii%=n;
        }
        if(ii!=0) can=0;
        ii=0;
        for(int i=0;i<k;i++){
            if(ans[i] != t[ii]) can=0;
            ii++;
            ii%=m;
        }

        if(ii!=0) can=0;
        if(!can){
            cout << "-1\n";
            continue;
        }
        cout << ans << "\n";

    }
    return 0;
}
