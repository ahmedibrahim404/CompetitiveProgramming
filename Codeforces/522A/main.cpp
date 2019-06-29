#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

int n;
string s1, s2, ss;
vector< vector<int> > ns;
map<string, int> mp;

int mx=0;

void BFS(){

    queue<ii> q;
    q.push(ii(1, 1));

    while(!q.empty()){

        ii no=q.front();q.pop();
        int i=no.first, u=no.second;
        mx=max(u, mx);
        for(int j=0;j<ns[i].size();j++){
            q.push(ii(ns[i][j], u+1));
        }

    }

}

int main(){

    cin >> n;
    ns=vector<vector<int>>(209);
    mp.insert(make_pair("polycarp", 1));
    int idx=2;
    for(int i=0;i<n;i++){
        cin >> s1 >> s2 >> s2;
        transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
        transform(s2.begin(), s2.end(), s2.begin(), ::tolower);
        if(!mp.count(s1)) mp.insert(make_pair(s1, idx++));
        if(!mp.count(s2)) mp.insert(make_pair(s2, idx++));
        ns[mp[s2]].push_back(mp[s1]);
    }

    BFS();

    cout << mx <<endl;

    return 0;
}
