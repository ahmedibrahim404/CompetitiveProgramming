#include<bits/stdc++.h>
using namespace std;

string ans="";
string a;
bool is=0;
stringstream ss;
void get(){
    if(ss >> a){
        if(a=="pair"){
            ans += "pair<";
            get();
            ans += ",";
            get();
            ans += ">";
        } else {
            ans += "int";
        }
    } else {
        is=1;
    }


}

int n;
string str;
int main(){
    getline(cin, a);
    getline(cin, str);
    ss << str;
    get();
    if(is || ss >> a){
        cout << "Error occurred\n";
    } else cout << ans << "\n";
    return 0;
}
