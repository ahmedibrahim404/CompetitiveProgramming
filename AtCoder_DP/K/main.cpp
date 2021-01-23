#include<bits/stdc++.h>
using namespace std;
vector<int> vi;
int n, k, no;
const int MAX=1e5+3;
bool dp[MAX];
int main(){
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++){
        scanf("%d",&no);
        vi.push_back(no);
        dp[no]=1;
    }

    dp[0]=0;

    for(int i=1;i<=k;i++){
        for(int j=0;j<n;j++){
            if(i-vi[j]>0&&!dp[ i-vi[j] ]){
                dp[i]=1;
                break;
            }
        }
    }

    if(dp[k]) printf("First\n");
    else printf("Second\n");



    return 0;
}
