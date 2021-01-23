#include <iostream>

using namespace std;

int n, k;
string word, str;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    cin >> word;
    n--;
    while(n--){
        cin >> str;
        word += " " + str;
    }

    bool is_caps=false;
    cin >> k;

    string res="";
    int cur=0;
    while(k--){
        cin >> str;
        if(str[0]=='C'){
            is_caps = 1-is_caps;
        } else if(str[0]=='B'){
            if(res.length() > 0)
                res = res.substr(0, res.length()-1);
        } else if(str[0]=='S'){
            res += " ";
        } else {
            char s=str[0];
            if(is_caps) res += toupper(s);
            else res += s;
        }
    }

    cout << res << " " << word << endl;
    if(res == word) cout << "Correct" << endl;
    else cout << "Incorrect" << endl;

    return 0;
}
