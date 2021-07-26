#include<bits/stdc++.h>

using namespace std;
int t, n;

int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        set<int> st;
        bool can=1;
        for(int i=0;i<n;i++){
            int no;
            scanf("%d",&no);
            if(st.find(no) == st.end()) st.insert(no);
            else can=0;
        }
        if(can) printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}
