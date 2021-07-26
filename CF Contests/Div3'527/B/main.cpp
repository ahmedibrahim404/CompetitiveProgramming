#include<bits/stdc++.h>

using namespace std;

int n, ns[100+3];
int main(){
    cin >> n;
    for(int i=0;i<n;i++ )cin>>ns[i];
    sort(ns, ns+n);
    int add=0;
    for(int i=1;i<n;i+=2){
        add += ns[i]-ns[i-1];
    }
    cout << add;
    return 0;
}
