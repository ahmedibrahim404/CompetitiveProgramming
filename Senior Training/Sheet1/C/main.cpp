#include<bits/stdc++.h>
using namespace std;

int n;
string str;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    cin >> n;
    map<string, string> par;
    set<string> st;
    while(n--){
        string a, b;
        cin >> a >> b;
        if(par.find(a) != par.end()){
            par[b]=par[a];
            par.erase(par.find(a));
        } else {
            par[b]=a;
        }
    }

    cout << par.size() << "\n";
    while(par.size()){
        auto it=par.begin();
        cout << it->second << " " << it->first << "\n";
        par.erase(it);
    }




    return 0;
}
