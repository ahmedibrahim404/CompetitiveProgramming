#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=1e6+3;
// dp[MAX][diff][to]
int dp[MAX][3][2][3][2];
char str[MAX];
int N, M;

int solve(int idx, int diff, int to, int inc, int bit){

    if(idx==N-1) {
        return 1;
    }

    int &ret=dp[idx][diff][to][inc][bit];
    if(ret != -1) return ret;
    ret=0;

    if(inc+1<=2) {
        if(bit==to){
            if(diff+1<=2)ret += solve(idx+1, diff+1, to, inc+1, bit);
        } else ret += solve(idx+1,  abs(diff-1), (diff-1) < 0 ? (1-to) : to, inc+1, bit);
    }

    if(bit==0){
        if(to==0) {
                ret += solve(idx+1, abs(diff-1), (diff-1) < 0 ? 1 : 0, 1, 1);
        }
        else {
            if(diff+1<=2){
                ret += solve(idx+1, diff+1, to, 1, 1);
            }
        }
    } else {
        if(to==1) ret += solve(idx+1, abs(diff-1), (diff-1) < 0 ? 0 : 1, 1, 0);
        else {
            if(diff+1<=2){
                ret += solve(idx+1, diff+1, to, 1, 0);
            }
        }
    }

    return ret;

}

int main(){
    scanf("%d%d%s",&N,&M,str);
    memset(dp, -1, sizeof(dp));
    int P=0, L=0,ans=0;
    for(int i=0;i<N;i++){

        if(str[i]=='P'&&abs(P-(L+1))<=2){
//            cout << (P-(L+1)) << " " << L+1 << " " << P << endl;
            if(i-1 >= 0&& str[i-1]=='L'&&i-2>=0&&str[i-2]=='L') continue;
            int add=(solve(i, abs(P-(L+1)), (L+1)>P?0:1, ( 1 + (i-1>=0&&str[i-1]=='L') ) ,0));
            printf("ADD %d\n",add);
            ans += add;
        }

        if(str[i]=='P')P++;
        else L++;

    }
//    ans--;
    printf("%d", ans);
    return 0;
}
