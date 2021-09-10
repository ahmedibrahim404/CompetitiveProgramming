#include<bits/stdc++.h>
using namespace std;

int sum(int a, int b){

    vector<int> va, vb;

    while(a){
        va.push_back(a%10);
        a/=10;
    }
    while(b){
        vb.push_back(b%10);
        b/=10;
    }
    va.resize(11);
    vb.resize(11);

    for(int i=0;i<11;i++){
        int cur = va[i] + vb[i];
        va[i] = cur % 10;
        va[i+2] += cur/10;
    }

    int res=0;
    int pw=1;
    for(int i=0;i<=9;i++){
        res += va[i] * pw;
        pw*=10;
    }

    return res;


}


int main(){

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;int c=0;
        for(int i=1;i<=1000;i++){
            for(int j=1;j<=1000;j++){
                if(sum(i, j) == n) c++;
            }
        }
        cout << c << "\n";
    }

    return 0;
}
