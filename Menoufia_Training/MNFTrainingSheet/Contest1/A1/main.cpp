#include <iostream>
#include<math.h>
using namespace std;
int T,a,H;
const double PI=3.14159265358979;
int main(){
    cin>>T;
    cout.precision(11);
    while(T--){
        cin>>a>>H;
        double theta=(double)a/180*M_PI;
        double x=(double)H/(2*sin(theta/2));
        double area=0.5*x*x*sin(theta);
        cout<<area<<endl;
    }
    return 0;
}
