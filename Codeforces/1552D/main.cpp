#include <iostream>

using namespace std;

const int N = 11;
int ns[N];
int n;;

bool solve(int idx, int sum, bool is){
    if(idx == n) return !sum && is;
    return solve(idx+1, sum+ns[idx], 1) | solve(idx+1, sum-ns[idx], 1) | solve(idx+1, sum, is);
}

int main(){
    int t;scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=0;i<n;i++) scanf("%d",&ns[i]);
        if(solve(0, 0, 0)) printf("YES\n"); else printf("NO\n");
    }
    return 0;
}
