#include <iostream>

using namespace std;
int T,N;
bool ns[21];

void func(int idx, bool ar[]){
    if(idx==N){
        for(int i=0;i<idx;i++) {
            if(ar[i]) printf("1");
            else printf("0");
        }
        printf("\n");
        return;
    }
    ar[idx]=0;
    func(idx+1, ar);
    ar[idx]=1;
    func(idx+1, ar);
}

int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d",&N);
        func(0, ns);
    }
    return 0;
}
