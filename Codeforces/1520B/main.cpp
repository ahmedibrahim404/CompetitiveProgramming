#include<bits/stdc++.h>
using namespace std;

int t, n;

int main(){
    scanf("%d",&t);

    vector<int> st;

    for(int i=1;i<=9;i++){
        int cur=i;
        for(int j=1;j<=9;j++){
            st.push_back(cur);
            cur *= 10;
            cur += i;
        }

    }


    while(t--){
        scanf("%d",&n);int tot=0;
        for(int i=0;i<st.size();i++){
            if(st[i] <= n){
                tot++;
            }
        }
        cout << tot << "\n";
    }
    return 0;
}
