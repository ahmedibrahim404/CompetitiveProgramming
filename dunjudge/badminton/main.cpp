#include <iostream>

using namespace std;

string s;

int main(){
    cin >> s;
    int ascore=0, bscore=0;
    int awon=0, bwon=0;
    for(int i=0;i<s.length();i++){

        if(s[i] == 'A') ascore ++;
        else bscore ++;

        if(ascore == 21 || bscore == 21){
            cout << ascore << "-" << bscore << endl;
            awon += ascore > bscore, bwon += bscore > ascore, ascore =0, bscore = 0;
        }


    }

    if(awon > bwon)
        cout << "A" << endl;
    else
        cout << "B" << endl;

    return 0;
}
