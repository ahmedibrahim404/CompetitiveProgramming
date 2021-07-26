#include <iostream>

using namespace std;


//freopen ("input.txt","r",stdin);
//freopen ("output.txt","w",stdout);

int a, b, t, no;
int main(){
    cin >> a >> b >> t;
    while(t--){
        cin >> no;
        if(no>1000){
            cout << no <<" " <<(no-1000)*b+1000*a << endl;;
        }else {
            cout << no << " "<<no*a << endl;
        }

    }


    return 0;
}
