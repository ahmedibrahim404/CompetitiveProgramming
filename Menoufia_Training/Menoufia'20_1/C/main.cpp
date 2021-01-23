#include <iostream>
#include <cstring>
using namespace std;
int T, n;
int a, b, c;
const int MAX=100+3;
bool is[MAX][MAX];
int main(){
    cin >> T;
    while(T--){
        cin >> n;
        memset(is, 0, sizeof is);
        for(int i=0;i<n;i++){
            cin >> a >> b >> c;
            for(int x=a+1;x<=b;x++){
                for(int j=1;j<=c;j++){
                    is[x][j]=1;
                }
            }
        }
        int cnt=0;
        for(int i=0;i<MAX;i++){
            for(int j=0;j<MAX;j++){
                if(is[i][j])cnt ++;
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}
