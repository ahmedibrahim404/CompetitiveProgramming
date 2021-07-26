#include <iostream>

using namespace std;

int t, n, m;
int main(){
    cin >> t;
    char ch;
    while(t--){
        cin >> n >> m;
        int c=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin >> ch;
                if(i==n-1 && j != m-1){
                    if(ch!='R') c++;
                } else if(j==m-1 && i != n-1){
                    if(ch!='D') c++;
                }
            }
        }

        cout << c << "\n";
    }
    return 0;
}
