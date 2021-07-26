#include <iostream>

using namespace std;

int n, x, y, ns[100000+9];
int main(){
    scanf("%d %d %d",&n,&x,&y);
    for(int i=0;i<n;i++) scanf("%d",&ns[i]);
    for(int i=0;i<n;i++){
        bool can=1;
        int to=max(i-x, 0);
        for(int j=i-1;j>=to;j--){
            if(ns[j] <= ns[i]){
                can=0;
                break;
            }
        }
        to=min(n-1, i+y);
        for(int j=i+1;j<=to;j++){
            if(ns[j] <= ns[i]){
                can=0;
                break;
            }
        }
        if(can){
            printf("%d\n", i+1);
            break;
        }
//        cout << "HERE" << endl;
    }
    return 0;
}
