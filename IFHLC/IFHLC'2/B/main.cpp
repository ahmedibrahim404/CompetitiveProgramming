#include<bits/stdc++.h>
using namespace std;

int T, n,No;
vector<bool> vi;
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        vi=vector<bool>(1e6+1);
        for(int i=0;i<n;i++){
            scanf("%d",&No);
            vi[No]=1;
        }
        for(int i=0;i<n;i++){
            scanf("%d",&No);
            if(vi[No]){printf("%d\n", No);break;}
        }
    }
    return 0;
}
