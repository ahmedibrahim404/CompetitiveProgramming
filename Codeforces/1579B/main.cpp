#include<bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin >> t;
    while(t--){

        int n;
        cin >> n;
        vector<int> ns = vector<int>(n);
        for(int i=0;i<n;i++){
            cin >> ns[i];
        }

        int k = n;
        vector<int> v1, v2;
        while(k){

            int mx=0;
            for(int i=0;i<k;i++){
                if(ns[i] > ns[mx]) mx=i;
            }

            if(mx+1 != k){
                v1.push_back(mx+1);
                v2.push_back(k);
                ns.erase(ns.begin()+mx);
            }

            k--;


        }

        cout << v1.size() << endl;
        for(int i=0;i<v1.size();i++){
            cout << v1[i] << " " << v2[i] << " 1\n";
        }

    }

    return 0;
}
