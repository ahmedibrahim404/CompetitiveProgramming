#include <iostream>

using namespace std;
int t, n , m;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    while(t--){
        cin >> n >> m;
        int ns[n][m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin >> ns[i][j];
                int should=(i+j)%2;
                if(ns[i][j]%2!=should) ns[i][j]++;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++) cout << ns[i][j] << " ";
            cout << "\n";
        }
    }
    return 0;
}
