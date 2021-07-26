#include<bits/stdc++.h>
using namespace std;

string s1, s2, s3, s4, chose;
int n;
int main(){
    cin >> s1 >> n;
    bool done=false;
    for(int i=0;i<n;i++){
        cin >> s2;

        bool is=true;
        for(int i=0;i<s1.length();i++){
            if(s1[i] != s2[i]) { is=false;break; }
        }

        if(is){
            if( s2 < chose || !done ) chose=s2, done=true;
        }

    }

    if(!done) chose=s1;


    cout << chose << endl;

    return 0;
}
