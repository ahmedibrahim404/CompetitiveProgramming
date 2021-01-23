#include <iostream>

using namespace std;

string a, b;
int dp[100+3][100+3];
int main(){
    int t=1;
    while(getline(cin, a) && a != "#"){
        getline(cin, b);
        int l1=a.length(), l2=b.length();
        for(int i=0;i<=l1;i++) for(int j=0;j<=l2;j++) dp[i][j]=0;
        for(int i=1;i<=l1;i++){
            for(int j=1;j<=l2;j++){
                if(a[i]==b[j]) dp[i][j]=1+dp[i-1][j-1];
                else
                dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
            }
        }

        printf("Case #%d: you can visit at most %d cities.\n", t, dp[l1][l2]);
        t++;
    }
    return 0;
}
