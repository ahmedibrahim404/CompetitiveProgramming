#include<bits/stdc++.h>
using namespace std;
int n, ns[1000+3], t;

int gcd(int n1, int n2){
    while(n1 != n2)
    {
        if(n1 > n2)
            n1 -= n2;
        else
            n2 -= n1;
    }

    return n1;
}

bool used[1000+3];

int main(){
    cin >> t;
    while(t--){
        cin >> n;
        for(int i=0;i<n;i++){
            cin >> ns[i];
            used[i]=0;
        }
        sort(ns, ns+n, greater<int>());
        cout << ns[0] << " ";
        used[0]=1;
        int till=ns[0];
        for(int i=1;i<n;i++){
            if(used[i]) continue;
            int mx=gcd(till, ns[i]), idx=i;

            for(int j=0;j<n;j++){
                if(used[j]) continue;
                int sh=gcd(till, ns[j]);
                if(sh > mx){
                    mx=sh, idx=j;
                }
            }

            if(idx!=i)i--;
            used[idx]=1;
            till=gcd(till, ns[idx]);
            cout << ns[idx] << " ";

        }
        cout << endl;
    }
    return 0;
}
