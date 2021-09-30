#include <iostream>

using namespace std;
const int N = 20 + 1;
char grid[N][N];
bool need[N][N];

int n, m, k;
void is(int x, int y){
    int i;
    for(i=0;;i++){
        if(x-i < 0 || y+i >= m || grid[x-i][y+i] != '*') break;
        if(x-i < 0 || y-i < 0 || grid[x-i][y-i] != '*') break;
    }

    if(i-1 >= k){
        for(i=0;;i++){
            if(x-i < 0 || y+i >= m || grid[x-i][y+i] != '*') break;
            if(x-i < 0 || y-i < 0 || grid[x-i][y-i] != '*') break;
            need[x-i][y+i] = 0;
            need[x-i][y-i] = 0;
        }
    }

}

int main(){
//    freopen("input.txt", "r", stdin);
    int t;
    cin >> t;
    while(t--){
        cin >> n >> m >> k;
        for(int i=0;i<n;i++){
            string s;
            cin >> s;
            for(int j=0;j<m;j++) grid[i][j] = s[j];
        }

        for(int i=0;i<n;i++) for(int j=0;j<m;j++){
            if(grid[i][j] == '*') need[i][j] = 1;
            else need[i][j] = 0;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] != '*') continue;

                is(i, j);

            }
        }

        bool can=1;
        for(int i=0;i<n;i++) for(int j=0;j<m;j++){
            if(grid[i][j] == '*') {
                if(!need[i][j]) continue;
                can=0;
            }
        }

        if(can) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
