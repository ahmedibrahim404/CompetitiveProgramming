#include<bits/stdc++.h>
using namespace std;

const int N = 1 << 17 + 1;



int n;
int lg[N];
int spMN[18][N], spMX[18][N];
int arr[N];
void init(){

    lg[0]=-1;
    for(int i=0;i<n;i++){
        lg[i+1] = lg[i] + !(i & (i+1));
        spMN[0][i] = arr[i];
        spMX[0][i] = arr[i];
    }

}

void buildSP(){

    for(int j=1;(1<<(j-1)) < n;j++){
        for(int i=0;i+(1<<(j-1)) < n;i++){
            int a = spMN[j-1][i];
            int b = spMN[j-1][i+(1<<(j-1))];
            spMN[j][i] = min(a, b);

            a = spMX[j-1][i];
            b = spMX[j-1][i+(1<<(j-1))];
            spMX[j][i] = max(a, b);
        }
    }

}
int s, ll;

int getMin(int st, int en){
    int sz=en-st+1;
    int l = lg[sz];
    int a = spMN[l][st];
    int b = spMN[l][en - (1<<l) + 1 ];

    return min(a, b);
}
int getMax(int st, int en){
    int sz=en-st+1;
    int l = lg[sz];
    int a = spMX[l][st];
    int b = spMX[l][en - (1<<l) + 1 ];
    return max(a, b);
}

int query(int a, int b){
    return getMax(a, b) - getMin(a, b);
}

int main(){
    cin >> n >> s >> ll;
    for(int i=0;i<n;i++) cin >> arr[i];
    init();
    buildSP();

    map<int, int> dp;
    int pre = -1;
    dp[pre]=0;

    for (int i = 0; i < n; i++){
        while (pre < n && (i - pre >= ll && query(pre+1,i)>s || dp.find(pre) == dp.end())){
            pre++;
        }

        if(i-pre>=ll){
            if(dp.find(i) == dp.end()) dp[i]=dp[pre]+1;
            else dp[i] = min(dp[i],dp[pre]+1);
        }
    }


    if(dp.find(n-1) == dp.end()) printf("-1\n");
    else printf("%d\n",dp[n-1]);




    return 0;
}
