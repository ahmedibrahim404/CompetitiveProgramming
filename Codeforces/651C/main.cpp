#include <iostream>
#include <map>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    long n; cin >> n;

    map<long, long> countX;
    map<long, long> countY;
    map<pair<long, long>, long> countXY;

    int64_t pairs(0);
    while(n--){
        long x, y; cin >> x >> y;
        if(countX.count(x) > 0){pairs += countX[x]; ++countX[x];}
        else{countX[x] = 1;}

        if(countY.count(y) > 0){pairs += countY[y]; ++countY[y];}
        else{countY[y] = 1;}

        pair<long, long> xy = make_pair(x, y);
        if(countXY.count(xy) > 0){pairs -= countXY[xy]; ++countXY[xy];}
        else{countXY[xy] = 1;}
    }

    cout << pairs << endl;

    return 0;
}
