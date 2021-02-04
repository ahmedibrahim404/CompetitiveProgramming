#include<bits/stdc++.h>
using namespace std;
int t, q, d;

bool check(int no){
    bool can=0;
    while(no){
        if((no%10)==d) return true;
        no /= 10;
    }
    return false;
}

int main(){
//    queue<int> q[10];
//    for(int i=1;i<=9;i++){
//        q.push(7);
//        while(!q.empty()){
//
//        }
//
//    }

    cin >> t;
    while(t--){
        cin >> q >> d;
        int no;


        while(q--){
            cin >> no;
            int rem=no%d;
            int num;
            int cur=1;
            bool done=0;
            while(true){
                num=rem+d*cur;
                if(num > no) break;
                if(check(num)){
                    done=1;
                    break;
                }
                cur++;
            }

            if(done) cout << "YES\n";
            else cout << "NO\n";

        }
    }
    return 0;
}
