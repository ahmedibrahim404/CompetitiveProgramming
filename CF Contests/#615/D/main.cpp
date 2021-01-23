#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int q, x;
set<ll> st;
int main(){
    scanf("%d%d",&q,&x);
    ll mex=0;
    ll no;
    ll maxi=-1;
    ll cnt=0;
    map<ll, ll> mp;
    for(int i=0;i<q;i++){
        scanf("%lld",&no);
        ll p=no-( (no/x) *x), put=-1;
        ll sta=0, en=q+1, take=-1;
        if(mp[p]) sta=mp[p];
        while(en > sta){

            ll mid=(sta+en)>>1;
            if( st.find(p+mid*x) == st.end() ){
                take=mid;
                en=mid;
            } else {
                sta=mid+1;
            }

        }

        if(take==-1) continue;

        ll in=p+take*x;
        mp[p]=take+1;
        st.insert(in);

            if(in > maxi){
                cnt += max(in-maxi-1, 0LL);
                maxi=in;
            } else {
                cnt --;
            }

        auto fir=st.lower_bound(in);
        auto sec=st.lower_bound(maxi);

        int dist = distance(fir, sec);
        if((maxi-in-1)-(dist-1)>=cnt){
            ll a=in, b=maxi;
            pre=in;
            ll c;
            while(b>a){
                c=(a+b)>>1;
//                if(st.find(c) != st.end())
            }
            mex=pre+1;

        }
        if(!cnt) mex=st.size();
        cout << mex << endl;

    }
    return 0;
}
