#include<bits/stdc++.h>

using namespace std;
int t, n, k;
string str;
int main(){
    cin >> t;
    while(t--){
        cin >> n >> k;
        cin >> str;
        int ns[k][26];
        memset(ns, 0, sizeof ns);
        for(int i=0;i<n;i++){
            int ch=str[i]-'a';
            ns[i%k][ch]++;
        }


        int tot=0;
        for(int i=0;i<(k+1)/2;i++){

            // i, k-i-1
            int mx=0, no;
            for(int j=0;j<26;j++){
                if(i != k-i-1)
                mx=max(mx, ns[i][j]+ns[k-i-1][j]);
                else
                mx=max(mx, ns[i][j]);
            }

            if(i != k-i-1){
                no=2*(n/k);
            } else {
                no=(n/k);
            }

            tot += (no-mx);
        }

        cout << tot << "\n";

    }
    return 0;
}
