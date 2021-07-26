#include <bits/stdc++.h>
using namespace std;
int main(){
	int a, b, x, y;
	cin>>a>>b>>x>>y;
	int d = __gcd(x, y);
	x /= d;
	y /= d;
	a = min(a/x, b/y);
	cout<<x*a<<" "<<y*a<<endl;
	return 0;
}
