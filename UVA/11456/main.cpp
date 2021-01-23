#include<algorithm>
#include<cstdio>

using namespace std;

int A[2500], Ma[2500], Mb[2500];
int N, T;

int main() {
	scanf("%d", &T);
	for(int t = 0; t < T; t++) {
		scanf("%d", &N);
		for(int i = 0; i < N; i++)
			scanf("%d", &A[i]);

		for(int i = N - 1; i >= 0; i--) {
			Ma[i] = 1;
			for(int j = i + 1; j < N; j++) {
				if(A[i] < A[j]) {
					Ma[i] = max(Ma[j] + 1, Ma[i]);
				}
			}
		}
		for(int i = N - 1; i >= 0; i--) {
			Mb[i] = 1;
			for(int j = i + 1; j < N; j++) {
				if(A[i] > A[j]) {
					Mb[i] = max(Mb[j] + 1, Mb[i]);
				}
			}
		}
		int ans = 0;
		for(int i = 0; i < N; i++) {
			ans = max(ans, Ma[i] + Mb[i] - 1);
		}
		printf("%d\n", ans);
	}
}
