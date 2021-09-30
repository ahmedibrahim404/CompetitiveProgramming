#include<bits/stdc++.h>
using namespace std;
const double EPS=1e-11;
/**

    Divide the data and drop some part and conquer the another
    it should be in range ( strictly increasing then strictly decreasing ) or vice versa
    must have one min or one max => it's our target


**/

/**
    Ternary real => Target real numbers ( double )
    Ternary discrete => Target Natural number ( int ) called discrete
**/


int ternaryReal(){
    // clear ????
    double left=v[0], right=v.back();
    while(right-left > EPS){
        double g=left+(right-left)/3, h=left+2*(right-left)/3;
        if(f(g) < f(h))
            right=h;
        else
            left=g;

    }
}

/** what if we target natural numbers ??
    we need at least 4 numbers [ left, g, h, right ]
    soo

**/
int ternary(){
    // clear ????
    int left=v[0], right=v.back();
    while(right-left > 3){
        int g=left+(right-left)/3, h=left+2*(right-left)/3;
        if(f(g) < f(h))
            right=h;
        else
            left=g;
    }

    for(int i=left;i<=right;i++){
        /**
            get the best solution here
        **/
    }

}


const int MAX=100;
int n, ns[MAX];
int main(){
    cin >> n;
    for(int i=0;i<n;i++) cin >> ns[i];
    for(int i=0;i<n;i++){
        int ans=0;
        for(int j=0;j<n;j++) ans += abs(ns[i]-ns[j]);
        cout << ans << " ";
    }
    return 0;
}
