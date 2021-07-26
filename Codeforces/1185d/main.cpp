#include<bits/stdc++.h>
using namespace std;

bool isAtOrigin(string s){

    int moves[4];
    memset(moves, 0, sizeof(moves));
    for(int i=0;i<s.length();i++){
        if(s[i] == 'L') moves[0]++;
        else if(s[i] == 'R') moves[1]++;
        else if(s[i] == 'U') moves[2]++;
        else moves[3]++;
    }


    return (moves[0]==moves[1]) & (moves[2]==moves[3]);

}

int main(){
    cout << isAtOrigin("UD") << endl;
    cout << isAtOrigin("LR") << endl;
    cout << isAtOrigin("LL") << endl;

    return 0;
}
