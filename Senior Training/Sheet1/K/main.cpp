#include<bits/stdc++.h>
using namespace std;

const int MAX=100+5;
int n, m;
char ns[MAX][MAX];

void DFS(int x, int y) {
    if (x<0 || x>=n || y<0 || y>=m || ns[x][y]!='@') return;
    ns[x][y] = '0';
    DFS(x-1,y-1); DFS(x-1,y); DFS(x-1,y+1);
    DFS(x,y-1); DFS(x,y+1);
    DFS(x+1,y-1); DFS(x+1,y); DFS(x+1,y+1);
}

main() {
    int i, j;
    while (cin >> n >> m) {
        if (n==0 && m==0) break;
        for (i=0;i<n;i++) cin >> ns[i];
        int cnt = 0;
        for (i=0;i<n;i++)
            for (j=0;j<m;j++)
                if (ns[i][j]=='@') {
                    cnt++;
                    DFS(i,j);
                }
        cout << cnt << endl;
    }
}
