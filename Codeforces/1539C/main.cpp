#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX= 2e5 + 3;
int n;ll k, x;
ll ns[MAX];


int main(){
    scanf("%d%lld%lld", &n,&k,&x);
    set<ll> st;
    for(int i=0;i<n;i++ ){
        ll no;
        scanf("%lld",&no);
        st.insert(no);
    }

    int i=0;
    for(auto it=st.begin();it != st.end();it++){
        ns[i++] = (*it);
    }


    n=st.size();

    sort(ns+1, ns+i);

    vector<ll> vi;

    for(int i=1;i<n;i++){
        vi.push_back(ns[i]-ns[i-1]);
    }

    sort(vi.begin(), vi.end());

    int g=0;
    for(int i=0;i<vi.size();i++){
        if(vi[i] <= x){
            continue;
        }

        if(k >= (vi[i]-1)/x ) k-= (vi[i]-1)/x;
        else g++;
    }
    g++;

    printf("%d\n", g);


    return 0;
}
