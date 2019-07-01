#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pi;
typedef vector<int> vi;
int T, N;
ll a[100000+9], b[100000+9];
ll sum1, sum2;
int main() {

	scanf("%d",&T);
	while(T--){
		scanf("%d",&N);
		ll ans=0;
		for(int i=0;i<N;i++) scanf("%lld", &a[i]);
		for(int i=0;i<N;i++) scanf("%lld",&b[i]);
	

		for(int i=0;i<N;i++){
            sum1=0, sum2=0;
            for(int j=i;j<N;j++){
                sum1 += a[j];
                sum2 += b[j];
                if(sum1 >= sum2) ans++;
            }
		}


		printf("%lld\n", ans);

	}

	return 0;
}