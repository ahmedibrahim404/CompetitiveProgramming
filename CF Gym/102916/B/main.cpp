#include<bits/stdc++.h>

typedef long double ld;

using namespace std;
const int LIM = 2e5 + 3;
int n;
ld a[LIM], b[LIM], c[LIM], d[LIM];

bool bsearch(ld mid){
	ld num = 0, den = 0;
	for(int i=0;i<n;i++){
		if(mid * (c[i] - a[i]) > (d[i] - b[i])){
			num += b[i];
			den += a[i];
		}
		else{
			num += d[i];
			den += c[i];
		}
	}
	return (num/den >= mid);
}

int main(){

	int tests = 1;
	//cin>>tests;
	while(tests--){
		cin>>n;
		for(int i=0;i<n;i++){
			int ta,tb,tc,td;
			cin>>ta>>tb>>tc>>td;
			a[i] = ta;
			b[i] = tb;
			c[i] = tc;
			d[i] = td;
		}

		ld l = 0, r = 1e10;

		for(int i=0;i<200;i++){
			ld mid = (l+r)/2;
			if(bsearch(mid)) l = mid;
			else r = mid;
		}
		cout<<setprecision(35)<<fixed;

		cout<<l<<"\n";
	}



	return 0;
}
