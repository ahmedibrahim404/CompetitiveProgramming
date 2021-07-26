#include <iostream>
#include<algorithm>
using namespace std;

long long  o[1000005],L,R;
int T,len;

void dp(int i, int j, long long sum){

	if (i==18) {
            o[++len]=sum;
            return;
	}
	dp(i+1,j,sum*10);
	if (j<3)
		for (int k=1;k<=9;++k)
			dp(i+1,j+1,sum*10+k);

}

int main(){


	dp(0,0,0);o[++len]=1e18;

//    for(int i=0;i<1500;i++){
//        cout << i << " " << o[i] << endl;
//    }

    scanf("%d", &T);

    while(T--){
        scanf("%lld %lld", &L, &R);
        printf("%d\n",upper_bound(o+1,o+len+1,R)-lower_bound(o+1,o+len+1,L));
    }

    return 0;
}
