#include <iostream>

using namespace std;

int t;
string str;

int main(){
    cin >> t;
    while(t--){
        cin >> str;
        int n=str.length(), c=0;
        for(int i=0;i<n-1;i++){
            if(i<n-2 && str[i]==str[i+1] && str[i]==str[i+2] && str[i] != '?'){
                c+=2, str[i+1]=str[i+2]='?';
            } else if(i<n-2 && str[i]==str[i+2] && str[i] != '?'){
                c++, str[i+2]='?';
            }else if(str[i]==str[i+1] && str[i] != '?'){
                c++, str[i+1]='?';
            }
        }
        cout << c << "\n";
    }
    return 0;
}
