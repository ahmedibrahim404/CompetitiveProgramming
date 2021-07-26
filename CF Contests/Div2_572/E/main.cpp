#include <iostream>
using namespace std;

int day(string s){
    if(s=="Saturday")
        return 1;
    else if(s=="Sunday")
        return 2;
    else if(s=="Monday")
        return 3;
    else if(s=="Tuesday")
        return 4;
    else if(s=="Wednesday")
        return 5;
    else if(s=="Thursday")
        return 6;
    else
        return 7;
}


int N, X, no;
string dy;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> N >> dy >> X;
    int c=0;
    for(int i=0;i<N;i++){
        cin >> no;
        if((day(dy)+i)%7 != 2 && (day(dy)+i)%7 != 1 && no >= X) c++;
    }

    cout << c << endl;

    return 0;
}
