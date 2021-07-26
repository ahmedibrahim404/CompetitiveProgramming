// IOI Qualification Day 2 - Problem B
// For every pair i, j ( i <= j )
// get count of pairs such ( Sum(B, i, j) <= Sum(A, i, j) ) 
// at first we get the difference between A[i], B[i] for every 0<i<N
// do cumulative sum on them and sort them in another array
// For every element check how many elements is bigger than it and ADD THEM AS PAIR
// O(NLog(N))

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

		sum[0]=ns[0];
		for(int i=1;i<N;i++) ns[i] += ns[i-1], sum[i]=ns[i];
		sort(sum.begin(), sum.end());

		for(int i=0;i<N-1;i++){
			int idx=lower_bound(sum.begin(), sum.end(), ns[i])-sum.begin();
			ans += max(0, ( (N-i) - idx-1 ) - (ns[i+1]>=ns[i]) );
			sum.erase(sum.begin()+idx);
		}

		for(int i=1;i<N;i++){
			ans += (ns[i]>=0);
		}
		

		printf("%lld\n", ans);

	}

	return 0;
}