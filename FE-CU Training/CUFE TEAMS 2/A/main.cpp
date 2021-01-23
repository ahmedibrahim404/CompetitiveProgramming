#include<bits/stdc++.h>
using namespace std;
int t, n, q;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&q);
        map<int, int>mp;
        set<int> st;
        int ns[n];
        for(int i=0;i<n;i++){
            int no;scanf("%d",&no);
            ns[i]=no;
            if(no==0) continue;
            st.insert(no);
            if(mp.find(no)==mp.end()) mp[no]=1;
            else mp[no]++;
        }

        while(q--){
            int ty,a,b;
            scanf("%d",&ty);
            if(ty==1){
                scanf("%d%d",&a,&b);
                a--;
                int cur=ns[a];
                ns[a]=b;

                if(cur !=0){
                    mp[cur]--;
                    if(mp[cur]==0) st.erase(cur);
                }
                if(b==0)continue;

                st.insert(b);
                if(mp.find(b)==mp.end()) mp[b]=1;
                else mp[b]++;


            } else {
                printf("%d\n", st.size());
            }
        }

    }
    return 0;
}
