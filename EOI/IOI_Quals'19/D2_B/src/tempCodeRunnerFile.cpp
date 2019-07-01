#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pi;
typedef vector<int> vi;
int T, N;
ll ns[100000+9], no, A[100000+9];
vi sum;
int main() {

	scanf("%d",&T);
	while(T--){
		scanf("%d",&N);
		ll ans=0;
		sum=vi(N);
		for(int i=0;i<N;i++) scanf("%lld", &A[i]);
		for(int i=0;i<N;i++) {
			scanf("%lld",&no);
			ns[i]=A[i]-no;
			if(ns[i]>=0) ans++;
		}

		for(int i=1;i<N;i++) ns[i] += ns[i-1], sum[i]=ns[i];
		sort(sum.begin(), sum.end());

		for(int i=0;i<N;i++){
			int idx=lower_bound(sum.begin(), sum.end(), ns[i])-sum.begin();
			ans += ((N-i)-idx-1);
			sum.erase(sum.begin()+idx);
		}

		ans += (ns[N-1]>=0);

		printf("%lld\n", ans);

	}

	return 0;
}