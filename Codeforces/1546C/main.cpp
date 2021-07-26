#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e5;

int calcO(int a, int b){
    int ans=(b-a+1)/2;
    if((a&1) && (b-a+1)%2) ans++;
    return ans;
}


int main(){
    int t, n;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        set<int> ns[N+1];
        set<int> st;
        int occ[N];memset(occ, 0, sizeof occ);
        for(int i=0;i<n;i++){
            int no;
            scanf("%d",&no);
            ns[no-1].insert(i);
            st.insert(no-1);
            occ[no-1]++;
        }
        bool can=1;
        int idx=0;
        for(auto itt=st.begin();itt!=st.end();itt++){
            int val=*itt;

            // [ idx, idx+occ[val] ]
            int odd = calcO(idx, idx+occ[val]-1);
            int even = occ[val] - odd;

            auto it=ns[val].begin();
            for(;it != ns[val].end();it++){
                if((*it)&1) odd--;
                else even--;
            }

            idx += occ[val];

            if(odd || even){
                can=0;
                break;
            }

        }

        if(can)printf("YES\n");
        else printf("NO\n");

    }
    return 0;
}
