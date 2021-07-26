#include<bits/stdc++.h>
using namespace std;

int t, n;

int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int ns[n];
        for(int i=0;i<n;i++) scanf("%d",&ns[i]);
        set<int> st;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                st.insert(ns[j]-ns[i]);
            }
        }
        printf("%d\n", st.size());
    }
    return 0;
}
