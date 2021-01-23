#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;

const long long INF = 0x3f3f3f3f3f3f3f;
int t;
long long xx1, yy1, xx2, yy2;
long long a, b, c;

long long read(){
	double t;
	scanf("%lf", &t);
	return (long long)(10 * (t + 0.05));
}

long long gcd(long long a, long long b) {
	if (!b) return a;
	return gcd(b, a % b);
}

long long exgcd(long long a, long long b, long long &x, long long &y) {
	if (!b) {x = 1; y = 0; return a;}
	long long d = exgcd(b, a % b, y, x);
	y -= a / b * x;
	return d;
}

void build() {
	a = (yy2 - yy1) * 10;
	b = (xx1 - xx2) * 10;
	c = (yy2 - yy1) * xx1 + (xx1 - xx2) * yy1;
	long long t = gcd(gcd(a, b), c);
	a /= t; b /= t; c /= t;
}

long long solve() {
	long long ans = 0;
	long long x, y;
	long long d = exgcd(a, b, x, y);
	long long up = INF, down = -INF;
	if (xx1 > xx2) swap(xx1, xx2);
	if (yy1 > yy2) swap(yy1, yy2);
	if (c % d) return ans;
	if (b / d > 0) {
		down = max(down, (long long)ceil((xx1 * d * 1.0 / 10 - x * c * 1.0) / b));
		up = min(up, (long long)floor((xx2 * d * 1.0 / 10 - x * c * 1.0) / b));
 	}
 	else if (b / d < 0) {
 		up = min(up, (long long)floor((xx1 * d * 1.0 / 10 - x * c * 1.0) / b));
		down = max(down, (long long)ceil((xx2 * d * 1.0 / 10 - x * c * 1.0) / b));
  	}
  	else if (xx1 % 10) return ans;
  	if (a / d > 0) {
  		down = max(down, (long long)ceil((y * c * 1.0 - d * yy2 * 1.0 / 10) / a));
  		up = min(up, (long long)floor((y * c * 1.0 - d * yy1 * 1.0 / 10) / a));
   	}
   	else if (a / d < 0) {
   		up = min(up, (long long)floor((y * c * 1.0 - d * yy2 * 1.0 / 10) / a));
  		down = max(down, (long long)ceil((y * c * 1.0 - d * yy1 * 1.0 / 10) / a));
   	}
   	else if (yy1 % 10) return ans;
   	if (down <= up)
   		ans += up - down + 1;
	return ans;
}

int main() {
	scanf("%d", &t);
	while (t--) {
		xx1 = read(); yy1 = read(); xx2 = read(); yy2 = read();
		build();
		printf("%lld\n", solve());
 	}
	return 0;
}
