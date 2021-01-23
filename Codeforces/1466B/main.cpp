#include<bits/stdc++.h>

using namespace std;
int t, n;

int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        set<int> st;
        for(int i=0;i<n;i++){
            int no;
            scanf("%d",&no);
            if(st.find(no)==st.end()) st.insert(no);
            else st.insert(no+1);
        }
        printf("%d\n", st.size());
    }
    return 0;
}
