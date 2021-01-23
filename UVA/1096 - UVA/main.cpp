#include <iostream>
#include <math.h>
using namespace std;

int n, b1, b2;
int x, y;

double dis(int x1, int y1, int x2, int y2){
    return sqrt( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) );
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);

    cout << dis(1, 2, 3, 3) + dis(3, 3, 4, 1) + dis(4, 1, 6, 7) << "\n";
    cout << dis(1, 2, 4, 1) + dis(4, 1, 3, 3) + dis(3, 3, 6, 7) << "\n";

//    cin >> n >> b1 >> b2;
//    for(int i=0;i<n;i++){
//        cin >> x >> y;
//
//    }
    return 0;
}
