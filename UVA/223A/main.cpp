#include <iostream>

using namespace std;

string s;
int main(){
    cin >> s;
    int mx=0;
    string mxstr="";
    for(int i=0;i<s.length();i++){

        if( s[i] == '(' || s[i] == '[' ){

            int no=0, a=0, b=0;

            if(s[i] == '(') a++; else b++, no++;

            int lastadd=0;

            for(int j=i+1;j<s.length();j++){
                if(s[j] == '[') no++, b++;if(s[j] == ']') b--;
                if(s[j] == '(') a++;if(s[j] == ')') a--;

                if(a == 0 && b == 0){

                    lastadd = j-i;
                    if(no >= mx){
                        mx=no;
                        mxstr = s.substr(i, j-i+1);
                    }

                }

                if(a < 0 || b < 0 || j == s.length()-1){
                    i += lastadd;
                    break;
                }

                if( s[i] == '(' ){

                    if(a == 0 && b > 0){
                        i += lastadd;
                        break;
                    }

                } else {

                    if(b == 0 && a > 0){
                        i += lastadd;
                        break;
                    }

                }



            }

        } else continue;

    }

    cout << mx << endl;
    cout << mxstr << endl;

    return 0;
}
