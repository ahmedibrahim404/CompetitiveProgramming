#include<bits/stdc++.h>

using namespace std;

int t, d;

vector<int> vi;
void prim(){

    bool prim[25000+3];
    memset(prim, 1, sizeof prim);
    prim[1]=prim[0]=0;
    for(int i=2;i<=25000;i++){
        if(!prim[i])continue;
        for(int j=i*i;j<=25000;j+=i){
            prim[j]=0;
        }
    }

    for(int i=2;i<=25000;i++){
        if(prim[i]) vi.push_back(i);
    }

}

int main(){
    cin >> t;
    prim();
    while(t--){
        cin >> d;
        int i=lower_bound(vi.begin(), vi.end(), 1+d)-vi.begin();
        int i2=lower_bound(vi.begin(), vi.end(), vi[i]+d)-vi.begin();
        cout << vi[i] * vi[i2] << "\n";
    }
    return 0;
}
