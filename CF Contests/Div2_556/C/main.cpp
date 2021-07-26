#include<bits/stdc++.h>

using namespace std;

int n;
int ns[2], num;
bool primes[400000+9];
vector<int> vs(400000+9);

int main(){

    scanf("%d", &n);

    for(int i=0;i<n;i++){
        scanf("%d", &num);
        ns[num-1]++;
    }

    for(int i=2;i<400000+1;i++) primes[i]=true;

    for(int i=2;i<400000+1;i++){
        if(!primes[i]) continue;
        for(int j=i*2;j<400000+1;j+=i){
            if(j > 400000+1) break;
            primes[j]=false;
        }
    }

    int pre=0, id=0;
    for(int i=2;i<=min(2*n,400000+1);i++){
        if(primes[i]){
            vs[id++]=i-pre;
            pre=i;
        }
    }

    int idx=0, took=0;
    while(took < n && idx < id){
        int remain=vs[idx];

        while(remain >= 2 && ns[1] > 0){
            printf("2 ");
            ns[1]--, remain-=2;
            took++;
        }

        while(remain >= 1 && ns[0] > 0){
            printf("1 ");
            ns[0]--, remain-=1;
            took++;
        }

        idx++;

    }

    if(ns[0] > 0){
        for(int i=0;i<ns[0];i++){
            printf("1 ");
        }
    }

    if(ns[1] > 0){
        for(int i=0;i<ns[1];i++){
            printf("2 ");
        }
    }

    return 0;
}
