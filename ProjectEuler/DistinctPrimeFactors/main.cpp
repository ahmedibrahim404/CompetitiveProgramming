#include <iostream>

using namespace std;
bool prime[100000+9];

bool isdiv(int num){

    for(int i=1;i*i<=num;i++){

        if(i == 1) continue;

        if(num%i==0){
            int fir=i, sec=num/i;
            if(prime[fir] != true || prime[sec] != true) return false;
        }

    }

    return true;

}

bool is(int no){

    for(int i=1;i<=3;i++){
        if(isdiv(no+i) == false) return false;
    }

    return true;

}

int main(){

    for(int i=2;i<100000+9;i++) prime[i]=true;

    for(int i=2;i<=100000;i++){
        if(!prime[i]) continue;
        for(int j=i+i;j<=100000;j+=i) prime[j]=false;
    }

    for(int i=1000;i<=100000;i++){
        if(is(i)) {
            return cout << i << endl, 0;
        }
    }

    return 0;
}
