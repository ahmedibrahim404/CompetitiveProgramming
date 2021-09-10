#include<bits/stdc++.h>
using namespace std;

int n;
int main(){
    scanf("%d",&n);
    int ns[n];vector<int> st;
    for(int i=0;i<n;i++){
        scanf("%d",&ns[i]);
        ns[i]--;if(ns[i] == i) st.push_back(i);
    }

    printf("%d\n", (st.size()+1)/2);
    for(int i=0;i<st.size();i+=2){
        if(i+1 != st.size()){
            printf("%d %d\n", st[i]+1, st[i+1]+1);
        } else {
            int sw=1;
            if(st[i] + 1 == 1) sw=2;
            printf("%d %d\n", st[i]+1, sw);
        }
    }

    return 0;
}
