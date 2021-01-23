#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t, n;
int main(){
    scanf("%d",&t);
    while(t--){
        ll T;
        scanf("%d%lld",&n,&T);
        int ns[n], bs[n];
        for(int i=0;i<n;i++) ns[i]=-1;
        map<int, multiset<int>> mp;
        set<int> s1, s2;
        for(int i=0;i<n;i++){
            int no;
//            scanf("%d",&ns[i]);
            scanf("%d",&no);
            bs[i]=no;
            if(mp.find(T-no) != mp.end() && mp[T-no].size()){
                int cur=*mp[T-no].begin();
                mp[T-no].erase(cur);
                s1.insert(no);
                s2.insert(T-no);
                ns[i]=0;ns[cur]=1;
            } else {
                mp[no].insert(i);
            }
        }

        for(int i=0;i<n;i++){
            if(ns[i]==-1){
                if(s1.find(T-bs[i])==s1.end()){
                    s1.insert(bs[i]);
                    ns[ i ]=0;
                } else {
                    s2.insert(bs[i]);
                    ns[ i ]=1;
                }
            }
        }

        for(int i=0;i<n;i++) printf("%d ", ns[i]);
        printf("\n");

    }
    return 0;
}
