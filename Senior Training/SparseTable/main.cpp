#include <iostream>

using namespace std;

const int N = 1 << 17 + 1;

int lg[N];
int sp[17][N];
int arr[N];
void init(){

    lg[0]=-1;
    for(int i=0;i<N-1;i++){
        lg[i+1] = lg[i] + !(i & (i+1));
        sp[0][i] = i;
    }

}

void buildSP(){

    for(int j=1;(1<<j) < N;j++){
        for(int i=0;i+(1<<j) < N;i++){
            int a = sp[j-1][i];
            int b = sp[j-1][i+(1<<(j-1))];
            sp[j][i] = arr[a] < arr[b] ? a : b;
        }
    }

}

int getMinInd(int st, int en){
    int sz=en-st+1;
    int l = lg[sz];
    int a = sp[l][st];
    int b = sp[l][en - (1<<l) + 1 ];
    return arr[a] < arr[b] ? a : b;
}



int main(){
    init();
    buildSP();

    return 0;
}
