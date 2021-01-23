#include <iostream>
#include<algorithm>
using namespace std;
int n, k, no, ns[1000+9];
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin >> no;
        no--;
        ns[no]++;
    }
    sort(ns,ns+k, greater<int>());
    int stop=0, took=0, i=0;
    while(k){
        int re=min(k, ns[i]/2);
        ns[i]-=re*2;
        k -=re;
        took+=re;
        stop=max(stop, ns[i]);
        i++;
    }

    cout << 2*took + min(stop, k*2) << endl;

    return 0;
}
