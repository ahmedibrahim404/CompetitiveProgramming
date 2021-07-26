#include <iostream>

using namespace std;
const int MAX=5*1e5+3;
int dp[2][27];
int n;int f[MAX], l[MAX], len[MAX];
string str;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> str;
        f[i]=str[0]-'a', l[i]=str[str.length()-1]-'a';
        len[i]=str.length();
    }
    int mx=0;


    for(int first=0;first<26;first++){

        for(int last=0;last<26;last++){
            if(first==last) dp[n%2][last]=0;
            else dp[n%2][last]=-1e9;
        }


        for(int i=n-1;i>=0;i--){
            for(int last=0;last<26;last++){
                int MOD=i%2;
                int &ret=dp[MOD][last];
                ret=dp[1-MOD][last];
                if(f[i]==last) ret=max(ret, dp[1-MOD][ l[i] ] + len[i]);
            }
        }
        mx=max(mx, dp[0][first]);
    }
    printf("%d\n", mx);

    return 0;
}
