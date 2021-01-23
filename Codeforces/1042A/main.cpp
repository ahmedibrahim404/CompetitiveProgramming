#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int n, m, as[109];

int main(){

    scanf("%d %d", &n, &m);

    int mx=0;
    for(int i=0;i<n;i++){
        scanf("%d", &as[i]);
        if(as[i] > mx)mx=as[i];
    }

    mx += m;
    sort(as, as+n);

    for(int i=n-2;i>=0 && m > 0;i--){
        int mi=min(as[i+1]-as[i], m);
        m-=mi;
        as[i] += mi;

//        cout << i << " IS " << as[i] << endl;
    }

    int mmi=as[n-1];;
    if(m > 0){
        mmi += ceil((double) m/n);
    }
    // 8 14 14 14

    printf("%d %d", mmi, mx);

    return 0;
}
