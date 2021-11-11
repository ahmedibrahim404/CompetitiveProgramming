#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;cin >> n;
    vector<int> v;
    v.push_back(1);
    for(int i=2;i*i<=n;i++){
        if(n%i) continue;
        if(i == n/i) {if(n%(2*i) == 0) v.push_back(i);}
        else{
            if(n%(2*i) == 0) v.push_back(i);
            if(n%(2*(n/i)) == 0) v.push_back(n/i);
        }
    }
    sort(v.begin(), v.end());
    cout << v.size() << endl;
    for(const auto &e: v) cout << e << " ";
    cout << "\n";
    return 0;
}
