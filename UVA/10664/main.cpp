#include<bits/stdc++.h>
using namespace std;


int T, n, dp[21][201], ns[21], total=0;;

bool solve(int idx, int took){

    if(idx >= n) return 0;
    if(idx == n-1){
        return (took == total-took);
    }

    int &ret = dp[idx][took];
    if(ret != -1) return ret;
    ret = solve(idx+1, took) || solve(idx+1, took+ns[idx+1]);
    return ret;

}

int main() {
	string line;
	int T;
	scanf("%d", &T);
    getchar();

	while(T--) {

        for(int i=0;i<21;i++) for(int j=0;j<201;j++) dp[i][j]=-1;
        n=0, total=0;
		getline(cin, line);
		istringstream in(line);
        for(int i=0;i<21;i++) ns[i]=0;
        while(in>>ns[n]) total += ns[n++];
        if(solve(0, 0)) printf("YES\n");
        else printf("NO\n");
	}

    return 0;
}
