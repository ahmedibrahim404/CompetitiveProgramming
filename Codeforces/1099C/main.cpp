#include <iostream>

using namespace std;

string s;
int k;
int main(){

    cin >> s >> k;
    int le=0;
    for(int i=0;i<s.length();i++){
        if(s[i] == '?' || s[i] == '*') continue;
        le++;
    }

    for(int i=0;i<s.length();i++){

        if(le > k){

            if(s[i] == '?' || s[i] == '*'){
                s = s.substr(0, i-1) + s.substr(i+1, s.length()-i);
                le--;
                i--;
            }

        } else if(le == k){

            if(s[i] == '?' || s[i] == '*'){
                s = s.substr(0, i) + s.substr(i+1, s.length()-i);
                i--;
            }

        } else {

            if(s[i] == '?'){
                s = s.substr(0, i) + s.substr(i+1, s.length()-i);
                i--;
            }

            if(s[i] == '*') {
                s = s.substr(0, i) + string(k-le, s[i-1]) +  s.substr(i+1, s.length()-i);
                le += k-le;
                i--;
            }




        }

    }


    if(s.length() == k)    cout << s << endl;
    else cout << "Impossible" << endl;
    return 0;

}
