#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    int n, m, s, i, j;
    while(scanf("%d %d %d", &n, &m, &s) == 3) {
        if(n == 0 && m == 0 && s == 0)
            break;
        char ns[20][20];
        int ti=1;
        for(i = 0; i < n; i++)
            scanf("%s", ns[i]);
        bool used[20][20];int open[20][20];
        int x = 0, y = s-1, step = 0;
        for(i = 0; i < n; i++)
            for(j = 0; j < m; j++)
                used[i][j] = 0;
        used[x][y] = 0;
        while(1) {
            step++;
            if(ns[x][y] == 'N')
                x--;
            else if(ns[x][y] == 'S')
                x++;
            else if(ns[x][y] == 'E')
                y++;
            else
                y--;
            if(x < 0 || y < 0 || x >= n || y >= m) {
                printf("%d step(s) to exit\n", step);
                break;
            }
            if(used[x][y]) {
                printf("%d step(s) before a loop of %d step(s)\n", open[x][y], step-open[x][y]);
                break;
            }
            open[x][y] = ti++;
            used[x][y] = 1;
        }
    }
    return 0;
}
