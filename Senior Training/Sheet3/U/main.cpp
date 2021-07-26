#include<bits/stdc++.h>
using namespace std;

int t;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    cin.ignore();
    while(t--){
        vector<int> vi;
        string line;int num;
        getline(cin, line);
        istringstream iss(line);
        while(iss >> num){
            vi.push_back(num);
        }
        int sz=vi.size();int mx=1;
        for(int i=0;i<sz;i++){
            for(int j=i+1;j<sz;j++){
                mx=max( __gcd(vi[i], vi[j]), mx);
            }
        }
        cout << mx << "\n";
    }
    return 0;
}
