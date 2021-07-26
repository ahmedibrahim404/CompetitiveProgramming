#include<bits/stdc++.h>
using namespace std;
int t, n;
int main(){
    cin >> t;
    while(t--){
        cin >> n;
        int ns[n];
        for(int i=0;i<n;i++) cin >> ns[i];
        sort(ns, ns+n);
        int diff=2e9;int id;
        for(int i=n-2;i>=0;i--){
            if(diff > abs(ns[i] - ns[i+1])){
                diff = abs(ns[i] - ns[i+1]);
                id=i;
            }
        }

        int nw[n-2], idx=0;
        for(int i=0;i<n;i++){
            if(i==id || i==id+1) continue;
            nw[idx++] = ns[i];
        }


        printf("%d ", ns[id]);
        int nidx = lower_bound(nw, nw+idx, ns[id])-nw;
        for(int i=nidx;i<idx;i++) printf("%d ", nw[i]);
        int nidx2 = upper_bound(nw, nw+idx, ns[id+1])-nw;
        for(int i=0;i<nidx2;i++){
            if(i >= nidx && i < idx) continue;
            printf("%d ", nw[i]);
        }
        for(int i=0;i<idx;i++){
            if(i >= nidx && i < idx) continue;
            if(i >= 0 && i < nidx2) continue;
            printf("%d ", nw[i]);
        }
        printf("%d\n", ns[id+1]);


    }
    return 0;
}
