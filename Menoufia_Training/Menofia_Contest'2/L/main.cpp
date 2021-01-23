#include <iostream>

using namespace std;

string s;
int mod=1e9+7, ms[100000+9];
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> s;
    int len=s.length(), idx=0, sum=0;
    for(int i=0;i<len;i++){
        if(s[i]=='a'){
            as++;
        } else if(s[i]=='b'){
            ms[idx++]=as;
            sum += as;
            as=0;
        }
    }

    if(as > 0) ms[idx++]=as, sum += as;



    return 0;
}
