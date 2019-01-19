#include <iostream>
#include <stdio.h>
#include <cmath>
#include <map>
#include <vector>
#include <functional>
#include <assert.h>
#include <string>
#include <algorithm>

using namespace std;


const int MXN = 1e5 + 5;
int n, k;
int a[MXN];

bool can(int distance) {
	int current_val = a[0], ptr = 1, cntr = 1;
	for (int i = 1; i < n; i++) {
		if (a[i] - current_val >= distance) {
			cntr++;
			current_val = a[i];
		}
	}
	if (cntr >= k) return true;
	return false;
}

int main () {
	int num_tests;
	cin>>num_tests;
	for (int test=0; test<num_tests; test++) {

		cin>>n>>k;
		for (int i=0; i<n; i++) cin>>a[i];

		sort(a, a+n);

		int hi = 1e9 + 7, lo = 0, mid;
		while (lo < hi - 1) {
			mid = (lo + hi) / 2;
			if (can(mid)) lo = mid;
			else hi = mid;
		}
		if (can(hi)) cout<<hi<<endl;
		else cout<<lo<<endl;
	}
	return 0;
}
