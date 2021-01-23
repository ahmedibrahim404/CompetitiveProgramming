#include <iostream>

using namespace std;
const int MAX=200000+3;
int t, n, k;
int hs[MAX];
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&k);
        for(int i=0;i<n;i++) scanf("%d",&hs[i]);
        int l=hs[0], r=hs[0];
        bool can=1;
		for(int i=1;i<n;i++){
			l-=k-1;
			r+=k-1;
			l=max(l,hs[i]);
			r=min(r,hs[i]+k-1);
			if(l>r){
				can=0;
			}
		}

		if(l != hs[n-1]) can=0;

        if(can) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
