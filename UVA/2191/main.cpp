#include <cstdio>
#include <cctype>

using namespace std;

#define MAXN 200000

int n, a, A[200000+9], tree[MAXN*4], x, y;
char str[4];

void treeInit(int n, int l, int r){
	if (l == r){
		tree[n] = A[l];
		return;
	}

	treeInit(2*n, l, (l+r)/2);
	treeInit(2*n+1, (l+r)/2+1, r);

	tree[n] = tree[2*n] + tree[2*n+1];
}

int query(int n, int l, int r, int i, int j){
	if (i > r || j < l) return 0;
	if (i <= l && r <= j) return tree[n];
	return query(2*n, l, (l+r)/2, i, j) + query(2*n+1, (l+r)/2+1, r, i, j);
}

void update(int n, int l, int r, int i, int v){
	if (i < l || i > r) return;

	if (l == r){
		tree[n] = v;
		return;
	}

	update(2*n, l, (l+r)/2, i, v);
	update(2*n+1, (l+r)/2+1, r, i, v);

	tree[n] = tree[2*n] + tree[2*n+1];
}

char cmd[50];
int cases=0;
int main(){

    while(scanf("%d", &n) == 1 && n) {
        for(int i = 1; i <= n; i++) scanf("%d", &A[i]);
        while(getchar() != '\n');
        treeInit(1, 1, n);
        printf("Case %d:\n", ++cases);

        while(scanf("%s", cmd)){

            if(cmd[0] == 'E')
                break;

            if(cmd[0] == 'M'){
                scanf("%d %d", &x, &y);
                printf("%d\n", query(1, 1, n, x, y));
            } else {
                scanf("%d %d", &x, &y);
                update(1, 1, n, x, y);
            }

        }

    }


    return 0;
}
