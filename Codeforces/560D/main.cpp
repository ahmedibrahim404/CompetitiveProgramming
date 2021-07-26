#include <iostream>

using namespace std;

string is(string s1){

    if(s1.length() & 1) return s1;

    string ss1=is( s1.substr(0, s1.length()/2) ), ss2=is(s1.substr(s1.length()/2, s1.length()/2));

    return ss1 < ss2 ? ss2 + ss1 : ss1 + ss2;

}

string s1, s2;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> s1 >> s2;

    if(is(s1) == is(s2)){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
