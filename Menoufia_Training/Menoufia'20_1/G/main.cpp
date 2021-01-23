#include <iostream>

using namespace std;
const int MAX=23;

int T, n, m;
int main(){
    cin >> T;
    while(T--){
        cin >> n >> m;
        char ns[n+4][m+4];
        for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin >> ns[i][j];
        bool is=0;
        for(int i=0;i<n;i++) {

            for(int j=0;j<m;j++){

                if(ns[i][j] != 'p') continue;

                if(ns[i+1][j]=='i' && ns[i+2][j]=='e') {is=1;break;}
                if(ns[i][j+1]=='i' && ns[i][j+2]=='e') {is=1;break;}


                if(ns[i+1][j+1]=='i' && ns[i+2][j+2]=='e') {is=1;break;}
                if(i-2 >= 0 && j-2 >= 0 && ns[i-1][j-1]=='i' && ns[i-2][j-2]=='e') {is=1;break;}
                if(j-2 >= 0 && ns[i+1][j-1]=='i' && ns[i+2][j-2]=='e') {is=1;break;}
                if(i-2 >= 0 && ns[i-1][j+1]=='i' && ns[i-2][j+2]=='e') {is=1;break;}

            }

            if(is) break;
        }
        if(is) cout << "Cutie Pie!\n";
        else cout << "Sorry Man\n";
    }
    return 0;
}
