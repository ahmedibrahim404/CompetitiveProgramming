#include<bits/stdc++.h>
using namespace std;
int n, k;
int main(){
    scanf("%d%d",&n,&k);
    vector<int> vi;
    set<int> st;
    for(int i=0;i<n;i++){
        int no;
        scanf("%d",&no);
        if(st.find(no) != st.end()) continue;
        vi.push_back(no);
        st.insert(no);
        if(vi.size() > k){

            st.erase(*vi.begin());
            vi.erase(vi.begin());
        }
    }
    cout << vi.size() << "\n";
    reverse(vi.begin(), vi.end());
    for(auto no: vi) cout << no << " ";
    cout << "\n";

    return 0;
}
