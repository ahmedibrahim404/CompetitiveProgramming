#include <iostream>
const int MOD = 1073741824  ;
long long sol[1000001];

using namespace std;
long long d(long long a) {
    if (sol[a] != 0) {
		return sol[a];
	}
	int i, c = 0;
	for (i = 1; i * i <= a; i++) {
		if (a % i == 0) {
			if (i * i != a) {
				c++;
			}
			c++;
		}
	}
    sol[a] = c;
	return c;
}

int main() {
	long long i, j, k, a, b, c, ans;
	cin >> a >> b >> c;
	ans = 0;
	for (i = 1; i <= a; i++)
		for (j = 1; j <= b; j++)
			for (k = 1; k <= c; k++)
				ans += d(i * j * k);

	cout << ans % MOD ;
}


