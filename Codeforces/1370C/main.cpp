#include<bits/stdc++.h>
using namespace std;
string names[2] = {"Ashishgup" , "FastestFinger"};
bool prime(int n){

    for(int i=2;i*i<=n;i++){
        if(n%i==0) return 0;
    }

    return 1;

}
int t, n;
int main(){
    cin >> t;
    while(t--){

        cin >> n;

      if(n == 1)
         cout << names[1] << "\n";
      else if(n == 2)
         cout << names[0] << "\n";
      else{
         if(n & 1){
            cout << names[0] << "\n";
         }
         else{
            if(!(n&(n-1)))cout << names[1] << '\n';
            else{
               // even with odd primes
               n /= 2;
               if(n & 1){
                  cout << names[prime(n)] << "\n";
               }
               else{
                  cout << names[0] << "\n";
               }
            }
         }


        }
    }
    return 0;
}
