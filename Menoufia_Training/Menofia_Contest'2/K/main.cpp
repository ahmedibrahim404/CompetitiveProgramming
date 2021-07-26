#include <stdio.h>
#include<set>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pi;
int n;
set<ll> st;
set<pi> st2;
ll ans=-1;

void check(ll a){
        for(int i=1;i*i<=a;i++){
            if((a%i)==0){
                if(i*i==a){
                    st.insert(i);
                } else {
                    if(i != 1) st.insert(i);
                    st.insert(a/i);
                }
            }
        }
}

void get(ll a, ll b){
    for(auto it=st.begin();it!=st.end();){
        ll num=*it;
        if(a%num!=0 && b%num !=0){
            st.erase(it++);
            if(it==st.end()) break;
        } else it++;
    }
}

ll a, b;

int main(){
    scanf("%d %d %d",&n,&a,&b);
    check(a);check(b);
    for(int i=0;i<n-1;i++){
        scanf("%d %d",&a,&b);
        if(st2.find(pi(a, b)) != st2.end()) continue;
        get(a, b);
        st2.insert(pi(a, b));
    }
    if(st.size() > 0) ans=*st.begin();
    printf("%lld\n", ans);
    return 0;
}
