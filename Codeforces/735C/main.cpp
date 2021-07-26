#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
	long long n;
	cin >> n;
	vector<long long> a(1000000);
	a[0] = 1;
	a[1] = 2;
	for (int i = 1;; ++i) {
		a[i+1] = a[i] + a[i-1];
		if (a[i+1] > n) {
			cout << i << endl;
			return 0;
		}
	}
}
