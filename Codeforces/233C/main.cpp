#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int k;
const int N=100;
bool is[100][100];
int main(){
    scanf("%d",&k);
    for(int i=1;k;i++){
        is[i][0]=is[0][i]=1;
        for(int j=1;j<i;j++){
            if(k<j) break;
            is[i][j]=is[j][i]=1;
            k-=j;
        }
    }

    printf("%d\n", N);
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++) if(is[i][j]) printf("1"); else printf("0");
        printf("\n");
    }

    return 0;

}
