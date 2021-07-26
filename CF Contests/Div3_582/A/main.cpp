#include <iostream>

using namespace std;

int n,ns[100+3];
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&ns[i]);
    }
    int tt=1e5;
    for(int i=0;i<n;i++){
        int total=0;
        for(int j=0;j<n;j++){
            if((ns[i]-ns[j])%2&&ns[i]!=ns[j]) total++;
        }
        tt=min(total, tt);
    }
    printf("%d", tt);
    return 0;
}
