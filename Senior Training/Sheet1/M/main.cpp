#include<bits/stdc++.h>

using namespace std;

int main(){
    int n, x, y, i, j, k, m;
	int ns[101][101];
	while(scanf("%d", &n) != EOF) {
        if(!n) break;
		memset(ns, 0, sizeof(ns));
		while(scanf("%d", &x) != EOF) {
		    if(!x) break;
			while(scanf("%d", &y) != EOF && y)
				ns[x-1][y-1] = 1;
		}
		for(i = 0; i < n; i++)
			for(j = 0; j < n; j++)
				if(ns[i][j] == 0)
					ns[i][j] = 1e9;
		for(k = 0; k < n; k++)
			for(i = 0; i < n; i++)
				for(j = 0; j < n; j++)
					if(ns[i][j] > ns[i][k] + ns[k][j])
						ns[i][j] = ns[i][k] + ns[k][j];
		scanf("%d", &m);

		while(m--) {
			scanf("%d", &x);
			x--;
			int ans[101], sz = 0;
			for(i = 0; i < n; i++)
				if(ns[x][i] == 1e9){
					ans[sz++] = i;
				}
			printf("%d", sz);
			for(i = 0; i < sz; i++)
				printf(" %d", ans[i]+1);
			printf("\n");
		}
	}

    return 0;
}
