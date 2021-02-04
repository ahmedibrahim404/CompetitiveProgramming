#include<bits/stdc++.h>
using namespace std;
const int MAX=1000+3;
int n, s;
map<int, int> a, b;
int main(){
    cin >> n >> s;
    int as=0, bs=0;
    vector<pair<int, int>> ass, bss;
    for(int i=0;i<n;i++){
        char ch;int v, u;
        cin >> ch >> v >> u;
        if(ch=='B') if(a[v]) a[v] += u; else a[v] = u, as++;
        else if(ch == 'S') if(b[v]) b[v] += u; else b[v] = u, bs++;
    }

    for (auto it = a.begin(); it != a.end(); it++){
        ass.push_back({ it->first, it->second });
    }
    for (auto it = b.begin(); it != b.end(); it++){
        bss.push_back({ it->first, it->second });
    }


    sort(ass.rbegin(), ass.rend());
    sort(bss.rbegin(), bss.rend());
    int st = max(0,(int)bss.size() - s);
    for (int i = st; i < (int)bss.size(); i++){
        cout << "S " << bss[i].first << " " << bss[i].second << endl;
    }
    for (int i = 0; i < min(s, (int)ass.size()); i++){
        cout << "B " << ass[i].first << " " << ass[i].second << endl;
    }


    return 0;
}
