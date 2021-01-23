#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll a, b, k;
int main(){
    scanf("%d%lld%lld%lld",&n,&a,&b,&k);
    ll sum=a+b, no, ks;
    int pts=0, idx=0;
    int vs[n];
    for(int i=0;i<n;i++){
        scanf("%lld",&no);
        if(no<=a) {pts++;continue;}
        else if(no-a<=b){
            ll re=no-a;
            if(k) {
                ks=(re)/a+((re%a)?1:0);
                if(ks>1){
                    vs[idx++]=ks;
                    continue;
                }
//                cout << 1 << " " << i << endl;
                k--, pts++;
            }
            continue;
        }

        ll rem=no%sum;
        if(rem&&rem<=a) {
            pts++;
//            cout<<2<<" " <<i<<endl;
        } else {
            if(k) {
                if(!rem) ks=sum/a+(sum%a?1:0)-1;
                else ks = rem/a+((rem%a)?1:0)-1;
                if(ks>1){
                    vs[idx++]=ks;
                    continue;
                }
                pts++, k--;
//                cout<<3<<" " <<i<<" " << ks << endl;
            }
        }

    }

    sort(vs, vs+idx);
    int i=0;
    while(k&&i<idx){
        if(vs[i]<=k){k-=vs[i], pts++;}
        i++;
    }

    cout << pts << endl;
    return 0;
}
