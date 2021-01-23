#include<bits/stdc++.h>
using namespace std;
typedef pair<long long, string> pi;
int T, n, m;
pi s[100+9];

bool cmpr(pi p2, pi p1){
    if(p2.first == p1.first) return p2.second < p1.second;
    return p2.first > p1.first;
}

int main(){
    cin >> T;
    while(T--){
        cin >> n >> m;
        for(int i=0;i<n;i++){
            cin >> s[i].second >> s[i].first;
            s[i].first *= -1;
        }
        sort(s, s+n);
        long long ans=0;
        string ansS="";
        for(int i=0;i<m;i++){
            ans += (m-i)*-s[i].first;
            ansS += s[i].second;
            if(i != m-1) ansS += " ";
        }
        cout << ans << " " << ansS;
        cout << "\n";
    }
    return 0;
}
