#include <iostream>

using namespace std;

int n;
string a,b;

bool check(char a, char b, int del){

    int noa=a-'a', nob=b-'a';
    if(noa+del==nob || noa-del==nob) return 1;
    return 0;

}

int main(){


    cin >> n;
    while(n--){
        cin >> a >> b;
        if(a==b){
            cout<<1<<"\n";
            continue;
        }
        if(a.length()!=b.length()){
            cout<<3<<"\n";
            continue;
        }

        int la=a.length(), lb=b.length();
        bool done=1;
        for(int i=0;i<la;i++){

            if( !(check(a[i],b[i],0) || check(a[i],b[i],1) || check(a[i],b[i],8) || check(a[i],b[i],9) || check(a[i],b[i],10))  ){
                done=0;
                break;
            }

        }

        if(!done) {
            cout << 3 << "\n";
        } else cout << 2 <<"\n";

    }
    return 0;
}
