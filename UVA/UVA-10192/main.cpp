#include <stdio.h>
#include <string.h>


using namespace std;
char a[100+9], b[100+9];
int l1, l2;
int main(){
    int cs=0;
    while(gets(a)){
        if(strcmp(a, "#") == 0)
            break;
        gets(b);
        int dp[102][102] = {};
        l1=strlen(a); l2=strlen(b);
        for(int i=0;i<=l1;i++) for(int j=0;j<=l2;j++) dp[i][j]=0;
        for(int i=1;i<=l1;i++){
            for(int j=1;j<=l2;j++){
                if(a[i-1]==b[j-1]) dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=dp[i][j-1] > dp[i-1][j] ? dp[i][j-1] : dp[i-1][j];

            }
        }
            printf("Case #%d: you can visit at most %d cities.\n", ++cs, dp[l1][l2]);
    }
    return 0;
}
