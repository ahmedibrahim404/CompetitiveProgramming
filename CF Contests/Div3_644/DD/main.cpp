#include<bits/stdc++.h>
using namespace std;

int n;
const int MAX=100000+3;
int ns[MAX];
int dp[MAX];
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&ns[i]);
    int res=0;
    for(int i=0;i<n;i++){
        vector<int> vi;
        int no=ns[i];
        int mx=0;
        for(int j=1;j*j<=no;j++){
            if(no%j==0){
                if(j!=1) vi.push_back(j);
                if(j*j!=no)vi.push_back(no/j);
                mx=max(mx, max(dp[j]+1, dp[no/j]+1));
            }
        }

        int sz=vi.size();
        for(int k=0;k<sz;k++) dp[ vi[k] ]=max( dp[ vi[k] ], mx );
        res=max(res, mx);
    }

    printf("%d\n", res);

    return 0;
}
