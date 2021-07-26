#include <bits/stdc++.h>
using namespace std;
const int MAX=200000+3;
int n, k;
int last[MAX], ns[MAX];
bool took[MAX];
int main(){
    memset(took, 0, sizeof took);
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++){
        scanf("%d",&ns[i]);
        last[ ns[i] ]=i;
    }


    vector<int> ans;
    for(int i=0;i<n;i++){

        int cur=ns[i];
//        cout << "HERE " << i << "\n";
        if(took[cur]) continue;
        if(!ans.size()){
            ans.push_back(cur);
//            cout << "INSERT " << cur << "\n";
            took[cur]=1;
        } else {

            int idx=ans.size()-1;

            while(idx>=0){
                if(ans[idx] > cur && last[ ans[idx] ] > i){
                    took[ ans[idx] ]=0;
//                    cout << "REMOVE " << ans[idx] << "\n";
                    idx--;
                } else {
                    break;
                }
            }

            ans.resize(idx+1);
//            cout << "ADD " << cur << "\n";
            ans.push_back(cur);
            took[ cur ]=1;


        }
    }

    for(int elem: ans) printf("%d ", elem);

    return 0;
}
