#include<bits/stdc++.h>
using namespace std;

int n, m;
int t;
string str;
int main(){
    cin >> t;
    while(t--){
        cin >> n >> m;
        cin >> str;
        int ms[m];
        for(int i=0;i<m;i++){
            cin >> ms[i];
            ms[i]--;
        }
        sort(ms, ms+m);
        int ns[26];
        for(int i=0;i<26;i++) ns[i]=0;
        for(int i=0;i<n;i++){
            int cur=str[i]-'a';
            int idx=lower_bound(ms, ms+m, i)-ms;
            ns[cur] += (m-idx)+1;
        }
        for(int i=0;i<26;i++) cout << ns[i] << " ";
        cout << "\n";
    }
    return 0;
}
