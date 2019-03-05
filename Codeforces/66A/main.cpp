#include <iostream>
#include <bits/stdc++.h>

using namespace std;

string s;

long double a;

int main(){

    cin >> a;
    a=abs(a);

    if(a<=127)printf("byte");
    else if(a<=32767)printf("short");
    else if(a<=2147483647)printf("int");
    else if(a<=9223372036854775807) printf("long");
    else printf("BigInteger");
    return 0;
}
