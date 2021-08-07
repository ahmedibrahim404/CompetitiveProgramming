#include<bits/stdc++.h>
using namespace std;

int t;

int main(){
    cin >> t;
    while(t--){
        string a, b;
        cin >> a >> b;bool found=0;
        int n=a.length(), m=b.length();

        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(a[i] != b[0]) continue;
                string cur=a.substr(i, j-i+1);
                string tb = b.substr(0, min(b.length(), cur.length() ));
                if(cur != tb) continue;
                int idx=cur.length();
                string rem=b.substr(idx);
                reverse(rem.begin(), rem.end());
                string cpr="";
                for(int k=j-rem.length(); k<j;k++) cpr += a[k];
                if(rem == cpr){
                    cout << "YES\n";
                    found=1;
                    break;
                }

            }if(found) break;
        }

        if(!found) cout << "NO\n";


    }
    return 0;
}
