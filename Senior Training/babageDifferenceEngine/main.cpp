#include<bits/stdc++.h>
using namespace std;

void babageDifferenceEngine(vector<vector<int>> &def, int m){

    while(def.back().size() > 1){
        vector<int> n, &p = def.back();
        for(int i=0;i<p.size()-1;i++){
            n.emplace_back(p[i+1] - p[i]);
        }
        def.emplace_back(n);
    }

    def.back().resize(m+1, def.back().back());

//    for(int i=0;i<def.size();i++){
//        for(int j=0;j<def[i].size();j++){
//            cout << def[i][j] << " ";
//        }
//        cout << "\n";
//    }

    for(int i=def.size()-1, j=1;i>0;i--, j++){
        vector<int> &cur=def[i], &prev=def[i-1];
        // j denotes level
        for(int k=0;k<m;k++){
            prev.emplace_back(cur[k+j] + prev[k+j]);
        }
    }



}
int t, n, m;
int main(){
    scanf("%d",&t);
    while(t--){
        vector<vector<int>> tot;
        tot.push_back(vector<int>());
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++){
            int no;
            scanf("%d",&no);
            tot.back().push_back(no);
        }
        babageDifferenceEngine(tot, m);
        for(int i=n;i<tot[0].size();i++) printf("%d ", tot[0][i]);
        printf("\n");
    }
    return 0;
}
