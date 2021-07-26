#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, int > pi;
int t, n;

int main(){
    cin >> t;
    while(t--){
        cin >> n;
        pi ns[n];
        for(int i=0;i<n;i++){
            cin >> ns[i].first;
            ns[i].second = i+1;
        }
        sort(ns, ns+n);int ans=0;
        for(int i=0;i<n;i++){

//            int st=i+1, en=n-1;int ans1=i;
//            while(en >= st){
//                int mid=(st+en)/2;
//                if(1LL * (ns[mid].second + ns[i].second) == ns[i].first * ns[mid].first) ans1=mid;
//                if( 1LL * (ns[mid].second + ns[i].second) > ns[i].first * ns[mid].first ){
//                    st=mid+1;
//                } else {
//                    en=mid-1;
//                }
//            }
//
//            int ans2=i;
//            st=i+1; en=n-1;
//            while(en >= st){
//                int mid=(st+en)/2;
//                if(1LL * (ns[mid].second + ns[i].second) == ns[i].first * ns[mid].first) ans2=mid;
//                if( 1LL * (ns[mid].second + ns[i].second) >= ns[i].first * ns[mid].first ){
//                    st=mid+1;
//                } else {
//                    en=mid-1;
//                }
//            }
//
//
//            if(ans2 > ans1)
//            ans += ans2-ans1+1;


        }

        printf("%d\n", ans);

    }
    return 0;
}
