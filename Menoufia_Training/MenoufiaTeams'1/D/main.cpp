#include <iostream>

using namespace std;

int T, R, C, I;
char ns[101][101];
int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    cin >> T;
    while(T--){
        cin >> R >> C >> I;
        int a,b,c,d;
        char e;
        for(int i=0;i<R;i++) for(int j=0;j<C;j++) ns[i][j]='.';
        while(I--){
            cin >> a >> b >> c >> d >> e;
            a--, b--, c--, d--;
            for(int i=a;i<=c;i++){
                for(int j=b;j<=d;j++){
                    ns[i][j]=e;
                }
            }
        }
            for(int i=0;i<R;i++){
                for(int j=0;j<C;j++) cout << ns[i][j];
                cout << "\n";
            }

    }
    return 0;
}
