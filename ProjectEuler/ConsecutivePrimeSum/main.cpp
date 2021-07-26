#include <iostream>

using namespace std;

bool prime[1000000+9];
int main(){

    for(int i=2;i<1000000;i++) prime[i]=true;

    for(int i=2;i<=1000000;i++){
        if(!prime[i]) continue;
        for(int j=i+i;j<=1000000;j+=i) prime[j]=false;
    }

    int took=0, mx=0, num;
    for(int i=2;i<=1000000;i++){
        if(!prime[i]) continue;
        int total=i, took=1;
        for(int j=i+1;j<=1000000;j++){
            if(prime[j]) total += j;
            took++;
            if(total >= 1000000) break;
            if(prime[total] && took > mx) mx=took, num=total;
        }
    }

    cout << num << endl;



    return 0;
}
