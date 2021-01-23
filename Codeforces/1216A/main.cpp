#include <iostream>

using namespace std;
int n;
string s;
int main(){
    cin >> n >> s;
    int c=0;
    for(int i=0;i<n;i+=2){

        if(s[i]==s[i+1]){
            if(s[i]=='a') s[i]='b';
            else s[i]='a';
            c++;
        }

    }

    cout << c << "\n" << s << endl;


    return 0;
}
