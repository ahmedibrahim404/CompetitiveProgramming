#include <iostream>

using namespace std;
typedef long long ll;

int dp[10000000+9];
int N;

int solve(int no){
    int &ret=dp[no];
    if(ret != -1) return ret;
    if(no&1)
        return ret=1+solve(3*no+1);
    else
        return ret=1+solve(no/2);
}

int main(){
    for(int i=0;i<10000000+9;i++) dp[i]=-1;
    dp[1]=1;
    scanf("%d",&N);
    printf("%d", solve(N));
    return 0;
}
