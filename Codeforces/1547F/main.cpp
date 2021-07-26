#include<bits/stdc++.h>

using namespace std;

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (1 << 18) + 10;

int lg[N];
int sp[20][N];
int arr[N];
int n;
void init(){

    lg[0]=-1;
    for(int i=0;i<n;i++){
        lg[i+1] = lg[i] + !(i & (i+1));
        sp[0][i] = arr[i];
    }


}

void buildSP(){

    for(int j=1;(1<<j) <= n;j++){
        for(int i=0;i+(1<<(j-1)) < n;i++){
            int a = sp[j-1][i];
            int b = sp[j-1][i+(1<<(j-1))];


            sp[j][i] = __gcd(a, b);
        }
    }

}


int gcd(int st, int en){
    int sz=en-st+1;
    int l = lg[sz];
    int a = sp[l][st];
    int b = sp[l][en - (1<<l) + 1 ];

    return __gcd(a, b);
}

bool can(int k){

    set<int> stt;
    for(int i=0;i<n;i++){
        int st=i, en=i+k;
        if(en>=n){
            stt.insert( __gcd( gcd(st, n-1) , gcd(0, en%n) ) );
        } else {
            stt.insert(gcd(st, en));
        }
    }

    return stt.size() == 1;

}



int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=0;i<n;i++) scanf("%d",&arr[i]);

        init();
        buildSP();

//        for(int i=0;i<100;i++){
//            int a, b;
//            cin >> a >> b;
//            cout << gcd(a, b) << endl;
//        }


        int st=0, en=n;
        while(en >= st){
            int mid=(st+en)/2;
            if(can(mid)) en=mid-1;
            else st=mid+1;
        }

        printf("%d\n", en+1);

    }
    return 0;
}
