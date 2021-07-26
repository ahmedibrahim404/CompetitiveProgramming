#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const double EPS=1e-9;
ll b1, b2, p1, p2;


int main(){
    int T;
    cin >> T;
    while(T--){

        cin >> b1 >> p1 >> b2 >> p2;
        string ans="";
        if(!b1 && !b2){
            ans="Lazy";
        } else if(!b1) {
            ans="Congrats";
        } else if(!b2){
           ans="HaHa";
        } else if(b1==b2 && b1==1){
            ans="Lazy";
        } else if(b1==1) {
            if(!p2) ans="Lazy";
            else ans="Congrats";
        } else if(b2==1){
            if(!p1) ans="Lazy";
            else ans="HaHa";
        }

        if(ans ==""){
            if((p1*log(b1))-(p2*log(b2))>EPS){
                ans="HaHa";
            } else if((p1*log(b1))<(p2*log(b2))){
                ans="Congrats";
            } else {
                ans="Lazy";
            }
        }

        cout << ans << "\n";

    }
    return 0;
}
