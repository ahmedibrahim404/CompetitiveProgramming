#include <iostream>

using namespace std;
int T, L, R, S;
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d",&L,&R,&S);
        if(S>R) {cout << "-1 -1\n";continue;}
        int st=(L+S-1)/S;
        int en=R/S;
        if(st>en){cout<< "-1 -1\n";continue;}
        cout << st << " " << en << endl;;
    }
    return 0;
}
