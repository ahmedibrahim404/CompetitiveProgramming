#include<bits/stdc++.h>
using namespace std;
const int MAX=1000000+3;
int n, m, no, k;
vector<int> occ[MAX];

int main(){
    while(cin >> n >> m){
    for(int i=0;i<MAX;i++) occ[i].clear();
    for(int i=0;i<n;i++){
        cin >> no;
        occ[no].push_back(i);
    }
    while(m--){
        cin >>k >> no;
        if(k > occ[no].size()) cout << "0\n";
        else cout << occ[no][k-1]+1<<"\n";
    }
    }

    return 0;
}
