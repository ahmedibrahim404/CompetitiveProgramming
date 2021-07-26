#include <iostream>
#include <cstring>
using namespace std;

int T, n;
char ns[100+1][100+1];
bool vis[100+1][100+1];

int main(){
    cin >> T;
    int ts=1;
    while(T--){
        int cnt=0;
        cin >> n;
        memset(vis, 0, sizeof vis);
        for(int i=0;i<n;i++)cin >> ns[i];
        for(int i=0;i<n;i++) for(int j=0;j<n;j++){

            if(ns[i][j]=='x' && !vis[i][j]){
                int nx=i+1, ny=j;
                while(ns[nx][ny]=='x' || ns[nx][ny] == '@'){
                    vis[nx][ny]=1;
                    nx++;
                }
                nx=i, ny=j+1;
                while(ns[nx][ny]=='x' || ns[nx][ny] == '@'){
                    vis[nx][ny]=1;
                    ny++;
                }
                cnt++;
            }
        }
        cout << "Case " << ts ++ << ": " << cnt << endl;
    }
    return 0;
}
