#include<bits/stdc++.h>
using namespace std;

int t, n, k;

int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&k);
        int ns[n];
        for(int i=0;i<n;i++)scanf("%d",&ns[i]);

        int mx = *max_element(ns, ns+n);
		if(n * mx < k){
			printf("-1\n");
			continue;
		}



		int ans = n+1;
		for(int b=0;b<k;b++){
			int to = -2;
			for(int i=0;i<n-1;i++){
				if(ns[i] < ns[i+1]){
					to = i;
					break;
				}
			}
			ans = to + 1;
			if(to == -2)break;
			ns[to]++;
		}

		printf("%d\n", ans);


    }
    return 0;
}
