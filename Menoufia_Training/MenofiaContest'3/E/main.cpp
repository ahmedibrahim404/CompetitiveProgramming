#include <iostream>

using namespace std;

int N, x, y, t;
int main(){
    cin >> N;
    int px=0, py=0, pt=0;
    bool c=0;
    while(N--){
        cin >> t >> x >> y;
        if(c) continue;
        if((abs(x-px) + abs(y-py) > t-pt) || ( ((abs(x-px) + abs(y-py))&1) != ((t-pt)&1) ))c=1;
        px=x, py=y, pt=t;
    }
    if(c==1) cout << "No" << endl;
    else cout << "Yes" << endl;
    return 0;
}
