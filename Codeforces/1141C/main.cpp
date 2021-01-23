#include <iostream>
#include <algorithm>
using namespace std;


int n, a[200000+9], b[200000+9];
int main(){

    scanf("%d", &n);
    b[0]=a[0]=0;
    for(int i=1;i<n;i++){
        scanf("%d", &a[i]);
        a[i] += a[i-1];
        b[i] = a[i];
    }

    sort(a, a+n);

    for(int i=1;i<n;i++){
        if(a[i] - a[i-1] != 1) {
            cout << "-1" << endl;
            return 0;
        }
    }

//    for(int i=0;i<n;i++) cout << a[i] << endl;

    int strt=n-a[n-1];
    for(int i=0;i<n;i++) cout << strt + b[i] << " ";

    return 0;
}
