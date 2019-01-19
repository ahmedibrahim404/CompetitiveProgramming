#include <iostream>
#include <math.h>

using namespace std;

int main(){
    double x1, y1, x2, y2, x3, y3, x4, y4;

    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

    double ss = sqrt((( x4-x2 )*( x4 - x2 )) + (( y4-y2 )*( y4 - y2 )));

    cout << (x1+ss) << " " << y1 << endl;

    return 0;
}
