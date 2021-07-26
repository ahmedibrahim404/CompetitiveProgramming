#include <iostream>

using namespace std;
int t, a, b, c, d, x, y, xx, yy, x2, y2;
int main(){
    cin >> t;
    while(t--){
        cin >> a >> b >> c >> d;
        cin >> x >> y >> xx >> yy >> x2 >> y2;
        bool can=1;
        if(xx==x2 && (a||b)){
            can=0;
        }
        if(yy==y2 && (c||d)){
            can=0;
        }

        if(!can){
            cout << "No\n";
            continue;
        }


        int mi=min(a, b);
        a-=mi;b-=mi;
        mi=min(c, d);
        c-=mi;d-=mi;

        if(a){
            if(x-a < xx) can=0;
        } else if(b){
            if(x+b > x2) can=0;
        }

        if(c){
            if(y-c<yy) can=0;
        } else if(d){
            if(y+d>y2) can=0;
        }

        if(!can){
            cout << "No\n";
        } else cout << "Yes\n";

    }
    return 0;
}
