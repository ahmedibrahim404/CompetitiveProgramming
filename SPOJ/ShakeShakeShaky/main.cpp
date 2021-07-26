#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int t;
int n;
int k;
vector<int> ns, ts;

int main(){

    cin >> t;

    while(t--){

        cin >> n >> k;
        ns = vector<int>(n);

        for(int i=0;i<n;i++) cin >> ns[i];

        sort(ns.begin(), ns.end());

        int start=1, end=ns[n-1]+1, mid;
        int mx=0;
        while(end >= start){


            ts = ns;

            mid = (start+end)/2;
            int totake = k;
            int from=n-1;


            while(true && from >=0){
                totake -= (ts[from]/mid);
                if(totake <= 0) break;
                from--;
            }


            if(totake <= 0)
                mx = max(mx, mid), start=mid+1;
            else
                end = mid-1;

        }


        cout << mx << endl;


    }

    return 0;
}
