#include <iostream>

using namespace std;
int t, n;
string str;
int main(){
    cin >> t;
    while(t--){
        cin >> n >> str;
        if(n==1){
            if((str[0]-'0')%2) cout << "1\n";
            else cout << "2\n";
            continue;
        }
        bool is=0;

        if(n%2){

       for(int i=0;i<n;i+=2){
            if((str[i]-'0')%2==1){
                is=1;
            }
        }

        if(is) cout << "1\n";
        else cout << "2\n";


        } else {
        for(int i=1;i<n;i+=2){
            if((str[i]-'0')%2==0){
                is=1;
            }
        }

        if(is) cout << "2\n";
        else cout << "1\n";


        }



    }
    return 0;
}
