#include <iostream>

using namespace std;
const int MAX=200+1;
int n;
int dis[MAX][MAX][MAX];
void floyd(){
    for(int k=0;k<n;k++) for(int i=0;i<n;i++) for(int j=0;j<n;j++){
        if(dp[i][k] < OO && dp[k][k] < OO && dp[i][k] + dp[k][j] < dp[i][j]){
            dp[i][j]=dp[i][k]+dp[k][j];
            prev[i][j] = prev[k][j];
        }
    }
}

void build(int i, int j){
    if(i != j) build(i, prev[i][j]);
    printf("%d\n", j);
}


int main(){
    return 0;
}
