#include<bits/stdc++.h>
using namespace std;
int n;
string cmd, plc;
int a, b;
int parent1[26]; // stores the first parent
int parent2[26]; // stores the next parent
vector<int>vs[26];

void clr(int x){

    for(int i=0;i<n;i++){
        if(parent2[i]==x){
            parent2[i]=i;
            parent1[i]=i;
        }
    }

}

void mov(int x, int y){

    for(int i=0;i<n;i++){
        if(parent2[i]==x){
            parent1[i]=parent1[y];
        }
    }

}

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++) parent1[i]=parent2[i]=i;
    return 0;
}
