#include <iostream>
#include <algorithm>
using namespace std;

string s;

int main(){

    cin >> s;

    for(char i='a';i<='z';i++){

        for(int j=0;j<=s.length();j++){

            string a=s;
            string b=a.substr(0, j) + i + a.substr(j, s.length()-j+1);
            string c=b;
            reverse(b.begin(), b.end());

            if(b == c) return cout<< c << endl, 0;

        }

    }

    cout << "NA" << endl;

    return 0;
}
