#include <iostream>

using namespace std;

long long ns[100][100];
long long tm[100][100];
int T, n, m, q, a, b, c, d;

int main(){

    scanf("%d",&T);

    while(T--){

        scanf("%d %d", &n, &m);

        for(int i=0;i<100;i++) for(int j=0;j<100;j++){
            if(i == j) ns[i][j]=0;
            else ns[i][j] = 1e17, tm[i][j] = 1e17;
        }

		for(int i = 0; i < m; i++) {
			scanf("%d %d %d %d", &a, &b, &c, &d);
			if(c < tm[a - 1][b - 1] || (c == tm[a - 1][b - 1] && d < ns[a - 1][b - 1])) {
				tm[a - 1][b - 1] = tm[b - 1][a - 1] = c;
				ns[a - 1][b - 1] = ns[b - 1][a - 1] = d;
			}
		}

        scanf("%d", &q);

        for(int k=0;k<n;k++) for(int i=0;i<n;i++) for(int j=0;j<n;j++){

            if(tm[i][j] > tm[i][k] + tm[k][j]) {
                ns[i][j] = ns[i][k] + ns[k][j];
                tm[i][j] = tm[i][k] + tm[k][j];
            }
            else if(tm[i][j] == tm[i][k] + tm[k][j] && ns[i][j] > ns[i][k] + ns[k][j])
                ns[i][j] = ns[i][k] + ns[k][j];
        }

        while(q--){

            scanf("%d %d", &a, &b);

            if(ns[a-1][b-1] != 1e17){
				printf("Distance and time to reach destination is %lld & %lld.\n", ns[a - 1][b - 1], tm[a - 1][b - 1]);
            } else {
                printf("No Path.\n");
            }


        }

        if(T) printf("\n");

    }

    return 0;
}
