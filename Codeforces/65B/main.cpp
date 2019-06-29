#include<bits/stdc++.h>
using namespace std;

int n, ns[1000+9];

int solve(int cur, int mx){


    string str=to_string(cur);

    int num=0;
    for(int i=0;i<4;i++){
        for(int j=9;j>=0;j--){
            if(i == 0 && j == 0) continue;
            char prev=str[i];
            str[i]=j+'0';
            int no=atoi(str.c_str());
            if( no <= mx ){
                num=max(num, no);
            }
            str[i]=prev;
        }
    }

    return num;

}

int main(){

//    cout << solve(3011, 2011) << endl;
   scanf("%d", &n);
    for(int i=0;i<n;i++) scanf("%d", &ns[i]);
    for(int i=n-1;i>=0;i--){
        if(i == n-1) ns[i] = solve(ns[i], 2011);
        else ns[i] = solve(ns[i], ns[i+1]);
        if(ns[i] == 0) return printf("No solution\n"), 0;
    }

    for(int i=0;i<n;i++) printf("%d\n", ns[i]);


}
