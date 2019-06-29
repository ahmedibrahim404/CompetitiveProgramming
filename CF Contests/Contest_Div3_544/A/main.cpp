#include <iostream>

using namespace std;

int a, b, c, d;
string s1, s2;
int main(){
    cin >> s1 >> s2;
    string a1=s1.substr(0, 2), a2=s1.substr(3, 2);
    string b1=s2.substr(0, 2), b2=s2.substr(3, 2);
    int a=atoi(a1.c_str()), b=atoi(a2.c_str()), c=atoi(b1.c_str()), d=atoi(b2.c_str());

    int hours, mins;

    if((a+c)%2 == 0){
        mins=(b+d)/2;
    } else {
        mins=(b+d)/2 + 30;
    }
    //(((b+d)/2) < 10 ? "0":"")+
    if(mins >= 60){
        hours=(a+c)/2+1;
        mins=mins%60;
    } else {
        hours=(a+c)/2;
    }

    cout << ((hours) < 10 ? "0":"") << hours << ":" << ((mins) < 10 ? "0":"") << mins << endl;
    return 0;
}
