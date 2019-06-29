#include <iostream>
using namespace std;

int n, m, k;
int main() {

	cin >> n >> m >> k;
	k=min(m, k);

	if(k >= n) printf("Yes");
	else printf("No");

}