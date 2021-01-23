#include<bits/stdc++.h>

using namespace std;
const int MAX=5000+1;
int n,m;
bool vis[MAX];
map<string, int> mp;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    cin >> n >> m;
    int mx=0;
    string ans="";
    string strs;
    for(int i=0;i<n;i++){
        cin >> strs;
        if(mp.find( strs )==mp.end()) mp[ strs ]=1;
        else mp[ strs ]++;
    }

    for(auto elem: mp){
        string s=elem.first;
        int cnt=elem.second;
        int ctr=0;
        for(int i=0;i<m;i++){
            if(s[i]=='1') ctr++;
        }
        if(ctr>=8&&ctr<=15&&cnt>mx){
            mx=cnt;
            ans=s;
        }
    }

    if(ans==""){
        for(int i=0;i<m;i++){
            if(i<8) ans += "1";
            else ans +="0";
        }
    }

    cout << ans;

    return 0;
}
