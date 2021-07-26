#include<bits/stdc++.h>
using namespace std;

int t, k;
vector<int> vi;
bool can[10][10];

bool check(int num){
    if(num < 0) return 0;
    string str=to_string(num);
    int len=str.length();
    for(int i=0;i<len-1;i++){
        if(!can[ str[i]-'0' ][ str[i+1]-'0' ]) return 0;
    }
    return 1;


}

int main(){
    scanf("%d",&t);
    memset(can, 0, sizeof can);
    for(int i=0;i<9;i++){
        int row=(i+1)/3;
        int col=(i%3);
        if((i+1)%3==0) can[i+1][i+1]=1;
        for(int j=row;j<3;j++){
            for(int k=col;k<3;k++){
                can[i+1][(j)*3+(k+1)]=1;
            }
        }
    }

    for(int i=0;i<9;i++) if((i+1)%3) can[i+1][0]=1;
    can[0][0]=1;

//
    while(t--){
        scanf("%d",&k);
        int bef=k, aft=k;
        while(!check(bef)){
            bef--;
        }
        while(!check(aft)){
            aft++;
        }

        if(aft-k > k-bef) printf("%d\n", bef);
        else printf("%d\n", aft);


    }
    return 0;
}
