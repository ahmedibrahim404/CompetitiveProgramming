#include<bits/stdc++.h>
using namespace std;
int n, m;
string ns[1000+3];

bool cpr(string s2, string s1){
    if(s2.length() != s1.length()) return s2.length() < s1.length();
    return s2<s1;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    cin >> n >> m;
    int tot=0;
    for(int i=0;i<m;i++){
        cin >> ns[i];
        tot += ns[i].length();
    }
    sort(ns, ns+m, cpr);
    int cnt=0;
    for(int i=0;i<m;i++){
        if(i && ns[i] == ns[i-1]){
            continue;
        }
        int len=ns[i].length();
        if(len <= n) n-= len+1, cnt++;
        else break;
    }
    n++;
    if(n<0) cnt--;
    cout << cnt << endl;
    return 0;
}
