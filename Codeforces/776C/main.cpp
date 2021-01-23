#include <cstdio>
#include <map>
#include <cstdlib>
typedef long long LL;
int n,k,x; LL s,p,ans;
std::map <LL,int> cnt;
int main() {
	scanf("%d%d",&n,&k);
	for (int i=0;i<n;i++) {
		scanf("%d",&x);
		s+=x;
		for (p=1;llabs(p)<=1e14;p*=k) {
			if (p==s) ans++;
			if (cnt.find(s-p)!=cnt.end()){
                ans+=cnt[s-p];
			}
			if (p*k==1) break;
		}
		cnt[s]++;
	}
	printf("%lld\n",ans);
	return 0;
}
