#include<bits/stdc++.h>
using namespace std;

int t, n;
int ns[100+3];
bool is[100+3];
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=0;i<n;i++) ns[i]=0, is[i]=0;
        vector<int> vs;
        for(int i=0;i<n;i++) scanf("%d",&ns[i]);
        for(int i=0;i<n;i++) {
            scanf("%d",&is[i]);
            if(!is[i]) vs.push_back(ns[i]);
        }

        int sz=vs.size();
        sort(vs.begin(), vs.end(), greater<int>());
        int idx=0;
        for(int i=0;i<n;i++){
            if(is[i]) continue;
            ns[i]=vs[idx];
            idx++;
        }


        for(int i=0;i<n;i++) printf("%d ", ns[i]);
        printf("\n");


    }
    return 0;
}
