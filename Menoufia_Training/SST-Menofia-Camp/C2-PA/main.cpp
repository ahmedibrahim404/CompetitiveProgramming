#include<bits/stdc++.h>
using namespace std;
struct triple {
    int f, s, t;
};
const int MAX=5e3+5;
triple ns[MAX];

int main(){

    int mh=0, mx=0, i=0;
    vector<int> ans;
    string str;
    while(true){
        getline(cin, str);
        stringstream ss(str);
        ss >> ns[i].f >> ns[i].t >> ns[i].s;
        if(!ns[i].f && !ns[i].t && !ns[i].s) break;
        if(ns[i].f >= mx && i != 0){
            if(ns[i].f > mx) {ans.push_back(mx);ans.push_back(0);}
            mx=ns[i].s;
            mh=0;
        }
        if(ns[i].t > mh){
            mh=ns[i].t;
            if(ns[i].s > mx)mx=ns[i].s;
            ans.push_back(ns[i].f);
            ans.push_back(ns[i].t);
        }

        i++;

    }

    for(int i=0;i<ans.size();i++) cout << ans[i] << endl;

    return 0;
}
