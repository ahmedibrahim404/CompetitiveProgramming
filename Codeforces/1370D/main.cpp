#include <iostream>

using namespace std;
int n, k;
int main(){
    cin >> n >> k;
    int ns[n], mi=2e9, mx=0;
    for(int i=0;i<n;i++){
        cin >> ns[i];
        mi=min(mi, ns[i]);
        mx=max(mx, ns[i]);
    }

    int st=mi, en=mx;
    int ans=mx;
    while(en >= st){

        int mid=(st+en)/2;
        int idx=0, cnt=(k+1)/2;
        while(idx < n-(k%2==0) && cnt){
            if(ns[idx] <= mid) cnt--, idx++;
            idx++;
        }

        if(cnt == 0){
            en=mid-1;
            ans=min(ans, mid);
        } else {
            st=mid+1;
        }
    }

    st=mi, en=mx;
    while(en >= st){

        int mid=(st+en)/2;
        int idx=1, cnt=k/2;
        while(idx < n-(k%2==1) && cnt){
            if(ns[idx] <= mid) cnt--, idx++;
            idx++;
        }

        if(cnt == 0){
            en=mid-1;
            ans=min(ans, mid);
        } else {
            st=mid+1;
        }
    }

    cout << ans << "\n";

    return 0;
}
